# Ikysito OS

I found this old code in an old CD-ROM, I think it's from my experiments 
with OS when I was yong, a long time ago.

It's just a simple Kernel that boots with old Grub and show a simple command prompt.

## Prequirements
* nasm
* gcc
* mtools
* qemu


## To compile
```
cd src
make
```
A file kernel.bin will be generate in ./bin directory


## To create a kernel image
```
cd deploy
./deploy.sh
```
A file core.img will be generate in ./deploy directory


## To test

Inside deploy directory
```
qemu-system-i386 -hda core.img
```

