#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {

	FILE *fin, *fout;
	char inFileName[BUFSIZ], outFileName[BUFSIZ];
	string Arraycode[BUFSIZ] = {""} ;
	char Array[BUFSIZ]  = {""};
	char ch, ch1 ;
	int k = 0, FileCounter = 0 ;
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
	 
	ch = fgetc(fin); // зчитування першого символу
	Array[k] = ch; ++k;
	++FileCounter ; 
	while ( ((ch = fgetc(fin)) != (char) 32)  |  ((ch1 = fgetc(fin)) != (char) 32) ){
//	while ()
		++FileCounter;
		fseek(fin, FileCounter, SEEK_SET);       

	//	if (ch == ' ' & ch1 == ' ') break ;

		if ((ch != '0') & (ch != '1')) {
			Array[k] = ch;
			++k;
		}
	}

	fseek(fin, 0 , SEEK_SET);
	k = -1;
	FileCounter = 0 ;

//	++FileCounter ; 
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
	return 0;

}