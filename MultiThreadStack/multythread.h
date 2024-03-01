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
    Q_INVOKABLE  StartThreads();

signals:
    void       queueEmpty(bool);
    void startFandSTreads(bool);

public slots:
    void datafromFirstTread();
    void   datafromSecTread();
};

#endif // MULTYTHREAD_H
