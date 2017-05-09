#include <stdio.h>

/*�������� �����������*/

int f_calculate(int i){

    printf ("\nInput the formated triad :\n");

    /*�������� ����������
    � ����� ����� ���� �������� ��� �������������.
    ���� ���������, �� ����� ����������� ��� �� scanf ���� ��� ��������� ��� �� ������ */
    float n;
    float n1;
    char c1;
    char c2;
    char c3;
    float n2;

    /*����� ��������� ���������� ������� ����� ��������� ��������� ���� scanf, */
    int sn1 = 0;
    int sc1 = 0;
    int sc2 = 0;
    int sc3 = 0;
    int sn2 = 0;

    /*���������� ��� ������� ���� ��������� ��� �����������*/
    int r = 0;
    int ix = 0;
    char chr;

    /*������ � ���������� ��������� ��������� ��� �� ������ ��� � ������� ���� �� ����������*/
    if (scanf(" %f", &n1) == 1){
        sn1 = 1;
    }
    if (scanf("%c", &c1) == 1){
        sc1 = 1;
    }
    if (scanf("%c", &c2) == 1){
        sc2 = 1;
    }
    if (scanf("%c", &c3) == 1){
        sc3 = 1;
    }
    if (scanf("%f", &n2) == 1){
        sn2 = 1;
    }
    /*������ � �������� ����� ����� ���� ��� �� �� ���������� ����
    �������� ���������� ��� �� ���������� � ����� �����.
    �� ���������� ����� ���� ��������, ����������� ������� ����������*/
    if (sn1 == 1 && sc1 == 1 && c1 == ' ' && sc2 == 1 && sc3 == 1 && c3 == ' ' && sn2 == 1){

        if (c2 == '+'){
            n = n1 + n2;
            printf("Result of addition is : %f\n", n);
        }
        else if (c2 == '-'){
            n = n1 - n2;
            printf("Result of deduction is : %f\n", n);
        }
        else if (c2 == '*'){
            n = n1 * n2;
            printf("Result of multiplication is : %f\n", n);
        }
        else if (c2 == '/') {
            if (n2 != 0){
                n = n1 / n2;
                printf("Result of division is : %f\n", n);
            }
            else{
                printf("Division cant be done (nothing can be divided by zero)\n"); // � ��������� ������� 0
            }
        }
        else {
            printf("Error! Wrong formula!\n"); // ��� ������ ���� +, -, *, / ���� c2
        }
    }

    else{
        //printf("sn1:%d, sc1:%d, sc2:%d, sc3:%d, sn2:%d\n", sn1, sc1, sc2, sc3, sn2);
        printf("\n Input error!\n");
    }

    /*���������� buffer*/
    clear_s();

    /*������� ��� ��� ��������� � ��� ���������� ��� ����������� �� ������ ��������� ��� �� ������*/
    while (ix == 0){
        printf ("Do you want to continue the program (y/n) ? ");
        if (scanf (" %c", &chr) == 1){
            if (chr ==  'y'){
                ix = 1; //������������ � ������������ �������
                printf("OK\n");
            }
            else if (chr ==  'n'){
                printf("Thanks for using this program!");
                printf("EAP/Exercise 1/ Theme 1.");
                r = 1;
                ix = 1; // ������������ � ������������ �������  ��� �� ���������
            }
        }
    }
    return r;
}

int clear_s(void){
    while ( getchar() != '\n' );
    return 0;
}

/*������ ��� main*/
int main()
{
    /*����������� ��� �� ��������� */
    printf ("------------------------------------------------------|\n");
    printf ("|Calculation Program                                  |\n");
    printf ("|                                                     |\n");
    printf ("|Use:                                                 |\n");
    printf ("|Input a triad formated as follows                    |\n");
    printf ("|NUMBER FORMULA NUMBER                                |\n");
    printf ("|Formula: + for addition, - for deduction             |\n");
    printf ("| * for multiplication and  / for division            |\n");
    printf ("|Be careful. Only one space is allowed between them   |\n");
    printf ("|Example 0.75 * -2                                    |\n");
    printf ("|-----------------------------------------------------|\n");
    printf ("\n");

    /*'������� ������� ���� ��� ������������*/
    int i = 0;
    while (i == 0)
        {
            int ret;
            ret = f_calculate(i);  /*�������� ��� function ��� �������� �� ����� ���������*/
            i = ret;
        }
    return 0;
}


