#include"Header.h"
#include <stdio.h>
#include <stdlib.h>


void readFile(char* buffer, long long* size) {

    FILE* file;
    errno_t err = fopen_s(&file, "C:/Users/Eisim/Documents/voyna_i_mir.txt", "r");

    if (err != 0) {
        printf("File was not opened");
    }
    else {

        int c;
        long long counter = 0;
        while ((c = fgetc(file)) != EOF) {
            buffer[counter++] = (char)c;
        }
        *size = counter;


        buffer[counter++] = '\0';



        fclose(file);

    }
}


bool isLetter(char letter){
    //for Russian
    if (letter=='¸'||((int)letter>=(int)'à' && (int)letter<=(int)'ÿ')  || letter == '¨' || ((int)letter >= (int)'À' && (int)letter <= (int)'ß'))
        return true;
    //for English
    if (((int)letter >= (int)'a' && (int)letter <= (int)'z') || ((int)letter >= (int)'A' && (int)letter <= (int)'Z'))
        return true;
    return false;
}
bool isSimilarLetter(char letter1,char letter2) {
    if (isLetter(letter1) && isLetter(letter2)) {
        if (letter1==letter2 || (int)letter1==(int)letter2-32|| (int)letter1 == (int)letter2 + 32)//32-is a step resizing letter 
            return true;

    }

    return false;
}

int findWord(char* text, long long Tlenght, char* Fword, int FWlenght) {
    int Wcounter = 0;
    bool similar;
    for (int i = 0; i <= Tlenght-FWlenght; i++) {
        similar = true;
        for (int Windex=0; Windex < FWlenght; Windex++) {
            if (!isSimilarLetter(Fword[Windex],text[i+Windex])) {
                similar = false;
            }
        }
        if (similar)
            Wcounter++;
    }

    return Wcounter;
}



int getLenght(char* text) {
    int lenght = 0;
    while (text[lenght] != '\0')
        lenght++;

    return lenght;
}


