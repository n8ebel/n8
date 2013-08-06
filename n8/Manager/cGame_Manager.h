/*
 * cGame_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cGame_Manager_h
#define n8_cGame_Manager_h

#include "cMessage_Handler.h"
#include "cSystem.h"
#include "cRender_System.h"
#include "cMovement_System.h"
#include "cCamera_System.h"
#include "cResource_Handler.h"
#include "cSprite.h"

#include <string>

class cGame_Manager{
  
private:
    int state;
    cMessage_Handler* message_handler;
    map<string, cSystem*> registered_systems;
    map<int,cEntity*> registered_entities;
    cResource_Handler* resource_handler;
    
    Uint32 start;
    SDL_Event event;
    bool running;
    bool keysHeld[323];
    
    cMessage_Handler* get_message_handler();
    cResource_Handler* get_resource_handler();

    
public:
    static const int LOADING_SCREEN;
    static const int MENU;
    static const int WORLD_VIEW;
    
    
    ~cGame_Manager();
    cGame_Manager();
    cGame_Manager(string resource_config, int screenW, int screenH);
    
    bool add_system(string ID, cSystem* newSystem);
    cEntity* create_screen_entity(int w, int h, int bpp);
    cEntity* create_camera_entity(int x, int y, int w, int h);
    cSystem* create_system(string ID);
    cEntity* create_user_entity(int id, string initName, int initX, int initY, cSprite* sprite);
    cEntity* get_entity(int ID);
    cSprite* get_sprite(string id);
    cSystem* get_system(string ID);
    void handle_input();
    bool initializeSDL();
    void initializeGameLoop();
    bool is_running();
    void load_images(string filepath);
    cEntity* register_entity(cEntity* newEntity);
    
    
};


#endif
