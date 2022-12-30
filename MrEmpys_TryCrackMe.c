//Code for MrEmpy's TryCrackme, you can download the .exe file from this url: https://crackmes.one/crackme/61c8deff33c5d413767ca0ea
//password is crackmes.one 
//Easy task, with simple R.E techniques you can find the password, i simply coded the output from ghidra decompiler and printed the key :)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

signed int Flag = 1;
unsigned char Usrinput[64];
unsigned char Key[104];
signed long Lvalue = 3833744396540657716; //Value extracted from Ghidra

void banner(){

    printf(R"EOF(
  _____          ___             _   __  __     
 |_   _| _ _  _ / __|_ _ __ _ __| |_|  \/  |___ 
   | || '_| || | (__| '_/ _` / _| / / |\/| / -_)
   |_||_|  \_, |\___|_| \__,_\__|_\_\_|  |_\___|
           |__/                                 
                       )EOF");
}


int main(void){

  
    banner();
	printf("\nInsert the key: "); //Changed the "Put the key" string.
	scanf("%s", Usrinput);
	size_t Len = strlen((char *)&Lvalue); //LEN IS EQ TO 10
	int k = 0;
	for(int i = 0; i < Len; i++){
	sprintf(Key + k, "%02x", (unsigned long)((int)*(char *)((long)&Lvalue + (long)i) & 255));
	k = k + 2; }
	//printf("Key is: %s\n", Key); Key is: 34407373373234353336
	Len = strlen(Key);
	Flag = strncmp(Usrinput, Key, Len);
        if (Flag == 0) {
           printf("[+] Correct key!\n"); //added \n
	   return  0;
  			}
 	 else {
    	   printf("[-] Incorrect key!\n"); //added \n
	   return 0;

		}
			}
