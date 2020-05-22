#ifndef MORSE_H_INCLUDED
#define MORSE_H_INCLUDED
typedef struct node{
    char letters;
    struct node *dot;
    struct node *dash;
}node;

node* newNode(char letters){
        node* nod = ( node*)malloc(sizeof(node));
        nod->letters = letters;

        nod->dot = NULL;
        nod->dash = NULL;
        return(nod);
}

/**

*/
node* data(){

    node *letter = newNode('#');

    letter->dot = newNode('E');
    letter->dash = newNode('T');
    letter->dot->dot = newNode('I');
    letter->dot->dash = newNode('A');
    letter->dash->dot = newNode('N');
    letter->dash->dash = newNode('M');
    letter->dot->dot->dot = newNode('S');
    letter->dot->dot->dash = newNode('U');
    letter->dot->dash->dot = newNode('R');
    letter->dot->dash->dash = newNode('W');
    letter->dash->dot->dot = newNode('D');
    letter->dash->dot->dash = newNode('K');
    letter->dash->dash->dot = newNode('G');
    letter->dash->dash->dash = newNode('O');
    letter->dot->dot->dot->dot = newNode('H');
    letter->dot->dot->dot->dash = newNode('V');
    letter->dot->dot->dash->dot   = newNode('F');
    letter->dot->dot->dash->dash   = newNode('#');
    letter->dot->dash->dot->dot   = newNode('L');
    letter->dot->dash->dot->dash   = newNode('#');
    letter->dot->dash->dash->dot   = newNode('P');
    letter->dot->dash->dash->dash   = newNode('J');
    letter->dash->dot->dot->dot   = newNode('B');
    letter->dash->dot->dot->dash   = newNode('X');
    letter->dash->dot->dash->dot   = newNode('C');
    letter->dash->dot->dash->dash   = newNode('Y');
    letter->dash->dash->dot->dot   = newNode('Z');
    letter->dash->dash->dot->dash   = newNode('Q');
    letter->dash->dash->dash->dot   = newNode('#');
    letter->dash->dash->dash->dash   = newNode('#');
    letter->dot->dot->dot->dot->dot   = newNode('5');
    letter->dot->dot->dot->dot->dash   = newNode('4');
    letter->dot->dot->dot->dash->dash   = newNode('3');
    letter->dot->dot->dash->dash->dash   = newNode('2');
    letter->dot->dash->dot->dash->dot   = newNode('#');
    letter->dot->dash->dash->dash->dash   = newNode('1');
    letter->dash->dot->dot->dot->dot   = newNode('6');
    letter->dash->dot->dot->dot->dash   = newNode('#');
    letter->dash->dot->dot->dash->dot   = newNode('#');
    letter->dash->dash->dot->dot->dot   = newNode('7');
    letter->dash->dash->dash->dot->dot   = newNode('8');
    letter->dash->dash->dash->dash->dot   = newNode('9');
    letter->dash->dash->dash->dash->dash   = newNode('0');
    return letter;
}
/*In following two arrays morse values of letters and numbers are in the same order, e.g D and its morse value have the same number of place in array. */
char *dataBase[37] = {".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..","-----",
                ".----","..---","...--","....-",".....",
                "-....","--...","---..","----."};
char *database2[37] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
               "P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3",
                "4","5","6","7","8","9"};



#endif // MORSE_H_INCLUDED
