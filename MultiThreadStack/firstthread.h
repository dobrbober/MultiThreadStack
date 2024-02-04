#ifndef FIRSTTHREAD_H
#define FIRSTTHREAD_H

#include <QObject>
#include <QThread>

class FirstThread : public QThread
{
    Q_OBJECT
public:
    Q_INVOKABLE FirstThread(QObject *parent = nullptr);
};

#endif // FIRSTTHREAD_H
