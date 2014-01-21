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

using namespace std;

static const int GAME_STATE = 0;
static const int MENU_STATE = 1;

static const string STATES[2] = {"Game State", "Menu State"};

static const string EXIT_STATE_EVENT = "Exit State Event";
static const string MENU_STATE_EVENT = "Menu State Event";

static const string HERO_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/sayain2.png";
static const string BOARD_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/ConnectFourBoard.png";

static const string BACKGROUND_SPRITE = "/Users/lcballa44/Projects/n8/New/Game/gfx/background.bmp";

#endif
