#include <stdio.h>
#include <ctype.h>
int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}
char affine_decrypt(char c, int a_inv, int b) {
    if (isalpha(c)) {
        c = toupper(c) - 'A'; 
        c = (a_inv * (c - b + 26)) % 26; 
        return c + 'A'; 
    }
    return c; 
}
int main() {
    int C1 = 1, C2 = 20; 
    int P1 = 4, P2 = 19; 
    int a = (C2 - C1) * mod_inverse(P2 - P1, 26) % 26;
    if (a < 0) a += 26; 
    int b = (C1 - a * P1) % 26;
    if (b < 0) b += 26; 
    int a_inv = mod_inverse(a, 26);
    if (a_inv == -1) {
        printf("Error: 'a' has no modular inverse. Invalid keys.\n");
        return 1;
    }
    char ciphertext[] = "BUBBUBU";
    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        putchar(affine_decrypt(ciphertext[i], a_inv, b));
    }
    printf("\n");
    printf("Keys found: a = %d, b = %d\n", a, b);
    return 0;
}
