#include "stdio.h"
#include"stdlib.h"
#include"string.h"
char s[50];
int TOP=-1;
void push(char x);
char pop();
int main(){
    char str[50];
    int i=0;;
    printf("enter the string:");
    scanf("%s",str);
    char ch=str[0];
    while(ch!='c'){
        push(ch);
        ch=str[++i];
    }
    i++;
    while(str[i]!='\0'){
        if(str[i++]!=pop()){
          printf("invalid string");
          return 0;
        }
    }
    printf("valid string");
    return 0;

}
void push(char x){
 if (TOP >= 50 - 1)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        s[++TOP] = x;
        
    }
}
char pop(){

 if (TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return s[TOP--];
    }
}