#include <stdio.h>
#include <stdbool.h>

#define LEN_P 11 //13

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

        if (i == 0){
            flag_num = false;
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
    //пустая строка
    //unsigned char P[1] = "\0";
  
    //делится на 4
    unsigned char P[LEN_P] = "1231214124\0";

  //не делится на 4
    //unsigned char P[LEN_P] = "1231214125\0";

  //не число
    //unsigned char P[LEN_P] = "123121412b\0";

  //русские символы
    //unsigned char P[LEN_P] = "1231214124а\0";

    int res = div4(P);

    //нулевой указатель
    // int res = div(NULL);

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
