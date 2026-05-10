#include <stdio.h>
#include <stdbool.h>

#include <wchar.h>

int divFour(wchar_t* str)
{
    int res = -1;

    if (str)
    {
        res = 0;
        
        bool flagNum = true;
        int i;

        for (i = 0; str[i] != L'\0'; i++)
        {
            if (str[i] < L'0' || str[i] > L'9')
            {
                flagNum = false;
            }
        }
        if (wcslen(str) == 0)
        {
            flagNum = false;
        }

        if (flagNum)
        {
            if (!( ((str[i-1] - L'0') + ((str[i-2] - L'0') * 10)) % 4 ))
            {
                res = 1;
            }
        }
        else
        {
            res = -1;
        }
    }

    return res;
}

int main()
{
    //wchar_t str[1] = L"\0";
    wchar_t str[11] = L"1231214124\0";
    //wchar_t str[11] = L"1231214125\0";
    //wchar_t str[11] = L"12312b4124\0";

    int res = divFour(str);

    if (res != -1)
    {
        if (res)
        {
            printf("divisible\n");
        }
        else
        {
            printf("not divisible\n");
        }
    }
    else
    {
        printf("string is not a number or the pointer is empty\n");
    }

    return 0;
}