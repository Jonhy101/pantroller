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
#include <QLineEdit>
#include <QRadioButton>

GuiPic18f4550::GuiPic18f4550(QWidget *panelOptions, QWidget *panelConf, QWidget *parent)
    :QWidget(parent){
//Componentes de panelOptions
    //Mostrar imagen de pines (pinout)
    mainLayoutOptions= new QVBoxLayout(panelOptions);
    iconShow=QIcon(":/icons/images/icons/showIcon.png");
    iconHide=QIcon(":/icons/images/icons/hideIcon.png");
    iconHelp=QIcon(":/icons/images/icons/helpIcon.png");
    setupPinout();
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
    setupFeatures();

    //Menú de periféricos disponibles
    periphealMenu();

//Componentes del panelConf
    // QVBoxLayout *mainLayoutConf=new QVBoxLayout(panelConf);
    // labelTest2=new QLabel("Panel de configuración");
    // mainLayoutConf->addWidget(labelTest2);
    //QTabWidget para mostrar panel de configuración
    mainLayoutConf=new QVBoxLayout(panelConf);
    tabWidgetPeripheal=new QTabWidget();
    mainLayoutConf->addWidget(tabWidgetPeripheal);
}


void GuiPic18f4550::setupPinout(){
    //Crear y configurar layout
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
    btnHideImg=WidgetsFactory::createIconButton();
    btnHideImg->setIcon(iconShow);
    layoutImageControls->addWidget(btnHideImg);

    //slot
    connect(btnHideImg,&QPushButton::clicked,this,[=](){
        if(imgContainer->isHidden()){
            btnHideImg->setIcon(iconHide);
            imgContainer->show();
        }
        else{
            btnHideImg->setIcon(iconShow);
            imgContainer->hide();
        }
    });
}

void GuiPic18f4550::setupFeatures(){
    //creear y configurar layouts
    QHBoxLayout *layoutFeaturesControls=new QHBoxLayout();
    layoutFeaturesControls->setContentsMargins(0,0,0,0);
    mainLayoutOptions->addLayout(layoutFeaturesControls);

    //titulo de esta sección
    labelCaract= WidgetsFactory::createLblGui("Características");
    layoutFeaturesControls->addWidget(labelCaract);
    layoutFeaturesControls->addStretch();

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

    //Botón para mostrar u ocultar características
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
}

void GuiPic18f4550::periphealMenu(){
    //widget contenedor y layout
    QWidget *menuPeripContainer=new QWidget();
    menuPeripContainer->setStyleSheet("background-color: #10192D");
    mainLayoutOptions->addWidget(menuPeripContainer);
    QGridLayout *layoutMenuPerip=new QGridLayout(menuPeripContainer);

    //título de esta sección
    labelPerip=WidgetsFactory::createLblGui("Periféricos");
    mainLayoutOptions->addWidget(labelPerip);

    //Agregar scroll porque son varios botones y no alcanzan en pantallas estandar
    QScrollArea *scrollAreaPeripContainer=WidgetsFactory::createQScrollArea(menuPeripContainer);
    mainLayoutOptions->addWidget(scrollAreaPeripContainer);

    /********Botones en el menú***********/
    //botón oscillator
    tBtnOscillator=WidgetsFactory::createBtnCrystal();
    layoutMenuPerip->addWidget(tBtnOscillator,0,0);
    connect(tBtnOscillator,&QToolButton::clicked,this,GuiPic18f4550::clickedBtnOscillator);

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
    /*************************************/

    //igualar ancho de las columnas (prueba)
    layoutMenuPerip->setColumnStretch(0,0);
    layoutMenuPerip->setColumnMinimumWidth(0,80);
    layoutMenuPerip->setColumnStretch(1,0);
    layoutMenuPerip->setColumnMinimumWidth(1,80);
    layoutMenuPerip->setColumnStretch(2,0);
    layoutMenuPerip->setColumnMinimumWidth(2,80);
    layoutMenuPerip->setColumnStretch(3,0);
    layoutMenuPerip->setColumnMinimumWidth(3,80);
}

//slots
void GuiPic18f4550::clickedBtnOscillator(){     //Configuración del reloj del microcontrolador
    int index=tabWidgetPeripheal->indexOf(tabOscillator);
    qDebug()<<"El index es:"<<index;
    if(index==-1){
        //Agregar componentes a esta pestaña
        tabOscillator=new QWidget();
        QVBoxLayout *layoutOscContainer=new QVBoxLayout(tabOscillator);

        //Titulo
        QLabel *lblTitulo=WidgetsFactory::createLblGui("Configuración del Cristal de Cuarzo");
        layoutOscContainer->addWidget(lblTitulo,0,Qt::AlignCenter);

        //Input Frecuencia del cristal
        QHBoxLayout *layoutInputFreq=new QHBoxLayout();
        layoutOscContainer->addLayout(layoutInputFreq);
        QLabel *lblFreq=WidgetsFactory::createLblForm("Frecuencia del Cristal (max. 48MHz):");
        layoutInputFreq->addWidget(lblFreq);
        QLineEdit *lineEditFreq=WidgetsFactory::createLineEditForm();
        lineEditFreq->setMaximumWidth(60);
        layoutInputFreq->addWidget(lineEditFreq);
        QLabel *lblMhz=WidgetsFactory::createLblForm("MHz");
        layoutInputFreq->addWidget(lblMhz);
        layoutInputFreq->addStretch();

        //Habilitar/deshabilitar PLL
        QHBoxLayout *layoutPll=new QHBoxLayout();
        layoutPll->setContentsMargins(0,0,0,0);
        layoutOscContainer->addLayout(layoutPll);
        QLabel *lblPll=WidgetsFactory::createLblForm("Habilitar PLL(PLLDIV):");
        layoutPll->addWidget(lblPll);
        //QCheckBox para habilitar o deshabilitar pll
        QCheckBox *checkEnablePLL=WidgetsFactory::createCheckBox("Habilitar");
        layoutPll->addWidget(checkEnablePLL);
        layoutPll->addStretch();                //lo que está antes se va a la izquierda, lo que está después a la derecha
        //botón de ayuda
        QPushButton *btnHelpPLL=WidgetsFactory::createIconButton();
        btnHelpPLL->setIcon(iconHelp);
        layoutPll->addWidget(btnHelpPLL);

        //Postcaler del oscilador->CPUDIV
        const QStringList postScalerOptionsNoPLL={
            "Freq del Cristal dividida por 4",
            "Freq del Cristal dividida por 3",
            "Freq del Cristal dividida por 2",
            "Freq del Cristal sin dividir"
        };
        const QStringList postScalerOptionsPLL={
            "96MHz de PLL dividido por 6",
            "96MHz de PLL dividido por 4",
            "96MHz de PLL dividido por 3",
            "96MHz de PLL dividido por 2"
        };

        //Selección de CPUDIV->Postscaler
        QHBoxLayout *layoutCpudiv=new QHBoxLayout();
        layoutCpudiv->setContentsMargins(0,0,0,0);
        layoutOscContainer->addLayout(layoutCpudiv);
        QLabel *lblCpudiv=WidgetsFactory::createLblForm("Postscaler del Oscilador (CPUDIV):");
        layoutCpudiv->addWidget(lblCpudiv);
        QComboBox *QComboPostcaler=WidgetsFactory::createComboBoxNoSearchable(postScalerOptionsNoPLL);
        layoutCpudiv->addWidget(QComboPostcaler);
        layoutCpudiv->addStretch();

        //Fuente de reloj del módulo USB
        QHBoxLayout *layoutUsbdiv=new QHBoxLayout();
        layoutUsbdiv->setContentsMargins(0,5,0,0);
        layoutOscContainer->addLayout(layoutUsbdiv);
        QLabel *lblUsbdiv=WidgetsFactory::createLblForm("Fuente de reloj de USB (USBDIV):");
        layoutUsbdiv->addWidget(lblUsbdiv,0,Qt::AlignTop);
        //layout para radiobuttons
        QVBoxLayout *layoutRBUsbSource=new QVBoxLayout();
        layoutUsbdiv->addLayout(layoutRBUsbSource);
        QRadioButton *qRBUsbSourceClock=WidgetsFactory::createRBtn("Origen desde PLL, 96MHz dividido por 2");
        layoutRBUsbSource->addWidget(qRBUsbSourceClock);
        qRBUsbSourceClock->setChecked(true);
        QRadioButton *qRBUsbSpeed=WidgetsFactory::createRBtn("Origen desde oscilador primario sin Postscaler");
        layoutRBUsbSource->addWidget(qRBUsbSpeed);
        layoutUsbdiv->addStretch();
        //botón de ayuda
        QPushButton *btnHelpUsbdiv=WidgetsFactory::createIconButton();
        btnHelpUsbdiv->setIcon(iconHelp);
        layoutUsbdiv->addWidget(btnHelpUsbdiv,0,Qt::AlignTop);

        //Habilitar/deshabilitar Full-speed usb
        QHBoxLayout *layoutUsbSpeed=new QHBoxLayout();
        layoutUsbSpeed->setContentsMargins(0,0,0,0);
        layoutOscContainer->addLayout(layoutUsbSpeed);
        layoutOscContainer->setAlignment(layoutUsbSpeed,Qt::AlignTop);
        QLabel *lblUsbSpeed=WidgetsFactory::createLblForm("Habilitar Full-Speed USB (FSEN):");
        layoutUsbSpeed->addWidget(lblUsbSpeed);
        //QCheckBox para habilitar o deshabilitar full-speed usb
        QCheckBox *checkEnableUsbSpeed=WidgetsFactory::createCheckBox("Habilitar");
        layoutUsbSpeed->addWidget(checkEnableUsbSpeed);
        layoutUsbSpeed->addStretch();                //lo que está antes se va a la izquierda, lo que está después a la derecha
        //botón de ayuda
        QPushButton *btnHelpUsbSpeed=WidgetsFactory::createIconButton();
        btnHelpUsbSpeed->setIcon(iconHelp);
        layoutUsbSpeed->addWidget(btnHelpUsbSpeed);

        //Subir todo hacia arriba
        layoutOscContainer->addStretch();
        //Agregar Pestaña
        index=tabWidgetPeripheal->addTab(tabOscillator,"Oscillator");
        qDebug()<<"Se creó pestaña, ahora index="<<index;

        //slot de checkEnablePLL
        connect(checkEnablePLL,&QCheckBox::toggled,this,[=](){
            QComboPostcaler->clear();
            if(checkEnablePLL->isChecked()){
                QComboPostcaler->addItems(postScalerOptionsPLL);
            }
            else{
                QComboPostcaler->addItems(postScalerOptionsNoPLL);
            }
            QComboPostcaler->setCurrentIndex(0);
        });
    }
    tabWidgetPeripheal->setCurrentIndex(index);

}
