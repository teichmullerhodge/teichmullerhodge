#!/usr/bin/bash
#The __stack_chk_fail signature is \x74\x05\xe8\x92\xfe\xff\xff 
#original command: sed -i 's,\x74\x05\xe8\x92\xfe\xff\xff,\xINST\x05\xe8\x92\xfe\xff\xff,g' [NAME OF THE FILE]
#STACK_JZ=\x74\x05\xe8\x92\xfe\xff\xff 
#STACK_JG=\x7f\x05\xe8\x92\xfe\xff\xff 
#STACK_JS=\x78\x05\xe8\x92\xfe\xff\xff 
#STACK_JL=\x7c\x05\xe8\x92\xfe\xff\xff 
#STACK_JA=\x77\x05\xe8\x92\xfe\xff\xff 
#STACK_JNZ=\x75\x05\xe8\x92\xfe\xff\xff
#STACK_JGE=\x7d\x05\xe8\x92\xfe\xff\xff
#STACK_JLE=\x7e\x05\xe8\x92\xfe\xff\xff 
#STACK_JECXZ=\xe3\x05\xe8\x92\xfe\xff\xff 
#STACK_JMP=\xeb\x05\xe8\x92\xfe\xff\xff
#Simple program to patch STACK_PROTECTION on gcc compiled binaries

ARGC=("$#")
if [ $ARGC -eq 3 ]; then
 FILENAME=$1 
 CURRENT_INSTRUCTION=$2
 NEW_INSTRUCTION=$3
 STACK_CURRENT="\x$CURRENT_INSTRUCTION\x05\xe8\x92\xfe\xff\xff" #default instruction is JZ = 74
 STACK_CHANGED="\x$NEW_INSTRUCTION\x05\xe8\x92\xfe\xff\xff" 
 STRING='sed -i 's,$STACK_CURRENT,$STACK_CHANGED,g''
 COMMAND=`$STRING $FILENAME` 
else
 echo "Usage: ./StackInjection <filename> <current instr:[ex: 75]> <new instr:[ex: eb]>"
 exit 0
fi
