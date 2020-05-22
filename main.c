#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morse.h"



/* This function makes lowercase letters to uppercase,
if letter is already in uppercase it returns the letter*/
char lowerToUpper(char chr1){
    if(chr1 >= 'a' && chr1 <= 'z'){
        return 'A' + chr1 - 'a';
    }
    else{
        return chr1;
    }
}
/** Using lowerToUpper function this function makes lower case letters of entered text into uppercase and after that stores the text in array */
void enterText(char textEntered[512]){
    printf("Enter text:\n");
    gets(textEntered);
    int i = 0;
    while(textEntered[i] != '\0'){
        textEntered[i] = lowerToUpper(textEntered[i]);
        i++;
    }
    printf("\n");
}
/*  this function gets uppercased text and for every letter from the beginning, it counts number of its place in array database2. the morse value of it,
 is the same number place but on dataBase */
void inMorse(char textEntered[],char morse[512][40]){
    int i = 0;
    while(textEntered[i] != '\0'){
        if(textEntered[i] >= 'A' && textEntered[i] <= 'Z'){ //calculating the place number for letter
            strcpy(morse[i],dataBase[textEntered[i] - 'A']);
        }else if(textEntered[i] >= '0' && textEntered[i] <= '9'){ // calculating th place number for numbers
            strcpy(morse[i],dataBase['Z' - 'A' + textEntered[i] - '0']);
        }else if(textEntered[i] == ' '){
            morse[i][0] = ' ';
            morse[i][1] = ' ';
        }
        i++;
    }

}

void find(node * root,node * curr, char * morseCode){
    if(*morseCode == ' ' && *(morseCode + 1) == ' '){
        printf("%c ",curr->letters);
        find(root,root,morseCode + 2);
    }else if(*morseCode == ' '){
        printf("%c",curr->letters);
        find(root,root,morseCode + 1);
    }else if(*morseCode == '\0'){
        printf("%c",curr->letters);
    }else if(*morseCode == '.'){
        find(root,curr->dot,morseCode + 1);
    }else if(*morseCode == '-'){
        find(root,curr->dash,morseCode + 1);
    }else{
        printf("Invalid characters!\n");
    }
}
/* this function gets the array of the letters that are entered to be converted in morse and the letters are already in upper case.*/
int encodeStatLett(char chr1[]){
    int letStat = 0;
    for(int i = 0; i<512; i++){
        if(chr1[i] == '\0'){
            break;
        }
        if(chr1[i] != ' '){
            letStat++;
        }
    }
    return letStat;
}

void encodestatdotdash(char chr1[512][40],int dotdashstat[2], int letterNum){

    for(int i = 0; i<letterNum; i++){
        for(int j = 0; j<40; j++){
            if(chr1[i][0] == '\0'){
                break;
            }
            if(chr1[i][j] == '.'){
                dotdashstat[0]++;
            }else if(chr1[i][j] == '-'){
               dotdashstat[1]++;
            }
        }
    }
}

int decodeStats(char chr2[]){

}
//
int main(){
    FILE *f;
    f=fopen("Statistics", "wt");
    printf("if u want to close the program enter * symbol");

    while(1){
        int letterNum = 0;

       // dotdashnum = 0;
       int dotnum = 0 ;
       int dashnum = 0;
        char t[1];
        printf("\nType 'e' if u want to encode, type 'd' if you want to decode : ");
        gets(t);
        if(t[0] == 'e'){
            char text[512];
            char end[512][40];
            enterText(text);
            inMorse(text,end);
            int i = 0;
            while(end[i][0] != '\0'){
                printf("%s ", end[i]);
                i++;

            }

            letterNum = encodeStatLett(text);
            int dotDashNum[2] = {0,0};
            encodestatdotdash(end,dotDashNum,letterNum);
            printf("dot-%d dash-%d\n",dotDashNum[0],dotDashNum[1]);
            printf("Letters-%d ", letterNum);
            fprintf(f,"number of letters -> %d\nnumber of dots -> %d\nnumber of dashes -> %d",letterNum,dotDashNum[0],dotDashNum[1]);

        }else if(t[0] == 'd'){
            letterNum = 1;
            printf("\nEnter Morse: ");
            char morseCode[512];
            gets(morseCode);
            node * root = data();
            find(root,root,morseCode);
             for(int i = 0; i<=512; i++){
                    if(morseCode[i] == '\0'){
                        break;
                    }
                    if(morseCode[i] == '.'){
                        dotnum++;
                    }else if(morseCode[i] == '-'){
                        dashnum++;
                    }else if(morseCode[i] == ' '){
                        letterNum++;
                    }
            }
            printf(" Letters-%d\nDashes-%d\nDots-%d ",letterNum,dashnum,dotnum);
            fprintf(f,"number of letters -> %d\nnumber of dots -> %d\nnumber of dashes -> %d",letterNum, dotnum, dashnum);

        }else if(t[0] == '*'){
            printf("Use morse converter again!");
            break;
        }else{
        printf("Please type 'e' or 'd'");
        }

         fclose(f);
    }
    return 0;
}








