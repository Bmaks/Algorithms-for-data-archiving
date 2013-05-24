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
    char ch, end;
	short offset_voc;
	short length_voc;
	const int alg_size = 12;
	int entry, OtherCase;
	string alg_voc;
	short i,j;
	int chcount, k, d;


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

/*	while (!feof(fin)){
		fseek(fin,1,SEEK_CUR);*/
	while ( (ch = fgetc(fin))  != EOF ){
		while ( (ch = fgetc(fin))  != EOF ){
//				ch = fgetc(fin);
	/*		if (ch == '<' | ch == '>' | ch == ','){
				++entry;
				continue;
			}*/
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
	return 0;
}