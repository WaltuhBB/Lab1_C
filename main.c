#include <stdio.h>
#include <stdbool.h>

#define W_LEN 4
#define P_LEN 24 // 22

int find_substr(unsigned char* str, unsigned char* substr, int* len){

    int res = -2;

    if (str != NULL && substr != NULL && len != NULL){

        res = -1;

        int i = 0;
        int j = 0;

        // добавил && str[i] != '.'
        for (i = 0; (str[i] != '\0' && str[i] != '.') && (substr[j] != '\0') && (str[i] <= 127) && (substr[j] <= 127); i++){

            if (str[i] == substr[j]){
                j++;
            }
            else {
                j = 0;
            }

        }

        if (str[i] > 127 || str[j] > 127){

            res = -2;

        }
        else{

            if (substr[j] == '\0'){
                res = i;

                // добавил && str[i] != '.'
                if (str[i] != '\0' && str[i] != '.'){
                    res--;
                }
            }

        }

        *len = j;

    }
    
    return res;

}

int main()
{

    unsigned char p[P_LEN] = "abcа bbc abc abc. abc\0"; // после 'c' 'а' русская
    unsigned char w[W_LEN] = "abc\0";

    int len;

    int i = 0;
    int cnt = 0;

    bool flag = false;

    while (find_substr(&p[i], w, &len) != -1 && !flag){

        if (find_substr(&p[i], w, &len) == -2){
            flag = true;
        }

        if (p[find_substr(&p[i], w, &len) + i + 1] == ' ' || p[find_substr(&p[i], w, &len) + i - len - 1] == ' '){
            cnt++;
        }

        i = find_substr(&p[i], w, &len) + i;

    }

    if (!flag){
        printf("%d", cnt);
    }
    else{
        printf("Not an ascii letters or NULL pointer");
    }

    return 0;
}
