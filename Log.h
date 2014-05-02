#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;
using namespace boost;
using namespace boost::posix_time;

void Log(const string& function, const string& message)
{
    // Get now
    ptime now = second_clock::local_time();
    cout << now << " - " << function << ": " << message << endl;
}

#endif // LOG_H_INCLUDED
