#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct players_info_s{
    char name[17];
    unsigned short score;
    unsigned short id;
}players_info;

typedef struct cards_s{
    unsigned short color;
    unsigned short shape;
    unsigned short number;
    unsigned short texture;
}cards;

int active_p;       //Καθολική Μεταβλητή που αναφέρεται στον ενεργό παίκτη (αριθμός που αντιστοιχεί σε αυτόν)

//Δηλώσεις συναρτήσεων
void game_banner(players_info players_table[], int players);
void InitCardsTable(cards cards_table[]);
void getNextCard(int rand_cards_table_pos[]);
void InitPlayersTable(players_info players_table[], int players);
int game_function(players_info players_table[], int players, int reset, int rand_cards_table_pos[], cards cards_table[]);
int get_random_n(void);
int check_cards(cards final_table[]);
void clear_s(void);

int main(){

    /*ΒΗΜΑ 1 Δήλωση και Δημιουργία Πίνακα 81 θέσεων με περιεχόμενα τύπου cards(struct cards_s)*/
    cards cards_table[81];
    InitCardsTable(cards_table);

    /*ΒΗΜΑ 2 Επιλογή 12 διαφορετικών τυχαίων αριθμών από το 0 έως το 80, που αντιστοιχούν σε καρτες του σχετικού πίνακα*/
    int rand_cards_table_pos[12];
    getNextCard(rand_cards_table_pos);


    /*ΒΗΜΑ 3 Δημιουργία Δυναμικού πίνακα 3 θέσεων με περιεχόμενα τύπου players_info(struct players_info_s)
    Επιλέχθηκε η δημιουργία δυναμικού σε περίπτωση που απαιτηθεί μελλοντικά να γίνει δυναμική εισαγωγή στοιχείων παικτών...*/
    int players;
    players = 3;
    players_info *players_table;
    players_table =(players_info *)malloc(sizeof(players_info)* players);
    InitPlayersTable(players_table, players); //Αρχικοποίηση τιμών Πίνακα

    /*ΒΗΜΑ 4 ΑΡΧΙΚΟΠΟΙΗΣΗ ΠΑΙΧΝΙΔΙΟΥ  reset = 1,  επιλογή ενεργου παικτη */
    int reset = 1;
    int i = 1;
    while (i !=0){
        if (reset != 0){
            reset = game_function(players_table, players, reset, rand_cards_table_pos, cards_table); /*Εκτέλεση της function που αποτελεί το κύριο πρόγραμμα*/
        }
        else{
            i = reset; printf("END OF GAME\n EAP Exercise 2 Theme 3");
        }
    }
    return 0;
}

void game_banner(players_info players_table[], int players){
    //Πληροφορίες για το πρόγραμμα
    printf ("-------------------------------------------------------|\n");
    printf ("| SET GAME                                             |\n");
    printf ("|                                                      |\n");
    printf ("| Rules:                                               |\n");
    printf ("| Enter the players id and select 3 cards              |\n");
    printf ("| using the coordinations of the shown matrix          |\n");
    printf ("| for example x = 0, y = 0 is the upper left corner    |\n");
    printf ("| card and x = 2, y = 3 is the bottom right card       |\n");
    printf ("| If the SET is correct the player receives 2 points   |\n");
    printf ("| bout if is wrong receives a penalty of 1 point.      |\n");
    printf ("| To exit the program enter 0 at players turn.         |\n");
    printf ("|------------------------------------------------------|\n");
    printf ("\n");
    int i;
    for (i=0; i < players; i = i+1){
        printf("PLAYER %3d Id : %c  SCORE : %3d  / Name : %s\n", i+1, players_table[i].id, players_table[i].score, players_table[i].name);
    }
    printf ("\n");
}

void InitCardsTable(cards cards_table[]){
    int i, x, y, z, w;
    x = y = z = w = 0;

    for (i = 0; i < 81; i = i+1){
        //COLOR
        if (x==0){
            cards_table[i].color = 'r';  //Cards color Red
            x = x+1;
        }
        else if (x==1){
            cards_table[i].color = 'g';   //Cards color Green
            x = x+1;
        }
        else if (x==2){
            cards_table[i].color = 'b';      //Cards color Green
            x = 0;
        }
        //SHAPE
        if (y >= 0 && y <= 2){
            cards_table[i].shape = 'c';      //Cards shape cycle
            y = y + 1;
        }
        else if (y >= 3 && y <= 5){
            cards_table[i].shape = 't';      //Cards shape triangle
            y = y + 1;
        }
        else if (y >= 6 && y <= 8){
            cards_table[i].shape = 'r';      //Cards shape rhombus
            if (y < 8){
                y = y + 1;
            }
            else if (y == 8){
                y = 0;
            }
        }
        //NUMBER
        if (z >= 0 && z <= 8){
            cards_table[i].number = '1';       //Cards number 1
            z = z + 1;
        }
        else if (z >= 9 && z <= 17){
            cards_table[i].number = '2';      //Cards number 2
            z = z + 1;
        }
        else if (z >= 18 && z <= 26){
            cards_table[i].number = '3';      //Cards number 3
            if (z < 26){
                z = z + 1;
            }
            else if (z == 26){
                z = 0;
            }
        }
        //TEXTURE
        if (w >= 0 && w <= 26){
            cards_table[i].texture = 'b';       //Cards bold filed
            w = w + 1;
        }
        else if (w >= 27 && w <= 53){
            cards_table[i].texture = 'h';      //Cards horizontal lined
            w = w + 1;
        }
        else if (w >= 54 && w <= 80){
            cards_table[i].texture = 'e';      //Cards texture empty, not filed  - no lines in.
            if (w < 80){
                w = w + 1;
            }
            if (w == 80){
                w = 0;
            }
        }
    }
    /*
    printf("CARDS INITILIZED\n");
    for (i = 0; i < 81 ; i = i+1){
        printf("%3d %c,", i, cards_table[i].color);
        printf("%c,", cards_table[i].shape);
        printf("%c,", cards_table[i].number);
        printf("%c\n", cards_table[i].texture);
    }
    */
}

void getNextCard(int rand_cards_table_pos[]){
    srand (time (NULL));
    int i, r_n;
    for (i = 0; i <12; i = i+1){
        rand_cards_table_pos[i] = -1;
    }
    /*for (i=0; i<12; i = i+1 ){
        printf("Before: rand table i = %3d\n", rand_cards_table_pos[i]);
    }*/
    for (i=0; i<12; i = i+1 ){
        if (i==0){
            r_n = rand() % 80;
            //printf("r_n (for i=0) = %3d\n", r_n);
            rand_cards_table_pos[i] = r_n;
        }
        else{
            while(rand_cards_table_pos[i]<0){
                r_n = rand() % 80;
                //printf("i = %3d  r_n = %3d\n", i, r_n);
                int x;
                for (x= 0; x < i; x= x+1){
                    if (rand_cards_table_pos[x] == r_n){
                        r_n = -1;
                    }
                }
                if(r_n >= 0){
                    rand_cards_table_pos[i] = r_n;
                }
            }
        }
    }
    /*for (i=0; i<12; i = i+1 ){
        printf("After: rand table i = %3d\n", rand_cards_table_pos[i]);
    }*/
}

void InitPlayersTable(players_info players_table[], int len){
    int i, x; //Μετρητές για τις εντολές for

    for(i =0; i < len; i = i+1){
        if (i==0){
            char px[17] = "Marina Andreou";
            for (x=0; x<17; x = x+1){
                players_table[i].name[x] = px[x];
            }
            players_table[i].score = 0;
            players_table[i].id = 'a';
        }
        if (i==1){
            char p2[17] = "Kostas Grammenos";
            for (x=0; x<17; x = x+1){
                players_table[i].name[x] = p2[x];
            }
            players_table[i].score = 0;
            players_table[i].id = 'g';
        }
        if (i==2){
            char p3[17] = "Maria Perdika";
            for (x=0; x<17; x = x+1){
                players_table[i].name[x] = p3[x];
            }
            players_table[i].score = 0;
            players_table[i].id = 'p';
        }
    }
    /*for(i =0; i < len; i = i+1){
        printf("\n%d " , players_table[i].id);
        printf("%s<END HARE " , players_table[i].name);
        printf("%d\n", players_table[i].score);
    }*/
}

int game_function(players_info players_table[], int players, int reset, int rand_cards_table_pos[], cards cards_table[]){
    static int round_counter = 0;

    //printf("\nSTARTING RESET = %d\n", reset);

    //SCORE FIX
    if (reset == 4){
        players_table[active_p].score = players_table[active_p].score +2 ;
    }
    if (reset == 3){
        if (players_table[active_p].score >= 1){
            players_table[active_p].score = players_table[active_p].score -1;
        }
    }

    //SHOW ON SCREEN
    system("cls");
    game_banner(players_table, players);
    if (reset == 4 || reset == 1){
        if (reset == 4){
            getNextCard(rand_cards_table_pos);
            printf("MESSAGE : Congratulations %s your SET is correct ! Got 2 points \n\n", players_table[active_p].name);
            //Winner condition
            if (players_table[active_p].score >= 10){
                printf("The winner is %s\n\n", players_table[active_p].name);
                printf("Thanks for using this program\n");
                printf("EAP / exercise 2 / theme 3\n");
                exit(1);
            }
        }
        else{
            printf("MESSAGE : The game started ! Good luck and try to find a SET......\n\n");
        }
        round_counter = round_counter+1;
    }
    else if (reset == 3){
        printf("MESSAGE : Sorry the Set is Wrong !\n\n");
    }
    else if (reset == 2){
        printf("MESSAGE : You selected a Wrong id! Please Select a Valid Id!!!!!\n\n");
    }
    else if (reset == 21){
        printf("MESSAGE : %s, you entered Wrong Coordinations!\n Be careful next time!!\n\n", players_table[active_p].name);
    }
    else if (reset == 22){
        printf("MESSAGE : %s, you tried to select two same cards!\n Don't try to cheat again!\n\n", players_table[active_p].name);
    }

    int x, y, z, w, pos;
    cards twoD_table [ 3 ][ 4 ];
    x = y = z = w = 0;
    for (x = 0; x < 3; x = x + 1){
        for(y = 0; y < 4; y = y + 1){
            pos = rand_cards_table_pos[z];
            twoD_table[x][y] = cards_table[pos];
            if (w < 4){
                printf("   [%c,%c,%c,%c]", cards_table[pos].color, cards_table[pos].shape, cards_table[pos].number, cards_table[pos].texture );
            }
            else {
                printf("\n   [%c,%c,%c,%c]", cards_table[pos].color, cards_table[pos].shape, cards_table[pos].number, cards_table[pos].texture );
                w =0;
            }
            w = w + 1;
            z = z + 1;
        }
    }
    printf ("\n\n");

    char a_char; /*Μεταβλητή της εισόδου για την επιλογή του χρήστη */
    /*Είσοδος στοιχείων από το χρήστη*/
    printf ("SET GAME  - ROUND : %d\nPLEASE ENTER PLAYERS ID (or 0 to exit game): ", round_counter);
    scanf ("%c", &a_char);

    reset = 0;

    if (a_char == '0'){
        reset = 0;
    }
    else {
        active_p = -1;
        int i;
        for (i=0; i < players; i = i+1){
            if (a_char == players_table[i].id){
                active_p = i;
            }
        }
        if(active_p != -1){
            printf ("Active player = %c\n", players_table[active_p].id);
            cards final_table[ 3 ];
            int x, y, c0, c1, c2;
            for(i = 0; i < 3; i = i+1){
                printf ("%s, please select CARD %d to make a SET (example x = 0 y =0)\n", players_table[active_p].name, i+1);
                fflush(stdin);
                printf("x%d = ",i);
                scanf ("%d", &x);
                if (x>=0 && x<3){
                    fflush(stdin);
                    printf("y%d = ",i);
                    scanf ("%d", &y);
                    printf("\n");
                    if (y>=0 && y <4){
                        int ca;
                        ca = (x + 1)*(y + 1)-1;
                        if (i ==0){
                            c0 = ca;
                        }
                        else if(i == 1){
                            c1 = ca;
                        }
                        else{
                            c2 = ca;
                        }
                    }
                    else{
                        reset = 21;
                        break;
                    }
                }
                else{
                    reset = 21;
                    break;
                }
                final_table[i] = twoD_table[x][y];
            }
            if (reset != 21){
                if (c0!=c1 && c1!=c2 && c0 !=c2){
                    //printf("Check EVERYTHING!\n");
                    reset = check_cards(final_table);
                }
                else{
                    reset = 22;
                }
            }
        }
        else{
            if (a_char == '#'){
                getNextCard(rand_cards_table_pos);
                //printf("NEW CARDS ON TABLE! Welcome Hackers!.");
            }
            reset = 2;
        }
    }
    //printf("\nENDING RESET = %d\n", reset);
    fflush(stdin);

    return reset;
}

int check_cards(cards final_table[]){
    int reset;
    reset = 3;
    int con1, con2, con3, con4;
    con1 = con2 = con3 = con4 = 0;
    //COLOR CHECK
    if(final_table[0].color == final_table[1].color && final_table[1].color == final_table[2].color){
        con1 = 1;
    }
    else{
        if(final_table[0].color != final_table[1].color && final_table[1].color != final_table[2].color && final_table[0].color != final_table[2].color){
        con1 = 1;
        }
    }
    /*
    if (con1 == 1){
        printf("COLOR TRUE\n");
    }
    else{
        printf("COLOR FALSE\n");
    }
    printf("%c\n",final_table[0].color);
    printf("%c\n",final_table[1].color);
    printf("%c\n",final_table[2].color);
    */

    //SHAPE CHECK
    if(final_table[0].shape == final_table[1].shape && final_table[1].shape == final_table[2].shape){
        con2 = 1;
    }
    else{
        if(final_table[0].shape != final_table[1].shape && final_table[1].shape != final_table[2].shape && final_table[0].shape != final_table[2].shape){
        con2 = 1;
        }
    }
    /*
    if (con2 == 1){
        printf("SHAPE TRUE\n");
    }
    else{
        printf("SHAPE FALSE\n");
    }
    printf("%c\n",final_table[0].shape);
    printf("%c\n",final_table[1].shape);
    printf("%c\n",final_table[2].shape);
    */

    //NUMBER CHECK
    if(final_table[0].number == final_table[1].number && final_table[1].number == final_table[2].number){
        con3 = 1;
    }
    else{
        if(final_table[0].number != final_table[1].number && final_table[1].number != final_table[2].number && final_table[0].number != final_table[2].number){
        con3 = 1;
        }
    }
    /*
    if (con3 == 1){
        printf("NUMBER TRUE\n");
    }
    else{
        printf("NUMBER FALSE\n");
    }
    printf("%c\n",final_table[0].number);
    printf("%c\n",final_table[1].number);
    printf("%c\n",final_table[2].number);
    */

    //TEXTURE CHECK
    if(final_table[0].texture == final_table[1].texture && final_table[1].texture == final_table[2].texture){
        con4 = 1;
    }
    else{
        if(final_table[0].texture != final_table[1].texture && final_table[1].texture != final_table[2].texture && final_table[0].texture != final_table[2].texture){
        con4 = 1;
        }
    }
    /*
    if (con4 == 1){
        printf("TEXTURE TRUE\n");
    }
    else{
        printf("TEXTURE FALSE\n");
    }
    printf("%c\n",final_table[0].texture);
    printf("%c\n",final_table[1].texture);
    printf("%c\n",final_table[2].texture);
    */

    //if (con1 == 1){
    if (con1 == 1 && con2 == 1 && con3 == 1 && con4 == 1){
        reset = 4;
    }

    return reset;
}

void clear_s(void){
    while (getchar() != '\n');
}
