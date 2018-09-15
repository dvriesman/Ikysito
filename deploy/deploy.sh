#!/bin/sh

echo "drive c: file=\"`pwd`/core.img\" partition=1" > ~/.mtoolsrc
dd if=/dev/zero of=core.img count=088704 bs=512
mpartition -I c:
mpartition -c -t 88 -h 16 -s 63 c:
mformat c:
mmd c:/boot
mmd c:/boot/grub
mcopy ../grub/stage1 c:/boot/grub
mcopy ../grub/stage2 c:/boot/grub
mcopy ../grub/fat_stage1_5 c:/boot/grub
echo "(hd0) core.img" > bmap
printf "geometry (hd0) 88 16 63 \n root (hd0,0) \n setup (hd0)\n" | ../grub/grub --device-map=bmap  --batch
mcopy ../grub/menu.lst c:/boot/grub/
mcopy ../bin/kernel.bin c:/boot/grub/

