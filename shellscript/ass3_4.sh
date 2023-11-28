#!bin/bash
#Write a shell script to determine whether a given number is prime or not

echo "enter no. :"
read n

i=2
flag=0
if(($n % $i==0))
then
	echo "number is not prime"
	flag=1
	
else
	echo "number is prime"
	flag=0
fi
