#!/bin/sh
for file in `ls *.c`
do
 newfile=`echo $file | sed 's/\.c/\.i/g'`
 echo $file
 echo $newfile
 mv $file $newfile
done
