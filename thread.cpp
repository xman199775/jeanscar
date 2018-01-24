#include "thread.h"

thread::thread(MainWindow *x)
{
M=x;
}
void thread::run()
{while(true)
 {M->updatedate();
  this->msleep(100);
    }
}

thread::~thread()
{

    this->quit();
    if(!this->wait(3000)) //Wait until it actually has terminated (max. 3 sec)
    {
        this->terminate(); //Thread didn't exit in time, probably deadlocked, terminate it!
        this->wait(); //We have to wait again here!
    }
}
