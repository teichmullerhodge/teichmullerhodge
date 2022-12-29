#!/usr/bin/bash 

#Simple bruteforce script in bash for programs that take passwords as arguments.

SUCESS="Sucess!" #As the name suggests, this string is the standard sucess output of the program.  

for i in {0..N}; do #loop N times, or just make a while true:
 STRING="./[program name] $i" #$i can be anything, numbers, random strings, etc.
 COMMAND=`$STRING` #Executes the command N times.
 if [ "$SUCESS" = "$COMMAND" ]; then #if the output of the command is equal to the sucess string...
  echo "password found! Password is: $i"
  exit 0 #print the right password ($i) and exits.
 else
  echo "trying...$i"
 fi
done
