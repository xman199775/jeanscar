#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <mainwindow.h>
class thread:public QThread
{
public:
    MainWindow *M;
    thread(MainWindow *x);
    void run();
    ~thread();
};

#endif // THREAD_H
