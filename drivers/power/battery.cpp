/* * ARkalpyOS - Battery Monitor (ACPI Interface)
 * Lê os registros de carga e status da bateria do notebook
 */

#include <stdint.h>

struct BatteryStatus {
    uint32_t percentage;
    bool is_charging;
};

BatteryStatus get_hardware_battery() {
    BatteryStatus status;
    
    // No hardware real, leríamos do EC (Embedded Controller)
    // Aqui simulamos a porta de leitura ACPI 0x62 e 0x66
    uint8_t raw_data = inb(0x62); 
    
    status.percentage = (raw_data > 100) ? 100 : raw_data;
    status.is_charging = (inb(0x66) & 0x01);
    
    return status;
}
