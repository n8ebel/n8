/*
 * Point3D.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/14/13
 * Organization:    n8Tech
 *
 */

#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

class Point3D: public Point2D {
  public:
	Point3D(int initX, int initY, int initZ);
    ~Point3D();



	    /** Used to get the z position of the point
	     *
	     *  @return The z coordinate of the point
	     */
	    int GetZ() { return m_z; }



	    /** Adds a value to the z coordinate of the point.
	     *
	     *  @param zOffset The value to add to the z coordinate
	     */
	    void AddZ(int zOffset) { m_z += zOffset; }



	    /** Sets the z coordinate of the point to a passsed value
	     *
	     *  @param newZ The new z coordinate of the point
	     */
	    void SetZ(int newZ) { m_z = newZ; }

  private:
	int m_z;
};

#endif /* POINT3D_H */
