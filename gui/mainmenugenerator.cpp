#include "mainmenugenerator.h"
#include "gui/widgetsfactory.h"
#include <QFrame>

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
    btnConfPeriferico->setProperty("index",0);
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

    //botón de filtros
    btnFiltros=WidgetsFactory::createButton("Filtros");
    btnFiltros->setProperty("index",1);
    btnFiltros->setMinimumHeight(40);
    layoutHerramientas->addWidget(btnFiltros);

    //separador
    layoutHerramientas->addWidget(WidgetsFactory::createMenuSeparator());

    //botón de divisor de voltaje
    btnDivVolt=WidgetsFactory::createButton("Divisor de Voltaje");
    btnDivVolt->setProperty("index",2);
    btnDivVolt->setMinimumHeight(40);
    layoutHerramientas->addWidget(btnDivVolt);

    //separador
    layoutHerramientas->addWidget(WidgetsFactory::createMenuSeparator());

    //botón de Convertidor de base numérica
    btnConBase=WidgetsFactory::createButton("Convertidor de Base Numérica");
    btnConBase->setProperty("index",3);
    btnConBase->setMinimumHeight(40);
    layoutHerramientas->addWidget(btnConBase);

    mainLayout->addWidget(containerHerramientas);
    /**********************************************/

    /**************Soporte*************************/
    QWidget *containerSoporte=new QWidget();
    containerSoporte->setStyleSheet("background-color: #1F2B42");
    QVBoxLayout *layoutSoporte=new QVBoxLayout(containerSoporte);
    layoutSoporte->setContentsMargins(0,10,0,10);

    //label soporte
    lblSoporte=WidgetsFactory::createLblMenu("Soporte");
    lblSoporte->setAlignment(Qt::AlignLeft);
    layoutSoporte->addWidget(lblSoporte);

    //botón ayuda
    btnAyuda=WidgetsFactory::createButton("Ayuda");
    btnAyuda->setProperty("index",4);
    btnAyuda->setMinimumHeight(40);
    layoutSoporte->addWidget(btnAyuda);

    //separador
    layoutSoporte->addWidget(WidgetsFactory::createMenuSeparator());

    //botón acerca de
    btnAcercaDe=WidgetsFactory::createButton("Acerca de Pantroller");
    btnAcercaDe->setProperty("index",5);
    btnAcercaDe->setMinimumHeight(40);
    layoutSoporte->addWidget(btnAcercaDe);

    mainLayout->addWidget(containerSoporte);

    //Signals and slots
    connect(btnConfPeriferico,&QPushButton::clicked,this,MainMenuGenerator::onMenuButtonClicked);
    connect(btnFiltros,&QPushButton::clicked,this,MainMenuGenerator::onMenuButtonClicked);
    connect(btnDivVolt,&QPushButton::clicked,this,MainMenuGenerator::onMenuButtonClicked);
    connect(btnConBase,&QPushButton::clicked,this,MainMenuGenerator::onMenuButtonClicked);
    connect(btnAyuda,&QPushButton::clicked,this,MainMenuGenerator::onMenuButtonClicked);
    connect(btnAcercaDe,&QPushButton::clicked,this,MainMenuGenerator::onMenuButtonClicked);
}

void MainMenuGenerator::onMenuButtonClicked(){
    QPushButton *pressedButton=qobject_cast<QPushButton*>(sender());
    int index=pressedButton->property("index").toInt();
    actualizaEstado(pressedButton);
    emit menuOptionSelected(index);
}


void MainMenuGenerator::actualizaEstado(QPushButton *newActiveButton){
    if(activeButton){       //al ejecutar por primera vez, active button es nulo
        activeButton->setChecked(false);
    }
    newActiveButton->setChecked(true);
    activeButton=newActiveButton;
}
