#include <stdio.h>


struct seat_info {
    char name[40];
    unsigned short tel_num [10];
    unsigned int seat_pos;

};

void InitBusTable(struct seat_info bus_table[], int len){

    int i, x; //Μετρητές για τις εντολές for
    int y; //Μεταβλητή για τον αριθμό θέσεων που διαβάζεται από το αρχείο

    for(i =0; i < len; i = i+1){
        bus_table[i].name[0] = '\0';
        for (x = 0; x < 10; x = x+1){
            bus_table[i].tel_num[x] = 0;
        }
        bus_table[i].seat_pos = i;
    }

    for(i =0; i < len; i = i+1){
        printf("%d \n" , bus_table[i].seat_pos);
        printf("%s \n" , bus_table[i].name);
        for (x = 0; x < 10; x = x+1){
            printf("%d ", bus_table[i].tel_num[x]);
        }
        printf("\n");
    }

}


void ChangeBusTable(struct seat_info bus_table[]){
    printf("inside");
    int i;
    int len;
    len = 0;
    for (i = 0; i< 40; i = i+1){
        bus_table[len].name[i] = 'A';
    }


}


main ( ) {

    int s;
    s= 53;
    struct seat_info bus_table[s];
    //InitBusTable(bus_table, sizeof(bus_table) / sizeof(*bus_table));

    InitBusTable(bus_table, s);
    s = 0;
    ChangeBusTable(bus_table);
    printf("%s \n" , bus_table[s].name);

}
