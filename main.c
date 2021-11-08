#include <stdio.h>
#include <stdlib.h>

char characters[] = {
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '
};

char* encrypt(char* plaintext,int length,int key) {
    char* result = (char*) malloc((length) * sizeof(char));
    for(int i = 0 ; i < length; i++)
    {
        for(int j = 0; j < 27; j++)
            if(plaintext[i] == characters[j])
                result[i]= characters[(j + key) % 27];
    }
    result[length] = '\0';
    return result;
}

char* decrypt(char* cipher,int length,int key) {
    char*  result = (char*) malloc((length) * sizeof(char));
    for(int i = 0 ; i < length; i++)
    {
        for(int j = 0; j < 27; j++)
            if(cipher[i] == characters[j])
                result[i]= characters[(j - key + 27) % 27];
    }
    result[length] = '\0';
    return result;
}
int main() {
    int key = 7;
    char* plain = "rome is the greatest empire";
    char* cipher = "yvtlgpzg olgnylh lz gltwpyl";
    printf("%s\n", encrypt(plain, 27, key));
    printf("%s\n", decrypt(cipher, 27, key));
    return 0;
}
