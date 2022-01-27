# rpi specific data model
SRC_URI_append = " \
    ${CMF_GITHUB_ROOT}/tr69-datamodel;protocol=${CMF_GIT_PROTOCOL};branch=${CMF_GITHUB_MAIN_BRANCH};destsuffix=git/platform/rpi;name=tr69agentplatrpi \
"

SRCREV_tr69agentplatrpi = "${AUTOREV}"

do_install_append() {
        install -d ${D}/etc
        install -m 0644 ${S}/platform/rpi/generic/data-model.xml ${D}/etc/
}
FILES_${PN} += "/etc/*"
