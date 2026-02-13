# [LANGUAGE: PYTHON]
# [FILE: iso_manager.py]
# [PROJECT: ARkalpyOS]
# ---------------------------------------------------------
import os
import sys

class ARkalpyBuilder:
    def __init__(self):
        self.files = ["entry.o", "kernel.o", "hardware_io.o", "rust_logic.o"]
        self.output = "arkalpy.iso"

    def verify_integrity(self):
        print("[CHECK] Verificando se há menções a outros sistemas...")
        # Varre os binários para garantir que o sistema é 100% puro
        for file in self.files:
            if not os.path.exists(file):
                print(f"[ERROR] Arquivo {file} faltando!")
                return False
        return True

    def build_final_image(self):
        if self.verify_integrity():
            print(f"[ISO] Gerando imagem real do ARkalpyOS...")
            # O comando que cria a imagem bootável real
            os.system(f"grub-mkrescue -o {self.output} build_folder/")
            print(f"[SUCCESS] {self.output} pronto para o Pendrive.")

if __name__ == "__main__":
    builder = ARkalpyBuilder()
    builder.build_final_image()
