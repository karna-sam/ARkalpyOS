/* ************************************************************
 * ARkalpyOS - Keyboard-Driven Installer (No Mouse)
 * [LANGUAGE: C++]
 * ************************************************************
 */

#include "keyboard_driver.h"

int current_selection = 0; // Controla qual opção está focada
bool setup_finished = false;

// Listas de Configuração
const char* countries[] = {"Brasil", "USA", "Portugal", "Japan", "Germany"};
const char* keyboards[] = {"ABNT2", "US-International", "PT-PT", "JIS", "QWERTZ"};
const char* timezones[] = {"UTC-3", "UTC-5", "UTC+0", "UTC+9", "UTC+1"};

void draw_setup_screen() {
    clear_screen(0x1B); // Fundo Azul Instalador
    
    // Título
    draw_box(5, 2, 75, 22, 0x0F, 0x00, '#');
    draw_text(30, 4, "ARkalpyOS SYSTEM SETUP", 0x01);
    draw_text(10, 6, "Use as setas [UP/DOWN] e [ENTER] para configurar", 0x08);

    // Opção 1: País/Língua
    draw_option(15, 9, "Pais/Lingua:", countries[current_selection % 5], (current_selection == 0));

    // Opção 2: Teclado
    draw_option(15, 11, "Layout Teclado:", keyboards[current_selection % 5], (current_selection == 1));

    // Opção 3: Horário
    draw_option(15, 13, "Fuso Horario:", timezones[current_selection % 5], (current_selection == 2));

    // BOTÃO FINAL: COMPLETE
    if (current_selection == 3) {
        draw_fill_rect(30, 18, 50, 20, 0x0A); // Verde quando selecionado
        draw_text(34, 19, "> [ COMPLETE ] <", 0x0F);
    } else {
        draw_fill_rect(30, 18, 50, 20, 0x07); // Cinza normal
        draw_text(35, 19, "  COMPLETE  ", 0x0F);
    }
}

// Função que desenha a opção e destaca se o foco estiver nela
void draw_option(int x, int y, const char* label, const char* value, bool is_focused) {
    if (is_focused) {
        draw_text(x - 2, y, "> ", 0x0E); // Seta amarela de foco
        draw_text(x, y, label, 0x0E);
        draw_text(x + 20, y, value, 0x0F);
    } else {
        draw_text(x, y, label, 0x07);
        draw_text(x + 20, y, value, 0x08);
    }
}
