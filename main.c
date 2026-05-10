#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include <wchar.h>
#include <locale.h>

static int Tab[65536];
static bool TabInit = false;

void InitTab()
{
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

    TabInit = true;
}

int countWord(wchar_t* text, wchar_t* word)
{
    int res = -1;
    
    if (text && word)
    {
        res = 0;

        if (!TabInit)
        {
            InitTab();
        }
    
        bool EndOfText = false;

        size_t i = 0;

        while (!EndOfText)
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
                res++;
            }
        }
    }

    return res;
}

int main()
{
    setlocale(LC_ALL, "");
    
    if (!TabInit)
    {
        InitTab();
    }
    
    wchar_t Wstr[27] = L"abcd abcd bbc abc abc. abc\0";
    //wchar_t Wstr[31] = L"abcd ффв abcd bbc abc abc. abc\0";

    int i = 0;
    bool EndOfText = false;

    while (!EndOfText)
    {
        while (Tab[Wstr[i]] == 1)
        {
            i++;
        }
        if (Tab[Wstr[i]] == 2)
        {
            EndOfText = true;
        }

        int j = 0;
        wchar_t buff[100] = {0};

        while (Tab[Wstr[i]] != 1 && Tab[Wstr[i]] != 2)
        {
            buff[j] = Wstr[i];
            j++;
            i++;
        }
        buff[j] = L'\0';

        if (countWord(Wstr, buff) == 1)
        {
            wprintf(L"%s\n", buff);
        }
    }

    return 0;
}