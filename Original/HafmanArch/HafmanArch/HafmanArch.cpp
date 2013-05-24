#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) 
{ 
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


	/*		int number1 = (int) (Arraycountfl[i] * Quant);
			int number2 = (int) (Arraycountfl[i-1] * Quant);
			if (number1 == number2) flag = 1;
			for (int j = 0;!(j == k); ++j){
				if (Arraycount[j] == number1 & flag == 1)  {  flag = 0; continue;  }
				if (Arraycount[j] == number1 & flag == 0)  { truenumber = j; break; }
			} */
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

			ArrayCode[truenumber] += "1"; //////////////string nado

		 number = (int) (Arraycountfl[i+1] * Quant);
		 for (int j = 0;!(j == k); ++j)
		  if (Arraycount[j][0] == number & (Arraycount[j][1] == 0 && Arraycount[j][2] == 0)) { truenumber = j; Arraycount[j][2] = 1; break; }
	/*		 number1 = (int) (Arraycountfl[i+1] * Quant);
			 number2 = (int) (Arraycountfl[i] * Quant);
			if (number1 == number2) flag = 1;
			for (int j = 0;!(j == k); ++j){
				if (Arraycount[j] == number1 & flag == 1)  {  flag = 0; continue;  }
				if (Arraycount[j] == number1 & flag == 0 & ArrayCode[j] == "")  { truenumber = j;  break; }
			}*/
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
		/*	int number = (int) (Arraycountfl[i+1] * Quant);
			for (int j = 0;!(j == k); ++j)
			if (Arraycount[j] == number)  truenumber = j;  

			ArrayCode[truenumber] =+ '0';**/

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
	return 0;

}