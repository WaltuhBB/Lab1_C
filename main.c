#include <stdio.h>

#define LEN_S 11

int main()
{

    char P[LEN_S] = "1231214124\0";

    int flag_num = 1;

    int i;

    //check if string is a number
    for (i = 0; P[i] != '\0'; i++){

        if (P[i] > '9' || P[i] < '0'){

            flag_num = 0;
            P[i] = 0;

        }

    }


    //check if number divivsible by 4
    if (flag_num){
        int check = (P[i-1] - '0') + (P[i-2] - '0')*10;

        if (check % 4 == 0){
            printf("You can devide this number by 4");
        }
        else{
            printf("You cant devide this number by 4");
        }

    }
    else{
        printf("String in not a number");
    }

    return 0;
}
