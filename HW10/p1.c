/*###########################################################################*/
/*HW10_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 2/5/2016 by Muhammed_Selim_Dursun							     */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*	Program that simple database management system which reads information   */
/* about a department in a university such as students, lectures, and        */
/*professors and outputs a file which includes some summary information      */
/*									    									 */
/*Inputs:								 								     */
/*	-input.dat = binary file												 */
/*Outputs:																	 */
/*	-output.txt = txt file   	 							               	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define MAX_STRING_SIZE 30
#define MAX_STUDENT 20
#define MAX_DAY 7
#define MAX_DAY_LENGT 10
#define ZERO 0
#define ONE 1
/*---------------------------------------------------------------------------*/
/*                               Typedefs                                    */
/*---------------------------------------------------------------------------*/
typedef struct student 
{
	int id;
	char name[MAX_STRING_SIZE];
	char surname[MAX_STRING_SIZE];
} studentT;

typedef struct lecturers
{
	char degree[MAX_STRING_SIZE];
	int id;
	char name[MAX_STRING_SIZE];
	char surname[MAX_STRING_SIZE];
} lecturersT;

typedef struct lectures
{
	int code;
	char name[MAX_STRING_SIZE];
	int id; 
} lecturesT;

typedef struct schedule
{
	char classroomName[MAX_STRING_SIZE];
	char day[MAX_STRING_SIZE];
	int startTime;
	int lectureDuration;
	int code;
} scheduleT;

typedef struct course
{
	int id;
	int code;
} courseT;
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* int lectureTeacherFinder(int n,lecturersT *lecturers, int id)       	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* Result - id degiskeninin struct arrayindaki indexi						 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*lecturersT tipindeki struct icinde id degiskeninin indexini bulan fonksiyon*/
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int lectureTeacherFinder(int n,lecturersT *lecturers, int id);
/*---------------------------------------------------------------------------*/
/* int countOfTeacherLecture(int n, courseT *course, int code)       	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* count - code degiskeninin struct arrayindaki sayisi						 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*courseT tipindeki struct icinde code degiskeninin sayisini bulan fonksiyon */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int countOfTeacherLecture(int n, courseT *course, int code);
/*---------------------------------------------------------------------------*/
/* int countOfStudentLecture(int n, courseT *course, int id)         	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* count -  id degiskeninin struct arrayindaki sayisi						 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/*courseT tipindeki struct icinde id degiskeninin sayisini bulan fonksiyon   */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int countOfStudentLecture(int n, courseT *course, int id);


int main()
{
	int n1, n2, n3, n4, n5;  /*5 farkli veri tipi icin, veri tipi sayisi*/
	int a, b, c, d, e ; /*loop control variables*/
	int index;
	/*text'e verileri girerken ayni gunu 2 kere girmemek icin kullanilen 
	degisken */
	int flag; 

	FILE *inp, *outp; /*file pointers*/
	
	studentT student[MAX_STUDENT];
	lecturersT lecturers[MAX_STUDENT];
	lecturesT lectures[MAX_STUDENT];
	scheduleT schedule[MAX_STUDENT];
	courseT course[MAX_STUDENT];
	/*bireyin hangi gun dersleri var ise o gunleri barindiracak string*/
	char day[MAX_DAY][MAX_DAY_LENGT];
	
	inp = fopen("input.dat","rb");
	outp = fopen("output.txt","w");
	/*dosya eger null ise, program islem yapmadan sonlanmali*/
	if(inp == NULL){
		return 1;
	}
	else 
	{
		/*binary dosyadan, struct'a veri okuma */
		fread(&n1,sizeof(int),ONE,inp);
		for(a = ZERO; a < n1; a++)
		{
			fread(&student[a],sizeof(studentT),ONE,inp);		
		}
		fread(&n2,sizeof(int),ONE,inp);
		for(a = ZERO; a < n2; a++)
		{
			fread(&lecturers[a],sizeof(lecturersT),ONE,inp);		
		}
		fread(&n3,sizeof(int),ONE,inp);		
		for(a = ZERO; a < n3; a++)
		{
			fread(&lectures[a],sizeof(lecturesT),ONE,inp);		
		}
		fread(&n4,sizeof(int),ONE,inp);		
		for(a = ZERO; a<n4; a++)
		{
			fread(&schedule[a],sizeof(scheduleT),ONE,inp);		
		}		
		fread(&n5,sizeof(int),ONE,inp);		
		for(a = ZERO; a < n5; a++)
		{
			fread(&course[a],sizeof(courseT),ONE,inp);		
		}
			
			
		/*okunan verilerin ekrandan kontrolu*/	
#ifdef DEBUG
		for(a = ZERO; a<n1; a++)
		{
			printf("%d %s %s\n",student[a].id, student[a].name, 
			student[a].surname);	
		}
		for(a = ZERO; a<n2; a++)
		{
			printf("%s %d %s %s\n",lecturers[a].degree,lecturers[a].id, 
			lecturers[a].name, lecturers[a].surname);	
		}
		for(a = ZERO; a<n3; a++)
		{
			printf("%d %s %d\n",lectures[a].code, lectures[a].name, 
			lectures[a].id);	
		}
		for(a = ZERO; a<n4; a++)
		{
			printf("%s %s %d %d %d\n",schedule[a].classroomName, 
			schedule[a].day, schedule[a].startTime, 
			schedule[a].lectureDuration, schedule[a].code);	
		}
		for(a = ZERO; a<n5; a++)
		{
			printf("%d %d\n",course[a].id, course[a].code);	
		}
#endif
			
		/*file'a verileri yazma*/
		fprintf(outp, "Lecture-Lecturer\n");
		for(a = ZERO; a < n3; a++){
			
			index = lectureTeacherFinder(n2, lecturers, lectures[a].id);
			
			fprintf(outp, "%s %s %s %d\n",lectures[a].name, 
			lecturers[index].name, lecturers[index].surname, 
			countOfTeacherLecture(n5,course,lectures[a].code));
		}

		fprintf(outp,"\nStudent-Lecture\n");	
		for(a = ZERO; a < n1; a++)
		{
			fprintf(outp,"%d %s %s %d\n", student[a].id, student[a].name, 
			student[a].surname, 
			countOfStudentLecture(n5, course, student[a].id));
		}

		fprintf(outp, "\nStudent-Day\n");
		for(a = ZERO; a < n1; a++){
			/*day arrayinin icini bosaltma*/
			for(b = ZERO; b < MAX_DAY; b++)
				for(c = ZERO; c < MAX_DAY_LENGT; c++)
					strcpy(&day[b][c],"\0");
					
			fprintf(outp,"%d %s %s ", student[a].id, student[a].name, 
			student[a].surname);
			/*ogrencinin dersinin oldugu gunleri arraye doldurup sonra ise 
			arrayden dosyaya yazma islemleri*/
			d = ZERO;
			flag = ZERO;
			for(b = ZERO; b < n5; b++)
			{
				if(student[a].id == course[b].id)
				{
					for(c = ZERO; c < n4; c++)
					{
						if(course[b].code == schedule[c].code)
						{
							/*bulunan day, arrayde yoksa arraye yeni 
							veri kopyalanacak*/
							for(e = ZERO; e < MAX_DAY; e++)
							{
								if(!strcmp(schedule[c].day, day[e]))
									flag = ONE;
							}
								if(flag != ONE){
									strcpy(day[d],schedule[c].day);
									d++;
									flag = ZERO;	
								}							
						}
					}
				}
			}
			/*array icideki gunleri dosyaya satir sonuna yazdirma*/
			for(c = ZERO; c < d; c++){
				fprintf(outp,"%s", day[c]);
				if(c!=d-ONE) fprintf(outp,", ");
			}
			fprintf(outp,"\n");
		}
	}
	/*acilan dosyalari kapatma*/
	fclose(outp);
	fclose(inp);
	
	return 0;
} /*end of main*/

/*lecturersT tipindeki struct icinde id degiskeninin indexini bulan fonksiyon*/
int lectureTeacherFinder(int n, lecturersT *lecturers, int id)
{
	int a, result;
	for(a = ZERO; a < n; a++)
	{
		if(lecturers[a].id == id)
			result = a;
	}
	return result;
} /*end of lectureTeacherFinder func*/

/*courseT tipindeki struct icinde code degiskeninin sayisini bulan fonksiyon */
int countOfTeacherLecture(int n, courseT *course, int code)
{
	int a;
	int count = ZERO;
	for(a = ZERO; a < n; a++)
	{
		if(course[a].code == code)
			count++;		
	}
	return count;
} /*end of countOfTeacherLecture func */

/*courseT tipindeki struct icinde id degiskeninin sayisini bulan fonksiyon   */
int countOfStudentLecture(int n, courseT *course, int id)
{
	int a;
	int count = ZERO;
	for(a = ZERO; a < n; a++)
	{
		if(course[a].id == id)
			count++;		
	}
	return count;
} /* end of  countOfStudentLecture func */
/*###########################################################################*/
/*			End of HW10_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
