/*###########################################################################*/
/*HW02_Muhammed_Selim_Dursun							 				     */
/*_____________________________________									     */
/*Created on 29/12/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*Program that calculates the overall grade of the students	 				 */
/*Includes only funtions because of HW's last update						 */
/*									    									 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define MAX_TOTAL_GRADE 100

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* void calculateLastGrade()								                 */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	function that get midterm, homework and final's weight and grade, and    */
/*calculate finally grade and print finally grade							 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/

void calculateLastGrade();

int main(){
	calculateLastGrade();

	return 0;

}

/*	
	function that get midterm, homework and final's weight and grade, and 
calculate finally grade and print finally grade
*/
void calculateLastGrade()
{
    
    int MidWeight, HwWeight,  FinalWeight,  MidGrade,  HwGrade,  FinalGrade;
    double FinallyGrade;
	printf("Please enter the 1. midterm weight:");
	scanf("%d", &MidWeight);

	printf("Please enter the 1. homework weight:");
	scanf("%d", &HwWeight);

	printf("Please enter the final exam weight:");
	scanf("%d", &FinalWeight);

	printf("Please enter the 1. midterm grade:");
	scanf("%d", &MidGrade);

	printf("Please enter the 1. homework grade:");
	scanf("%d", &HwGrade);

	printf("Please enter the final exam grade:");
	scanf("%d", &FinalGrade);

	FinallyGrade =  ( (MidWeight * MidGrade) + (HwWeight * HwGrade) + 
(FinalWeight * FinalGrade) ) / MAX_TOTAL_GRADE  ;

	printf("Your final grade is: %f\n", FinallyGrade);
	
}


/*###########################################################################*/
/*			End of HW02_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
