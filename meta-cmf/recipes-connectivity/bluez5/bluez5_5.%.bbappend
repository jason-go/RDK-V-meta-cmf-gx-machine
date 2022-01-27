PACKAGES =+ "${PN}-bluetoothd ${PN}-mpris-proxy"

FILES_${PN}-bluetoothd = "${libdir}/bluez5/bluetooth/bluetoothd"
FILES_${PN}-mpris-proxy = "${bindir}/mpris-proxy"
