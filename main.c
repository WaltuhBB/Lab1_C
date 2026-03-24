#include <stdio.h>
#include <stdbool.h>

#define W_LEN 4
#define P_LEN 15

int find_substr(char* str, char* substr){

    int res = -1;

    int i = 0;
    int j = 0;

    for (i = 0; (str[i] != '\0') && (substr[j] != '\0'); i++){

        if (str[i] == substr[j]){
            j++;
        }
        else {
            j = 0;
        }
    
    }

    if (substr[j] == '\0'){
        res = i;

        if (str[i] != '\0'){
            res--;
        }
    }
    
    return res;

}

int main()
{

    char p[P_LEN] = "abc bbc abcdd.\0";
    char w[W_LEN] = "abc\0";

    int a = find_substr(p, w);
    printf("%d", a);

    return 0;
}
