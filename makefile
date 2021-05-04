.PHONY: all install_apt install_pacman build clean

all := install_apt install_pacman build

build:
	@echo "Buiding project..."
	@as --32 boot.S -o tmp/boot.o

	@gcc -m32 -c kernel.c -o tmp/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

	@ld -m elf_i386 -T linker.ld tmp/kernel.o tmp/boot.o -o tmp/Aurora.bin -nostdlib

	@grub-file --is-x86-multiboot tmp/Aurora.bin

	@mkdir -p isodir/boot/grub
	@cp tmp/Aurora.bin isodir/boot/Aurora.bin
	@cp grub.cfg isodir/boot/grub/grub.cfg
	@grub-mkrescue /usr/lib/grub/i386-pc -o output/Aurora.iso isodir

	@echo "Done! Executing....."

	@qemu-system-x86_64 -cdrom output/Aurora.iso

install_apt:
	@echo "Installing dipendences via apt...."
	@sudo apt-get install build-essential
	@sudo apt-get install xorriso
	@sudo apt-get install grub
	@sudo apt-get install grub-pc-bin
	@sudo apt-get install qemu-kvm qemu virt-manager virt-viewer libvirt-bin
	@echo "Done!"

install_pacman:
	@echo "Installing dipendences via pacman...."
	@sudo pacman -S xorriso
	@sudo pacman -S grub
	@sudo pacman -S qemu-kvm qemu virt-manager virt-viewer
	@echo "Done!"

clean:
	@echo "Cleaning 'tmp' directory...."
	@cd tmp
	@rm tmp/*
	@echo "Done!"
