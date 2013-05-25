// FinishedArch.cpp: главный файл проекта.
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iostream>
#using <System.dll>

using namespace std;

class ILoad
{
public:
    virtual void Archiving()=0;
    virtual void Unzipping()=0;
};

class LZ : public ILoad
{
public:
    LZ(){};
    ~LZ(){};
	virtual void Archiving()
    {
    char inFileName[BUFSIZ], outFileName[BUFSIZ], alg_bufc[BUFSIZ];
    FILE *fin, *fout;
    char ch;
	string alg_voc;
	string alg_buf10;
	string alg_buf9;
	string alg_buf8;
	string alg_buf7;
	string alg_buf6;
	string alg_buf5;
	string alg_buf4;
	string alg_buf3;
	string alg_buf2;
	string alg_buf1;
	long counter_buf = 0, entry = 0, i = 0, j = 0, c = 0, InAlg = 0;
	long FileCounter = 0;
	char emptyword[100];
	short endofprog = 0;
	short LastSymbolvar = 0;
	
    
    printf("Введiть назву(шлях) вхiдного файлу, данi якого будуть архiвуватися:  ");
    if ( scanf("%s", inFileName) != 1 ){
        perror("scanf");
        exit(1);
    }
    printf("Введiть назву(шлях) вихiдного файлу, який мiститиме код файлу архiвування: ");
    if ( scanf("%s", outFileName) != 1 ){
    perror("scanf");
        exit(1);
    }
    if ( ( fin = fopen(inFileName, "r") ) == NULL ){
        perror("fopen");
        exit(1);
    }
    if ( ( fout = fopen(outFileName, "w") ) == NULL ){
        perror("fopen");
        if ( fclose(fin) )
            perror("fclose");
        exit(1);
    }
   
	InAlg = -1;
	FileCounter = 0;

	while(LastSymbolvar == 0){

		if (InAlg == -1){ 	 //перше зчитування в буфер
			alg_voc = "";
			fseek(fin,FileCounter + 0,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
			alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		} 
		if (InAlg == 0){      //зчитування в буфер у випадку не знаходження входження +1байт
			alg_voc += alg_buf10[0];
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 1;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 1){    //у випадку співпадання одного символу буфера і словника
			for(j = 0;!(j == 2); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 2;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 2){
			for(j = 0;!(j == 3); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 3;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 3){
			for(j = 0;!(j == 4); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 4;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 4){
			for(j = 0;!(j == 5); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 5;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 5){
			for(j = 0;!(j == 6); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 6;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 6){
			for(j = 0;!(j == 7); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 7;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 7){
			for(j = 0;!(j == 8); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 8;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 8){
			for(j = 0;!(j == 9); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 9;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 9){
			for(j = 0;!(j == 10); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 10;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}
		if (InAlg == 10){
			for(j = 0;!(j == 11); ++j)
				alg_voc += alg_buf10[j];			
					while (alg_voc.length() > 12)
					{
							alg_voc.erase(0,1);
					}
			FileCounter += 11;
			fseek(fin,FileCounter,SEEK_SET);
			alg_buf10 = "";
			while ( (ch = fgetc(fin))  != EOF ){
				alg_buf10 += ch;
				counter_buf++;
				if (counter_buf == 10) break;
			}
		}


		if (alg_buf10.length() == 1){
			LastSymbolvar = 1;
			goto LastSymbolpre;
		}		
		if (alg_buf10.length() == 0){
			LastSymbolvar = 1;
			goto LastSymbolafter;
		}

		entry = alg_voc.find(alg_buf10);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('10', fout);
			fputc(',', fout);
			fputc(ch = fgetc(fin), fout);
			fputc('>', fout);
			InAlg = 10;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf9 = "";
	for (i = 0;!(i == 9); ++i)
		if (i < alg_buf10.length())
		alg_buf9 += alg_buf10[i];
		
		entry = alg_voc.find(alg_buf9);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('9', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[9], fout);
			fputc('>', fout);
			InAlg = 9;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf8 = "";
	for (i = 0;!(i == 8); ++i)
		if (i < alg_buf10.length())
		alg_buf8 += alg_buf10[i];

		entry = alg_voc.find(alg_buf8);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('8', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[8], fout);
			fputc('>', fout);
			InAlg = 8;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf7 = "";
	for (i = 0;!(i == 7); ++i)
		if (i < alg_buf10.length())
		alg_buf7 += alg_buf10[i];

		entry = alg_voc.find(alg_buf7);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('7', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[7], fout);
			fputc('>', fout);
			InAlg = 7;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf6 = "";
	for (i = 0;!(i == 6); ++i)
		if (i < alg_buf10.length())
		alg_buf6 += alg_buf10[i];

		entry = alg_voc.find(alg_buf6);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('6', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[6], fout);
			fputc('>', fout);
			InAlg = 6;
			goto exitfromseek;
		}											//block
		counter_buf = 0;


		alg_buf5 = "";
	for (i = 0;!(i == 5); ++i)
		if (i < alg_buf10.length())
		alg_buf5 += alg_buf10[i];

		entry = alg_voc.find(alg_buf5);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('5', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[5], fout);
			fputc('>', fout);
			InAlg = 5;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf4 = "";
	for (i = 0;!(i == 4); ++i)
		if (i < alg_buf10.length())
		alg_buf4 += alg_buf10[i];

		entry = alg_voc.find(alg_buf4);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('4', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[4], fout);
			fputc('>', fout);
			InAlg = 4;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf3 = "";
	for (i = 0;!(i == 3); ++i)
		if (i < alg_buf10.length())
		alg_buf3 += alg_buf10[i];

		entry = alg_voc.find(alg_buf3);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('3', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[3], fout);
			fputc('>', fout);
			InAlg = 3;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf2 = "";
	for (i = 0;!(i == 2); ++i)
		if (i < alg_buf10.length())
		alg_buf2 += alg_buf10[i];

		entry = alg_voc.find(alg_buf2);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('2', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[2], fout);
			fputc('>', fout);
			InAlg = 2;
			goto exitfromseek;
		}											//block
		counter_buf = 0;

		alg_buf1 = "";
	for (i = 0;!(i == 1); ++i)
		if (i < alg_buf10.length())
		alg_buf1 += alg_buf10[i];

		entry = alg_voc.find(alg_buf1);
		if(entry!=string::npos) {
			fputc('<', fout);
			fputc((12-alg_voc.length())+entry + '0', fout);
			fputc(',', fout);
			fputc('1', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[1], fout);
			fputc('>', fout);
			InAlg = 1;
			goto exitfromseek;
		}						
			
			LastSymbolpre:
			InAlg = 0;
			fputc('<', fout);
			fputc(0 + '0', fout);
			fputc(',', fout);
			fputc('0', fout);
			fputc(',', fout);
			fputc(ch = alg_buf10[0], fout);
			fputc('>', fout);
			LastSymbolafter:

			exitfromseek: c++;
	}								//block
    
    if ( fclose(fin) )
        perror("fclose");
    if ( fclose(fout) )
        perror("fclose");
    }

	virtual void Unzipping(){
	char inFileName[BUFSIZ], outFileName[BUFSIZ], alg_bufc[BUFSIZ];
    FILE *fin, *fout;
    char ch, end;
	short offset_voc = 0;
	short length_voc = 0;
	const int alg_size = 12;
	int entry = 0, OtherCase = 0;
	string alg_voc;
	short i = 0,j = 0;
	int chcount = 0, k = 0, d = 0;


	    printf("Введiть назву(шлях) вхiдного файлу, данi якого будуть розархiвованi:  ");
    if ( scanf("%s", inFileName) != 1 ){
        perror("scanf");
        exit(1);
    }
    printf("Введiть назву(шлях) вихiдного файлу, який мiститиме оригiнальнi данi: ");
    if ( scanf("%s", outFileName) != 1 ){
    perror("scanf");
        exit(1);
    }
    if ( ( fin = fopen(inFileName, "r") ) == NULL ){
        perror("fopen");
        exit(1);
    }
    if ( ( fout = fopen(outFileName, "w") ) == NULL ){
        perror("fopen");
        if ( fclose(fin) )
            perror("fclose");
        exit(1);
	}

	while ( (ch = fgetc(fin))  != EOF ){
		while ( (ch = fgetc(fin))  != EOF ){
			if (ch == '0') offset_voc = 0; else {
				OtherCase ++;
				offset_voc = static_cast<int>(ch) - 48;
			}
			fseek(fin,1,SEEK_CUR);
			ch = fgetc(fin);
			if (ch == '0') length_voc = 0; else {
				OtherCase ++;
				length_voc = static_cast<int>(ch) - 48;
			}
			fseek(fin,1,SEEK_CUR);
			break;
		}

		ch = fgetc(fin);
		if (OtherCase > 1) {
			for (i = offset_voc,j = length_voc; !(j == 0); --i , --j){
				while (alg_size < alg_voc.length()){
					fputc(alg_voc[0],fout);
					alg_voc.erase(0,1);
				} 
				chcount = offset_voc - (alg_size - alg_voc.length());
				alg_voc += alg_voc[chcount];
			}
				alg_voc += ch;
				fseek(fin,1,SEEK_CUR);
				entry = 0;
				OtherCase = 0;

		} else{
				while (alg_size < alg_voc.length()){
					fputc(alg_voc[0],fout);
					alg_voc.erase(0,1);
				} 
				alg_voc += ch;
				fseek(fin,1,SEEK_CUR);
		 }
	}

	for (k = alg_voc.length(), d = 0;(k > 0); ++d ,--k)
		fputc(alg_voc[d],fout);

	if ( fclose(fin) )
        perror("fclose");
    if ( fclose(fout) )
        perror("fclose");
	}

};
class HF : public ILoad
{
	public:
		 HF(){};
		 ~HF(){};
		 virtual void Archiving(){
				char inFileName[BUFSIZ], outFileName[BUFSIZ], Array[BUFSIZ] ;
	string ArrayCode[BUFSIZ] = {""};
	int Arraycount[BUFSIZ][3] = {0}, Arraytruenumber[BUFSIZ] = {0};
	float Arraycountfl[BUFSIZ] = {0}, Arraycountflch[BUFSIZ] = {0};
    FILE *fin, *fout;
    char ch;
	int k = 0, Quant = 0;
	short first = 0;
	short check = 0;
	int truenumber , flag, secondflag, thirdflag, firsttime;
	int queuecount;
	string str;


	    printf("Введiть назву(шлях) вхiдного файлу, данi якого будуть архiвуватися:  ");
    if ( scanf("%s", inFileName) != 1 ){
        perror("scanf");
        exit(1);
    }
    printf("Введiть назву(шлях) вихiдного файлу, який мiститиме код файлу архiвування: ");
    if ( scanf("%s", outFileName) != 1 ){
    perror("scanf");
        exit(1);
    }
    if ( ( fin = fopen(inFileName, "r") ) == NULL ){
        perror("fopen");
        exit(1);
    }
    if ( ( fout = fopen(outFileName, "w") ) == NULL ){
        perror("fopen");
        if ( fclose(fin) )
            perror("fclose");
        exit(1);
    }

	while ( (ch = fgetc(fin))  != EOF ){
		if (first == 0) goto firstentry;
		for (int i = 0;!(i == k); ++i)
		if (ch != Array[i]) 
				check++;

		if (check == k){
firstentry:	Array[k] = ch;
			++Arraycount[k][0];
			++k;
			first = 1;
			check = 0;
		} else
			for (int j = 0;!(j == k); ++j)
				if (ch == Array[j]){
					++Arraycount[j][0];
					check = 0;
				}
	} 
		for (int i = 0;!(i == k); ++i){
			Quant += Arraycount[i][0]; 
		}

		for (int i = 0;!(i == k); ++i){
			Arraycountfl[i] = (float) Arraycount[i][0]/Quant;
		}

    int i, j;
	float value;
 
    for(i = 1; i < k; i++) {
        value = Arraycountfl[i];
        for (j = i - 1; j >= 0 && Arraycountfl[j] > value; j--) {
            Arraycountfl[j + 1] = Arraycountfl[j];
        }
        Arraycountfl[j + 1] = value;
    }
	for (int i = 0;!(i == k); ++i)
		Arraycountflch[i] = Arraycountfl[i];


	for (int i = 0;!(i == k-1); ++i){

		int number = (int) (Arraycountfl[i] * Quant);
		for (int j = 0;!(j == k); ++j)
		if (Arraycount[j][0] == number & Arraycount[j][1] == 0) { truenumber = j; Arraycount[j][1] = 1; break; }

			if (!(i >= k-2))
				for (int q = 0;!(q == queuecount); ++q){
					if (truenumber == 0 & secondflag == 0) {
						secondflag = 1;
						Arraytruenumber[queuecount] = truenumber;
						++queuecount;
						firsttime = 1;
						break;
					}
					if (firsttime == 0) goto labelfirsttime;
					if (Arraytruenumber[q] != truenumber) 
						++thirdflag;
					}
					if (thirdflag == queuecount) { 
					labelfirsttime: 
					Arraytruenumber[queuecount] = truenumber;
					++queuecount;
					firsttime = 1;
					thirdflag = 0;
					}
					thirdflag = 0;   

			ArrayCode[truenumber] += "1"; 

		 number = (int) (Arraycountfl[i+1] * Quant);
		 for (int j = 0;!(j == k); ++j)
		  if (Arraycount[j][0] == number & (Arraycount[j][1] == 0 && Arraycount[j][2] == 0)) { truenumber = j; Arraycount[j][2] = 1; break; }
			if (!(i >= k-2))
				for (int q = 0;!(q == queuecount); ++q){
					if (truenumber == 0 & secondflag == 0) {
						secondflag = 1;
						Arraytruenumber[queuecount] = truenumber;
						++queuecount;
						firsttime = 1;
						break;
					}
					if (Arraytruenumber[q] != truenumber) 
						++thirdflag;
					}
					if (thirdflag == queuecount) {
						Arraytruenumber[queuecount] = truenumber;
						++queuecount;
						firsttime = 1;
						thirdflag = 0;
					}
					thirdflag = 0;   

			ArrayCode[truenumber] += "0";

			Arraycountflch[i+1] = Arraycountflch[i+1] + Arraycountflch[i];
			Arraycountflch[i] = 0;
	}
	--queuecount ;
	Arraytruenumber[queuecount] = 0;
	
	while (!(queuecount == 0)){
	for (int i = 0;!(i == queuecount); ++i)
		ArrayCode[Arraytruenumber[i]] += "1";
		--queuecount;
	}

	for (int i = 0;!(i == k); ++i){
		fputc(Array[i], fout);
		for (int j = ArrayCode[i].length()-1;!(j < 0); --j){
			str = ArrayCode[i];
			fputc(str[j], fout);
			}
	}
	fputc(' ', fout);
	fputc(' ', fout);
	fseek(fin,0,SEEK_SET);
	while ( (ch = fgetc(fin))  != EOF ){
		for (int i = 0;!(i == k); ++i)
		if (ch == Array[i]) 
			for (int j = ArrayCode[i].length()-1;!(j < 0); --j){
			str = ArrayCode[i];
			fputc(str[j], fout);
			}
	} 
	
    if ( fclose(fin) )
        perror("fclose");
    if ( fclose(fout) )
        perror("fclose");	 
		 }
		 virtual void Unzipping(){
			
	FILE *fin, *fout;
	char inFileName[BUFSIZ], outFileName[BUFSIZ];
	string Arraycode[BUFSIZ] = {""} ;
	char Array[BUFSIZ]  = {""};
	char ch, ch1 ;
	int k = 0, FileCounter = 0 ;
	string str;

    printf("Введiть назву(шлях) вхiдного файлу, данi якого будуть архiвуватися:  ");
    if ( scanf("%s", inFileName) != 1 ){
        perror("scanf");
        exit(1);
    }
    printf("Введiть назву(шлях) вихiдного файлу, який мiститиме код архiвованого файлу: ");
    if ( scanf("%s", outFileName) != 1 ){
    perror("scanf");
        exit(1);
    }
    if ( ( fin = fopen(inFileName, "r") ) == NULL ){
        perror("fopen");
        exit(1);
    }
    if ( ( fout = fopen(outFileName, "w") ) == NULL ){
        perror("fopen");
        if ( fclose(fin) )
            perror("fclose");
        exit(1);
    }
	 
	ch = fgetc(fin); // зчитування першого символу
	Array[k] = ch; ++k;
	++FileCounter ; 
	while ( ((ch = fgetc(fin)) != (char) 32)  |  ((ch1 = fgetc(fin)) != (char) 32) ){
		++FileCounter;
		fseek(fin, FileCounter, SEEK_SET);       

		if ((ch != '0') & (ch != '1')) {
			Array[k] = ch;
			++k;
		}
	}

	fseek(fin, 0 , SEEK_SET);
	k = -1;
	FileCounter = 0 ;

	while ( ((ch = fgetc(fin)) != (char) 32)  |  ((ch1 = fgetc(fin)) != (char) 32) ){
		++FileCounter;
		fseek(fin, FileCounter, SEEK_SET);  

		if (ch != '0' & ch != '1') ++k;
			if (ch == '0' | ch == '1') 
				Arraycode[k] += ch;
	}

	while ( (ch = fgetc(fin))  != EOF ){
		str += ch;
		for (int i = 0;!(i == k+1); ++i)
			if (str == Arraycode[i]){ 
				fputc(Array[i], fout);
				str = "";
			}
	}

    if ( fclose(fin) )
        perror("fclose");
    if ( fclose(fout) )
        perror("fclose");
		 }
};


int main()
{
    setlocale(LC_ALL, "rus");
	int chose;
	char chosechar;
	LZ LimpelZivel;
	HF Haffmana;

	Again:
    printf("Виберiть, будь ласка, умову виконання програми:\n");
	printf("1 - Архiвування; 2 - Розархiвування.\n");
	cin >> chose;
	switch((int)chose){
		case 1:
			printf("Виберiть, будь ласка, тип архiвування:\n");
			printf("1 - Архiвування алгоритмом Лiмпеля-Зiвеля, 2 - Архiвування алгоритмом Хаффмана\n");
			cin >> chose;
			switch (chose){
			case 1: 
				LimpelZivel.Archiving();
				printf("Якщо бажаєте продовжити натиснiть клавiшу \"c\", вихiд з програми - \"q\"\n");
				cin >> chosechar;
				if (chosechar == 'c') goto Again;
				else if (chosechar == 'q') exit; else printf("Неправильна команда!");					
				break;
			case 2:
				Haffmana.Archiving();
				printf("Якщо бажаєте продовжити натиснiть клавiшу \"c\", вихiд з програми - \"q\"\n");
				cin >> chosechar;
				if (chosechar == 'c') goto Again;
				else if (chosechar == 'q') exit; else printf("Неправильна команда!");	
				break;
			}
			break;
		case 2: 
			printf("Виберiть, будь ласка, тип розархiвування:\n");
			printf("1 - Розархiвування алгоритмом Лiмпеля-Зiвеля, 2 - Розархiвування алгоритмом Хаффмана\n");
			cin >> chose;
			switch (chose){
			case 1: 
				LimpelZivel.Unzipping();
				printf("Якщо бажаєте продовжити натиснiть клавiшу \"c\", вихiд з програми - \"q\"\n");
				cin >> chosechar;
				if (chosechar == 'c') goto Again;
				else if (chosechar == 'q') exit; else printf("Неправильна команда!");	
				break;
			case 2:
				Haffmana.Unzipping();
				printf("Якщо бажаєте продовжити натиснiть клавiшу \"c\", вихiд з програми - \"q\"\n");
				cin >> chosechar;
				if (chosechar == 'c') goto Again;
				else if (chosechar == 'q') exit; else printf("Неправильна команда!");	
				break;
			}
			break;
		default:
			printf("Неправильна команда!\n");
			goto Again;
			break;
	}
    return 0;
}
