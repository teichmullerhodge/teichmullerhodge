//Keygen for the 2ourc3's Baby Keygen 4 crackme, you can download the .exe file from here: https://crackmes.one/crackme/63a38ce833c5d43ab4ecf076
//password is crackmes.one
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 11 //Lenght of the Keys.

signed int COUNT = 0; //initial value for COUNTER.
signed int ASCII = 65; //since the decimal value of A is 65, let's start from there.
unsigned char Keygen[LEN];

int main(void){

	srand(time(NULL));
	while(COUNT < 100){ //100 key's are enough i guess.
	for(int i = 0; i < LEN; i++){
	ASCII += random() % 61;
	Keygen[i] = ASCII;
	ASCII = 65; }
	Keygen[0] = 'A'; //Conditions for the password being accepted.
	Keygen[3] = 'X'; //
	Keygen[7] = 'X'; //-----------------------------------------//
	printf("Keygen: %s\n", Keygen);
	COUNT++;
		} return 0;
		 		}
