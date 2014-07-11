include(qtdefs.pri)

contains(QT_VER_MAJ, 4) {
   QT     += core gui svg
   CONFIG += qt warn_on thread uitools
}
contains(QT_VER_MAJ, 5) {
   QT     += core gui svg uitools  printsupport
   CONFIG += qt warn_on thread widgets
   DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000 
}   

unix: {
  CONFIG += x11
}


ios: {
  QMAKE_CFLAGS += -gdwarf-2
  QMAKE_CXXFLAGS += -gdwarf-2
 }
!ios {
  macx: {
     CONFIG += app_bundle
     ICON = ../src/caQtDM.icns
     cplugins.path = Contents/PlugIns/designer
     cplugins.files = ../../caQtDM_QtControls/plugins/libqtcontrols_controllers_plugin.dylib
     gplugins.path = Contents/Plugins/designer
     gplugins.files = ../../caQtDM_QtControls/plugins/libqtcontrols_graphics_plugin.dylib
     mplugins.path = Contents/Plugins/designer
     mplugins.files = ../../caQtDM_QtControls/plugins/libqtcontrols_monitors_plugin.dylib
     QMAKE_BUNDLE_DATA += cplugins gplugins mplugins
     calib.path = Contents/Frameworks
     calib.files = $$(EPICS_BASE)/lib/darwin-x86/libca.3.14.12.dylib
     comlib.path = Contents/Frameworks
     comlib.files = $$(EPICS_BASE)/lib/darwin-x86/libCom.3.14.12.dylib
     QMAKE_BUNDLE_DATA += calib comlib
  }
}

SOURCES +=\
    caQtDM.cpp \
    fileopenwindow.cpp \
    messagebox.cpp \

HEADERS  +=  \
    messagebox.h \
    fileopenwindow.h \

NETWORKDOWNLOADSUPPORT {

   QT += network
   SOURCES += configDialog.cpp
   HEADERS  +=  configDialog.h
}


FORMS += main.ui


unix:{
	DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M')\\\"
	DEFINES += BUILDDATE=\\\"$$system(date '+%d-%m-%Y')\\\"
}
win32{
	DEFINES += BUILDTIME=\\\"\\\"
	DEFINES += BUILDDATE=\\\"\\\"
	DEFINES += SUPPORT=\\\"\\\"
}
DEFINES += BUILDVERSION=\\\"$${CAQTDM_VERSION}\\\"
DEFINES += BUILDARCH=\\\"$$(QMAKESPEC)\\\"

