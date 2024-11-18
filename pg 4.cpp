#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100], cipher[100];
    int i, j = 0;

    // Input plaintext and key
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline from fgets

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline from fgets

    // Encryption process
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            // Make sure the key repeats
            char keyChar = tolower(key[j % strlen(key)]);  // Repeat the key if necessary

            // Encrypt lowercase letters
            if (islower(text[i])) {
                cipher[i] = (text[i] - 'a' + (keyChar - 'a')) % 26 + 'a';
            }
            // Encrypt uppercase letters
            else if (isupper(text[i])) {
                cipher[i] = (text[i] - 'A' + (keyChar - 'a')) % 26 + 'A';
            }

            // Move to the next character in the key
            j++;
        } else {
            // Non-alphabetic characters are not changed
            cipher[i] = text[i];
        }
    }
    cipher[i] = '\0'; // Null terminate the cipher text

    // Output the ciphertext
    printf("Ciphertext: %s\n", cipher);

    return 0;
}

