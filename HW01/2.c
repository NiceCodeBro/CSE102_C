/*###########################################################################*/
/*HW01_Muhammed_Selim_Dursun							 				     */
/*_____________________________________									     */
/*Created on 20/12/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*Program that calculates how many days the user has lived					 */
/*									    									 */
/*Inputs:								 								     */
/*	-Current date    													   	 */
/*	-Birthdate								    						   	 */
/*	-Time of Another Planet					    						   	 */
/*Outputs:																	 */
/*	-Have lived days			  							               	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define DAY_IN_MONTH 30
#define DAY_IN_YEAR 365
#define HOURS_IN_EARTH_DAY 24

int main(void) {

	
	int currentYear, currentMonth, currentDay ;
	int birthdateYear, birthdateMonth, birthdateDay ;
	int livedDays, totalHours ;
	int planetHours, planetDay, planetMonth ; 
	int personPlanetDay, personPlanetMonth, personPlanetYear ;


	printf("Please enter the current date.\n") ;
	printf("Year:") ;
	scanf("%d", &currentYear) ;

	printf("Month:") ;
	scanf("%d", &currentMonth) ;

	printf("Day:") ;
	scanf("%d", &currentDay) ;

	printf("Please enter your birthday.\n") ;
	printf("Year:") ;
	scanf("%d", &birthdateYear) ;

	printf("Month:") ;
	scanf("%d", &birthdateMonth) ;

	printf("Day:") ;
	scanf("%d", &birthdateDay) ;

/*	Calculating that user has lived based on date of birth and current       */
/*time difference from the turning point									 */
	livedDays = ( currentDay + (currentMonth-1) * DAY_IN_MONTH + 
(currentYear-1) * DAY_IN_YEAR ) - ( birthdateDay + (birthdateMonth-1) * 
DAY_IN_MONTH + (birthdateYear-1) * DAY_IN_YEAR ) ;


	printf("You have lived %d days.\n", livedDays);

		
	printf("Please enter about the time of another planet\n") ;
	printf("How many hours is a day?") ;
	scanf("%d", &planetHours) ;
	printf("How many days is a month?") ;
	scanf("%d", &planetDay) ;
	printf("How many months is a year?") ;
	scanf("%d", &planetMonth) ;
/*	Lived hours for other calculating operations							 */
	totalHours = livedDays * HOURS_IN_EARTH_DAY ;

/*	Timing calculations on the planet by total hours						 */
	personPlanetDay = (totalHours % (planetHours * planetDay) ) / planetHours ;

	personPlanetMonth = ( ( (totalHours - (planetHours * personPlanetDay) ) ) 
% (planetHours * planetDay*planetMonth) ) / (planetHours * planetDay) ;

	personPlanetYear = ( totalHours - (personPlanetDay * planetHours 
+ personPlanetMonth * planetDay * planetHours) ) 
/ (planetMonth * planetDay*planetHours) ;
	
	printf("If you lived in a planet where a day is ") ;
	printf("%d hours, a month is %d days and ", planetHours, planetDay) ;
	printf("a year is %d months: you were %d", planetMonth, personPlanetYear) ;
	printf(" years, %d months and ", personPlanetMonth) ;
	printf("%d days old\n", personPlanetDay) ;

	return (0) ;
}
 
/*###########################################################################*/
/*			End of HW01_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
