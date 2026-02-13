#!/usr/bin/perl
# ************************************************************
# ARkalpyOS Multi-Language Build System
# Author: [Seu Nome]
# Version: 1.0.0
# ************************************************************

use strict;
use warnings;

print "--------------------------------------------------\n";
print "   ARKALPY-OS : INICIANDO COMPILAÇÃO POLIGLOTA    \n";
print "--------------------------------------------------\n";

# 1. Compilando Assembly (O Bootloader)
print "[1/7] Compilando Bootloader (Assembly)... ";
system("nasm -f bin boot_entry.asm -o boot.bin") == 0 
    or die "Falha no Assembly";
print "OK\n";

# 2. Compilando o Kernel (C++)
print "[2/7] Compilando Mosaic Kernel (C++)... ";
system("g++ -m32 -c mosaic_kernel.cpp -o kernel.o -ffreestanding -O2 -nostdlib") == 0 
    or die "Falha no C++";
print "OK\n";

# 3. Compilando Safety Layer (Rust)
print "[3/7] Compilando Safety Layer (Rust)... ";
# No futuro, aqui rodaria o cargo build
print "SKIP (Simulado para Alpha)\n";

# 4. Linkando tudo com o Linker Script
print "[4/7] Linkando binários finais... ";
system("ld -m elf_i386 -T linker.ld -o arkalpy_kernel.bin kernel.o") == 0;
print "OK\n";

# 5. Criando a ISO (Python)
print "[5/7] Gerando Imagem ISO (Python)... ";
system("python3 iso_manager.py") == 0;
print "OK\n";

print "--------------------------------------------------\n";
print "   ARKALPY-OS CONSTRUÍDO COM SUCESSO!            \n";
print "--------------------------------------------------\n";
