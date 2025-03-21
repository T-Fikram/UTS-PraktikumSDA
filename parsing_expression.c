#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define OPERAND(ch) ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))

typedef struct {
    int top;
    char *item[MAX]; // Stack stores strings (char arrays)
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

void push(Stack *s, char *value) {
    if (cek_penuh(s)) {
        printf("Stacknya Udah Penuh hai!\n");
        return;
    }
    s->item[++(s->top)] = value;
}

char* pop(Stack *s) {
    if (cek_kosong(s)) {
        printf("Stacknya Masih Kosong lah cik!\n");
        exit(EXIT_FAILURE);
    }
    return s->item[(s->top)--];
}

char* peek(Stack *s) {
    if (cek_kosong(s)) {
        printf("Stack Kosong! mau tengok apa coba\n");
        exit(EXIT_FAILURE);
    }
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

void balik_string(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int apakah_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Prototype
void infixToPostfix(char infix[], char postfix[]);
void infixToPrefix(char infix[], char prefix[]);
void PostfixToInfix(char postfix[], char infix[]);
void PostfixToPrefix(char postfix[], char prefix[]);
void PrefixToInfix(char prefix[], char infix[]);
void PrefixToPostfix(char prefix[], char postfix[]);

// Main function
int main() {
    int pilihan;
    char ekspresi[MAX], hasil[MAX];
    // keknya nanti kita buat perulangan aja di sini
    while(1){
    printf("1. Infix ke Postfix\n2. Infix ke Prefix\n3. Postfix ke Infix\n4. Postfix ke Prefix\n5. Prefix ke Infix\n6. Prefix ke Postfix\n7. Keluar\n-------------------------\n");
    printf("Ahoi! Nak buat ape? -> ");
    scanf("%d", &pilihan);
    getchar(); // To consume the newline character after scanf
    switch (pilihan) {
        case 1:
        case 2:
            printf("\ntamong operasi infix di sini --> ");
            fgets(ekspresi, MAX, stdin);
            // Menghapus newline ('\n') yang mungkin terbawa dari fgets
            ekspresi[strcspn(ekspresi, "\n")] = 0;
            
            if (pilihan == 1) {
                infixToPostfix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            else if (pilihan == 2) {
                infixToPrefix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            break;
        case 3:
        case 4:
            printf("tamong operasi Postfix di sini --> ");
            fgets(ekspresi, MAX, stdin);
            ekspresi[strcspn(ekspresi, "\n")] = 0;

            if (pilihan == 3) {
                PostfixToInfix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            else if (pilihan == 4) {
                PostfixToPrefix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            printf("Ketik enter untuk lanjut");
            scanf("%c", &pilihan);
            break;
        case 5:
        case 6:
            printf("tamong operasi Prefix di sini --> ");
            fgets(ekspresi, MAX, stdin);
            ekspresi[strcspn(ekspresi, "\n")] = 0;

            if (pilihan == 5) {
                PrefixToInfix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            else if (pilihan == 6) {
                PrefixToPostfix(ekspresi, hasil);
                printf("Hasil nibak peurubahan nyan nakeuh lagèe nyoe : %s\n", hasil);
            }
            printf("Ketik enter untuk lanjut");
            scanf("%c", &pilihan);
            break;
        case 7:
         printf("sampai jumpa || adios");
         return 0;

        default:
            printf("Pilihan tidak valid!\n");
            break;
    }
    
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
            // tambah ke postfix kalau operand
            postfix[j++] = ch;
        } else if (ch == '(') {
            // push ke stack
            char *parenthesis = (char *)malloc(2 * sizeof(char));
            sprintf(parenthesis, "%c", ch);
            push(&s, parenthesis);
        } else if (ch == ')') {
            // kalau ), pop operator sampai jumpa (
            while (!cek_kosong(&s) && strcmp(peek(&s), "(") != 0) {
                char *op = pop(&s);
                postfix[j++] = op[0]; // masukkan operator ke postfix
                free(op); 
            }
            char *leftParenthesis = pop(&s); // pop ( dari stack
            free(leftParenthesis); 
        } else {
            // If it's an operator, pop higher-priority operators from the stack
            while (!cek_kosong(&s) && prioritas(peek(&s)[0]) >= prioritas(ch)) {
                char *op = pop(&s);
                postfix[j++] = op[0]; // Add the operator to the postfix expression
                free(op); // Free the memory allocated for the operator
            }
            // Push the current operator onto the stack as a string
            char *operator = (char *)malloc(2 * sizeof(char));
            sprintf(operator, "%c", ch);
            push(&s, operator);
        }
        i++; 
    }

    // Pop any remaining operators from the stack
    while (!cek_kosong(&s)) {
        char *op = pop(&s);
        postfix[j++] = op[0]; 
        free(op); 
    }

    postfix[j] = '\0'; 
}

void infixToPrefix(char infix[], char prefix[]) {
    Stack s;
    inisialisasi(&s);
    char temp[MAX];

    // Balik infix
    balik_string(infix);

    // Konversi infix yang sudah dibalik ke postfix
    infixToPostfix(infix, temp);

    // Balik hasil postfix jadi prefix
    balik_string(temp);
    strcpy(prefix, temp);
}

void PostfixToInfix(char postfix[], char infix[]) {
    Stack s;
    inisialisasi(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // push kalau jumpa operand
        if (OPERAND(ch)) {
            char *operand = (char *)malloc(2 * sizeof(char)); 
            sprintf(operand, "%c", ch); // ubah operand ke string
            push(&s, operand); // push operand
        }
        // kalau operator
        else if (apakah_operator(ch)) {
            // pop 2 operand
            char *op2 = pop(&s); // operand 2
            char *op1 = pop(&s); // operand 1
            
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 4) * sizeof(char));
            sprintf(newExpr, "(%s%c%s)", op1, ch, op2); // menggabungkan operand dan operator

            // Push infix baru ke stack
            push(&s, newExpr);

            // free memory tuk operand
            free(op1);
            free(op2);
        }
    }
    // masukkan hasil ke infix(sekaligus)
    strcpy(infix, pop(&s));
}

void PostfixToPrefix(char postfix[], char prefix[]) {
    Stack s;
    inisialisasi(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // push jika operand
        if (OPERAND(ch)) {
            char *operand = (char *)malloc(2 * sizeof(char)); 
            sprintf(operand, "%c", ch); // ubah operand ke string
            push(&s, operand); // push operand
        }
        // jika operator, maka
        else if (apakah_operator(ch)) {
            // Pop 2 operand
            char *op2 = pop(&s); // Operand 2
            char *op1 = pop(&s); // Operand 1
            // alokasi memori tuk prefix baru
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 2) * sizeof(char));
            sprintf(newExpr, "%c%s%s", ch, op1, op2); // gabungkan operator dan operand
            // push prefix baru
            push(&s, newExpr);
            free(op1);
            free(op2);
        }
    }
    // masukkan stack ke prefix
    strcpy(prefix, pop(&s));
}

void PrefixToInfix(char prefix[], char infix[]) {
    Stack s;
    inisialisasi(&s);

    int length = strlen(prefix);

    // perulangan dari kanan ke kiri
    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        // push kalau operand
        if (OPERAND(ch)) {
            char *operand = (char *)malloc(2 * sizeof(char)); 
            sprintf(operand, "%c", ch); 
            push(&s, operand);
        }
        // kalau operator
        else if (apakah_operator(ch)) {
            // pop dua operand secara urut
            char *op1 = pop(&s); // Operand 1
            char *op2 = pop(&s); // Operand 2

            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 4) * sizeof(char));
            sprintf(newExpr, "(%s%c%s)", op1, ch, op2); // gabungkan

            // push semua ke stack
            push(&s, newExpr);

            free(op1);
            free(op2);
        }
    }

    // pop semua stack ke infix
    strcpy(infix, pop(&s));
}

void PrefixToPostfix(char prefix[], char postfix[]) {
    Stack s;
    inisialisasi(&s);

    int length = strlen(prefix);

    // perulangan dari kanan ke kiri
    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (OPERAND(ch)) {
            char *operand = (char *)malloc(2 * sizeof(char));
            sprintf(operand, "%c", ch);
            push(&s, operand);
        } else if (apakah_operator(ch)) {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 2) * sizeof(char));
            sprintf(newExpr, "%s%s%c", op1, op2, ch);
            push(&s, newExpr);
            free(op1);
            free(op2);
        }
    }

    // pop semua stack ke postfix
    strcpy(postfix, pop(&s));
}
