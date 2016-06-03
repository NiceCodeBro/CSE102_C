/*###########################################################################*/
/*HW04_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 19/03/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*	Program calculate sin and cos that entered number by taylor series 		 */
/* narcisstic number or not 												 */
/*									    									 */
/*Inputs:								 								     */
/*	-Degree				 													 */
/*	-n : number of first step of taylor series				   				 */
/*	-If user want that exit program; can press E or e						 */
/*Outputs:																	 */
/*	-Result of input's sin and cos 							               	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define PI 3.14 	
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* double factorial(int number)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* Result - Yollanan numberin faktoriyeli									 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Girilen number degerinin faktoriyelini hesaplayip return eden fonksiyon  */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
double factorial(int number);
/*---------------------------------------------------------------------------*/
/* double powerOfX(double radyan, int power)			              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* result - Yollanan input degerinin power kadar kati						 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Girilen radyan degerinin faktoriyelini hesaplayip return eden fonksiyon  */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
double powerOfX(double radyan, int power);
/*---------------------------------------------------------------------------*/
/* double sine(int degree, int n)						              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* Result - input degerleri icin sinus degeri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Girilen degree degeri icin taylor serisinin ilk n adimini sinus 		 */	
/* icin hesaplayan fonksiyon 												 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
double sine(int degree, int n);
/*---------------------------------------------------------------------------*/
/* double cosine(int degree, int n) 					              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* Result - input degerleri icin cosinus degeri 							 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Girilen degree degeri icin taylor serisinin ilk n adimini cosinus 		 */	
/* icin hesaplayan fonksiyon 												 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
double cosine(int degree, int n);
/*---------------------------------------------------------------------------*/
/* void getInputs(int* degree, int* n, int* exit)		              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Inputlari kullanicidan alip sin ve cos fonksiyonlarini cagiran program    */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void getInputs(int* degree, int* n, int* exit);

int main(){

	int degree, n, exit;

	getInputs(&degree, &n, &exit);

	if(exit==0){
	sine(degree, n);
	cosine(degree, n);
	}

	return 0;

}

/*	Girilen number degerinin faktoriyelini hesaplayip return eden fonksiyon  */
double factorial(int number){

	double result = 1.0; /* Faktoriyel hesabi icin baskangic deger */
	int i; /*	Dongu kontrol degiskeni */

		for(i = 1; i <= number; i++){

			result *= i;

		}
	
	return result; /* Yollanan input degerinin faktoriyeli */
} /* factorial fonksiyonunun sonu */

/*	Girilen radyan degerinin faktoriyelini hesaplayip return eden fonksiyon  */
double powerOfX(double radyan, int power){

	int i; /* Dongu kontrol degiskeni */
	double result = 1.0; /* Pow fonksiyonu icin baslangic deger */

	for(i = 0; i < power; i++){
	
		result *= radyan;

	}

	return result; /* Yollanan input degerinin power kadar kati */

} /* powerOfX fonksyinonun sonu */

/*	Girilen degree degeri icin taylor serisinin ilk n adimini sinus 		 */	
/* icin hesaplayan fonksiyon 												 */
double sine(int degree, int n){

	double coef=1.0, /* Katsayinin başlangic durumu */
		   divider, /* Serinin boleni */
		   x, /* Degree'nin radyan degerinin pow foksinyonundaki sonucu */
		   radyan, /* radyan hesabı icin kullanılan degisken */
		   result = 0.0;
	int tempDegree, /* Radyan hesabinda kullanilan degisken */
		i; /* Dongu kontrol degiskeni */

	for(i = 0; i < n; i++){
		/* Katsayinin durumu */
		if(i % 2 == 0) {
			coef = 1.0;
		} 	else {
			 coef = -1.0;
			}

		divider = factorial((2 * i) + 1);	 /* Bolen */
	
		tempDegree = degree;

		if(degree >= 180) {  /* Mod alma durumu */
			tempDegree %= 180;
		}

		radyan = ( (tempDegree) / 180.0) * PI; /*	Radyan hesabi	*/

		x = powerOfX(radyan, ((2 * i) + 1));  /* pow fonksiyonu */

		result += ((coef * x) / divider); /* Sonuc hesabı */
	}
	
	printf("sin(%d) where n is %d = %.4f\n", degree, n, result);

	return result; /* input degerleri icin sinus degeri */
} /* sine fonksiyon sonu */

/*	Girilen degree degeri icin taylor serisinin ilk n adimini cosinus 		 */	
/* icin hesaplayan fonksiyon 												 */
double cosine(int degree, int n){
 
	double coef=1.0, /* Katsayinin başlangic durumu */
		   divider, /* Serinin boleni */
		   x, /* Degree'nin radyan degerinin pow foksinyonundaki sonucu */
		   radyan, /* radyan hesabı icin kullanılan degisken */
		   result = 0.0;
	int tempDegree, /* Radyan hesabinda kullanilan degisken */
		i; /* Dongu kontrol degiskeni */

	for(i = 0; i < n; i++){
		/* Katsayinin durumu */
		 if(i % 2 == 0) {
			coef = 1.0;
		} 	else {
			 coef = -1.0;
			} 

		tempDegree = degree;
		if(degree >= 90) {  /* Mod alma durumu */
			tempDegree %= 90;
		}
	
		divider = factorial((2 * i));  /* Bolen */
	
		radyan = ( tempDegree / 180.0) * PI; /*	Radyan hesabi	*/
	
		x = powerOfX(radyan, (2 * i));  /* pow fonksiyonu */

		result += ((coef * x) / divider); /* Sonuc hesabı */
	
	}
	
	printf("cos(%d) where n is %d = %.4f\n", degree, n, result);

	return result; /* input degerleri icin cosinus degeri */
} /* cosine fonksiyon sonu */

/* Inputlari kullanicidan alip sin ve cos fonksiyonlarini cagiran program    */
void getInputs(int* degree, int* n, int* exit){

	int temp, temp2; /* Integer okumasinda kullanilan gecici degiskenler */
	char chr; /* karakter girilmesi durumunda harf kontrolu icin  */

		if(scanf("%d", &temp) == 0) { /* Okunan deger karakter cikma durumu */

			scanf("%c", &chr); /* Karakter cikma durumunda e veya E kontrolu */
		
			if(chr == 'e' || chr == 'E'){
				*exit = 1;
			}
		}

		if(*exit != 1) {

			scanf("%d", &temp2);

/*	Buraya kadar gelinmiş ise zaten 2 tane integer okunmuş demektir          */
		 	/* inputlari guncelleme 	*/
			*degree = temp;
			*n = temp2;
			*exit = 0;

		}
} 		 	/* getInputs fonksiyon sonu	*/

/*###########################################################################*/
/*			End of HW04_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
