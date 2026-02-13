#!/usr/bin/perl
# [LANGUAGE: PERL]
# [FILE: build_logic.pl]
# ---------------------------------------------------------
use strict;
use warnings;

print "=" x 40, "\n";
print "   ARKALPY OS BUILD SYSTEM   \n";
print "=" x 40, "\n";

my @steps = (
    "nasm -f elf32 boot_entry.asm -o entry.o",
    "g++ -m32 -c mosaic_kernel.cpp -o kernel.o -ffreestanding -O2 -nostdlib",
    "rustc --emit=obj --target=i686-unknown-linux-gnu safety_manager.rs -o rust.o",
    "ld -m elf_i386 -T link.ld -o arkalpyos.bin entry.o kernel.o rust.o"
);

foreach my $cmd (@steps) {
    print "Executando: $cmd...\n";
    my $res = system($cmd);
    if ($res != 0) {
        die "❌ ERRO CRÍTICO no passo: $cmd\n";
    }
}

print "\n✅ ARkalpyOS construído com sucesso!\n";
