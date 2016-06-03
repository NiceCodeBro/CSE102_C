/*###########################################################################*/
/*HW07_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 10/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/* icinde her turlu karakterin bulundugu stringde sadece harfleri goz onune  */ 
/*alarak harflerin butununun palindrome olup olmadigini bulan program 	     */
/*	returns							    									 */
/*	1 > palindrome 								    						 */
/*	0 > palindrome  degil						    						 */
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
/* int isPalindrome(char * str)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 - palindrome															 */
/* 0 - palindrome degil														 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*Kendisine gonderilen karakter stringi ile string boyutunu, stingdeki harf  */
/*sayisini, sag ve sol yaklasim indexlerini checkPalindrome recursive        */
/*fonksionuna gonderir return value'sini kontrol eder 						 */ 
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isPalindrome(char * str);
/*---------------------------------------------------------------------------*/
/* int checkPalindrome(char* str, int left, int right, int numberOfLetter)   */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 0 - palindrome degil														 */
/* 1 - palindrome  															 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* kendisine gonderilen bir stringdeki kelimenin palindrome olup olmadigini  */
/*check eder, sagdan ve soldan kelimenin merkezine dogru harf kontrolu yapar */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int checkPalindrome(char* str, int left, int right, int numberOfLetter);

int main(){

	printf("%d", isPalindrome("aa!'^<a"));

	return 0;
}
/*Kendisine gonderilen karakter stringi ile string boyutunu, stingdeki harf  */
/*sayisini, sag ve sol yaklasim indexlerini checkPalindrome recursive        */
/*fonksionuna gonderir return value'sini kontrol eder 						 */ 
int isPalindrome(char * str){

	int sizeStr;
	int i;
	int numberOfLetter = 0;
	
	if(str==NULL) return 0;
	sizeStr = strlen(str);
	
	for(i=0; i<sizeStr; i++){

		if(str[i]>='a' && str[i]<='z') numberOfLetter++;
		if(str[i]>='A' && str[i]<='Z') numberOfLetter++;		
	
	}


	/* 0. indexten size-1. index gonderilir ki tarama yapilsin*/
	if(checkPalindrome(str, 0, sizeStr-1, numberOfLetter )) return 1;
	else return 0;
	
}  /* isPalindrome fonksiyon sonu */

/* kendisine gonderilen bir stringdeki kelimenin palindrome olup olmadigini  */
/*check eder, sagdan ve soldan kelimenin merkezine dogru harf kontrolu yapar */
int checkPalindrome(char* str, int left, int right, int numberOfLetter){

	int palindrome=-1; /* baslangic degeri*/
	/*  eger indexte harf varsa bunu bu degerlere atilir*/
	char tempL, tempR; 

	/* eger hic letter yoksa palindrom da degildir */
	if(strlen(str)>=0 && numberOfLetter == 0) return 0;

	/* eger indexteki karakter harf ise kucuk harf olarak, soldaki indexde ki 
	harfi  tempL'ye, sagdaki idexdeki harfi tempR'ye atar */
	if(str[left] >= 'a' && str[left] <= 'z') tempL = str[left] ; 
	if(str[right] >= 'a' && str[right] <= 'z') tempR = str[right] ; 

	if(str[left] >= 'A' && str[left] <= 'Z') tempL = str[left] + 32; 
	if(str[right] >= 'A' && str[right] <= 'Z') tempR = str[right] + 32; 

	if((tempL >= 'a' && tempL <= 'z') && (tempR >= 'a' && tempR <= 'z')) {

		if(tempL == tempR){
			/* buraya kadar gelinmis ve 2 letter varsa elimizde  bu harfler 
			birbirine esittir, yani string palindromdur */
			if(numberOfLetter == 2) palindrome = 1;
			
			if(numberOfLetter > 2 ){
				/* karsilikli indexlerdeki harfler esitse sonraki idexler 
				icin de fonksiyon cagirilir */
				palindrome = checkPalindrome(str,left+1,right-1,
							 numberOfLetter-2);
			}
		}
		else{
			/* eger karsilikli indexler harf ve birbirine esit degilse 
			palindrom degildir */
			palindrome = 0;
			/* artik recursiv islemi yapmaya gerek kalmadi, string palindrom 
			degil*/
			numberOfLetter = 0; 
		}
	}
	
	
	/* eger indexdeki karakter veya karakterler harf degilse gereken taraftan 
	1 er index yaklasilmali */
	if(numberOfLetter > 0){

		if((str[left] < 'a' || str[left] > 'z') && (str[left] < 'A' || 
		str[left] > 'Z' ) && ((str[right] >= 'a' && str[right] <= 'z') || 
		(str[right] >= 'A' && str[right] <= 'Z'))) {
		
			palindrome = checkPalindrome(str, left+1, right, numberOfLetter);
		}
		if((str[right] < 'a' || str[right] > 'z') && (str[right] < 'A' || 
		str[right] > 'Z' ) && ((str[left] >= 'a' && str[left] <= 'z') || 
		(str[left] >= 'A' && str[left] <= 'Z'))) {

			palindrome = checkPalindrome(str, left, right-1, numberOfLetter);
		}
		if((str[left] < 'a' || str[left] > 'z') && (str[left] < 'A' || 
		str[left] > 'Z' ) && (str[right] < 'a' || str[right] > 'z') && 
		(str[right] < 'A' || str[right] > 'Z' ) ) {

			palindrome = checkPalindrome(str, left+1, right-1, numberOfLetter);
		}
		
	}

	return palindrome;
} /* checkPalindrome fonksiyon sonu */

/*###########################################################################*/
/*			End of HW07_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
