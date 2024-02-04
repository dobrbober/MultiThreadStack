#ifndef SECTHREAD_H
#define SECTHREAD_H

#include <QObject>
#include <QThread>

class SecThread : public QThread
{
    Q_OBJECT
public:
    Q_INVOKABLE SecThread(QObject *parent = nullptr);
};

#endif // SECTHREAD_H
