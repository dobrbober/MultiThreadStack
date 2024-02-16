#ifndef SECTHREAD_H
#define SECTHREAD_H

#include <QObject>
#include <QThread>

class SecThread : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE SecThread(QObject *parent = nullptr);

signals:
    void dataSecToMain();

public slots:
    void     startThread();
    void dataSecFromMain();
};

#endif // SECTHREAD_H
