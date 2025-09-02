#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <cs50.c>

bool checkKey(char key[]);
void cipher(char text[],char key[]);

int main(int argc,char *argv [])
{
   if(argc!=2){
    printf("There should be only one argument, not more or less \n");
    return 1;
   }
   if(!(checkKey(argv[1]))){
    printf("Key is Not Valid Try Again!!\n");
    return 1;
   }
   
   string text=get_string("plaintext : ");
   cipher(text,argv[1]);
    return 0;
}
bool checkKey(char key[]){
    int length=strlen(key);
    if(strlen(key)!=26){
        
        printf("key must contain 26 characters only\n");
        return false;
    }
    char upperCaseKey[26];
    for(int i=0;i<length;i++){
         if(!(isalpha(key[i]))){
                printf("key contains characters that are not letters\n");
                return false;
            }
        upperCaseKey[i]=toupper(key[i]);
    }
    for(int i=65;i<=90;i++){
        int count=0;
        for(int j=0;j<26;j++){
            char ch=upperCaseKey[j];
            if(i==ch){
                count++;
            }
        }
        if(count!=1){
            printf("the key contains more than 1 characters of same letter \n");
            return false;
        }
    }
    return true;
}

 void cipher(char text[],char key[]){
    char ciphertext[26]="";
    for(int i=0;i<strlen(text);i++){
        char ch=text[i];
        char cipherchar;
        if(!isalpha(ch)){
            cipherchar=ch;
        }
        else if(isupper(ch)){
            cipherchar=toupper(key[((int)ch)-65]);
        }
        else{
            cipherchar=tolower(key[((int)ch)-97]);
        }
        ciphertext[i]=cipherchar;
    }
    printf("ciphertext : %s \n",ciphertext);
}