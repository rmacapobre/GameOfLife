#ifndef MONTHREAD_H
#define MONTHREAD_H

#define BOOST_THREAD_USE_LIB

#include <iostream>
#include <string>
#include <sstream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/thread/thread.hpp"
#include "boost/version.hpp"

#include "Log.h"
#include "GameOfLife.h"

using namespace std;
using namespace boost;

class MonThread
{
    shared_ptr<thread> p;
public:
    MonThread(int** pBoard, int size)
    {
        // Start thread
        p.reset(new boost::thread(&ThreadFunction, pBoard, size));
    }

    ~MonThread()
    {
        // Ask thread to stop
        p->interrupt();

        // Join - wait when thread actually exits
        p->join();
    }

    static void ThreadFunction(int** pBoard, int size)
    {
        GameOfLife o(size);
        o.SetConfiguration(pBoard);

        cout << "Initial state " << endl << endl;

        o.DisplayBoard();

        int generation = 1;
        for(;;)
        {
            try
            {
                std::system("clear");

                cout << "Generation " << generation++ << endl << endl;

                o.NextConfiguration();
                o.DisplayBoard();
            }
            catch(boost::thread_interrupted&)
            {
                Log(__func__, "Finir. Tu as appuye ENTER. Le thread a arrete");
                return;
            }
        }

        Log(__func__, "Finir");
    }
};

#endif // MONTHREAD_H
