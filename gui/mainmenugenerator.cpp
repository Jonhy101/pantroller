#include "mainmenugenerator.h"
#include "gui/widgetsfactory.h"

MainMenuGenerator::MainMenuGenerator(QWidget *parent)
    :QWidget(parent){

    this->setStyleSheet("background-color: #151E36");
    QVBoxLayout *mainLayout=new QVBoxLayout(this);

    /*********Menu configurar periférico***********/
    QWidget *containerMPerifericos=new QWidget();
    containerMPerifericos->setStyleSheet("background-color: #1F2B42");
    QVBoxLayout *layoutPerifericos=new QVBoxLayout(containerMPerifericos);
    layoutPerifericos->setContentsMargins(0,10,0,10);

    //label de titulo
    lblTitPeriferico=WidgetsFactory::createLblMenu("Configurar Periférico");
    lblTitPeriferico->setAlignment(Qt::AlignLeft);
    layoutPerifericos->addWidget(lblTitPeriferico);

    //botón de configurar periferico
    btnConfPeriferico=WidgetsFactory::createButton("Seleccionar Dispositivo");
    btnConfPeriferico->setMinimumHeight(40);
    layoutPerifericos->addWidget(btnConfPeriferico);

    //agregar widget contenedor al layout principal
    mainLayout->addWidget(containerMPerifericos);
    /**********************************************/

    /*********Menú de otras herramientas***********/
    QWidget *containerHerramientas=new QWidget();
    containerHerramientas->setStyleSheet("background-color: #1F2B42");
    QVBoxLayout *layoutHerramientas=new QVBoxLayout(containerHerramientas);
    layoutHerramientas->setContentsMargins(0,10,0,10);

    //label de titulo
    lblOtrasHerr=WidgetsFactory::createLblMenu("Otras Herramientas");
    lblOtrasHerr->setAlignment(Qt::AlignLeft);
    layoutHerramientas->addWidget(lblOtrasHerr);

    btnFiltros=WidgetsFactory::createButton("Filtros");
    btnFiltros->setMinimumHeight(40);
    layoutHerramientas->addWidget(btnFiltros);

    btnDivVolt=WidgetsFactory::createButton("Divisor de Voltaje");
    btnDivVolt->setMinimumHeight(40);
    layoutHerramientas->addWidget(btnDivVolt);

    btnConBase=WidgetsFactory::createButton("Convertidor de Base Numérica");
    btnConBase->setMinimumHeight(40);
    layoutHerramientas->addWidget(btnConBase);

    mainLayout->addWidget(containerHerramientas);
    /**********************************************/

    /**************Soporte*************************/
    QWidget *containerSoporte=new QWidget();
    containerSoporte->setStyleSheet("background-color: #1F2B42");
    QVBoxLayout *layoutSoporte=new QVBoxLayout(containerSoporte);
    layoutSoporte->setContentsMargins(0,10,0,10);

    lblSoporte=WidgetsFactory::createLblMenu("Soporte");
    lblSoporte->setAlignment(Qt::AlignLeft);
    layoutSoporte->addWidget(lblSoporte);

    btnAyuda=WidgetsFactory::createButton("Ayuda");
    btnAyuda->setMinimumHeight(40);
    layoutSoporte->addWidget(btnAyuda);

    btnAcercaDe=WidgetsFactory::createButton("Acerca de Pantroller");
    btnAcercaDe->setMinimumHeight(40);
    layoutSoporte->addWidget(btnAcercaDe);

    mainLayout->addWidget(containerSoporte);

    //Signals and slots
    connect(btnConfPeriferico,&QPushButton::clicked,this,MainMenuGenerator::onConfPerifericoClicked);
    connect(btnFiltros,&QPushButton::clicked,this,MainMenuGenerator::onFiltrosClicked);
    connect(btnDivVolt,&QPushButton::clicked,this,MainMenuGenerator::onDivVoltClicked);
    connect(btnConBase,&QPushButton::clicked,this,MainMenuGenerator::onConBaseClicked);
    connect(btnAyuda,&QPushButton::clicked,this,MainMenuGenerator::onAyudaClicked);
    connect(btnAcercaDe,&QPushButton::clicked,this,MainMenuGenerator::onAcercaDeClicked);

}

void MainMenuGenerator::onConfPerifericoClicked(){
    emit menuOptionSelected(0);
}

void MainMenuGenerator::onFiltrosClicked(){
    emit menuOptionSelected(1);
}

void MainMenuGenerator::onDivVoltClicked(){
    emit menuOptionSelected(2);
}

void MainMenuGenerator::onConBaseClicked(){
    emit menuOptionSelected(3);
}

void MainMenuGenerator::onAyudaClicked(){
    emit menuOptionSelected(4);
}

void MainMenuGenerator::onAcercaDeClicked(){
    emit menuOptionSelected(5);
}
