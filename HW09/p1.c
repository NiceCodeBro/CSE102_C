/*###########################################################################*/
/*HW09_Muhammed_Selim_Dursun								 				 */
/*_____________________________________									     */
/*Created on 28/04/2016 by MuhammedSelim_Dursun								 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*C program that keeps information about world countries.					 */
/*									    									 */
/*Inputs:								 								     */
/*	-a Add a country														 */
/*	-b Print name of the most powerful country in terms of military strength */
/*	-c Print name of the largest country in terms of land it possesses  	 */
/*	-d Calculates and prints how many people at minimum should be seen       */
/*	-e Exit the program    						   							 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
/*                               Typedefs                                    */
/*---------------------------------------------------------------------------*/
typedef struct wContries{
	char name[25];
	int population;
	int area;
	int nOfArmy;
	char neighborContries[10][25];
} contriesT;

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* int indexFind(contriesT* cont, char* str,int i)		              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Str stringini cont tipindeki struct icinde buldugu indexi donduren fonk	 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int indexFind(contriesT* cont, char* str,int i);
/*---------------------------------------------------------------------------*/
/* int findMinPop(contriesT* cont,int source,int target, int i)        	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*	Hedefe ulasabilirse komsu ulkeler uzerinden gorulen total insan sayisini */
/* toplayan fonksiyon														 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int findMinPop(contriesT* cont,int source,int target, int i);


int main()
{
	char choice;  /*yapilan secimleri tutan degisken*/
	char desicion[25]; /*girilen strin -1 mi degil mi diye kontrol degiskeni*/
	
	int i, /* number of total add contry*/
		j, /*loop control variables*/
		a,/*loop control variables*/
		t,/*loop control variables*/
		k,/*loop control variables*/
		m;/*loop control variables*/
	
	int indexOfDesicion;
	char dest[1000][25];
	int karar;
	int max;
	int indexOfMax;

	contriesT cont[100];
	contriesT cont2[100];
	
	/*gidilecek yer ve bulunan yer*/
	char sourceCont[25];
	char targetCont[25];
	int indexOfSource;
	int indexOfTarget;
	i = -1;

	do{

		printf("Make your choice:\n");
		scanf(" %c", &choice);

		/*Add a country (if user presses corresponding key, in this case: ‘a’), 
		(Type ‘-1’ to finish neighbor input )*/
		if(choice == 'a')
		{
			j = 0;
			i++;
			scanf("%s", cont[i].name);
			scanf("%d", &cont[i].population);
			scanf("%d", &cont[i].area);
			scanf("%d", &cont[i].nOfArmy);
			
			do{
				scanf("%s", desicion);
				if(strcmp(desicion, "-1") != 0)
				{

					strcpy(cont[i].neighborContries[j], desicion);
					if(j < 10) j++;
				}
				
				if(strcmp(desicion, "-1") == 0) {
						for(a = j; a < 10; a++)
					strcpy(cont[i].neighborContries[j], "\0");
				
				}
				
			}while(strcmp(desicion, "-1") != 0 );

		}

		/*Print name of the most powerful country in terms of military 
		strength in vicinity of a given country (among neighbors of neighbors 
		of given country including itself )*/
		if(choice == 'b')
		{
			scanf("%s", desicion);
			if(i == 0) printf("%s", cont[0].name);
			else
			{
				indexOfDesicion = 0;
				for(a = 0; a <= i; a++)
				{
				
					if(strcmp(cont[a].name, desicion)==0)
						indexOfDesicion = a;
				
				}
				t = 0;
				strcpy(dest[t],cont[indexOfDesicion].name);
				t++;
				for(a = 0; a < 10; a++)
				{
					if(cont[indexOfDesicion].neighborContries[a]!='\0')
					{
						strcpy(dest[t],
						cont[indexOfDesicion].neighborContries[a]);
						t++;
					}
				}
				k = t - 1;
				for(a = 0; a < k; a++)
				{		
					for(m = 0; m <= i; m++)
					{
						if(strcmp(cont[indexOfDesicion].neighborContries[a],
						cont[m].name) == 0)
						{
							strcpy(dest[t],cont[m].name);
							t++;
							for(j = 0; j < 10; j++)
							{
								if(cont[m].neighborContries[j] != '\0')
								{
									strcpy(dest[t],
									cont[m].neighborContries[j]);
									t++;
								}
							}
						}
					}
				}

				for(a = 0; a < 100; a++)
				{
					cont2[a] = cont[a];
				}
				
				karar = 0;
				for(a = 0; a <= i; a++)
				{
					for(j = 0; j < t; j++)
					{
						if(strcmp(cont[a].name, dest[j])==0)
							karar = 1;
					}
					if(karar == 0)
					{
						cont2[a].nOfArmy = 0;
					}
					else karar = 0;
				}
			
				max = cont2[0].nOfArmy;
				indexOfMax = 0;
				for(a = 0;a <= i; a++)
				{
					if(max < cont2[a].nOfArmy)
					{
						max = cont2[a].nOfArmy;
						indexOfMax = a;
					}
				}			
				printf("%s\n", cont[indexOfMax].name);
			}
		}
		/*Print name of the largest country in terms of land it possesses in
		 vicinity of a given country (among neighbors of neighbors of given 
		 country including itself )*/
		if(choice == 'c')
		{
			scanf("%s", desicion);
			if(i == 0) printf("%s", cont[0].name);
			else
			{
				for(a = 0; a <= i; a++)
				{
					if(strcmp(cont[a].name, desicion)==0)
						indexOfDesicion = a;	
				}
				t = 0;
				strcpy(dest[t], cont[indexOfDesicion].name);
				t++;
				for(a = 0; a < 10; a++)
				{
					if(cont[indexOfDesicion].neighborContries[a] != '\0')
					{
						strcpy(dest[t], 
							   cont[indexOfDesicion].neighborContries[a]);
						t++;
					}
				}
				k = t - 1;
				for(a = 0; a < k; a++)
				{		
					for(m = 0;m <= i; m++)
					{
						if(strcmp(cont[indexOfDesicion].neighborContries[a], 
						cont[m].name) == 0)
						{
							strcpy(dest[t],cont[m].name);
							t++;
							for(j = 0; j < 10; j++)
							{
								if(cont[m].neighborContries[j] != '\0')
								{
									strcpy(dest[t], 
									cont[m].neighborContries[j]);
									t++;
								}
							}
						}
					}
				}

				for(a = 0;a < 100; a++)
				{
					cont2[a] = cont[a];
				}

				karar = 0;
				for(a = 0; a <= i; a++)
				{
					for(j = 0; j < t; j++)
					{
						if(strcmp(cont[a].name,dest[j]) == 0)
							karar = 1;
					}
					if(karar == 0)
					{
						cont2[a].area = 0;
					}
					else karar = 0;
				}
			
			max = cont2[0].area;
			indexOfMax = 0;
			for(a = 0; a<= i; a++)
			{
				if(max < cont2[a].area)
				{
					max = cont2[a].area;
					indexOfMax = a;
				}
			}
			printf("%s\n",cont[indexOfMax].name);
			}
		}
		/*Calculates and prints how many people at minimum should be seen if 
		I need to go from a given country to another given country (Assume that 
		if I visit a country, I would see all people of that country). If the 
		target country is inaccessible then print INACCESSIBLE.*/
		if(choice == 'd')
		{
			scanf("%s %s", sourceCont, targetCont);
			
			if(indexFind(cont, sourceCont,i) == -1 || 
			indexFind(cont, targetCont, i) == -1)
			{
				printf("INACCESSIBLE\n");
			}
			else
			{
				karar = 0;
				indexOfSource = indexFind(cont,sourceCont,i);
				indexOfTarget = indexFind(cont,targetCont,i);
				for(a=0; a<10; a++)
				{
					if(strcmp(cont[indexOfSource].neighborContries[a],
					cont[indexOfTarget].name) == 0)
						karar = 1;
				}
				if(karar==1) 
				{
					printf("%d", cont[indexOfSource].population + 
					cont[indexOfTarget].population );
				}
				else
				{
					printf("%d", findMinPop(cont, indexOfSource, indexOfTarget, 
					i));				
				}
			}
		}
	/*Exit the program (Presses key ‘e’)*/
	}while(choice != 'e');

	printf("Good Bye");
	return 0;
} /*main sonu*/

/*	Str stringini cont tipindeki struct icinde buldugu indexi donduren fonk	 */
int indexFind(contriesT* cont, char* str,int i)
{
	int a;
	for(a = 0; a <= i; a++)
	{
		if(strcmp(cont[a].name, str)==0)
			return a;
	}
	return -1;
} /*indexFind fonk sonu*/

/*	Hedefe ulasabilirse komsu ulkeler uzerinden gorulen total insan sayisini */
/* toplayan fonksiyon														 */
int findMinPop(contriesT* cont, int source, int target, int i)
{
	int min;
	int a, j;
	/*son asama*/
	if(strcmp(cont[source].name, cont[target].name) ==0)
	{
		return cont[target].population;
	}
	else 
	{
		for(a = 0; a <= i; a++)
			for(j = 0; j < 10; j++)
			{
				if(strcmp(cont[a].neighborContries[j],cont[source].name)==0)
				{
					min = cont[source].population + 
					findMinPop(cont, a, target, i);
					j = 10;
					a = i + 1;
				}
			}
	}
	
	return min;

} /*findMinPop fonk sonu*/
/*###########################################################################*/
/*			End of HW09_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
