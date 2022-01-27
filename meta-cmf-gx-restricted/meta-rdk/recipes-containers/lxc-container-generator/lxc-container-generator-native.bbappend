FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

#Video 
SRC_URI_append = "${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers-video', ' file://xml/lxc_conf_PLATFORMCONTROL.xml ', '', d)}"
SRC_URI_append = "${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers-video', ' file://xml/lxc_conf_RMFSTREAMER.xml ', '', d)}"
SRC_URI_append = "${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers-video', ' file://xml/lxc_conf_RDKBROWSER2.xml ', '', d)}"

do_install_append () {

#Video
	${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers-video', ' install_lxc_config secure lxc_conf_PLATFORMCONTROL.xml ', '', d)}
        ${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers-video', ' install_lxc_config secure lxc_conf_RMFSTREAMER.xml ', '', d)}
        ${@bb.utils.contains('DISTRO_FEATURES', 'lxc-secure-containers-video', ' install_lxc_config secure lxc_conf_RDKBROWSER2.xml ', '', d)}
}
