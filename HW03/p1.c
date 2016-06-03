/*###########################################################################*/
/*HW03_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 04/03/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*	Program find that entered positive number is odd, factorial and 		 */
/* narcisstic number or not 												 */
/*									    									 */
/*Inputs:								 								     */
/*	-Positive integer    													 */
/*	-1,2 or 3 (respectively odd, factorial or narcissistic)   				 */
/*Outputs:																	 */
/*	-Entered number is positive or not						               	 */
/*	-Entered number is odd or not, factorial or not, narcissistic or not	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* void isOdd(int number)								              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	function find and print that number is odd or not odd					 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void isOdd(int number);
/*---------------------------------------------------------------------------*/
/* void isFactorial(int number)								                 */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	function check and print that number is factorial or not     		     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void isFactorial(int number);
/*---------------------------------------------------------------------------*/
/* int numberOfDigits(int number)								             */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* count - number of digits													 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	function find and return that number have digits					     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int numberOfDigits(int number);
/*---------------------------------------------------------------------------*/
/* void isNarcissistic(int number)								             */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	function find and print that number is narcisstic or not			     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void isNarcissistic(int number);

int main(void) 
{

	int posInteger, choice;
	char decision;

	printf("*****************************************************\n");
	printf("*                   WELCOME !                       *\n");
	printf("*  This program checks whether the given number     *\n");
	printf("* is an odd, a factorial or a narcissistic number   *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");

	do{

	printf("\nPlease enter a positive integer : ");
	scanf("%d", &posInteger);

	
	if(posInteger > 0){

	printf("Which property would you like to check?\n");
	printf("1)Odd nuber\n");
	printf("2)Factorial number\n");
	printf("3)Narcissistic number\n");
	printf("Please enter (1/2/3): ");

	scanf("%d", &choice); 

	if(choice == 1) { 
	    isOdd(posInteger);
	}
	if(choice == 2) {
	   isFactorial(posInteger);
	}
	if(choice == 3) {
	    isNarcissistic(posInteger);
	}

		} else {
			printf("The entered number is not positive.\n");
		    
		}

	printf("Do you want to continue (y/n)? ");
	scanf(" %c", &decision);

	} while(decision == 'y' || decision == 'Y');

	if(decision == 'n' || decision == 'N') {
		printf("Good bye !\n");
	}


	return 0;

}

/*	function find and print that number is odd or not odd					 */
void isOdd(int number) 
{

	if (number % 2 == 0) {
		printf("%d is not odd number.\n", number);
	}

	if (number % 2 != 0) {
		printf("%d is odd number.\n", number);
	}

}

/*	function check and print that number is factorial or not     		     */
void isFactorial(int number)
{

	int testNumber = 1, counter = 1;

	do{

	testNumber = testNumber * counter;

	if(testNumber == number) { 
		printf("%d is a factorial number !\n", number);   
	}

	counter++;

	} while(testNumber < number );

	if(testNumber > number  || testNumber != number ) {
		printf("%d is not factorial number !\n", number);
	}
} 

/*	function find and return that number have digits					     */
int numberOfDigits(int number)
{

	int temp, count = 0;
	
	temp = number;

	while(temp != 0){
	
	temp = temp / 10;
	count++;

	}

	return count;

}

/*	function find and print that number is narcisstic or not			     */
void isNarcissistic(int number)
{

	int temp, lastDigit, a, sum = 0;
	int nOfdigits = numberOfDigits(number);

	temp = number;

	for(a=1; a<=nOfdigits; a++){

	lastDigit = temp % 10;

	sum += (int)pow(lastDigit, nOfdigits);

	temp = (temp - (temp % 10)) / 10;
	}

	if(sum == number)  {
		printf("%d is narcissistic number.\n", number);
	}
	else {
		printf("%d is not narcissistic number.\n", number);
	}

} 

/*###########################################################################*/
/*			End of HW03_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
