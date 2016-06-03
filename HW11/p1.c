/*###########################################################################*/
/*HW11_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 14/05/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*	Program that takes a binary filename and output array parameter and      */
/*returns the decoded data structure. Data structure have max 11 data type 	 */
/*with double avg, we dont know that how set in type.						 */
/*									    									 */
/*Inputs:								 								     */
/*	-Bin input file				 											 */
/*Outputs:																	 */
/*	-														               	 */
/*___________________________________________________________________________*/
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define MAX_DATA 10 /*avg haric*/
#define ZERO 0
#define ONE 1
#define BEGINNING -1
#define TOTAL_RECORDS 1000 /* total records in binary file */
#define NOFDATATYPE 5 /* number of data type */

/*byte of given data type*/
#define CHAR 1
#define INT 4
#define FLOAT 4
#define DOUBLE 8
#define LONGLONGINT 8

#pragma pack(1)
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* int hwDecode(const char filename[], int arr_out[] )	              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 0 > success 																 */
/* 1 > If input file is not exist	    									 */
/* Description																 */
/* ----------- 																 */
/*																		     */
/* binary dosyandaki struct elemanlarini cozumleyen ve arr_out arrayini 	 */
/*asagidaki return degerlerine gore doldurur. Maksimum 10 eleman bulunur	 */
/*																			 */
/*			c >> char >> 1													 */
/*			i >> int >> 2													 */
/*			f >> float >> 4													 */
/*			d >> double >> 5												 */
/*			l >> long long int >> 3											 */
/*																			 */
/*---------------------------------------------------------------------------*/
int hwDecode(const char filename[], int arr_out[] );
/*---------------------------------------------------------------------------*/
/* int byteOfData(int number)   						              	     */
/* -----------																 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*
	0 dan 5 e kadar gonderilen sayilara gore, data tiplerinin byte cinsinden 
	degerini return eder
	
	bu degerlere gore define edilmistir
	
	number 			 	 tip  			  byte
	______ 			 	 ___ 			  ____
	  0 		>> 		 char		   >>  1
	  1		    >>	 	 int  		   >>  4
	  2 		>> 		 float		   >>  4
	  3 		>>	     doulbe 	   >>  8
	  4 		>> 		 long long int >>  8
	  
*/
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int byteOfData(int number);
/*---------------------------------------------------------------------------*/
/* const char* byteOfSymbol(int number) 				              	     */
/* -----------																 */
/*									    									 */
/*
	Gonderilen sayiya gore sadece 1 karakter (data tiplerinin sembolleri) 
	iceren string return eder
	number 			 tip  	
	______           ___
	0 		>> 		 char			"c"
	1		>>	 	 int  			"i"
	2 		>> 		 float		    "d"
	3 		>>	     doulbe 	    "d"
	4 		>> 		 long long int  "l"
*/
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
const char* byteOfSymbol(int number);
/*---------------------------------------------------------------------------*/
/* int symbolToReturnValue(char dataTypeSymbol)			              	     */
/* -----------																 */
/*									    									 */
/*
		data tiplerinin sembolleri
			c >> char >> 1
			i >> int >> 2
			f >> float >> 4
			d >> double >> 5
			l >> long long int >> 3	
		yukaridaki sembollere gore yanlarindaki return degerlerini return eder
*/
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int symbolToReturnValue(char dataTypeSymbol);
/*---------------------------------------------------------------------------*/
/* void fillToArrayAllPossibility(int *index,const int byteOfOneLine,        */
/*                                 char **superposition)					 */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* -								 										 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*
	1 den 10 haneli olasiliklar icin superposition arrayini dolduran fonksiyon
	hane sayiisi kadar loop ile 
	
	her loop 0 dan 5 e kadar doner, rakamlarin temsil degeri su sekildedir
	0 		>> 		 char
	1		>>	 	 int  
	2 		>> 		 float
	3 		>>	     doulbe
	4 		>> 		 long long int 
	
	rakamin temsil degerine gore byteOfSymbol fonksiyonu ile data tipinin 
	sembolune erisilik ve superposition arrayinin icine yazilir
	
*/
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void fillToArrayAllPossibility(int *index,const int byteOfOneLine, 
							   char **superposition);


int main()

{
	int str[10];
/*
	FILE*outp;
	
	char v1='a';
	float v2=3.5;
	double v3=4.5;
	int v4=1;
	long long int v5=1;
	int i;
	double avg;

	avg = ((double)v1+ v2 + v3 + (double)v4)/4;

	outp = fopen("out.bin","wb");

	for(i=0;i<TOTAL_RECORDS; i++){
	
		fwrite(&v1,sizeof(char),1,outp);
		fwrite(&v2,sizeof(float),1,outp);
		fwrite(&v3,sizeof(double),1,outp);
		fwrite(&v4,sizeof(int),1,outp);
		fwrite(&avg,sizeof(double),1,outp);
}


	fclose(outp);*/
	/*fwrite(&v1,sizeof(char),1,outp);
		fwrite(&v2,sizeof(float),1,outp);
	fwrite(&v3,sizeof(double),1,outp);
	fwrite(&v4,sizeof(int),1,outp);*/

	hwDecode("test.bin",str);
	return 0;
}

/*___________________________________________________________________________*/
/*
binary dosyandaki struct elemanlarini cozumleyen ve arr_out arrayini asagidaki 
return degerlerine gore doldurur. Maksimum 10 eleman bulunur

			c >> char >> 1
			i >> int >> 2
			f >> float >> 4
			d >> double >> 5
			l >> long long int >> 3	
*/
int hwDecode(const char filename[], int arr_out[] )
{

	FILE *inp;
	/*dosyanin toplam boyutu byte cinsinden*/
	int totalByte;
	
	/*eslesen ilk data tipleri icin deneme esnasinda dosya sonuna gelip 
	gelinmedigini test etmek icin kullanilir */
	int totalByte2;
	
	/*avg haric 1 struct data total boyutu*/
	int byteOfOneLine;
	
	/*  **superposition >> byteOFOneLine a gore olusabilecek tum olasiliklar 
	bu iki boyutlu arraya doldurulur*/
	char **superposition; 
	
	
	int i, j, k;  /*loop control variables*/
	int index = ZERO; /*byteOfOneLine a gore olusabilecek tum durumlarin sayisi*/
	
	/*okuma esnasinda okunan degeri avg ile karsilastirmada kullanilan 
	degiskenler*/
	double byteComp, byteComp2;
	
	double count; /*1 struct icindeki veri sayisi*/
	
	/*avg > dosyadaki tekrar eden data typelerinin ortalamasi 
	(char tiplerinin int degeri)*/
	double avg; 
	int flag; /*dongu durdurma degiskeni*/
	
	/*bulunan eslesmeyi tum bin dosyasinda test etmede kullanilan degiskenler*/
	char v1;
	int v2;
	float v3;
	double v4;
	long long int v5;

	/*dosya acma*/
	inp = fopen(filename, "rb");

	/*dosya null degilse islem yapilsin, null ise -1 return ile cikis*/
	if( inp == NULL ) 
	{
		return -1;
    }
	else{
   		/*arrayi baslangicta -1 ile doldurma*/
		for(i = ZERO; i < MAX_DATA; i++)
			arr_out[i] = BEGINNING;

		/*dosya sonuna ilerledik*/
		fseek(inp, ZERO, SEEK_END);
		/*dosyanin toplam boyutu byte cinsinden*/
		totalByte = ftell(inp);

		/* 1 data setinin toplam boyutu byte cinsinden- avg haric*/
		byteOfOneLine = totalByte / TOTAL_RECORDS - sizeof(double);
		/*dosya basina geriledik*/
		rewind(inp);
		
		/*
		max cift boyutlu array icin yer ayirdik
		max 5^10 ihtimal oldugu icin ona gore yer ayrilmali
		*/
		superposition = (char**) 
						malloc(sizeof(char*) * pow(NOFDATATYPE, MAX_DATA));
						
		for(i = ZERO; i < (int) pow(NOFDATATYPE, MAX_DATA); i++)
		{
			superposition[i] = (char *) malloc(MAX_DATA * sizeof(char));		
		}
		
		/*byteOfOneLine a gore superposition arrayini dolduran fonk*/
		fillToArrayAllPossibility(&index, byteOfOneLine, &(*superposition));
		

/*Dosyadaki avg haric bir struct boyutundaki tum olasiliklari ekrana basar*/
#ifdef DEBUG1
		printf("%d\n",index);
		for(i = ZERO; i < index; i++)
			printf("%s\n", superposition[i]);
#endif  	
		/*
		data tiplerinin sembolleri
			c >> char
			i >> int
			f >> float
			d >> double
			l >> long long int		
		*/

		/*ici doldurulmus superposition arrayinin icinde c, i, f , l, d 
		harflerinin bulunmasina gore o satirin avg si ile okunan degerin 
		avgsi karsilastirilir, eger esit ise 1000 satirlik dosya icin de 
		saglaniyor mu diye kontrol edilir */
		flag = ZERO; /*initializing*/
		for(j = ZERO; j < index && !flag; j++)
		{
			flag = ZERO; /*initializing*/
			byteComp = (double) ZERO; /*initializing*/
			byteComp2 = (double) ZERO; /*initializing*/
			count = (double)  ZERO; /*initializing*/

			for(i = ZERO; i < MAX_DATA; i++)
			{
				if(superposition[j][i] == 'c')
				{
					fread(&v1, sizeof(char), ONE, inp);
					byteComp += (int)v1;
					count++;
				}
				if(superposition[j][i] == 'i')
				{
					fread(&v2, sizeof(int), ONE, inp);
					byteComp += (double) v2;
					count++;
				}
				if(superposition[j][i] == 'f')
				{
					fread(&v3, sizeof(float), ONE, inp);
					byteComp += v3;
					count++;
				}
				if(superposition[j][i] == 'd')
				{
					fread(&v4, sizeof(double), ONE, inp);
					byteComp += v4;
					count++;
				}
				if(superposition[j][i] == 'l')
				{
					fread(&v5, sizeof(long long int), ONE, inp);
					byteComp += (double)v5;
					count++;
				}
			}

			byteComp /= count;
			fread(&avg, sizeof(double), ONE,inp);
			
			rewind(inp); /*okuma pointerini en basa cekme*/
						

			if(avg == byteComp) {

				do{

					count = ZERO;
					byteComp2 = ZERO;
					for(i = ZERO; i <  MAX_DATA; i++)
					{
						if(superposition[j][i] == 'c')
						{
							fread(&v1, sizeof(char), ONE, inp);
							byteComp2 += (int)v1;
							count++;
						}
						if(superposition[j][i] == 'i')
						{
							fread(&v2, sizeof(int), ONE, inp);
							byteComp2 += (double)v2;
							count++;
						}
						if(superposition[j][i] == 'f')
						{
							fread(&v3, sizeof(float), ONE, inp);
							byteComp2 += v3;
							count++;
						}
						if(superposition[j][i] == 'd')
						{
							fread(&v4, sizeof(double), ONE,inp);
							byteComp2 += v4;
							count++;
						}
						if(superposition[j][i] == 'l')
						{
							fread(&v5, sizeof(long long int), ONE, inp);
							byteComp2 += (double)v5;
							count++;
						}
					}
					
				fread(&avg, sizeof(double), ONE, inp);
				byteComp2 /= count ;

				if(byteComp2 != avg) 
					flag = ZERO;		
				else 
					flag = ONE;
				
				/*okuma pointerinin yerini kontrol*/
				totalByte2 = ftell(inp);
				
				}while(totalByte2 <= totalByte && !flag);
			}
				
			rewind(inp); /*pointeri tekrardan en basa alma */
		}
		/*dosyayi kapatma*/
		fclose(inp);

			/*bu asamada superposition arrayinde hangi indexdeki durum 
			dosyadaki siralama ile uyustugunu biliyoruz, bu index uzerinden 
			gecerek her data tipi icin belirlenmis olan return degerlerini 
			arr_out arrayine dolduruyoruz*/
			i = ZERO; 
			for(k = ZERO; k <  MAX_DATA; k++)
			{
				/*j-1 olmasinin sebebi flag kontrolu sirasinda fazladan 
				j'nin arttirilmasi
				olasi tum durumlarin tutuldugu yerde butun dosyayi saglayan 
				tek durum j-1. indextir
				*/
				if(symbolToReturnValue(superposition[j-1][k]) != -1){
					arr_out[i] = symbolToReturnValue(superposition[j-1][k]);
					i++;
				}
			}

/*arr_out arrayinin icini ekrana basar*/
#ifdef DEBUG2
	for(k = ZERO; k <  MAX_DATA; k++)
	{
		printf("%d ",arr_out[k]);
	}
	printf("\n");
#endif

	}
	return 0; /*success*/
} /*end of hwDecode func */
/*___________________________________________________________________________*/
/*
	1 den 10 haneli olasiliklar icin superposition arrayini dolduran fonksiyon
	hane sayiisi kadar loop ile 
	
	her loop 0 dan 5 e kadar doner, rakamlarin temsil degeri su sekildedir
	0 		>> 		 char
	1		>>	 	 int  
	2 		>> 		 float
	3 		>>	     doulbe
	4 		>> 		 long long int 
	
	rakamin temsil degerine gore byteOfSymbol fonksiyonu ile data tipinin 
	sembolune erisilik ve superposition arrayinin icine yazilir
	
*/
void fillToArrayAllPossibility(int *index,const int byteOfOneLine, 
	                           char **superposition)
{
	int i,j,k,l,m,n,o,p,q,r; /*loop control variables*/
	/*byteOfData fonksiyonu ile her donuste toplam byte hesaplanir ve 
	gercekteki byte degerine es mi diye kontrol edilir.*/
	int denemeTotal = ZERO; 
	
	/*sadece 1 haneli ihtimaller icin */
	for(r = ZERO; r < NOFDATATYPE; r++)
	{
		denemeTotal = byteOfData(r);

		if(denemeTotal == byteOfOneLine )
		{
			strcpy(superposition[*index], byteOfSymbol(r));
			(*index)++;
		}
	}
	
	/*sadece 2 haneli ihtimaller icin*/
	for(q = ZERO; q < NOFDATATYPE; q++)
	{
		for(r = ZERO; r < NOFDATATYPE; r++)
		{
			denemeTotal = byteOfData(r) + byteOfData(q);
			
			if(denemeTotal == byteOfOneLine)
			{
				strcpy(superposition[*index], byteOfSymbol(r));
				strcat(superposition[*index], byteOfSymbol(q));
				(*index)++;
			}
		}
	}

	/*sadece 3 haneli ihtimaller icin*/
	for(p = ZERO; p < NOFDATATYPE; p++)
	{
		for(q = ZERO; q < NOFDATATYPE; q++)
		{
			for(r = ZERO; r < NOFDATATYPE; r++)
			{
				denemeTotal = byteOfData(r) + byteOfData(q) + byteOfData(p);
				
			if(denemeTotal == byteOfOneLine)
			{
				strcpy(superposition[*index], byteOfSymbol(r));
				strcat(superposition[*index], byteOfSymbol(q));
				strcat(superposition[*index], byteOfSymbol(p));
				(*index)++;
			}
			}
		}
	}
	/*sadece 4 haneli ihtimaller icin*/	
	for(o = ZERO; o < NOFDATATYPE; o++)
	{
		for(p = ZERO; p < NOFDATATYPE; p++)
		{
			for(q = ZERO; q < NOFDATATYPE; q++)
			{
				for(r = ZERO; r < NOFDATATYPE; r++)
				{
					denemeTotal = byteOfData(r) + byteOfData(q) + byteOfData(p) 
					+ byteOfData(o);
				
				if(denemeTotal == byteOfOneLine)
				{
					strcpy(superposition[*index], byteOfSymbol(r));
					strcat(superposition[*index], byteOfSymbol(q));
					strcat(superposition[*index], byteOfSymbol(p));
					strcat(superposition[*index], byteOfSymbol(o));
					(*index)++;
				}
				}
			}
		}
	}
	/*sadece 5 haneli ihtimaller icin*/
	for(n = ZERO; n < NOFDATATYPE; n++)
	{
		for(o = ZERO; o < NOFDATATYPE; o++)
		{
			for(p = ZERO; p < NOFDATATYPE; p++)
			{
				for(q = ZERO; q < NOFDATATYPE; q++)
				{
					for(r = ZERO; r < NOFDATATYPE; r++)
					{
						denemeTotal = byteOfData(r) + byteOfData(q) + 
						byteOfData(p) + byteOfData(o) + byteOfData(n);
				
					if(denemeTotal == byteOfOneLine)
					{
						strcpy(superposition[*index], byteOfSymbol(r));
						strcat(superposition[*index], byteOfSymbol(q));
						strcat(superposition[*index], byteOfSymbol(p));
						strcat(superposition[*index], byteOfSymbol(o));
						strcat(superposition[*index], byteOfSymbol(n));
						(*index)++;
					}
					}
				}
			}
		}
	}
	/*sadece 6 haneli ihtimaller icin*/
	for(m = ZERO; m < NOFDATATYPE; m++)
	{
		for(n = ZERO; n < NOFDATATYPE; n++)
		{
			for(o = ZERO; o < NOFDATATYPE; o++)
			{
				for(p = ZERO; p < NOFDATATYPE; p++)
				{
					for(q = ZERO; q < NOFDATATYPE; q++)
					{
						for(r = ZERO; r < NOFDATATYPE; r++)
						{
							denemeTotal = byteOfData(r) + byteOfData(q) + 
							byteOfData(p) + byteOfData(o) + byteOfData(n) + 
							byteOfData(m);
				
						if(denemeTotal == byteOfOneLine)
						{
							strcpy(superposition[*index], byteOfSymbol(r));
							strcat(superposition[*index], byteOfSymbol(q));
							strcat(superposition[*index], byteOfSymbol(p));
							strcat(superposition[*index], byteOfSymbol(o));
							strcat(superposition[*index], byteOfSymbol(n));
							strcat(superposition[*index], byteOfSymbol(m));
							(*index)++;
						}
						}
					}
				}
			}
		}
	}
	/*sadece 7 haneli ihtimaller icin*/
	for(l = ZERO; l < NOFDATATYPE; l++)
	{
		for(m = ZERO; m < NOFDATATYPE; m++)
		{
			for(n = ZERO; n < NOFDATATYPE; n++)
			{
				for(o = ZERO; o < NOFDATATYPE; o++)
				{
					for(p = ZERO; p < NOFDATATYPE; p++)
					{
						for(q = ZERO; q < NOFDATATYPE; q++)
						{
							for(r = ZERO; r < NOFDATATYPE; r++)
							{
								denemeTotal = byteOfData(r) + byteOfData(q) +
								 byteOfData(p) + byteOfData(o) + byteOfData(n) 
								 + byteOfData(m) + byteOfData(l);
				
							if(denemeTotal == byteOfOneLine)
							{
								strcpy(superposition[*index], byteOfSymbol(r));
								strcat(superposition[*index], byteOfSymbol(q));
								strcat(superposition[*index], byteOfSymbol(p));
								strcat(superposition[*index], byteOfSymbol(o));
								strcat(superposition[*index], byteOfSymbol(n));
								strcat(superposition[*index], byteOfSymbol(m));
								strcat(superposition[*index], byteOfSymbol(l));
								(*index)++;
							}
							}
						}
					}
				}
			}
		}
	}
	/*sadece 8 haneli ihtimaller icin*/
	for(k = ZERO; k < NOFDATATYPE; k++)
	{
		for(l = ZERO; l < NOFDATATYPE; l++)
		{
			for(m = ZERO; m < NOFDATATYPE; m++)
			{
				for(n = ZERO; n < NOFDATATYPE; n++)
				{
					for(o = ZERO; o < NOFDATATYPE; o++)
					{
						for(p = ZERO; p < NOFDATATYPE; p++)
						{
							for(q = ZERO; q < NOFDATATYPE; q++)
							{
								for(r = ZERO; r < NOFDATATYPE; r++)
								{
									denemeTotal = byteOfData(r) + byteOfData(q) 
									+ byteOfData(p) + byteOfData(o) + 
									byteOfData(n) + byteOfData(m) + 
									byteOfData(l) + byteOfData(k);
				
								if(denemeTotal == byteOfOneLine)
								{
									strcpy(superposition[*index],
									byteOfSymbol(r));
									strcat(superposition[*index],
									byteOfSymbol(q));
									strcat(superposition[*index],
									byteOfSymbol(p));
									strcat(superposition[*index],
									byteOfSymbol(o));
									strcat(superposition[*index],
									byteOfSymbol(n));
									strcat(superposition[*index],
									byteOfSymbol(m));
									strcat(superposition[*index],
									byteOfSymbol(l));
									strcat(superposition[*index],
									byteOfSymbol(k));
									(*index)++;
								}
								}
							}
						}
					}
				}
			}
		}
	}
	/*sadece 9 haneli ihtimaller icin*/
	for(j = ZERO; j < NOFDATATYPE; j++)
	{
		for(k = ZERO; k < NOFDATATYPE; k++)
		{
			for(l = ZERO; l < NOFDATATYPE; l++)
			{
				for(m = ZERO; m < NOFDATATYPE; m++)
				{
					for(n = ZERO; n < NOFDATATYPE; n++)
					{
						for(o = ZERO; o < NOFDATATYPE; o++)
						{
							for(p = ZERO; p < NOFDATATYPE; p++)
							{
								for(q = ZERO; q < NOFDATATYPE; q++)
								{
									for(r = ZERO; r < NOFDATATYPE; r++)
									{
										denemeTotal = byteOfData(r) + 
										byteOfData(q) + byteOfData(p) + 
										byteOfData(o) + byteOfData(n) + 
										byteOfData(m) + byteOfData(l) + 
										byteOfData(k) + byteOfData(j);
				
									if(denemeTotal == byteOfOneLine)
									{
										strcpy(superposition[*index],
										byteOfSymbol(r));
										strcat(superposition[*index],
										byteOfSymbol(q));
										strcat(superposition[*index],
										byteOfSymbol(p));
										strcat(superposition[*index],
										byteOfSymbol(o));
										strcat(superposition[*index],
										byteOfSymbol(n));
										strcat(superposition[*index],
										byteOfSymbol(m));
										strcat(superposition[*index],
										byteOfSymbol(l));
										strcat(superposition[*index],
										byteOfSymbol(k));
										strcat(superposition[*index],
										byteOfSymbol(j));
										(*index)++;
									}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	/*sadece 10 haneli ihtimaller icin*/
	for(i = ZERO; i < NOFDATATYPE; i++)
	{
		for(j = ZERO; j < NOFDATATYPE; j++)
		{
			for(k = ZERO; k < NOFDATATYPE; k++)
			{
				for(l = ZERO; l < NOFDATATYPE; l++)
				{
					for(m = ZERO; m < NOFDATATYPE; m++)
					{
						for(n = ZERO; n < NOFDATATYPE; n++)
						{
							for(o = ZERO; o < NOFDATATYPE; o++)
							{
								for(p = ZERO; p < NOFDATATYPE; p++)
								{
									for(q = ZERO; q < NOFDATATYPE; q++)
									{
										for(r = ZERO; r < NOFDATATYPE; r++)
										{
											denemeTotal = byteOfData(r) + 
											byteOfData(q) + byteOfData(p) + 
											byteOfData(o) + byteOfData(n) + 
											byteOfData(m) + byteOfData(l) + 
											byteOfData(k) + byteOfData(j) + 
											byteOfData(i);
				
										if(denemeTotal == byteOfOneLine)
										{
											strcpy(superposition[*index],
											byteOfSymbol(r));
											strcat(superposition[*index],
											byteOfSymbol(q));
											strcat(superposition[*index],
											byteOfSymbol(p));
											strcat(superposition[*index],
											byteOfSymbol(o));
											strcat(superposition[*index],
											byteOfSymbol(n));
											strcat(superposition[*index],
											byteOfSymbol(m));
											strcat(superposition[*index],
											byteOfSymbol(l));
											strcat(superposition[*index],
											byteOfSymbol(k));
											strcat(superposition[*index],
											byteOfSymbol(j));
											strcat(superposition[*index],
											byteOfSymbol(i));
											(*index)++;
										}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

} /* end of fillToArrayAllPossibility func */
 
/*___________________________________________________________________________*/
/*
	0 dan 5 e kadar gonderilen sayilara gore, data tiplerinin byte cinsinden 
	degerini return eder
	
	bu degerlere gore define edilmistir
	
	number 			 	 tip  			  byte
	______ 			 	 ___ 			  ____
	  0 		>> 		 char		   >>  1
	  1		    >>	 	 int  		   >>  4
	  2 		>> 		 float		   >>  4
	  3 		>>	     doulbe 	   >>  8
	  4 		>> 		 long long int >>  8  
*/
int byteOfData(int number)
{
	int result;
	
	if(number == 0) result = CHAR;
	if(number == 1) result = INT;
	if(number == 2) result = FLOAT;
	if(number == 3) result = DOUBLE;
	if(number == 4) result = LONGLONGINT;

	return result;
} /* end of byteOfData func */

/*___________________________________________________________________________*/
/*
	Gonderilen sayiya gore sadece 1 karakter (data tiplerinin sembolleri) 
	iceren string return eder
	number 			 tip  	
	______           ___
	0 		>> 		 char			"c"
	1		>>	 	 int  			"i"
	2 		>> 		 float		    "d"
	3 		>>	     doulbe 	    "d"
	4 		>> 		 long long int  "l"
*/
const char* byteOfSymbol(int number)
{	
	if(number == 0) return "c";
	else if(number == 1) return "i";
	else if(number == 2) return "f";
	else if(number == 3) return "d";
	else return "l"; 
} /* end of byteOfSymbol func */
/*___________________________________________________________________________*/
/*
		data tiplerinin sembolleri
			c >> char >> 1
			i >> int >> 2
			f >> float >> 4
			d >> double >> 5
			l >> long long int >> 3	
		yukaridaki sembollere gore yanlarindaki return degerlerini return eder
*/
int symbolToReturnValue(char dataTypeSymbol)
{
	if(dataTypeSymbol=='c') return 1;
	else if(dataTypeSymbol=='i') return 2;
	else if(dataTypeSymbol=='l') return 3;
	else if(dataTypeSymbol=='f') return 4;
	else if(dataTypeSymbol=='d') return 5;	
	else return -1; /*istenilenden baska bir karakter gonderilmesi durumunda */
} /* end of symbolToReturnValue func */
/*###########################################################################*/
/*			End of HW11_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
