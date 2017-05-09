#include <stdio.h>

#define DIVIDE  2

/*������ �����������*/
int f_calculate(int i){

    /*���������� ��� ������� ���� ��������� ��� �����������*/
    int r = 0;
    int ix = 0;
    char chr;

    int a_num = 0; /*��������� ��� �������� ��� scanf, input ������*/
    int x;/*��������� ��� ���������� �� ���������� ��� �������*/

    /*������� ��������� ��� �� ������*/
    printf ("\n");
    printf ("Enter a positive integer (> 0): ");
    scanf ("%d", &a_num);

    /*���������� - �������� ������� - �������� �������������*/
    if (a_num >= 1 ){
        printf("Result : ");
        while (a_num >= 1){
            x = a_num%2;
            /*����� ��� ��������� �������*/
            putchar(x == 0 ? '0' : '1');
            a_num = a_num / DIVIDE;
        }
        printf("\n");
    }
    else {
        printf("Enter a positive integer!\n");
    }

    /*������� ��� ��� ��������� � ��� ���������� ��� ����������� �� ������ ��������� ��� �� ������*/
    while (ix == 0){
        /*���������� buffer*/
        clear_s();
        printf ("\nDo you want to continue the program (y/n) ? ");
        if (scanf ("%c", &chr) == 1){
            if (chr ==  'y'){
                ix = 1; //������������ � ������������ �������
                printf("OK\n");
            }
            else if (chr ==  'n'){
                r = 1;
                ix = 1; // ������������ � ������������ �������  ��� �� ���������
            }
        }
    }
    return r;
}

int clear_s(void){
    while ( getchar() != '\n' );
}

int main (){
    int i = 0;
    /*����������� ��� �� ��������� */
    printf ("------------------------------------------------------|\n");
    printf ("|Integer -> Binary Converting Program                 |\n");
    printf ("|                                                     |\n");
    printf ("|Use:                                                 |\n");
    printf ("|Input a positive integer.                            |\n");
    printf ("|The result is the numbers binary array               |\n");
    printf ("|in reverse order.                                    |\n");
    printf ("|                                                     |\n");
    printf ("|-----------------------------------------------------|\n");
    printf ("\n");

    /*'������� ������� ���� ��� ������������*/

    while (i == 0)
        {
            int ret;
            ret = f_calculate(i);  /*�������� ��� function ��� �������� �� ����� ���������*/
            i = ret;
        }

    /*������ ��� �� ���������*/
    printf("Thanks for using this program\n");
    printf("EAP / exercise 1 / theme 3\n");
    return 0;
}
