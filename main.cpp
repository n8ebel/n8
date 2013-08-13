//
//  main.cpp
//  n8
//
//  Created by Nate Ebel on 7/26/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "SDL/SDL.h"
#include "n8.h"
#include "Game_Manager.h"
#include <iostream>

using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;

//SDL_Surface* load_image(string);
//void apply_surface(int,int, SDL_Surface*, SDL_Surface*);
void RegisterInteractions(Game_Manager* game);
Entity* CreateUserEntity(Game_Manager* game, string name, int x, int y, Sprite* sprite);
Entity* CreateEnemyEntity(Game_Manager* game, int x, int y, Sprite* sprite);
bool SetupGameSystems(Game_Manager* game);
void SetupKeyInput(Game_Manager* game);

int main( int argc, char* argv[] )
{   
    
/*** Create the game manager ****/
    Game_Manager* game = new Game_Manager();
    if(game->initializeSDL()){ cout << "SDL initialized" << endl; }
    else{ cout << "SDL not initialized" << endl; }  

/***  Set the window caption  ***/
    SDL_WM_SetCaption( "n8", NULL );
    
    game->initializeGame();
    SetupGameSystems(game);
    SetupKeyInput(game);

    game->set_world_bounds(SCREEN_WIDTH, SCREEN_HEIGHT);
    
/*** Create the screen and register it ***/
    Entity* entScreen = game->create_screen_entity(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    //renderSystem->register_screen_entity(entScreen);
    
/*** Create the camera entity ***/
    Entity* entCamera = game->create_camera_entity(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    //cameraSystem->register_camera_entity(entCamera);
    //renderSystem->register_camera_entity(entCamera);

/*** Load image resources ***/
    game->load_images("/Users/lcballa44/Desktop/n8/Assets/gfx/images.txt");
    
    Sprite* message = game->get_sprite("/Users/lcballa44/Desktop/n8/Assets/gfx/hello.bmp");
    Sprite* background = game->get_sprite( "/Users/lcballa44/Desktop/n8/Assets/gfx/background.bmp" );
    

/*** Create background entity ***/
    Entity* entBackground = game->create_drawable_entity(BACKGROUND, BACKGROUND_TYPE, 0, 0, background);
    //Entity* entBackground = new Entity(BACKGROUND);
    //entBackground->add_component(new Position_Component(POSITION, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    //entBackground->add_component(new Drawable_Component(DRAWABLE, background));
    //game->register_entity(entBackground);
    
/*** Create user controlled entity ***/
    Entity* nate = CreateUserEntity(game, "Nate", 0,0, message);
    

/*** Create entity ***/
    Entity* megan = CreateEnemyEntity(game, 400,400, message);
    Entity* vader = CreateEnemyEntity(game, 350,700, message);
    //game->create_user_entity(n8::get_next_id(), "Megan", 450, 200, message);
    

  
/*** GAME LOOP ***/
    game->initializeGameLoop();
    
    while (game->is_running()) {
        game->handle_input();
        
        /*** Update the game logic ***/
        game->get_system(MOVEMENT_SYSTEM)->update();
        game->get_system(INTERACTION_SYSTEM)->update();
        game->get_system(CAMERA_SYSTEM)->update();
        game->get_system(RENDER_SYSTEM)->update();
        
        /*** Render the frame ***/
        n8::get_render_system(game)->render();
        //renderSystem->render();
        
    }
    
    
    delete game;
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}

void StopGame(Game_Manager* game){
	n8::log_debug("Game_Manager","Stopped Game");
	game->set_running(false);
}
void Left(Game_Manager* game){
	n8::log_debug("Game_Manager","Moved Left");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(-5,0);
}
void Right(Game_Manager* game){
	n8::log_debug("Game_Manager","Moved Right");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(5,0);
}
void Up(Game_Manager* game){
	n8::log_debug("Game_Manager","Moved Up");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(0,-5);
}
void Down(Game_Manager* game){
	n8::log_debug("Game_Manager","Moved Down");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(0,5);
}
void SetupKeyInput(Game_Manager* game){
	game->register_key_action(SDLK_ESCAPE, StopGame);
	game->register_key_action(SDLK_LEFT, Left);
	game->register_key_action(SDLK_RIGHT, Right);
	game->register_key_action(SDLK_UP, Up);
	game->register_key_action(SDLK_DOWN, Down);

}

bool SetupGameSystems(Game_Manager* game){
/* Create a movement system */
	Movement_System* movementSystem = (Movement_System*)game->create_system(MOVEMENT_SYSTEM);
	if (movementSystem == NULL) {
		n8::log_error("Main","Movement system wasn't initialized");
		return false;
	}
	else{
		n8::log_info("Main","Movement system was initialized");
		//movementSystem->set_world_bounds(1000, 750);
	}

	/* Create an interaction system */
	Interaction_System* interactionSystem = (Interaction_System*)game->create_system(INTERACTION_SYSTEM);
	if (interactionSystem == NULL) {
		n8::log_error("Main","Interaction system wasn't initialized");
		return false;
	}
	else{
	   n8::log_info("Main","Interaction system was initialized");
	}

	RegisterInteractions(game);

	return true;
}

Entity* CreateUserEntity(Game_Manager* game, string name, int x, int y, Sprite* sprite){
	Entity* newEntity = game->create_controllable_entity(n8::get_next_id(), USER_TYPE, x, y, sprite);
	newEntity->add_component(new Name_Component(NAME,name));
	game->register_entity(newEntity);

	static_cast<Camera_System*>(game->get_system(CAMERA_SYSTEM))->register_entity_to_follow(newEntity);
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->register_user_entity(newEntity);

	return newEntity;
}

Entity* CreateEnemyEntity(Game_Manager* game, int x, int y, Sprite* sprite){
	Entity* newEntity = game->create_drawable_entity(n8::get_next_id(), ENEMY_TYPE, x, y, sprite);

	return newEntity;
}

void ProjectileInteraction(Game_Manager* game, Entity* ent1, Entity* ent2){
    cout << "GOOOOOOOOOOOOO FOOOOOOOOOOOOOOOOO" << endl;
    SDL_WM_SetCaption( "GOOOO", NULL );
}

void RegisterInteractions(Game_Manager* game){
	if ( game->register_interaction(PROJECTILE_SYSTEM, ProjectileInteraction) ){
		n8::log_info("Main", "PROJECTILE_INTERACTION was registered");
	}
	else{
		n8::log_error("Main", "PROJECTILE_INTERACTION could not be registered");
	}

}

