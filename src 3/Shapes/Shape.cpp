/*
 * Shape.cpp
 *
 *  Created on: Jan. 11, 2019
 *      Author: serge
 */

#include "Shape.h"

void Shape::MoveBy(const Vec2D& deltaOffset)
{
	for(Vec2D& point : mPoints)
	{
		point = point + deltaOffset;
	}
}
