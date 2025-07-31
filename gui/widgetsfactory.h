#ifndef WIDGETSFACTORY_H
#define WIDGETSFACTORY_H

#include <QPushButton>
#include <QLabel>
#include <QFrame>

class WidgetsFactory {
public:
    static QLabel* createLblMenu(const QString &text,QWidget *parent=nullptr);
    static QPushButton* createButton(const QString &text,QWidget *parent=nullptr);
    static QFrame* createMenuSeparator();
};

#endif // WIDGETSFACTORY_H
