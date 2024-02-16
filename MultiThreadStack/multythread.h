#ifndef MULTYTHREAD_H
#define MULTYTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

class MultyThread : public QObject
{
    Q_OBJECT
    QThread firstThread;
    QThread   secThread;
public:
    Q_INVOKABLE  MultyThread(QObject *parent = nullptr);
    Q_INVOKABLE ~MultyThread();
    Q_INVOKABLE  CreateQueue();
    Q_INVOKABLE  StartTreads();
    Q_INVOKABLE     DelQueue();

public slots:
    void datafromFirstTread();
    void   datafromSecTread();

signals:
    void       queueEmpty();
    void startFandSTreads();
};

#endif // MULTYTHREAD_H
