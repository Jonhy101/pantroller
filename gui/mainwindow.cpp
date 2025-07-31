#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


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

    //layout principal, eliminando márgenes
    QVBoxLayout *mainLayout=new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0,0,0,0);

    /**********parte superior, logo, nombre y versión del programa*********/
    QWidget *headerWidget=new QWidget();
    headerWidget->setFixedHeight(64);
    headerWidget->setStyleSheet("background-color: #1F2B42;");
    mainLayout->addWidget(headerWidget);

    //layout del encabezado
    QHBoxLayout *layoutHeader=new QHBoxLayout(headerWidget);

    //logo
    labelLogo=new QLabel();
    QPixmap qpixLogo(":/icons/images/icons/mainLogo.png");
    QPixmap qpixLogoScaled= qpixLogo.scaled(48,48,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    labelLogo->setPixmap(qpixLogoScaled);
    layoutHeader->addWidget(labelLogo,0,Qt::AlignVCenter);

    //nombre
    labelNombrePrograma=new QLabel("Pantroller");
    labelNombrePrograma->setStyleSheet(R"(
        font-size: 24px;
        color: #4E7FE3;
        font-weight: bold;
    )");

    //versión
    layoutHeader->addWidget(labelNombrePrograma);
    layoutHeader->addStretch();
    layoutHeader->addWidget(new QLabel("Version 1.0"));
    /***********************************************************************/

    //Layout de los paneles del programa
    QHBoxLayout *layoutPaneles=new QHBoxLayout();
    mainMenuPanel=new MainMenuGenerator(this);
    layoutPaneles->addWidget(mainMenuPanel);    
    mainLayout->addLayout(layoutPaneles);

    //subir todo hacia arriba
    mainLayout->addStretch();

    //Signals and slots
    connect(mainMenuPanel,MainMenuGenerator::menuOptionSelected,this,&MainWindow::cambiarPanel);

}

void MainWindow::cambiarPanel(int index){
    qDebug()<<"Cambiando al panel: "<<index;
}

MainWindow::~MainWindow() {
    delete ui;
}
