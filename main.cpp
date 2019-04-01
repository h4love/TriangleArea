#ifndef _HELLO_H
#define _HELLO_H

#include "struck.h"

#endif

#include <iostream>
#include <locale.h>
#include "geometry.h"
#include "file.h"
#include "search.h"

using namespace std;
int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout << "Start command: Triangles.exe inf.txt outf.txt" << endl;
		return -1;
	}
	const char *inFileName = argv[1];  // Имя входного файла
	const char *outFileName = argv[2]; // Имя выходного файла
	int pointNum = countPoints(inFileName);

	if (pointNum < 0)
	{
		cout << "Input file isn't exist" << endl;
		return -2;
	}
	else if (pointNum < 4)
	{
		cout << "Input file too little" << endl;
		return -3;
	}
	Point *pointArray = new Point[pointNum];
	if (!readPoints(inFileName, pointArray, pointNum))
	{
		cout << "Unknown errors, when entering points" << endl;
		return -3;
	}
	const int maxTrNum = 3;
	Triangle trArray[maxTrNum];
	searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum);
	if (writeTriangles(outFileName, trArray, maxTrNum) == false)
	{
		cout << "Could not write result" << endl;
		return -4;
	}
	cout << "Program completed successfully" << endl;
	delete[] pointArray;
	return 0;
}