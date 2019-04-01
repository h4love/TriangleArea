#ifndef _HELLO_H
#define _HELLO_H

#include "struck.h"

#endif

#include <math.h>
#include "geometry.h"

void clearPoint(Point &p)
{
	p.x = p.y = 0.0;
}

void clearTriangle(Triangle &tr)
{
	for (int i = 0; i < 3; i++)
		clearPoint(tr.vertexes[i]);
	tr.area = 0.0;
}

double calcTriangleArea(Triangle &tr)
{
	Point *v = tr.vertexes;
	double a = calcDistance(v[0], v[1]);
	double b = calcDistance(v[1], v[2]);
	double c = calcDistance(v[2], v[0]);
	return tr.area = calcAreaBySides(a, b, c);
}

void findAndInsert(Triangle *trArray, int length, const Triangle &triangle)
{
	int pos;
	for (pos = length - 1; pos >= 0; pos--)
	{
		if (triangle.area <= trArray[pos].area)
			break;
	}
	pos++;
	if (pos == length)
		return;
	for (int m = length - 2; m >= pos; m--)
		trArray[m + 1] = trArray[m];
	trArray[pos].area = triangle.area;
	trArray[pos].vertexes[0] = triangle.vertexes[0];
	trArray[pos].vertexes[1] = triangle.vertexes[1];
	trArray[pos].vertexes[2] = triangle.vertexes[2];
}

void searchLargestTriangles(const Point *pointArray, int pointNum, Triangle *trArray, int maxTrNum)
{
	if (maxTrNum <= 0)
		return;
	// Очистка треугольников
	for (int i = 0; i < maxTrNum; i++)
		clearTriangle(trArray[i]);
	Triangle triangle;
	// Перебор троек точек
	for (int i = 0; i < pointNum; i++)
	{
		triangle.vertexes[0] = pointArray[i];
		for (int j = i + 1; j < pointNum; j++)
		{
			triangle.vertexes[1] = pointArray[j];
			for (int k = j + 1; k < pointNum; k++)
			{
				triangle.vertexes[2] = pointArray[k];
				calcTriangleArea(triangle);
				findAndInsert(trArray, maxTrNum, triangle);
			}
		}
	}
}