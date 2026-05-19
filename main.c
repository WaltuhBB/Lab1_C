#include <stdio.h>
#include <stdbool.h>

#include <wchar.h>
#include <locale.h>

int findWord(wchar_t* text, wchar_t* word, wchar_t* delim)
{
    int res = -2;
    
    if (text && word && delim)
    {
        res = -1;
    
        bool EndOfText = false;
        bool wFound = false;

        size_t i = 0;
        size_t word_len = wcslen(word);

        while (!EndOfText && !wFound)
        {
            while (text[i] != L'\0' && wcschr(delim, text[i]))
            {
                i++;
            }
            
            if (text[i] == L'.' || text[i] == L'\0')
            {
                EndOfText = true;
            }

            size_t word_start = i;
            while (text[i] != L'\0' && !wcschr(delim, text[i]) && text[i] != L'.')
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
    setlocale(LC_ALL, "");
    
    wchar_t Wstr[27] = L"abcd abcd bbc abc abc. abc\0";
    //wchar_t Wstr[5] = L"abcd\0";
    //wchar_t Wstr[1] = L"\0";

    wchar_t delimetr[5] = L" -,:\0";
    
    int begin = 0;
    int end = 0;
    bool EndOfText = false;
    
    while (!EndOfText)
    {
        while (wcschr(delimetr, Wstr[begin]))
        {
            begin++;
        }
        
        end = begin;
        
        while (!wcschr(delimetr, Wstr[end]) &&
                (Wstr[end] != L'.' && Wstr[end] != L'\0'))
        {
            end++;
        }

        if (begin == 0 && (Wstr[end] == L'.' || !Wstr[end]))
        {
            wprintf(L"%s\n", Wstr);
        }
        else
        {
            if (Wstr[end] == L'.' || !Wstr[end])
            {
                wchar_t tmp_l = Wstr[begin-1];
                wchar_t tmp_r = Wstr[end];
                Wstr[begin-1] = L'\0';
                Wstr[end] = L'\0';

                if (findWord(Wstr, &Wstr[begin], delimetr) == -1)
                {
                    wprintf(L"%s\n", &Wstr[begin]);
                }

                Wstr[begin-1] = tmp_l;
                Wstr[end] = tmp_r;
            }
            else
            {
                wchar_t tmp_r = Wstr[end];
                Wstr[end] = L'\0';

                if (findWord(Wstr, &Wstr[begin], delimetr) == begin &&
                    findWord(&Wstr[end+1], &Wstr[begin], delimetr) == -1)
                {
                    wprintf(L"%s\n", &Wstr[begin]);
                }

                Wstr[end] = tmp_r;
            }
        }
        
        if (Wstr[end] == L'.' || !Wstr[end])
        {
            EndOfText = true;
        }

        begin = end;
    }
    
    return 0;
}
