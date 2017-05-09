/* Δημιουργία μονοδιάστατου πίνακα B δυναμικά*/
/* Δώστε τιμές στον πίνακα */

#include <stdlib.h>
#define n 3

typedef struct s_words {
        int num;
        char strg[5];
        //struct s_words* next;
} words;

void pass_c(words C[]);

int main(void){
    int i, x, number;
    char str[5];

    words *C;
    C =(words *)malloc(sizeof(words)*n);

    for(i=0; i<n; i++){
        printf("C[%d]: \n", i);
        scanf("%d %s", &number, str);
        C[i].num = number;
        for (x=0; x<5; x = x+1){
            C[i].strg[x] = str[x];
        }
    }

    for(i=0; i<n; i++){
        printf("C[%d].num : %d\n", i, C[i].num);
        printf("C[%d].strg : %s\n", i, C[i].strg);
    }

    pass_c(C);

    free(C);
	return 0;
}

void pass_c(words C[]){
    int i;
    for(i=0; i<n; i++){
        printf("C[%d].num : %d\n", i, C[i].num);
        printf("C[%d].strg : %s\n", i, C[i].strg);
    }

}

