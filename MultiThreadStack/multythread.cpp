#include "multythread.h"
#include "firstthread.h"
#include   "secthread.h"

MultyThread::MultyThread(QObject *parent) : QObject(parent)
{
    FirstThread *FThread = new FirstThread;
    SecThread   *SThread = new SecThread  ;

    FThread->moveToThread(&firstThread);
    connect(&firstThread, &QThread::finished, FThread, &QObject::deleteLater);
    connect(this, &MultyThread::startFandSTreads, FThread, &FirstThread::startThread);
    connect(FThread, &FirstThread::dataFirstToMain, this, &MultyThread::datafromFirstTread);

    SThread->moveToThread(&secThread);
    connect(&secThread, &QThread::finished,     SThread,   &QObject::deleteLater);
    connect(this, &MultyThread::startFandSTreads, SThread, &SecThread::startThread);
    connect(SThread, &SecThread::dataSecToMain, this,    &MultyThread::datafromFirstTread);

    firstThread.start();
      secThread.start();
}

MultyThread::~MultyThread()
{
    firstThread.quit();
    firstThread.wait();

      secThread.quit();
      secThread.wait();
}
