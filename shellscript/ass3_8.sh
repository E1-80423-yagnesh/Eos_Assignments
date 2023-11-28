#!/bin/bash

#Write a program to print the table of a given number.

echo "enter n :"
read n
i=1
until (( $i > 10 ))
do 
    res=`expr $n \* $i`
	echo "Table of $n * $i =$res "
    i=`expr $i + 1`  
done

