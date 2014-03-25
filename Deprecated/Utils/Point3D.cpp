/*
 * Point3D.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/14/13
 * Organization:    n8Tech
 *
 */

#include "Point3D.h"

Point3D::Point3D(int initX, int initY, int initZ) : Point2D(initX, initY) {
	m_z = initZ;

}

Point3D::~Point3D() {
	// TODO Auto-generated destructor stub
}

