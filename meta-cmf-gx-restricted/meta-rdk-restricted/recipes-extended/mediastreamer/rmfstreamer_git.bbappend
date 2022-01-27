#
# ============================================================================
# RDK MANAGEMENT, LLC CONFIDENTIAL AND PROPRIETARY
# ============================================================================
# This file (and its contents) are the intellectual property of RDK Management, LLC.
# It may not be used, copied, distributed or otherwise disclosed in whole or in
# part without the express written permission of RDK Management, LLC.
# ============================================================================
# Copyright (c) 2016 RDK Management, LLC. All rights reserved.
# ============================================================================
#

EXTRA_OECONF_append_hybrid += " --enable-emulator-qam --enable-trm"
#EXTRA_OECONF_remove_hybrid += " --enable-recorder"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PACKAGECONFIG_remove_hybrid = "frontpanel ppv qam pod sdv"

SRC_URI_append = " \
    ${CMF_GIT_ROOT}/rdk/devices/intel-x86-pc/emulator/rmf_mediastreamer;protocol=${CMF_GIT_PROTOCOL};branch=${CMF_GIT_BRANCH};destsuffix=git/platform/rdkemulator;name=mediastreamerplatx86 \
"
SRCREV_mediastreamerplatx86 = "${AUTOREV}"

do_fetch[vardeps] += "SRCREV_mediastreamerplatx86"

inherit systemd

do_install_append() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/platform/rdkemulator/streamerSetup ${D}${bindir}

    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${S}/platform/rdkemulator/rmfstreamersetup.service ${D}${systemd_unitdir}/system/
    install -m 0644 ${S}/platform/rdkemulator/rmfstreamer.service ${D}${systemd_unitdir}/system/
}

SYSTEMD_SERVICE_${PN} += "rmfstreamersetup.service"
FILES_${PN} += "${systemd_unitdir}/system/rmfstreamersetup.service"
FILES_${PN} += "${bindir}/streamerSetup"

# for feature lxc-secure-containers
SRC_URI_append = "${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers', ' file://rmfstreamer.service ', '', d)}"
SRC_URI_append = "${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers', ' file://rmfstreamer.conf ', '', d)}"

do_install_append() {
    if [ "${@bb.utils.contains("DISTRO_FEATURES", "lxc-secure-containers", "yes", "no", d)}" = "yes" ]; then
        install -d ${D}${systemd_unitdir}/system
        install -m 0644 ${WORKDIR}/rmfstreamer.service ${D}${systemd_unitdir}/system

        install -d ${D}${sysconfdir}/tmpfiles.d
        install -m 0644 ${WORKDIR}/rmfstreamer.conf ${D}${sysconfdir}/tmpfiles.d/
    fi
}

FILES_${PN}_append = "${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers', ' ${sysconfdir}/tmpfiles.d/rmfstreamer.conf ', '', d)}"
