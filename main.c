#include <stdio.h>
#include <stdbool.h>

#define W_LEN 4 // 5
#define P_LEN 22 // 23

int find_substr(unsigned char* str, unsigned char* substr, int* len){

    int res = -2;

    if (str != NULL && substr != NULL && len != NULL){

        res = -1;

        int i = 0;
        int j = 0;

        bool flag = false;

        for (i = 0; (str[i] != '\0' && str[i] != '.') && (substr[j] != '\0') && !flag; i++){

            if (str[i] > 127 || substr[j] > 127){
                flag = true;
            }

            if (str[i] == substr[j]){
                j++;
            }
            else {
                j = 0;
            }

        }

        if (flag){

            res = -2;

        }
        else{

            if (substr[j] == '\0'){
                res = i;

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

    //unsigned char p[P_LEN] = "abcd bbc abф abc. abc\0";
    //unsigned char w[W_LEN] = "aфc\0";

    unsigned char p[P_LEN] = "abcd bbc abc abc. abc\0";
    unsigned char w[W_LEN] = "abc\0";

    int len;

    int i = 0;
    int cnt = 0;

    bool flag = false;

    int res = find_substr(p, w, &len);

    while (res != -1 && !flag){

        if (res == -2){
            flag = true;
        }

        if (p[res + i + 1] == ' ' || p[res + i - len - 1] == ' '){
            cnt++;
        }

        i = res + i;

        res = find_substr(&p[i], w, &len);

    }

    if (!flag){
        printf("Words found: %d ", cnt);
    }
    else{
        printf("Not an ascii letters or a NULL pointer ");
    }

    return 0;
}
