/*###########################################################################*/
/*HW05_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 01/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*	Basit bir satranc hamle kontrol oyunu							 		 */
/*									    									 */
/*Inputs:								 								     */
/*	-Komut:1 initialize board, 2 get input, 3 printf board, 4 exit			 */
/*	-Tas secme : Hangi tasin oynanacagi kordinat bilgisi ( ex a2)			 */
/*	-Tasin kordinat bilgisi 												 */
/*Outputs:																	 */
/*	-Tasin oynanabilirligi yes veya no seklinde ekrana basilmasi           	 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*                               Includes                                    */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------*/
/*                               Typedef                                     */
/*---------------------------------------------------------------------------*/
typedef enum{rook=1, knight, bishop, queen, king, pawn} pieceT;
typedef enum{A1,B1,C1,D1,E1,F1,G1,H1} colT;
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define TOTAL_ROW 8 /* number of frames in a row   */
#define TOTAL_COLUMN 8 /* number of frames in a column   */
#define TOTALSIZE_BOARD 64

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*																			 */
/*---------------------------------------------------------------------------*/
/* void emptyBuffer()									              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	-																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Buffer temizlemede kullanilan fonksiyon 									 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void emptyBuffer();
/*---------------------------------------------------------------------------*/
/* void printBoard(char *board)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	-																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Tahtayi alan kodlari ile beraber ekrana basan fonksiyon				     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void printBoard(char *board);
/*---------------------------------------------------------------------------*/
/* int isPieceMovable(char *board)						              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > tas hedefe oynayabilir, sakinca yok									 */
/* 0 > tas hedefe oynamasi kurallara aykiri									 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* 		oynanacak tasi tespit eder ve valid ise tasi tespit edip,  			 */
/* 	o tasin fonksiyonunu cagirir 											 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isPieceMovable(char *board);
/*---------------------------------------------------------------------------*/
/* void getPosition(char *col, int *row)				              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	 -																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Kullanicidan kordinat degeri okur ve valid ise pointerlere atama yapar    */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void getPosition(char *col, int *row);
/*---------------------------------------------------------------------------*/
/* int isValidCell(char col, int row)										 */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Girilen kordinat valid												 */
/* 0 > Girilen kordinat invalid												 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Girilen inputun tahtanin icinden bir nokta olup olmadini kontrol eden fonk*/
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isValidCell(char col, int row);
/*---------------------------------------------------------------------------*/
/* void initBoard(char *board)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	-																		 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Satranc tahtasini baslangic pozisyonunda arraye tek tek initialize eder   */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
void initBoard(char *board);
/*---------------------------------------------------------------------------*/
/* int whichPiece(const char *board,char col, int row)	              	     */
/* -----------																 */
/*									    									 */
/* Return	(tpypedef türünden return eder)									 */
/* ------																	 */
/* rook(1) > oynanmak istenen tas kale										 */
/* knight(2) > oynanmak istenen tas at										 */
/* bishop(3) > oynanmak istenen tas fil										 */
/* queen(4) > oynanmak istenen tas vezir									 */
/* king(5) > oynanmak istenen tas kral										 */
/* pawn(6) > oynanmak istenen tas piyon										 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Tasin turunu belirleyen fonksiyon  										 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int whichPiece(const char *board,char col, int row);
/*---------------------------------------------------------------------------*/
/* int pieceIsWhere(int row,char col)					              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* point > girilen kordinatin arraydeki yeri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Boarddaki lokasyon hesabinda kullanilan fonksiyon */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int pieceIsWhere(int row,char col);
/*---------------------------------------------------------------------------*/
/* int isRookMovable									              	     */
/*(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)*/
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Tasin hedefe gitmesinde sakinca yok									 */
/* 0 > Tasin hedefe gitmesi kurallara aykiri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Oynanacak tasin kale olmasi durumunda cagirilacak fonksiyon 				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isRookMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/*---------------------------------------------------------------------------*/
/* int isPawnMovable									              	     */
/*(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)*/
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Tasin hedefe gitmesinde sakinca yok									 */
/* 0 > Tasin hedefe gitmesi kurallara aykiri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Oynanacak tasin piyon olmasi durumunda cagirilacak fonksiyon 			 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isPawnMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
/*---------------------------------------------------------------------------*/
/* int isBishopMovable									              	     */
/*(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)*/
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Tasin hedefe gitmesinde sakinca yok									 */
/* 0 > Tasin hedefe gitmesi kurallara aykiri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Oynanacak tasin fil olmasi durumunda cagirilacak fonksiyon				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isBishopMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
/*---------------------------------------------------------------------------*/
/* int isQueenMovable									              	     */
/*(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)*/
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Tasin hedefe gitmesinde sakinca yok									 */
/* 0 > Tasin hedefe gitmesi kurallara aykiri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Oynanacak tasin vezir olmasi durumunda cagirilacak fonksiyon 			 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isQueenMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
/*---------------------------------------------------------------------------*/
/* int isKingMovable									              	     */
/*(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)*/
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Tasin hedefe gitmesinde sakinca yok									 */
/* 0 > Tasin hedefe gitmesi kurallara aykiri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Oynanacak tasin kral olmasi durumunda cagirilacak fonksiyon				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isKingMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
/*---------------------------------------------------------------------------*/
/* int isKnightMovable														 */
/*(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)*/
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 1 > Tasin hedefe gitmesinde sakinca yok									 */
/* 0 > Tasin hedefe gitmesi kurallara aykiri								 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Oynanacak tasin at olmasi durumunda cagirilacak fonksiyon				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);


int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: 
				initBoard(board);
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
				
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}

/* Buffer temizlemede kullanilan fonksiyon 									 */
void emptyBuffer()
{
	while ( getchar() != '\n' );
} /*emptyBuffer fonksiyon sonu*/

/* Satranc tahtasini baslangic pozisyonunda arraye tek tek initialize eder   */
void initBoard(char *board) {

	int i;
	char tempBoard[TOTALSIZE_BOARD] = {'r','n','b','q','k','b','n','r',
			  			 			    'p','p','p','p','p','p','p','p',
			  			 			    ' ',' ',' ',' ',' ',' ',' ',' ',
			  						    ' ',' ',' ',' ',' ',' ',' ',' ',
			  						    ' ',' ',' ',' ',' ',' ',' ',' ',
			  					        ' ',' ',' ',' ',' ',' ',' ',' ',
			  			 			    'P','P','P','P','P','P','P','P',
			  			 			    'R','N','B','Q','K','B','N','R'};

	for(i = 0; i < TOTALSIZE_BOARD; i++){
		board[i] = tempBoard[i];
	}

} /* fillBoard fonksiyon sonu */

/* Tahtayi alan kodlari ile beraber ekrana basan fonksiyon				     */
void printBoard(char *board) {

	int i; /* dongu kontrol degiskeni */	
	int wallNumbers = TOTAL_ROW; 

	printf("  a b c d e f g h\n");
	printf("  - - - - - - - -\n");

	for(i = 0; i < TOTALSIZE_BOARD; i++){

		if(i % 8 == 0) {
			printf("%d|", wallNumbers--);
		}
		if(i % 8 != 0){
			printf(" ");
		}
		printf("%c", board[i]);

		if(i % 8 == 7){
			printf("|\n");
		}

	}

	printf("  - - - - - - - -\n");

} /* printBoard fonksiyon sonu */


/* Girilen inputun tahtanin icinden bir nokta olup olmadini kontrol eden fonk*/
int isValidCell(char col, int row){

	if(col >= 'a' && col <= 'h') {

		if(row >= 1 && row <= 8 ){

			return 1;
		}
	}
	return 0;
} /* isValidCell fonksiyon sonu */

/* Kullanicidan kordinat degeri okur ve valid ise pointerlere atama yapar    */
void getPosition(char *col, int *row){

	char tempCol; 
	int tempRow;

	scanf("%c%d", &tempCol, &tempRow);
	if(isValidCell(tempCol, tempRow) == 1){
		*col = tempCol;	
		*row = tempRow;
	}
} /* getPosition fonksiyon sonu */



/* 		oynanacak tasi tespit eder ve valid ise tasi tespit edip,  			 */
/* 	o tasin fonksiyonunu cagirir 											 */
int isPieceMovable(char *board) {
	char sCol, tCol, empty;
	int sRow, tRow;

	getPosition(&sCol, &sRow); /*Hangi tasin oynanacagi bilgisini alir*/

	if(isValidCell(sCol, sRow)){

		scanf("%c", &empty); /*  For space character */
		
		getPosition(&tCol, &tRow); /*Hedef noktanin adresini alir*/
		
		if(isValidCell(tCol, tRow)){
			/* Tas turleri typdef biciminde tanimlanmistir */
			if(whichPiece(board,sCol,sRow) == rook){
				if(isRookMovable(board, sCol, sRow, tCol, tRow)){

					return 1;
				}
			}

			if(whichPiece(board,sCol,sRow) == knight){
				if(isKnightMovable(board, sCol, sRow, tCol, tRow)){

					return 1;
				}
			}		

			if(whichPiece(board,sCol,sRow) == bishop){
				if(isBishopMovable(board, sCol, sRow, tCol, tRow)){

					return 1;
				}
			}

			if(whichPiece(board,sCol,sRow) == queen){
				if(isQueenMovable(board, sCol, sRow, tCol, tRow)){

					return 1;
				}
			}

			if(whichPiece(board,sCol,sRow) == king){
				if(isKingMovable(board, sCol, sRow, tCol, tRow)){

					return 1;
				}
			}

			if(whichPiece(board,sCol,sRow) == pawn){
				if(isPawnMovable(board, sCol, sRow, tCol, tRow)){

					return 1;
				}
			}
		}
	}

	return 0; /* input eger valid degilse */
}/*isPieceMovable fonksiyon sonu*/

/* Boarddaki lokasyon hesabinda kullanilan fonksiyon */
int pieceIsWhere(int row,char col){
	int determine, 
		point; /* girilen kordinat degerinin boarddaki karsiligi */

/*	 A1,B1,... typedef seklinde tanimlanmistir, bu case'in amaci girilen 	 */
/* colm degerini rakamsal degerine cevirmektir. */
	switch(col)
		{
		case 'a':
			determine = A1;
			break;
		case 'b':
			determine = B1;	
			break;
		case 'c':
			determine = C1;
			break;
		case 'd':
			determine = D1;
			break;
		case 'e':
			determine = E1;
			break;
		case 'f':
			determine = F1;
			break;
		case 'g':
			determine = G1;
			break;
		case 'h':
			determine = H1;
			break;
		}

	point = ((TOTAL_ROW - row ) * TOTAL_COLUMN) + determine;

	return point;
}/*pieceIsWhere fonksiyon sonu*/

/* Tasin turunu belirleyen fonksiyon  										 */
int whichPiece(const char *board,char col, int row){
	
	int currentLocation; /* girilen kordinatin boarddaki yeri  */
	 
	currentLocation =  pieceIsWhere(row, col);

	if(board[currentLocation] == 'r' || board[currentLocation] == 'R' ){
		 return rook; /* means that rook */
	}
	if(board[currentLocation] == 'n' || board[currentLocation] == 'N' ){
		 return knight; /* means that knight */
	}
	if(board[currentLocation] == 'b' || board[currentLocation] == 'B' ){
		 return bishop; /* means that bishop */
	}
	if(board[currentLocation] == 'q' || board[currentLocation] == 'Q' ){
		 return queen; /* means that queen */
	}
	if(board[currentLocation] == 'k' || board[currentLocation] == 'K' ){
		 return king; /* means that king */
	}
	if(board[currentLocation] == 'p' || board[currentLocation] == 'P' ){
		 return pawn; /* means that pawn */
	}
	
	return 0;
} /* whichPiece fonksiyon sonu*/

/* Eger secilen tas at ise bu fonksiyon cagirilacak, bu fonksiyon ise satranc*/
/*kuralinda oldugu gibi L biciminde hareketleri kontrol ediyor 			     */
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	/* hedef ve secilen tasin bulundugu konumun arraydeki yeri */
	int currentBoardPoint, targetBoardPoint;  
	int difference;	/*Hedef ile anlık bulunan nokta arasi fark*/

	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);

	difference = targetBoardPoint - currentBoardPoint;

	/* Kordinat duzleminde 1. bolge */
	if((sourceCol < targetCol) && (sourceRow < targetRow)){  
		/*1. bolgede oynanacak 2 durum var,buda farkin -6 ve-15 olması durumu*/
		if(difference == -6) {
			/*tasimiz hangi renkte ise hedefin zıt renk veya bosluk olması*/
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}
			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}			
		}

		if(difference == -15){
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}

			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}
		}
	} 

	/* Kordinat duzleminde 2. bolge */
	if((sourceCol > targetCol) && (sourceRow < targetRow)){  
		/*2.bolgede oynanacak 2 durum var,buda farkin -17 ve-10 olması durumu*/
		if(difference == -17){
			/*tasimiz hangi renkte ise hedefin zıt renk veya bosluk olması*/
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
							return 1; 
			}
			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
							return 1; 
			}
		} 

		if(difference == -10){
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}

			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}
		}
	}/* 2. bolge if'inin sonu*/
	
	/* Kordinat duzleminde 3. bolge */
	if((sourceCol > targetCol) && (sourceRow > targetRow)){ 
		/*3.bolgede oynanacak 2 durum var,buda farkin 6 ve 15 olması durumu*/ 
		if(difference == 6){
			/*tasimiz hangi renkte ise hedefin zıt renk veya bosluk olması*/
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}

			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}
		} 

		if(difference == 15){
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}

			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}
		}
	}/* 3. bolge if'inin sonu*/

	/* Kordinat duzleminde 4. bolge */
	if((sourceCol < targetCol) && (sourceRow > targetRow)){ 
		/*4.bolgede oynanacak 2 durum var,buda farkin 17 ve 10 olması durumu*/ 
		if(difference == 17){
			/*tasimiz hangi renkte ise hedefin zıt renk veya bosluk olması*/
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z')
			{
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}

			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z')
			{
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}
		} 

		if(difference == 10){
			if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z'){
				if((board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z') || board[targetBoardPoint] ==' ')
					return 1; 
			}

			if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z'){
				if((board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z') || board[targetBoardPoint] ==' ')
					return 1; 
			}	
		}
	}/* 4. bolge if'inin sonu*/
	return 0;
}/*isKnightMovable fonksiyon sonu*/

/* Secilen tasin kral olmasi durumunda cagirilecek fonksiyon */
int isKingMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	/* hedef ve secilen tasin bulundugu konumun arraydeki yeri */
	int currentBoardPoint, targetBoardPoint;
	int difference;	/*Hedef ile anlık bulunan nokta arasi fark*/

	/*tahtadaki mevcut konum ve hedef konumun arraydeki yeri*/
	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);
	
	
	difference = targetBoardPoint - currentBoardPoint;
	
	/*Hedef ve mevcut konum farklarinin -9,-8,-7,-1,1,7,8,9 olmasi durumlarinda
	tas sadece 1 kare oynayacak demektir. Kralin oynama stili vezirin sadece 
	1 hamle yapabildigi durumlar oldugu icin vezir fonksiyonu cagirilmistir*/
	if ((difference == -9) || (difference == -8) || (difference == -7) || 
	(difference == -1) || (difference == 1) || (difference == 7) || 
	(difference == 8)  || (difference == 9) )
	{
		/*dogru olma durumunda vezir 1 degeri uretecek ve return olacaktir*/
		return isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow);
	} 

	return 0; /*aksi durumda 0 return edilecek*/
}

/* Secilen tasin vezir olmasi durumunda cagirilecek fonksiyon */
int isQueenMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	/* Vezirin oynayamayacagi durum */
	if(targetRow == sourceRow && sourceCol == targetCol) return 0;

/* Vezirin oyun stili fil ve kalenin toplami oldugu icin bu taslarin 
fonksiyonlari tekrar kullanilmistir.										 */
	
	/* Filin oynama stiline göre olmasi gereken durumlar */
	if(((targetRow > sourceRow) && (sourceCol < targetCol)) || 
	((targetRow > sourceRow) && (sourceCol > targetCol)) || 
	((targetRow < sourceRow) && (sourceCol > targetCol)) || 
	((targetRow < sourceRow) && (sourceCol < targetCol)))
	{
		return isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
	}

	/* Kalenin oynama stiline göre olmasi gereken durumlar */
	if(((targetRow == sourceRow) && (sourceCol < targetCol)) || 
	((targetRow > sourceRow) && (sourceCol == targetCol)) || 
	((targetRow == sourceRow) && (sourceCol > targetCol)) || 
	((targetRow < sourceRow) && (sourceCol == targetCol)))
	{
		return isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
	}

	return 0; /*yukaridaki iflere girmediyse olumsuz return etme durumu*/
}/*isQueenMovable fonksiyon sonu*/

/*Secilentasin fil olmasi durumunda cagirilacak fonksiyon					 */
int isBishopMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	/* hedef ve secilen tasin bulundugu konumun arraydeki yeri */
	int currentBoardPoint, targetBoardPoint;
	/*hedefe kadar yolu kontrol ederken kullanilan degisken*/
	int currentTest; 

	int count = 0;
	int diff;

	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);
	
	currentTest = currentBoardPoint; 

	/* eger atin oynama bicimi olan L biciminde oynanirsa 
	mecbur bu sarta takilacak*/
	diff = targetBoardPoint - currentBoardPoint;

	if(abs(diff)%7!=0 && abs(diff)%9!=0) return 0;


	/*Filin hareketinin bastan olmayacagi durumlar */
	if(targetRow == sourceRow && sourceCol == targetCol) return 0;
	if(targetRow < sourceRow && sourceCol == targetCol) return 0;
	if(targetRow > sourceRow && sourceCol == targetCol) return 0;
	if(targetRow == sourceRow && sourceCol < targetCol) return 0;
	if(targetRow == sourceRow && sourceCol > targetCol) return 0;

	/*baslangic konumundan hedefe kadar capraz sekilde 1 er kutu 1 er kutu 
	ilerleyip kontrol eden dongu*/
	do{ 

		/*Her bolge icin capraz hareketi 1 kutu row 1 kutu colm degistirerek 
		hareketi saglayan islemler*/
		if ((targetRow > sourceRow) && (sourceCol < targetCol)) {
			currentTest -= (TOTAL_COLUMN - 1); 
		}
		if ((targetRow > sourceRow) && (sourceCol > targetCol)) {	
			currentTest -= (TOTAL_COLUMN + 1); 
		}
		if ((targetRow < sourceRow) && (sourceCol > targetCol)) {	
			currentTest += (TOTAL_COLUMN - 1); 
		}
		if ((targetRow < sourceRow) && (sourceCol < targetCol)) {
			currentTest += (TOTAL_COLUMN + 1);
		} 

		/*Tasin renk kontrolü*/
		if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z'){
			/*Arada tas varsa sayac artıyor return olmasi icin sayacin 
			0 olmasi gerekir*/
			if(currentTest != targetBoardPoint){
				if(board[currentTest]>='A' && board[currentTest]<='Z') 
					count++;
				if(board[currentTest]>='a' && board[currentTest]<='z') 
					count++;
			}
			if(currentTest == targetBoardPoint && count == 0)
				if((board[currentTest]>='a' && board[currentTest]<='z') || 
				board[currentTest] ==' ' )
					return 1; 
		}
				
		/*Tasin renk kontrolü*/
		if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z'){
			/*Arada tas varsa sayac artıyor return olmasi icin sayacin 
			0 olmasi gerekir*/
			if(currentTest != targetBoardPoint){
				if(board[currentTest]>='A' && board[currentTest]<='Z') 
					count++;
				if(board[currentTest]>='a' && board[currentTest]<='z') 
					count++;
				}
			if(currentTest == targetBoardPoint && count == 0)
				if((board[currentTest]>='A' && board[currentTest]<='Z') || 
				board[currentTest] ==' ')
					return 1; 
		}
	} while(currentTest != targetBoardPoint);

	return 0;
}/*isBishopMovable fonksiyon sonu*/

/* Oynanacak tasin kale olmasi durumunda cagirilacak fonksiyon */
int isRookMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	/* hedef ve secilen tasin bulundugu konumun arraydeki yeri */
	int currentBoardPoint, targetBoardPoint;
	/*hedefe kadar yolu kontrol ederken kullanilan degisken*/
	int currentTest;
	int count = 0;


	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);
	
	currentTest = currentBoardPoint;


	/* kalenin oynamasinin bastan fail oldugu durumlar */
	if((targetRow == sourceRow) && (sourceCol == targetCol)) return 0;
	if((targetRow < sourceRow) && (sourceCol < targetCol)) return 0;
	if((targetRow > sourceRow) && (sourceCol > targetCol)) return 0;
	if((targetRow > sourceRow) && (sourceCol < targetCol)) return 0;
	if((targetRow < sourceRow) && (sourceCol > targetCol)) return 0;
	


	/*baslangic konumundan hedefe kadar  row hizasinda 1 veya colm hizasinda 
	1 kutu ilerleyip kontrol eden dongu*/
	do{
		/*Her bolge icin dogrusal hareketi row hizasinda 1 veya colm hizasinda 
		1 kutu degistirerek hareketi saglayan islemler*/
		if ((targetRow == sourceRow) && (sourceCol < targetCol)) {
			currentTest += 1; 
		}
		if ((targetRow > sourceRow) && (sourceCol == targetCol)) {	
			currentTest -= TOTAL_COLUMN; 
		}
		if ((targetRow == sourceRow) && (sourceCol > targetCol)) {	
			currentTest -= 1; 
		}
		if ((targetRow < sourceRow) && (sourceCol == targetCol)) {
			currentTest += TOTAL_COLUMN ;
		} 

		/*Tasin renk kontrolü*/
		if(board[currentBoardPoint]>='A' && board[currentBoardPoint]<='Z' ){
			/*Arada tas varsa sayac artıyor return olmasi icin sayacin 
			0 olmasi gerekir*/
			if(currentTest != targetBoardPoint){

				if(board[currentTest]>='A' && board[currentTest]<='Z') 
					count++;
				if(board[currentTest]>='a' && board[currentTest]<='z') 
					count++;
			}

			if(currentTest == targetBoardPoint && count==0)
				if((board[currentTest]>='a' && board[currentTest]<='z') 
				|| board[currentTest] ==' ' )
					return 1; 
		}
		/*Tasin renk kontrolü*/	
		if(board[currentBoardPoint]>='a' && board[currentBoardPoint]<='z' ){
			/*Arada tas varsa sayac artıyor return olmasi icin sayacin 
			0 olmasi gerekir*/
			if(currentTest != targetBoardPoint){

				if(board[currentTest]>='A' && board[currentTest]<='Z') 
						count++;
				if(board[currentTest]>='a' && board[currentTest]<='z') 
						count++;

				}
			if(currentTest == targetBoardPoint && count==0)
				if((board[currentTest]>='A' && board[currentTest]<='Z') 
				|| board[currentTest] ==' ')
					return 1; 
		} 
	} while(currentTest != targetBoardPoint);
	
/*eger buraya kadar retun olmamıssa istenen sartlar yerine getirilmemistir.*/
	return 0; 

} /*isRookMovable fonksiyon sonu */

/*secilen tasin piyon olma durumunda cagirilacak fonksiyon					 */
int isPawnMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	/* hedef ve secilen tasin bulundugu konumun arraydeki yeri */
	int targetBoardPoint, currentBoardPoint;
	
	int currentTest ;
	
	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);
	
	currentTest = currentBoardPoint;

	/* tasin rengine gore islem, bu da hareket yönünü bulmada yardımcı olur */
	if(board[currentBoardPoint] == 'P'){
		/*dikine harekette hedefin ' ' olma durumu*/
		if(sourceCol == targetCol){
			currentTest -= TOTAL_COLUMN;
			if(currentTest == targetBoardPoint)
				if(board[targetBoardPoint] ==' ')
				
					return 1;

		}
		/*capraz harekette hedefin zit renk tas olma durumu*/
		if(sourceCol < targetCol){
			currentTest -= (TOTAL_COLUMN - 1);
			if(currentTest == targetBoardPoint )
				if(board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z')
				
					return 1;
		}
		/*capraz harekette hedefin zit renk tas olma durumu*/
		if(sourceCol > targetCol){
			currentTest -= (TOTAL_COLUMN + 1);
			if(currentTest == targetBoardPoint )
				if(board[targetBoardPoint]>='a' && 
				board[targetBoardPoint]<='z')
				
					return 1;
		}

	}

	if(board[currentBoardPoint] == 'p'){
		/*dikine harekette hedefin ' ' olma durumu*/
		if(sourceCol == targetCol){
			currentTest += TOTAL_COLUMN;
			if(currentTest == targetBoardPoint)
				if(board[targetBoardPoint] ==' ')
				
					return 1;
		}
		/*capraz harekette hedefin zit renk tas olma durumu*/
		if(sourceCol > targetCol){
			currentTest += (TOTAL_COLUMN - 1);
			if(currentTest == targetBoardPoint )
				if(board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z')
				
					return 1;
		}
		/*capraz harekette hedefin zit renk tas olma durumu*/
		if(sourceCol < targetCol){
			currentTest += (TOTAL_COLUMN + 1);
			if(currentTest == targetBoardPoint )
				if(board[targetBoardPoint]>='A' && 
				board[targetBoardPoint]<='Z')
					return 1;
		}
	}
	return 0;
} /* isPawnMovable fonksiyonu sonu */

/*###########################################################################*/
/*			End of HW05_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
