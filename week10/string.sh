#!/bin/bash

name=EkaterinA
#print the third letter
echo ${name:2:1} #${var:offset:lenght}
#TODO
#print "kate"
echo ${name:1:4} 
#Print the last letter Hint: use the length of the name
lenth=${#name}
echo ${name:${#name}-1:1} 
