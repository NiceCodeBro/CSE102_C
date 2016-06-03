/*HW06_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 06/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/* Bir string icerisindeki karakterlerin adedini integer arraye aktarir	     */
/*Aa-zZ arasi ilk 26 sizeda, 0-9 rakamlar sonraki 10 sizeda, bunlar disindaki*/
/*karakterler arrayin 36.indexinde sayacta tutuluyor					     */
/*									    									 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define SIZE 37
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* void freq(char* str, int* fr)						              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Bir string icerisindeki karakterlerin adedini integer arraye aktarir	     */
/*Aa-zZ arasi ilk 26 sizeda, 0-9 rakamlar sonraki 10 sizeda, bunlar disindaki*/
/*karakterler arrayin 36.indexinde sayacta tutuluyor					     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void freq(char* str, int* fr);

int main(){

	int fr[SIZE];


	freq("abCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |",fr);


	return 0;
}

/* Bir string icerisindeki karakterlerin adedini integer arraye aktarir
Aa-zZ arasi ilk 26 sizeda, 0-9 rakamlar sonraki 10 sizeda, bunlar disindaki 
karakterler arrayin 36.indexinde sayacta tutuluyor							 */
void freq(char* str, int* fr){

	int i;

	for(i=0; i<SIZE;i++){ /* integer arrayini initialize etme */
		
		fr[i] = 0;

	}
	
	i = 0;
	/* karakterin durumuna göre string sonuna kadar integer arrayin indexini 
	arttirma islemi */
	while(str[i]!='\0'){

		if(str[i] == 'A' || str[i] == 'a'){
			(fr[0])++;
		}
		else if((str[i] == 'B') || (str[i] == 'b')){
			(fr[1])++;
		}
		else if((str[i] == 'C') || (str[i] == 'c')){
			(fr[2])++;
		}
		else if((str[i] == 'D') || (str[i] == 'd')){
			(fr[3])++;
		}
		else if((str[i] == 'E') || (str[i] == 'e')){
			(fr[4])++;
		}
		else if((str[i] == 'F') || (str[i] == 'f')){
			(fr[5])++;
		}
		else if((str[i] == 'G') || (str[i] == 'g')){
			(fr[6])++;
		}
		else if((str[i] == 'H') || (str[i] == 'h')){
			(fr[7])++;
		}
		else if((str[i] == 'I') || (str[i] == 'i')){
			(fr[8])++;
		}
		else if((str[i] == 'J') || (str[i] == 'j')){
			(fr[9])++;
		}
		else if((str[i] == 'K') || (str[i] == 'k')){
			(fr[10])++;
		}
		else if((str[i] == 'L') || (str[i] == 'l')){
			(fr[11])++;
		}
		else if((str[i] == 'M') || (str[i] == 'm')){
			(fr[12])++;
		}
		else if((str[i] == 'N') || (str[i] == 'n')){
			(fr[13])++;
		}
		else if((str[i] == 'O') || (str[i] == 'o')){
			(fr[14])++;
		}
		else if((str[i] == 'P') || (str[i] == 'p')){
			(fr[15])++;
		}
		else if((str[i] == 'Q') || (str[i] == 'q')){
			(fr[16])++;
		}
		else if((str[i] == 'R') || (str[i] == 'r')){
			(fr[17])++;
		}
		else if((str[i] == 'S') || (str[i] == 's')){
			(fr[18])++;
		}
		else if((str[i] == 'T') || (str[i] == 't')){
			(fr[19])++;
		}
		else if((str[i] == 'U') || (str[i] == 'u')){
			(fr[20])++;
		}
		else if((str[i] == 'V') || (str[i] == 'v')){
			(fr[21])++;
		}
		else if((str[i] == 'W') || (str[i] == 'w')){
			(fr[22])++;
		}
		else if((str[i] == 'X') || (str[i] == 'x')){
			(fr[23])++;
		}
		else if((str[i] == 'Y') || (str[i] == 'y')){
			(fr[24])++;
		}
		else if((str[i] == 'Z') || ( str[i] == 'z')){
			(fr[25])++;
		}
		else if(str[i] == '0'){
			(fr[26])++;
		}
		else if(str[i] == '1'){
			(fr[27])++;
		}
		else if(str[i] == '2'){
			(fr[28])++;
		}
		else if(str[i] == '3'){
			(fr[29])++;
		}
		else if(str[i] == '4'){
			(fr[30])++;
		}
		else if(str[i] == '5'){
			(fr[31])++;
		}
		else if(str[i] == '6'){
			(fr[32])++;
		}
		else if(str[i] == '7'){
			(fr[33])++;
		}
		else if(str[i] == '8'){
			(fr[34])++;
		}
		else if(str[i] == '9'){
			(fr[35])++;
		}
		/* yukaridaki karakterler harici tum karakterler bu indexe */
		else {
			(fr[36])++; 
		
		}
		i++; /* update */
	}
} /* freq fonksiyon sonu */

/*###########################################################################*/
/*			End of HW06_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
