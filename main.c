#include <stdio.h>

#define LEN 33

int main()
{
    
    char words[LEN] = "abc cba, bbc,ccb abc, abcd. ddc\0";

    int i = 0;
    int j = 0;

    char buffer[1000] = {'0'};

    while (words[i] != '\0' && words[i] != '.'){

        if (words[i] == ' ' || words[i] == ','){

            buffer[j+1] = '\0';
            j = 0;

            printf("%s\n", buffer);

            while (words[i] == ' ' || words[i] == ','){
                i++;
            }

        }
        else{
            buffer[j] = words[i];

            i++;
            j++;
        }

    }

    printf("algorithm finished");
    
    return 0;

}
