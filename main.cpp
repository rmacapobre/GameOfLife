
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <boost/version.hpp>
#include <boost/algorithm/string.hpp>

#include "Log.h"
#include "MonThread.h"
#include "GameOfLife.h"

using namespace std;

// #define DEV
// #define TOAD
// #define BEACON
// #define PULSAR
#define GLIDER

int main()
{
	// create rows
	int size = 20;

	int** pBoard = new int* [size];

	// create columns
	for (int row = 0; row < size; ++row)
		pBoard[row] = new int[size];

	for (int row = 0; row < size; ++row)
			pBoard[row] = new int[size];

#ifdef BLINKER
    pBoard[1][3] = 1;
    pBoard[2][3] = 1;
    pBoard[3][3] = 1;
#endif

#ifdef TOAD
    pBoard[1][2] = 1;
    pBoard[1][3] = 1;
    pBoard[1][4] = 1;
    pBoard[2][1] = 1;
    pBoard[2][2] = 1;
    pBoard[2][3] = 1;
#endif

#ifdef BEACON
    pBoard[1][2] = 1;
    pBoard[1][3] = 1;
    pBoard[2][2] = 1;
    pBoard[2][3] = 1;

    pBoard[3][4] = 1;
    pBoard[3][5] = 1;
    pBoard[4][4] = 1;
    pBoard[4][5] = 1;
#endif // BEACON


#ifdef PULSAR
    pBoard[1][3] = 1;
    pBoard[1][4] = 1;
    pBoard[1][5] = 1;

    pBoard[1][9] = 1;
    pBoard[1][10] = 1;
    pBoard[1][11] = 1;

    pBoard[6][3] = 1;
    pBoard[6][4] = 1;
    pBoard[6][5] = 1;

    pBoard[6][9] = 1;
    pBoard[6][10] = 1;
    pBoard[6][11] = 1;

    pBoard[8][3] = 1;
    pBoard[8][4] = 1;
    pBoard[8][5] = 1;

    pBoard[8][9] = 1;
    pBoard[8][10] = 1;
    pBoard[8][11] = 1;

    pBoard[13][3] = 1;
    pBoard[13][4] = 1;
    pBoard[13][5] = 1;

    pBoard[13][9] = 1;
    pBoard[13][10] = 1;
    pBoard[13][11] = 1;

    // -------------------

    pBoard[3][1] = 1;
    pBoard[4][1] = 1;
    pBoard[5][1] = 1;

    pBoard[3][6] = 1;
    pBoard[4][6] = 1;
    pBoard[5][6] = 1;

    pBoard[3][8] = 1;
    pBoard[4][8] = 1;
    pBoard[5][8] = 1;

    pBoard[3][13] = 1;
    pBoard[4][13] = 1;
    pBoard[5][13] = 1;

    pBoard[9][1] = 1;
    pBoard[10][1] = 1;
    pBoard[11][1] = 1;

    pBoard[9][6] = 1;
    pBoard[10][6] = 1;
    pBoard[11][6] = 1;

    pBoard[9][8] = 1;
    pBoard[10][8] = 1;
    pBoard[11][8] = 1;

    pBoard[9][13] = 1;
    pBoard[10][13] = 1;
    pBoard[11][13] = 1;

#endif // PULSAR

#ifdef GLIDER
    pBoard[9][13] = 1;
    pBoard[9][14] = 1;
    pBoard[9][15] = 1;
    pBoard[8][15] = 1;
    pBoard[7][14] = 1;
#endif // GLIDER

    shared_ptr<MonThread> p;
    p.reset(new MonThread(pBoard, size));

    // Wait for Enter
    char ch;
    cin.get(ch);
    Log(__func__, "Finir");

	return 0;
}
