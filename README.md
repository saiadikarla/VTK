# VTK
Simple Visualization Toolkit(VTK) examples for self learning.

VtkCpp: 
-This is a Qt Console based application to demonstrate VTK 9 rendering using C++
-Source code renders a VTK Polygon using the pipeline such as Source, Mapper, Renderer,  Render Window and Interactor.
-As shown in Qt Project file, this code is linked to VTK ver 9 debug build.

VtkQt:
-Is a Qt Widget based application to demonstrate based VTK 9 rendering using Qt GUI
-Source code renders a VTK Polygon using the pipeline such as Source, Mapper, Renderer,  Render Window and Interactor. The render window mapped to Qt Widget so the display happens on Qt GUI
-Qt Widget is promoted to QVTKOpenGLNativeWidget so VTK Renderers and Actors can be added to it.
-QSurfaceFormat::setDefaultFormat is used in main.cpp to create the OpenGL context
-As shown in Qt Project file, this code is linked to VTK ver 9 debug build.