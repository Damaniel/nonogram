#pragma once

#include "includes.h"

extern void select_all_game_components(void);

// Draw the static background elements
extern void draw_background(void);

// Draw the buttons in the lower right corner
extern void draw_buttons(void);

// Draw the status window (minus the timer)
extern void draw_status_overview(void);

// Draw the timer
extern void draw_timer(void);

// Draw the board (minus the hints and puzzle data)
extern void draw_board(void);

// Draw the in-progress puzzle work
extern void draw_puzzle(void);

// Draw the hint text
extern void draw_hints(void);

// Draw whatever is needed for the current state
extern void render(void);
