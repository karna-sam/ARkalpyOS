// [LANGUAGE: C++]
// [FILE: mosaic_kernel.cpp]
// [PROJECT: ARkalpyOS]
// ---------------------------------------------------------
#define VIDEO_MEM (unsigned short*)0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Definição de cores (Paleta Retrô)
enum Color {
    BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, 
    MAGENTA = 5, BROWN = 6, LGRAY = 7, DGRAY = 8, WHITE = 15
};

void draw_rect(int x1, int y1, int x2, int y2, Color bg, Color fg, char border_char) {
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            int pos = y * SCREEN_WIDTH + x;
            if (y == y1 || y == y2 || x == x1 || x == x2)
                VIDEO_MEM[pos] = ((bg << 4 | fg) << 8) | border_char;
            else
                VIDEO_MEM[pos] = ((bg << 4 | fg) << 8) | ' ';
        }
    }
}

void print_at(int x, int y, const char* str, Color bg, Color fg) {
    int pos = y * SCREEN_WIDTH + x;
    while (*str) {
        VIDEO_MEM[pos++] = ((bg << 4 | fg) << 8) | *str++;
    }
}

extern "C" void kernel_main() {
    // Limpa a tela com fundo sólido
    draw_rect(0, 0, 79, 24, BLUE, WHITE, ' ');

    // --- BLOCO 1: GOOGLE ENGINE ---
    draw_rect(2, 1, 25, 6, LGRAY, BLACK, 219);
    print_at(8, 3, "G O O G L E", LGRAY, RED);
    print_at(4, 5, "[ Buscar no OS ]", LGRAY, DGRAY);

    // --- BLOCO 2: CALCULADORA ---
    draw_rect(27, 1, 52, 6, LGRAY, BLACK, 219);
    print_at(32, 2, "CALCULADORA", LGRAY, BLACK);
    print_at(29, 4, "7 8 9 /", LGRAY, BLUE);
    print_at(29, 5, "4 5 6 *", LGRAY, BLUE);

    // --- BLOCO 3: AJUSTES ---
    draw_rect(54, 1, 77, 6, LGRAY, BLACK, 219);
    print_at(59, 3, "AJUSTES", LGRAY, BLACK);

    // --- BLOCO 4: O TERMINAL (Diferente do Kernel) ---
    draw_rect(2, 8, 77, 20, BLACK, GREEN, '#');
    print_at(4, 9, "ARKALPY-SHELL v1.0", BLACK, GREEN);
    print_at(4, 11, "root@arkalpy:~# sys_info", BLACK, WHITE);
    print_at(4, 12, "Kernel: 0.0.1-Alpha | Mode: Mosaic", BLACK, LGRAY);

    // --- BOTÃO DE LIMPEZA DE DISCO ---
    draw_rect(54, 21, 77, 23, RED, WHITE, '!');
    print_at(56, 22, "LIMPAR OUTROS SO", RED, WHITE);

    while(1); // Mantém o sistema vivo
}

void run_terminal() {
    char* prompt = "arkalpy@user:# ";
    unsigned char color_terminal = 0x0A; // Verde Matrix (diferente do resto)
    
}
