/*
 * Size_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/6/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Size_Component_h
#define n8_Size_Component_h

#include "Component.h"

class Size_Component : public Component{

private:
    int width_;     /** < The width of an entity **/
    int height_;    /** < The height of an entity **/
    
public:
    ~Size_Component();
    Size_Component(string newID, int w, int h);
    
    /** Used to get the width stored by the component
     *
     *  @return The width of the component
     */
    int get_width() { return width_; }
    
    /** Used to get the height stored by the component
     *
     *  @return The height of the component
     */
    int get_height() { return height_; }
    
};


#endif
