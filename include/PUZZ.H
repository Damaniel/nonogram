#pragma once

#define MAX_PUZZ_WIDTH      12
#define MAX_PUZZ_HEIGHT     12

#define PUZZLE_BASE_PATH    "res/puzzles"

typedef struct {
    int collection;
    int level;
    int category;
    int width;
    int height;
} PuzzleMetadata;

typedef struct {
    PuzzleMetadata metadata;
    char num_row_hints[MAX_PUZZ_HEIGHT];
    char num_col_hints[MAX_PUZZ_WIDTH];
    char squares[MAX_PUZZ_WIDTH][MAX_PUZZ_HEIGHT];
    char row_hints[MAX_PUZZ_HEIGHT][MAX_PUZZ_WIDTH / 2];
    char col_hints[MAX_PUZZ_WIDTH][MAX_PUZZ_HEIGHT / 2];
} Puzzle;

// Given a puzzle, generate the row and column hints
extern void generate_hints(Puzzle *p);

// Load a puzzle at the given file path
extern void load_puzzle(char *filename, Puzzle *p);

// Get information about a particular puzzle
extern void get_puzzle_metadata(char *filename, PuzzleMetadata *md);
