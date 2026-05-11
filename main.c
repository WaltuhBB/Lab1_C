#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include <wchar.h>
#include <locale.h>

int countWord(wchar_t* text, wchar_t* word, wchar_t* del)
{
    int res = -1;
    
    if (text && word && del)
    {
        res = 0;
    
        bool EndOfText = false;

        size_t i = 0;

        while (!EndOfText)
        {
            while (wcschr(del, text[i]))
            {
                i++;
            }
            if (text[i] == L'.' || text[i] == L'\0')
            {
                EndOfText = true;
            }

            int j = 0;
            wchar_t buff[200] = {0};

            while (!wcschr(del, text[i]) && !(text[i] == L'.' || !text[i]))
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
    
    wchar_t delimetr[5] = L" -,:\0";

    wchar_t Wstr[27] = L"abcd abcd bbc abc abc. abc\0";
    //wchar_t Wstr[31] = L"abcd ффв abcd bbc abc abc. abc\0";

    int i = 0;
    bool EndOfText = false;

    while (!EndOfText)
    {
        while (wcschr(delimetr, Wstr[i]))
        {
            i++;
        }
        if (Wstr[i] == L'.' || Wstr[i] == L'\0')
        {
            EndOfText = true;
        }

        int j = 0;
        wchar_t buff[100] = {0};

        while (!wcschr(delimetr, Wstr[i]) && !(Wstr[i] == L'.' || !Wstr[i]))
        {
            buff[j] = Wstr[i];
            j++;
            i++;
        }
        buff[j] = L'\0';

        if (countWord(Wstr, buff, delimetr) == 1)
        {
            wprintf(L"%s\n", buff);
        }
    }

    return 0;
}