#include <QQueue>

#include "multythread.h"
#include "firstthread.h"
#include   "secthread.h"

MultyThread::MultyThread(QObject *parent) : QObject(parent) //подключение потоков
{
    FirstThread *FThread = new FirstThread;
    SecThread   *SThread = new SecThread  ;

    //First Thread
    connect(&firstThread,
            &QThread::finished,
            FThread,
            &QObject::deleteLater
            );

    connect(this,
            &MultyThread::startFandSTreads,
            FThread,
            &FirstThread::startThread
            );

    connect(FThread,
            &FirstThread::dataFirstToMain,
            this,
            &MultyThread::datafromFirstTread
            );

    //Second Thread
    connect(&secThread,
            &QThread::finished,
            SThread,
            &QObject::deleteLater
            );

    connect(this,
            &MultyThread::startFandSTreads,
            SThread,
            &SecThread::startThread
            );

    connect(SThread,
            &SecThread::dataSecToMain,
            this,
            &MultyThread::datafromFirstTread
            );
}

MultyThread::~MultyThread()
{
    firstThread.quit();
    firstThread.wait();

    secThread.quit();
    secThread.wait();
}

MultyThread::CreateQueue()
{
    QQueue<int> queueThr;        //создание очереди
    for(int i = 0; i <= 40; i++)
    {
        queueThr.enqueue(i);
    }

    MultyThread::StartThreads(); //запуск потоков
    return 0;
}

MultyThread::StartThreads()
{
    bool StartBool = true;
    emit startFandSTreads(StartBool);
    return 0;
}

MultyThread::datafromFirstTread()
{

}

MultyThread::datafromSecTread()
{

}
