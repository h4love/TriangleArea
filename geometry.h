#ifndef _HELLO_H
#define _HELLO_H

#include "struck.h"

#endif

#ifndef _GEOMETRY_H
#define _GEOMETRY_H

// Расстояние между двумя точками по их координатам
double calcDistance(const Point& pa, const Point& pb);

// Площадь треугольника по координатам точек
double calcAreaBySides(double a, double b, double c);

#endif

