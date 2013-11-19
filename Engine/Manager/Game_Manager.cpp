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

#include "Game_Manager.h"





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
    input_handler_ = new Input_Handler();
    input_handler_->register_action_object(this);
    running_ = false;
    initializeSDL();
    screen_ = NULL;
    camera_ = NULL;

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
    input_handler_ = new Input_Handler();
    input_handler_->register_action_object(this);
    initializeSDL();
    running_ = false;
    screen_ = NULL;
    camera_ = NULL;
    
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

/** Initializes the essential game systems that are required by the game to
 *  run with minimal functionality.  These include Render_System, Movement_System,
 *  Camera_System
 */
bool Game_Manager::initializeGame(){
/*** Set up the game systems ***/

	/* Create a base system */
	System* baseSystem = create_system(BASE_SYSTEM);
	if( baseSystem == NULL){
		Log::error("Main","Game manager wasn't initialized");
	}
	else{
		Log::info("Main","Game manager was initialized");
	}

	/* Create a render system */
	Render_System* renderSystem = (Render_System*)create_system(RENDER_SYSTEM);
	if (renderSystem == NULL) {
		Log::error("Main","Render system wasn't initialized");
	}
	else{
		Log::info("Main","Render system was initialized");
	}

	/* Create a camera system */
	Camera_System* cameraSystem = (Camera_System*)create_system(CAMERA_SYSTEM);
	if (cameraSystem == NULL) {
		Log::error("Main","Camera system wasn't initialized");
	}
	else{
		Log::info("Main","Camera system was initialized");
	}
    
    initialize_screen(100, 100, 32);
    
    return true;
    
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
   // for (int i = 0; i < 323; i++) {
        //keysHeld_[i] = false;
   // }
}

/** Handles game input from the mouse or keyboard
 */
void Game_Manager::handle_input(){
    input_handler_->handle_input();
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
    registered_entities_[newEntity->get_id()] = newEntity;
    
    if (newEntity->get_type() == BACKGROUND_TYPE) {
        static_cast<Render_System*>(registered_systems_[RENDER_SYSTEM])->add_base_layer(newEntity);
    }
    else if (newEntity->get_type() == SCREEN_TYPE ){
        
    }
    else{
        map<string,System*>::iterator ii;
        for( ii=registered_systems_.begin(); ii != registered_systems_.end(); ii++){
            ii->second->register_entity(newEntity);
        }
    }
    
    return newEntity;
}

/** Removes all flagged entities from the game
 */
void Game_Manager::remove_entities(){
    for (int i = 0; i < entities_to_remove_.size(); i++) {
        remove_entity(entities_to_remove_[i]);
    }
    
    entities_to_remove_.clear();
}

/** Adds the specified entity to the vector of entities that need to be removed
 *  from the game.  
 *
 *  @param entity The entity to mark as needing removed
 */
void Game_Manager::flag_to_remove_entity(Entity* entity){
    entities_to_remove_.push_back(entity);
}

/** Removes the specified entity from the game.  This includes removing
 *  references to the entity from all game systesm.
 *
 *  @param entity The entity to remove from the game
 */
void Game_Manager::remove_entity(Entity* entity){
	int ID = entity->get_id();

	map<string,System*>::iterator ii;
	for( ii=registered_systems_.begin(); ii != registered_systems_.end(); ii++){
		ii->second->remove_entity(ID);
	}

	registered_entities_.erase(ID);
	delete entity;
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


void Game_Manager::register_key_action(int keyID, Input_Handler::keyActionFunction func, int state){
    input_handler_->register_key_action(keyID,func,state);
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
        System* newSystem = new System(this);
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

/** Creates a new drawable entity.
 *  Using this method ensures the proper components are added to the entity so it can be drawn to the screen. <p>
 *  Added components include: Position, Drawable
 *
 *  @param id the id for the new user entity
 *  @param initX the initial x position
 *  @param intiY the initial y position
 *  @param sprite the sprite to use to draw the entity
 *  @return a pointer to the created entity
 *
 *  @see Entity
 *  @see Position_Component
 *  @see Drawable_Component
 *  @see Component
 */
Entity* Game_Manager::create_drawable_entity(int id, string tp, int initX, int initY, Sprite* sprite){

    if (sprite != NULL) {


        Entity* foo = new Entity(id, tp);
        Position_Component* position = new Position_Component(POSITION, initX, initY, sprite->get_width(), sprite->get_height());
        Drawable_Component* drawable = new Drawable_Component(DRAWABLE, sprite);

        foo->add_component(position);
        foo->add_component(drawable);

        register_entity(foo);
        return foo;
    }
    else{
    	Log::error("Game_Manager.create_user_entity", "Failed to create drawable entity. Sprite was NULL" );
        return NULL;
    }

}

/** Creates a new user controllable entity.
 *  Using this method ensures the proper components are added to the entity so it can be controlled by a user. <p>
 *  Added components include: Position, Drawable
 *
 *  @param id the id for the new user entity
 *  @param initX the initial x position
 *  @param intiY the initial y position
 *  @param sprite the sprite to use to draw the entity
 *  @return a pointer to the created entity
 *
 *  @see Entity
 *  @see Position_Component
 *  @see Drawable_Component
 *  @see Component
 */
Entity* Game_Manager::create_controllable_entity(int id, string tp, int initX, int initY, Sprite* sprite){
    
    if (sprite != NULL) {
        
    
        Entity* foo = new Entity(id, tp);
        //Name_Component* name = new Name_Component(NAME, initName);
       
        
        Position_Component* position = new Position_Component(POSITION, initX, initY, sprite->get_width(), sprite->get_height());
        
        //Size_Component* size = new Size_Component(SIZE,sprite->get_width(), sprite->get_height());
        
        Drawable_Component* drawable = new Drawable_Component(DRAWABLE, sprite);  
        Controllable_Coponent* controllable = new Controllable_Coponent(CONTROLLABLE);
        
        //foo->add_component(name);
        foo->add_component(position);
        foo->add_component(drawable);
        foo->add_component(controllable);
        //foo->add_component(size);
        
        
        register_entity(foo);
        return foo;
    }
    else{
    	Log::error("Game_Manager.create_controllable_entity", "Failed to create entity" );
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
bool Game_Manager::initialize_screen(int w, int h, int bpp){
    
    if (screen_ != NULL) {
        remove_entity(screen_);
        screen_ = NULL;
    }
    
    SDL_Surface *screen_surface = NULL;
    screen_surface = SDL_SetVideoMode(w, h, bpp, SDL_SWSURFACE);
    
    //If there was an error in setting up the screen
    if( screen_surface == NULL )
    {
    	Log::error("Game_Manager.create_screen_entity","Problem setting up screen");
        return NULL;    
    }
    
    screen_ = new Entity(SCREEN, SCREEN_TYPE);  // uses 'SCREEN' const value of -1
    if (screen_ != NULL) {
        
        Sprite* screenSprite = new Sprite("SCREEN", screen_surface);
        if (screenSprite == NULL) {
            delete screen_;
            screen_ = NULL;
            return false;
        }
        screen_->add_component(new Drawable_Component(DRAWABLE, screenSprite));
        screen_->add_component(new Position_Component(POSITION, 0, 0, screenSprite->get_width(), screenSprite->get_height()));
		screen_->add_component(new Color_Component(COLOR, 0,0,0));
        
        register_entity(screen_);
        
        Render_System* renderSystem = static_cast<Render_System*>(get_system(RENDER_SYSTEM));
        renderSystem->register_screen_entity(screen_);
    }
    else{
        return false;
    }
    

    return true;
    
    
}

void Game_Manager::set_screen_color(int r, int g, int b){
	if(screen_ != NULL && screen_->get_component(COLOR) != NULL){
		static_cast<Color_Component*>(screen_->get_component(COLOR))->set_color(r,g,b);
	}
	else{
		Log::error("Game_Manager.set_screen_color(r,g,b)","Could not set screen color.  Either screen was null or it does not have a Color_Component");
	}

}
void Game_Manager::set_screen_color(int a ,int r, int g, int b){
	if(screen_ != NULL && screen_->get_component(COLOR) != NULL){
		static_cast<Color_Component*>(screen_->get_component(COLOR))->set_color(a,r,g,b);
	}
	else{
		Log::error("Game_Manager.set_screen_color(a,r,g,b)","Could not set screen color.  Either screen was null or it does not have a Color_Component");
	}
}

/** Used to create a camera entity that is used to control what is drawn to the screen.
 *  Once the entity is created, it is registered to the camera and render systems
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
bool Game_Manager::initialize_camera(int x, int y){//, int w, int h){
    camera_ = new Entity(CAMERA, CAMERA_TYPE);
    if( camera_ != NULL){
        camera_->add_component(new Position_Component(POSITION, x,y, 
                                                      n8::get_position_component(screen_)->get_width(), 
                                                      n8::get_position_component(screen_)->get_height()));
        
        register_entity(camera_);

        static_cast<Camera_System*>(get_system(CAMERA_SYSTEM))->register_camera_entity(camera_);
        static_cast<Render_System*>(get_system(RENDER_SYSTEM))->register_camera_entity(camera_);
    }
    else{
        return false;
    }
                          
    return true;
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
