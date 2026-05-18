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
            while (text[i] != L'\0' && wcschr(del, text[i]))
            {
                i++;
            }
            
            if (text[i] == L'.' || text[i] == L'\0')
            {
                EndOfText = true;
            }

            size_t word_start = i;
            while (text[i] != L'\0' && !wcschr(del, text[i]) && text[i] != L'.')
            {
                i++;
            }

            size_t word_end = i;
            size_t current_word_len = word_end - word_start;

            if (current_word_len == word_len)
            {
                wchar_t tmp = text[word_end];
                text[word_end] = L'\0';

                int check = wcscmp(word, &text[word_start]);

                text[word_end] = tmp;

                if (!check)
                {
                    res = word_start;
                    wFound = true;
                }
            }
        }
    }

    return res;
}

int main()
{
    wchar_t delimetr[5] = L" -,:\0";
    
    wchar_t Wstr[27] = L"abcd abcd bbc abc abc. abc\0";
    //wchar_t Wstr[1] = L"\0";
    //wchar_t Wstr[4] = L"abc\0";

    wchar_t Wsubstr[4] = L"abc\0";

    int cnt = 0;
    size_t i = 0;
    size_t word_len = wcslen(Wsubstr);
    
    int res = findWord(Wstr, Wsubstr, delimetr);

    if (res != -2)
    {
        while (res != -1)
        {
            cnt++;
            i = i + res + word_len;
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
