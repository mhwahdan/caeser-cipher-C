#include <stdio.h>
#include <stdlib.h>

unsigned char characters[] = {
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '
};

char* encrypt(unsigned char* plaintext,int length,int key) {
    unsigned char* result = (unsigned char*) malloc((length) * sizeof(unsigned char));
    for(int i = 0 ; i < length; i++)
    {
        for(int j = 0; j < 27; j++)
            if(plaintext[i] == characters[j])
                result[i]= characters[(j + key) % 27];
    }
    result[length] = '\0';
    return result;
}

char* decrypt(unsigned char* cipher,int length,int key) {
    unsigned char*  result = (unsigned char*) malloc((length) * sizeof(unsigned char));
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
    unsigned char* plain = "rome is the greatest empire";
    unsigned char* cipher = "yvtlgpzg olgnylh lz gltwpyl";
    printf("%s\n", encrypt(plain, 27, key));
    printf("%s\n", decrypt(cipher, 27, key));
    return 0;
}
