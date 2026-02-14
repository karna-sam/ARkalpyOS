/* ************************************************************
 * ARkalpyOS - Unified Graphical Calculator
 * Language: C++ (Mosaic System)
 * Features: Mouse Support, Grid Detection, Math Engine Hook
 * ************************************************************
 */

#include "mosaic_kernel.h"
#include "drivers/mouse_driver.h"

class Calculator {
private:
    char display_buffer[16] = "0";
    double current_value = 0;
    double last_value = 0;
    char pending_op = ' ';
    
    // Definição da área da janela da calculadora
    const int start_x = 25;
    const int start_y = 5;
    const int width = 30;
    const int height = 15;

    // Estrutura para os botões
    struct Button {
        const char* label;
        int x, y, w, h;
    };

public:
    void render() {
        // 1. Desenha o corpo da calculadora
        draw_fill_rect(start_x, start_y, start_x + width, start_y + height, 0x07); // Cinza
        draw_rect(start_x, start_y, start_x + width, start_y + height, 0x00);      // Borda
        
        // Titulo da Janela
        draw_fill_rect(start_x, start_y, start_x + width, start_y + 1, 0x01);
        draw_text(start_x + 1, start_y, "ARKALPY CALC", 0x0F);

        // 2. Desenha o Display (Onde os números aparecem)
        draw_fill_rect(start_x + 2, start_y + 2, start_x + width - 2, start_y + 4, 0x0F);
        draw_text(start_x + width - 4 - str_len(display_buffer), start_y + 3, display_buffer, 0x00);

        // 3. Desenha a Grade de Botões (4x4)
        const char* layout[4][4] = {
            {"7", "8", "9", "/"},
            {"4", "5", "6", "*"},
            {"1", "2", "3", "-"},
            {"C", "0", "=", "+"}
        };

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int bx = start_x + 2 + (j * 7);
                int by = start_y + 6 + (i * 2);
                
                // Desenha o botão
                draw_fill_rect(bx, by, bx + 5, by + 1, 0x08);
                draw_text(bx + 2, by, layout[i][j], 0x0F);
            }
        }
    }

    // O coração do sistema: Checa onde o mouse clicou
    void process_click(int mx, int my) {
        const char* layout[4][4] = {
            {"7", "8", "9", "/"},
            {"4", "5", "6", "*"},
            {"1", "2", "3", "-"},
            {"C", "0", "=", "+"}
        };

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int bx = start_x + 2 + (j * 7);
                int by = start_y + 6 + (i * 2);
                int bw = 5;
                int bh = 1;

                // SEU CÓDIGO DE CLICK AQUI:
                // Se o bico da seta (mx, my) estiver dentro deste botão específico
                if (mx >= bx && mx <= bx + bw && my >= by && my <= by + bh) {
                    on_button_pressed(layout[i][j]);
                    trigger_click_animation(bx, by); // Feedback visual
                    return;
                }
            }
        }
    }

    void on_button_pressed(const char* label) {
        if (label[0] >= '0' && label[0] <= '9') {
            if (str_compare(display_buffer, "0")) {
                copy_string(display_buffer, label);
            } else {
                append_string(display_buffer, label);
            }
        } else if (label[0] == 'C') {
            copy_string(display_buffer, "0");
            current_value = 0;
            pending_op = ' ';
        } else if (label[0] == '=') {
            execute_math();
        } else {
            // Operadores (+, -, *, /)
            last_value = string_to_double(display_buffer);
            pending_op = label[0];
            copy_string(display_buffer, "0");
        }
        render(); // Redesenha com o novo valor no display
    }

    void execute_math() {
        current_value = string_to_double(display_buffer);
        double result = 0;

        // Aqui chama a lógica que antes estava no C# ou faz direto no FPU (Rust)
        if (pending_op == '+') result = last_value + current_value;
        if (pending_op == '-') result = last_value - current_value;
        if (pending_op == '*') result = last_value * current_value;
        if (pending_op == '/') result = last_value / current_value;

        double_to_string(result, display_buffer);
    }
};
