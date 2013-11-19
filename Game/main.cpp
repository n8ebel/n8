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
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 850;
const int WORLD_WIDTH = SCREEN_WIDTH;
const int WORLD_HEIGHT = 2 * SCREEN_HEIGHT;

const int SCREEN_BPP = 32;

const int FPS = 100;

void RegisterInteractions(Game_Manager* game);
void PickInteraction(Interaction_System* sys, Entity* ent1, Entity* ent2);

Entity* CreateUserEntity(Game_Manager* game, string name, int x, int y, Sprite* sprite);
Entity* CreateEnemyEntity(Game_Manager* game, string type, int x, int y, Sprite* sprite, double xHeading, double yHeading, double magnitude, bool worldBound);

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

    game->set_world_bounds(SCREEN_WIDTH, SCREEN_HEIGHT*2);
    
/*** Create the screen and register it ***/
    game->initialize_screen(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    game->set_screen_color(100, 100, 100);
    
/*** Create the camera entity ***/
    game->initialize_camera(0, 0);//, SCREEN_WIDTH, SCREEN_HEIGHT);

/*** Load image resources ***/
    game->load_images("/Users/lcballa44/Projects/n8/Assets/gfx/images.txt");
    
    //Sprite* message = game->get_sprite("/Users/lcballa44/Projects/n8/Assets/gfx/hello.bmp");
    Sprite* background = game->get_sprite( "/Users/lcballa44/Projects/n8/Assets/gfx/background.bmp" );
    Sprite* shipSprite = game->get_sprite("/Users/lcballa44/Projects/n8/Assets/gfx/user_ship.bmp");
    Sprite* enemySprite = game->get_sprite("/Users/lcballa44/Projects/n8/Assets/gfx/enemy_ship.bmp");
    //Sprite* missileSprite = game->get_sprite("/Users/lcballa44/Desktop/n8/Assets/gfx/missile.bmp");
    

/*** Create background entity ***/
    //Entity* entBackground = game->create_drawable_entity(BACKGROUND, BACKGROUND_TYPE, 0, 0, background);
	Entity* entBackground = new Entity(n8::get_next_id(), BACKGROUND_TYPE);
    entBackground->add_component(new Drawable_Component(DRAWABLE, background));
	entBackground->add_component(new Position_Component(POSITION, 200, 200, background->get_width(), background->get_height()));
    game->register_entity(entBackground);
    //static_cast<Render_System*>(game->get_system(RENDER_SYSTEM))->add_base_layer(entBackground);
    
/*** Create user controlled entity ***/
    CreateUserEntity(game, "Nate", WORLD_WIDTH/2, WORLD_HEIGHT - 2*shipSprite->get_height(), shipSprite);
    

/*** Create enemy entities ***/
    CreateEnemyEntity(game, ENEMY_TYPE, 400,400, enemySprite, 1,1,2, true);
    CreateEnemyEntity(game, ENEMY_TYPE, 350,700, enemySprite, -1,-1,1, true);

/*** GAME LOOP ***/
    game->initializeGameLoop();
    
    
    Uint32 time;
    while (game->is_running()) {
        
        time = SDL_GetTicks();
                
            game->handle_input();
            
            /*** Update the game logic ***/
            game->get_system(MOVEMENT_SYSTEM)->update();
            game->get_system(INTERACTION_SYSTEM)->update();
            game->remove_entities();
            
            game->get_system(CAMERA_SYSTEM)->update();
            game->get_system(RENDER_SYSTEM)->update();
            
            /*** Render the frame ***/
            static_cast<Render_System*>(game->get_system(RENDER_SYSTEM))->render();
            
        
        if ( 1000/FPS > SDL_GetTicks() - time) {
            SDL_Delay(1000/FPS - (SDL_GetTicks() - time));
        }

    }
    
    
    delete game;
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}

void StopGame(Object* obj){
	Game_Manager* game = static_cast<Game_Manager*>(obj);
	Log::debug("Game_Manager","Stopped Game");
	game->set_running(false);
}
void Left(Object* obj){
	Game_Manager* game = static_cast<Game_Manager*>(obj);
	Log::debug("Game_Manager","Moved Left");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(-5,0);
}
void Right(Object* obj){
	Game_Manager* game = static_cast<Game_Manager*>(obj);
	Log::debug("Game_Manager","Moved Right");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(5,0);
}
void Up(Object* obj){
	Game_Manager* game = static_cast<Game_Manager*>(obj);
	Log::debug("Game_Manager","Moved Up");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(0,-5);
}
void Down(Object* obj){
	Game_Manager* game = static_cast<Game_Manager*>(obj);
	Log::debug("Game_Manager","Moved Down");
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->move(0,5);
}
void Space(Object* obj){
	Game_Manager* game = static_cast<Game_Manager*>(obj);
	Log::debug("Game_Manager", "Pressed Space");
	Entity* userEntity = static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->get_user_entity();
	Position_Component* userPosition = static_cast<Position_Component*>(userEntity->get_component(POSITION));
    Sprite* projectileSprite = game->get_sprite("/Users/lcballa44/Projects/n8/Assets/gfx/missile.bmp");
    
	CreateEnemyEntity(game, PROJECTILE_TYPE,  userPosition->get_x(), userPosition->get_y() - projectileSprite->get_height() ,
						projectileSprite,
						0, -1, 2, false);
}
void SetupKeyInput(Game_Manager* game){
	game->register_key_action(SDLK_ESCAPE, StopGame, Input_Handler::DOWN);
	game->register_key_action(SDLK_LEFT, Left, Input_Handler::DOWN);
	game->register_key_action(SDLK_RIGHT, Right ,Input_Handler::DOWN);
	game->register_key_action(SDLK_UP, Up, Input_Handler::DOWN);
	game->register_key_action(SDLK_DOWN, Down, Input_Handler::DOWN);
	game->register_key_action(SDLK_SPACE, Space, Input_Handler::UP);
    
    game->get_input_handler()->register_exit_action(StopGame);

}

bool SetupGameSystems(Game_Manager* game){
/* Create a movement system */
	Movement_System* movementSystem = (Movement_System*)game->create_system(MOVEMENT_SYSTEM);
	if (movementSystem == NULL) {
		Log::error("Main","Movement system wasn't initialized");
		return false;
	}
	else{
		Log::info("Main","Movement system was initialized");
	}

	/* Create an interaction system */
	Interaction_System* interactionSystem = (Interaction_System*)game->create_system(INTERACTION_SYSTEM);
	if (interactionSystem == NULL) {
		Log::error("Main","Interaction system wasn't initialized");
		return false;
	}
	else{
	   Log::info("Main","Interaction system was initialized");
	   interactionSystem->register_pick_interaction_function(PickInteraction);
	}

	RegisterInteractions(game);

	return true;
}

Entity* CreateUserEntity(Game_Manager* game, string name, int x, int y, Sprite* sprite){
	Entity* newEntity = game->create_controllable_entity(n8::get_next_id(), USER_TYPE, x, y, sprite);
    Name_Component* nameComp = new Name_Component(NAME,name);
	newEntity->add_component(nameComp);

	game->register_entity(newEntity);

	static_cast<Camera_System*>(game->get_system(CAMERA_SYSTEM))->register_entity_to_follow(newEntity);
	static_cast<Movement_System*>(game->get_system(MOVEMENT_SYSTEM))->register_user_entity(newEntity);

	return newEntity;
}

Entity* CreateEnemyEntity(Game_Manager* game, string type, int x, int y, Sprite* sprite, double xHeading, double yHeading, double magnitude, bool worldBound){
	Entity* newEntity = game->create_drawable_entity(n8::get_next_id(), type, x, y, sprite);
	newEntity->add_component(new Movement_Component(MOVEMENT, xHeading, yHeading, magnitude, worldBound));
    
    game->register_entity(newEntity);
    
	return newEntity;
}

void ProjectileInteraction(Game_Manager* game, Entity* ent1, Entity* ent2){
    
    Log::info("PROJECTILE_INTERACTION", Numerical_Utilities::num_to_string(ent1->get_id()) );
    Log::info("PROJECTILE_INTERACTION", Numerical_Utilities::num_to_string(ent2->get_id()) );
	if ( ent1->get_type() == PROJECTILE_TYPE){
		game->flag_to_remove_entity(ent2);
	}
	else{
		game->flag_to_remove_entity(ent1);
	}
}

void GenericInteraction(Game_Manager* game, Entity* ent1, Entity* ent2){
	//n8::log_info("GENERIC_INTERACTION", "Entity 1: " + ent1->get_id() + "  Entity 2: " + ent2->get_id());
}

void RegisterInteractions(Game_Manager* game){
	if ( game->register_interaction(GENERIC_INTERACTION, GenericInteraction) ){
		Log::info("Main", "GENERIC_INTERACTION was registered");
	}
	else{
		Log::error("Main", "GENERIC_INTERACTION could not be registered");
	}
	if ( game->register_interaction(PROJECTILE_INTERACTION, ProjectileInteraction) ){
		Log::info("Main", "PROJECTILE_INTERACTION was registered");
	}
	else{
		Log::error("Main", "PROJECTILE_INTERACTION could not be registered");
	}

}

void PickInteraction(Interaction_System* sys, Entity* ent1, Entity* ent2){
	if( ent1->get_type() == PROJECTILE_TYPE || ent2->get_type() == PROJECTILE_TYPE ){
		sys->handle_interaction(PROJECTILE_INTERACTION, ent1, ent2);
	}
	else{
		sys->handle_interaction(GENERIC_INTERACTION, ent1, ent2);
	}
}

