#include "widgetsfactory.h"
#include <QLineEdit>
#include <QAbstractItemView>
#include <QScrollBar>
#include <QListView>

/***********QLabels**************/
QLabel* WidgetsFactory::createLblMenu(const QString &text, QWidget *parent){
    QLabel *lbl=new QLabel(text,parent);
    lbl->setProperty("tipo","label-menu");   
    return lbl;
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
    return label;
}
/********************************/


/***********QTextEdit***************************/
QTextEdit* WidgetsFactory::createTextEditInfo(const QString &text, QWidget *parent){
    QTextEdit *textEdit=new QTextEdit(parent);
    textEdit->setPlainText(text);
    textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);   
    // Asignar propiedad al QTextEdit
    textEdit->setProperty("tipo", "text-Edit"); //Aplicar estilos de qss externa: styles.qss
    // Propagar propiedad al QScrollBar vertical hijo (necesario para aplicar estilos de hoja externa
    QScrollBar* vScroll = textEdit->verticalScrollBar();
    if (vScroll) {
        vScroll->setProperty("tipo", "text-Edit-scroll");
        // Forzar recálculo del estilo después de setProperty
        // vScroll->style()->unpolish(vScroll);
        // vScroll->style()->polish(vScroll);
    }
    // Forzar recálculo del estilo del QTextEdit también (necesario para aplicar estilos de hoja externa)
    // textEdit->style()->unpolish(textEdit);
    // textEdit->style()->polish(textEdit);
    return textEdit;
}
/************************************************/


/*********************QLineEdit******************/
QLineEdit* WidgetsFactory::createLineEditForm(QWidget *parent){
    QLineEdit *myQLineEdit=new QLineEdit(parent);
    myQLineEdit->setAlignment(Qt::AlignRight);
    myQLineEdit->setProperty("tipo","form-LineEdit");
    return myQLineEdit;
}
/************************************************/


/***********************Buttons******************/
//Crea QPushButton para el menú principal
QPushButton* WidgetsFactory::createButton(const QString &text, QWidget *parent){
    QPushButton *btn=new QPushButton(text,parent);
    btn->setProperty("tipo","main-menu-button");    
    btn->setCheckable(true);
    return btn;
}

QPushButton* WidgetsFactory::createControlButton(const QString &text, QWidget *parent){
    QPushButton *btnControl=new QPushButton(text,parent);
    btnControl->setProperty("tipo","control-button");
    btnControl->setFixedHeight(30);
    return btnControl;
}

QPushButton* WidgetsFactory::createIconButton(QWidget *parent){
    QPushButton *btnIcon=new QPushButton(parent);
    btnIcon->setProperty("tipo","button-icon");
    return btnIcon;
}

QRadioButton* WidgetsFactory::createRBtn(const QString &text, QWidget *parent){
    QRadioButton *myRadioButton=new QRadioButton(text,parent);
    myRadioButton->setProperty("tipo","form-rb");
    return myRadioButton;
}

//Crea QToolButton de vista de log
QToolButton* WidgetsFactory::createLogButton(QWidget *parent){
    QToolButton *myToolButton=new QToolButton(parent);
    QIcon buttonIcon(":/icons/images/icons/LogButton.png");
    myToolButton->setIcon(buttonIcon);
    myToolButton->setIconSize(QSize(24,24));
    myToolButton->setMaximumSize(QSize(30,30));
    return myToolButton;
}

//Crea un QToolButton de vista de código
QToolButton* WidgetsFactory::createSourceButton(QWidget *parent){
    QToolButton *myToolButton=new QToolButton(parent);
    QIcon buttonIcon(":/icons/images/icons/CodeButton.png");
    myToolButton->setIcon(buttonIcon);
    myToolButton->setIconSize(QSize(24,24));
    myToolButton->setMaximumSize(QSize(30,30));
    return myToolButton;
}

/**************************************************/


/**********************QToolButton*****************/
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
    return myButton;
}
/**************************************************/


/*********************QComboBox********************/
QComboBox* WidgetsFactory::createComboBoxSearchable(const QStringList &itemList, QWidget *parent){
    QComboBox *comboBox=new QComboBox(parent);        
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
/**************************************************/


/**********************CheckBox********************/
QCheckBox* WidgetsFactory::createCheckBox(const QString &text, QWidget *parent){
    QCheckBox *myCheckBox=new QCheckBox(text,parent);
    myCheckBox->setProperty("tipo","form-check-box");   
    return myCheckBox;
}
/**************************************************/


/********************ScrollArea********************/
QScrollArea* WidgetsFactory::createQScrollArea(QWidget *widgetContainer, QWidget *parent){
    QScrollArea *myScrollArea= new QScrollArea(parent);
    myScrollArea->setWidget(widgetContainer);
    myScrollArea->setWidgetResizable(true);
    myScrollArea->setProperty("tipo","scroll-area-scroll");   
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
/**************************************************/


/**************QFrame****************/
QFrame* WidgetsFactory::createMenuSeparator(){
    QFrame *separator=new QFrame();
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Plain);
    separator->setFixedHeight(2);
    separator->setProperty("tipo","menu-separator");  
    return separator;
}
/*************************************/


/****************QToolButton Peripheal*****************/
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
/**************************************************/