#!/bin/bash
#Write a program to find given number of terms in the Fibonacci series.
echo -e -n "Enter any number : "
read n

n1=0
n2=1
i=2

while [ $i -le $n ]
do
i=`expr $i + 1`
n3=`expr $n1 + $n2`
echo -n -e "$n3 "
n1=$n2
n2=$n3
done

