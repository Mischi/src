#	$OpenBSD: Makefile,v 1.6 2017/02/27 16:53:59 bluhm Exp $

# This test needs a manual setup of four machines, the make
# target create-setup can be used distribute the configuration.
# The setup is the same as for regress/sys/net/pf_forward.
# Set up machines: SRC IPS RT ECO
# SRC is the machine where this makefile is running.
# IPS is running IPsec, it is reflecting or forwarding packets.
# RT is a router forwarding packets, maximum MTU is 1300.
# ECO is reflecting the ping and UDP and TCP echo packets.
#
# By choosing the net prefix of the outgoing packet the mode is selected
# 5 -> 5 : transport v4
# 4 -> 5 : transport v6
# 8 -> c : tunnel v4 stack v4
# 8 -> c : tunnel v4 stack v6
# 8 -> d : tunnel v6 stack v4
# 8 -> d : tunnel v6 stack v6
# 8 -> e : tunnel v4 forward v4
# 8 -> e : tunnel v4 forward v6
# 8 -> f : tunnel v6 forward v4
# 8 -> f : tunnel v6 forward v6
#
#               1400        1300
# +---+   0   +---+   1   +---+   2   +---+
# |SRC| ----> |IPS| ----> |RT | ----> |ECO|
# +---+ 458 5 +---+ cd    +---+    ef +---+
#     out    in   out    in   out    in
#
# The encapsulation is chosen by the digit before
# 0,1 ESP
# 2,3 AH
# 4,5 IPIP

PREFIX_IPV4 ?=	10.188.1
PREFIX_IPV6 ?=	fdd7:e83e:66bc:1

# IPv4 outgoing address is selected by route if address of cloning route,
# so SRC_TRANSP_IPV4 and IPS_TRANSP_IPV4 must be in same net
# IPv6 outgoing address is selected common prefix, 4 and 5 are close together
# SRC_TRANSP_IPV6 and IPS_TRANSP_IPV6 should be in different network
# to avoid encryption of neighbor discovery packets

SRC_OUT_IPV4 ?=	${PREFIX_IPV4}00.17
SRC_OUT_IPV6 ?=	${PREFIX_IPV6}00::17
SRC_ESP_TRANSP_IPV4 ?=	${PREFIX_IPV4}05.17
SRC_ESP_TRANSP_IPV6 ?=	${PREFIX_IPV6}04::17
SRC_ESP_TUNNEL_IPV4 ?=	${PREFIX_IPV4}08.17
SRC_ESP_TUNNEL_IPV6 ?=	${PREFIX_IPV6}08::17
SRC_AH_TRANSP_IPV4 ?=	${PREFIX_IPV4}25.17
SRC_AH_TRANSP_IPV6 ?=	${PREFIX_IPV6}24::17
SRC_AH_TUNNEL_IPV4 ?=	${PREFIX_IPV4}28.17
SRC_AH_TUNNEL_IPV6 ?=	${PREFIX_IPV6}28::17
SRC_IPIP_TRANSP_IPV4 ?=	${PREFIX_IPV4}45.17
SRC_IPIP_TRANSP_IPV6 ?=	${PREFIX_IPV6}44::17
SRC_IPIP_TUNNEL_IPV4 ?=	${PREFIX_IPV4}48.17
SRC_IPIP_TUNNEL_IPV6 ?=	${PREFIX_IPV6}48::17

IPS_IN_IPV4 ?=	${PREFIX_IPV4}00.70
IPS_IN_IPV6 ?=	${PREFIX_IPV6}00::70
IPS_OUT_IPV4 ?=	${PREFIX_IPV4}01.70
IPS_OUT_IPV6 ?=	${PREFIX_IPV6}01::70
IPS_ESP_TRANSP_IPV4 ?=	${PREFIX_IPV4}05.70
IPS_ESP_TRANSP_IPV6 ?=	${PREFIX_IPV6}05::70
IPS_ESP_TUNNEL4_IPV4 ?=	${PREFIX_IPV4}12.70
IPS_ESP_TUNNEL4_IPV6 ?=	${PREFIX_IPV6}0c::70
IPS_ESP_TUNNEL6_IPV4 ?=	${PREFIX_IPV4}13.70
IPS_ESP_TUNNEL6_IPV6 ?=	${PREFIX_IPV6}0d::70
IPS_AH_TRANSP_IPV4 ?=	${PREFIX_IPV4}25.70
IPS_AH_TRANSP_IPV6 ?=	${PREFIX_IPV6}25::70
IPS_AH_TUNNEL4_IPV4 ?=	${PREFIX_IPV4}32.70
IPS_AH_TUNNEL4_IPV6 ?=	${PREFIX_IPV6}2c::70
IPS_AH_TUNNEL6_IPV4 ?=	${PREFIX_IPV4}33.70
IPS_AH_TUNNEL6_IPV6 ?=	${PREFIX_IPV6}2d::70
IPS_IPIP_TRANSP_IPV4 ?=	${PREFIX_IPV4}45.70
IPS_IPIP_TRANSP_IPV6 ?=	${PREFIX_IPV6}45::70
IPS_IPIP_TUNNEL4_IPV4 ?=	${PREFIX_IPV4}52.70
IPS_IPIP_TUNNEL4_IPV6 ?=	${PREFIX_IPV6}4c::70
IPS_IPIP_TUNNEL6_IPV4 ?=	${PREFIX_IPV4}53.70
IPS_IPIP_TUNNEL6_IPV6 ?=	${PREFIX_IPV6}4d::70

RT_IN_IPV4 ?=	${PREFIX_IPV4}01.71
RT_IN_IPV6 ?=	${PREFIX_IPV6}01::71
RT_OUT_IPV4 ?=	${PREFIX_IPV4}02.71
RT_OUT_IPV6 ?=	${PREFIX_IPV6}02::71

ECO_IN_IPV4 ?=	${PREFIX_IPV4}02.72
ECO_IN_IPV6 ?=	${PREFIX_IPV6}02::72
ECO_ESP_TUNNEL4_IPV4 ?=	${PREFIX_IPV4}14.72
ECO_ESP_TUNNEL4_IPV6 ?=	${PREFIX_IPV6}0e::72
ECO_ESP_TUNNEL6_IPV4 ?=	${PREFIX_IPV4}15.72
ECO_ESP_TUNNEL6_IPV6 ?=	${PREFIX_IPV6}0f::72
ECO_AH_TUNNEL4_IPV4 ?=	${PREFIX_IPV4}34.72
ECO_AH_TUNNEL4_IPV6 ?=	${PREFIX_IPV6}2e::72
ECO_AH_TUNNEL6_IPV4 ?=	${PREFIX_IPV4}35.72
ECO_AH_TUNNEL6_IPV6 ?=	${PREFIX_IPV6}2f::72
ECO_IPIP_TUNNEL4_IPV4 ?=	${PREFIX_IPV4}54.72
ECO_IPIP_TUNNEL4_IPV6 ?=	${PREFIX_IPV6}4e::72
ECO_IPIP_TUNNEL6_IPV4 ?=	${PREFIX_IPV4}55.72
ECO_IPIP_TUNNEL6_IPV6 ?=	${PREFIX_IPV6}4f::72

# Configure Addresses on the machines, there must be routes for the
# networks.  Adapt interface and addresse variables to your local
# setup.  To control the remote machine you need a hostname for
# ssh to log in.
#
# IPS and ECO need inetd echo service on TRANSP and TUNNEL addresses.
# Run make create-setup to copy hostname.if files to the machines
# Run make check-setup to see if you got the setup correct.

SRC_OUT_IF ?=	tap4
IPS_IN_IF ?=	vio1
IPS_OUT_IF ?=	vio2
RT_IN_IF ?=	vio1
RT_OUT_IF ?=	vio2
ECO_IN_IF ?=	vio1

.if empty (IPS_SSH) || empty (RT_SSH) || empty (ECO_SSH)
regress:
	@echo this tests needs three remote machines to operate on
	@echo IPS_SSH RT_SSH ECO_SSH are empty
	@echo fill out these variables for additional tests, then
	@echo check wether your test machines are set up properly
	@echo SKIPPED
.endif

.MAIN: all

.if make (regress) || make (all)
.BEGIN: ipsec.conf addr.py
	@echo
	${SUDO} true
	ssh -t ${IPS_SSH} ${SUDO} true
	rm -f stamp-ipsec
.endif

depend: addr.py

# Create python include file containing the addresses.
addr.py: Makefile
	rm -f $@ $@.tmp
.for host in SRC IPS RT ECO
.for dir in IN OUT
.for ipv in IF IPV4 IPV6
	echo '${host}_${dir}_${ipv}="${${host}_${dir}_${ipv}}"' >>$@.tmp
.endfor
.endfor
.endfor
.for sec in ESP AH IPIP
.for host mode in SRC TRANSP SRC TUNNEL \
    IPS TRANSP IPS TUNNEL4 IPS TUNNEL6 \
    ECO TUNNEL4 ECO TUNNEL6
.for ipv in IPV4 IPV6
	echo '${host}_${sec}_${mode}_${ipv}="${${host}_${sec}_${mode}_${ipv}}"'\
	    >>$@.tmp
.endfor
.endfor
.endfor
	mv $@.tmp $@

# load the ipsec sa and flow into the kernel of the SRC and IPS machine
stamp-ipsec: addr.py ipsec.conf
	@echo '\n======== $@ ========'
	cat addr.py ${.CURDIR}/ipsec.conf | ipsecctl -n -f -
	${SUDO} ipsecctl -F
	cat addr.py ${.CURDIR}/ipsec.conf | ${SUDO} ipsecctl -f -
	ssh ${IPS_SSH} ${SUDO} ipsecctl -F
	cat addr.py ${.CURDIR}/ipsec.conf | ssh ${IPS_SSH} ${SUDO} ipsecctl\
	    -f - -D FROM=to -D TO=from -D LOCAL=peer -D PEER=local
	@date >$@

# Ping all addresses.  This ensures that the IP addresses are configured
# and all routing table are set up to allow bidirectional packet flow.

.for host dir in SRC OUT IPS IN IPS OUT RT IN RT OUT ECO IN
.for ping ipv in ping IPV4 ping6 IPV6
TARGETS +=      ping-${host}_${dir}_${ipv}
run-regress-ping-${host}_${dir}_${ipv}:
	@echo '\n======== $@ ========'
	${ping} -n -c 1 -w 2 ${${host}_${dir}_${ipv}}
.endfor
.endfor

run-regress-ping-IPS_ESP_TRANSP_IPV6:
	@echo '\n======== $@ ========'
	@echo 'IPv6 IPsec input does not filter enc0 interface with pf.  Echo'
	@echo 'request does not create state and echo reply does not pass pf.'
	@echo DISABLED

run-regress-tcp-IPS_ESP_TRANSP_IPV6:
	@echo '\n======== $@ ========'
	@echo 'IPv6 IPsec input does not filter enc0 interface with pf.  TCP'
	@echo 'SYN does not create state and SYN+ACK does not pass pf.'
	@echo DISABLED

.for sec in ESP AH IPIP

.for host mode in SRC TRANSP SRC TUNNEL \
    IPS TRANSP IPS TUNNEL4 IPS TUNNEL6 \
    ECO TUNNEL4 ECO TUNNEL6
.for ping ipv in ping IPV4 ping6 IPV6
TARGETS +=      ping-${host}_${sec}_${mode}_${ipv}
ping ${host:L} ${sec:L} ${mode:L} ${ipv:L}:\
    run-regress-ping-${host}_${sec}_${mode}_${ipv}
run-regress-ping-${host}_${sec}_${mode}_${ipv}:
	@echo '\n======== $@ ========'
	netstat -s -p ${sec:L:S/ipip/ipencap/} |\
	    awk '/input ${sec} /{print $$1}' >pkt.in
	netstat -s -p ${sec:L:S/ipip/ipencap/} |\
	    awk '/output ${sec} /{print $$1}' >pkt.out
	${ping} -n -c 1 -w 2 ${${host}_${sec}_${mode}_${ipv}}
.if "${host}" != SRC
	netstat -s -p ${sec:L:S/ipip/ipencap/} |\
	    awk '/input ${sec} /{print $$1-1}' |\
	    diff pkt.in -
	netstat -s -p ${sec:L:S/ipip/ipencap/} |\
	    awk '/output ${sec} /{print $$1-1}' |\
	    diff pkt.out -
.endif
.endfor
.endfor

.for host mode in IPS TRANSP IPS TUNNEL4 IPS TUNNEL6 \
    ECO TUNNEL4 ECO TUNNEL6
.for ipv in IPV4 IPV6
TARGETS +=      udp-${host}_${sec}_${mode}_${ipv}
udp ${host:L} ${sec:L} ${mode:L} ${ipv:L}:\
    run-regress-udp-${host}_${sec}_${mode}_${ipv}
run-regress-udp-${host}_${sec}_${mode}_${ipv}:
	@echo '\n======== $@ ========'
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/input ${sec} /{print $$1}' >pkt.in
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/output ${sec} /{print $$1}' >pkt.out
	echo $$$$ | nc -n -u -w 1 ${${host}_${sec}_${mode}_${ipv}} 7 |\
	    fgrep $$$$
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/input ${sec} /{print $$1-1}' |\
	    diff pkt.in -
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/output ${sec} /{print $$1-1}' |\
	    diff pkt.out -

TARGETS +=      tcp-${host}_${sec}_${mode}_${ipv}
tcp ${host:L} ${sec:L} ${mode:L} ${ipv:L}:\
    run-regress-tcp-${host}_${sec}_${mode}_${ipv}
run-regress-tcp-${host}_${sec}_${mode}_${ipv}:
	@echo '\n======== $@ ========'
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/input ${sec} /{print $$1}' >pkt.in
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/output ${sec} /{print $$1}' >pkt.out
	echo $$$$ | nc -n -N -w 3 ${${host}_${sec}_${mode}_${ipv}} 7 |\
	    fgrep $$$$
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/input ${sec} /{print $$1-4}' |\
	    diff pkt.in -
	netstat -s -p ${sec:L:S/ipip/ipencap/} | awk '/output ${sec} /{print $$1-6}' |\
	    diff pkt.out -
.endfor
.endfor

.endfor

REGRESS_TARGETS =	${TARGETS:S/^/run-regress-/}

${REGRESS_TARGETS}: stamp-ipsec

CLEANFILES +=		addr.py *.pyc *.log stamp-* */hostname.* *.{in,out}

.PHONY: create-setup

create-setup: stamp-hostname

etc/hostname.${SRC_OUT_IF}: Makefile
	@echo '\n======== $@ ========'
	mkdir -p ${@:H}
	rm -f $@ $@.tmp
	echo '### regress ipsec $@' >$@.tmp
	echo '# SRC_OUT' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${SRC_OUT_${ipv}} ${masklen}' >>$@.tmp
.endfor
.for sec in ESP AH IPIP
	echo '## SRC_${sec}' >>$@.tmp
.for mode in TRANSP TUNNEL
	echo '# SRC_${sec}_${mode}' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${SRC_${sec}_${mode}_${ipv}} ${masklen}' >>$@.tmp
.endfor
.endfor
	echo '# IPS_${sec}_TRANSP_IPV6/64 IPS_IN_IPV6' >>$@.tmp
	echo '!route -q delete -inet6 ${IPS_${sec}_TRANSP_IPV6}/64' >>$@.tmp
	echo '!route add -inet6 ${IPS_${sec}_TRANSP_IPV6}/64 ${IPS_IN_IPV6}'\
	    >>$@.tmp
.for host dir in RT IN ECO IN
	echo '# ${host}_${dir}/pfxlen IPS_IN' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet} ${${host}_${dir}_${ipv}}/${pfxlen}'\
	    >>$@.tmp
	echo '!route add -${inet} ${${host}_${dir}_${ipv}}/${pfxlen}\
	    ${IPS_IN_${ipv}}' >>$@.tmp
.endfor
.endfor
.for host in IPS ECO
.for mode in TUNNEL4 TUNNEL6
	echo '# ${host}_${sec}_${mode}/pfxlen reject\
	    ${SRC_${sec}_TUNNEL_${ipv}}' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet}\
	    ${${host}_${sec}_${mode}_${ipv}}/${pfxlen}' >>$@.tmp
	echo '!route add -${inet} ${${host}_${sec}_${mode}_${ipv}}/${pfxlen}\
	    -reject ${SRC_${sec}_TUNNEL_${ipv}}' >>$@.tmp
.endfor
.endfor
.endfor
.endfor
	mv $@.tmp $@

${IPS_SSH}/hostname.${IPS_IN_IF}: Makefile
	mkdir -p ${@:H}
	rm -f $@ $@.tmp
	echo '### regress ipsec $@' >$@.tmp
	echo '# IPS_IN' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${IPS_IN_${ipv}} ${masklen}' >>$@.tmp
.endfor
.for sec in ESP AH IPIP
	echo '## IPS_${sec}' >>$@.tmp
	echo '# IPS_${sec}_TRANSP' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${IPS_${sec}_TRANSP_${ipv}} ${masklen}' >>$@.tmp
.endfor
	echo '# SRC_${sec}_TRANSP_IPV6/64 SRC_OUT_IPV6' >>$@.tmp
	echo '!route -q delete -inet6 ${SRC_${sec}_TRANSP_IPV6}/64' >>$@.tmp
	echo '!route add -inet6 ${SRC_${sec}_TRANSP_IPV6}/64 ${SRC_OUT_IPV6}'\
	    >>$@.tmp
.for mode in TUNNEL
	echo '# SRC_${sec}_${mode}/pfxlen reject ${IPS_IN_${ipv}}' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet}\
	    ${SRC_${sec}_${mode}_${ipv}}/${pfxlen}' >>$@.tmp
	echo '!route add -${inet} ${SRC_${sec}_${mode}_${ipv}}/${pfxlen}\
	    -reject ${IPS_IN_${ipv}}' >>$@.tmp
.endfor
.endfor
.endfor
	mv $@.tmp $@

${IPS_SSH}/hostname.${IPS_OUT_IF}: Makefile
	@echo '\n======== $@ ========'
	mkdir -p ${@:H}
	rm -f $@ $@.tmp
	echo '### regress ipsec $@' >$@.tmp
	echo '# IPS_OUT' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${IPS_OUT_${ipv}} ${masklen}' >>$@.tmp
.endfor
	echo '# ECO_IN/pfxlen RT_IN' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet} ${ECO_IN_${ipv}}/${pfxlen}'\
	    >>$@.tmp
	echo '!route add -${inet} ${ECO_IN_${ipv}}/${pfxlen} ${RT_IN_${ipv}}'\
	    >>$@.tmp
.endfor
.for sec in ESP AH IPIP
	echo '## IPS_${sec}' >>$@.tmp
.for mode in TUNNEL4 TUNNEL6
	echo '# IPS_${sec}_${mode}' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${IPS_${sec}_${mode}_${ipv}} ${masklen}' >>$@.tmp
.endfor
.endfor
.for mode in TUNNEL4 TUNNEL6
	echo '# ECO_${sec}_${mode}/pfxlen RT_IN' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet}\
	    ${ECO_${sec}_${mode}_${ipv}}/${pfxlen}' >>$@.tmp
	echo '!route add -${inet} ${ECO_${sec}_${mode}_${ipv}}/${pfxlen}\
	    ${RT_IN_${ipv}}' >>$@.tmp
.endfor
.endfor
.endfor
	mv $@.tmp $@

${RT_SSH}/hostname.${RT_IN_IF}: Makefile
	@echo '\n======== $@ ========'
	mkdir -p ${@:H}
	rm -f $@ $@.tmp
	echo '### regress ipsec $@' >$@.tmp
	echo '# RT_IN' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${RT_IN_${ipv}} ${masklen}' >>$@.tmp
.endfor
	echo '# SRC_OUT/pfxlen IPS_OUT' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet} ${SRC_OUT_${ipv}}/${pfxlen}'\
	    >>$@.tmp
	echo '!route add -${inet} ${SRC_OUT_${ipv}}/${pfxlen}'\
	    ${IPS_OUT_${ipv}} >>$@.tmp
.endfor
.for sec in ESP AH IPIP
	echo '## IPS_${sec}' >>$@.tmp
.for mode in TUNNEL
	echo '# SRC_${mode}/pfxlen IPS_OUT' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet} ${SRC_${sec}_${mode}_${ipv}}/${pfxlen}'\
	    >>$@.tmp
	echo '!route add -${inet} ${SRC_${sec}_${mode}_${ipv}}/${pfxlen}\
	    ${IPS_OUT_${ipv}}' >>$@.tmp
.endfor
.endfor
.endfor
	mv $@.tmp $@

${RT_SSH}/hostname.${RT_OUT_IF}: Makefile
	@echo '\n======== $@ ========'
	mkdir -p ${@:H}
	rm -f $@ $@.tmp
	echo '### regress ipsec $@' >$@.tmp
	echo '# RT_OUT' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${RT_OUT_${ipv}} ${masklen}' >>$@.tmp
.endfor
.for sec in ESP AH IPIP
	echo '## IPS_${sec}' >>$@.tmp
.for mode in TUNNEL4 TUNNEL6
	echo '# ECO_${sec}_${mode}/pfxlen ECO_IN' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet}\
	    ${ECO_${sec}_${mode}_${ipv}}/${pfxlen}' >>$@.tmp
	echo '!route add -${inet} ${ECO_${sec}_${mode}_${ipv}}/${pfxlen}\
	    ${ECO_IN_${ipv}}' >>$@.tmp
.endfor
.endfor
.endfor
	mv $@.tmp $@

${ECO_SSH}/hostname.${ECO_IN_IF}: Makefile
	@echo '\n======== $@ ========'
	mkdir -p ${@:H}
	rm -f $@ $@.tmp
	echo '### regress ipsec $@' >$@.tmp
	echo '# ECO_IN' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${ECO_IN_${ipv}} ${masklen}' >>$@.tmp
.endfor
.for host in IPS SRC
	echo '# ${host}_OUT/pfxlen RT_OUT' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet} ${${host}_OUT_${ipv}}/${pfxlen}'\
	    >>$@.tmp
	echo '!route add -${inet} ${${host}_OUT_${ipv}}/${pfxlen}\
	    ${RT_OUT_${ipv}}' >>$@.tmp
.endfor
.endfor
.for sec in ESP AH IPIP
	echo '## IPS_${sec}' >>$@.tmp
.for mode in TUNNEL4 TUNNEL6
	echo '# ECO_${sec}_${mode}' >>$@.tmp
.for inet ipv masklen in inet IPV4 255.255.255.0 inet6 IPV6 64
	echo '${inet} alias ${ECO_${sec}_${mode}_${ipv}} ${masklen}' >>$@.tmp
.endfor
.endfor
.for mode in TUNNEL
	echo '# SRC_${sec}_${mode}/pfxlen RT_OUT' >>$@.tmp
.for inet ipv pfxlen in inet IPV4 24 inet6 IPV6 64
	echo '!route -q delete -${inet}\
	    ${SRC_${sec}_${mode}_${ipv}}/${pfxlen}' >>$@.tmp
	echo '!route add -${inet} ${SRC_${sec}_${mode}_${ipv}}/${pfxlen}\
	    ${RT_OUT_${ipv}}' >>$@.tmp
.endfor
.endfor
.endfor
	mv $@.tmp $@

stamp-hostname: etc/hostname.${SRC_OUT_IF} \
    ${IPS_SSH}/hostname.${IPS_IN_IF} ${IPS_SSH}/hostname.${IPS_OUT_IF} \
    ${RT_SSH}/hostname.${RT_IN_IF} ${RT_SSH}/hostname.${RT_OUT_IF} \
    ${ECO_SSH}/hostname.${ECO_IN_IF}
	@echo '\n======== $@ ========'
	${SUDO} sh -c "umask 027;\
	    { sed '/^### regress/,\$$d' /etc/hostname.${SRC_OUT_IF} &&\
	    cat; } >/etc/hostname.${SRC_OUT_IF}.tmp"\
	    <etc/hostname.${SRC_OUT_IF}
	${SUDO} sh -c "mv /etc/hostname.${SRC_OUT_IF}.tmp\
	    /etc/hostname.${SRC_OUT_IF} &&\
	    sh /etc/netstart ${SRC_OUT_IF}"
.for host dir in IPS IN IPS OUT RT IN RT OUT ECO IN
	ssh root@${${host}_SSH} "umask 027;\
	    { sed '/^### regress/,\$$d' /etc/hostname.${${host}_${dir}_IF} &&\
	    cat; } >/etc/hostname.${${host}_${dir}_IF}.tmp"\
	    <${${host}_SSH}/hostname.${${host}_${dir}_IF}
	ssh root@${${host}_SSH} "mv /etc/hostname.${${host}_${dir}_IF}.tmp\
	    /etc/hostname.${${host}_${dir}_IF} &&\
	    sh /etc/netstart ${${host}_${dir}_IF}"
.endfor
	date >$@

.PHONY: check-setup

# Check wether the address, route and remote setup is correct
check-setup: check-setup-src check-setup-ips check-setup-rt check-setup-eco

check-setup-src:
	@echo '\n======== $@ ========'
.for ping inet ipv in ping inet IPV4 ping6 inet6 IPV6
.for host dir in SRC OUT
	${ping} -n -c 1 ${${host}_${dir}_${ipv}}  # ${host}_${dir}_${ipv}
	route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${dir}_${ipv}
.endfor
	${ping} -n -c 1 ${IPS_IN_${ipv}}  # IPS_IN_${ipv}
.for host dir in IPS OUT RT IN RT OUT ECO IN
	route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    fgrep -q 'gateway: ${IPS_IN_${ipv}}' \
	    # ${host}_${dir}_${ipv} IPS_IN_${ipv}
.endfor
.for sec in ESP AH IPIP
.for host mode in SRC TRANSP SRC TUNNEL
	${ping} -n -c 1 ${${host}_${sec}_${mode}_${ipv}} \
	    # ${host}_${sec}_${mode}_${ipv}
	route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${sec}_${mode}_${ipv}
.endfor
.for host mode in IPS TUNNEL4 IPS TUNNEL6 ECO TUNNEL4 ECO TUNNEL6
	route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    grep -q 'flags: .*REJECT'  # ${host}_${sec}_${mode}_${ipv}
.endfor
.endfor
.endfor
.for sec in ESP AH IPIP
	route -n get -inet ${IPS_${sec}_TRANSP_IPV4} |\
	    egrep -q 'flags: .*(CLONING|CLONED)'  # IPS_${sec}_TRANSP_IPV4
	route -n get -inet6 ${IPS_${sec}_TRANSP_IPV6} |\
	    fgrep -q 'gateway: ${IPS_IN_IPV6}' \
	    # IPS_${sec}_TRANSP_IPV6 IPS_IN_IPV6
.endfor
	sysctl net.inet.esp.enable | fgrep =1
	sysctl net.inet.ah.enable | fgrep =1
	sysctl net.inet.ipip.allow | fgrep =1

check-setup-ips:
	@echo '\n======== $@ ========'
.for ping inet ipv in ping inet IPV4 ping6 inet6 IPV6
.for host dir in IPS IN IPS OUT
	ssh ${IPS_SSH} ${ping} -n -c 1 ${${host}_${dir}_${ipv}} \
	    # ${host}_${dir}_${ipv}
	ssh ${IPS_SSH} route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${dir}_${ipv}
.endfor
	ssh ${IPS_SSH} ${ping} -n -c 1 ${SRC_OUT_${ipv}}  # SRC_OUT_${ipv}
	ssh ${IPS_SSH} ${ping} -n -c 1 ${RT_IN_${ipv}}  # RT_IN_${ipv}
.for host dir in RT OUT ECO IN
	ssh ${IPS_SSH} route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    fgrep -q 'gateway: ${RT_IN_${ipv}}' \
	    # ${host}_${dir}_${ipv} RT_IN_${ipv}
.endfor
.for sec in ESP AH IPIP
.for host mode in IPS TRANSP IPS TUNNEL4 IPS TUNNEL6
	ssh ${IPS_SSH} ${ping} -n -c 1 ${${host}_${sec}_${mode}_${ipv}} \
	    # ${host}_${sec}_${mode}_${ipv}
	ssh ${IPS_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${sec}_${mode}_${ipv}
.endfor
.for host mode in ECO TUNNEL4 ECO TUNNEL6
	ssh ${IPS_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    fgrep -q 'gateway: ${RT_IN_${ipv}}' \
	    # ${host}_${sec}_${mode}_${ipv} RT_IN_${ipv}
.endfor
.for host mode in SRC TUNNEL
	ssh ${IPS_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    grep -q 'flags: .*REJECT'  # ${host}_${sec}_${mode}_${ipv}
.endfor
.for host mode in IPS TRANSP IPS TUNNEL4 IPS TUNNEL6
	ssh ${IPS_SSH} netstat -nav -f ${inet} -p udp |\
	    fgrep ' ${${host}_${sec}_${mode}_${ipv}}.7 ' \
	    # ${host}_${sec}_${mode}_${ipv}
.endfor
.endfor
	ssh ${ECO_SSH} netstat -na -f ${inet} -p tcp | fgrep ' *.7 '
.endfor
.for sec in ESP AH IPIP
	ssh ${IPS_SSH} route -n get -inet ${SRC_${sec}_TRANSP_IPV4} |\
	    egrep -q 'flags: .*(CLONING|CLONED)'  # SRC_${sec}_TRANSP_IPV4
	ssh ${IPS_SSH} route -n get -inet6 ${SRC_${sec}_TRANSP_IPV6} |\
	    fgrep -q 'gateway: ${SRC_OUT_IPV6}' \
	    # SRC_${sec}_TRANSP_IPV6 SRC_OUT_IPV6
.endfor
	ssh ${IPS_SSH} sysctl net.inet.esp.enable | fgrep =1
	ssh ${IPS_SSH} sysctl net.inet.ah.enable | fgrep =1
	ssh ${IPS_SSH} sysctl net.inet.ipip.allow | fgrep =1

check-setup-rt:
	@echo '\n======== $@ ========'
.for ping inet ipv in ping inet IPV4 ping6 inet6 IPV6
.for host dir in RT IN RT OUT
	ssh ${RT_SSH} ${ping} -n -c 1 ${${host}_${dir}_${ipv}} \
	    # ${host}_${dir}_${ipv}
	ssh ${RT_SSH} route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${dir}_${ipv}
.endfor
	ssh ${RT_SSH} ${ping} -n -c 1 ${IPS_OUT_${ipv}}  # IPS_OUT_${ipv}
.for host dir in IPS IN SRC OUT
	ssh ${RT_SSH} route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    fgrep -q 'gateway: ${IPS_OUT_${ipv}}' \
	    # ${host}_${dir}_${ipv} IPS_OUT_${ipv}
.endfor
	ssh ${RT_SSH} ${ping} -n -c 1 ${ECO_IN_${ipv}}  # ECO_IN_${ipv}
.for sec in ESP AH IPIP
.for host mode in SRC TUNNEL
	ssh ${RT_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    fgrep -q 'gateway: ${IPS_OUT_${ipv}}' \
	    # ${host}_${sec}_${mode}_${ipv} IPS_OUT_${ipv}
.endfor
.for host mode in ECO TUNNEL4 ECO TUNNEL6
	ssh ${RT_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    fgrep -q 'gateway: ${ECO_IN_${ipv}}' \
	    # ${host}_${sec}_${mode}_${ipv} ECO_IN_${ipv}
.endfor
.endfor
.endfor

check-setup-eco:
	@echo '\n======== $@ ========'
.for ping inet ipv in ping inet IPV4 ping6 inet6 IPV6
.for host dir in ECO IN
	ssh ${ECO_SSH} ${ping} -n -c 1 ${${host}_${dir}_${ipv}} \
	    # ${host}_${dir}_${ipv}
	ssh ${ECO_SSH} route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${dir}_${ipv}
.endfor
	ssh ${ECO_SSH} ${ping} -n -c 1 ${RT_OUT_${ipv}}  # RT_OUT_${ipv}
.for host dir in RT IN IPS OUT IPS IN SRC OUT
	ssh ${ECO_SSH} route -n get -${inet} ${${host}_${dir}_${ipv}} |\
	    fgrep -q 'gateway: ${RT_OUT_${ipv}}' \
	    # ${host}_${dir}_${ipv} RT_OUT_${ipv}
.endfor
.for sec in ESP AH IPIP
.for host mode in ECO TUNNEL4 ECO TUNNEL6
	ssh ${ECO_SSH} ${ping} -n -c 1 ${${host}_${sec}_${mode}_${ipv}} \
	    # ${host}_${sec}_${mode}_${ipv}
	ssh ${ECO_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    grep -q 'flags: .*LOCAL'  # ${host}_${sec}_${mode}_${ipv}
.endfor
.for host mode in SRC TUNNEL
	ssh ${ECO_SSH} route -n get -${inet} ${${host}_${sec}_${mode}_${ipv}} |\
	    fgrep -q 'gateway: ${RT_OUT_${ipv}}' \
	    # ${host}_${sec}_${mode}_${ipv} RT_OUT_${ipv}
.endfor
.for host mode in ECO TUNNEL4 ECO TUNNEL6
	ssh ${ECO_SSH} netstat -nav -f ${inet} -p udp |\
	    fgrep ' ${${host}_${sec}_${mode}_${ipv}}.7 ' \
	    # ${host}_${sec}_${mode}_${ipv}
.endfor
.endfor
	ssh ${ECO_SSH} netstat -na -f ${inet} -p tcp | fgrep ' *.7 '
.endfor

.include <bsd.regress.mk>
