#include <stdio.h>
#include <string.h>
#include <ctype.h>
void remove_duplicates(char *keyword) {
    int len = strlen(keyword);
    int index = 0;
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (keyword[i] == keyword[j]) {
                for (int k = j; k < len; k++) {
                    keyword[k] = keyword[k + 1];
                }
                len--; 
                j--; 
            }
        }
    }
}
void generate_cipher_alphabet(char *keyword, char *cipher_alphabet) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int used[26] = {0}; 
    int index = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher_alphabet[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!used[i]) {
            cipher_alphabet[index++] = alphabet[i];
        }
    }
    cipher_alphabet[index] = '\0'; 
}
void encrypt(char *plaintext, char *cipher_alphabet, char *ciphertext) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int j = 0;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            int index = ch - 'A';
            ciphertext[j++] = cipher_alphabet[index];
        } else {
            ciphertext[j++] = plaintext[i]; 
        }
    }
    ciphertext[j] = '\0'; 
}
int main() {
    char keyword[] = "CIPHER"; 
    char plaintext[100], ciphertext[100], cipher_alphabet[27];
        remove_duplicates(keyword);
    generate_cipher_alphabet(keyword, cipher_alphabet);
        printf("Cipher Alphabet: %s\n", cipher_alphabet);
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    encrypt(plaintext, cipher_alphabet, ciphertext);
        printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}
