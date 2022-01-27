DEPENDS += "directfb"
do_install_append(){
sed -i '/^E/d' ${D}${systemd_unitdir}/system/storagemgrmain.service
sed -i 's/Type=notify/ /g' ${D}${systemd_unitdir}/system/storagemgrmain.service
sed -i 's/ExecStop=\/bin\/kill -15 $MAINPID/ /g' ${D}${systemd_unitdir}/system/storagemgrmain.service
sed -i 's/Restart=always/ /g' ${D}${systemd_unitdir}/system/storagemgrmain.service
}
