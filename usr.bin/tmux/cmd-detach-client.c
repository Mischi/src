/* $OpenBSD: cmd-detach-client.c,v 1.30 2017/01/13 10:12:12 nicm Exp $ */

/*
 * Copyright (c) 2007 Nicholas Marriott <nicholas.marriott@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include <string.h>

#include "tmux.h"

/*
 * Detach a client.
 */

static enum cmd_retval	cmd_detach_client_exec(struct cmd *,
			    struct cmdq_item *);

const struct cmd_entry cmd_detach_client_entry = {
	.name = "detach-client",
	.alias = "detach",

	.args = { "aE:s:t:P", 0, 0 },
	.usage = "[-aP] [-E shell-command] "
	         "[-s target-session] " CMD_TARGET_CLIENT_USAGE,

	.sflag = CMD_SESSION,
	.tflag = CMD_CLIENT,

	.flags = CMD_READONLY,
	.exec = cmd_detach_client_exec
};

const struct cmd_entry cmd_suspend_client_entry = {
	.name = "suspend-client",
	.alias = "suspendc",

	.args = { "t:", 0, 0 },
	.usage = CMD_TARGET_CLIENT_USAGE,

	.tflag = CMD_CLIENT,

	.flags = 0,
	.exec = cmd_detach_client_exec
};

static enum cmd_retval
cmd_detach_client_exec(struct cmd *self, struct cmdq_item *item)
{
	struct args	*args = self->args;
	struct client	*c = item->state.c, *cloop;
	struct session	*s;
	enum msgtype	 msgtype;
	const char	*cmd = args_get(args, 'E');

	if (self->entry == &cmd_suspend_client_entry) {
		tty_stop_tty(&c->tty);
		c->flags |= CLIENT_SUSPENDED;
		proc_send(c->peer, MSG_SUSPEND, -1, NULL, 0);
		return (CMD_RETURN_NORMAL);
	}

	if (args_has(args, 'P'))
		msgtype = MSG_DETACHKILL;
	else
		msgtype = MSG_DETACH;

	if (args_has(args, 's')) {
		s = item->state.sflag.s;
		TAILQ_FOREACH(cloop, &clients, entry) {
			if (cloop->session == s) {
				if (cmd != NULL)
					server_client_exec(cloop, cmd);
				else
					server_client_detach(cloop, msgtype);
			}
		}
		return (CMD_RETURN_STOP);
	}

	if (args_has(args, 'a')) {
		TAILQ_FOREACH(cloop, &clients, entry) {
			if (cloop->session != NULL && cloop != c) {
				if (cmd != NULL)
					server_client_exec(cloop, cmd);
				else
					server_client_detach(cloop, msgtype);
			}
		}
		return (CMD_RETURN_NORMAL);
	}

	if (cmd != NULL)
		server_client_exec(c, cmd);
	else
		server_client_detach(c, msgtype);
	return (CMD_RETURN_STOP);
}
