#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createTable(char *key, char table[5][5]) {
    int used[26] = {0}, i = 0, j = 0;

    // Process the key
    for (int k = 0; key[k]; k++) {
        char ch = toupper(key[k]);
        if (ch == 'J') ch = 'I'; // Treat 'J' as 'I'
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            table[i][j++] = ch;
            used[ch - 'A'] = 1;
            if (j == 5) { j = 0; i++; }
        }
    }

    // Fill in the remaining letters of the alphabet
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue; // Skip 'J'
        if (!used[ch - 'A']) {
            table[i][j++] = ch;
            if (j == 5) { j = 0; i++; }
        }
    }
}

void decryptPlayfair(char *cipherText, char *key, char *decryptedText) {
    char table[5][5];
    createTable(key, table);
    int k = 0;

    for (int i = 0; cipherText[i]; i += 2) {
        char first = toupper(cipherText[i]), second = toupper(cipherText[i + 1]);
        int r1, c1, r2, c2;

        // Find positions of the characters in the table
        for (r1 = 0; r1 < 5; r1++) for (c1 = 0; c1 < 5; c1++) if (table[r1][c1] == first)
            for (r2 = 0; r2 < 5; r2++) for (c2 = 0; c2 < 5; c2++) if (table[r2][c2] == second) {

                // Apply Playfair cipher decryption rules
                if (r1 == r2) { // Same row
                    c1 = (c1 - 1 + 5) % 5;
                    c2 = (c2 - 1 + 5) % 5;
                }
                else if (c1 == c2) { // Same column
                    r1 = (r1 - 1 + 5) % 5;
                    r2 = (r2 - 1 + 5) % 5;
                }
                else { // Rectangle
                    int temp = c1;
                    c1 = c2;
                    c2 = temp;
                }

                decryptedText[k++] = table[r1][c1];
                decryptedText[k++] = table[r2][c2];
                break;
            }
    }
    decryptedText[k] = '\0';
}

int main() {
    char cipherText[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char key[] = "PT109 JFK", decryptedText[200];

    // Decrypt the message
    decryptPlayfair(cipherText, key, decryptedText);

    printf("Decrypted Text: %s\n", decryptedText);
    return 0;
}
