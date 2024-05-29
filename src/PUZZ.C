#include "includes.h"
#include "puzz.h"

void load_puzzle(char *filename, Puzzle *p) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open puzzle file!\n");
        return;
    }

    fscanf(fp, "%d %d %d\n", &(p->metadata.collection), &(p->metadata.level), &(p->metadata.category));
    fscanf(fp, "%d %d\n", &(p->metadata.width), &(p->metadata.height));

    for(j=0;j < p->metadata.height; j++) {
        for(i = 0; i < p->metadata.width; i++) {
            p->squares[i][j] = fgetc(fp);
            p->filled_status[i][j] = SQUARE_EMPTY;
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
    
}

void generate_hints(Puzzle *p) {
    int line, hint_count, idx, finished, i;

    // to generate a hint (row described here, column is similar)
    // - set hint count to 0
    // - while not end of row
    //   - scan until 'X' is found, set count to 0
    //   - scan until '.' is found, increment 1 per character scanned
    //   - emit <count> as the next hint
    //   - increment hint count

    // generate the row hints
    for (line=0; line < p->metadata.height; line++ ) {
        hint_count = 0;
        idx = 0;
        finished = 0;
        p->num_row_hints[line] = 0;
        do {
            while(p->squares[idx][line] != 'X' && idx < p->metadata.width) {
                ++idx;
            }
            hint_count = 0;
            while(p->squares[idx][line] == 'X' && idx < p->metadata.width) {
                ++idx;
                ++hint_count;
            }
            if (hint_count > 0) {
                p->row_hints[line][p->num_row_hints[line]] = hint_count;
                ++(p->num_row_hints[line]);
            }
            if(idx >= p->metadata.width) {
                finished = 1;
            }
        } while(!finished);
        printf("row %d: %d hints - ", line, p->num_row_hints[line]);
        for (i=0;i<p->num_row_hints[line]; i++) {
            printf("%d ", p->row_hints[line][i]);
        }
        printf("\n");
    }

    // generate the column hints
    for (line=0; line < p->metadata.width; line++ ) {
        hint_count = 0;
        idx = 0;
        finished = 0;
        p->num_col_hints[line] = 0;
        do {
            while(p->squares[line][idx] != 'X' && idx < p->metadata.height) {
                ++idx;
            }
            hint_count = 0;
            while(p->squares[line][idx] == 'X' && idx < p->metadata.height) {
                ++idx;
                ++hint_count;
            }
            if(hint_count > 0) {
                p->col_hints[line][p->num_col_hints[line]] = hint_count;
                ++(p->num_col_hints[line]);
            }
            if(idx >= p->metadata.height) {
                finished = 1;
            }
        } while(!finished);
        printf("col %d: %d hints - ", line, p->num_col_hints[line]);
        for (i=0;i<p->num_col_hints[line]; i++) {
            printf("%d ", p->col_hints[line][i]);
        }
        printf("\n");
    }
}

void get_puzzle_metadata(char *filename, PuzzleMetadata *md) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open puzzle file!\n");
        return;
    }

    fscanf(fp, "%d %d %d\n", &(md->collection), &(md->level), &(md->category));
    fscanf(fp, "%d %d\n", &(md->width), &(md->height));

    fclose(fp);
}