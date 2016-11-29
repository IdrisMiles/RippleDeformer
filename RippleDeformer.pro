
QT       -= core gui

TARGET = RippleDeformerNode
macx:TARGET = RippleDeformerNode.bundle

SOURCES += src/*.cpp
HEADERS += include/*.h

INCLUDEPATH += include/

OBJECTS_DIR = obj

DEFINES +=  REQUIRE_IOSTREAM \
            _BOOL

MAYALIBS =  -lOpenMaya \
            -lFoundation

# --------------------------------------------------
# LINUX specific stuff
# --------------------------------------------------
linux-g++*:MAYALOCATION = /usr/autodesk/maya2016/
linux-g++*:MAYADEVKIT = /public/devel/2015/mayaDevkit_2016
linux-g++*:TEMPLATE = lib
linux-g++*:INCLUDEPATH += $$MAYALOCATION/include $$MAYADEVKIT/include
linux-g++*:LIBS += -L$$MAYALOCATION/lib $$MAYALIBS
linux-g++*:DEFINES += linux


# --------------------------------------------------
# MAC specific stuff
# --------------------------------------------------
macx:MAYALOCATION = /Applications/Autodesk/maya2017
macx:CONFIG -=  app_bundle
macx:INCLUDEPATH += $$MAYALOCATION/devkit/include
macx:LIBS += -bundle
mac:LIBS -= -dynamiclib
macx:LIBS += -L$$MAYALOCATION/Maya.app/Contents/MacOS $$MAYALIBS
macx:DEFINES += OSMac_


# --------------------------------------------------
# WINDOWS specific stuff - TODO
# --------------------------------------------------
