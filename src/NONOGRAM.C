#include "includes.h"

Puzzle g_puzzle;
GameGlobals g_globals;
unsigned volatile long g_clock_ticks;
char g_timer_overflow;

void (__interrupt __far *old_isr)();

void __interrupt __far timer_func(void) {
    g_clock_ticks++;
}

void init_globals(void) {
    g_globals.current_state = STATE_TITLE;
    g_globals.previous_state = STATE_TITLE;
    g_globals.elapsed_seconds = 0;
    g_globals.exit_game = 0;
    g_globals.start_ticks = 0;
    g_globals.cursor_x = 0;
    g_globals.cursor_y = 0;
    g_globals.old_cursor_x = 0;
    g_globals.old_cursor_y = 0;
}

void change_state(GameState new_state) {
    g_globals.previous_state = g_globals.current_state;
    g_globals.current_state = new_state;

    switch (g_globals.current_state) {
        case STATE_TITLE:
            break;
        case STATE_LOAD_MENU:
            break;
        case STATE_GAME:
            select_all_game_components();
            break;
        case STATE_SAVE:
            break;
        case STATE_LOAD:
            break;
        case STATE_COMPLETE:
            break;
        case STATE_EXIT:
            g_globals.exit_game = 1;
            break;
    }
}

void process_timing(void) {
    long elapsed_ticks = g_clock_ticks - g_globals.start_ticks;

    if (elapsed_ticks >= 19 && g_timer_overflow >= 5) {
        g_globals.elapsed_seconds++;
        g_timer_overflow = 0;
        g_globals.start_ticks = g_clock_ticks;
    }
    else if (elapsed_ticks >= 18) {
        g_globals.elapsed_seconds++;
        g_timer_overflow++;
        g_globals.start_ticks = g_clock_ticks;
    }
}

void game_init(void) {
    // Reset the tick counter
    g_clock_ticks = 0;
    // Prep our pre-written timer interrupt function
    old_isr = _dos_getvect(0x1C);
    _dos_setvect(0x1C, timer_func);

    // Set the screen
    set_text_mode(MODE_80X25);
    clear_screen();
    hide_cursor();
}

void game_cleanup(void) {
    // restore the timer handler
    _dos_setvect(0x1C, old_isr);

    // Reset the screen
    set_text_mode(MODE_80X25);
    clear_screen();
    show_cursor();
}

int main(void) {
    unsigned short key;
    int i, j;

    game_init();
    init_globals();

    load_puzzle("res/puzzles/01/01.puz", &(g_globals.current_puzzle));
    generate_hints(&(g_globals.current_puzzle));
    change_state(STATE_GAME);

    while(!g_globals.exit_game) {
        key = get_input_key();
        if (key) {
            process_input(key);
        }
        process_timing();
        render();
        delay(2);
    }

    game_cleanup();

    return 0;
}