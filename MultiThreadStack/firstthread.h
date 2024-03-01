#ifndef FIRSTTHREAD_H
#define FIRSTTHREAD_H

#include <QObject>
#include <QThread>

class FirstThread : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE FirstThread(QObject *parent = nullptr);

signals:
    void   dataFirstToMain();

public slots:
    void       startThread();
    void dataFirstFromMain();
    void        stopThread();

};

#endif // FIRSTTHREAD_H
