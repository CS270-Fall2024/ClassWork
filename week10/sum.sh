#!/bin/bash

#Creat a list
numbers=(1 2 3 4 5 6 7 8 9)

sum=0
#echo ${numbers[*]}
#Add all elements
# for num in ${numbers[*]}
for num in $@
do
    #echo $num
    (( sum=$sum+$num ))
done


#display sum
echo "Sum = $sum"
echo "count = $#"
declare -i aver
(( aver = $sum / $# )) 
echo -n "average = "
echo "scale=2; $sum / $#" | bc
