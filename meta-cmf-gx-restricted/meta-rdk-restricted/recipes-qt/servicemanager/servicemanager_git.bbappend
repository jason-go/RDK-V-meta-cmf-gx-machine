EXTRA_QMAKEVARS_PRE_remove_krogoth = "CONFIG+=build_refactored_storagemanager"

EXTRA_QMAKEVARS_PRE += "DEFINES+=DISABLE_WEBKIT"
DEPENDS_remove = "qtwebkit"
DEPENDS_remove = "qtwebsockets"

EXTRA_QMAKEVARS_PRE += "CONFIG+=build_enable_wifi_manager"
QT_INC_BASE_DIR = "${STAGING_INCDIR}/qt5"

CXXFLAGS += " -I${QT_INC_BASE_DIR}"
CXXFLAGS += " -I${QT_INC_BASE_DIR}/QtWebSockets"
CXXFLAGS += " -I${QT_INC_BASE_DIR}/QtConcurrent"
CXXFLAGS += " -I${QT_INC_BASE_DIR}/QtOpenGL"
CXXFLAGS += " -I${QT_INC_BASE_DIR}/QtWidgets"
CXXFLAGS += " -I${QT_INC_BASE_DIR}/QtCore"

LDFLAGS += " -lQt5OpenGL"
