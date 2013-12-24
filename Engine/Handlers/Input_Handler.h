/*
 * Input_Handler.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/15/13
 * Organization:    n8Tech
 *
 */

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <map>

#include "SDL/SDL.h"
#include "Object.h"



using namespace std;



class Input_Handler {
  public:
    typedef void (*keyActionFunction)(Object*);
    
    static const int UP = 1;
    static const int DOWN = 0;

   
	Input_Handler();
	virtual ~Input_Handler();

    /** Stores a pointer to an object that is passed to keyActionFunction pointers.
     *  Allows for called functions to operate on some outside object and/or data.
     *
     *  @param obj The object pointer to store
     */
    void register_action_object(Object* obj) { action_object_ = obj; }
	void register_key_action(int keyID, keyActionFunction,int state);
    //void register_key_action(int keyID, MethodPointer,int state);
    
    /** Registers a function as the action to take when the exit button is clicked.
     *
     *  @param func A function pointer to a user defined function that defines the behavior
     */
    void register_exit_action(keyActionFunction func) { exit_action_ = func; }
    
	void handle_input();
    
  private:
  	bool keysHeld_[323];  /** < Array to store whether or not a key is being held down **/
  	map<int, keyActionFunction> keyDownActions_;  /** < Map to hold function pointers for actions associated with a key down press **/
    map<int, keyActionFunction> keyUpActions_;   /** < Map to hold function pointers for actions associated with a key up press **/
    
    keyActionFunction exit_action_;  /** The action to take when the exit button is clicked **/
    
    SDL_Event event_;  /** < Used for handling game event loop **/
    Object* action_object_;  /** Can store an object that is passed to the keyActionFunction pointers **/
};

#endif /* INPUT_HANDLER_H */
