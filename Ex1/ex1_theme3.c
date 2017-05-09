#include <stdio.h>

#define DIVIDE  2

/*Δήλωση συναρτήσεων*/
int f_calculate(int i){

    /*Μεταβλητές που αφορούν στην επανάληψη της διαδικασίας*/
    int r = 0;
    int ix = 0;
    char chr;

    int a_num = 0; /*Μεταβλητή για εκχώρηση στη scanf, input χρήστη*/
    int x;/*Μεταβλητή που αναπαριστά το αποτέλεσμα των πράξεων*/

    /*Είσοδος στοιχείων από το χρήστη*/
    printf ("\n");
    printf ("Enter a positive integer (> 0): ");
    scanf ("%d", &a_num);

    /*Συγκρίσεις - εκτέλεση πράξεων - εμφάνιση αποτελεσμάτων*/
    if (a_num >= 1 ){
        printf("Result : ");
        while (a_num >= 1){
            x = a_num%2;
            /*Χρήση του τριαδικού τελεστή*/
            putchar(x == 0 ? '0' : '1');
            a_num = a_num / DIVIDE;
        }
        printf("\n");
    }
    else {
        printf("Enter a positive integer!\n");
    }

    /*Βρόγχος για την επανάληψη ή τον τερματισμό της διαδικασίας με Είσοδο στοιχείων από το χρήστη*/
    while (ix == 0){
        /*Εκκαθάριση buffer*/
        clear_s();
        printf ("\nDo you want to continue the program (y/n) ? ");
        if (scanf ("%c", &chr) == 1){
            if (chr ==  'y'){
                ix = 1; //Τερματίζεται ο εκτελούμενος βρόγχος
                printf("OK\n");
            }
            else if (chr ==  'n'){
                r = 1;
                ix = 1; // Τερματίζεται ο εκτελούμενος βρόγχος  και το πρόγραμμα
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
    /*Πληροφορίες για το πρόγραμμα */
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

    /*'Βρόγχος ελέγχου ροής του προγράμματος*/

    while (i == 0)
        {
            int ret;
            ret = f_calculate(i);  /*Εκτέλεση της function που αποτελεί το κύριο πρόγραμμα*/
            i = ret;
        }

    /*Έξοδος από το πρόγραμμα*/
    printf("Thanks for using this program\n");
    printf("EAP / exercise 1 / theme 3\n");
    return 0;
}
