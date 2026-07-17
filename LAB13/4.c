#include "stdio.h"
#include"stdlib.h"
#include"string.h"
char s[50];
int TOP=-1;
void push(char x);
int main(){
    char str[50];
    int i=0,b=0;
    printf("enter the string:");
    scanf("%s",str);
    char ch=str[0];
    while(str[i]!='\0'){
      
      if(str[i]=='a') {
          push(str[i]);
    } 

    else{
        b++;
    }
    i++;
}
       
    if(TOP+1==b){
        printf("valid string\n");
        printf("i=%d",b);
    }
    else{
        printf("invalid string");
    }
   

}


void push(char x){
 if (TOP >= 49)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        s[++TOP] = x;
        
    }
}