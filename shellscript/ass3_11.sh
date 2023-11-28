#!/bin/bash
#Write a program to calculate gross salary if the DA is 40%, HRA is 20% of basic salary.
#Accept basic salary form user and display gross salary
echo -n "Enter the basic salary : "
read basicSal

da=0.2
hra=0.4

hra=$(echo "$basicSal*$hra"|bc)
da=$(echo "$basicSal*$da"|bc)
grossSal=$(echo "$basicSal+$hra+$da"|bc -l)

echo "Basic Salary : $basicSal"
echo "DA 20% : $da"
echo "HRA 40% : $hra"
echo "The Gross Salary : $grossSal"
