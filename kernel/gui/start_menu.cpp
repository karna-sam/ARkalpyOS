/* ************************************************************
 * ARkalpyOS - Start Menu System (Apps & Search)
 * Renderiza a lista de aplicativos sobre o Mosaico
 * ************************************************************
 */

bool start_menu_open = false;

void toggle_start_menu() {
    start_menu_open = !start_menu_open;
    if (start_menu_open) {
        render_start_menu();
    } else {
        refresh_mosaico(); // Limpa o menu da tela
    }
}

void render_start_menu() {
    // 1. Janela do Menu (Canto inferior esquerdo)
    // Cores: 0x08 (Cinza Escuro), 0x0F (Branco)
    draw_fill_rect(1, 10, 25, 23, 0x08); 
    draw_rect(1, 10, 25, 23, 0x01); // Borda Azul

    // 2. Cabeçalho do Usuário
    draw_text(3, 11, "USER: ARkalpy", 0x0E); // Amarelo
    draw_text(2, 12, "---------------------", 0x07);

    // 3. Lista de Apps Nativos
    draw_text(4, 14, "[G] Google Crome", 0x0F);
    draw_text(4, 15, "[F] Files Explorer", 0x0F);
    draw_text(4, 16, "[T] Terminal Shell", 0x0F);
    
    // 4. Seção de Apps .EXE (Detectados pelo PE Loader)
    draw_text(2, 18, "--- INSTALLED EXE ---", 0x0B);
    draw_text(4, 19, "> Calculator.exe", 0x0A);
    draw_text(4, 20, "> Notepad.exe", 0x0A);

    // 5. Opções de Energia
    draw_text(2, 22, "[P] Power Off", 0x0C);
}
