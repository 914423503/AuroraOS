as --32 boot.S -o tmp/boot.o

gcc -m32 -c kernel.c -o tmp/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

ld -m elf_i386 -T linker.ld tmp/kernel.o tmp/boot.o -o tmp/Aurora.bin -nostdlib

grub-file --is-x86-multiboot tmp/Aurora.bin

mkdir -p isodir/boot/grub
cp tmp/Aurora.bin isodir/boot/Aurora.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o output/Aurora.iso isodir

qemu-system-x86_64 -cdrom output/Aurora.iso
