#include <stdio.h>
#include <stdbool.h>

#define LEN 34

int find_substr(unsigned char* str, unsigned char* substr, int* len){

    int res = -2;

    if (str != NULL && substr != NULL && len != NULL){

        res = -1;

        int i = 0;
        int j = 0;

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

        while (find_substr(&p[i], w, &len) != -1 && !flag){

            if (find_substr(&p[i], w, &len) == -2){
                flag = true;
            }

            if (p[find_substr(&p[i], w, &len) + i + 1] == ' ' || p[find_substr(&p[i], w, &len) + i - len - 1] == ' ' ||
                p[find_substr(&p[i], w, &len) + i + 1] == ',' || p[find_substr(&p[i], w, &len) + i - len - 1] == ','){
                cnt++;
            }

            i = find_substr(&p[i], w, &len) + i;

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
    
    unsigned char words[LEN] = "cbc cba, bbc,ccb abc, abcd . ddc\0";

    int i = 0;
    int j = 0;

    unsigned char buffer[1000] = {'0'};

    bool flag = false;

    while (!flag){

        if (words[i] == ' ' || words[i] == ',' || words[i] == '.' || words[i] == '\0'){

            if (words[i] != '.' && words[i] != '\0'){
                
                buffer[j+1] = '\0';
                j = 0;

                printf("%s\n", buffer);

                while (words[i] == ' ' || words[i] == ','){
                    i++;

                }

            }
            else{

                if (words[i-1] != ' ' && words[i-1] != ','){

                    buffer[j+1] = '\0';
                    j = 0;

                    printf("%s\n", buffer);
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

    printf("algorithm finished");
    
    return 0;

}