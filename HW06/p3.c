/*###########################################################################*/
/*HW06_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 08/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/* Bir stringin icindeki kelimenin buyuk stringdeki tekrar adedini bulan 	 */
/*program, kucuk stringde sadece tek numarali karakterler dikkate alinir     */
/*									    									 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* int count(char* str, char* substr)					              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* count - substr'nin strdeki tekrar adedi (tek numarali karakterlere gore)  */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*kaynak stringin cift indexlerini hedefte arar, kac defa gectigini bulur    */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/

int count(char* str, char* substr);
/*---------------------------------------------------------------------------*/
/* int helperCount(char* str, char* substr, int nOfOdd)			      	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 - eslesme var															 */
/* 0 - eslesme yok															 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* parametre olarak aldigi stringin tek rakamli karakterlerini kontrol eder  */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int helperCount(char* str, char* substr, int nOfOdd);


int count(char* str, char* substr){
	
	int sizeN = 0,sizeH = 0;
	int i = 0;
	int control;
	int nOfOdd;	/* needle daki tek sayi adedi */
	int counter=0;
	/* size of strings */
	sizeN = strlen(substr);
	sizeH = strlen(str);

	/* substr daki tek sayi adedi */
	if(sizeN == 1) nOfOdd = 1;
	else if(sizeN % 2 == 0) nOfOdd =  sizeN / 2;
	else if(sizeN % 2 == 1) nOfOdd = (sizeN + 1) / 2;

	/* kucuk stringde buyuk stringi aratma kontrolu*/
	if(sizeN <= sizeH){
		/*dongu sonuna kadar 1 er index kayarak eslesme oldukca return 
		1 oluyor ve sayac artiyor */
		do{
			control = helperCount(&str[i], substr, nOfOdd);
			
			if(control == 1) counter++; 
			i++;
		}while(i <= sizeH - sizeN );
	}

		return counter;

} /* count fonksiyon sonu */

/* parametre olarak aldigi stringin tek rakamli karakterlerini kontrol eder  */
int helperCount(char* str, char* substr, int nOfOdd){
	
	int i; /*loop control variable */
	int counter = 0;
	int sizeN = 0; /* size of needle */

	sizeN = strlen(substr);

	for(i = 0;i < sizeN;i += 2){ /* +2 update ile tek rakamlari kontrol */
	
		if(str[i]==substr[i]) 
			counter++;
	}
	if(counter == nOfOdd) return 1;
	else return 0;

} /* helperCount fonksiyon sonu */


/*###########################################################################*/
/*			End of HW06_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
