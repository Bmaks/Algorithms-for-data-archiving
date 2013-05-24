#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
 
int main(void){
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
	long counter_buf, entry, i, j, c, InAlg;
	long FileCounter;
	char emptyword[100];
	short endofprog = 0;
	short LastSymbolvar;
	
    
    printf("Input file: ");
    if ( scanf("%s", inFileName) != 1 ){
        perror("scanf");
        exit(1);
    }
    printf("Output file: ");
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
/*			else
			{
				alg_buf10 += ' ';
				counter_buf++;
				if (counter_buf == 10) break;
			}*/
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
		/*	for (c = 0;!(c == 10); ++c)
				if (alg_buf10[c] == ' ') ++endofprog;*/

	}								//block
    
    if ( fclose(fin) )
        perror("fclose");
    if ( fclose(fout) )
        perror("fclose");
	return 0;
}