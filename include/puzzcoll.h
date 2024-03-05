#pragma once

#define MAX_WIDTH   10
#define MAX_HEIGHT  10
#define MAX_PUZZLES 20

typedef struct {
    char width;
    char height;
    char puzz_data[MAX_WIDTH][MAX_HEIGHT];
} Puzzle;

typedef struct {
    char name[32];
    int num_puzzles;
    Puzzle puzzles[MAX_PUZZLES];
} Collection;

//
// The actively worked on puzzle.  Includes:
//  - The puzzle data itself
//  - Puzzle progress 
//    = 0: no filled in square, 
//    = 1: filled in square, 
//    = 2: flagged by user as not part of the puzzle
//  - The set of 'hints' for each row and column.
//    Note: these are generated on the fly from the puzzle
//      data instead of being stored with the puzzle data
//      itself.
//
//  Note that the number of hints in a row or column can
//  never be more than half the row/column's size, rounded up.
//  (i.e. a column 10 high can have up to 5 hints - '1 1 1 1 1')
//
typedef struct {
    Puzzle p;
    char puzz_progress[MAX_WIDTH][MAX_HEIGHT];
    char horizontal_hints[MAX_HEIGHT][MAX_WIDTH/2 + 1];
    char vertical_hints[MAX_WIDTH][MAX_HEIGHT/2 + 1];
} ActivePuzzle;

extern Collection g_puzzle_collection;
