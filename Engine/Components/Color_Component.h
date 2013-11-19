/*
 * Color_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/19/13
 * Organization:    n8Tech
 *
 */

#ifndef Color_Component_h
#define Color_Component_h

#include <string>

#include "Component.h"

using namespace std;

/** Class to store color information that can be used fro drawing operations */
class Color_Component : public Component {
    
public:
	/** Default Destructor */
    ~Color_Component() {}
	
	/** Constructor <p>
	 *	Stores standard rgb values so they may be used for drawing operations
	 *
	 *	@param red The red value of the color between 0-255
	 *	@param green The green value of the color between 0-255
	 *	@param blue The blue value of the color between 0-255
	 */
    Color_Component(string newID, int red, int green, int blue) : Component(newID)
    { red_ = red%255; green_ = green%255; blue_ = blue%255; alpha_ = 0;}
	
	/** Constructor <p>
	 *	Stores standard argb values so they may be used for drawing operations
	 *
	 *	@param alpha The alpha value of the color between 0 - 1.0
	 *	@param red The red value of the color between 0-255
	 *	@param green The green value of the color between 0-255
	 *	@param blue The blue value of the color between 0-255
	 */
	Color_Component(string newID, double alpha, int red, int green, int blue) : Component(newID)
    { red_ = red%255; green_ = green%255; blue_ = blue%255; alpha_ = alpha ;}
    
	/** Sets the rgb color values
	 *
	 *	@param red The red value of the color between 0-255
	 *	@param green The green value of the color between 0-255
	 *	@param blue The blue value of the color between 0-255
	 */
    void set_color(int red, int green, int blue)
    { red_ = red%255; green_=green%255; blue_=blue%255; alpha_ = 0;}
	
	/** Sets the argb color values
	 *
	 *	@param alpha The alpha value of the color between 0 - 1.0
	 *	@param red The red value of the color between 0-255
	 *	@param green The green value of the color between 0-255
	 *	@param blue The blue value of the color between 0-255
	 */
	void set_color( double alpha, int red, int green, int blue)
    { red_ = red%255; green_=green%255; blue_=blue%255; alpha_ = alpha;}

	/** Gets the value of the red component of the color
	 *
	 *	@return The integer value of the red component of the color
	 */
	int get_red() { return red_;}
	
	/** Gets the value of the green component of the color
	 *
	 *	@return The integer value of the green component of the color
	 */
	int get_green() { return green_;}
	
	/** Gets the value of the blue component of the color
	 *
	 *	@return The integer value of the blue component of the color
	 */
	int get_blue() {return blue_; }
	
	/** Gets the value of the alpha component of the color
	 *
	 *	@return The double value of the alpha component of the color
	 */
	int get_alpha() {return alpha_;}
    
private:
    double alpha_;
	int red_;
	int green_;
	int blue_;
};

#endif
