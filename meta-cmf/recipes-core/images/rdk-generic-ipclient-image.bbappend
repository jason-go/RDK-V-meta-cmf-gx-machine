#REFPLTV-976 removing the Control Manager service, as feature not fully functional.
require add-non-root-user-group.inc
ROOTFS_POSTPROCESS_COMMAND += "remove_systemd_ctrlm_services; "
ROOTFS_POSTPROCESS_COMMAND += "remove_Failure_case_dsmgr_services; "

remove_systemd_ctrlm_services() {
                if [ ! -f ${IMAGE_ROOTFS}${sysconfdir}/systemd/system/multi-user.target.wants/ctrlm-main.service ]; then
                        rm -rf ${IMAGE_ROOTFS}${systemd_unitdir}/system/ctrlm-main.service
                fi
		if [ ! -f ${IMAGE_ROOTFS}${sysconfdir}/systemd/system/multi-user.target.wants/ctrlm-main.service ]; then
			rm -rf ${IMAGE_ROOTFS}${sysconfdir}/systemd/system/multi-user.target.wants/ctrlm-main.service
		fi
}

remove_Failure_case_dsmgr_services () {
                       sed -i '/OnFailure=reboot-notifier@%i.service/ c\#OnFailure=reboot-notifier@%i.service' ${IMAGE_ROOTFS}${systemd_unitdir}/system/dsmgr.service
}
