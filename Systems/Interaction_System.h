/*
 * Interaction_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/12/13
 * Organization:    n8Tech
 *
 */

#ifndef INTERACTION_SYSTEM_H
#define INTERACTION_SYSTEM_H

#include <string>
#include <map>

#include "Entity.h"
//#include "Game_Manager.h"
#include "System.h"
// #include "n8.h"

class Game_Manager;


/** Handles interactions between game entities.  Custom interactions can be defined in
 *  separate files and then registered with the system via function pointer.  This allows
 *  different types of interactions to be defined based on what entities are currently
 *  interacting.
 */
class Interaction_System : public System {
 public:
    typedef void (*interactionFunction)(Game_Manager*,Entity*,Entity*);
    
    
	~Interaction_System();
    Interaction_System(Game_Manager* gameManager);

    bool do_collide(Entity* ent1, Entity* ent2);
    void handle_interaction(string interactionType, Entity* ent1, Entity* ent2);
    bool register_interaction(string interactionType, void (*func)(Game_Manager* game, Entity* ent1, Entity* ent2));

    void update();
  private:

    Game_Manager* game_;	/** < A pointer to the game manager.  Used to gain access to other systems and required data **/
    map <string, interactionFunction > registered_interactions_;
};

#endif /* INTERACTION_SYSTEM_H_ */
