#include"Header.h"

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

int findWord(char* text, long long Tlenght, char* Fword, int FWlenght) {
    long long Wcount = 0;
    int indicator = 0;

    for (int i = 0; i <= Tlenght; i++) {
        if ((int)text[i] == (int)(Fword[indicator]) || (int)text[i]==((int)Fword[indicator]+32) || (int)text[i] == ((int)Fword[indicator] - 32)) {
            indicator++;
        }
        else
            indicator = 0;
        if (indicator == FWlenght) {
            indicator = 0;
            Wcount++;
        }
    }

    return Wcount;
}


int getLenght(char* text) {
    int lenght = 0;
    while (text[lenght] != '\0')
        lenght++;

    return lenght;
}

