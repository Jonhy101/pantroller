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
    QScrollArea *scrollAreaPeripContainer=new QScrollArea;
    scrollAreaPeripContainer->setWidget(menuPeripContainer);
    scrollAreaPeripContainer->setWidgetResizable(true);
    // scrollAreaPeripContainer->setStyleSheet(R"(


    //     QScrollBar::drop-down {
    //         subcontrol-origin: padding;
    //         subcontrol-position: top right;
    //         width: 25px;                    /* Ancho del área de la flecha */
    //         border-left: 1px solid #999999;
    //         background-color: #f0f0f0;
    //     }

    //     /* Imagen de la flecha abajo */
    //     QScrollBar::down-arrow {
    //         image: url(:/icons/images/icons/down-arrow-lineEdit.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Imagen de la flecha al presionar con el mouse sobre ella*/
    //     QScrollBar::down-arrow:pressed{
    //         image: url(:/icons/images/icons/down-arrow-lineEdit-Pressed.png);
    //     }

    //     /* Color base del scroll*/
    //     QScrollBar:vertical {
    //         background: #10192d;         /* Fondo del canal donde se desliza la barra*/
    //         width: 12px;                 /* Ancho del scroll */
    //         margin: 0px;
    //         border: none;
    //     }

    //     /* Estilos de la barra */
    //     QScrollBar::handle:vertical {
    //         background: #273754;
    //         min-height: 15px;
    //         border: none;
    //         border-radius: 4px;
    //         outline: none;
    //         margin-top: 12px;           /*con esto la barra no se superpone sobre la flecha superior*/
    //         margin-bottom: 12px;        /*con esto la barra no se superpone sobre la flecha inferior*/
    //     }

    //     /*Estilos al pasar el mouse sobre la barra*/
    //     QScrollBar::handle:vertical:hover{
    //         background: #354970;
    //     }

    //     /* Botón superior (flecha hacia arriba) */
    //     QScrollBar::sub-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     /* Flecha hacia arriba arriba */
    //     QScrollBar::up-arrow:vertical {
    //         image: url(:/icons/images/icons/up-arrowIcon.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Flecha hacia arriba al presionar mouse sobre ella*/
    //     QScrollBar::up-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/up-arrow-pressed.png);
    //     }

    //     /* Botón inferior (flecha hacia abajo) */
    //     QScrollBar::add-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     /* Flecha abajo */
    //     QScrollBar::down-arrow:vertical {
    //         image: url(:/icons/images/icons/down-arrowIcon.png);  /* Puedes reemplazar con una imagen personalizada */
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Flecha abajo al presionar el mouse sobre ella*/
    //     QScrollBar::down-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/down-arrow-pressed.png);
    //     }

    //     /* Sin esto aparece un fondo creado por el sistema*/
    //     QScrollBar::add-page:vertical,
    //     QScrollBar::sub-page:vertical {
    //         background: none;               /*!!Imporante, debe estar en "none" para que se visualicen las flechas*/
    //     }



    // )");
    scrollAreaPeripContainer->setStyleSheet(R"(

        /************** SCROLL VERTICAL **************/
        QScrollBar:vertical {
            background: #10192d;
            width: 12px;
            margin: 0px;
            border: none;
        }

        QScrollBar::handle:vertical {
            background: #273754;
            min-height: 15px;
            border: none;
            border-radius: 4px;
            outline: none;
            margin-top: 12px;
            margin-bottom: 12px;
        }

        QScrollBar::handle:vertical:hover {
            background: #354970;
        }

        QScrollBar::sub-line:vertical {
            background: #273754;
            height: 12px;
            border: solid;
        }

        QScrollBar::add-line:vertical {
            background: #273754;
            height: 12px;
            border: solid;
        }

        QScrollBar::up-arrow:vertical {
            image: url(:/icons/images/icons/up-arrowIcon.png);
            width: 12px;
            height: 12px;
        }

        QScrollBar::up-arrow:vertical:pressed {
            image: url(:/icons/images/icons/up-arrow-pressed.png);
        }

        QScrollBar::down-arrow:vertical {
            image: url(:/icons/images/icons/down-arrowIcon.png);
            width: 12px;
            height: 12px;
        }

        QScrollBar::down-arrow:vertical:pressed {
            image: url(:/icons/images/icons/down-arrow-pressed.png);
        }

        QScrollBar::add-page:vertical,
        QScrollBar::sub-page:vertical {
            background: none;
        }

        /************** SCROLL HORIZONTAL **************/
        QScrollBar:horizontal {
            background: #10192d;
            height: 12px;
            margin: 0px;
            border: none;
        }

        QScrollBar::handle:horizontal {
            background: #273754;
            min-width: 15px;
            border: none;
            border-radius: 4px;
            outline: none;
            margin-left: 12px;
            margin-right: 12px;
        }

        QScrollBar::handle:horizontal:hover {
            background: #354970;
        }

        QScrollBar::sub-line:horizontal {
            background: #273754;
            width: 12px;
            border: solid;
            subcontrol-origin: margin;
            subcontrol-position: left;    /*Esto es necesario para que se pueda ver*/
        }

        QScrollBar::add-line:horizontal {
            background: #273754;
            width: 12px;
            border: solid;
        }

        QScrollBar::left-arrow:horizontal {
            image: url(:/icons/images/icons/left-drow.png);
            width: 12px;
            height: 12px;
        }

        QScrollBar::left-arrow:horizontal:pressed {
            image: url(:/icons/images/icons/left-drow-pressed.png);
        }

        QScrollBar::right-arrow:horizontal {
            image: url(:/icons/images/icons/right-drow.png);
            width: 12px;
            height: 12px;
        }

        QScrollBar::right-arrow:horizontal:pressed {
            image: url(:/icons/images/icons/right-drow-pressed.png);
        }

        QScrollBar::add-page:horizontal,
        QScrollBar::sub-page:horizontal {
            background: none;
        }

    )");

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
    tBtnCpp=WidgetsFactory::createBtnCpp();
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
