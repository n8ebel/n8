/*
 * Interaction_System.h
 *
 *  Created on: Aug 12, 2013
 *      Author: nath7313
 */

#ifndef INTERACTION_SYSTEM_H
#define INTERACTION_SYSTEM_H

#include <string>
#include <map>

#include "Entity.h"
#include "Game_Manager.h"
#include "System.h"


class Interaction_System : public System {
 public:

	~Interaction_System();
    Interaction_System();

    bool do_collide(Entity ent1, Entity ent2);
    void handle_interaction(string interactionType, Entity ent1, Entity ent2);
    bool register_interaction(string interactionType, void (*func)(Game_Manager game, Entity ent1, Entity ent2));

    void update();
  private:

    Game_Manager* game;
    typedef void (*func)(Game_Manager,Entity,Entity);
    map <string, func > registered_interactions_;
};

#endif /* INTERACTION_SYSTEM_H_ */
