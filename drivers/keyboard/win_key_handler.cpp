/* ************************************************************
 * ARkalpyOS - Windows Key Interrupt Handler
 * Monitora o barramento do teclado para disparar o Menu Iniciar
 * ************************************************************
 */

#include "gui/start_menu.h"

#define KEY_WINDOWS 0x5B 

void process_keyboard_input(uint8_t scancode) {
    static bool is_extended = false;

    if (scancode == 0xE0) {
        is_extended = true;
        return;
    }

    if (is_extended && scancode == KEY_WINDOWS) {
        // Tecla Windows pressionada!
        toggle_start_menu(); 
    }

    is_extended = false;
}
