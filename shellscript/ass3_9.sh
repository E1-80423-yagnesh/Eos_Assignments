#!/bin/bash
#Write a program to find the factorial of given number.
echo "enter n : "
read n

res=1
while [ $n -gt 0 ]
do
	res=`expr $res \* $n`
	n=`expr $n - 1`
done
echo "factorial of number  is $res"
