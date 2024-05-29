#pragma once

#include "includes.h"

#define VERSION          "v0.01 (05/29/2024)"

#define TITLE_BAR_X             0
#define TITLE_BAR_Y             0

#define TITLE_TEXT_X            3    
#define TITLE_TEXT_Y            0

#define VERSION_TEXT_X         61
#define VERSION_TEXT_Y          0

#define STATUS_X1              52
#define STATUS_Y1               2
#define STATUS_X2              74
#define STATUS_Y2              11


#define STATUS_LEVEL_TEXT_X         54
#define STATUS_LEVEL_TEXT_Y          3
#define STATUS_CATEGORY_TEXT_X      54
#define STATUS_CATEGORY_TEXT_Y       6
#define STATUS_TIME_TEXT_X          54
#define STATUS_TIME_TEXT_Y           9
#define STATUS_LEVEL_X              61
#define STATUS_LEVEL_Y               4
#define STATUS_CATEGORY_X           61
#define STATUS_CATEGORY_Y            7
#define STATUS_TIME_X               61
#define STATUS_TIME_Y               10

#define BUTTONS_AREA_X1             52
#define BUTTONS_AREA_Y1             16
#define BUTTONS_AREA_X2             74
#define BUTTONS_AREA_Y2             22
#define BUTTON_V_DIVIDER_X          63
#define BUTTON_V_DIVIDER_Y          16
#define BUTTON_V_DIVIDER_H         7
#define BUTTON_H1_DIVIDER_X         52
#define BUTTON_H1_DIVIDER_Y         18
#define BUTTON_H2_DIVIDER_X         52
#define BUTTON_H2_DIVIDER_Y         20
#define BUTTON_H_DIVIDER_W          23
#define BUTTON_HELP_X               56
#define BUTTON_HELP_Y               17
#define BUTTON_OPTS_X               67  
#define BUTTON_OPTS_Y               17
#define BUTTON_SAVE_X               56
#define BUTTON_SAVE_Y               19
#define BUTTON_LOAD_X               67
#define BUTTON_LOAD_Y               19
#define BUTTON_MARK_X               56
#define BUTTON_MARK_Y               21
#define BUTTON_EXIT_X               67
#define BUTTON_EXIT_Y               21

// The position of the largest puzzle area. This will move depending on the puzzle size
// We'll try to calculate the positions based on the puzzle size and these constants.
#define PUZZLE_AREA_MIN_X   19
#define PUZZLE_AREA_MIN_Y   9

#define PUZZLE_TOP_AREA_MIN_X1       19
#define PUZZLE_TOP_AREA_MIN_Y1        2
#define PUZZLE_TOP_AREA_MIN_X2       44
#define PUZZLE_TOP_AREA_MIN_Y2        9

#define PUZZLE_LEFT_AREA_MIN_X1       5
#define PUZZLE_LEFT_AREA_MIN_Y1       9
#define PUZZLE_LEFT_AREA_MIN_X2      19
#define PUZZLE_LEFT_AREA_MIN_Y2      22