#include <stdio.h>
#include <string.h>
#include <ctype.h>
void createTable(char *key, char table[5][5]) {
    int used[26] = {0}, i = 0, j = 0;
        for (int k = 0; key[k]; k++) {
        char ch = toupper(key[k]);
        if (ch == 'J') ch = 'I'; 
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            table[i][j++] = ch;
            used[ch - 'A'] = 1;
            if (j == 5) { j = 0; i++; }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue; 
        if (!used[ch - 'A']) {
            table[i][j++] = ch;
            if (j == 5) { j = 0; i++; }
        }
    }
}

void processMessage(char *message, char *processedMessage) {
    int j = 0;
    for (int i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            processedMessage[j++] = toupper(message[i]);
        }
    }
    processedMessage[j] = '\0';

    if (j % 2 != 0) {
        processedMessage[j++] = 'X';
    }
    processedMessage[j] = '\0';
}

void encryptPlayfair(char *message, char *key, char *encryptedText) {
    char table[5][5];
    createTable(key, table);
    char processedMessage[100];
    processMessage(message, processedMessage);

    int k = 0;
    for (int i = 0; processedMessage[i]; i += 2) {
        char first = processedMessage[i], second = processedMessage[i + 1];
        int r1, c1, r2, c2;
                for (r1 = 0; r1 < 5; r1++) for (c1 = 0; c1 < 5; c1++) if (table[r1][c1] == first)
            for (r2 = 0; r2 < 5; r2++) for (c2 = 0; c2 < 5; c2++) if (table[r2][c2] == second) {
                                if (r1 == r2) { 
                    c1 = (c1 + 1) % 5;
                    c2 = (c2 + 1) % 5;
                }
                else if (c1 == c2) { 
                    r1 = (r1 + 1) % 5;
                    r2 = (r2 + 1) % 5;
                }
                else { 
                    int temp = c1;
                    c1 = c2;
                    c2 = temp;
                }

                encryptedText[k++] = table[r1][c1];
                encryptedText[k++] = table[r2][c2];
                break;
            }
    }
    encryptedText[k] = '\0';
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char key[] = "MFHIJKUNOPQZVWXYELARGDSTBC";
    char encryptedText[200];

    printf("Original Message: %s\n", message);

    encryptPlayfair(message, key, encryptedText);

    printf("Encrypted Text: %s\n", encryptedText);
    return 0;
}
