#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include <locale.h>
#include <wchar.h>

int findWord(wchar_t* text, wchar_t* word)
{
    int res = -2;
    
    if (text && word)
    {
        res = -1;

        int Tab[65536];
        for (int i = 0; i < 65536; i++)
        {
            if ((L'0' <= i && i <= L'9') ||
                (L'A' <= i && i <= L'Z') ||
                (L'a' <= i && i <= L'z') ||
                (L'А' <= i && i <= L'Я') ||
                (L'а' <= i && i <= L'я'))
            {
                Tab[i] = 0;
            }
            else
            {
                Tab[i] = 1;
            }
        }
        Tab[L'ё'] = 0;
        Tab[L'Ё'] = 0;
        Tab[L'\0'] = 2;
        Tab[L'.'] = 2;
        Tab[L'?'] = 2;
        Tab[L'!'] = 2;
    
        bool EndOfText = false;
        bool wFound = false;

        size_t i = 0;
        size_t word_len = wcslen(word);

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
            wchar_t buff[200] = {0};

            while (Tab[text[i]] != 1 && Tab[text[i]] != 2)
            {
                buff[j] = text[i];
                j++;
                i++;
            }
            buff[j] = L'\0';

            if (!wcscmp(word, buff))
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
    wchar_t Wstr[27] = L"abcd abcd bbc abc abc. abc\0";
    //wchar_t Wstr[23] = L"abcd abcd bbc abc. abc\0";
    //wchar_t Wstr[26] = L"abc abcd bbc abc acb. abc\0";
    //wchar_t Wstr[4] = L"abc\0";

    wchar_t Wsubstr[4] = L"abc\0";

    //wchar_t Wstr[12] = L"abc ффв bфc\0";
    //wchar_t Wsubstr[4] = L"ффв\0";

    int cnt = 0;

    int i = 0;
    size_t word_len = wcslen(Wsubstr);
    
    int res = findWord(Wstr, Wsubstr);

    if (res != -2)
    {
        while (res != -1)
        {
            cnt++;

            i = i + (res + word_len - 1);
            res = findWord(&Wstr[i], Wsubstr);
        }

        printf("Words found: %d\n", cnt);
    }
    else
    {
        printf("NULL pointer\n");
    }

    return 0;
}
