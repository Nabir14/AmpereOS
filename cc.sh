sudo apt install build-essential
sudo apt install bison
sudo apt install flex
sudo apt install libgmp3-dev
sudo apt install libmpc-dev
sudo apt install libmpfr-dev
sudo apt install texinfo
sudo apt install libisl-dev

export CC=/usr/bin/gcc 
export LD=/usr/bin/gcc 
export PREFIX="/usr/local/i386elfgcc"
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"

#mkdir /tmp/src 
cd pkgs
#curl -O https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.gz 
tar xf binutils-2.40.tar.gz
mkdir binutils-build
cd binutils-build
../binutils-2.40/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
make all install 2>&1 | tee make.log

cd ~/projects/cc/pkgs
#curl -O https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.gz 
tar xf gcc-12.2.0.tar.gz 
mkdir gcc-build
cd gcc-build
../gcc-12.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c --without-headers
make all-gcc 
make all-target-libgcc 
make install-gcc
make install-target-libgcc
