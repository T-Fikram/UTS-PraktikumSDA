#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

#define MAX 100

typedef struct{
    int top;
    char item[MAX];
}Stack;

void inisialisasi(Stack *s){
    s->top = -1; //buat stack kosong
}
bool cek_kosong(Stack *s){
    return(s->top == -1);
}
bool cek_penuh(Stack *s){
    return(s->top == MAX - 1);
}
void push(Stack *s, char value){
    s->item[++(s->top)] == value;
}
void pop(Stack *s, char value){
    s->item[(s->top)--];
}
char peek(Stack *s){
    return s->item[s->top];
}

// Prototype
void infixToPostfix(char infix[], char postfix[]);
void infixToPrefix(char infix[], char prefix[]);
void postfixToInfix(char postfix[], char infix[]);
void prefixToInfix(char prefix[], char infix[]);
void prefixToPostfix(char prefix[], char postfix[]);
void postfixToPrefix(char postfix[], char prefix[]);

/* Bagian utama program
Nanti bakal kita atur input sama menunya (pilihan konversi) */
int main() {
    int pilihan;
    char ekspresi[MAX], hasil[MAX];
    //keknya nanti kita buat perulangan aja di sini
    printf("1. Infix ke Postfix\n2. Infix ke Prefix\n-------------------------\n");
    printf("Ahoi! Nak buat ape?\n");
    pilihan = getch();
    switch(pilihan){
        case 1 || 2:
            printf("tamong operasi infix di sini\n");
            scanf("%s", ekspresi);
            if(pilihan == 1){
                infixToPostfix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            else if(pilihan == 2){
                infixToPrefix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
        
        case 3 || 4:
            //kita rehat sejenak

        default:
    }
}
