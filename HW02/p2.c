/*###########################################################################*/
/*HW02_Muhammed_Selim_Dursun							 				     */
/*_____________________________________									     */
/*Created on 29/12/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*Program that calculates the area and perimeter of certain geometric shape	 */
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
#define PI 3.14


/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* int areaOfRectangle(int width, int height)				                 */
/* -----------																 */
/*	width	- width of rectangle	    									 */
/*	height	- height of rectangle	    									 */
/*									    									 */						    									 
/* Return																	 */
/* ------																	 */
/*	width*height															 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	A function that calculate area of rectangle								 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int areaOfRectangle(int width, int height);

/*---------------------------------------------------------------------------*/
/* int perimeterOfRectangle(int width, int height)			                 */
/* -----------																 */
/*	width	- width of rectangle		    								 */
/*	height	- height of rectangle		    								 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*	2 * (width + height)													 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	A function that calculate perimeter of rectangle						 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int perimeterOfRectangle(int width, int height);

/*---------------------------------------------------------------------------*/
/* int areaOfSquare(int edgeLength)					 		                 */
/* -----------																 */
/*	edgeLength	- edge of square	    								 	 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*	edgeLength * edgeLength													 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	A function that calculate area of square								 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int areaOfSquare(int edgeLength);

/*---------------------------------------------------------------------------*/
/* int perimeterOfSquare(int edgeLength)			 		                 */
/* -----------																 */
/*	edgeLength	- edge of square	    									 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*	2 * (edgeLength + edgeLength)										     */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	A function that calculate perimeter of square							 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int perimeterOfSquare(int edgeLength);

/*---------------------------------------------------------------------------*/
/* double areaOfCircle(int radius) 					 		                 */
/* -----------																 */
/*	radius	- radius of circle			    								 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*	PI * radius * radius												     */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	A function that calculate area of circle								 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
double areaOfCircle(int radius);

/*---------------------------------------------------------------------------*/
/* double perimeterOfCircle(int radius)				 		                 */
/* -----------																 */
/*	radius	- radius of circle			    								 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/*	2 * PI * radius														     */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	A function that calculate perimeter of circle							 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
double perimeterOfCircle(int radius);

int main(void){
	int widthRectangle, heightRectangle;
	int widthSquare;
	int radiusOfCircle;
	int printVariable1, printVariable2;
	double printVariable3, printVariable4;

	printf("Please enter the width of the rectangle:");
	scanf("%d", &widthRectangle);

	printf("Please enter the height of the rectangle:");
	scanf("%d", &heightRectangle);
	
	printVariable1 = areaOfRectangle(widthRectangle, heightRectangle);
	printf("The area of the rectangle is: %d\n", printVariable1);

	printVariable2 = perimeterOfRectangle(widthRectangle, heightRectangle);
	printf("The perimeter of the rectangle is: %d\n", printVariable2);

	printf("Please enter the width of the square:");
	scanf("%d", &widthSquare);

	printVariable3 = areaOfSquare(widthSquare);
	printf("The area of the square is: %.2f\n", printVariable3);

	printVariable3 = perimeterOfSquare(widthSquare);
	printf("The perimeter of the square is: %.2f\n", printVariable3);

	printf("Please enter the radius of the circle:");
	scanf("%d", &radiusOfCircle);
	
	printVariable3 = areaOfCircle(radiusOfCircle);
	printf("The area of the circle is: %.2f\n", printVariable3);

	printVariable4 = perimeterOfCircle(radiusOfCircle);
	printf("The perimeter of the circle is: %.2f\n", printVariable4);
	
	
	return 0;

}

/*	A function that calculate area of rectangle								 */
int areaOfRectangle(int width, int height){

	return width*height;
}

/*	A function that calculate perimeter of rectangle						 */
int perimeterOfRectangle(int width, int height){

	return 2 * (width + height);
}

/*	A function that calculate area of square								 */
int areaOfSquare(int edgeLength)
{
	return edgeLength * edgeLength;
}

/*	A function that calculate perimeter of square							 */
int perimeterOfSquare(int edgeLength)
{
	return 2 * (edgeLength + edgeLength);
}

/*	A function that calculate area of circle								 */
double areaOfCircle(int radius)
{
	return PI * radius * radius;
}

/*	A function that calculate perimeter of circle							 */
double perimeterOfCircle(int radius)
{
	return 2 * PI * radius;
}


/*###########################################################################*/
/*			End of HW02_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
