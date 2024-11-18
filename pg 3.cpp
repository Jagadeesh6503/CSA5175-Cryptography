#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100], matrix[5][5], cipher[100];
    int used[26] = {0}; // To track used letters
    char alphabet[] = "abcdefghiklmnopqrstuvwxyz"; // 'j' excluded

    // Input plaintext and keyword
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline from fgets

    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline from fgets

    // Fill the 5x5 matrix with keyword characters
    int k = 0;
    for (int i = 0; key[i]; i++) {
        char ch = tolower(key[i]);
        if (isalpha(ch) && !used[ch - 'a']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'a'] = 1;
            k++;
        }
    }

    // Fill remaining matrix positions with the rest of the alphabet (excluding 'j')
    for (int i = 0; alphabet[i]; i++) {
        if (!used[alphabet[i] - 'a']) {
            matrix[k / 5][k % 5] = alphabet[i];
            used[alphabet[i] - 'a'] = 1;
            k++;
        }
    }

    // Prepare the plaintext (remove non-alphabets and handle odd length)
    int len = strlen(text), j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) text[j++] = tolower(text[i]);
    }
    if (j % 2 != 0) text[j++] = 'x';  // Add 'x' if odd length
    text[j] = '\0';  // Null terminate the prepared text

    // Encrypt the text in pairs
    int m = 0;
    for (int i = 0; i < j; i += 2) {
        char a = text[i], b = text[i + 1];
        int row1, col1, row2, col2;

        // Find positions of 'a' and 'b' in the matrix
        for (row1 = 0; row1 < 5; row1++) for (col1 = 0; col1 < 5; col1++) if (matrix[row1][col1] == a) break;
        for (row2 = 0; row2 < 5; row2++) for (col2 = 0; col2 < 5; col2++) if (matrix[row2][col2] == b) break;

        // Apply Playfair rules
        if (row1 == row2) { 
            cipher[m++] = matrix[row1][(col1 + 1) % 5]; 
            cipher[m++] = matrix[row2][(col2 + 1) % 5]; 
        }
        else if (col1 == col2) { 
            cipher[m++] = matrix[(row1 + 1) % 5][col1]; 
            cipher[m++] = matrix[(row2 + 1) % 5][col2]; 
        }
        else { 
            cipher[m++] = matrix[row1][col2]; 
            cipher[m++] = matrix[row2][col1]; 
        }
    }

    cipher[m] = '\0';  // Null terminate the ciphertext
    printf("Ciphertext: %s\n", cipher);

    return 0;
}

