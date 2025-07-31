#include "widgetsfactory.h"


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
        }
        QPushButton:hover{
            background-color: #354970;
        }

        QPushButton:pressed{
            background-color: #273754;
        }
    )");    
    return btn;
}

