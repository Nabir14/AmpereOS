# AmpereOS
AmpereOS is an open source operating system. 
(I am still learning Operation System development so code might be messy!)


![ampereos_icon](https://github.com/Nabir14/AmpereOS/blob/main/static/aos_icon.svg)
![ampereos_screenshot](https://github.com/Nabir14/AmpereOS/blob/main/static/aos_ss.png)

## OS Information:
- **Bootloader:** `Grub2` (Custom Bootloader In The Future!)
- **Kernel:** `AMPEREK` (Custom)
- **Main:** `Not Present`

## Build Instructions:
- **1. Install Build Dependencies:**
> Ubuntu/Debian:
```sh
sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libisl-dev nasm qemu-system grub-pc grub-efi grub2-common
```
> Arch Linux:
```sh
sudo pacman -Syu base-devel gmp libmpc mpfr nasm qemu grub mtools 
```
> Fedora:
```sh
sudo dnf install gcc gcc-c++ make bison flex libgmp-devel libmpc-devel libmpfr-devel texinfo libisl-devel nasm @virtualization gawk grub2-tools xorriso
```

- **2. Setup Cross-Compiler:**
```sh
chmod +x scripts/cross-compiler.sh
./scripts/cross-compiler.sh
```

- **3. Build && Run:**
```sh
make all
```
