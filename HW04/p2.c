/*###########################################################################*/
/*HW04_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 18/03/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/* 	Program get a positive integer from the user and print out 				 */
/* a simple ASCII art. 													     */
/*									    									 */
/*Inputs:								 								     */
/*	-Num : number that will print											 */
/*	-borderWidth : number of border's width					   				 */
/*	-chr : pattern of that will print number						    	 */
/*Outputs:																	 */
/*	-Print out that entered number between 0-99999   		               	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* getInputs(int* num, int* borderWidth, char* chr)					 	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Kullanicidan num, borderwidth ve chr degerleri alir ve günceller	     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void getInputs(int* num, int* borderWidth, char* chr);
/*---------------------------------------------------------------------------*/
/* printNumber(int num, int borderWidth, char chr)						     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 - Print islemi basarili												 */
/* 0 - Print islemi basarisiz												 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Num, borderwidth ve chr degerlerini alir ve numberOfDigits fonksiyonu    */
/* ile  basamak sayısını hesaplar ona gore digitleri ayıklar, printBorder	 */
/* ve helperFuncForPrint fonksiyonlarini da uygun durumlarda kullanarak  	 */
/* ASCII art tablosunu ekrana basan fonksiyon  								 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int printNumber(int num, int borderWidth, char chr);
/*---------------------------------------------------------------------------*/
/* numberOfDigits(int number)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* Count - Sayinin basamak degeri											 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Number degerinin basamak sayisini bulan fonkssiyon					     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int numberOfDigits(int number);
/*---------------------------------------------------------------------------*/
/* helperFuncForPrint(int digit, int count, char chr)	              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*   -																 		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Girilen count degeri yardimi ile hangi sayinin hangi satirinin 			 */
/*	basilacagina karar verir ve ekrana basan fonksiyon						 */						    									 
/*---------------------------------------------------------------------------*/
void helperFuncForPrint(int digit, int count, char chr);
/*---------------------------------------------------------------------------*/
/* printBorder(int num, int borderWidth, int nOfBorderLength, char chr)      */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*   -																 		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	nOfBorderLength sayısınca ekrana istenen deseni basan fonksiyon 		 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void printBorder(int num, int borderWidth, int nOfBorderLength, char chr);

int main(void){

	int num,borderWidth;
	char chr;

	getInputs(&num,&borderWidth,&chr);
	printNumber(num,borderWidth,chr);

	return 0;
}

/*	Kullanicidan num, borderwidth ve chr degerleri alir ve günceller	     */
void getInputs(int* num, int* borderWidth, char* chr){

	scanf("%d%d %c", num, borderWidth, chr);

}

/*	Num, borderwidth ve chr degerlerini alir ve numberOfDigits fonksiyonu    */
/* ile  basamak sayısını hesaplar ona gore digitleri ayıklar, printBorder	 */
/* ve helperFuncForPrint fonksiyonlarini da uygun durumlarda kullanarak  	 */
/* ASCII art tablosunu ekrana basan fonksiyon  								 */
int printNumber(int num, int borderWidth, char chr){

/*	Basamak sayisina gore sayiyi rakamlara ayirmada kullanilan degiskenler   */
	int digit1, digit2, digit3, digit4, digit5;
	int digitNumber = 0, /* Katarlara ayirmada, katar tespit degiskeni */
		temp = 0,   /* Katar ayirmada yardimci degisken */
		temp2;		/* Katar ayirmada yardimci degisken */
	int count = 1; /* helperFuncForPrint fonksiyonuna gonderilen sayac */
	int i,  /*	Dongu kontrol degiskeni	*/
		nOfBorderLength; /* Ekrana basilacak borderin üst ve alt kısım sayisi*/

	if(num>0 && numberOfDigits(num)>=1 && numberOfDigits(num) <= 5 ){
		
		nOfBorderLength = ((numberOfDigits(num)) * 7) + borderWidth * 2;

		/* Ust borderi bastirma*/
		printBorder(num, borderWidth, nOfBorderLength, chr);

		if(numberOfDigits(num) <= 5){/* Basamak sayisinin 5 ve daha az olmasi*/
	
			/* num'un 0 olması durumu */
			if(num == 0) {
				digitNumber = 1; 
				digit5 = num;
				}

			temp = num;

			/* Sayiyi katarlarina ayirma islemleri */
			while(temp != 0){
	
				temp2 = temp;
				temp = temp / 10;
	
				digitNumber++;	
	
				if(digitNumber == 1)  {
					digit5 = (temp2 % 10);
				}	
				if(digitNumber == 2)  {
					digit4 = (temp2 % 10);
				}	
				if(digitNumber == 3)  {
					digit3 = (temp2 % 10);
				}	
				if(digitNumber == 4)  {
					digit2 = (temp2 % 10);
				}	
				if(digitNumber == 5)  {
					digit1 = (temp2 % 10);
				}	
			}
		}

/* Sayi 1 basamakli ise 1 katar ayni sayac degeri icin helper fonku cagirma  */
/*	ve sag - sol borderi ekrana basma										 */
		if(numberOfDigits(num) == 1){

			while(count <= 7){
				/* Sol border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}

				helperFuncForPrint(digit5, count, chr);
				/* Sag border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}
				count++;
				printf("\n");
			}
		}
	
/* Sayi 2 basamakli ise 2 katar ayni sayac degeri icin helper fonku cagirma  */
/*	ve sag - sol borderi ekrana basma										 */
		if(numberOfDigits(num) == 2){

			while(count <= 7){
				/* Sol border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}

				helperFuncForPrint(digit4, count, chr);
				helperFuncForPrint(digit5, count, chr);
				/* Sag border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}
				count++;
				printf("\n");
			}
		}
	
/* Sayi 3 basamakli ise 3 katar ayni sayac degeri icin helper fonku cagirma  */
/*	ve sag - sol borderi ekrana basma										 */
		if(numberOfDigits(num) == 3){

			while(count <= 7){
				/* Sol border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}

				helperFuncForPrint(digit3, count, chr);
				helperFuncForPrint(digit4, count, chr);
				helperFuncForPrint(digit5, count, chr);
				/* Sag border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}
				count++;
				printf("\n");
			}
		}

/* Sayi 4 basamakli ise 4 katar ayni sayac degeri icin helper fonku cagirma  */
/*	ve sag - sol borderi ekrana basma										 */
		if(numberOfDigits(num) == 4){

			while(count <= 7){
				/* Sol border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}

				helperFuncForPrint(digit2, count, chr);
				helperFuncForPrint(digit3, count, chr);
				helperFuncForPrint(digit4, count, chr);
				helperFuncForPrint(digit5, count, chr);
				/* Sag border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}
				count++;
				printf("\n");
			}
		}

/* Sayi 5 basamakli ise 5 katar ayni sayac degeri icin helper fonku cagirma  */
/*	ve sag - sol borderi ekrana basma										 */
		if(numberOfDigits(num) == 5){

			while(count <= 7){
				/* Sol border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}

				helperFuncForPrint(digit1, count, chr);
				helperFuncForPrint(digit2, count, chr);
				helperFuncForPrint(digit3, count, chr);
				helperFuncForPrint(digit4, count, chr);
				helperFuncForPrint(digit5, count, chr);
				/* Sag border */
				for(i = 0; i < borderWidth; i++){
					printf("%c", chr);
				}

				count++;
				printf("\n");
			}
		}
		/* Alt borderi bastirma */
		printBorder(num, borderWidth, nOfBorderLength, chr);
	
		return 1;

	}

	return 0;
}  /*	end of printNumber function	*/

/*	nOfBorderLength sayısınca ekrana istenen deseni basan fonksiyon 		 */
void printBorder(int num, int borderWidth, int nOfBorderLength, char chr){

	int i, j; /* Dongu kontrol degiskenleri */

	for(j =0 ; j < borderWidth; j++){
	
		for(i = 0; i < nOfBorderLength; i++ ) {
			printf("%c", chr);
		}

		printf("\n");
	}
} /*	end of printBorder function	*/

/*	Number degerinin basamak sayisini bulan fonksiyon					     */
int numberOfDigits(int number){

	int temp, count = 0;
	
	temp = number;

	while(temp != 0){
		temp = temp / 10;
		count++;
	}

	if(number == 0) { 
		count++;
	}

	return count;

} /*	end of numberOfDigits function	*/

/*	Girilen count degeri yardimi ile hangi sayinin hangi satirinin 			 */
/*	basilacagina karar verir ve ekrana basan fonksiyon						 */
void helperFuncForPrint(int digit, int count, char chr){

	/*Ekrana 1 bastirma islemleri */
	if(digit == 1){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("   %c   ", chr);
		}

		if(count == 3){
			printf("  %c%c   ", chr, chr);
		}

		if(count == 4){
			printf("   %c   ", chr);
		}

		if(count == 5){
			printf("   %c   ", chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 2 bastirma islemleri */
	if(digit == 2){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("    %c  ", chr);
		}

		if(count == 4){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 5){
			printf("  %c    ", chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 3 bastirma islemleri */
	if(digit == 3){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("    %c  ", chr);
		}

		if(count == 4){
			printf("   %c%c  ", chr, chr);
		}

		if(count == 5){
			printf("    %c  ", chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 4 bastirma islemleri */
	if(digit == 4){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c %c  ", chr, chr);
		}

		if(count == 3){
			printf("  %c %c  ", chr, chr);
		}

		if(count == 4){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 5){
			printf("    %c  ", chr);
		}

		if(count == 6){
			printf("    %c  ", chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 5 bastirma islemleri */
	if(digit == 5){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("  %c    ", chr);
		}

		if(count == 4){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 5){
			printf("    %c  ", chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 6 bastirma islemleri */
	if(digit == 6){

		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("  %c    ", chr);
		}

		if(count == 4){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 5){
			printf("  %c %c  ", chr, chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 7 bastirma islemleri */
	if(digit == 7){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("    %c  ", chr);
		}

		if(count == 4){
			printf("    %c  ", chr);
		}

		if(count == 5){
			printf("    %c  ", chr);
		}

		if(count == 6){
			printf("    %c  ", chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 8 bastirma islemleri */
	if(digit == 8){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("  %c %c  ", chr, chr);
		}

		if(count == 4){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 5){
			printf("  %c %c  ", chr, chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 9 bastirma islemleri */
	if(digit == 9){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("  %c %c  ", chr, chr);
		}

		if(count == 4){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 5){
			printf("    %c  ", chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}

	}

	/*Ekrana 0 bastirma islemleri */
	if(digit == 0){
		if(count == 1){
			printf("       ");
		}

		if(count == 2){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 3){
			printf("  %c %c  ",chr,chr);
		}

		if(count == 4){
			printf("  %c %c  ",chr,chr);
		}

		if(count == 5){
			printf("  %c %c  ",chr,chr);
		}

		if(count == 6){
			printf("  %c%c%c  ", chr, chr, chr);
		}

		if(count == 7){
			printf("       ");
		}
	}
}  /*	end of helperFuncForPrint function	*/

/*###########################################################################*/
/*			End of HW04_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
