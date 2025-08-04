#include "widgetsfactory.h"
#include <QLineEdit>
#include <QAbstractItemView>

QLabel* WidgetsFactory::createLblMenu(const QString &text, QWidget *parent){
    QLabel *lbl=new QLabel(text,parent);
    lbl->setStyleSheet(R"(
        font-size: 17px;
        padding-left: 5px;
    )");
    return lbl;
}

QPushButton* WidgetsFactory::createButton(const QString &text, QWidget *parent){
    QPushButton *btn=new QPushButton(text,parent);
    btn->setStyleSheet(R"(
        QPushButton{
            background-color: #1F2B42;
            border-style: none;
            font-size: 15px;
            text-align: left;
            padding-left: 15px;
            padding-right: 15px;
        }

        QPushButton:hover{
            background-color: #354970;
        }

        QPushButton:pressed{
            background-color: #273754;
        }

        QPushButton:checked{
            background-color: #273754;
        }
    )");
    btn->setCheckable(true);
    return btn;
}

QPushButton* WidgetsFactory::createControlButton(const QString &text, QWidget *parent){
    QPushButton *btnControl=new QPushButton(text,parent);
    btnControl->setStyleSheet(R"(
        QPushButton{
            background-color: #4E7FE3;
            border-style: none;
            border-radius: 5px;
            font-size: 15px;
            padding-left: 15px;
            padding-right: 15px;
        }

        QPushButton::disabled{
            background-color: #86a5e3;
            color: #595959;
        }

        QPushButton:hover{
            background-color: #578bf7;
        }

        QPushButton:pressed{
            background-color: #426cc2;
        }
    )");
    btnControl->setFixedHeight(30);
    return btnControl;
}

QComboBox* WidgetsFactory::createComboBoxSearchable(const QStringList &itemList, QWidget *parent){
    QComboBox *comboBox=new QComboBox(parent);
    comboBox->setStyleSheet(R"(
        /* Estilo principal del QComboBox (parte visible antes de desplegar) */
        QComboBox {
            background-color: #ffffff;
            border: none;
            color: #10192D;
            font-size: 15px;
            margin: 0px;
        }

        /* Flecha de despliegue del QComboBox */
        QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 25px;                    /* Ancho del área de la flecha */
            border-left: 1px solid #999999;
            background-color: #f0f0f0;
        }

        /* Imagen de la flecha */
        QComboBox::down-arrow {
            image: url(:/icons/images/icons/down-arrow-lineEdit.png);
            width: 12px;
            height: 12px;
        }

        /*Imagen de la flecha al presionar con el mouse sobre ella*/
        QComboBox::down-arrow:pressed{
            image: url(:/icons/images/icons/down-arrow-lineEdit-Pressed.png);
        }

        /*Colores del la lista*/
        QComboBox QAbstractItemView{
            background-color: #ffffff;       /* Fondo de la lista desplegable */
            color: #10192D;                  /* Color del texto de los ítems */
            selection-background-color: #273754; /* Fondo cuando se pasa el mouse o se selecciona */
            selection-color: red;            /* Color del texto cuando se pasa el mouse o se selecciona */
            border: none;                    /* Borde de la lista desplegable */
            outline: none;                   /* Sin contorno */
            padding: 0px;
        }

        /*Color de un Item al pasar el mouse sobre el*/
        QComboBox QAbstractItemView::item:hover {
            background-color: #10192D;       /* Cambia el color de fondo al pasar el mouse */
            color: white;                    /* Cambia el color del texto si deseas */
        }

        /* Color base del scroll*/
        QComboBox QScrollBar:vertical {
            background: #10192d;         /* Fondo del canal donde se desliza la barra*/
            width: 12px;                 /* Ancho del scroll */
            margin: 0px;
            border: none;
        }

        /* Estilos de la barra */
        QComboBox QScrollBar::handle:vertical {
            background: #273754;
            min-height: 15px;
            border: none;
            border-radius: 4px;
            outline: none;
            margin-top: 12px;           /*con esto la barra no se superpone sobre la flecha superior*/
            margin-bottom: 12px;        /*con esto la barra no se superpone sobre la flecha inferior*/
        }

        /*Estilos al pasar el mouse sobre la barra*/
        QComboBox QScrollBar::handle:vertical:hover{
            background: #354970;
        }

        /* Botón superior (flecha hacia arriba) */
        QComboBox QScrollBar::sub-line:vertical {
            background: #273754;
            height: 12px;
            border: solid;
        }

        /* Flecha hacia arriba arriba */
        QComboBox QScrollBar::up-arrow:vertical {
            image: url(:/icons/images/icons/up-arrowIcon.png);
            width: 12px;
            height: 12px;
        }

        /*Flecha hacia arriba al presionar mouse sobre ella*/
        QComboBox QScrollBar::up-arrow:vertical:pressed {
            image: url(:/icons/images/icons/up-arrow-pressed.png);
        }

        /* Botón inferior (flecha hacia abajo) */
        QComboBox QScrollBar::add-line:vertical {
            background: #273754;
            height: 12px;
            border: solid;
        }

        /* Flecha abajo */
        QComboBox QScrollBar::down-arrow:vertical {
            image: url(:/icons/images/icons/down-arrowIcon.png);  /* Puedes reemplazar con una imagen personalizada */
            width: 12px;
            height: 12px;
        }

        /*Flecha abajo al presionar el mouse sobre ella*/
        QComboBox QScrollBar::down-arrow:vertical:pressed {
            image: url(:/icons/images/icons/down-arrow-pressed.png);
        }

        /* Sin esto aparece un fondo creado por el sistema*/
        QComboBox QScrollBar::add-page:vertical,
        QComboBox QScrollBar::sub-page:vertical {
            background: none;               /*!!Imporante, debe estar en "none" para que se visualicen las flechas*/
        }

    )");
    comboBox->addItems(itemList);
    comboBox->setMaxVisibleItems(5);
    comboBox->setInsertPolicy(QComboBox::NoInsert);
    comboBox->setEditable(true);
    comboBox->setCurrentIndex(-1);          //importante colocar después de haber agregado los item
    if(comboBox->lineEdit()){               //si existe un qlineedit se ingresa, al no existir es un nullptr
        comboBox->lineEdit()->setPlaceholderText("elige un dispositivo...");
    }
    return comboBox;
}


void WidgetsFactory::adjustComboBoxWidth(QComboBox* comboBox){
    //obtener los textos en forma de QStringList
    QStringList items;
    for (int i = 0; i < comboBox->count(); ++i) {
        items << comboBox->itemText(i);
    }
    QFontMetrics fm(comboBox->font());
    int maxWidth = 0;
    for (int i = 0; i < items.size(); ++i) {
        const QString& item = items[i];
        int width = fm.horizontalAdvance(item);
        if (width > maxWidth)
            maxWidth = width;
    }
    // Sumar un margen extra para que no quede muy justo
    maxWidth += 30;
    // Establecer el ancho del popup
    comboBox->view()->setMinimumWidth(maxWidth);
}


QFrame* WidgetsFactory::createMenuSeparator(){
    QFrame *separator=new QFrame();
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Plain);
    separator->setFixedHeight(2);
    separator->setStyleSheet(R"(
        background-color: #10192D;
        margin-left: 15px;
        margin-right: 15px;
        border: none;
    )");
    return separator;
}



