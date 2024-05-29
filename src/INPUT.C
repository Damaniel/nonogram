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
    switch(get_scan_code(key)) {
        case KEY_ESC:
            change_state(STATE_EXIT);
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