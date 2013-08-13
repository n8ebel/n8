/*
 * Game_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Game_Manager_h
#define n8_Game_Manager_h

#include "Message_handler.h"
#include "System.h"
#include "Render_System.h"
#include "Movement_System.h"
#include "Camera_System.h"
#include "Interaction_System.h"
#include "Resource_handler.h"
#include "Sprite.h"

#include <string>

/** Manager class for overall game operation.  All game entities, systems, and data are stored
 *  within the game manager.  Systems all hold a pointer the the game manager so they can access
 *  data and other systems when needed.  The game manager offers a single point of access and storage
 *  for game information.
 */
class Game_Manager{
  
public:
    static const int LOADING_SCREEN;
    static const int MENU;
    static const int WORLD_VIEW;
    
    typedef void (*interactionFunction)(Game_Manager*,Entity*,Entity*);
    
    
    ~Game_Manager();
    Game_Manager();
    Game_Manager(string resource_config, int screenW, int screenH);
    
    bool add_system(string ID, System* newSystem);
    Entity* register_entity(Entity* newEntity);
    bool register_interaction(string type, interactionFunction func);
    
    Entity* create_screen_entity(int w, int h, int bpp);
    Entity* create_camera_entity(int x, int y, int w, int h);
    System* create_system(string ID);
    Entity* create_user_entity(int id, string initName, int initX, int initY, Sprite* sprite);
    
    Entity* get_entity(int ID);
    
    /** Used to get a pointer to a desired sprite object that is stored in the resource handler
     *
     *  @param id The unique, string id of the resource.  It could be a filepath, or a unique name.
     *  @return a pointer to the sprite object, or NULL if it doesn't exist
     *
     *  @see Sprite
     */
    Sprite* get_sprite(string ID) { return resource_handler_->get_sprite(ID); }
    System* get_system(string ID);
    
    void handle_input();
    bool initializeSDL();
    void initializeGameLoop();
    
    /** Used to check whether the game loop is running or not
     *
     *  @return True if the game loop is running, False otherwise
     */
    bool is_running() { return running_; }
    
    /** 
     *  Loads image assets defined in a specified file
     *
     *  @param filepath The filepath of the configuration file that contiains the filepaths
     *  of all required game images
     */
    void load_images(string filepath) { resource_handler_->load_images(filepath); }
    
    
    void set_world_bounds(int w, int h);

private:
    int state;  /** < Current state of the game.  **/
    Message_Handler* message_handler_;  /** < Stores a pointer to a message handler **/
    map<string, System*> registered_systems_;  /** < Stores registered system objects **/
    map<int,Entity*> registered_entities_;  /** < Stores all registered game entities using an int as a unique id which is used to access an entity **/
    Resource_Handler* resource_handler_;   /** < Stores a pointer to a resource handler object **/
    
    Uint32 start_; /** < Used for controlling game timing **/
    SDL_Event event_;  /** < Used for handling game event loop **/
    bool running_;  /** Flag for tracking whether the game loop is currently running **/
    bool keysHeld_[323];  /** < Array to store whether or not a key is being held down **/
    
    /** 
     *  Used to gain access to the message handler
     *
     *  @return a pointer to the message handler
     *  @see Message_Handler
     */
    Message_Handler* get_message_handler_() { return message_handler_;}
    
    /** Used to gain access to the resource handler
     *
     *  @return a pointer to the resource handler
     *  @see Resource_Handler
     */
     Resource_Handler* get_resource_handler_() { return resource_handler_;}   
    
};


#endif
