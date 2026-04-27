#include <stdio.h>
#include <stdbool.h>

#define W_LEN 4 // 5
#define P_LEN 27 // 23

int find_substr(unsigned char* str, unsigned char* substr, int* len){

    int res = -2;

    if (str != NULL && substr != NULL && len != NULL){

        res = -1;

        int i = 0;
        int j = 0;

        bool flag = false;

        for (i = 0; (str[i] != '\0' && str[i] != '.') && (substr[j] != '\0' && substr[j] != '.') && !flag; i++){

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
                res--;
                
            }

        }

        *len = j;

    }
    
    return res;

}

int main()
{

    //unsigned char str[1] = "\0";

    //unsigned char str[P_LEN] = "abcd bbc abф abc. abc\0";
    //unsigned char substr[W_LEN] = "aфc\0";

    unsigned char str[P_LEN] = "abcd abcd bbc abc abc. abc\0";
    unsigned char substr[W_LEN] = "abc\0";

    //unsigned char str[12] = "bbc abc ddc\0";
    //unsigned char str[12] = "abc bbc ddc\0";
    //unsigned char str[12] = "bbc ddc abc\0";
    //unsigned char str[4] = "abc\0";
    //unsigned char str[5] = "abc \0";
    //unsigned char str[5] = " abc\0";

    //unsigned char substr[4] = "abc\0";

    int len;

    int i = 0;
    int cnt = 0;
    bool flag = false;

    int res = find_substr(str, substr, &len);
    
    int begin = res - len + 1;
    int end = res;

    if (begin == 0 && (str[end+1] == '\0' || str[end+1] == '.') && res != -1){
        cnt++;
    }
    
    while (res != -1 && !flag){
   
        if (res == -2){
            flag = true;
        }

        begin = res - len + 1 + i;
        end = res + i;
        
        if (str[begin-1] == ' ' || str[end+1] == ' '){
        
            if (str[begin-1] == ' ' && str[end+1] == ' '){
                cnt++;
            }

            if (begin == 0){
                cnt++;
            }

            if (str[end+1] == '.' || str[end+1] == '\0'){
                cnt++;
            }

        }

        i = res + i;
        res = find_substr(&str[i], substr, &len);

    }

    if (!flag){
        printf("Words found: %d", cnt);
    }
    else{
        printf("Non ascii or a NULL pointer");
    }

    return 0;
}
