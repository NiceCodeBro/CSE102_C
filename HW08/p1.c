/*###########################################################################*/
/*HW08_MuhammedSelim_Dursun							 				   	     */
/*_____________________________________									     */
/*Created on 20/04/2016 by Muhammed_Selim_Dursun							 */
/*									    									 */
/*Description  								  								 */
/*________  								   								 */
/*	Basit bir satranc oyunu											 		 */
/*									    									 */
/*Inputs:								 								     */
/*	-Taslarin Source ve target bilgisi										 */
/*Outputs:																	 */
/*	-Anlik tahtanin durumu, oynama sirasini ve kazanani ekrana basar       	 */
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
typedef enum{A1,B1,C1,D1,E1,F1,G1,H1} colT;
typedef enum{rook=1, knight, bishop, queen, king, pawn} pieceT;
/*---------------------------------------------------------------------------*/
/*                               Defines                                     */
/*---------------------------------------------------------------------------*/
#define BOARD_SIZE 8
#define TOTAL_ROW 8 /* number of frames in a row   */
#define TOTAL_COLUMN 8 /* number of frames in a column   */
#define TOTALSIZE_BOARD 64
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
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
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
/*---------------------------------------------------------------------------*/
/* int isInCheck(char* board)												 */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 0 > King'ler icin her hangi bir tehdit yok								 */
/* 1 > Siyah king icin tehdit var											 */
/* 2 > Beyaz king icin tehdit var											 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* King'in tehdit durumlari olup olmadigini check eden fonksiyon 			 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isInCheck(char* board);
/*---------------------------------------------------------------------------*/
/* int makeMove(char *board, char sc, int sr, char tc, int tr)				 */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 0 > If move is invalid													 */
/* 1 > If move is invalid because same player's king is in check			 */
/* 2 > If move is valid														 */
/* 3 > If move is valid and opponent player's king is in check				 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Taslarin sakinca yoksa oynanmasini ve maine mesaj gonderen fonksiyon		 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int makeMove(char *board, char sc, int sr, char tc, int tr);
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
/* char getPlayer(char* board, char sc, int sr)			              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	 Piece - Tahtada o noktada bulunan tas									 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Tahtada o noktada bulunan tasi belirler ve return eder				     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
char getPlayer(char* board, char sc, int sr);
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
/* int isBlack(char currPlayer)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	1 > Secilen tas kucuk harfler yani black								 */
/* 	0 > Secilen tas kucuk harfler degil										 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Secilen tasin rengini bulan fonksiyon								     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isBlack(char currPlayer);
/*---------------------------------------------------------------------------*/
/* int isWhite(char currPlayer)							              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* 	1 > Secilen tas buyuk harf yani white									 */
/* 	0 > Secilen tas buyuk harf degil										 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Secilen tasin rengini bulan fonksiyon								     */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int isWhite(char currPlayer);
/*---------------------------------------------------------------------------*/
/* int isPieceMovable(char *board, char sc, int sr, char tc, int tr)    	 */
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
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
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
/* int rowN(int n) 										              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* row > Tasin oldugu noktaya gore bulundugu row							 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Tasin oldugu noktaya gore bulundugu rowu bulan fonksiyon  				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
int rowN(int n);
/*---------------------------------------------------------------------------*/
/* char colmCh(int n)									              	     */
/* -----------																 */
/*									    									 */
/* Return																	 */
/* ------																	 */
/* colm > Tasin oldugu noktaya gore bulundugu colm							 */
/*									    									 */
/* Description																 */
/* ----------- 																 */
/* Tasin oldugu noktaya gore bulundugu colm'u bulan fonksiyon  				 */
/*									    									 */						    									 
/*---------------------------------------------------------------------------*/
char colmCh(int n);
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

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty); 
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }

        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}

/* Satranc tahtasini baslangic pozisyonunda arraye tek tek initialize eder   */
void initBoard(char *board) 
{
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
void printBoard(char *board) 
{
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

/* Kullanicidan kordinat degeri okur									     */
void getPosition(char *col, int *row)
{
	scanf("%c%d", col, row);		
} /* getPosition fonksiyon sonu */

/* Girilen inputun tahtanin icinden bir nokta olup olmadini kontrol eden fonk*/
int isValidCell(char col, int row)
{
	if(col >= 'a' && col <= 'h') {
		if(row >= 1 && row <= 8 ){
			return 1;
		}
	} 
	return 0;
} /* isValidCell fonksiyon sonu */

/* Tahtada o noktada bulunan tasi belirler ve return eder				     */
char getPlayer(char* board, char sc, int sr)
{
	char piece;
	if(isValidCell(sc,sr)){
		piece = board[pieceIsWhere(sr,sc)];
	}
	return piece;
} /* getPlayer fonksiyon sonu */

/* Boarddaki lokasyon hesabinda kullanilan fonksiyon */
int pieceIsWhere(int row,char col)
{
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
/* Tasin rengini belirleyen fonksiyon				    				     */
int isBlack(char currPlayer)
{
	if(currPlayer>='a' && currPlayer<='z')
		return 1;
	else
		return 0;
}

/* Tasin rengini belirleyen fonksiyon				    				     */
int isWhite(char currPlayer)
{ 
	if(currPlayer>='A' && currPlayer<='Z')
		return 1;
	else
		return 0;
}
/* Tasin turunu belirleyen fonksiyon  										 */
int whichPiece(const char *board,char col, int row)
{
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

/* 		oynanacak tasi tespit eder ve valid ise tasi tespit edip,  			 */
/* 	o tasin fonksiyonunu cagirir 											 */
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{
			/* Tas turleri typdef biciminde tanimlanmistir */
			if(whichPiece(board,sc,sr) == rook){
				if(isRookMovable(board, sc, sr, tc, tr)){

					return 1;
				}
			}
			if(whichPiece(board,sc,sr) == knight){
				if(isKnightMovable(board, sc, sr, tc, tr)){

					return 1;
				}
			}		
			if(whichPiece(board,sc,sr) == bishop){
				if(isBishopMovable(board, sc, sr, tc, tr)){

					return 1;
				}
			}
			if(whichPiece(board,sc,sr) == queen){
				if(isQueenMovable(board, sc, sr, tc, tr)){

					return 1;
				}
			}
			if(whichPiece(board,sc,sr) == king){
				if(isKingMovable(board, sc, sr, tc, tr)){

					return 1;
				}
			}
			if(whichPiece(board,sc,sr) == pawn){
				if(isPawnMovable(board, sc, sr, tc, tr)){

					return 1;
				}
			}
	return 0; /* input eger valid degilse */
}/*isPieceMovable fonksiyon sonu*/

/* Taslarin sakinca yoksa oynanmasini ve maine mesaj gonderen fonksiyon		 */
int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	/*Tasin gitmesini istedigimiz ve bulundugu yerlerin arraydeki yeri*/
	int currentBoardPoint, targetBoardPoint; 
	 
	char piece,      /*oynanacak tas*/
		 tempPiece1, /*check durumlarinda kullanilacak gecici degisken*/
		 tempPiece2; /*check durumlarinda kullanilacak gecici degisken*/
		 
	currentBoardPoint = pieceIsWhere(sr, sc);
	targetBoardPoint = pieceIsWhere(tr, tc);
	
	piece = board[currentBoardPoint];
	/*beyaz*/
	if(board[currentBoardPoint] >= 'A' && board[currentBoardPoint] <= 'Z'){
		/*beyaz kingin tehdit durumu*/
		if(isInCheck(board) == 1) {
		
			tempPiece1 = board[currentBoardPoint];
			tempPiece2 = board[targetBoardPoint];
			board[targetBoardPoint] = piece;
			board[currentBoardPoint] = ' ';
			/*tas oynandigi halde tehdit devam ediyorsa hamle yapilamaz*/
			if(isInCheck(board) == 1){
				board[targetBoardPoint] = tempPiece2;
				board[currentBoardPoint] = tempPiece1;
				return 1;
			} else 
				return 2; /*sakinca olmayan durum*/
		}
		/*eger tas oynandiktan sonra sah oluyorsa oynama gecersiz */
		if(isPieceMovable(board, sc, sr, tc, tr) == 1 ){
		
			tempPiece1 = board[currentBoardPoint];
			tempPiece2 = board[targetBoardPoint];
			board[targetBoardPoint] = piece;
			board[currentBoardPoint] = ' ';
			
			if(isInCheck(board) == 1){

				board[targetBoardPoint] = tempPiece2;
				board[currentBoardPoint] = tempPiece1;
				return 0;
			}
			if(isInCheck(board) == 2) return 3;
			else 
				return 2; 		/*sakinca olmayan durum*/
		}
		else 
			if(isPieceMovable(board, sc, sr, tc, tr) == 0 ) return 0;	
	}
	/*siyah*/
	else 
		if(board[currentBoardPoint] >= 'a' && board[currentBoardPoint] <= 'z'){
		/*siyah kingin tehdit durumu*/
		if(isInCheck(board) == 2) {
		
			tempPiece1 = board[currentBoardPoint];
			tempPiece2 = board[targetBoardPoint];
			board[targetBoardPoint] = piece;
			board[currentBoardPoint] = ' ';
			/*tas oynandigi halde tehdit devam ediyorsa hamle yapilamaz*/
			if(isInCheck(board) == 2){
			
				board[targetBoardPoint] = tempPiece2;
				board[currentBoardPoint] = tempPiece1;
				return 1;
			} else 
				return 2; /*sakinca olmayan durum*/
		}
		/*eger tas oynandiktan sonra sah oluyorsa oynama gecersiz */
		if(isPieceMovable(board, sc, sr, tc, tr) == 1 ){
		
			tempPiece1 = board[currentBoardPoint];
			tempPiece2 = board[targetBoardPoint];
			board[targetBoardPoint] = piece;
			board[currentBoardPoint] = ' ';
			
			if(isInCheck(board) == 2){

				board[targetBoardPoint] = tempPiece2;
				board[currentBoardPoint] = tempPiece1;
				return 0;
			}
			if(isInCheck(board) == 1) return 3;
			else 
				return 2; 		/*sakinca olmayan durum*/
		}
		else 
			if(isPieceMovable(board, sc, sr, tc, tr) == 0 ) return 0;	
	}
	return 0;
} /*makeMove fonksiyon sonu*/

/*Tasin arraydeki yerine gore bulundugu row'u bulan fonksiyon				 */
int rowN(int n)
{
	int row;
	
	if(n>=0 && n<=7) row = 8;
	if(n>=8 && n<=15) row = 7;
	if(n>=16 && n<=23) row = 6;
	if(n>=24 && n<=31) row = 5;
	if(n>=32 && n<=39) row = 4;
	if(n>=40 && n<=47) row = 3;
	if(n>=48 && n<=55) row = 2;
	if(n>=56 && n<=63) row = 1;
	
	return row;
} /*rowN fonksiyon sonu*/

/*Tasin arraydeki yerine gore bulundugu row'u bulan fonksiyon				 */
char colmCh(int n)
{
	char colm;
	
	if(n%8==0) colm = 'a';
	if(n%8==1) colm = 'b';
	if(n%8==2) colm = 'c';
	if(n%8==3) colm = 'd';
	if(n%8==4) colm = 'e';
	if(n%8==5) colm = 'f';
	if(n%8==6) colm = 'g';
	if(n%8==7) colm = 'h';

	return colm;
} /*colmCh fonksiyon sonu */

/* King'in tehdit durumlari olup olmadigini check eden fonksiyon 			 */
int isInCheck(char* board)
{
	int i;
	int blackKingIndex;	
	int whiteKingIndex;
	int sr,tr;
	char sc, tc;
	char piece;
	
	/*Arraydeki black ve white kingin indexlerini bulma*/
	for(i=0; i <TOTALSIZE_BOARD;i++ ){
		if(board[i] == 'k')   blackKingIndex = i;
		if(board[i] == 'K')   whiteKingIndex = i; 
	}
	
	for(i=0; i <TOTALSIZE_BOARD;i++ ){
	/*kücük - siyah king icin*/
		if(board[i] >= 'A' && board[i] <= 'Z'){
			/*fonksiyonlara gonderilecek degiskenleri belirleme*/
			piece = board[i];
			tr = rowN(blackKingIndex);
			tc = colmCh(blackKingIndex);
			sr = rowN(i);
			sc = colmCh(i);
			
			switch (piece){
			
				case 'P':
					if(isPawnMovable(board,sc,sr,tc,tr) == 1) return 2;
					break;
				case 'R':
					if(isRookMovable(board,sc,sr,tc,tr) == 1) return 2;
					break;
				case 'N':
					if(isKnightMovable(board,sc,sr,tc,tr) == 1) return 2;
					break;
				case 'B':
					if(isBishopMovable(board,sc,sr,tc,tr) == 1) return 2;
					break;
				case 'Q':
					if(isQueenMovable(board,sc,sr,tc,tr) == 1) return 2;
					break;
				case 'K':
					if(isKingMovable(board,sc,sr,tc,tr) == 1) return 2;
					break;
			}	
		}
		/*buyuk - beyaz king icin*/
		if(board[i] >= 'a' && board[i] <= 'z'){
			/*fonksiyonlara gonderilecek degiskenleri belirleme*/
			piece = board[i];
			tr = rowN(whiteKingIndex);
			tc = colmCh(whiteKingIndex);
			sr = rowN(i);
			sc = colmCh(i);
			
			switch (piece){
			
				case 'p':
					if(isPawnMovable(board,sc,sr,tc,tr) == 1) return 1;
					break;
				case 'r':
					if(isRookMovable(board,sc,sr,tc,tr) == 1) return 1;
					break;
				case 'n':
					if(isKnightMovable(board,sc,sr,tc,tr) == 1) return 1;
					break;
				case 'b':
					if(isBishopMovable(board,sc,sr,tc,tr) == 1) return 1;
					break;
				case 'q':
					if(isQueenMovable(board,sc,sr,tc,tr) == 1) return 1;
					break;
				case 'k':
					if(isKingMovable(board,sc,sr,tc,tr) == 1) return 1;
					break;
			}	
		}
	}
	/*donguden return etmeden ciktiysa tehdit yok demektir*/
	return 0;
} /*isInCheck fonksiyon sonu */
/* Oynanacak tasin Knight olmasi durumunda cagirilacak fonksiyon			 */
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	/* hedef ve secilen tasin bulundugu konumun arraydeki yeri */
	int currentBoardPoint, targetBoardPoint;  
	int difference;	/*Hedef ile anlik bulunan nokta arasi fark*/

	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);

	difference = targetBoardPoint - currentBoardPoint;

	/* Kordinat duzleminde 1. bolge */
	if((sourceCol < targetCol) && (sourceRow < targetRow)){  
		/*1. bolgede oynanacak 2 durum var,buda farkin -6 ve-15 olmasi durumu*/
		if(difference == -6) {
			/*tasimiz hangi renkte ise hedefin zit renk veya bosluk olmasi*/
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
		/*2.bolgede oynanacak 2 durum var,buda farkin -17 ve-10 olmasi durumu*/
		if(difference == -17){
			/*tasimiz hangi renkte ise hedefin zit renk veya bosluk olmasi*/
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
		/*3.bolgede oynanacak 2 durum var,buda farkin 6 ve 15 olmasi durumu*/ 
		if(difference == 6){
			/*tasimiz hangi renkte ise hedefin zit renk veya bosluk olmasi*/
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
		/*4.bolgede oynanacak 2 durum var,buda farkin 17 ve 10 olmasi durumu*/ 
		if(difference == 17){
			/*tasimiz hangi renkte ise hedefin zit renk veya bosluk olmasi*/
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
	int difference;	/*Hedef ile anlik bulunan nokta arasi fark*/

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
	
	/* Filin oynama stiline gore olmasi gereken durumlar */
	if(((targetRow > sourceRow) && (sourceCol < targetCol)) || 
	((targetRow > sourceRow) && (sourceCol > targetCol)) || 
	((targetRow < sourceRow) && (sourceCol > targetCol)) || 
	((targetRow < sourceRow) && (sourceCol < targetCol)))
	{
		return isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
	}

	/* Kalenin oynama stiline gore olmasi gereken durumlar */
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
	int diffC, diffR;

	currentBoardPoint = pieceIsWhere(sourceRow, sourceCol);
	targetBoardPoint = pieceIsWhere(targetRow, targetCol);
	
	currentTest = currentBoardPoint; 

	/* eger atin oynama bicimi olan L biciminde oynanirsa 
	mecbur bu sarta takilacak*/
	diff = targetBoardPoint - currentBoardPoint;
	diffC = abs(targetCol - sourceCol);
	diffR = abs(targetRow - sourceRow);
	
	if(diffC != diffR) return 0;
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
			/*Arada tas varsa sayac artiyor return olmasi icin sayacin 
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
			/*Arada tas varsa sayac artiyor return olmasi icin sayacin 
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
			/*Arada tas varsa sayac artiyor return olmasi icin sayacin 
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
			/*Arada tas varsa sayac artiyor return olmasi icin sayacin 
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
/*eger buraya kadar retun olmamissa istenen sartlar yerine getirilmemistir.*/
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

	/* tasin rengine gore islem, bu da hareket yonünü bulmada yardimci olur */
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
/*			End of HW08_131044023_MuhammedSelim_Dursun.c					 */
/*###########################################################################*/
