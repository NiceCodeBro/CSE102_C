/*###########################################################################*/
/*HW01_Muhammed_Selim_Dursun								 				 */
/*_____________________________________									     */
/*Created on 20/12/2016 by MuhammedSelim_Dursun								 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*program that calculates the overall grad of the students					 */
/*									    									 */
/*Inputs:								 								     */
/*	-Exams and homework's weights and grades     						   	 */
/*Outputs:																	 */
/*	-Total final grade										               	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>

/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define MAX_TOTAL_GRADE 100.0

int main (void){

	int firstMidWeight, secMidWeight, thirdMidWeight, firstHwWeight, 
secHwWeight, finalWeight ;
	int firstMidGrade, secMidGrade, thirdMidGrade, firstHwGrade, 
secHwGrade, finalGrade ;
	double totFinalGrade = 0 ;
	
	printf("Please enter the 1. midterm weight:") ;
	scanf("%d", &firstMidWeight) ;

	printf("Please enter the 2. midterm weight:") ;
	scanf("%d", &secMidWeight) ;

	printf("Please enter the 3. midterm weight:") ;
	scanf("%d", &thirdMidWeight) ;

	printf("Please enter the 1. homework weight:") ;
	scanf("%d", &firstHwWeight) ;

	printf("Please enter the 2. homework weight:") ;
	scanf("%d", &secHwWeight) ;

	printf("Please enter the final exam weight:") ;
	scanf("%d", &finalWeight) ;



	printf("Please enter the 1. midterm grade:") ;
	scanf("%d", &firstMidGrade) ;

	printf("Please enter the 2. midterm grade:") ;
	scanf("%d", &secMidGrade) ;

	printf("Please enter the 3. midterm grade:") ;
	scanf("%d", &thirdMidGrade) ;

	printf("Please enter the 1. homework grade:") ;
	scanf("%d", &firstHwGrade) ;

	printf("Please enter the 2. homework grade:") ;
	scanf("%d", &secHwGrade) ;

	printf("Please enter the final exam grade:") ;
	scanf("%d", &finalGrade) ;

/*	Averaging that midterms, final and homeworks							 */
	totFinalGrade = ( (firstMidWeight * firstMidGrade) +  
(secMidWeight * secMidGrade) +  (thirdMidWeight * thirdMidGrade) + 
(firstHwWeight * firstHwGrade)  +  (secHwWeight * secHwGrade) + 
(finalWeight * finalGrade) ) / MAX_TOTAL_GRADE ;


	printf("Your final grade is: %f\n", totFinalGrade) ;
	
	return 0 ;

}


/*###########################################################################*/
/*			End of HW01_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
