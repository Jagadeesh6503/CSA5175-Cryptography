#include <stdio.h>
#include <string.h>
void decrypt_substitution(char* ciphertext, char* key, char* alphabet) {
    int len = strlen(ciphertext);
    
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] != ' ') {
            for (int j = 0; j < strlen(key); j++) {
                if (ciphertext[i] == key[j]) {
                    printf("%c", alphabet[j]);
                    break;
                }
            }
        } else {
            printf(" "); 
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
	   
    
    char key[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"; 
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted Plaintext: ");
        decrypt_substitution(ciphertext, key, alphabet);
    
    return 0;
}
