#pragma once


#define MAX_PUZZ_WIDTH      12
#define MAX_PUZZ_HEIGHT     12

#define PUZZLE_BASE_PATH    "res/puzzles"

// Empty - no square.  Filled - marked with a square.  Flagged - marked as 'not square' by user
typedef enum {
    SQUARE_EMPTY,
    SQUARE_FILLED,
    SQUARE_FLAGGED
} SquareType;

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
    int collection;
    int level;
    int category;
    int width;
    int height;
} PuzzleMetadata;

// The key regions of the puzzle area.
// Since the puzzle can be of varying sizes, the puzzle area needs to be 
// dynamic.
//
// pax, pay - the main puzzle area
// hxx, hxy - x (i.e. horizontal) hints
// hyy, hyy - y (i.e. vertical) hints
// hshade - the horizontal shading
// vshade - the vertical shading
typedef struct {
    char pax1, pay1, pax2, pay2;
    char hxx1, hxy1, hxx2, hxy2;
    char hyx1, hyy1, hyx2, hyy2;
    char hshade_x, hshade_y, hshade_w;
    char vshade_x, vshade_y, vshade_h;
} PuzzleArea;

typedef struct {
    PuzzleMetadata metadata;
    char num_row_hints[MAX_PUZZ_HEIGHT];
    char num_col_hints[MAX_PUZZ_WIDTH];
    char squares[MAX_PUZZ_WIDTH][MAX_PUZZ_HEIGHT];
    SquareType filled_status[MAX_PUZZ_WIDTH][MAX_PUZZ_HEIGHT];
    char row_hints[MAX_PUZZ_HEIGHT][MAX_PUZZ_WIDTH / 2];
    char col_hints[MAX_PUZZ_WIDTH][MAX_PUZZ_HEIGHT / 2];
} Puzzle;

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
    Puzzle current_puzzle;
    PuzzleArea pa;
    long elapsed_seconds;
    long start_ticks;
    char exit_game;
} GameGlobals;

extern GameGlobals g_globals;
extern unsigned long g_game_ticks;
