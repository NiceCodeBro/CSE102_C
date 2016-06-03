/*HW06_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 06/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/* String.h kutuphanesindeki strcmp fonksiyonunun kisitlanmis hali, string   */
/* karsilastirmasi yaparken kaynak stringin cift indexlerinin hedef stringde */
/* uyusma durumlarini kontrol eder	    									 */
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
/* char* matcher(char* haystack, char* needle) 			              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* char* - eslesmenin ilk karakterinin indexini string adresiyle			 */
/* NULL - eslesme yoksa										     			 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*haystack stringinde needle stringini aratir (yanlizca kelimedeki tek sayili*/
/*karakterler)ilk buldugu yerdeki stringin adresini dondurur				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
char* matcher(char* haystack, char* needle);
/*---------------------------------------------------------------------------*/
/* int helperMatcher(char* newHaystack, char* needle, int nOfOdd)      	     */
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
int helperMatcher(char* newHaystack, char* needle, int nOfOdd);

int main(){

	char *x="";
	char *b="";

	printf("%s", matcher(x, b));


	return 0;
}

/*haystack stringinde needle stringini aratir (yanlizca kelimedeki tek sayili 
karakterler)ilk buldugu yerdeki stringin adresini dondurur*/
char* matcher(char* haystack, char* needle){
	
	int sizeN = 0,sizeH = 0;
	int i = 0;
	int control;
	int nOfOdd;	/* needle daki tek sayi adedi */
	
	/* size of strings */
	sizeN = strlen(needle);
	sizeH = strlen(haystack);
	
	if(haystack[0]=='\0') return NULL;
	if(needle[0]=='\0') return NULL;
	
	/* needle daki tek sayi adedi */
	if(sizeN == 1) nOfOdd = 1;
	else if(sizeN % 2 == 0) nOfOdd =  sizeN / 2;
	else if(sizeN % 2 == 1) nOfOdd = (sizeN + 1) / 2;

	/* kucuk stringde buyuk stringi aratma kontrolu*/
	if(sizeN <= sizeH){
		/*eger eslesme olursa control degiskeninin degeri 1 olacak ve 
		dongu sonlanacak*/
		do{
			control = helperMatcher(&haystack[i], needle, nOfOdd);

			if(control != 1) i++; 

		}while(i <= sizeH - sizeN && control != 1);
	}
	if(control == 1 ){
		return &haystack[i];
	}
	else {
		return NULL;
	}

} /* matcher fonksiyon sonu */

/* parametre olarak aldigi stringin tek rakamli karakterlerini kontrol eder  */
int helperMatcher(char* newHaystack, char* needle, int nOfOdd){
	
	int i; /*loop control variable */
	int counter = 0;
	int sizeN = 0; /* size of needle */

	sizeN = strlen(needle);

	for(i = 0;i < sizeN;i += 2){ /* +2 update ile tek rakamlari kontrol */
	
		if(newHaystack[i]==needle[i]) 
			counter++;
	}
	if(counter == nOfOdd) return 1;
	else return 0;

} /* helperMatcher fonksiyon sonu */
/*###########################################################################*/
/*			End of HW06_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
