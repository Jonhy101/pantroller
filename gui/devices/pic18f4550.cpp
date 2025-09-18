#include "pic18f4550.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "widgetsfactory.h"
#include <QIcon>
#include <QDebug>
#include <QScrollArea>

GuiPic18f4550::GuiPic18f4550(QWidget *panelOptions, QWidget *panelConf, QWidget *parent)
    :QWidget(parent){
//Componentes de panelOptions
    //Mostrar imagen de pines (pinout)
    QVBoxLayout *mainLayoutOptions= new QVBoxLayout(panelOptions);
    labelPinout=WidgetsFactory::createLblGui("PinOut");
    QHBoxLayout *layoutImageControls=new QHBoxLayout();
    layoutImageControls->setContentsMargins(0,0,0,0);
    layoutImageControls->addWidget(labelPinout);
    layoutImageControls->addStretch();
    mainLayoutOptions->addLayout(layoutImageControls);

    //Contenedor de imagen
    QWidget *imgContainer=new QWidget();
    imgContainer->setStyleSheet("background-color: #10192D");
    imgContainer->hide();
    QVBoxLayout *layoutImgContainer=new QVBoxLayout(imgContainer);
    mainLayoutOptions->addWidget(imgContainer);
    //label con la imagen
    labelImgDisp=new QLabel();
    QPixmap pix(":/imgDevices/images/img_devices/pic18f4550.jpg");
    QPixmap scaled=pix.scaled(300,pix.height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    labelImgDisp->setPixmap(scaled);
    layoutImgContainer->addWidget(labelImgDisp,0,Qt::AlignCenter);

    //botón para mostrar u ocultar imagen de pinout
    QIcon iconShow(":/icons/images/icons/showIcon.png");
    QIcon iconHide(":/icons/images/icons/hideIcon.png");
    btnHideImg=WidgetsFactory::createIconButton();
    btnHideImg->setIcon(iconShow);
    layoutImageControls->addWidget(btnHideImg);
    //slot
    connect(btnHideImg,&QPushButton::clicked,panelOptions,[=](){
        if(imgContainer->isHidden()){
            btnHideImg->setIcon(iconHide);
            imgContainer->show();
        }
        else{
            btnHideImg->setIcon(iconShow);
            imgContainer->hide();
        }
    });

    // QWidget *imgContainer=new QWidget();
    // QVBoxLayout *layoutImgContainer=new QVBoxLayout(imgContainer);
    // mainLayoutOptions->addWidget(imgContainer);
    // //Cargar imagen
    // QGraphicsScene *scene=new QGraphicsScene;
    // QGraphicsPixmapItem *item= scene->addPixmap(QPixmap(":/imgDevices/images/img_devices/pic18f4550.jpg"));
    // QGraphicsView *view= new QGraphicsView(scene);
    // view->setDragMode(QGraphicsView::ScrollHandDrag);
    // layoutImgContainer->addWidget(view);

    //Caracteristicas del dispositivo
    QHBoxLayout *layoutFeaturesControls=new QHBoxLayout();
    layoutFeaturesControls->setContentsMargins(0,0,0,0);
    labelCaract= WidgetsFactory::createLblGui("Características");
    layoutFeaturesControls->addWidget(labelCaract);
    layoutFeaturesControls->addStretch();
    mainLayoutOptions->addLayout(layoutFeaturesControls);
    QWidget *featuresContainer=new QWidget();
    QVBoxLayout *layoutFeaturesCont=new QVBoxLayout(featuresContainer);
    layoutFeaturesCont->setContentsMargins(0,0,0,0);
    mainLayoutOptions->addWidget(featuresContainer);    
    QString features="Fabricante: Microchip\n"
                        "Arquitectura: 8 bits\n"
                        "Memoria de Programa: 32KB\n"
                        "Memoria RAM: 2KB\n"
                        "Memoria EEPROM: 256B\n"
                        "Pines I/O: 35\n"
                        "Conversor A/D: 1, Canales: 10\n"
                        "Módulo CCP (PWM): 1\n"
                        "Módulo ECCP (PWM): 1\n"
                        "Puerto SPP: 1\n"
                        "Puerto MSSP: 1 (I2C/SPI)\n"
                        "Puerto Serie: 1 (EUSART)\n"
                        "Comparadores Analógicos: 2\n"
                        "Timers: 1 de 8 bits, 3 de 16 bits";
    txtEditFeatures= WidgetsFactory::createTextEditInfo(features);

    layoutFeaturesCont->addWidget(txtEditFeatures);
    //Botón para mostrar u ocultar
    btnHideFeatures=WidgetsFactory::createIconButton();
    btnHideFeatures->setIcon(iconHide);
    layoutFeaturesControls->addWidget(btnHideFeatures);
    //slot
    connect(btnHideFeatures, &QPushButton::clicked,this,[=](){
        if(txtEditFeatures->isHidden()){
            btnHideFeatures->setIcon(iconHide);
            txtEditFeatures->show();
        }
        else{
            btnHideFeatures->setIcon(iconShow);
            txtEditFeatures->hide();
        }
    });

    //Menú de periféricos disponibles
    labelPerip=WidgetsFactory::createLblGui("Periféricos");
    mainLayoutOptions->addWidget(labelPerip);
    QWidget *menuPeripContainer=new QWidget();
    menuPeripContainer->setStyleSheet("background-color: #10192D");
    QGridLayout *layoutMenuPerip=new QGridLayout(menuPeripContainer);
    mainLayoutOptions->addWidget(menuPeripContainer);
    //Agregar scroll porque son varios botones y no alcanzan en pantallas estandar
    QScrollArea *scrollAreaPeripContainer=WidgetsFactory::createQScrollArea(menuPeripContainer);
    mainLayoutOptions->addWidget(scrollAreaPeripContainer);

    //botón oscillator
    tBtnOscillator=WidgetsFactory::createBtnCrystal();
    layoutMenuPerip->addWidget(tBtnOscillator,0,0);

    //botón eeprom    
    tBtnEEprom=WidgetsFactory::createBtnEeprom();
    layoutMenuPerip->addWidget(tBtnEEprom,0,1);

    //botón interrupts    
    tBtnInterrupts=WidgetsFactory::createBtnInt();
    layoutMenuPerip->addWidget(tBtnInterrupts,0,2);

    //botón timers    
    tBtnTimers=WidgetsFactory::createBtnTimers();
    layoutMenuPerip->addWidget(tBtnTimers,0,3);

    //botón CPP
    tBtnCpp=WidgetsFactory::createBtnCcp();
    layoutMenuPerip->addWidget(tBtnCpp,1,0);

    //botón ECPP
    tBtnEccp=WidgetsFactory::createBtnEccp();
    layoutMenuPerip->addWidget(tBtnEccp,1,1);

    //botón USB
    tBtnUsb=WidgetsFactory::createBtnUSB();
    layoutMenuPerip->addWidget(tBtnUsb,1,2);

    //botón MSSP
    tBtnMssp=WidgetsFactory::createBtnMssp();
    layoutMenuPerip->addWidget(tBtnMssp,1,3);

    //botón EUSART
    tBtnEusart=WidgetsFactory::createBtnEusart();
    layoutMenuPerip->addWidget(tBtnEusart,2,0);

    //botón ADC
    tBtnADC=WidgetsFactory::createBtnAdc();
    layoutMenuPerip->addWidget(tBtnADC,2,1);

    //botón Comparador
    tBtnComparator=WidgetsFactory::createBtnComparator();
    layoutMenuPerip->addWidget(tBtnComparator,2,2);

    //botón Voltaje de ref. de comparador
    tBtnComparatorVoltRef=WidgetsFactory::createBtnComparatorVRef();
    layoutMenuPerip->addWidget(tBtnComparatorVoltRef,2,3);

    //igualar ancho de las columnas (prueba)
    layoutMenuPerip->setColumnStretch(0,0);
    layoutMenuPerip->setColumnMinimumWidth(0,80);
    layoutMenuPerip->setColumnStretch(1,0);
    layoutMenuPerip->setColumnMinimumWidth(1,80);
    layoutMenuPerip->setColumnStretch(2,0);
    layoutMenuPerip->setColumnMinimumWidth(2,80);
    layoutMenuPerip->setColumnStretch(3,0);
    layoutMenuPerip->setColumnMinimumWidth(3,80);


    //Componentes del panelConf
    QVBoxLayout *mainLayoutConf=new QVBoxLayout(panelConf);
    labelTest2=new QLabel("Panel de configuración");
    mainLayoutConf->addWidget(labelTest2);
}
