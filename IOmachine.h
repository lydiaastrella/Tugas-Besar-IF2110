
#ifndef _IOMACHINE_H_
#define _IOMACHINE_H_

#include "library.h"
extern char CC;
extern boolean EOP;
extern boolean EndKata;
extern Kata CKata;


/******** MESIN KARAKTER ********/
void START(char n);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
		  Jika CC != MARK maka EOP akan padam (false)
		  Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
		  CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */

/******** MESIN KATA ********/
void IgnoreBlank();
/*	I.S :	CC Sembarang
	F.S :	Skip BLANK atau ' ' */

void STARTKATA(char n);
/* 	I.S. : 	CC sembarang
	F.S. : 	EndKata = true, dan CC = MARK;
			atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
			CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* 	I.S. : 	CC adalah karakter pertama kata yang akan diakuisisi
	F.S. : 	CKata adalah kata terakhir yang sudah diakuisisi,
			CC adalah karakter pertama dari kata berikutnya, mungkin MARK
			Jika CC = MARK, EndKata = true.
	Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
	I.S. :	CC adalah karakter pertama dari kata
	F.S. :	CKata berisi kata yang sudah diakuisisi;
			CC = BLANK atau CC = MARK;
			CC adalah karakter sesudah karakter terakhir yang diakuisisi.
			Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/******** READ THUMBNAIL DATA ********/
void ReadThumbFile(ArrThumb *ArrTh, char *Name);

/******** WRITE THUMBNAIL DATA********/
void WriteThumbFile(ArrThumb ArrTh, char *Name);

/******** READ SAVE_DATA FROM FILE ********/
void ReadFileExt(Queue *Q, ArrTable *ArrT, ArrOrder *ArrO, Player *P, Stack *Tray, Stack *Hand);

/******** WRITE SAVE_DATA TO FILE ********/
void WriteFileExt(Queue Q, ArrTable ArrT, ArrOrder ArrO, Player P, Stack Tray, Stack Hand, char n);

/******** READ MAP MATRIX ********/
void AssignMap_FileExt(MapMatrix *R);

void ReadMap_FileExt(MapMatrix *R1, MapMatrix *R2, MapMatrix *R3, MapMatrix *RK);

#endif