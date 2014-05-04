#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>
#include <string>
#include <sstream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/thread/thread.hpp"
#include "boost/version.hpp"

#include "Log.h"

using namespace std;
using namespace boost;


class GameOfLife
{
    int **_pBoard;
	const int _size;

    bool _leftTopCorner;
    bool _rightTopCorner;
    bool _bottomLeftCorner;
    bool _bottomRightCorner;
    bool _leftEdge;
    bool _topEdge;
    bool _rightEdge;
    bool _bottomEdge;
    bool _inTheMiddle;

    int NeighbourSum(int, int);

public:
	GameOfLife() : _pBoard(NULL), _size(20)
	{
		InitBoard();
	};

	GameOfLife(int size) : _pBoard(NULL), _size(size)
	{
		InitBoard();
	}

    virtual ~GameOfLife()
	{
		CleanupBoard(_pBoard);
	}

	void InitBoard()
	{
		// create rows
		_pBoard = NewBoard(NULL);
	}

	void AnalyzePoint(int i, int j)
	{
	    _leftTopCorner =
        _rightTopCorner =
        _bottomLeftCorner =
        _bottomRightCorner =
        _leftEdge =
        _topEdge =
        _rightEdge =
        _bottomEdge =
        _inTheMiddle = false;

	    _leftTopCorner = (i == 0 && j == 0);
	    if (_leftTopCorner)
        {
            return;
        }

	    _rightTopCorner = (i == 0 && j == _size-1);
	    if (_rightTopCorner)
        {
            return;
        }

	    _bottomLeftCorner = (i == _size-1 && j == 0);
	    if (_bottomLeftCorner)
        {
            return;
        }

	    _bottomRightCorner = (i == _size-1 && j == _size-1);
	    if (_bottomRightCorner)
        {
            return;
        }

	    _leftEdge = (j == 0);
	    if (_leftEdge)
        {
            return;
        }

	    _topEdge = (i == 0);
	    if (_topEdge)
        {
            return;
        }

	    _rightEdge = (j == _size-1);
	    if (_rightEdge)
        {
            return;
        }

	    _bottomEdge = (i == _size-1);
	    if (_bottomEdge)
        {
            return;
        }

	    _inTheMiddle = true;
	}

	int GetLeftTop(int i, int j)
	{
	    int result = 0;

        if (_leftTopCorner) return _pBoard[_size-1][_size-1];
        if (_rightTopCorner) return _pBoard[_size-1][j-1];
	    if (_bottomLeftCorner) return _pBoard[i-1][_size-1];
	    if (_bottomRightCorner) return _pBoard[i-1][j-1];

	    if (_leftEdge) return _pBoard[i-1][_size-1];
	    if (_topEdge) return _pBoard[_size-1][j-1];
	    if (_rightEdge) return _pBoard[i-1][j-1];
	    if (_bottomEdge) return _pBoard[i-1][j-1];

	    if (_inTheMiddle) return _pBoard[i-1][j-1];

	    return result;
	}

    int GetTop(int i, int j)
    {
	    int result = 0;

        if (_leftTopCorner) return _pBoard[_size-1][j];
        if (_rightTopCorner) return _pBoard[_size-1][_size-1];
	    if (_bottomLeftCorner) return _pBoard[i-1][j];
	    if (_bottomRightCorner) return _pBoard[i-1][j];

	    if (_leftEdge) return _pBoard[i-1][j];
	    if (_topEdge) return _pBoard[_size-1][j];
	    if (_rightEdge) return _pBoard[i-1][j];
	    if (_bottomEdge) return _pBoard[i-1][j];

	    if (_inTheMiddle) return _pBoard[i-1][j];

	    return result;
	}

    int GetRightTop(int i, int j)
    {
	    int result = 0;

        if (_leftTopCorner) return _pBoard[_size-1][j+1];
        if (_rightTopCorner) return _pBoard[_size-1][0];
	    if (_bottomLeftCorner) return _pBoard[i-1][j+1];
	    if (_bottomRightCorner) return _pBoard[i-1][0];

	    if (_leftEdge) return _pBoard[i-1][j+1];
	    if (_topEdge) return _pBoard[_size-1][j+1];
	    if (_rightEdge) return _pBoard[i-1][0];
	    if (_bottomEdge) return _pBoard[i-1][j+1];

	    if (_inTheMiddle) return _pBoard[i-1][j+1];

	    return result;
	}

    int GetLeft(int i, int j)
    {
	    int result = 0;

        if (_leftTopCorner) return _pBoard[i][_size-1];
        if (_rightTopCorner) return _pBoard[i][j-1];
	    if (_bottomLeftCorner) return _pBoard[_size-1][_size-1];
	    if (_bottomRightCorner) return _pBoard[_size-1][j-1];

	    if (_leftEdge) return _pBoard[i][_size-1];
	    if (_topEdge) return _pBoard[i][j-1];
	    if (_rightEdge) return _pBoard[i][j-1];
	    if (_bottomEdge) return _pBoard[i][j-1];

	    if (_inTheMiddle) return _pBoard[i][j-1];

	    return result;
	}

    int GetRight(int i, int j)
    {
	    int result = 0;

        if (_leftTopCorner) return _pBoard[i][j+1];
        if (_rightTopCorner) return _pBoard[i][0];
	    if (_bottomLeftCorner) return _pBoard[i][j+1];
	    if (_bottomRightCorner) return _pBoard[i][0];

	    if (_leftEdge) return _pBoard[i][j+1];
	    if (_topEdge) return _pBoard[i][j+1];
	    if (_rightEdge) return _pBoard[i][0];
	    if (_bottomEdge) return _pBoard[i][j+1];

	    if (_inTheMiddle) return _pBoard[i][j+1];

	    return result;
	}

    int GetLeftBottom(int i, int j)
    {
        int result = 0;

        if (_leftTopCorner) return _pBoard[i+1][_size-1];
        if (_rightTopCorner) return _pBoard[i+1][j-1];
	    if (_bottomLeftCorner) return _pBoard[0][_size-1];
	    if (_bottomRightCorner) return _pBoard[0][_size-1];

	    if (_leftEdge) return _pBoard[i+1][_size-1];
	    if (_topEdge) return _pBoard[i+1][j-1];
	    if (_rightEdge) return _pBoard[i+1][j-1];
	    if (_bottomEdge) return _pBoard[0][j-1];

	    if (_inTheMiddle) return _pBoard[i+1][j-1];

	    return result;
	}

    int GetBottom(int i, int j)
    {
	    int result = 0;

        if (_leftTopCorner) return _pBoard[i+1][j];
        if (_rightTopCorner) return _pBoard[i+1][j];
	    if (_bottomLeftCorner) return _pBoard[0][j];
	    if (_bottomRightCorner) return _pBoard[0][j];

	    if (_leftEdge) return _pBoard[i+1][j];
	    if (_topEdge) return _pBoard[i+1][j];
	    if (_rightEdge) return _pBoard[i+1][j];
	    if (_bottomEdge) return _pBoard[0][j];

	    if (_inTheMiddle) return _pBoard[i+1][j];

	    return result;
	}

    int GetRightBottom(int i, int j)
    {
	    int result = 0;

        if (_leftTopCorner) return _pBoard[i+1][j+1];
        if (_rightTopCorner) return _pBoard[i+1][0];
	    if (_bottomLeftCorner) return _pBoard[0][j+1];
	    if (_bottomRightCorner) return _pBoard[0][0];

	    if (_leftEdge) return _pBoard[i+1][j+1];
	    if (_topEdge) return _pBoard[i+1][j+1];
	    if (_rightEdge) return _pBoard[i+1][0];
	    if (_bottomEdge) return _pBoard[0][j+1];

	    if (_inTheMiddle) return _pBoard[i+1][j+1];

	    return result;
	}

	int Sum(int i, int j)
	{
		int result = 0;
		if (_pBoard == NULL) return result;

        int leftTop = GetLeftTop(i, j);
        int top = GetTop(i, j);
        int rightTop = GetRightTop(i, j);
        int left = GetLeft(i, j);
        int right = GetRight(i, j);
        int leftBottom = GetLeftBottom(i, j);
        int bottom = GetBottom(i, j);
        int rightBottom = GetRightBottom(i, j);

        result =
            leftTop     + top    + rightTop +
            left        + 0      + right +
            leftBottom  + bottom + rightBottom;

		return result;
	}

	void CleanupBoard(int** pBoard)
	{
		// delete columns
		for (int row = 0; row < _size; ++row)
		{
			delete [] pBoard[row];
			pBoard[row] = NULL;
		}

		// delete rows
		delete [] pBoard;
		pBoard = NULL;
	}

	void DisplayBoard()
	{
	    for (int row = 0; row < _size; ++row)
		{
		    cout << "\t\t";

		    for (int col = 0; col < _size; ++col)
                cout << string(_pBoard[row][col] > 0 ? "*" : " ");

			// Next row
			cout << endl;
		}

		boost::this_thread::sleep(boost::posix_time::milliseconds(500));
	}

	void SetConfiguration(int **p)
	{
		for (int row = 0; row < _size; ++row)
		{
			for (int col = 0; col < _size; ++col)
                _pBoard[row][col] = p[row][col];
		}
	}

	int** NewBoard(int** pSource)
	{
	    // create rows
		int** pBoard = new int* [_size];

		// create columns
		for (int row = 0; row < _size; ++row)
			pBoard[row] = new int[_size];

		for (int row = 0; row < _size && pSource; ++row)
		{
			for (int col = 0; col < _size; ++col)
                pBoard[row][col] = pSource[row][col];
		}

		return pBoard;
	}

	void NextConfiguration()
	{
	    // create rows
		int** pBoard = NewBoard(_pBoard);

	    for (int row = 0; row < _size; ++row)
		{
			for (int col = 0; col < _size; ++col)
			{
			    AnalyzePoint(row, col);
			    int sum = Sum(row, col);
                bool alive = _pBoard[row][col] == 1;

                if (alive && sum < 2)
                {
                    // Under population
                    pBoard[row][col] = 0;
                }
                else if (alive && sum > 3)
                {
                    // Over crowding
                    pBoard[row][col] = 0;
                }
                else if (!alive && sum == 3)
                {
                    // Reproduction
                    pBoard[row][col] = 1;
                }
			}
		}

        // Apply to main board
		SetConfiguration(pBoard);

		// Clean up
        CleanupBoard(pBoard);
	}
};

#endif // GAMEOFLIFE_H
