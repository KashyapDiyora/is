#include<stdio.h>
#include<string.h>

char ciper[100];
char mat[25] = "";
char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
char playFairMatrix[5][5];
char data[2];

void encryption(char ,char );
void convertToLower(char *);
char* group(char *,char *);
char* matrix(char *,char *);
void unique(char );

int main()
{
    char text[100],ch,intermediate[200];
    char key[100];
    char encrypt[200];
    printf("Enter the string=");
    scanf("%s",text);
    printf("Enter the key=");
    scanf("%s",key);
    convertToLower(text);
    // printf("%s",text);
    group(text,intermediate);

    matrix(text,key);
    // printf("%s",mat);
    for(int i=0;intermediate[i] != '\0';i+=2)
    {
        encryption(intermediate[i],intermediate[i+1]);
        encrypt[i] = data[0];
        encrypt[i+1] = data[1];
    }
    printf("\n%s ",intermediate);
    printf("\nencypt data = %s",encrypt);
    return 0;
}

void convertToLower(char *text)
{
    int length = strlen(text);
    for(int i=0;i<length;i++)
    {
        if(text[i]>64 && text[i]<91)
        {
            text[i] += 32;
        }
    }
}

char* group(char *text,char *intermediate)
{
    int k=0;
    int length = strlen(text);
    int i=0;
    while(i<length)
    {
        if(i + 1 < length && text[i] == text[i+1])
        {
            intermediate[k++] = text[i];
            intermediate[k++] = 'x';
            i++;
        }
        else
        {
            intermediate[k++] = text[i];
            intermediate[k++] = text[i+1];
            i+=2;
        }
    }
    return intermediate;
}

void unique(char ch)
{
    int len = strlen(mat);
    if(len==0)
    {
        mat[0] = ch;
        return ;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(ch == mat[i])
                return ;
        }
        mat[len] = ch;
    }
    return ;
}

char* matrix(char *text,char *key)
{
    int len1 = strlen(key);
    int len2 = strlen(alphabet);
    int k=0;
    for(int i=0;i<len1;i++)
    {
        if(key[i] == 'j')
            continue;
        unique(key[i]);
    }
    for(int i=0;i<len2;i++)
    {
        if(alphabet[i] == 'j')
            continue;
        unique(alphabet[i]);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            playFairMatrix[i][j] = mat[k++];
            printf("%c ",playFairMatrix[i][j]);
        }
        printf("\n");
    }
    return NULL;
}

void encryption(char first,char second)
{
    int row1,col1,row2,col2;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(playFairMatrix[i][j] == first)
            {
                row1 = i;
                col1 = j;
            }
            if(playFairMatrix[i][j] == second)
            {
                row2=i;
                col2=j;
            }
        }
    }
    if(col1 == col2)
    {
        data[0] = playFairMatrix[(row1+1)%5][col1];
        data[1] = playFairMatrix[(row2+1)%5][col2];
    }
    else if(row1==row2)
    {
        data[0] = playFairMatrix[row1][(col1+1)%5];
        data[1] = playFairMatrix[row2][(col2+1)%5];
    }
    else
    {
        data[0] = playFairMatrix[row1][col2];
        printf("\n first %d %d",row1,col2);
        data[1] = playFairMatrix[row2][col1];
        printf("\n second %d %d",row2,col1);

    }
    return ;
}
