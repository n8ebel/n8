/*
 * Input_Handler.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/15/13
 * Organization:    n8Tech
 *
 */


#include "Input_Handler.h"

Input_Handler::Input_Handler() {
	for (int i = 0; i < 323; i++) {
		keysHeld_[i] = false;
	}

}

Input_Handler::~Input_Handler() {
	// TODO Auto-generated destructor stub
}

void Input_Handler::register_key_action(int keyID, keyActionFunction func, int state){
    if (state == Input_Handler::DOWN) {
        keyDownActions_[keyID] = func;
    }
    else{
        keyUpActions_[keyID] = func;
    }
    
    
}

void Input_Handler::handle_input(){
    if (SDL_PollEvent(&event_))
    {
        if (event_.type == SDL_QUIT)
		{
			//running_ = false;
            if (exit_action_ != NULL) {
                exit_action_(action_object_);
            }
		}

		if (event_.type == SDL_KEYDOWN)
		{
			keysHeld_[event_.key.keysym.sym] = true;
		}
		if (event_.type == SDL_KEYUP)
		{
			keysHeld_[event_.key.keysym.sym] = false;
			map<int, keyActionFunction>::iterator ii;
			for(ii = keyUpActions_.begin(); ii != keyUpActions_.end(); ii++){
				if (event_.key.keysym.sym == ii->first) {
					ii->second(action_object_);
				}
			}
		}
    }

	map<int, keyActionFunction>::iterator ii;
	for(ii = keyDownActions_.begin(); ii != keyDownActions_.end(); ii++){
		if(keysHeld_[ii->first]){
			ii->second(action_object_);
		}
	}
}
