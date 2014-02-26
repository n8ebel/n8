/*
 * Values.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef VALUES_H
#define VALUES_H

#include <string>

static const int GAME_STATE = 0;
static const int MENU_STATE = 1;

static const std::string STATES[2] = {"Game State", "Menu State"};

static const std::string EXIT_STATE_EVENT = "Exit State Event";
static const std::string MENU_STATE_EVENT = "Menu State Event";
static const std::string GAME_STATE_EVENT = "Game State Event";

static const std::string HERO_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/sayain2.png";
static const std::string BOARD_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/ConnectFourBoard.png";

static const std::string BACKGROUND_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/background.bmp";
static const std::string MENU_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/Menu.png";

#endif
