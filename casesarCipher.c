#include<stdio.h>
#include<ctype.h>

int main()
{
    char text[100],ch;
    int key=0;
    printf("Enter the string=");
    scanf("%s",text);
    printf("Enter the key=");
    scanf("%d",&key);

    for(int i=0;text[i] != '\0';i++)
    {
        ch = text[i];
        if(isalnum(text[i]))
        {
            if(islower(ch))
            {
                ch = (ch + key - 'a') % 26 + 'a';
            }
            else if(isupper(ch))
            {
                ch = (ch + key -'A') % 26 + 'A';
            }
            text[i] = ch;
        }
        else
        {
            printf("invalid string");
        }
    }
    printf("Encrypted test id %s",text);

    return 0;
}
