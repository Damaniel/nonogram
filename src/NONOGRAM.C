#include "puzz.h"
#include <stdio.h>

Puzzle g_puzzle;

int main(void) {
    int i, j;

    printf("%d\n",sizeof(Puzzle));
    printf("%d\n", sizeof(PuzzleMetadata));

    load_puzzle("res/puzzles/01/02.puz", &g_puzzle);

    printf("Puzzle width = %d, puzzle height = %d\n", g_puzzle.metadata.width, g_puzzle.metadata.height);
    for(j=0;j<g_puzzle.metadata.height;j++) {
        for(i=0;i<g_puzzle.metadata.width;i++) {
            printf("%c", g_puzzle.squares[i][j]);
        }
        printf("\n");
    }

    generate_hints(&(g_puzzle));

    return 0;
}