#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include <locale.h>
#include <wchar.h>

int findWord(wchar_t* text, wchar_t* word, wchar_t* del)
{
    int res = -2;
    
    if (text && word && del)
    {
        res = -1;
    
        bool EndOfText = false;
        bool wFound = false;

        size_t i = 0;
        size_t word_len = wcslen(word);

        while (!EndOfText && !wFound)
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
                res = i - word_len;
                wFound = true;
            }
        }
    }

    return res;
}

int main()
{
    wchar_t delimetr[5] = L" -,:\0";
    
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
    
    int res = findWord(Wstr, Wsubstr, delimetr);

    if (res != -2)
    {
        while (res != -1)
        {
            cnt++;

            i = i + (res + word_len - 1);
            res = findWord(&Wstr[i], Wsubstr, delimetr);
        }

        printf("Words found: %d\n", cnt);
    }
    else
    {
        printf("NULL pointer\n");
    }

    return 0;
}
