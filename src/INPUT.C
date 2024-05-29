#include "includes.h"

unsigned short get_input_key (void) {
    unsigned short key_state, shift_state, output;
    if (!_bios_keybrd(_KEYBRD_READY)) {
        return 0;
    }
    key_state = _bios_keybrd(_KEYBRD_READ);
    shift_state = _bios_keybrd(_KEYBRD_SHIFTSTATUS);

    output = shift_state << 8;
    output |= (key_state >> 8);

    return output;
}

_inline unsigned char get_scan_code(short key) {
    return (key & 0xFF);
}

_inline unsigned char get_shift_state(short key) {
    return (key >> 8);
}

void process_title_input(short key) {

}

void process_load_menu_input(short key) {

}

void process_complete_input(short key) {

}

void process_game_input(short key) {
    int complete;

    switch(get_scan_code(key)) {
        case KEY_ESC:
            change_state(STATE_EXIT);
            break;
        case KEY_SPACE:
            if (g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] == SQUARE_FILLED) {
                g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] = SQUARE_EMPTY;
                --g_globals.current_puzzle_squares;
            }
            else {
                g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] = SQUARE_FILLED;
                ++g_globals.current_puzzle_squares;
                // In the case where the number of marked squares equals the total number in the puzzle, then
                // check to see if they're in the correct places.
            }
            if(g_globals.current_puzzle_squares == g_globals.total_puzzle_squares) {
                complete = check_for_completion();
                if (complete) {
                    change_state(STATE_EXIT);
                }
            }
            g_globals.render.puzzle = 1;
            g_globals.render.puzzle_cursor = 1;
            break;
        case KEY_X:
            if (g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] == SQUARE_FILLED) {
                g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] = SQUARE_FLAGGED;
                --g_globals.current_puzzle_squares;
            } 
            else if (g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] == SQUARE_EMPTY) {
                g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] = SQUARE_FLAGGED;
            } 
            else {
                g_globals.current_puzzle.filled_status[g_globals.cursor_x][g_globals.cursor_y] = SQUARE_EMPTY;               
            }
            g_globals.render.puzzle = 1;
            g_globals.render.puzzle_cursor = 1;
            break;
        case KEY_UP:
            g_globals.old_cursor_y = g_globals.cursor_y;
            g_globals.cursor_y = g_globals.cursor_y - 1;
            if(g_globals.cursor_y < 0) {
                g_globals.cursor_y = 0;
            }
            g_globals.render.puzzle = 1;
            g_globals.render.puzzle_cursor = 1;
            break;
        case KEY_DOWN:
            g_globals.old_cursor_y = g_globals.cursor_y;
            g_globals.cursor_y = g_globals.cursor_y + 1;
            if (g_globals.cursor_y >= g_globals.current_puzzle.metadata.height) {
                g_globals.cursor_y = g_globals.current_puzzle.metadata.height - 1;
            }
            g_globals.render.puzzle = 1;
            g_globals.render.puzzle_cursor = 1;
            break;
        case KEY_LEFT:
            g_globals.old_cursor_x = g_globals.cursor_x;
            g_globals.cursor_x = g_globals.cursor_x - 1;
            if(g_globals.cursor_x < 0) {
                g_globals.cursor_x = 0;
            }
            g_globals.render.puzzle = 1;
            g_globals.render.puzzle_cursor = 1;
            break;
        case KEY_RIGHT:
            g_globals.old_cursor_x = g_globals.cursor_x;
            g_globals.cursor_x = g_globals.cursor_x + 1;
            if (g_globals.cursor_x >= g_globals.current_puzzle.metadata.width) {
                g_globals.cursor_x = g_globals.current_puzzle.metadata.width - 1;
            }
            g_globals.render.puzzle = 1;
            g_globals.render.puzzle_cursor = 1;
            break;           
    }
}

void process_input(short key) {
    switch(g_globals.current_state) {
        case STATE_TITLE:
            break;
        case STATE_LOAD_MENU:
            break;
        case STATE_GAME:
            process_game_input(key);
            break;
        case STATE_COMPLETE:
            break;
    }
}