#Write a Program to find the greatest of three numbers
#!bin/bash

echo "enter n1 "
read n1
echo "enter n2 "
read n2
echo "enter n3 "
read n3

if (($n1 > $n2 && $n1 > $n3)) 
then
    echo "$n1 is greater"
elif (($n2 > $n1 && $n2 > $n3)) 
then
    echo "$n2 is greater"
else
    echo "$n3 is greater"
fi
