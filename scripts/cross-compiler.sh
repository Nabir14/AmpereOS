export PREFIX=$HOME/code/AmpereOS/cross-compiler
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"

mkdir ../cross-compiler
cd ../cross-compiler
curl -O https://ftp.gnu.org/gnu/binutils/binutils-2.45.tar.gz
tar xf binutils-2.45.tar.gz
rm -rf binutils-2.45.tar.gz
mkdir build-binutils
cd build-binutils
../binutils-2.45/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
make all install 2>&1 | tee make.log

cd ..
curl -O https://ftp.gnu.org/gnu/gcc/gcc-15.2.0/gcc-15.2.0.tar.gz
tar xf gcc-15.2.0.tar.gz
rm -rf gcc-15.2.0.tar.gz
mkdir build-gcc
cd build-gcc
../gcc-15.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c --without-headers

imake all-gcc 
make all-target-libgcc 
make install-gcc 
make install-target-libgcc
