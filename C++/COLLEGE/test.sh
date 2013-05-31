#!/bin/sh
x=$((100000))
y=$((0))
while [ $x -ne $y ]
do
	z=`time ./a.out 100000 4`
	echo "HELLO" + echo $z | grep real | cut -d " " -f 2 | cut -d "m" -f 2 | tr -s "s" " "
	x=$((x-1))
done
