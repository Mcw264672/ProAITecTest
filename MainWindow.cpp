#include "MainWindow.h"
#include "CADLab.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    m_CADLab = new CADLab(this);
    if (m_CADLab)
    {
        m_CADLab->LaunchCADWindow();
    }
    setCentralWidget(m_CADLab->GetQMainWin());
}
