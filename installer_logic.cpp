void handle_installer_input() {
    uint8_t key = get_last_key();

    if (key == KEY_UP) {
        current_selection--;
        if (current_selection < 0) current_selection = 3;
    }
    if (key == KEY_DOWN) {
        current_selection++;
        if (current_selection > 3) current_selection = 0;
    }

    if (key == KEY_ENTER) {
        if (current_selection == 3) {
            execute_final_install();
        } else {
            // Se der enter nas outras opções, ele "gira" os países
            // No futuro você pode abrir um menu lateral aqui
        }
    }
}

void execute_final_install() {
    clear_screen(0x00);
    draw_text(20, 10, "GRAVANDO CONFIGURACOES NO SETOR DE BOOT...", 0x0A);
    
    // Chama o Rust para salvar o arquivo de config real
    save_system_config(countries[current_selection], keyboards[current_selection]);
    
    // Inicia a barra de progresso real
    for(int i=0; i<=100; i+=10) {
        draw_progress_bar(i);
        sleep(500);
    }
    
    draw_text(20, 15, "INSTALACAO CONCLUIDA! REINICIANDO...", 0x0B);
    reboot();
}
