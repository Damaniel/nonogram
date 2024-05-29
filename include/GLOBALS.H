#pragma once

typedef enum {
    STATE_TITLE,
    STATE_LOAD_MENU,
    STATE_GAME,
    STATE_SAVE,
    STATE_LOAD,
    STATE_COMPLETE,
    STATE_EXIT
} GameState;

typedef struct {
    char background_area;
    char status_overview_area;
    char timer;
    char button_area;
    char buttons;
    char puzzle_area;
    char puzzle;
    char hints;
} RenderComponents;

typedef struct {
    RenderComponents render;
    GameState current_state, previous_state;
    long elapsed_seconds;
    long start_ticks;
    char exit_game;
} GameGlobals;

extern GameGlobals g_globals;
extern unsigned long g_game_ticks;
