#pragma once
#include "includes.h"

// Determine if the puzzle is complete
extern int check_for_completion(void);

// Given a puzzle, generate the row and column hints
extern void generate_hints(Puzzle *p);

// Load a puzzle at the given file path
extern void load_puzzle(char *filename, Puzzle *p);

// Get information about a particular puzzle
extern void get_puzzle_metadata(char *filename, PuzzleMetadata *md);
