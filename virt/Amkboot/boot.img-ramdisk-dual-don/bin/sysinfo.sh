#!/bin/bash

echo "Mount & system info search"
echo $1 > /dev/ttyprintk
sleep 5
/bin/busybox mount -t ext4 /dev/mmcblk0p$1 /system
[ "`/bin/busybox grep -i ro.build.version.release=4.3 /system/build.prop`" ] && echo "1" > /system/etc/JB43
[ "`/bin/busybox grep -i ro.build.version.release=4.2 /system/build.prop`" ] && echo "1" > /system/etc/JB42
[ "`/bin/busybox grep -i ro.miui /system/build.prop`" ] && echo "1" > /system/etc/MIUI

if [ -f /system/etc/JB43 ]; then
	/bin/busybox cp -a /res/misc/jb43/* /
elif [ -f /system/etc/JB42 ]; then
	if [ -f /system/etc/MIUI ]; then
	/bin/busybox cp -a /res/misc/miui/* /
	else
	/bin/busybox cp -a /res/misc/jb42/* /
	fi
else
	/bin/sh
fi
rm /system/etc/JB43
rm /system/etc/JB42
umount /system

