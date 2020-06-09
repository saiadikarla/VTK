#include <QCoreApplication>

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
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCubeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"

// VTK Module is a macro to initialize required libraries. Failure to initialize this will
// cause run-time errors.

int main(int argc, char *argv[])
{
    // <ClassName>::New() convention is used to creatre a new VTK Objects. This allows platform
    //  specific implementation invoked during runtime.

    // Create  Source to produces polygonal data.
    vtkSmartPointer<vtkCubeSource> cubeSource =
            vtkSmartPointer<vtkCubeSource>::New();
    cubeSource->SetXLength(2.0);
    cubeSource->SetYLength(2.0);
    cubeSource->SetZLength(2.0);
    cubeSource->Update();

    // Create  Mapper to map the polygonal data to graphics primitives.
    vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    cubeMapper->SetInputConnection(cubeSource->GetOutputPort());

    // Create  actor to represent the mapper's primitive.
    vtkSmartPointer<vtkActor> cubeActor =
            vtkSmartPointer<vtkActor>::New();
    cubeActor->SetMapper(cubeMapper);

    // Create the Renderer  to assign and drawing actors to it.
    vtkSmartPointer<vtkRenderer> renderer =
            vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cubeActor);
    renderer->SetBackground(0.1, 0.3, 0.1);

    // Create the render window  by addign renderer.
    vtkSmartPointer<vtkRenderWindow> renderWindow =
            vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    renderWindow->SetSize(1200, 750);
    renderWindow->SetPosition(500,500);
    renderWindow->Render();
    renderWindow->SetWindowName("VTK Sample");

    // Create Interactor for mapping the user events to a corresponding action.
    vtkSmartPointer<vtkRenderWindowInteractor> rwInteractor =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    rwInteractor->SetRenderWindow(renderWindow);

    //Start event loop
    rwInteractor->Start();

    //To do: Clean-up on need basis.

    return EXIT_SUCCESS;
}
