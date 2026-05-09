#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int findWord(char* text, char* word)
{
    int res = -2;
    
    if (text && word)
    {
        res = -1;

        int Tab[127];
        for (int i = 0; i < 127; i++)
        {
            Tab[i] = 1;
            
            if ('0' <= i && i <= '9')
            {
                Tab[i] = 0;
            }
            if ('A' <= i && i <= 'Z')
            {
                Tab[i] = 0;
            }
            if ('a' <= i && i <= 'z')
            {
                Tab[i] = 0;
            }
        }
        Tab[0] = 2;
        Tab[33] = 2;
        Tab[46] = 2;
        Tab[63] = 2;
    
        bool EndOfText = false;
        bool wFound = false;

        size_t i = 0;
        size_t word_len = strlen(word);

        while (!EndOfText && !wFound)
        {
            while (Tab[text[i]] == 1)
            {
                i++;
            }
            if (Tab[text[i]] == 2)
            {
                EndOfText = true;
            }

            int j = 0;
            char buff[200] = {0};

            while (Tab[text[i]] != 1 && Tab[text[i]] != 2)
            {
                buff[j] = text[i];
                j++;
                i++;
            }
            buff[j] = '\0';

            if (!strcmp(word, buff))
            {
                res = i - word_len;
                wFound = true;
            }
        }
    }

    return res;
}

int main()
{

    char str[27] = "abcd abcd bbc abc acb. abc\0";
    //char str[23] = "abcd abcd bbc abc. abc\0";
    //char str[26] = "abc abcd bbc abc acb. abc\0";
    //char str[5] = "abc\0";
    
    char substr[4] = "abc\0";

    int res = findWord(str, substr);

    printf("%d %c", res, str[res]);

    return 0;
}
