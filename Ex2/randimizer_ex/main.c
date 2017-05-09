#include <stdio.h>
#include <stdlib.h>

#define ERR_NO_NUM -1
#define ERR_NO_MEM -2

int myRandom (int size) {
    int i, n;
    static int numNums = 0;
    static int *numArr = NULL;

    // Initialize with a specific size.

    if (size >= 0) {
        if (numArr != NULL)
            free (numArr);
        if ((numArr = malloc (sizeof(int) * size)) == NULL)
            return ERR_NO_MEM;
        for (i = 0; i  < size; i++)
            numArr[i] = i;
        numNums = size;
    }

    // Error if no numbers left in pool.

    if (numNums == 0)
       return ERR_NO_NUM;

    // Get random number from pool and remove it (rnd in this
    //   case returns a number between 0 and numNums-1 inclusive).

    n = rand() % numNums;
    i = numArr[n];
    numArr[n] = numArr[numNums-1];
    numNums--;
    if (numNums == 0) {
        free (numArr);
        numArr = 0;
    }

    return i;
}

int main (void) {
    int i, Array[12] ;

    srand (time (NULL));
    i = myRandom (80);

    int count;
    count = 0;
    while (i >= 0) {
        count = count+1;
        printf ("Number = %3d\n", i);
        Array[count-1]= i;
        i = myRandom (-1);
        if (count == 12){
            break ;
        }
    }
    printf ("Final  = %3d\n", i);
    //Array[count]= i;

    for(i=0; i<12; i =i+1){
        printf("Array! %3d\n", Array[i]);
    }

    return 0;
}
