QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HelloVtk.cpp

INCLUDEPATH += ../../VTK82/Mac/Debug/include/vtk-8.2

CONFIG(debug, debug|release):THP_LIB_PATH = ../../../VTK82/Mac/Debug/lib
else:CONFIG(release, debug|release):THP_LIB_PATH = ../../../VTK82/Mac/Debug/lib
LIBS += -L$$THP_LIB_PATH \
-lvtkCommonCore-8.2 \
-lvtkFiltersSources-8.2 \
-lvtkInteractionStyle-8.2 \
-lvtkRenderingCore-8.2 \
-lvtkRenderingOpenGL2-8.2 \
-lvtkCommonExecutionModel-8.2 \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
