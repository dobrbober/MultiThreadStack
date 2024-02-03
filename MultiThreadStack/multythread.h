#ifndef MULTYTHREAD_H
#define MULTYTHREAD_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>

class MultyThread : public QMutex
{
public:
    MultyThread();

private:

};

#endif // MULTYTHREAD_H
