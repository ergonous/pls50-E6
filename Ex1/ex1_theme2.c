#include <stdio.h>

/*����� ���� ��� ��� ���������� ��� ������������ �����, �� ����� ��� ��� ���������� ��� ���. ��������*/
#include <math.h>

/*������ �����������*/
//��������� ����������� ���������� ���������� - ��� ������ ��� ��������� ��� float
float f_square(float b_num){
    float x;
    x = b_num * 4.0;
    return x;
}

//��������� ����������� ���������� ���������� ���/��� - ��� �������� ��� ��������� ��� float
float f_rectangle(float b_num, float c_num){
    float x;
    x = (b_num * 2.0) + (c_num * 2.0);
    return x;
}

//��������� ����������� ���������� ���. ��������- ��� �������� ��� ��������� ��� float
float f_right_triangle(float b_num, float c_num){
    float x;
    x = sqrt((b_num * b_num) + (c_num * c_num)); // ����� ��� ���������� sqrt() ��� �� ���������� math.h
    x = x + b_num + c_num;
    return x;
}

//��������� ����������� ���������� ������ - ��� �������� ��� ��������� ��� float
float f_cycle(float b_num){
    float x;
    float y;
    float z;
    y = 3.14;
    z = 2.0;
    x = z * y * b_num;
    return x;
}

//��������� ��� ��� �������� ��������� ������.
int error_show(void){
    /*����� ����� -  � �� �����������*/
    clear_scanf();
    printf("\nError on input selection! Use only digits. Values must be >0. Please try again\n");

}

//��������� ��� ��� �������� ������� ��� ������. ��� ������� ��������.
int explanation_matrix(void){
    printf ("\n");
    printf ("Select a number to \n");
    printf ("Calculate square's perimeter          : 1  \n");
    printf ("Calculate rectangle's perimeter       : 2  \n");
    printf ("Calculate right triangle's perimeter  : 3  \n");
    printf ("Calculate cycle's perimeter           : 4  \n");
    printf ("Exit the program                      : 0  \n");
    printf ("\n");
    return 0;
}

//��������� ����������� buffer
int clear_scanf(void){
    while ( getchar() != '\n' );
}

//� ��������� ��� ���������� ����� ��� ������� ��� main. ����� � ������ ��������� ���������� ��� ������������.
int f_calculate(int i){

    i = 0; /*��������� ������� ����*/

    int a_num; /*��������� ��� ������� �������� ��� ������ ������� �� ��� ������� ��������*/
    float b_num = 0; /*��������� ��� ������� �������� ��� ������ ������� �� ��� �������� ��� �������� (��������� ��� ������)*/
    float c_num = 0; /*��������� ��� ������� �������� ��� ������ ������� �� ��� ������� �������� ��� �������� (�����/�� ��� ���. �������)*/
    float res_num = 0; /*��������� - ���������� ����������� ����������� ����������� ����������*/

    explanation_matrix();  /*�������� ���������� ��� ����������� ������������ �� ���� �� void function*/

    /*������� ��������� ��� �� ������*/
    printf ("Enter your selection: ");

    if (scanf("%d", &a_num) == 1){
        clear_scanf();
        /*�������� �����*/
        if (a_num == 1){
            printf("\n-Square's perimeter calculation.\n");
            printf("Be careful a square's side dimension can't be <=0.\n\n");
            printf("Input the square's side dimension : ");
            scanf ("%f", &b_num);
            if (b_num > 0){
                res_num = f_square(b_num); /*����� ��� function �� �� ��������� b_num (������ �) �� ������*/
                printf("|--------------------------------------------------------|\n");
                printf("  Square's perimeter = %f\n                               \n", res_num);
                printf("|--------------------------------------------------------|\n");
            }
            else {
                error_show();
            }
        }
        else if (a_num == 2){
            printf("\n-Rectangle's perimeter calculation.\n");
            printf("Be careful a rectangle's side dimension can't be <=0.\n\n");
            printf("Input the rectangle's side A  dimension : ");
            scanf ("%f", &b_num);
            printf ("\n");
            printf("Input the rectangle's side B  dimension : ");
            scanf ("%f", &c_num);
            if (b_num > 0 && c_num > 0){
                res_num = f_rectangle(b_num, c_num); /*����� ��� function �� ��� ���������� b_num, c_num (������� � ��� �) �� ��������*/
                printf("|--------------------------------------------------------|\n");
                printf("  Rectangle's perimeter = %f\n                            \n", res_num);
                printf("|--------------------------------------------------------|\n");
            }
            else {
                error_show();
            }
        }
        else if (a_num == 3){
            printf("\n-Right triangle's perimeter calculation.\n");
            printf("Be careful a right triangle's side dimension can't be <=0.\n\n");
            printf("Input the right triangle's side  A  dimension (vertical | ): ");
            scanf ("%f", &b_num);
            printf ("\n");
            printf("Input the right triangle's side  B  dimension (horizontal _ ): ");
            scanf ("%f", &c_num);
            if (b_num > 0 && c_num > 0){
                res_num = f_right_triangle(b_num, c_num); /*����� ��� function �� ��� ���������� b_num, c_num (������� � ��� �) �� ��������*/
                printf("|--------------------------------------------------------|\n");
                printf("  Right triangle's perimeter = %f\n                       \n", res_num);
                printf("|--------------------------------------------------------|\n");
            }
            else {
                error_show();
            }
        }
        else if (a_num == 4){
            printf("\n-Cycle's perimeter calculation.\n");
            printf("Be careful a cycles's radius dimension can't be <=0.\n\n");
            printf("Input the cycles's radius : ");
            scanf ("%f", &b_num);
            if (b_num > 0){
                res_num = f_cycle(b_num); /*����� ��� function �� �� ��������� b_num (������) �� ������*/
                printf("|--------------------------------------------------------|\n");
                printf("  Cycle's perimeter = %f\n                               \n", res_num);
                printf("|--------------------------------------------------------|\n");
            }
            else {
                error_show();
            }
        }
        else if (a_num == 0){
            /*������ ��� �� ���������*/
            printf("Thanks for using this program\n");
            printf("EAP / exercise 1 / theme 2\n");
            i = -1;
        }
        else{
            /*����� ���� �������� --- �������� ��� ������� ����� ��� error_show ��� - ���� ������ ���� 82 */
            printf("\n2. Error on selection! Use only Numbers from 0 to 4. Please try again\n");
        }
    }
    else{
        error_show();
    }
    return i;
}

main (){
    int i = 0;
    /*����������� ��� �� ��������� */
    printf ("-------------------------------------------------------|\n");
    printf ("|Perimeter Calculation Program                         |\n");
    printf ("|The program calculates the perimeter of square,       |\n");
    printf ("|rectangle, right triangle and cycle.                  |\n");
    printf ("|Use:                                                  |\n");
    printf ("|Select a number indicating the shape's perimeter      |\n");
    printf ("|you want to calculate and input the proper dimensions.|\n");
    printf ("|Select 0 to exit the program.                         |\n");
    printf ("|------------------------------------------------------|\n");
    printf ("\n");
    printf ("\n");

    /*'������� ������� ���� ��� ������������*/
    while (i == 0){
        int ret;
        ret = f_calculate(i);  /*�������� ��� function ��� �������� �� ����� ���������*/
        i = ret;
        }
    return 0;
}

