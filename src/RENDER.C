#include "includes.h"

void draw_game_background(void) {

}

void draw_game_buttons(void) {

}

void draw_game_status_overview(void) {

}

void draw_game_timer(void) {

}

void draw_game_board(void) {

}

void draw_game_puzzle(void) {

}

void draw_game_hints(void) {

}

// typedef struct {
//     char background_area;
//     char status_overview_area;
//     char timer;
//     char button_area;
//     char buttons;
//     char puzzle_area;
//     char puzzle;
//     char hints;
// } RenderComponents;

void select_all_game_components() {
    g_globals.render.background_area = 1;
    g_globals.render.status_overview_area = 1;
    g_globals.render.timer = 1;
    g_globals.render.button_area = 1;
    g_globals.render.buttons = 1;
    g_globals.render.puzzle_area = 1;
    g_globals.render.puzzle = 1;
    g_globals.render.hints = 1;
}

void render_horizontal_hint(int idx) {
    int j, cx;
    
    cx = g_globals.pa.pax1 - (g_globals.current_puzzle.num_row_hints[idx] * 2);

    if (g_globals.current_puzzle.num_row_hints[idx] == 0) {
        char_at(cx - 2, g_globals.pa.pay1 + idx + 1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK)); 
        char_at(cx - 1, g_globals.pa.pay1 + idx + 1, '0', make_attr(COLOR_WHITE, COLOR_BLACK));        
        return;
    }

    for(j=0; j<g_globals.current_puzzle.num_row_hints[idx]; j++) {
        char_at(cx, g_globals.pa.pay1 + idx + 1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));
        if (g_globals.current_puzzle.row_hints[idx][j] > 9) {
            char_at(cx + 1, g_globals.pa.pay1 + idx + 1, (g_globals.current_puzzle.row_hints[idx][j] - 10 + 48), make_attr(COLOR_MAGENTA, COLOR_BLACK));            
        }
        else {
            char_at(cx + 1, g_globals.pa.pay1 + idx + 1, g_globals.current_puzzle.row_hints[idx][j] + 48, make_attr(COLOR_WHITE, COLOR_BLACK));            
        }
        cx += 2;
    }
}

void render_vertical_hint(int idx) {
    int j, cy;

    cy = g_globals.pa.pay1 - g_globals.current_puzzle.num_col_hints[idx];

    if (g_globals.current_puzzle.num_col_hints[idx] == 0) {
        char_at(g_globals.pa.pax1 + 2 * idx + 1, cy - 1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(g_globals.pa.pax1 + 2 * idx + 2, cy - 1, '0', make_attr(COLOR_WHITE, COLOR_BLACK));
    }
    for(j=0;j<g_globals.current_puzzle.num_col_hints[idx];j++) {
        char_at(g_globals.pa.pax1 + 2 * idx + 1, cy, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));                
        if (g_globals.current_puzzle.col_hints[idx][j] > 9) {
            char_at(g_globals.pa.pax1 + 2 * idx + 2, cy, (g_globals.current_puzzle.col_hints[idx][j] - 10 + 48), make_attr(COLOR_MAGENTA, COLOR_BLACK));
        }
        else {
            char_at(g_globals.pa.pax1 + 2 * idx + 2, cy, (g_globals.current_puzzle.col_hints[idx][j] + 48), make_attr(COLOR_WHITE, COLOR_BLACK));
        }
        ++cy;
    }
}

void render_game_state(void) {
    int i, j;

    if(g_globals.render.background_area) {
        fill_box_at(0, 0, 79, 24, 177, make_attr(COLOR_LIGHT_BLUE, COLOR_BLUE));
        hline_at(TITLE_BAR_X, TITLE_BAR_Y, 80, ' ', make_attr(COLOR_WHITE, COLOR_CYAN));
        string_at(TITLE_TEXT_X, TITLE_TEXT_Y, "DamNonogram", make_attr(COLOR_WHITE, COLOR_CYAN));
        string_at(VERSION_TEXT_X, VERSION_TEXT_Y, VERSION, make_attr(COLOR_WHITE, COLOR_CYAN));
        g_globals.render.background_area = 0;
    }
    if(g_globals.render.status_overview_area) {
        // box
        box_at(STATUS_X1, STATUS_Y1, STATUS_X2, STATUS_Y2, BORDER_SINGLE, make_attr(COLOR_WHITE, COLOR_BLACK));
        fill_box_at(STATUS_X1+1, STATUS_Y1+1, STATUS_X2-1, STATUS_Y2-1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));
        // shading
        hline_at(STATUS_X1+1, STATUS_Y2+1, STATUS_X2-STATUS_X1+2, 177, make_attr(COLOR_BLUE, COLOR_BLACK));
        vline_at(STATUS_X2+1, STATUS_Y1+1, STATUS_Y2-STATUS_Y1+1, 177, make_attr(COLOR_BLUE, COLOR_BLACK));
        vline_at(STATUS_X2+2, STATUS_Y1+1, STATUS_Y2-STATUS_Y1+1, 177, make_attr(COLOR_BLUE, COLOR_BLACK));
        // text
        string_at(STATUS_LEVEL_TEXT_X, STATUS_LEVEL_TEXT_Y, "Level:", make_attr(COLOR_CYAN, COLOR_BLACK));
        string_at(STATUS_CATEGORY_TEXT_X, STATUS_CATEGORY_TEXT_Y, "Category:", make_attr(COLOR_CYAN, COLOR_BLACK));
        string_at(STATUS_TIME_TEXT_X, STATUS_TIME_TEXT_Y, "Elapsed time:", make_attr(COLOR_CYAN, COLOR_BLACK));
        g_globals.render.status_overview_area = 0;
    }
    if(g_globals.render.timer) {
        g_globals.render.timer = 0;
    }
    if(g_globals.render.button_area) {
        // box
        box_at(BUTTONS_AREA_X1, BUTTONS_AREA_Y1, BUTTONS_AREA_X2, BUTTONS_AREA_Y2, BORDER_SINGLE, make_attr(COLOR_WHITE, COLOR_BLACK));
        fill_box_at(BUTTONS_AREA_X1 + 1, BUTTONS_AREA_Y1 + 1, BUTTONS_AREA_X2 - 1, BUTTONS_AREA_Y2 - 1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));
        // border lines
        vline_at(BUTTON_V_DIVIDER_X, BUTTON_V_DIVIDER_Y, BUTTON_V_DIVIDER_H, 179, make_attr(COLOR_WHITE, COLOR_BLACK));
        hline_at(BUTTON_H1_DIVIDER_X, BUTTON_H1_DIVIDER_Y, BUTTON_H_DIVIDER_W, 196, make_attr(COLOR_WHITE, COLOR_BLACK));
        hline_at(BUTTON_H2_DIVIDER_X, BUTTON_H2_DIVIDER_Y, BUTTON_H_DIVIDER_W, 196, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_H1_DIVIDER_X, BUTTON_H1_DIVIDER_Y, 195, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_H1_DIVIDER_X + BUTTON_H_DIVIDER_W - 1, BUTTON_H1_DIVIDER_Y, 180, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_H2_DIVIDER_X, BUTTON_H2_DIVIDER_Y, 195, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_H2_DIVIDER_X + BUTTON_H_DIVIDER_W - 1, BUTTON_H2_DIVIDER_Y, 180, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_V_DIVIDER_X, BUTTON_V_DIVIDER_Y, 194, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_V_DIVIDER_X, BUTTON_V_DIVIDER_Y + BUTTON_V_DIVIDER_H - 1, 193, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_V_DIVIDER_X, BUTTON_H1_DIVIDER_Y, 197, make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_V_DIVIDER_X, BUTTON_H2_DIVIDER_Y, 197, make_attr(COLOR_WHITE, COLOR_BLACK));
        // shading
        hline_at(BUTTONS_AREA_X1+1, BUTTONS_AREA_Y2+1, BUTTONS_AREA_X2-BUTTONS_AREA_X1+2, 177, make_attr(COLOR_BLUE, COLOR_BLACK));
        vline_at(BUTTONS_AREA_X2+1, BUTTONS_AREA_Y1+1, BUTTONS_AREA_Y2-BUTTONS_AREA_Y1+1, 177, make_attr(COLOR_BLUE, COLOR_BLACK));
        vline_at(BUTTONS_AREA_X2+2, BUTTONS_AREA_Y1+1, BUTTONS_AREA_Y2-BUTTONS_AREA_Y1+1, 177, make_attr(COLOR_BLUE, COLOR_BLACK));        
        g_globals.render.button_area = 0;
    }
    if(g_globals.render.buttons) {
        // button text
        string_at(BUTTON_HELP_X, BUTTON_HELP_Y, " elp", make_attr(COLOR_WHITE, COLOR_BLACK));
        string_at(BUTTON_OPTS_X, BUTTON_OPTS_Y, " pts", make_attr(COLOR_WHITE, COLOR_BLACK));
        string_at(BUTTON_SAVE_X, BUTTON_SAVE_Y, " ave", make_attr(COLOR_WHITE, COLOR_BLACK)); 
        string_at(BUTTON_LOAD_X, BUTTON_LOAD_Y, " oad", make_attr(COLOR_WHITE, COLOR_BLACK));
        string_at(BUTTON_MARK_X, BUTTON_MARK_Y, " ark", make_attr(COLOR_WHITE, COLOR_BLACK));
        string_at(BUTTON_EXIT_X, BUTTON_EXIT_Y, " xit", make_attr(COLOR_WHITE, COLOR_BLACK));
        char_at(BUTTON_HELP_X, BUTTON_HELP_Y, 'H', make_attr(COLOR_MAGENTA, COLOR_BLACK));
        char_at(BUTTON_OPTS_X, BUTTON_OPTS_Y, 'O', make_attr(COLOR_MAGENTA, COLOR_BLACK));
        char_at(BUTTON_SAVE_X, BUTTON_SAVE_Y, 'S', make_attr(COLOR_MAGENTA, COLOR_BLACK));
        char_at(BUTTON_LOAD_X, BUTTON_LOAD_Y, 'L', make_attr(COLOR_MAGENTA, COLOR_BLACK));
        char_at(BUTTON_MARK_X, BUTTON_MARK_Y, 'M', make_attr(COLOR_MAGENTA, COLOR_BLACK));
        char_at(BUTTON_EXIT_X, BUTTON_EXIT_Y, 'E', make_attr(COLOR_MAGENTA, COLOR_BLACK));
        g_globals.render.buttons = 0;
    }
    if(g_globals.render.puzzle_area) {
        // Calculate where the puzzle area should go
        // Note that the X dimensions are all scaled by 2 because each 'square' is 2 characters wide in the x dimension

        //main puzzle area
        g_globals.pa.pax1 = PUZZLE_AREA_MIN_X;
        g_globals.pa.pay1 = PUZZLE_AREA_MIN_Y;
        g_globals.pa.pax2 = g_globals.pa.pax1 + (2 * g_globals.current_puzzle.metadata.width) + 1;
        g_globals.pa.pay2 = g_globals.pa.pay1 + g_globals.current_puzzle.metadata.height + 1;
        box_at(g_globals.pa.pax1, g_globals.pa.pay1, g_globals.pa.pax2, g_globals.pa.pay2, BORDER_DOUBLE, make_attr(COLOR_YELLOW, COLOR_BLACK));
        fill_box_at(g_globals.pa.pax1+1, g_globals.pa.pay1+1, g_globals.pa.pax2-1, g_globals.pa.pay2-1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));

        // horizontal hint area
        g_globals.pa.hxx1 = PUZZLE_AREA_MIN_X - (g_globals.current_puzzle.metadata.width ) - 1;
        g_globals.pa.hxy1 = PUZZLE_AREA_MIN_Y;
        g_globals.pa.hxx2 = PUZZLE_AREA_MIN_X;
        g_globals.pa.hxy2 = g_globals.pa.hxy1 + g_globals.current_puzzle.metadata.height + 1;
        box_at(g_globals.pa.hxx1, g_globals.pa.hxy1, g_globals.pa.hxx2, g_globals.pa.hxy2, BORDER_DOUBLE, make_attr(COLOR_YELLOW, COLOR_BLACK));
        fill_box_at(g_globals.pa.hxx1+1, g_globals.pa.hxy1+1, g_globals.pa.hxx2-1, g_globals.pa.hxy2-1, 177, make_attr(COLOR_DARK_GRAY, COLOR_BLACK));

        // vertical hint area
        g_globals.pa.hyx1 = PUZZLE_AREA_MIN_X;
        g_globals.pa.hyy1 = PUZZLE_AREA_MIN_Y - (g_globals.current_puzzle.metadata.height / 2) - 1;
        g_globals.pa.hyx2 = g_globals.pa.hyx1 + (2 * g_globals.current_puzzle.metadata.width) + 1;
        g_globals.pa.hyy2 = PUZZLE_AREA_MIN_Y;
        box_at(g_globals.pa.hyx1, g_globals.pa.hyy1, g_globals.pa.hyx2, g_globals.pa.hyy2, BORDER_DOUBLE, make_attr(COLOR_YELLOW, COLOR_BLACK));
        fill_box_at(g_globals.pa.hyx1+1, g_globals.pa.hyy1+1, g_globals.pa.hyx2-1, g_globals.pa.hyy2-1, 177, make_attr(COLOR_DARK_GRAY, COLOR_BLACK));

        // fix the corner symbols
        char_at(g_globals.pa.hyx2, g_globals.pa.hyy2, 185, make_attr(COLOR_YELLOW, COLOR_BLACK));
        char_at(g_globals.pa.hyx1, g_globals.pa.hyy2, 206, make_attr(COLOR_YELLOW, COLOR_BLACK));
        char_at(g_globals.pa.hxx2, g_globals.pa.hxy2, 202, make_attr(COLOR_YELLOW, COLOR_BLACK));

        // Shading
        g_globals.pa.hshade_x = g_globals.pa.hxx1 + 1;
        g_globals.pa.hshade_y = g_globals.pa.pay2 + 1;
        g_globals.pa.hshade_w = (g_globals.pa.pax2 - g_globals.pa.hshade_x) + 1;
        g_globals.pa.vshade_x = g_globals.pa.pax2 + 1;
        g_globals.pa.vshade_y = g_globals.pa.hyy1 + 1;
        g_globals.pa.vshade_h = (g_globals.pa.pay2 - g_globals.pa.vshade_y) + 2;
        hline_at(g_globals.pa.hshade_x, g_globals.pa.hshade_y, g_globals.pa.hshade_w, 177, make_attr(COLOR_BLUE, COLOR_BLACK));        
        vline_at(g_globals.pa.vshade_x, g_globals.pa.vshade_y, g_globals.pa.vshade_h, 177, make_attr(COLOR_BLUE, COLOR_BLACK));
        vline_at(g_globals.pa.vshade_x+1, g_globals.pa.vshade_y, g_globals.pa.vshade_h, 177, make_attr(COLOR_BLUE, COLOR_BLACK));

        g_globals.render.puzzle_area = 0;
    }
    if(g_globals.render.puzzle) {
        for (j=0;j<g_globals.current_puzzle.metadata.height; j++) {
            for (i=0; i<g_globals.current_puzzle.metadata.width; i++) {
                if(g_globals.current_puzzle.filled_status[i][j] == SQUARE_FILLED) {
                    char_at(g_globals.pa.pax1 + (2 * i) + 1, g_globals.pa.pay1 + j + 1, 219, make_attr(COLOR_WHITE, COLOR_BLACK));
                    char_at(g_globals.pa.pax1 + (2 * i) + 2, g_globals.pa.pay1 + j + 1, 219, make_attr(COLOR_WHITE, COLOR_BLACK));
                }
                else if(g_globals.current_puzzle.squares[i][j] == SQUARE_FLAGGED) {
                    char_at(g_globals.pa.pax1 + (2 * i) + 1, g_globals.pa.pay1 + j + 1, '>', make_attr(COLOR_WHITE, COLOR_BLACK));
                    char_at(g_globals.pa.pax1 + (2 * i) + 2, g_globals.pa.pay1 + j + 1, '<', make_attr(COLOR_WHITE, COLOR_BLACK));
                }
                else {
                    char_at(g_globals.pa.pax1 + (2 * i) + 1, g_globals.pa.pay1 + j + 1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));
                    char_at(g_globals.pa.pax1 + (2 * i) + 2, g_globals.pa.pay1 + j + 1, ' ', make_attr(COLOR_WHITE, COLOR_BLACK));
                }

            }
        }
        g_globals.render.puzzle = 0;
    }
    if(g_globals.render.hints) {
        // vertical hints
        for(i=0;i<g_globals.current_puzzle.metadata.width; i++) {
            render_vertical_hint(i);
        }
        // horizontal hints
        for(i=0;i<g_globals.current_puzzle.metadata.height; i++) {
            render_horizontal_hint(i);
        }
        g_globals.render.hints = 0;
    }
}

void render(void) {
    switch(g_globals.current_state) {
        case STATE_TITLE:
            break;
        case STATE_LOAD_MENU:
            break;
        case STATE_GAME:
            render_game_state();
            break;
        case STATE_SAVE:
            break;
        case STATE_LOAD:
            break;
        case STATE_COMPLETE:
            break;
    }
}