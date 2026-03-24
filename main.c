#include <stdio.h>
#include <stdbool.h>

#define W_LEN 4
#define P_LEN 15

int find_substr(char* str, char* substr){

    bool flag = false;

    int i = 0;
    int j = 0;

    while (str[i] != '\0' && !(flag == true && substr[j] == '\0')){

        if (substr[j] == str[i]){
            flag = true;
        }

        if (substr[j] == '\0'){
            j = 0;
        }

        i++;
        j++;

    }

    return i;
}

int main()
{

    char p[P_LEN] = "abc bbc abcdd.\0";
    char w[W_LEN] = "abc\0";

    int a = find_substr(p, w);
    printf("%d", a);

    return 0;
}
