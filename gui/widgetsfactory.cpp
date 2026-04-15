#include "widgetsfactory.h"
#include <QLineEdit>
#include <QAbstractItemView>
#include <QScrollBar>
#include <QListView>

QLabel* WidgetsFactory::createLblMenu(const QString &text, QWidget *parent){
    QLabel *lbl=new QLabel(text,parent);
    lbl->setProperty("tipo","label-menu");
    // lbl->setStyleSheet(R"(
    //     font-size: 17px;
    //     padding-left: 5px;
    // )");
    return lbl;
}

QTextEdit* WidgetsFactory::createTextEditInfo(const QString &text, QWidget *parent){
    QTextEdit *textEdit=new QTextEdit(parent);
    textEdit->setPlainText(text);
    textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);
    // textEdit->setStyleSheet(R"(
    //     QTextEdit{
    //         background-color: #10192D;
    //         padding-left: 5px;
    //         border: none;
    //     }
    //     /* Flecha de despliegue del QComboBox */
    //     QScrollBar::drop-down {
    //         subcontrol-origin: padding;
    //         subcontrol-position: top right;
    //         width: 25px;                    /* Ancho del área de la flecha */
    //         border-left: 1px solid #999999;
    //         background-color: #f0f0f0;
    //     }

    //     /* Imagen de la flecha */
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
    // Asignar propiedad al QTextEdit
    textEdit->setProperty("tipo", "text-Edit");

    // Propagar propiedad al QScrollBar vertical hijo
    QScrollBar* vScroll = textEdit->verticalScrollBar();
    if (vScroll) {
        vScroll->setProperty("tipo", "text-Edit-scroll");
        // Forzar recálculo del estilo después de setProperty
        // vScroll->style()->unpolish(vScroll);
        // vScroll->style()->polish(vScroll);
    }

    // Forzar recálculo del estilo del QTextEdit también
    // textEdit->style()->unpolish(textEdit);
    // textEdit->style()->polish(textEdit);
    return textEdit;
}

QLineEdit* WidgetsFactory::createLineEditForm(QWidget *parent){
    QLineEdit *myQLineEdit=new QLineEdit(parent);
    myQLineEdit->setAlignment(Qt::AlignRight);
    myQLineEdit->setProperty("tipo","form-LineEdit");

    // myQLineEdit->setStyleSheet(R"(
    //     QLineEdit{
    //         font-size: 13px;
    //         font-weight: bold;
    //         background-color: #FFFFFF;
    //         color: #10192D;
    //         border: none;
    //     }
    // )");
    return myQLineEdit;
}

/*Crea buttons para el menú principal
 *
 */
QPushButton* WidgetsFactory::createButton(const QString &text, QWidget *parent){
    QPushButton *btn=new QPushButton(text,parent);
    btn->setProperty("tipo","main-menu-button");
    // btn->setStyleSheet(R"(
    //     QPushButton{
    //         background-color: #1F2B42;
    //         border: none;
    //         font-size: 15px;
    //         text-align: left;
    //         padding-left: 15px;
    //         padding-right: 15px;
    //     }

    //     QPushButton:hover{
    //         background-color: #354970;
    //     }

    //     QPushButton:pressed{
    //         background-color: #273754;
    //     }

    //     QPushButton:checked{
    //         background-color: #274372;
    //         border-style: solid;
    //         border-width: 0px 0px 0px 4px;
    //         border-left-color: #4e7fe3;
    //     }
    // )");
    btn->setCheckable(true);
    return btn;
}

QToolButton* WidgetsFactory::createBtnPeriphelal(const QString &text, const QString &iconPath, const QString &textToolTip, QWidget *parent){
    QToolButton *myButton=new QToolButton(parent);
    myButton->setText(text);
    QIcon buttonIcon(iconPath);
    myButton->setIcon(buttonIcon);
    myButton->setToolTip(textToolTip);
    myButton->setIconSize(QSize(64,64));
    myButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    myButton->setMinimumWidth(80);
    myButton->setProperty("tipo","perip-button");
    // myButton->setStyleSheet(R"(
    //     QToolButton{
    //         background-color: #10192D;
    //         border: 2px solid #3056AB;
    //         border-radius:5px;
    //     }

    //     QToolButton:hover{
    //         background-color: #233661;
    //     }

    //     QToolButton:pressed{
    //         background-color: #273754;;
    //     }
    // )");

    return myButton;
}

QPushButton* WidgetsFactory::createControlButton(const QString &text, QWidget *parent){
    QPushButton *btnControl=new QPushButton(text,parent);
    // btnControl->setStyleSheet(R"(
    //     QPushButton{
    //         background-color: #4E7FE3;
    //         border-style: none;
    //         border-radius: 5px;
    //         font-size: 15px;
    //         padding-left: 15px;
    //         padding-right: 15px;
    //     }

    //     QPushButton::disabled{
    //         background-color: #86a5e3;
    //         color: #595959;
    //     }

    //     QPushButton:hover{
    //         background-color: #578bf7;
    //     }

    //     QPushButton:pressed{
    //         background-color: #426cc2;
    //     }
    // )");
    btnControl->setProperty("tipo","control-button");
    btnControl->setFixedHeight(30);
    return btnControl;
}

QPushButton* WidgetsFactory::createIconButton(QWidget *parent){
    QPushButton *btnIcon=new QPushButton(parent);
    btnIcon->setProperty("tipo","button-icon");
    // btnIcon->setStyleSheet(R"(
    //     QPushButton{
    //         background-color: transparent;
    //         border-style: none;
    //         border-radius: 5px;
    //         padding: 5px;
    //     }

    //     QPushButton:hover{
    //         background-color: #354970;
    //     }

    //     QPushButton:pressed{
    //         background-color: #273754;
    //     }
    // )");
    return btnIcon;
}

QComboBox* WidgetsFactory::createComboBoxSearchable(const QStringList &itemList, QWidget *parent){
    QComboBox *comboBox=new QComboBox(parent);    
    // comboBox->setStyleSheet(R"(
    //     /* Estilo principal del QComboBox (parte visible antes de desplegar) */
    //     QComboBox {
    //         background-color: #ffffff;
    //         border: none;
    //         color: #10192D;
    //         font-size: 15px;
    //         margin: 0px;
    //     }

    //     /* Flecha de despliegue del QComboBox */
    //     QComboBox::drop-down {
    //         subcontrol-origin: padding;
    //         subcontrol-position: top right;
    //         width: 25px;                    /* Ancho del área de la flecha */
    //         border-left: 1px solid #999999;
    //         background-color: #f0f0f0;
    //     }

    //     /* Imagen de la flecha */
    //     QComboBox::down-arrow {
    //         image: url(:/icons/images/icons/down-arrow-lineEdit.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Imagen de la flecha al presionar con el mouse sobre ella*/
    //     QComboBox::down-arrow:pressed{
    //         image: url(:/icons/images/icons/down-arrow-lineEdit-Pressed.png);
    //     }

    //     /*Colores del la lista*/
    //     QComboBox QAbstractItemView{
    //         background-color: #ffffff;       /* Fondo de la lista desplegable */
    //         color: #10192D;                  /* Color del texto de los ítems */
    //         selection-background-color: #273754; /* Fondo cuando se pasa el mouse o se selecciona */
    //         selection-color: red;            /* Color del texto cuando se pasa el mouse o se selecciona */
    //         border: none;                    /* Borde de la lista desplegable */
    //         outline: none;                   /* Sin contorno */
    //         padding: 0px;
    //     }

    //     /*Color de un Item al pasar el mouse sobre el*/
    //     QComboBox QAbstractItemView::item:hover {
    //         background-color: #10192D;       /* Cambia el color de fondo al pasar el mouse */
    //         color: white;                    /* Cambia el color del texto si deseas */
    //     }

    //     /* Color base del scroll*/
    //     QComboBox QScrollBar:vertical {
    //         background: #10192d;         /* Fondo del canal donde se desliza la barra*/
    //         width: 12px;                 /* Ancho del scroll */
    //         margin: 0px;
    //         border: none;
    //     }

    //     /* Estilos de la barra */
    //     QComboBox QScrollBar::handle:vertical {
    //         background: #273754;
    //         min-height: 15px;
    //         border: none;
    //         border-radius: 4px;
    //         outline: none;
    //         margin-top: 12px;           /*con esto la barra no se superpone sobre la flecha superior*/
    //         margin-bottom: 12px;        /*con esto la barra no se superpone sobre la flecha inferior*/
    //     }

    //     /*Estilos al pasar el mouse sobre la barra*/
    //     QComboBox QScrollBar::handle:vertical:hover{
    //         background: #354970;
    //     }

    //     /* Botón superior (flecha hacia arriba) */
    //     QComboBox QScrollBar::sub-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     /* Flecha hacia arriba arriba */
    //     QComboBox QScrollBar::up-arrow:vertical {
    //         image: url(:/icons/images/icons/up-arrowIcon.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Flecha hacia arriba al presionar mouse sobre ella*/
    //     QComboBox QScrollBar::up-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/up-arrow-pressed.png);
    //     }

    //     /* Botón inferior (flecha hacia abajo) */
    //     QComboBox QScrollBar::add-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     /* Flecha abajo */
    //     QComboBox QScrollBar::down-arrow:vertical {
    //         image: url(:/icons/images/icons/down-arrowIcon.png);  /* Puedes reemplazar con una imagen personalizada */
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Flecha abajo al presionar el mouse sobre ella*/
    //     QComboBox QScrollBar::down-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/down-arrow-pressed.png);
    //     }

    //     /* Sin esto aparece un fondo creado por el sistema*/
    //     QComboBox QScrollBar::add-page:vertical,
    //     QComboBox QScrollBar::sub-page:vertical {
    //         background: none;               /*!!Importante, debe estar en "none" para que se visualicen las flechas*/
    //     }

    // )");
    comboBox->setProperty("tipo","qcombo-box-list");
    // El scroll está dentro de la vista de la lista desplegable
    QScrollBar* vScroll = comboBox->view()->verticalScrollBar();
    if (vScroll) {
        vScroll->setProperty("tipo", "qcombo-box-list-scroll");
        vScroll->style()->unpolish(vScroll);
        vScroll->style()->polish(vScroll);
    }

    // Forzar recálculo del estilo del QComboBox
    comboBox->style()->unpolish(comboBox);
    comboBox->style()->polish(comboBox);

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

QComboBox* WidgetsFactory::createComboBoxNoSearchable(const QStringList &itemList, QWidget *parent){
    QComboBox *comboBox=new QComboBox(parent);
    QListView *listView = new QListView(comboBox);  //necesario para que funcionen los estilos
    comboBox->setView(listView);                    //necesario para que funcionen los estilos
    // comboBox->setStyleSheet(R"(
    //     /* Estilo principal del QComboBox (parte visible antes de desplegar) */
    //     QComboBox {
    //         background-color: #ffffff;
    //         min-height: 23px;
    //         border: 2px solid #274372;
    //         border-radius: 3px;
    //         color: #10192D;
    //         font-size: 13px;
    //         margin: 0px;
    //     }

    //     /* Flecha de despliegue del QComboBox */
    //     QComboBox::drop-down {
    //         subcontrol-origin: padding;
    //         subcontrol-position: top right;
    //         width: 25px;                    /* Ancho del área de la flecha */
    //         border: 0px;
    //         background-color: #f0f0f0;
    //     }

    //     /* Imagen de la flecha */
    //     QComboBox::down-arrow {
    //         image: url(:/icons/images/icons/down-arrow-lineEdit.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Imagen de la flecha al presionar con el mouse sobre ella*/
    //     QComboBox::down-arrow:pressed{
    //         image: url(:/icons/images/icons/down-arrow-lineEdit-Pressed.png);
    //     }

    //     /*Colores del la lista*/
    //     QComboBox QAbstractItemView{
    //         background-color: #ffffff;          /* Fondo de la lista desplegable */
    //         color: #10192D;                     /* Color del texto de los ítems */
    //         font-size: 13px;
    //         selection-background-color: #10192d;/* Fondo cuando se pasa el mouse o se selecciona */
    //         selection-color: white;             /* Color del texto cuando se pasa el mouse o se selecciona */
    //         border: 2px solid #274372;          /* Borde de la lista desplegable */
    //         border-radius: 3px;
    //         outline: none;                      /* Sin contorno */
    //         padding: 0px;
    //     }

    //     /*Color de un Item al pasar el mouse sobre el*/
    //     QComboBox QAbstractItemView::item:hover {
    //         background-color: #10192D;       /* Cambia el color de fondo al pasar el mouse */
    //         color: white;                    /* Cambia el color del texto si deseas */
    //     }

    //     /* Color base del scroll*/
    //     QComboBox QScrollBar:vertical {
    //         background: #10192d;         /* Fondo del canal donde se desliza la barra*/
    //         width: 12px;                 /* Ancho del scroll */
    //         margin: 0px;
    //         border: none;
    //     }

    //     /* Estilos de la barra */
    //     QComboBox QScrollBar::handle:vertical {
    //         background: #273754;
    //         min-height: 15px;
    //         border: none;
    //         border-radius: 4px;
    //         outline: none;
    //         margin-top: 12px;           /*con esto la barra no se superpone sobre la flecha superior*/
    //         margin-bottom: 12px;        /*con esto la barra no se superpone sobre la flecha inferior*/
    //     }

    //     /*Estilos al pasar el mouse sobre la barra*/
    //     QComboBox QScrollBar::handle:vertical:hover{
    //         background: #354970;
    //     }

    //     /* Botón superior (flecha hacia arriba) */
    //     QComboBox QScrollBar::sub-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     /* Flecha hacia arriba arriba */
    //     QComboBox QScrollBar::up-arrow:vertical {
    //         image: url(:/icons/images/icons/up-arrowIcon.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Flecha hacia arriba al presionar mouse sobre ella*/
    //     QComboBox QScrollBar::up-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/up-arrow-pressed.png);
    //     }

    //     /* Botón inferior (flecha hacia abajo) */
    //     QComboBox QScrollBar::add-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     /* Flecha abajo */
    //     QComboBox QScrollBar::down-arrow:vertical {
    //         image: url(:/icons/images/icons/down-arrowIcon.png);  /* Puedes reemplazar con una imagen personalizada */
    //         width: 12px;
    //         height: 12px;
    //     }

    //     /*Flecha abajo al presionar el mouse sobre ella*/
    //     QComboBox QScrollBar::down-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/down-arrow-pressed.png);
    //     }

    //     /* Sin esto aparece un fondo creado por el sistema*/
    //     QComboBox QScrollBar::add-page:vertical,
    //     QComboBox QScrollBar::sub-page:vertical {
    //         background: none;               /*!!Imporante, debe estar en "none" para que se visualicen las flechas*/
    //     }

    // )");
    // Propiedades para los selectores de atributo
    comboBox->setProperty("tipo", "qcombo-box-no-edit");

    // Propagar propiedad al QListView para sus estilos
    listView->setProperty("tipo", "qcombo-box-no-edit-view");
    listView->style()->unpolish(listView);
    listView->style()->polish(listView);

    // Propagar propiedad al scrollbar del QListView
    QScrollBar *vScroll = comboBox->view()->verticalScrollBar();
    if (vScroll) {
        vScroll->setProperty("tipo", "qcombo-box-no-edit-scroll");
        vScroll->style()->unpolish(vScroll);
        vScroll->style()->polish(vScroll);
    }

    comboBox->style()->unpolish(comboBox);
    comboBox->style()->polish(comboBox);
    //Agregar items
    comboBox->addItems(itemList);
    comboBox->setMaxVisibleItems(5);
    comboBox->setInsertPolicy(QComboBox::NoInsert);
    comboBox->setEditable(false);
    comboBox->setCurrentIndex(0);          //importante colocar después de haber agregado los item
    if(comboBox->lineEdit()){               //si existe un qlineedit se ingresa, al no existir es un nullptr
        comboBox->lineEdit()->setPlaceholderText("elige un dispositivo...");
    }
    return comboBox;
}

QCheckBox* WidgetsFactory::createCheckBox(const QString &text, QWidget *parent){
    QCheckBox *myCheckBox=new QCheckBox(text,parent);
    myCheckBox->setProperty("tipo","form-check-box");
    // myCheckBox->setStyleSheet(R"(
    //     QCheckBox{
    //         font-size: 13px;
    //         padding-left: 20px;
    //     }

    //     /* Estado: No marcado */
    //     QCheckBox::indicator:unchecked {
    //         image: url(:/icons/images/icons/ChBoxNoOk.png);
    //         width: 13px;  /* Ajusta el tamaño según tu imagen */
    //         height: 13px;
    //     }

    //     /* Estado: Marcado */
    //     QCheckBox::indicator:checked {
    //         image: url(:/icons/images/icons/ChBoxOk.png);
    //         width: 13px;
    //         height: 13px;
    //     }

    //     /*Estado: presionado*/
    //     QCheckBox::indicator:pressed{
    //         background-color: #354970;
    //     }
    // )");
    return myCheckBox;
}

QScrollArea* WidgetsFactory::createQScrollArea(QWidget *widgetContainer, QWidget *parent){
    QScrollArea *myScrollArea= new QScrollArea(parent);
    myScrollArea->setWidget(widgetContainer);
    myScrollArea->setWidgetResizable(true);
    myScrollArea->setProperty("tipo","scroll-area-scroll");
    // myScrollArea->setStyleSheet(R"(
    //     /************** SCROLL VERTICAL **************/
    //     QScrollBar:vertical {
    //         background: #10192d;
    //         width: 12px;
    //         margin: 0px;
    //         border: none;
    //     }

    //     QScrollBar::handle:vertical {
    //         background: #273754;
    //         min-height: 15px;
    //         border: none;
    //         border-radius: 4px;
    //         outline: none;
    //         margin-top: 12px;
    //         margin-bottom: 12px;
    //     }

    //     QScrollBar::handle:vertical:hover {
    //         background: #354970;
    //     }

    //     QScrollBar::sub-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     QScrollBar::add-line:vertical {
    //         background: #273754;
    //         height: 12px;
    //         border: solid;
    //     }

    //     QScrollBar::up-arrow:vertical {
    //         image: url(:/icons/images/icons/up-arrowIcon.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     QScrollBar::up-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/up-arrow-pressed.png);
    //     }

    //     QScrollBar::down-arrow:vertical {
    //         image: url(:/icons/images/icons/down-arrowIcon.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     QScrollBar::down-arrow:vertical:pressed {
    //         image: url(:/icons/images/icons/down-arrow-pressed.png);
    //     }

    //     QScrollBar::add-page:vertical,
    //     QScrollBar::sub-page:vertical {
    //         background: none;
    //     }

    //     /************** SCROLL HORIZONTAL **************/
    //     QScrollBar:horizontal {
    //         background: #10192d;
    //         height: 12px;
    //         margin: 0px;
    //         border: none;
    //     }

    //     QScrollBar::handle:horizontal {
    //         background: #273754;
    //         min-width: 15px;
    //         border: none;
    //         border-radius: 4px;
    //         outline: none;
    //         margin-left: 12px;
    //         margin-right: 12px;
    //     }

    //     QScrollBar::handle:horizontal:hover {
    //         background: #354970;
    //     }

    //     QScrollBar::sub-line:horizontal {
    //         background: #273754;
    //         width: 12px;
    //         border: solid;
    //         subcontrol-origin: margin;
    //         subcontrol-position: left;    /*Esto es necesario para que se pueda ver*/
    //     }

    //     QScrollBar::add-line:horizontal {
    //         background: #273754;
    //         width: 12px;
    //         border: solid;
    //     }

    //     QScrollBar::left-arrow:horizontal {
    //         image: url(:/icons/images/icons/left-drow.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     QScrollBar::left-arrow:horizontal:pressed {
    //         image: url(:/icons/images/icons/left-drow-pressed.png);
    //     }

    //     QScrollBar::right-arrow:horizontal {
    //         image: url(:/icons/images/icons/right-drow.png);
    //         width: 12px;
    //         height: 12px;
    //     }

    //     QScrollBar::right-arrow:horizontal:pressed {
    //         image: url(:/icons/images/icons/right-drow-pressed.png);
    //     }

    //     QScrollBar::add-page:horizontal,
    //     QScrollBar::sub-page:horizontal {
    //         background: none;
    //     }
    // )");
    // Propagar propiedad al scrollbar vertical
    QScrollBar *vScroll = myScrollArea->verticalScrollBar();
    if (vScroll) {
        vScroll->setProperty("tipo", "scroll-area-scroll");
        vScroll->style()->unpolish(vScroll);
        vScroll->style()->polish(vScroll);
    }

    // Propagar propiedad al scrollbar horizontal
    QScrollBar *hScroll = myScrollArea->horizontalScrollBar();
    if (hScroll) {
        hScroll->setProperty("tipo", "scroll-area-scroll");
        hScroll->style()->unpolish(hScroll);
        hScroll->style()->polish(hScroll);
    }

    // Forzar recálculo del estilo del QScrollArea
    myScrollArea->style()->unpolish(myScrollArea);
    myScrollArea->style()->polish(myScrollArea);
    return myScrollArea;
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
    separator->setProperty("tipo","menu-separator");
    // separator->setStyleSheet(R"(
    //     background-color: #10192D;
    //     margin-left: 15px;
    //     margin-right: 15px;
    //     border: none;
    // )");
    return separator;
}

QLabel* WidgetsFactory::createLblGui(const QString &text, QWidget *parent){
    QLabel *label=new QLabel(text,parent);
    label->setProperty("tipo","QLabel-Gui");
    return label;
}

QLabel* WidgetsFactory::createLblForm(const QString &text, QWidget *parent){
    QLabel *label=new QLabel(text,parent);
    label->setAlignment(Qt::AlignTop);
    label->setProperty("tipo","label-forms");
    // label->setStyleSheet(R"(
    //     font-size: 13px;
    // )");
    return label;
}

QRadioButton* WidgetsFactory::createRBtn(const QString &text, QWidget *parent){
    QRadioButton *myRadioButton=new QRadioButton(text,parent);
    myRadioButton->setProperty("tipo","form-rb");
    // myRadioButton->setStyleSheet(R"(
    //     QRadioButton{
    //         font-size: 13px;
    //     }

    //     QRadioButton::indicator::unchecked {
    //         image: url(:/icons/images/icons/RadioButtonNoCheck.png);
    //         width: 13px;
    //         height: 13px;
    //     }

    //     QRadioButton::indicator:unchecked:pressed {
    //         image: url(:/icons/images/icons/RadioButtonNoCheckPress.png);
    //         width: 13px;
    //         height: 13px;
    //     }

    //     QRadioButton::indicator::checked {
    //         image: url(:/icons/images/icons/RadioButtonCheck.png);
    //         width: 13px;
    //         height: 13px;
    //     }

    //     QRadioButton::indicator:checked:pressed {
    //         image: url(:/icons/images/icons/RadioButtonCheckPress.png);
    //         width: 13px;
    //         height: 13px;
    //     }

    // )");
    return myRadioButton;
}

QToolButton* WidgetsFactory::createBtnAdc(QWidget *parent){
    return createBtnPeriphelal("ADC",":/icons/images/icons/adc_icon.png","Convertidor Analógico-Digital",parent);
}

QToolButton* WidgetsFactory::createBtnCcp(QWidget *parent){
    return createBtnPeriphelal("CPP",":/icons/images/icons/ccp_icon.png","Captura, comparación y PWM",parent);
}

QToolButton* WidgetsFactory::createBtnComparator(QWidget *parent){
    return createBtnPeriphelal("Comparator",":/icons/images/icons/comparator_icon.png","Comparador Analógico",parent);
}

QToolButton* WidgetsFactory::createBtnComparatorVRef(QWidget *parent){
    return createBtnPeriphelal("Comp. Vref",":/icons/images/icons/comparator_volt_ref_icon.png","Voltaje de Ref del Comparador Analógico",parent);
}

QToolButton* WidgetsFactory::createBtnCrystal(QWidget *parent){
    return createBtnPeriphelal("Oscillator",":/icons/images/icons/crystal_icon.png", "Reloj del Microcontrolador",parent);
}

QToolButton* WidgetsFactory::createBtnDac(QWidget *parent){
    return createBtnPeriphelal("DAC",":/icons/images/icons/dac_icon.png","Comparador Digital-Analógico",parent);
}

QToolButton* WidgetsFactory::createBtnEccp(QWidget *parent){
    return createBtnPeriphelal("ECCP",":/icons/images/icons/eccp_icon.png","Captura, comparación y pwm Mejorado",parent);
}

QToolButton* WidgetsFactory::createBtnEeprom(QWidget *parent){
    return createBtnPeriphelal("EEPROM",":/icons/images/icons/eeprom_icon.png", "Lectura y escribura en EEPROM interna",parent);
}

QToolButton* WidgetsFactory::createBtnEusart(QWidget *parent){
    return createBtnPeriphelal("EUSART",":/icons/images/icons/eusart_icon.png","Puerto Serie EUSART",parent);
}

QToolButton* WidgetsFactory::createBtnExtInt(QWidget *parent){
    return createBtnPeriphelal("External Interrupt",":/icons/images/icons/ext_interrupt_icon.png","Configuración de Interrupción Externa",parent);
}

QToolButton* WidgetsFactory::createBtnInt(QWidget *parent){
    return createBtnPeriphelal("Interrupts",":/icons/images/icons/interrupt_icon.png","Configuración de Interrupciones",parent);
}

QToolButton* WidgetsFactory::createBtnMssp(QWidget *parent){
    return createBtnPeriphelal("MSSP",":/icons/images/icons/mssp_icon.png","Puerto Serie MSSP",parent);
}

QToolButton* WidgetsFactory::createBtnTimers(QWidget *parent){
    return createBtnPeriphelal("Timers",":/icons/images/icons/timer_icon.png","Configuración de Timers",parent);
}

QToolButton* WidgetsFactory::createBtnUsart(QWidget *parent){
    return createBtnPeriphelal("USART",":/icons/images/icons/usart_icon.png","Puerto Serie USART",parent);
}

QToolButton* WidgetsFactory::createBtnUSB(QWidget *parent){
    return createBtnPeriphelal("USB",":/icons/images/icons/usb_icon.png","Puerto Serie USB",parent);
}




