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

int count_words(unsigned char* str, unsigned char* substr){

    int res = -2;

    if (str != NULL && substr != NULL){

        int len;

        int i = 0;
        int cnt = 0;
        bool flag = false;

        int res_f = find_substr(str, substr, &len);
    
        int begin = res_f - len + 1;
        int end = res_f;

        if (begin == 0 && (str[end+1] == '\0' || str[end+1] == '.') && res != -1){
            cnt++;
        }
    
        while (res_f != -1 && !flag){
   
            if (res_f == -2){
                flag = true;
            }

            begin = res_f - len + 1 + i;
            end = res_f + i;
        
            if (str[begin-1] == ' ' || str[end+1] == ' ' ||
                str[begin-1] == ',' || str[end+1] == ','){
        
                bool bool_b = str[begin-1] == ' ' || str[begin-1] == ',';
                bool bool_e = str[end+1] == ' ' || str[end+1] == ',';
                
                if (bool_b && bool_e){
                    cnt++;
                }

                if (begin == 0){
                    cnt++;
                }

                if (str[end+1] == '.' || str[end+1] == '\0'){
                    cnt++;
                }

            }

            i = res_f + i;
            res_f = find_substr(&str[i], substr, &len);

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

    unsigned char buffer[1000] = {0};

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
