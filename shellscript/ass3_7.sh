#!/bin/bash
#Write a Program to find whether a given number is positive or negative

#!/bin/bash

echo "Enter a number: "
read n

if(($n > 0))
then 
	echo "$n is postive"
else
	echo "$n is negative"
fi
