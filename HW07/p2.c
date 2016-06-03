/*###########################################################################*/
/*HW07_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 14/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/* icinde her turlu karakterin bulundugu stringde sadece harfleri goz onune  */ 
/*alarak harflerin butununun palindrome olup olmadigini bulan program 	     */
/*									    									 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define PI 3.14159265
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* int reflection(int angle)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* reflection - +-5 derecelik yansima payi ile birlikte acinin son degeri    */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* aci degerine gore uretilen random +-5 sayi ile aci degerini toplayan      */
/*fonksiyon 																 */
/*									    									 */	
/*---------------------------------------------------------------------------*/					    									 
int reflection(int angle);
/*---------------------------------------------------------------------------*/
/* int randNumber(int angle);							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* rand() - random sayi														 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Aci degerine gore random sayi ureten fonksiyon 							 */
/*									    									 */	
/*---------------------------------------------------------------------------*/	
int randNumber(int angle);
/*---------------------------------------------------------------------------*/
/* int kickDisc(double wallWidth, double wallHeight, double ballCenterX,     */
/*  double kickAngle, double ballRadius, double goalWidth);				     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 - top kalenin icinde													 */
/* 0 - top kalenin icinde degil												 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Topun yansima acisina gore kaleye girip girmeme durumunu hesaplayan       */
/*fonksiyon 															     */
/*									    									 */	
/*---------------------------------------------------------------------------*/	
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth);
/*---------------------------------------------------------------------------*/
/*   int recursiveKickDisc(int side, double wallWidth, double wallHeight,    */
/*double ballCenterX, double kickAngle, double ballRadius, double goalWidth) */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 - top kalenin icinde													 */
/* 0 - top kalenin icinde degil												 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Topun sag sol duvara carpma durumlarini kendini cagirarak son asamaya     */
/*gelip,topun kaleye girip girmeyecegini hesaplayan fonksiyon  			     */
/*									    									 */	
/*---------------------------------------------------------------------------*/	
int recursiveKickDisc(int side, double wallWidth, double wallHeight, double 
ballCenterX, double kickAngle, double ballRadius, double goalWidth);

int main(){

	printf("%d", kickDisc(10,26,2,45,1,2));
	
	return 0;
}

/* Aci degerine gore random sayi ureten fonksiyon */
int randNumber(int angle){
	srand(angle);
	return rand();
}

/* aci degerine gore uretilen random +-5 sayi ile aci degerini toplayan 
fonksiyon  */
int reflection(int angle){

	int reflection,
	    tempRef;

	tempRef = randNumber(angle);

	reflection = angle + (tempRef % 10) -5 ;
	
	return reflection;
}

/* Topun yansima acisina gore kaleye girip girmeme durumunu hesaplayan 
fonksiyon */
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
double kickAngle, double ballRadius, double goalWidth){

	/* topun carpma durumlarinda aciya gore farkli hesaplamalar oldugu icin 
	bunu belirlemeye yarayan degisken*/
	int side; 

	/*imkansiz durumlar*/
	if(wallWidth == goalWidth) return 1;
	if(wallWidth <= 0 || wallHeight <= 0 || ballCenterX < 0 || goalWidth <= 0 ) 
		return 0;
	if(ballCenterX < ballRadius) return 0;
	if((2 * ballRadius) > wallWidth ) return 0;
	
	/* budu durumlarda mantiken direk gol olmali*/
	if((2 * ballRadius) == wallWidth &&  goalWidth!=0 ) 
		return 1;
	if(kickAngle == 90 && ballCenterX >= ((wallWidth - goalWidth) / 2) 
	&& ballCenterX <= (((wallWidth - goalWidth) / 2) + goalWidth) )
		return 1;
	
	
	if(kickAngle>90) side = -1;
	if(kickAngle<90) side = 1;
	/*acinin 5-175 arasindan buyuk olma durumlari*/
	if(kickAngle > 175.0) kickAngle = 175.0;
	if(kickAngle < 5.0) kickAngle = 5.0; 

	
	if(kickAngle > 90 && kickAngle <= 175) {
		kickAngle = 180 - kickAngle;
	}


	/* top r kadar yuksekten yollandigi icin  wallHeightten yaricap cikarilip
	 gonderilir */
	if(recursiveKickDisc(side, wallWidth, wallHeight-ballRadius, 
		ballCenterX, kickAngle,ballRadius, goalWidth))
		return 1;
	else 
		return 0;
}

/* Topun sag sol duvara carpma durumlarini kendini cagirarak son asamaya gelip, 
topun kaleye girip girmeyecegini hesaplayan fonksiyon  */
int recursiveKickDisc(int side, double wallWidth, double wallHeight, double
ballCenterX, double kickAngle, double ballRadius, double goalWidth){

	double currentHeight, /*topun ilk atilmasindan sonraki heightteki azalma*/
		   karar, /*son carpma kisminda topun kaleye girme kontrolü*/
		   kaleDuvar, /* kale ile duvar arasindaki mesafe */
		   currentDegree,  /*carpma sonrasi acinin sekmis degeri*/
		   radyanAngle; /* acinin radyan cinsinden degeri*/
	int returnValue;


	/* topun ilk gonderilme durumu */
	if(ballCenterX>0){
		radyanAngle = kickAngle * (PI / 180.0) ;
		if(side == -1) {

			wallHeight -= (ballCenterX - ballRadius) * tan(radyanAngle);	
		}
		if(side == 1)
			wallHeight -= (wallWidth - ballCenterX - ballRadius) * 
						  tan(radyanAngle);

	}
	
	/* her carpista farkli deger ile gonderilcegi icin aci her seferinde
	 degismeli*/
	currentDegree = reflection(kickAngle);
	radyanAngle = currentDegree * (PI / 180.0) ;
	currentHeight = (wallWidth - ( 2 * ballRadius)) * tan(radyanAngle); 

	/*height yeterince uzunsa son asamaya kadar bu kisimda yinelemeli gelinir*/
	if(wallHeight > currentHeight){
	
		ballCenterX = 0;
		returnValue = recursiveKickDisc(side, wallWidth, (wallHeight - 
					  currentHeight), ballCenterX, currentDegree,ballRadius, 
					  goalWidth);
	}
	/*son asama ya gol olacak ya olmayacak*/
	if(wallHeight <= currentHeight) {
	
		kaleDuvar = (wallWidth - goalWidth) / 2;
		karar = (wallHeight - ballRadius) / tan(radyanAngle) + ballRadius ;

		if(karar >= kaleDuvar && karar <= (kaleDuvar + goalWidth)){

			returnValue = 1;
		}
		else {
			returnValue =  0;
		}
			
	}

	return returnValue;

}
/*###########################################################################*/
/*			End of HW07_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
