#include <stdio.h>
#include <stdbool.h>

#define W_LEN 4
#define P_LEN 22 // 15

int find_substr(char* str, char* substr, int* len){

    int res = -1;

    int i = 0;
    int j = 0;

    // добавил && str[i] != '.'
    for (i = 0; (str[i] != '\0' && str[i] != '.') && (substr[j] != '\0'); i++){

        if (str[i] == substr[j]){
            j++;
        }
        else {
            j = 0;
        }
    
    }

    if (substr[j] == '\0'){
        res = i;

        // добавил && str[i] != '.'
        if (str[i] != '\0' && str[i] != '.'){
            res--;
        }
    }

    *len = j;
    
    return res;

}

int main()
{

    char p[P_LEN] = "abcc bbc abc abc. abc\0";
    char w[W_LEN] = "abc\0";

    int i = 0;
    int cnt = 0;

    int len;

    // убрал (p[i] != '\0' && p[i] != '.') &&
    while (find_substr(&p[i], w, &len) != -1){

        if (p[find_substr(&p[i], w, &len) + i + 1] == ' ' || p[find_substr(&p[i], w, &len) + i - len - 1] == ' '){
            cnt++;
        }
            
        i = find_substr(&p[i], w, &len) + i;
        

    }

    printf("%d", cnt);

    return 0;
}
