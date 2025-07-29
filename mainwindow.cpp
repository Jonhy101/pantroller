#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Pantroller");

    //crear widget central y establecer colores
    QWidget *centralWidget=new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setStyleSheet(R"(
        background-color: #10192d;
    )");
    //icono
    QIcon mainIcon;
    mainIcon.addFile(":/icons/images/icons/mainLogo16x16.ico", QSize(16,16));
    mainIcon.addFile(":/icons/images/icons/mainLogo32x32.ico", QSize(32,32));
    mainIcon.addFile(":/icons/images/icons/mainLogo48x48.ico", QSize(48,48));
    mainIcon.addFile(":/icons/images/icons/mainLogo256x256.ico", QSize(256,256));

    this->setWindowIcon(mainIcon);

}

MainWindow::~MainWindow() {
    delete ui;
}
