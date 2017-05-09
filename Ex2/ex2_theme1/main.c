#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAP         53   //������� ���������� ��������� ����������
#define LINE_0          11      //������ 0  11 ����������
#define LINEX           55      //������ x   ���������� 55 (40+1+2+1+10+1)

int seats; /*������� ������ ���������� global variable ������ �� �������������� ��� ���� ��� �����������*/
char seat_str[3];
int N; /*������� ��� ��� ���������� ��� ����� - ������� ��� ������ ��� ���������� - global variable*/
char plates[7]; /*character array ��� ��� ��������� */

struct seat_info {
    char name[40];
    unsigned short tel_num [10];
    unsigned int seat_pos;
};

/*�������� �����������*/
void InitBusTable(struct seat_info bus_table[], int len);
void read_file(struct seat_info bus_table[]);
void explanation_matrix(void);
void first_f(struct seat_info bus_table[]);
void second_f(struct seat_info bus_table[]);
struct seat_info second_f_st(struct seat_info point);
int Fix_String(char s_n[]);
void third_f(struct seat_info bus_table[]);
void fourth_f(struct seat_info bus_table[]);
struct seat_info fourth_f_st(struct seat_info point);
int getLayout(char *layout_c, int length, struct seat_info bus_table[], int show);
void saveLayout(char *layout_c);
void clear_s(void);

int main(){
    /* ���� 1 ����������� ��� �� ��������� */
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

    /*���� 2 ���������� ������������� ������ �� ����� 53 ������ */
    struct seat_info bus_table[MAX_CAP];

    /*���� 3 ������������ ���  ������ �� ��� ����� seat_info*/
    InitBusTable(bus_table, MAX_CAP);


    /*���� 4 read ��� �� ������ bus.txt */
    read_file(bus_table);

    /*'������ ������� ������� ���� ��� ������������*/
    if (seats > 0){
        explanation_matrix();
        int i = 0;
        while (i == 0){
            int a_num; /*��������� ��� ������� ��� ��� ������� ��� ������ */

            /*������� ��������� ��� �� ������*/
            printf ("ENTER NEW SELECTION : ");
            scanf ("%d", &a_num);

            system("cls"); // A������� ��� ������

            /*�������� �����*/
            if (a_num == 1){
                first_f(bus_table);
            }
            else if(a_num == 2){
                second_f(bus_table);
            }
            else if(a_num == 3){
                third_f(bus_table);
            }
            else if(a_num == 4){
                fourth_f(bus_table);
            }
            else if(a_num == 5){
                int filled_lines = 0;
                int x = 0;
                int show = 0;
                for (x = 0 ; x < seats ; x = x +1){
                    if (bus_table[x].name[0] != '\0'){
                        filled_lines = filled_lines +1;
                    }
                }
                int max_size;
                max_size = LINE_0 + (LINEX * filled_lines);
                char layout_c[max_size];
                int r_max;
                r_max = getLayout(layout_c, sizeof(layout_c) - 1, bus_table, show);
                printf("YOUR SECLECTION WAS: 5 (Show occupied seats with passengers Name & Tel.Number)\n\n");
                printf("Bus status (on screen): \n");
                for (x = 0 ; x < r_max -1 ; x = x + 1){
                    printf("%c", layout_c[x]);
                }
            }

            else if (a_num == 0){
                int filled_lines = 0;
                int x = 0;
                int show = 1;
                for (x = 0 ; x < seats ; x = x +1){
                    if (bus_table[x].name[0] != '\0'){
                        filled_lines = filled_lines +1;
                    }
                }
                int max_size;
                max_size = LINE_0 + (LINEX * filled_lines);
                char layout_c[max_size];
                int r_max;
                r_max = getLayout(layout_c, sizeof(layout_c) - 1, bus_table, show);
                /*������ ��� �� ���������*/
                printf("YOUR SECLECTION WAS: 0 (Save seats status on bus.txt and exit the program)\n\n");
                //���������� ��� �������
                saveLayout(layout_c);
                i = r_max;
            }
            else{
                /*����� ���� �������� */
                printf("\n");
                }
        }
    }
    return 0;

}

void InitBusTable(struct seat_info bus_table[], int len){

    int i, x; //�������� ��� ��� ������� for

    for(i =0; i < len; i = i+1){
        bus_table[i].name[0] = '\0';
        for (x = 0; x < 10; x = x+1){
            bus_table[i].tel_num[x] = 0;
        }
        bus_table[i].seat_pos = i+1;
    }

    //for(i =0; i < len; i = i+1){
        //printf("%d \n" , bus_table[i].seat_pos);
        //printf("%s \n" , bus_table[i].name);
        //for (x = 0; x < 10; x = x+1){
            //printf("%d ", bus_table[i].tel_num[x]);
        //}
        //printf("\n");
    //}
}

void read_file(struct seat_info bus_table[]){
    FILE *bus_file;
    bus_file = fopen("bus.txt", "r");

    if (bus_file != 0) {
        int i; //��������� ��� for loop
        int y_seats; //��������� ��� ��� ������ ������ ��� ���������� ��� �� ������
        char line[60]; //��������� ��� �� ����������� ��� ������� ��� �� ����������� ��� �� ������
        int line_n = 0; //��������� �������� ��� ������� �������
        int idx = 0;  //��������� ����������� ����������

        char chr = getc (bus_file);

        while ( chr != EOF ) {
            if ( chr != '\n'){
                line[idx] = chr;
                idx = idx+1;
            }
            else {
                line[idx] = '\0';
                idx = 0;
                if (line_n == 0){
                    sscanf(line, "%s %s", plates, seat_str);
                    printf("'bus.txt' file opened successfully.\n");
                    printf("Bus plate number : %s\n", plates);
                    printf("Bus capacity : %s persons\n", seat_str);
                   // printf("\nPassengers list / Seat  / Tel. Num:\n");

                    y_seats = atoi(seat_str);
                }
                else{
                    //printf ("%s\n", line);
                    char s_name[20];
                    char f_name[20];
                    int s_num;
                    char t_num[11];

                    sscanf(line, "%s %s %d %s", s_name, f_name, &s_num, t_num);
                    //��������� ��� ����� ��� ���������� �� ��������� ����� ��� �������� ��� ���� ��� ������.
                    int pos;
                    pos = s_num -1;

                    bus_table[pos].seat_pos = s_num;

                    //printf("\nSeat : %d\n", bus_table[pos].seat_pos);

                    char all_name[40];
                    all_name[0] = '\0';
                    strcat(all_name, s_name);
                    strcat(all_name, " ");
                    strcat(all_name,f_name);
                    for (i = 0; i < 40; i = i+1) {
                        bus_table[pos].name[i] = all_name[i];
                    }
                    //printf("Name : %s\n", bus_table[pos].name);

                    int ch;
                    for (i= 0 ; t_num[i]; i = i+1){
                        ch = t_num[i];
                        if (ch != '\0'){
                            //printf("\n %d %d", i, ch);
                            bus_table[pos].tel_num[i] = ch;
                        }
                    }
                    /* �������� ������ ���������
                    //printf("Tel Number : ");
                    int chn;
                    for (i=0; i< 10 ; i = i +1){
                        chn = bus_table[pos].tel_num[i];
                        //printf("%c",chn);
                    }*/
                    //printf("\n");

                    /* ����� ������ �� ��� ����� �� �������� ��������� �� double ��� ��� �������� �������� ���������������

                    printf ("%s\n", line);
                    char s_name[20];
                    char f_name[20];
                    int s_num;
                    double t_num;

                    sscanf(line, "%s %s %d %lf", s_name, f_name, &s_num, &t_num);

                    //��������� ��� ����� ��� ���������� �� ��������� ����� ��� �������� ��� ���� ��� ������.
                    int pos;
                    pos = s_num -1;

                    bus_table[pos].seat_pos = s_num;

                    printf("\nSeat : %d\n", bus_table[pos].seat_pos);

                    char all_name[40];
                    all_name[0] = '\0';
                    strcat(all_name, s_name);
                    strcat(all_name, " ");
                    strcat(all_name,f_name);
                    for (i = 0; i < 40; i = i+1) {
                        bus_table[s_num -1].name[i] = all_name[i];
                    }
                    printf("Name : %s\n", bus_table[pos].name);

                    long long int f_t_num;
                    int digit;
                    f_t_num = t_num * 1;
                    printf("Tel. Number : ");
                    for (i=0; i< 10 ; i = i +1){
                        digit = f_t_num % 10;
                        f_t_num = f_t_num / 10;
                        bus_table[pos].tel_num[9-i] = digit;
                    }
                    for (i=0; i< 10 ; i = i +1){
                         printf("%d",bus_table[pos].tel_num[i]);
                    }
                    printf("\n");

                    ����� �ou ����� ������*/

                }
                line_n = line_n +1;
            }
            chr = getc (bus_file);
        }

        //���� ��� ����� ���� ���������� ��� �
        int n;
        /*��������� ��� �� ������ ����� ��� Nmin = 0 (��������� ������ 5)
        ��� 53 ������ �������  ���.  53 = (4 * Nmax) +5 => Nmax = 48/4 +> Nmax = 12      */
        for (n = 0 ; n < 13 ; n = n +1){
            if (((4 * n) + 5) == y_seats ){
                seats = y_seats;
                N = n;
            }
        }
        if (seats > 0){
            printf("The program can manage occupancies of this type of bus\n");
        }
        else {
            printf("The program can not manage occupancies of this type of bus! \n");
            printf("The program will terminate.\n");
        }
        fclose(bus_file);
    }
    else{
        printf("\nError reading file. The program will terminate\n");
    }
}

void explanation_matrix(void){
    printf ("\n");
    printf ("|---------------------------------------------------------------|\n");
    printf ("| Select a number to                                            |\n");
    printf ("| Show remaining vacant seats                            : 1    |\n");
    printf ("| Occupy a vacant seat                                   : 2    |\n");
    printf ("| Check if a seat is occupied (by Name or Tel. number)   : 3    |\n");
    printf ("| Cancel occupied seat                                   : 4    |\n");
    printf ("| Show occupied seats (passengers Name and Tel.Number)   : 5    |\n");
    printf ("| Exit the program (and save occupancies)                : 0    |\n");
    printf ("|---------------------------------------------------------------|\n");
    printf ("\n");

}

void first_f(struct seat_info bus_table[]){
    explanation_matrix();
    printf("YOUR SECLECTION WAS: 1 (Show remaining vacant seats)\n\n");
    printf("Vacant seats (number of seat) :\n");
    int i = 0;
    int tot = 0;
    int line = 0;
    for (i = 0 ; i < seats ; i = i +1){
        if (bus_table[i].name[0] == '\0'){
            tot = tot + 1;
            line = line +1;
            if (line < 10){
                printf(" %3d, ", i+1);
            }
            else{
                printf(" %3d, \n", i+1);
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

void second_f(struct seat_info bus_table[]){
    explanation_matrix();
    printf("YOUR SECLECTION WAS: 2 (Occupy a vacant seat)\n\n");
    printf ("Seat number should be a number > 0 and =< %d.\n", seats);
    printf ("\n-Please enter the seat number : ");
    int b_num;
    scanf ("%d", &b_num);

    if (b_num > 0 && b_num < seats+1){
        printf("The number is OK, %d \n", b_num);
        int pos;
        pos = b_num -1;

        struct seat_info point;

        point = bus_table[pos];//� ���� point ������� ��� �� �������� ��� ����������� ����� ��� ������

        point = second_f_st(point);//����������� ��� ����� point ��� �� ��������� ��� ��������� ���.

        bus_table[pos] = point;//� ���� ��� ������ �������������� ��� �� ���� point
    }
    else {
        fflush(stdin);          /*����� ����� -  � �� �����������*/
        printf("\nError on input selection! Use only digits.\nValue must be >0 and =< %d.\n", seats);
    }
}

struct seat_info second_f_st(struct seat_info point){
    int i;
    if (point.name[0] == '\0'){
        //�������� ��������������
        printf("Please enter the passengers Last name and First name : ");
        char s_n[40];
        s_n[0] = '\0';
        char last_n[20];
        char first_n[20];

        scanf ("%s %s", last_n, first_n);
        char *f_ch;
        char *l_ch;

        int valid_n1 = 0;
        int valid_n2 = 0;

        int length1 = 0;                            //������� ������ ��������
        for (i=0; last_n[i]; i = i+1){
            length1 = length1+1;
        }
        //printf("length1 = %d\n", length1);
        int length2= 0;                            //������� ������ ��������
        for (i=0; first_n[i]; i = i+1){
            length2 = length2+1;
        }
        //printf("length2 = %d\n", length2);
        if (length1 <20  && length2 <20 ){
            f_ch = &first_n[0];
            l_ch = &last_n[0];

            valid_n1 = Fix_String(l_ch);    //������� ��� ��������� ���������� �������������� ���������� (string) ��������
            valid_n2 = Fix_String(f_ch);    //������� ��� ��������� ���������� �������������� ���������� (string) ��������

            strcat(s_n, last_n); //concatenate last and first name
            strcat(s_n, " ");
            strcat(s_n, first_n);
        }
        else{
            if(length1 > 19){
                printf("Very long Last name. For Last and First name use max 19 char each.\n");
            }
            else if(length2 > 19){
                printf("Very long First name. For Last and First name use max 19 char each.\n");
            }
        }
        //�������� ���������
        char tel_n[10];
        int valid_t = 0;
        int ch;
        if (valid_n1 == 1 && valid_n2 ==1){
            fflush(stdin);
            printf("Please enter the passengers Tel. number : ");

            scanf ("%s", tel_n);

            ch = tel_n[0];
            for (i=0; tel_n[i]; i = i+1){
                ch = tel_n[i];
                if (ch>='0' && ch <= '9'){
                    valid_t = valid_t+1;
                }
            }
        }
        //������� ��������� ��������� ��� ���� POINT // ���� �� ��� ����� �����
        if (valid_t ==10 && valid_n1 == 1 && valid_n2 ==1){
            //������� ��������
            for (i = 0; i<40; i = i+1){
                point.name[i] = s_n[i];
            }
            //������� ���������
            ch = tel_n[0];
            for (i= 0 ; tel_n[i]; i = i+1){
                ch = tel_n[i];
                if (ch != '\0'){
                    point.tel_num[i] = ch;
                }
            }
            //������� ����� ��� ����� ���������� ���� ��� ���� �������
            printf("\nSeat number : %d \nis now occupied by %s.\nTel. number : %s\n\n", point.seat_pos , point.name, tel_n);
        }
        else{
            //�������� ����� ���������
            if (valid_n1 == 0 || valid_n2 ==0){
                printf("Error!. Passengers Name wrong format\n");
            }
            if (valid_t != 10){
                printf("Error!. Passengers Tel. Number format\n");
            }
        }
    }
    else{
        printf("Error!. The seat was already occupied!\n");
    }
    //��������� ��� ��������� second_f ��� �����  point (��������� � ��� ��� ���� ������, � ���� ������ �� ����������)
    return point;
};

int Fix_String(char *ch){

    char check;
    int i;
    check = ch[0];
    int valid;
    //printf("%s\n", ch);
    for ( i=0; ch[i]; i++ ){
        check = ch[i];
        if (check <'A' || check >'z'){       //������� ��� ������������ ���������� (?!@ 123 ���)
            valid = 0;
            break;
        }
        else if(check>'Z' && check<'a'){    //������� ��� ������������ ���������� ([]/  ���)
            valid = 0 ;
            break;
        }
        else{                       //��������� �� ���� - �������� ���� �������� �� 'dIMITRiadis' ��� ����� 'Dimitriadis'
            valid = 1;
            if (i == 0){
                if (check>='a' && check <= 'z'){
                    ch[i] = ch[i] - 32;
                }
            }
            else{
                if(check>='A' && check<= 'Z'){
                    ch[i] = ch[i] + 32;
                }
            }
            //printf("%d", i);
        }
    }
    return valid;
}

void third_f(struct seat_info bus_table[]){
    explanation_matrix();
    printf("YOUR SECLECTION WAS: 3 (Search if a seat is occupied (by Name or Tel. number)\n\n");
    printf ("Enter '1' to search by Name, or '2' to search by Tel. Number\n");
    printf ("\n- Please enter your selection ( 1 / 2 ) : ");

    int select;

    scanf ("%d", &select);

    clear_s();

    if(select == 1){

        char name_entry[40];
        printf("Please enter the Name to be searched : ");

        gets(name_entry);

        int i;
        int length = 0;
        for (i=0; name_entry[i]; i = i+1){
            length = length+1;
        }
        if (length >0 && length <= 40){
            int found =1;
            int nt = 0;
            for (i = 0 ; i < seats ; i = i+1){ //��� ����� ���������� �� ������� ���� � �������. ����� ����� �� ������ ��� ���������� ��� �� bus.txt ��� ������������ ��� global seats
                found = strcmp(bus_table[i].name, name_entry);
                if (found  == 0){
                    printf("\nSeat occupied for this Name : %d\n", bus_table[i].seat_pos);
                    nt = 1;
                }
            }
            if (nt==0){
                printf("\nThere is not any seat occupied for this Name \n");
            }
        }
        else{
            printf("\nError on input format. The Name is too long.\n");
            printf("Last name and First name should have max. 19 characters each \nand one space between them\n");
        }
    }
    else if (select == 2){

        //fflush(stdin);

        char tel_entry[10];
        printf("Please enter the Tel. Number to be searched : ");
        gets(tel_entry);

        int i;
        int length = 0;
        for (i=0; tel_entry[i]; i = i+1){
            length = length+1;
        }
        //printf("%d,  %s\n", length, tel_entry);
        if (length !=10){
           printf("Error! Tel. number must have 10 digits!\n");
        }
        else if (length == 10){
            int pin[10];
            int ch;
            ch = tel_entry[0];
            for (i= 0 ; tel_entry[i]; i = i+1){
                ch = tel_entry[i];
                if (ch != '\0'){
                    //printf("\n %d %d", i, ch);
                    pin[i] = ch;
                    //printf("\n %d", pin[i]);
                }
            }
            int x;
            int f=0;
            int p=0;
            for (i = 0 ; i < seats ; i = i+1){
                f = 0;
                if (bus_table[i].name != '\0'){
                    for (x=0; x<10 ; x = x+1){
                        if (bus_table[i].tel_num[x] != pin[x]){
                            f = 1;
                            break;
                        }
                    }
                    if (f == 0){
                        p = 1;
                        printf("\nSeat occupied for this Tel. number : %d\n", bus_table[i].seat_pos);
                    }
                }
            }
            if (p == 0){
                printf("\nThere is not any seat occupied for this Tel. number \n");
            }
        }
    }
    else{
        fflush(stdin);              /*����� ����� */
        printf("\nError on input selection! Use only 1 for Name search or 2 for Tel. number search\n");
    }
}

void fourth_f(struct seat_info bus_table[]){
    explanation_matrix();
    printf("YOUR SECLECTION WAS: 4 (Cancel occupied seat)\n\n");
    printf ("Seat number should be a number > 0 and =< %d.\n", seats);
    printf ("\n- Please enter the seat number : ");
    int b_num;
    scanf ("%d", &b_num);

    if (b_num > 0 && b_num < seats+1){
        int pos;
        pos = b_num -1;

        struct seat_info point;

        point = bus_table[pos];//� ���� point ������� ��� �� �������� ��� ����������� ����� ��� ������

        point = fourth_f_st(point);//����������� ��� ����� point ��� �� ��������� ��� ��������� ���.

        bus_table[pos] = point;//� ���� ��� ������ �������������� ��� �� ���� point

    }
    else {
        fflush(stdin);          /*����� ����� -  � �� �����������*/
        printf("\nError on input selection! Use only digits.\nValue must be >0 and =< %d.\n", seats);
    }
}

struct seat_info fourth_f_st(struct seat_info point){

        if (point.name[0] != '\0'){
            printf("The occupancy of seat %d, by %s is about to be canceled.\nEnter 'y' to proceed or 'n' to cancel : ", point.seat_pos, point.name);
            fflush(stdin);
            char selection;
            scanf ("%c", &selection);
            if (selection == 'y'){
                point.name[0] = '\0';
                int x;
                for (x = 0; x < 10; x = x+1){
                    point.tel_num[x] = 0;
                }
                printf("Seat %d is now vacant.\n", point.seat_pos);
            }
            else if(selection == 'n'){
                printf("Seat %d is still occupied.\n", point.seat_pos);
            }
            else{
                printf("Error on selection! Seat %d is still occupied.\n", point.seat_pos);
            }
        }
    return point;
};

int getLayout(char *layout, int length, struct seat_info bus_table[], int show){

    explanation_matrix();

    int chr = 0;//�������� ����������
    int i = 0;

    //����� ������
    for (i = 0 ; i < 7 ; i = i + 1){
        //printf("%c", plates[i]);
        layout[chr++] = plates[i];
    }
    layout[chr++] = ' ';
    for (i = 0; seat_str[i]; i = i+1){
        layout[chr++] = seat_str[i];
    }
    layout[chr++] = '\n';
    //��������� �������
    int x;
    for(i = 0; i < 53; i = i + 1){

        int posit = i+1;

        if (bus_table[i].name[0] != '\0'){

            if(show == 1){
                //�����
                for(x =0; bus_table[i].name[x]; x = x+1){
                    layout[chr++] = bus_table[i].name[x];
                }
                layout[chr++] = ' ';
                //����
                int length = snprintf( NULL, 0, "%d", posit );
                char* str = malloc( length + 1 );
                snprintf( str, length + 1, "%d", posit );
                for(x =0; str[x]; x = x+1){
                    layout[chr++] = str[x];
                }
                free(str);
                layout[chr++] = ' ';
            }
            if(show ==0){
                //����
                int length = snprintf( NULL, 0, "%d", posit );
                char* str = malloc( length + 1 );
                snprintf( str, length + 1, "%d", posit );
                for(x =0; str[x]; x = x+1){
                    layout[chr++] = str[x];
                }
                free(str);
                layout[chr++] = ' ';
                //�����
                for(x =0; bus_table[i].name[x]; x = x+1){
                    layout[chr++] = bus_table[i].name[x];
                }
                layout[chr++] = ' ';
            }
            //��������
            for(x =0;  x< 10; x = x + 1){
                layout[chr++] = bus_table[i].tel_num[x];
            }
            layout[chr++] = '\n';
        }
    }
    layout[chr++] = '\0';
    return chr;
}

void saveLayout(char *layout_c){

    FILE *l_file = fopen("bus.txt", "w");
    int r = fputs(layout_c, l_file);
    if (r == EOF) {
        printf("Error! File was not written.\n");
    }
    else {
        printf("File was written successfully!\n");
    }
    fclose(l_file);

    printf("Thanks for using this program\n");
    printf("EAP / exercise 2 / theme 1\n");

}

void clear_s(void){
    while (getchar() != '\n');
}
