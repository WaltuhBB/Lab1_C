#include <stdio.h>
#include <stdbool.h>

#define LEN 34 //35

int find_substr(unsigned char* str, unsigned char* substr, int* len){

    int res = -2;

    if (str != NULL && substr != NULL && len != NULL){

        res = -1;

        int i = 0;
        int j = 0;

        bool flag = false;

        for (i = 0; (str[i] != '\0' && str[i] != '.') && (substr[j] != '\0') && !flag; i++){

            if (str[i] > 127 || str[j] > 127){
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

int count_words(unsigned char* p, unsigned char* w){

    int res = -2;

    if (p != NULL && w != NULL){

        int len;

        int i = 0;
        int cnt = 0;

        bool flag = false;

        int res_substr = find_substr(p, w, &len);

        while (res_substr != -1 && !flag){

            if (res_substr == -2){
                flag = true;
            }

            if (p[res_substr + i + 1] == ' ' || p[res_substr + i - len - 1] == ' ' ||
                p[res_substr + i + 1] == ',' || p[res_substr + i - len - 1] == ','){
                cnt++;
            }

            i = res_substr + i;

            res_substr = find_substr(&p[i], w, &len);

        }

        if (!flag){
            res = cnt;
        }
        else{
            res = -2;
        }

    }

    return res;

}

int main()
{
    unsigned char words[LEN] = "abc abc, bbc,ccb abc, abcd . ddc\0";
    //unsigned char words[LEN] = "abc abc, bbc,ccb фbc, abcd . ddc\0";

    int i = 0;
    int j = 0;

    unsigned char buffer[1000] = {'0'};

    bool flag = false;
    bool non_ascii = false;

    while (!flag && !non_ascii){

        if (words[i] == ' ' || words[i] == ',' || words[i] == '.' || words[i] == '\0'){

            if (words[i] != '.' && words[i] != '\0'){
                
                buffer[j+1] = '\0';
                j = 0;

                int res = count_words(words, buffer);

                if (res != -2){
                    if (res == 1){
                        printf("%s\n", buffer);
                    }

                    while (words[i] == ' ' || words[i] == ','){
                        i++;

                    }
                }
                else{
                    non_ascii = true;
                }

            }
            else{

                if (words[i-1] != ' ' && words[i-1] != ','){

                    buffer[j+1] = '\0';
                    j = 0;
                    
                    int res = count_words(words, buffer);

                    if (res != -2){
                        if (res == 1){
                            printf("%s\n", buffer);
                        }
                    }
                    else{
                        non_ascii = true;
                    }
                
                }
                
                flag = true;

            }

        }
        else{
            buffer[j] = words[i];

            i++;
            j++;
        }

    }

    if (non_ascii){
        printf("Non ascii letters or a NULL pointer ");
    }
    
    return 0;

}
