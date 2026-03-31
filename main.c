#include <stdio.h>
#include <stdbool.h>

#define LEN_P 11

int div4(unsigned char* str){

    int res = -1;

    if (str != NULL){

        bool flag_num = true;

        int i;

        for (i = 0; str[i] != '\0'; i++){

            if (str[i] < '0' || str[i] > '9'){
                flag_num = false;
            }

        }

        if (flag_num){

            if (((str[i-1] - '0') + (str[i-2] - '0')*10) % 4 == 0){

                res = 1;

            }
            else{
                res = 0;
            }

        }

    }

    return res;

}

int main()
{

    unsigned char P[LEN_P] = "1231214124\0";
    int res = div4(P);

    if (res != -1){

        if (res){
            printf("You can devide this number by 4 ");
        }
        else{
            printf("You can't devide this number by 4 ");
        }

    }
    else{
        printf("String is not a number or the pointer is empty ");
    }

    return 0;
}
