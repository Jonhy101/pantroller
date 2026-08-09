#include "helpbutton.h"
#include <QIcon>
#include <QMessageBox>

HelpButton::HelpButton(const QString &helpText, QWidget *parent)
    : QPushButton(parent)
    ,m_helpText(helpText){
    setIcon(QIcon(":/icons/images/icons/helpIcon.png"));
    setFlat(true);

    //slot
    connect(this,&QPushButton::clicked,this,&HelpButton::showHelp);

}

QString HelpButton::helpText() const{
    return m_helpText;
}

void HelpButton::setHelpText(const QString &helpText){

    m_helpText=helpText;
}

void HelpButton::showHelp(){
    QMessageBox::information(this,"Ayuda", m_helpText);
}
