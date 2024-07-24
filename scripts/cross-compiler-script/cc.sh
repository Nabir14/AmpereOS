export CC=/usr/bin/gcc 
export LD=/usr/bin/gcc 
export PREFIX="/usr/local/i386elfgcc" 
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"

#mkdir /tmp/src 
#cd /tmp/src 
#curl -O https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.gz 
#tar xf binutils-2.38.tar.gz
#mkdir binutils-build
#cd binutils-build
#../binutils-2.38/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
#make all install 2>&1 | tee make.log

cd /tmp/src 
curl -O https://ftp.gnu.org/gnu/gcc/gcc-11.4.0/gcc-11.4.0.tar.gz 
tar xf gcc-11.4.0.tar.gz 
mkdir gcc-build
cd gcc-build
../gcc-11.4.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c --without-headers
make all-gcc 
make all-target-libgcc 
make install-gcc
make install-target-libgcc
