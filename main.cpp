#include"Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<windows.h>


int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL,"RUS");
    const int MAXLENGHT=1000;
    char Fword[MAXLENGHT];

    printf("Word:");
    scanf_s("%s",Fword,MAXLENGHT);
    int Flenght=getLenght(Fword);

    long long size = 0;

    const int N = 10 * 1024 * 1024;
    char* buffer = (char*)malloc(N * sizeof(char));

    readFile(buffer, &size);


    int result = findWord(buffer,size,Fword,Flenght);
    printf("%s:%d\n",Fword ,result);

    char voyna[6] = "война";
    char mir[4] = "мир";


    printf("война:%d\nмир:%d", findWord(buffer,size,voyna,getLenght(voyna)),findWord(buffer,size,mir,getLenght(mir)));
    

    free(buffer);
    
    return 0;
}