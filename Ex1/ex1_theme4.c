#include <stdio.h>

#define VACANT          0
#define OCCUPAID        1
#define MAX_CAP         53
#define LAYOUT_SIZE     100

int seats; /*������� ������ ���������� global variable ������ �� �������������� ��� ���� ��� �����������*/
int N; /*������� ��� ��� ���������� ��� ����� - ������� ��� ������ ��� ���������� - global variable*/
char plates[7]; /*character array ��� ��� ��������� */
int bus_seats[MAX_CAP]; /*integer array ��� ��� �������� ���������� ������ ��� ����������*/

/*�������� �����������*/
int f_calculate(i){

    i = 0; /*��������� ������� ����*/
    int a_num; /*��������� ��� ������� ��� ��� ������� ��� ������ */

    /*������� ��������� ��� �� ������*/
    printf ("ENTER NEW SELECTION : ");
    scanf ("%d", &a_num);

    system("cls"); // �������� ��� ������

    /*�������� �����*/

    if (a_num == 1){
        first_f();
    }

    else if(a_num == 2){
        second_f();
    }

    else if(a_num == 3){
        third_f();
    }

    else if(a_num == 4){
        fourth_f();
    }

    else if(a_num == 5){
        fifth_f();
    }

    else if(a_num == 6){
        sixth_f();
    }

    else if(a_num == 7){
        int show = 0;
        eighth_f(show);
    }

    else if(a_num == 8){
        int show = 1;
        eighth_f(show);
    }

    else if (a_num == 0){
        /*������ ��� �� ���������*/
        printf("Thanks for using this program\n");
        printf("EAP / exercise 1 / theme 4\n");
        i = -1;
    }
    else{
        /*����� ���� �������� */
        printf("\n");
        }
    /*���������� buffer ��� scanf()*/
    clear_s();

    return i;
}

int first_f(void){
    int i = 0; //�������� ��� �� for
    int tot = 0; // �������� ������� ����� ������
    int line = 0;   // �������� ������������� ������� ������ �� ��� ����� (10 �� ���� ����� ��� ����������� ���� �����)

    explanation_matrix();
    printf("YOUR SECLECTION WAS: 1 (Show remaining vacant seats)\n\n");
    printf("Vacant seats (number of seat) :\n");
    for (i = 1 ; i < seats + 1; i = i +1){
        if (bus_seats[i] == VACANT){
            tot = tot + 1;
            line = line +1;
            if (line < 10){
                printf(" %3d, ", i);
            }
            else{
                printf(" %3d, \n", i);
                line = 0;
            }
        }
    }
    if (tot !=0){
        printf("\nRemaining vacant seats (total): %d\n", tot);
    }
    else{
        printf("\nRemaining vacant seats (total): 0");
    }
}

int second_f(void){
    int b_num; // ��������� ������� ��� �� ������ - ������� ����� ��� �� ������� � �������

    explanation_matrix();
    printf("YOUR SECLECTION WAS: 2 (Occupy a vacant seat)\n\n");
    printf ("Seat number should be a number > and =< %d.\n", seats);
    printf ("\- Please enter the seat number : ");
    scanf ("%d", &b_num);

    if (b_num > 0 && b_num < seats+1){
        if (bus_seats[b_num] == VACANT){
            bus_seats[b_num] = OCCUPAID;
            printf("The seat with number %d, is now occupied!\n", b_num);
        }
        else{
            printf("Error!. The seat was already occupied!\n");
        }
    }
    else {
        /*����� ����� -  � �� �����������*/
        printf("\nError on input selection! Use only digits.\nValue must be >0 and =< %d.\n", seats);
    }
}

int third_f(void){
    int i;  // �������� ��� for
    int pos = 0;   // �������� �����

    explanation_matrix();
    printf("YOUR SECLECTION WAS: 3 (Occupy first vacant window seat)\n\n");

    if (N > 0){     //������������� �� �������� �������� ��� �� ������ ���������
        for ( i = 0 ; i < N ; i = i +1 ){ //N ������  i*4+1 ��������  ��� i*4 + 4 �����  ����� �� ������ ��� ���������
            if (bus_seats[i*4 + 1] == VACANT){
                bus_seats[i*4 + 1] = OCCUPAID;
                pos = i*4 + 1;
                break;  // �� ������ �������� ���� �������� ������� (pos = i*4 + 1)
            }
            else if (bus_seats[i*4 + 4] == VACANT){
                bus_seats[i*4 + 4] = OCCUPAID;
                pos = i*4 + 4;
                break;  // �� ������ �������� ���� �����  ������� (pos = i*4 + 4)
            }
        }
    }
    if (pos == 0){ //������������� ���  �� �������� ������ - �������� ��� ��������.������ ��� ���� ��������� ��� N = 0
        if (bus_seats[seats - 4] == VACANT){
            bus_seats[seats - 4] = OCCUPAID;
            pos = seats - 4;
        }
        else if (bus_seats[seats] == VACANT){
            bus_seats[seats] = OCCUPAID;
            pos = seats;
        }
    }
    if (pos != 0){
        printf("The next to window seat with number %d,\nis occupied now.\n", pos);
    }
    else{
        printf("There are no vacant seats next to window!!\n");
    }
}

int fourth_f(void){
    int b_num; // ��������� ������� ��� �� ������ - ������� ����� ��� �� ������� � �������

    explanation_matrix();
    printf("YOUR SECLECTION WAS: 4 (Cancel occupied seat)\n\n");
    printf ("Seat number should be a number > and =< %d.\n", seats);
    printf ("\- Enter the seat number you want to cancel occupancy : ");
    scanf ("%d", &b_num);

    if (b_num > 0 && b_num < seats+1){
        if (bus_seats[b_num] == OCCUPAID){
            bus_seats[b_num] = VACANT;
            printf("The seat with number %d, is now vacant!\n", b_num);
        }
        else{
            printf("Error!. The seat was already vacant.\n");
        }
    }
    else {
        /*����� ����� -  � �� �����������*/
        printf("\nError on input selection! Use only digits.\nValue must be >0 and =< %d.\n", seats);
    }
}

int fifth_f(void){
    int b_num; // ��������� ������� ��� �� ������ - ������� ����� ��� �� ������� � �������

    explanation_matrix();
    printf("YOUR SECLECTION WAS: 5 (Check if a seat is occupied)\n\n");
    printf ("\nSeat number should be a number > and =< %d.\n", seats);
    printf ("\- Please enter the seat number to check : ");
    scanf ("%d", &b_num);

    if (b_num > 0 && b_num < seats+1){
        if (bus_seats[b_num] == VACANT){
            printf("The seat with number %d, is VACANT!\n", b_num);
        }
        else{
            printf("The seat with number %d, is OCCUPIED!\n", b_num);
        }
    }
    else {
        /*����� ����� -  � �� �����������*/
        printf("\nError on input selection! Use only digits.\nValue must be >0 and =< %d.\n", seats);
    }
}

int sixth_f(void){
    int i = 0; //�������� ��� �� for
    int tot = 0; // �������� ������� �� ����� ������
    int line = 0;   // �������� ������������� ������� ������ �� ��� ����� (10 �� ���� ����� ��� ����������� ���� �����)

    explanation_matrix();
    printf("YOUR SECLECTION WAS: 6 (Show occupied seats)\n\n");
    printf("Occupied seats (number of seat) :\n");
    for (i = 1 ; i < seats + 1; i = i +1){
        if (bus_seats[i] == OCCUPAID){
            tot = tot + 1;
            line = line +1;
            if (line < 10){
                printf(" %3d, ", i);
            }
            else{
                printf(" %3d, \n", i);
                line = 0;
            }
        }
    }
    if (tot !=0){
        printf("\nOccupied seats (total): %d\n", tot);
    }
    else{
        printf("\nOccupied seats (total): 0\n");
    }
}

int eighth_f(show){
    char layout[LAYOUT_SIZE]; //������� ���������� ����� character array ��� ��� ��������� ���������� / �������� ��� ������
    int chr = 0;//�������� ����������
    int i = 0;    //�������� ��� for

    int line = 0; //�������� ��� ������
    int cori = -1; //�������� ��� ��������

    int r; // ��������� ��� ��� ������� ����������� ��� �����������

    explanation_matrix();

    for (i = 0 ; i < 7 ; i = i + 1){
        //printf("%c", plates[i]);
        layout[chr++] = plates[i];
    }
    //printf("\n");
    layout[chr++] = '\n';

    //������ ���������
    i = 0;
    if (N > 0){
        for (i = 1 ; i < seats - 4 ; i = i +1){
            line = line + 1;
            cori = cori + 1;
            if (line < 4){
                if (cori < 2) {
                    if (bus_seats[i] == OCCUPAID){
                        //printf("%c", '*');
                        layout[chr++] = '*';
                    }
                    else if (bus_seats[i] == VACANT){
                        //printf("%c", '_');
                        layout[chr++] = '_';
                    }
                }
                else{
                    if (bus_seats[i] == OCCUPAID){
                        //printf(" %c", '*');
                        layout[chr++] = ' ';
                        layout[chr++] = '*';
                    }
                    else if (bus_seats[i] == VACANT){
                        //printf(" %c", '_');
                        layout[chr++] = ' ';
                        layout[chr++] = '_';
                    }
                    cori = -1;
                }
            }
            else{
                if (bus_seats[i] == OCCUPAID){
                    //printf("%c\n", '*');
                    layout[chr++] = '*';
                    layout[chr++] = '\n';
                }
                else if (bus_seats[i] == VACANT){
                    //printf("%c\n", '_');
                    layout[chr++] = '_';
                    layout[chr++] = '\n';
                }
                line = 0;
                cori = -1;
            }
        }
    }
    //�������� ��� ��������
    i = 0;
    for (i = seats -4 ; i < seats + 1; i = i +1){
        if (bus_seats[i] == OCCUPAID){
            //printf("%c", '*');
            layout[chr++] = '*';
        }
        else if (bus_seats[i] == VACANT){
            //printf("%c", '_');
            layout[chr++] = '_';
        }
    }
    layout[chr++] = '\n';
    layout[chr++] = '\0';

    //���� ��� ���������� ��� �������� ��� layout array, ��������� � �������� ������� �� �� argument ��� ������� ��� function
    if (show == 0){
        printf("YOUR SECLECTION WAS: 7 (Show on screen seats status)\n\n");
        printf("Bus status (on screen): \n");
        i = 0;
        for (i = 0 ; i < chr -1 ; i = i + 1){
            printf("%c", layout[i]);
        }
    }
    if (show == 1){
        printf("YOUR SECLECTION WAS: 8 (Save seats status on layout.txt)\n\n");
        //���������� ��� �������
        FILE *l_file = fopen("layout.txt", "w");

        r = fputs(layout, l_file);
        if (r == EOF) {
            printf("Error! File was not written.\n");
        }
        else {
           printf("File was written successfully!\n");
        }
        fclose(l_file);
    }
}

int clear_s(void){
    while (getchar() != '\n');
}

int explanation_matrix(void){
    printf ("\n");
    printf ("|--------------------------------------------|\n");
    printf ("| Select a number to                         |\n");
    printf ("| Show remaining vacant seats         : 1    |\n");
    printf ("| Occupy a vacant seat                : 2    |\n");
    printf ("| Occupy first vacant window seat     : 3    |\n");
    printf ("| Cancel occupied seat                : 4    |\n");
    printf ("| Check if a seat is occupied         : 5    |\n");
    printf ("| Show occupied seats                 : 6    |\n");
    printf ("| Show on screen seats status         : 7    |\n");
    printf ("| Save seats status (layout.txt)      : 8    |\n");
    printf ("| Exit the program                    : 0    |\n");
    printf ("|--------------------------------------------|\n");
    printf ("\n");
    return 0;
}

int main(){
    /*������ ����������*/
    int f_seats; //��������� ���� - ������� ������ ��� �� ������ bus.txt
    char f_plates[7]; // Array ��� ��� ���������� ��� ��������� - �������� ��� �� bus.txt
    int i;   // ��������
    int ret; //Returned value ��� ��� ��������� f_calculate(i)

    /*����������� ��� �� ��������� */
    printf ("------------------------------------------------------|\n");
    printf ("|Bus Seats Occupancy Program                          |\n");
    printf ("|                                                     |\n");
    printf ("|The program reads 'bus.txt' file,                    |\n");
    printf ("|and shows a message if can manage                    |\n");
    printf ("|occupancies for that type of bus.                    |\n");
    printf ("|                                                     |\n");
    printf ("|If the bus type is OK,                               |\n");
    printf ("|Instructions will follow,                            |\n");
    printf ("|about the available selections.                      |\n");
    printf ("|-----------------------------------------------------|\n");
    printf ("\n");

    /*Step 1 read ��� �� ������ bus.txt */
    FILE *bus_file;

    bus_file = fopen("bus.txt", "r");
    if (bus_file != 0) {
        fscanf(bus_file, "%s %d", f_plates, &f_seats);
        printf(" 'bus.txt' file opened successfully.\n");
        printf(" Bus plate number : %s\n", f_plates);
        printf(" Bus capacity : %d persons\n", f_seats);

        i =0;
        for (i = 0; i < 8 ; i = i +1){
            plates[i] = f_plates[i];    //������� ����� ���� global variable
        }

        i = 0;
        /*��������� ��� �� ������ ����� ��� Nmin = 0 (��������� ������ 5)
        ��� 53 ������ �������  ���.  53 = (4 * Nmax) +5 => Nmax = 48/4 +> Nmax = 12      */
        for (i = 0 ; i < 13 ; i = i +1){
            if (((4 * i) + 5) == f_seats ){
                seats = f_seats;    // ������� ����� ���� global variable
                N = i;              // ������� ����� ���� global variable
            }
        }
        if (seats > 0){
            printf(" The program can manage occupancies of this type of bus\n");
        }
        else {
            printf(" The program can not manage occupancies of this type of bus! \n");
            printf(" The program will terminate.\n");
        }
        fclose(bus_file);
    }
    else{
        printf("\n Error reading file. The program will terminate\n");
    }

    /*Step 2 ���������� ������  - ���� �� ������ �����
    O ������� ���� �������� +1 ��� ��� ��������� ����� � ���� bus_seat[0] ����� ���������� �� ����
    �� ���� ��� ����� ������� ��� ������ ������������ ��� ������ �� ��� ����� ��� ������ ��� ������� � �������*/

    i = 0;
    for ( i = 0 ; i < seats + 1 ; i = i +1 ){
        bus_seats[i] = VACANT;
    }

    fflush(stdin);

    if (seats > 0){
        explanation_matrix();
        /*'������ ������� ������� ���� ��� ������������*/
        i = 0;
        while (i == 0){
            ret = f_calculate(i);  /*�������� ��� function ��� �������� �� ����� ���������*/
            i = ret;
        }
    }
    return 0;
}

