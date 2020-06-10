#include "hellovtk.h"
#include "ui_hellovtk.h"

HelloVtk::HelloVtk(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HelloVtk)
{
    ui->setupUi(this);

}

HelloVtk::~HelloVtk()
{
    delete ui;
}

void HelloVtk::RenderCube()
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
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow =
            vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    //Set render window to Qt Windget for the final rendering.
    ui->VtkQtWidget->setRenderWindow(renderWindow);

    //To do: Clean-up on need basis.
}
