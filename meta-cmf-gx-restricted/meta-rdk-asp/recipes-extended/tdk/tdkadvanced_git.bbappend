SRC_URI_append = " \
    ${CMF_GIT_ROOT}/devices/raspberrypi/tdk-advanced;protocol=${CMF_GIT_PROTOCOL};branch=${CMF_GIT_BRANCH};destsuffix=git/advancecomponents/platform/gx;name=tdkgxadv \
"
SRCREV_tdkgxadv = "${AUTOREV}"

DEPENDS_remove = "closedcaption"

inherit coverity

EXTRA_OECONF_append = " --enable-aamp --enable-gstPluginTest"
EXTRA_OEMAKE_append = " AAMP_FLAGS=-DREF_PLATFORMS"
do_configure_prepend () {
    sed -i -e 's/ClosedCaption_stub //' ${S}/Makefile.am
    sed -i -e 's/ClosedCaption_stub\/Makefile//' ${S}/configure.ac
    sed -i -e 's/-lcanh -lpodmgr //' ${S}/configure.ac
    sed -i -e 's/-lpodserver //' ${S}/tdkRmfApp/Makefile.am
}

do_install_append_rpi() {
    install -D -p -m 755 ${S}/platform/gx/OpenSourceComponent_Stub/script/* ${D}${TDK_TARGETDIR}/opensourcecomptest/
    install -D -p -m 755 ${S}/platform/gx/agent/scripts/* ${D}${TDK_TARGETDIR}/
}

do_install_append_dunfell() {
    sed -i -e '$aexport RMF_USE_SOUPHTTPSRC=TRUE' ${D}${TDK_TARGETDIR}/StartTDK_adv.sh
}
