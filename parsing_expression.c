#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define OPERAND(ch) ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))

typedef struct {
    int top;
    char item[MAX];
} Stack;

void inisialisasi(Stack *s) {
    s->top = -1; // buat stack kosong
}

bool cek_kosong(Stack *s) {
    return (s->top == -1);
}

bool cek_penuh(Stack *s) {
    return (s->top == MAX - 1);
}

void push(Stack *s, char value) {
    if (cek_penuh(s)) {
        printf("Stacknya Udah Penuh hai!\n");
        return;
    }
    s->item[++(s->top)] = value;
}

char pop(Stack *s) {
    if (cek_kosong(s)) {
        printf("Stacknya Masih Kosong lah cik!\n");
        exit(EXIT_FAILURE);
    }
    return s->item[(s->top)--];
}

char peek(Stack *s) {
    return s->item[s->top];
}

int prioritas(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Prototype
void infixToPostfix(char infix[], char postfix[]);

// Main function
int main() {
    int pilihan;
    char ekspresi[MAX], hasil[MAX];
    // keknya nanti kita buat perulangan aja di sini
    printf("1. Infix ke Postfix\n2. Infix ke Prefix\n-------------------------\n");
    printf("Ahoi! Nak buat ape? -> ");
    scanf("%d", &pilihan);
    getchar(); // To consume the newline character after scanf
    switch (pilihan) {
        case 1:
        case 2:
            printf("tamong operasi infix di sini --> ");
            fgets(ekspresi, MAX, stdin);
            // Menghapus newline ('\n') yang mungkin terbawa dari fgets
            ekspresi[strcspn(ekspresi, "\n")] = 0;
            
            if (pilihan == 1) {
                infixToPostfix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            else if (pilihan == 2) {
                // infixToPrefix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            break;
        case 3:
        case 4:
            // kita rehat sejenak

        default:
            printf("Pilihan tidak valid!\n");
            break;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s; 
    inisialisasi(&s); 
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (OPERAND(ch)) {
            postfix[j++] = ch; // kalau jumpa operand berarti tambahkan ke postfix
        } else if (ch == '(') {
            push(&s, ch); // kalau jumpa ni (, masukkan ke stack
        } else if (ch == ')') {
            while (!cek_kosong(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s); 
            }
            pop(&s); // kalau jumpa ni ), popkan ni (
        } else {
            while (!cek_kosong(&s) && prioritas(peek(&s)) >= prioritas(ch)) {
                postfix[j++] = pop(&s); // mengecek tingkatan operator
            }
            push(&s, ch); 
        }
        i++; 
    }

    while (!cek_kosong(&s)) {
        postfix[j++] = pop(&s); 
    }

    postfix[j] = '\0'; 
}
