#include <stdio.h>

int main() {
    char text[100];
    int a, b;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a (multiplier): ");
    scanf("%d", &a);
    printf("Enter b (increment): ");
    scanf("%d", &b);

    // Encrypt text
    for (int i = 0; text[i] != '\0'; i++) {
        if ('a' <= text[i] && text[i] <= 'z')
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
        else if ('A' <= text[i] && text[i] <= 'Z')
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';
    }
    printf("Encrypted text: %s\n", text);

    // Find modular inverse of 'a'
    int a_inv = -1;
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    if (a_inv == -1) {
        printf("Inverse not found, decryption impossible.\n");
        return 1;
    }

    // Decrypt text
    for (int i = 0; text[i] != '\0'; i++) {
        if ('a' <= text[i] && text[i] <= 'z')
            text[i] = ((a_inv * (text[i] - 'a' - b + 26)) % 26) + 'a';
        else if ('A' <= text[i] && text[i] <= 'Z')
            text[i] = ((a_inv * (text[i] - 'A' - b + 26)) % 26) + 'A';
    }

    printf("Decrypted text: %s\n", text);
    return 0;
}

