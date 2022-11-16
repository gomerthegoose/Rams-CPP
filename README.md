# RheolauArmsManagmentSystem

- setup used for compiling -

install msys2

in mingw64 Run:
  - pacman -S mingw-w64-x86_64-gtk4
  - pacman -S mingw-w64-x86_64-gtkmm4
  - pacman -S --needed base-devel mingw-w64-x86_64-toolchain
  you need:
    -gdb
    -gcc
  
add "C:\msys64\mingw64\bin" to user variables

run ./make.bash in mingw64 terminal

if these steps dont make it compile, cry
