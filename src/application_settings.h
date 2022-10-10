#ifndef APPLICATION_SETTINGS_H
#define APPLICATION_SETTINGS_H

#include <QSettings>
#include <QDebug>

class ApplicationSettings : public QObject
{
    Q_OBJECT
public:
    ApplicationSettings(QObject* parent) : QObject(parent) {}

    Q_PROPERTY(
        bool isEulaAccepted READ isEulaAccepted WRITE setEulaAccepted NOTIFY isEulaAcceptedChanged)

    void setEulaAccepted(bool value) {
        qDebug() << "setEulaAccepted: " << value;
        QSettings().setValue("EULAAccepted", value);
        qDebug() << "setEulaAccepted new Value: " << QSettings().value("EULAAccepted").toBool();
        emit isEulaAcceptedChanged();
    }

    bool isEulaAccepted() const {
        bool val = QSettings().value("EULAAccepted", false).toBool();
        qDebug() << "isEulaAccepted: " << val;
        return val;
    }

signals:
    void isEulaAcceptedChanged();


};
#endif // APPLICATION_SETTINGS_H
