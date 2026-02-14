/* * ARkalpyOS - Pop-up Memory Safety
 * [LANGUAGE: RUST]
 */

#[no_mangle]
pub extern "C" fn validate_popup_content(msg_ptr: *const u8, max_len: usize) -> bool {
    // Verifica se a mensagem cabe no buffer do Pop-up
    if max_len > 255 {
        return false; // Mensagem muito longa, bloqueada por segurança
    }
    true
}
