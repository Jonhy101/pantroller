/*Esta clase genera los widgets necesarios para
 * la configuración de un dispositivo*/

#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QLabel>
#include <QPushButton>
#include "gui/widgetsfactory.h"

class DeviceWidget: public QWidget {
    Q_OBJECT
public:
    explicit DeviceWidget(QWidget *parent=nullptr);

private:
    QLabel *labelSeleccion, *label;
    QPushButton *btnConfirmDevice;
    QComboBox *cbSelectDevice;

};

#endif // DEVICEWIDGET_H
