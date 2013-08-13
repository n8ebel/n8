/*
 * Game_Manager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "n8.h"



#include "Game_Manager.h"


const int Game_Manager::LOADING_SCREEN = 1;
const int Game_Manager::MENU = 2;
const int Game_Manager::WORLD_VIEW = 3;


/** Destructor <p>
 */
Game_Manager::~Game_Manager(){
    if (resource_handler_ != NULL) {
        delete resource_handler_;
    }
    
    map<int, Entity*>::iterator entitiesIterator;
    for (entitiesIterator= registered_entities_.begin(); entitiesIterator != registered_entities_.end(); entitiesIterator++) {
        delete entitiesIterator->second;
    }
    
    map<string, System*>::iterator systemsIterator ;
    for (systemsIterator= registered_systems_.begin(); systemsIterator != registered_systems_.end(); systemsIterator++) {
		delete systemsIterator->second;
	}

    
}
/** Default Constructor<p>
 *  Used to create a new Game_Manager object
 */
Game_Manager::Game_Manager(){
    message_handler_ = NULL;
    resource_handler_ = new Resource_Handler();
    running_ = false;
    initializeSDL();
}

/** Constructor<p>
 *  Used to create a new Game_Manager object
 *  
 *  @param resource_config the filepath of the resource configuration file to use to load assets
 *  @param screenW the width of the desired screen
 *  @param screenH the height of the desired screen
 */
Game_Manager::Game_Manager(string resource_config, int screenW, int screenH){
    message_handler_ = NULL;
    resource_handler_ = new Resource_Handler();
    initializeSDL();
    running_ = false;
    
}

bool Game_Manager::initializeSDL(){
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }
    else{
        return true;
    }
}

/** Used to initialize the SDL driven game loop.
 *  Starts the game timer, sets running_ to True
 *  Initializes the keysHeld array to be false indicating that no keys have been pressed
 */
void Game_Manager::initializeGameLoop(){
    //The timer start_ing time
    start_ = 0;
    running_ = true;
    start_ = SDL_GetTicks();
    for (int i = 0; i < 323; i++) {
        keysHeld_[i] = false;
    }
}

/** Handles game input from the mouse or keyboard
 */
void Game_Manager::handle_input(){
    if (SDL_PollEvent(&event_))
    {
        if (event_.type == SDL_QUIT)
        {
            running_ = false;
        }
        
        if (event_.type == SDL_KEYDOWN)
        {
            keysHeld_[event_.key.keysym.sym] = true;
        } 
        if (event_.type == SDL_KEYUP)
        {
            keysHeld_[event_.key.keysym.sym] = false;
        }
    }
    
    if ( keysHeld_[SDLK_ESCAPE] )
    {
        running_ = false;
    }
    
    if ( keysHeld_[SDLK_LEFT] )
    {
        n8::log_debug("Game_Manager","Moved left");
        ((Movement_System*)registered_systems_[MOVEMENT_SYSTEM])->left();
    }
    if ( keysHeld_[SDLK_RIGHT] )
    {
        n8::log_debug("Game_Manager","Moved right");
        ((Movement_System*)registered_systems_[MOVEMENT_SYSTEM])->right();
    }
    if ( keysHeld_[SDLK_UP] )
    {
        n8::log_debug("Game_Manager","Moved up");
        ((Movement_System*)registered_systems_[MOVEMENT_SYSTEM])->up();
    }
    if (keysHeld_[SDLK_DOWN])
    {
        n8::log_debug("Game_Manager","Moved down");
        ((Movement_System*)registered_systems_[MOVEMENT_SYSTEM])->down();
    }
    
    
}

/** Registers a system with the game manager by storing a pointer to the system.
 *  This is how systems can be stored, retrieved, and removed from the game manager
 *
 *  @param ID the unique string id of the system.  Should indicate the type of the system
 *  @param newSystem the system to add to the systems map
 *  @return True if the system isn't already registered, False if it is
 *
 *  @see System
 */

bool Game_Manager::add_system(string ID, System* newSystem){
    map<string,System*>::iterator ii = registered_systems_.find(ID);
    
    if(ii != registered_systems_.end()){
        return false;
    }
    else{
        newSystem->connect_message_handler_(message_handler_);
        registered_systems_[ID] = newSystem;
    }
    
    return true;
}

/** Used to access a desired system from the systems map
 *
 *  @param ID the unique specifier of the system.  Determines which system to return
 *  @return a pointer to the desired system, or NULL if the system is not registered
 *
 *  @see System
 */
System* Game_Manager::get_system(string ID){
    map<string,System*>::iterator ii = registered_systems_.find(ID);
    
    if ( ii == registered_systems_.end() ) {
        return NULL;
    }
    else{
        return ii->second;
    }
}

/** Registers a new entity with the game manager
 *  Stores a pointer to the entity in a map
 *  After the entity is added to the map, it is registered with each registered system
 *
 *  @param newEntity The entity to register to the system
 *  @return a pointer to the added entity
 *
 *  @see System
 *  @see Entity
 */
Entity* Game_Manager::register_entity(Entity* newEntity){
    if (DEBUG_MODE) {
        cout << "Game_Manager.register_entity(Entity* newEntity)" << endl;
    }
    
    registered_entities_[newEntity->get_id()] = newEntity;
    
    map<string,System*>::iterator ii;
    for( ii=registered_systems_.begin(); ii != registered_systems_.end(); ii++){
        ii->second->register_entity(newEntity);
    }
    
    return newEntity;
}

/** Registers an interaction function with the interaction system if it exists
 *
 * 	@param type The identifier for the interaciton
 * 	@param func The function pointer for the interaction function
 * 	@return True if the interaction system exists and the function was successfully registered, False otherwise
 */
bool Game_Manager::register_interaction(string type, interactionFunction func){
	map<string, System*>::iterator ii = registered_systems_.find(INTERACTION_SYSTEM);
	if( ii != registered_systems_.end()){
		return dynamic_cast<Interaction_System*>(registered_systems_[INTERACTION_SYSTEM])->register_interaction(type,func);
	}
	else{
		return false;
	}

}


/** Used to access a specific registered entity
 *
 *  @param ID the unique, int specifier of the desired entity
 *  @return a pointer to the desired entity, or NULL if the entity is not registered with the system
 *
 *  @see Entity
 */
Entity* Game_Manager::get_entity(int ID){
    map<int, Entity*>::iterator ii = registered_entities_.find(ID);
    
    if ( ii == registered_entities_.end() ) {
        return NULL;
    }
    else{
        return ii->second;
    }
}


/** Used to create a desired system and register it with the game manager
 *  After the system is created, a pointer to the message handler is registered with the system
 *
 *  @param ID the unique specifier indicating what type of system to create
 *  @return a pointer to the created system, or NULL if the system is already registered
 *
 *  @see System
 *  @see n8
 */
System* Game_Manager::create_system(string ID){
    if (ID == BASE_SYSTEM) {
        System* newSystem = new System();
        newSystem->connect_message_handler_(message_handler_);
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    else if(ID == RENDER_SYSTEM){
        Render_System* newSystem = new Render_System(this);
        newSystem->connect_message_handler_(message_handler_);
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    else if(ID == MOVEMENT_SYSTEM){
        Movement_System* newSystem = new Movement_System(this);
        newSystem->connect_message_handler_(message_handler_);
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    else if(ID == CAMERA_SYSTEM){
        Camera_System* newSystem = new Camera_System(this);
        newSystem->connect_message_handler_(message_handler_);
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    else if (ID == INTERACTION_SYSTEM){
    	Interaction_System* newSystem = new Interaction_System(this);
		newSystem->connect_message_handler_(message_handler_);
		if( add_system(ID, newSystem) ){
			return newSystem;
		}
		else{
			return NULL;
		}
                                        
    }
    
    return NULL;
}


/** Creates a new user entity.
 *  Using this method ensures the proper components are added to the user entity. <p>
 *  Added components include: Name, Position, Drawable
 *
 *  @param id the id for the new user entity
 *  @param initName the name of the new user entity
 *  @param initX the initial x position
 *  @param intiY the initial y position
 *  @param sprite the sprite to use to draw the entity
 *  @return a pointer to the created entity
 *
 *  @see Entity
 *  @see Name_Component
 *  @see Position_Component
 *  @see Drawable_Component
 *  @see Component
 */
Entity* Game_Manager::create_user_entity(int id, string initName, int initX, int initY, Sprite* sprite){
    
    if (sprite != NULL) {
        
    
        Entity* foo = new Entity(id);
        Name_Component* name = new Name_Component(NAME, initName);
       
        
        Position_Component* position = new Position_Component(POSITION, initX, initY, sprite->get_width(), sprite->get_height());
        
        //Size_Component* size = new Size_Component(SIZE,sprite->get_width(), sprite->get_height());
        
        Drawable_Component* drawable = new Drawable_Component(DRAWABLE, sprite);  
        Controllable_Coponent* controllable = new Controllable_Coponent(CONTROLLABLE);
        
        foo->add_component(name);
        foo->add_component(position);
        foo->add_component(drawable);
        foo->add_component(controllable);
        //foo->add_component(size);
        
        
        register_entity(foo);
        return foo;
    }
    else{
        n8::log_error("Game_Manager.create_user_entity", "Failed to create entity " + initName + ". Sprite was NULL" );
        return NULL;
    }
    
}

/** Used to create a screen entity that can be used to draw on
 *
 *  @param w the width of the desired screen
 *  @param h the height of the desired screen
 *  @param bpp desired bits per pixel
 *  @return a pointer to the created entity
 *
 *  @see Entity
 *  @see Drawable_Component
 *  @see Position_Component
 *  @see Component
 *  @see n8
 */
Entity* Game_Manager::create_screen_entity(int w, int h, int bpp){
    SDL_Surface *screen_surface = NULL;
    
    
    
    //Set up the screen
    screen_surface = SDL_SetVideoMode(w, h, bpp, SDL_SWSURFACE);
    
    //If there was an error in setting up the screen
    if( screen_surface == NULL )
    {
        n8::log_error("Game_Manager.create_screen_entity","Problem setting up screen");
        return NULL;    
    }
    
    Entity* entScreen = new Entity(SCREEN);  // uses 'SCREEN' const value of -1
    Sprite* screenSprite = new Sprite("SCREEN", screen_surface);
    entScreen->add_component(new Drawable_Component(DRAWABLE, screenSprite));
    entScreen->add_component(new Position_Component(POSITION, 0, 0, screenSprite->get_width(), screenSprite->get_height()));
    
    register_entity(entScreen);
    
    return entScreen;
    
}

/** Used to create a camera entity that is used to control what is drawn to the screen
 *
 *  @param x the x position of the camera
 *  @param y the y position of the camera
 *  @param w the width of the camera
 *  @param h the height of the camera
 *  @return a pointer to the created camera entity
 *
 *  @see Entity
 *  @see Size_Component
 *  @see Position_Component
 *  @see Component
 *  @see n8
 */
Entity* Game_Manager::create_camera_entity(int x, int y, int w, int h){
    Entity* camera = new Entity(CAMERA);
    camera->add_component(new Position_Component(POSITION, x,y, w, h));
    //camera->add_component(new Size_Component(SIZE, w,h));
    
    register_entity(camera);
                          
    return camera;
}

/** Used to set the dimensions of the current game world.
 *  This is used by the movement system and camera system to control how enties move and are displayed
 *
 *  @param w the width of the current game world
 *  @param h the height of the current game world
 *
 *  @see Movement_System
 *  @see Camera_System
 */
void Game_Manager::set_world_bounds(int w, int h){
    if (get_system(MOVEMENT_SYSTEM) != NULL) {
        ((Movement_System*)registered_systems_[MOVEMENT_SYSTEM])->set_world_bounds(w, h);
    }
    if(get_system(CAMERA_SYSTEM)){
        ((Camera_System*)registered_systems_[CAMERA_SYSTEM])->set_world_bounds(w, h);
    }
}
