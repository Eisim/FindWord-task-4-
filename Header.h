#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<windows.h>


void readFile(char* buffer, long long* size);
int findWord(char* text, long long Tlenght, char* Fword, int FWlenght);
int getLenght(char* text);