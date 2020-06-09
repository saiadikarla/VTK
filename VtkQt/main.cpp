/*-------------------------------------------------------------------------*\
    Example program demonstrate simple VTK polygon rendering using the pipeline
    such as Source, Mapper, Renderer,  Render Window and Interactor.

    Make sure VTK 9.0 built successfully . Set the Lib and Include paths.

    Following VTK libraries required:
        vtkCommonCore-9.0
        vtkFiltersSources-9.0
        vtkInteractionStyle-9.0
        vtkRenderingCore-9.0
        vtkRenderingOpenGL2-9.0
        vtkCommonExecutionModel-9.0

    This program is a personal work and distributed for  knowledge share. No
    warranty or support is indented.

    Sai Adikarla
\*-------------------------------------------------------------------------*/

// Required header files for VTK.
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
// VTK Module is a macro to initialize required libraries. Failure to initialize this will
// cause run-time errors.

#include "hellovtk.h"

#include <QApplication>
#include <QtGui/QSurfaceFormat>

int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

    QApplication a(argc, argv);
    HelloVtk w;
    w.show();

    //Render the VTK Cube
    w.RenderCube();

    return a.exec();
}
