#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char s[50];
int TOP = -1;
int main()
{
    char str[50],c[2];
    c[1]='\0';

    int i = 0, b = 0;
    printf("enter the string:");
    scanf("%s", str);
    c[0]=str[0];
    while (str[i] != '\0')
    {
      if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
        strrev(s);
        strcat(s,c);
      }
      else{
                strcat(s,c);

      }
      c[0]=str[++i];
    }
    printf("string:%s",s);
    return 0;
}



