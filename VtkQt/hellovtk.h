#ifndef HELLOVTK_H
#define HELLOVTK_H

#include <QMainWindow>
#include <QWidget>

#include "QVTKOpenGLNativeWidget.h"
#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCubeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkGenericOpenGLRenderWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HelloVtk; }
QT_END_NAMESPACE

class HelloVtk : public QMainWindow
{
    Q_OBJECT

public:
    HelloVtk(QWidget *parent = nullptr);
    ~HelloVtk();

     void RenderCube();

private:
    Ui::HelloVtk *ui;
};
#endif // HELLOVTK_H
