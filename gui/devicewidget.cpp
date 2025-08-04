#include "devicewidget.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QListView>
#include <QLineEdit>
#include <QMessageBox>
#include "logic/devices.h"

DeviceWidget::DeviceWidget(QWidget *parent):QWidget(parent) {

    //establecer color de fondo y layout pricipal
    this->setStyleSheet("background-color: #151E36");
    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    //Panel de selección de dispositivo
    QWidget *panelSelDisp=new QWidget();
    QVBoxLayout *layoutSelDisp=new QVBoxLayout(panelSelDisp);    

    //Selección de dispositivo
    QHBoxLayout *layoutSeleccion=new QHBoxLayout();
    labelSeleccion=new QLabel("Selección de dispositivo:");
    labelSeleccion->setStyleSheet("font-size: 15px;");
    layoutSeleccion->addWidget(labelSeleccion,1);
    layoutSelDisp->addLayout(layoutSeleccion);

    //QComboBox para busqueda y selección de dispositivo
    QStringList devicesList=Devices::getDevicesList();
    cbSelectDevice=WidgetsFactory::createComboBoxSearchable(devicesList);
    WidgetsFactory::adjustComboBoxWidth(cbSelectDevice);
    layoutSeleccion->addWidget(cbSelectDevice,2);
    mainLayout->addWidget(panelSelDisp,1);
    //Ajustar tamaño del combobox




    //botón para confirmar elección
    QHBoxLayout *layoutControls=new QHBoxLayout();      //layout para limitar el ancho del botón
    layoutControls->addStretch();
    btnConfirmDevice=WidgetsFactory::createControlButton("Confirmar Selección");    
    layoutControls->addWidget(btnConfirmDevice);
    layoutControls->addStretch();
    layoutSelDisp->addSpacing(10);
    layoutSelDisp->addLayout(layoutControls);
    //slot
    connect(btnConfirmDevice,&QPushButton::clicked,this,[=](){
        QString textoActual=cbSelectDevice->currentText();
        QString textoActualMayusculas=textoActual.toUpper();
        int index=cbSelectDevice->findText(textoActualMayusculas,Qt::MatchExactly);
        if(index!=-1)
            qDebug()<<"Se presionó el botón, el index es: "<<index;
        else{
            if(textoActualMayusculas.isEmpty()){
                QMessageBox::critical(this,"Error","No has ingresado ningún dato");
            }
            else{
                QString errorText = "Error en la referencia seleccionada\nLa referencia: " + textoActualMayusculas + " no fue encontrada";
                qDebug()<<"Se presionó el botón, el texto no es valido";
                QMessageBox::critical(this,"Error",errorText);
            }
        }
    });
    layoutSelDisp->addStretch();

    //Panel de configuración de periferico y salida
    QWidget *panelConf=new QWidget();
    panelConf->setStyleSheet("background-color: #151E36");
    mainLayout->addWidget(panelConf,2);
}

