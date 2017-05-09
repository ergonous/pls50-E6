#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_ZERO 48

char pinakida[7];
int theseis;    //arithmos thesewn lewforeiou pou diavazei apo arxeio
int i;          //thesi leoforeiou
int k;          //gia bubblesort mazi me to i
int m;          //gia antikatastasi tilefwnou sto bubblesort
int j;          //thesi pinaka tilefwnou
int sumkenes;
int sumkratimenes;
int choice;

char tempLastName[40];
char tempName[40];
unsigned int tempSeatNo;
char tempTel[11];
char epivevaiwsi;
unsigned short swapTel[10];

//CODE CHANGED
typedef struct passenger{  //domi passenger me 3 metavlites
    char fullname[40];
    unsigned short tel[10];
    unsigned int seatNo;
    //struct passenger *next;
} passenger;

passenger *bus;
//passenger *head;
//passenger *newNode;
//passenger *current;

struct node{                                // œÃ¬œ”
    passenger data;
    struct node *next;
}*start=NULL;

//END OF CHANGE

void readFile();
void kenesTheseis();
void kratisiThesis();
void anazitisiMeOnoma();
void anazitisiMeTilefwno();
void akyrwsiThesis();
void kratimenesTheseis();
void writefile();

//CODE CHANGED
void prepare_list();                          //NEA SYNARTHSH

//END OF CHANGE

int main()
{
    readFile();
    printf("To lewforeio exei pinakida %s kai diathetei %d theseis\n\n", pinakida, theseis);

    do {
        printf("\nEpilekste ena apo ta parakatw: Epilekste\n");
        printf("1 gia emfanisi tou sinolou kenwn thesewn kai ton arithmwn me afksousa seira\n");
        printf("2 gia kratisi thesis me sigkekrimeno arithmo gia epivati tis epilogis sas\n");
        printf("3 gia na anazitisete me tilefwno i onom/mo epivati an mia thesi einai kratimeni\n");
        printf("4 gia na akirwsete mia kratimeni thesi me sygkekrimeno arithmo\n");
        printf("5 gia emfanisi tis listas kratimenwn thesewn\n");
        printf("0 gia eksodo apo to menou epilogwn\n");
        scanf(" %d", &choice);

        if (choice==1){
            kenesTheseis();
        }
        else if (choice==2){
            int kratisi;
            printf("Gia poia thesi epithimeite na ginei kratisi?\n");
            scanf(" %d", &kratisi);
            if (kratisi<1 || kratisi>theseis){
                printf("To lewforeio de diathetei ti thesi %d\n", kratisi);
            }
            else {
                kratisiThesis(&(bus[kratisi-1]));   //O deiktis tis sinartisis tha deixnei ti thesi tou lewforeiou
            }                                       //pou exei epilegei kai tha epistrefei tis nees times me anafora
        }
        else if (choice==3){
            char elegxosKratisis;
            printf("Epilekste 'o' gia anazitisi me on/mo h 't' gia anazitisi me tilefwno\n");
            scanf(" %c", &elegxosKratisis);
            if (elegxosKratisis=='o'){
                printf("Eisagete to onomatepwnymo tou epivati pou anazitate\n");
                scanf(" %s %s", tempLastName, tempName);
                strcat(tempLastName, " ");
                strcat(tempLastName, tempName);
                anazitisiMeOnoma(&tempLastName);
            }
            else if (elegxosKratisis=='t'){
                printf("Eisagete to tilefwno tou epivati pou anazitate\n");
                scanf(" %s", tempTel);
                anazitisiMeTilefwno(&tempTel);
            }
            else
                printf("Mi egkyri epilogi\n\n");
        }
        else if (choice==4){
            int akyrwsi;
            printf("Gia poia thesi epithimeite na ginei akyrwsi?\n");
            scanf(" %d", &akyrwsi);
            if (akyrwsi<1 && akyrwsi >theseis){
                printf("To lewforeio de diathetei ti thesi %d\n", akyrwsi);
            }
            else{
                akyrwsiThesis(&(bus[akyrwsi-1]));
            }
        }
        else if (choice==5){
            kratimenesTheseis();
        }
        //CODE CHANGED
        else if (choice==0){                //ƒÈÔÒË˘ÛÁ
        //END OF CHANGE
              prepare_list();
              writefile();
        }
        else if (choice<0 || choice>6){
            printf("Parakalw epilekste metaksy tou 0 kai tou 5");
        }

    } while(choice!=0);


    return 0;
}

void readFile(){

    FILE *fpointer;
    fpointer = fopen("bus.txt", "r");

    if (fpointer==NULL){
        printf("To arxeio de mporese na anagnwstei\n");
        exit(1);
    }
    fscanf(fpointer," %s %d", pinakida, &theseis);

    bus = (passenger *)malloc(theseis * sizeof(struct passenger));  //desmefsi mnimis
    if (bus == NULL){                              //elegxos an yparxei diathesimi mnimi
        printf("Den yparxei diathesimi mnimi\n");
        exit(1);
    }

    for (i=0; i<theseis; i++){          //arxikopoiisi pinaka
        strcpy(bus[i].fullname, "\0");
        bus[i].seatNo = i+1;
        for (j=0; j<10; j++){
            bus[i].tel[j] = 0;
        }
    }
    while(!feof(fpointer)){
        tempLastName[0] = '\0';
        fscanf(fpointer,"%s %s %d %s", tempLastName, tempName, &tempSeatNo, tempTel);

        //CODE CHANGED
        int ch;
        ch = tempLastName[0];
        if (ch != '\0'){
            strcat(tempLastName, " ");
            strcat(tempLastName, tempName);
            strcpy(bus[tempSeatNo-1].fullname, tempLastName);
        }

        printf("%s\n", bus[tempSeatNo-1].fullname);
        //END OF CHANGE

    }

    fclose(fpointer);

    return;
}

//CODE CHANGED
void prepare_list(){

    // ’–¡—◊≈… –—œ¬À«Ã¡ Ã≈ ‘¡ ‘«À≈÷ŸÕ¡ - ¬√¡∆≈… Ã«ƒ≈Õ… ¡  ‘”≈ ¡—≈ ‘œ
    /*
    for (i=1; i<theseis; i++) {         //epistrofi se taksinomisi kata onomatepwnymo
        for (k=0; k<=theseis-1-i; k++){
            for (j=0; j<40; j++){
                if (bus[k].fullname[j] > bus[k+1].fullname[j]){
                    strcpy(tempLastName, bus[k+1].fullname);
                    strcpy(bus[k+1].fullname, bus[k].fullname);
                    strcpy(bus[k].fullname, tempLastName);
                    tempSeatNo = bus[k+1].seatNo;
                    bus[k+1].seatNo = bus[k].seatNo;
                    bus[k].seatNo = tempSeatNo;
                    for (m=0; m<10; m++){
                                swapTel[j] = bus[k+1].tel[j];
                    }
                    for (m=0; m<10; m++){
                                bus[k+1].tel[m] = bus[k].tel[m];
                    }
                    for (m=0; m<10; m++){
                                bus[k].tel[m] = swapTel[m];
                    }
                    break;
                }
                else if (bus[k].fullname[j] < bus[k+1].fullname[j]){
                    break;
                }
            }
        }
    }
    */

    int i;
    struct node *new_node, *current;
    for (i=0; i<theseis; i++){
        if (bus[i].fullname[0] != '\0'){
            new_node=(struct node *)malloc(sizeof(struct node)); //ƒ›ÛÏÂıÛÁ ÏÌﬁÏÁÚ Í·È ‰ÁÏÈÔıÒ„ﬂ· struct node

            passenger d;                    //œÒÈÛÏ¸Ú ÏÂÙ·‚ÎÁÙﬁÚ Ù˝Ôı passenger
            d = bus[i];
            passenger *p;
            p = &d;

            new_node->data  = *p;
            new_node->next=NULL;

            if(start==NULL){                // AÎ‹ ”ıÌ‰Â‰ÂÏ›ÌÁ ÀﬂÛÙ·
                start=new_node;
                current=new_node;
            }
            else{
                current->next=new_node;
                current=new_node;
            }
        }
    }
}

void writefile(){

    FILE *fpointer;
    fpointer = fopen("bus.txt", "w");

    if (fpointer==NULL){
        printf("To arheio bus.txt de mporese na anagnostei\n");
        exit(1);
    }
    fprintf(fpointer, "%s %d\n", pinakida, theseis);

    //ƒ…≈√—¡ÿ≈ ¡’‘¡
    /*
    for (i=1; i<theseis; i++) {         //epistrofi se taksinomisi kata onomatepwnymo
        for (k=0; k<=theseis-1-i; k++){
            for (j=0; j<40; j++){
                if (bus[k].fullname[j] > bus[k+1].fullname[j]){
                    strcpy(tempLastName, bus[k+1].fullname);
                    strcpy(bus[k+1].fullname, bus[k].fullname);
                    strcpy(bus[k].fullname, tempLastName);
                    tempSeatNo = bus[k+1].seatNo;
                    bus[k+1].seatNo = bus[k].seatNo;
                    bus[k].seatNo = tempSeatNo;
                    for (m=0; m<10; m++){
                                swapTel[j] = bus[k+1].tel[j];
                    }
                    for (m=0; m<10; m++){
                                bus[k+1].tel[m] = bus[k].tel[m];
                    }
                    for (m=0; m<10; m++){
                                bus[k].tel[m] = swapTel[m];
                    }
                    break;
                }
                else if (bus[k].fullname[j] < bus[k+1].fullname[j]){
                    break;
                }
            }
        }
    }

    head = 0;

    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, "\0")!=0){
            newNode = (passenger *)malloc(sizeof(struct passenger));
            newNode->fullname[40] = bus[i].fullname;
            newNode->seatNo = bus[i].seatNo;
            for (j=0; j<10; j++){
                newNode->tel[j] = bus[i].tel[j];
            }
            if (head==NULL){
                newNode->next = NULL;
                head = newNode;
            }
            else if (head!=NULL){
                while (newNode->next!=0){
                    newNode = newNode->next;
                }
                newNode->next = NULL;
            }
        }
    }

    current = head;
    while (current!=NULL){
        printf("Onoma: %s Arithmos Thesis %d Tilefwno ", current->fullname, current->seatNo);
        for (j=0; j<10; j++){
            printf("%hu", current->tel);
        }
        printf("\n");
        current = current->next;
    }
    */



    struct node *new_node;

    new_node=start;                                        // ƒÂﬂÍÙÁÚ = ƒÂﬂÍÙÁ start
    while(new_node!=NULL){                              //”‹Ò˘ÛÁ ÙÁÚ ÎﬂÛÙ·Ú
        int x;
        //œÕœÃ¡
        for(x =0; new_node->data.fullname[x]; x = x+1){
            //printf("%c", new_node->data.fullname[x]);
            fprintf(fpointer, "%c", new_node->data.fullname[x]);
        }
        //printf(" ");
        fprintf(fpointer, " ");
        //»≈”«
        //printf("%d ", new_node->data.seatNo);
        fprintf(fpointer, "%d", new_node->data.seatNo);
        //printf(" ");
        fprintf(fpointer, " ");
        //‘«À≈÷ŸÕœ
        for(x =0;  x< 10; x = x + 1){
            //printf("%hu", new_node->data.tel[x]);
            fprintf(fpointer, "%hu", new_node->data.tel[x]);
        }

        //printf("\n");
        fprintf(fpointer, "\n");

        new_node=new_node->next;
    }

    fclose(fpointer);

    return 0;
}
//END OF CHANGE

void kenesTheseis(){
    sumkenes=0;
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, "\0")==0){
            sumkenes += 1;
        }
    }
    if (sumkenes == 0){
        printf("To lewforeio einai plires!\n");
    }
    else {
        printf("Sto lewforeio yparxoun synolika %d kenes theseis\n", sumkenes);
        printf("Oi kenes theseis taksinomimenes kata auksousa seira einai oi eksis:\n");
        for (i=0; i<theseis; i++){
            if (strcmp(bus[i].fullname, "\0")==0){
                printf("thesi %d\n", bus[i].seatNo);
            }
        }
        printf("\n\n");
    }
    return;
}

void kratisiThesis(passenger *p){      //deiktis gia thesi lewforeiou bus[kratisi-1]

    if (strcmp((*p).fullname, "\0")!=0){
        printf("I thesi %d pou epileksate einai idi kratimeni\n", (*p).seatNo);
    }
    else {
        printf("I thesi einai eleftheri. Parakalw eisagete to onomatepwnimo tou epivati\n");
        scanf(" %s %s", tempLastName, tempName);
        printf("Eisagete to tilefwno tou epivati\n");
        scanf(" %s", tempTel);
        strcat(tempLastName, " ");
        strcat(tempLastName, tempName);
        printf("Eiste vevaioi oti thelete na kratithei i thesi %d gia epivati me on/mo %s\n", (*p).seatNo, tempLastName);
        printf("kai til %s? Epilekste y/n\n", tempTel);
        scanf(" %c", &epivevaiwsi);

        if (epivevaiwsi=='y'){
            strcpy((*p).fullname, tempLastName);
            for (j=0; j<10; j++){
                (*p).tel[j] = tempTel[j] - ASCII_ZERO;
            }
            printf("I kratisi tis thesis me arithmo %d gia ton epivati %s ", (*p).seatNo, (*p).fullname);
            printf("me tilefwno %s oloklirwthike!\n\n", tempTel);
        }
        else if (epivevaiwsi=='n'){
            printf("I diadikasia kratisis thesis termatistike\n\n");
        }
        else
            printf("mi egkyri epilogi!!");
    }
    return;
}

void anazitisiMeOnoma(char *tempLastName){
    int found = 0;  //an de vrethei epivatis me idio onomatepwnymo i found menei miden kai typwnetai to apotelesma
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, tempLastName)==0){
            printf("O epivatis me on/mo %s vrisketai sti thesi %d\n", tempLastName, bus[i].seatNo);
            found += 1;  // gia kathe epivati me idio on/mo afksanei to found paratirwntas diploeggrafes i epivati me idio on/mo
        }
    }
    if (found > 1){
        printf("Vrethikan synolika %d epivates me to onomatepwnymo pou anazitate!!\n", found);
    }
    if (found ==0){
        printf("De vrethike kratimeni thesi gia to on/mo %s\n", tempLastName);
    }
    return;
}

void anazitisiMeTilefwno(char *tempTel){
    int found = 0;
    for (i=0; i<theseis; i++){
        if ((bus[i].tel[0]==tempTel[0])&&(bus[i].tel[1]==tempTel[1])&&(bus[i].tel[2]==tempTel[2])
            &&(bus[i].tel[3]==tempTel[3])&&(bus[i].tel[4]==tempTel[4])&&(bus[i].tel[5]==tempTel[5])
            &&(bus[i].tel[6]==tempTel[6])&&(bus[i].tel[7]==tempTel[7])&&(bus[i].tel[8]==tempTel[8])
            &&(bus[i].tel[9]==tempTel[9])){

            if (strcmp(bus[i].fullname, "\0")!= 0){
                printf("O epivatis me til %s vrisketai sti thesi %u kai onomazetai %s\n", tempTel, bus[i].seatNo, bus[i].fullname);
                found +=1;
            }
            if (strcmp(bus[i].fullname, "\0")==0){
                printf("To tilefwno %s einai kataxwrimeno sti thesi %d omws i thesi einai keni\n", tempTel, bus[i].seatNo);
                found +=1;
            }
        }
    }
    if (found > 1){
        printf("To tilefwno pou anazitate vrethike einai kataxwrimeno 2 fores\n");
    }
    if (found == 0){
        printf("Den yparxei kratimeni thesi pou na antistoixei sto tilefwno pou zitisate\n\n");
    }
    return;
}

void akyrwsiThesis(passenger *p){
    char epivevaiwsi;

    if(strcmp((*p).fullname, "\0")==0){
            printf("I thesi %d pou epileksate einai idi eleftheri\n\n", (*p).seatNo);
    }
    else {
        printf("I thesi einai kratimeni ston epivati %s me til ", (*p).fullname);
        for (j=0; j<10; j++){
            printf("%hu", (*p).tel[j]);
        }
        printf("\nEiste vevaioi oti thelete na akyrwthei i thesi %d gia epivati me on/mo %s kai til ", (*p).seatNo, (*p).fullname);
        for (j=0; j<10; j++){
            printf("%hu", (*p).tel[j]);
        }
        printf(" ?\nEpilekste y/n\n");

        scanf(" %c", &epivevaiwsi);
        if (epivevaiwsi=='y'){
            tempSeatNo = (*p).seatNo;
            strcpy(tempLastName, (*p).fullname);

            strcpy((*p).fullname, "\0");
            for (j=0; j<10; j++){
                (*p).tel[j] = 0;
            }
            printf("I akyrwsi tis thesis me arithmo %d gia ton epivati %s oloklirwthike!!\n\n", (*p).seatNo, (*p).fullname);
        }
        else if (epivevaiwsi=='n'){
            printf("I diadikasia akyrwsis thesis termatistike!\n\n");
        }
        else{
            printf("mi egkyri epilogi!!\n\n");
        }
    }
    return;
}

void kratimenesTheseis(){
    sumkratimenes=0;
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, "\0")!=0){
            sumkratimenes += 1;
        }
    }
    if (sumkratimenes == 0){
        printf("Den yparxoun kratimenes theseis sto lewforeio\n");
    }
    else {
        printf("Sto lewforeio yparxoun synolika %d kratimenes theseis\n", sumkratimenes);
        printf("Parakalw epilekste ti seira emfanisis twn kratimenwn thesewn. Epilekste:\n");
        printf("1 gia emfanisi kata tilefwno i\n2 gia emfanisi kata onomatepwnymo\n");
        scanf(" %d", &choice);

        if (choice==1){             //taksinomisi kata tilefwno
            for (i=1; i<theseis; i++){
                for (k=0; k<=theseis-1-i; k++){
                    for (j=0; j<10; j++){
                        if (bus[k].tel[j] > bus[k+1].tel[j]){
                            strcpy(tempLastName, bus[k+1].fullname);
                            strcpy(bus[k+1].fullname, bus[k].fullname);
                            strcpy(bus[k].fullname, tempLastName);
                            tempSeatNo = bus[k+1].seatNo;
                            bus[k+1].seatNo = bus[k].seatNo;
                            bus[k].seatNo = tempSeatNo;
                            for (m=0; m<10; m++){
                                swapTel[m] = bus[k+1].tel[m];
                            }
                            for (m=0; m<10; m++){
                                bus[k+1].tel[m] = bus[k].tel[m];
                            }
                            for (m=0; m<10; m++){
                                bus[k].tel[m] = swapTel[m];
                            }
                            break;
                        }
                        else if (bus[k].tel[j] < bus[k+1].tel[j]){
                            break;
                        }
                    }
                }
            }
            printf("Oi kratimenes theseis taksinomimenes kata tilefwno einai oi eksis:\n");
            for (i=0; i<theseis; i++){
                if (strcmp(bus[i].fullname, "\0")!=0){
                    printf("On/mo: %s Thesi: %d Tilefwno: ", bus[i].fullname, bus[i].seatNo);
                    for (j=0; j<10; j++){
                        printf("%hu", bus[i].tel[j]);
                    }
                    printf("\n");
                }
            }
            for (i=1; i<theseis; i++) {         //epistrofi se taksinomisi kata onomatepwnymo
                for (k=0; k<=theseis-1-i; k++){
                    for (j=0; j<40; j++){
                        if (bus[k].fullname[j] > bus[k+1].fullname[j]){
                            strcpy(tempLastName, bus[k+1].fullname);
                            strcpy(bus[k+1].fullname, bus[k].fullname);
                            strcpy(bus[k].fullname, tempLastName);
                            tempSeatNo = bus[k+1].seatNo;
                            bus[k+1].seatNo = bus[k].seatNo;
                            bus[k].seatNo = tempSeatNo;
                            for (m=0; m<10; m++){
                                swapTel[j] = bus[k+1].tel[j];
                            }
                            for (m=0; m<10; m++){
                                bus[k+1].tel[m] = bus[k].tel[m];
                            }
                            for (m=0; m<10; m++){
                                bus[k].tel[m] = swapTel[m];
                            }
                            break;
                        }
                        else if (bus[k].fullname[j] < bus[k+1].fullname[j]){
                            break;
                        }
                    }
                }
            }
        }
        else if (choice==2){            //taksinomisi kata onomatepwnymo
            for (i=1; i<theseis; i++) {
                for (k=0; k<=theseis-1-i; k++) {
                    for (j=0; j<40; j++){
                        if (bus[k].fullname[j] > bus[k+1].fullname[j]){
                            strcpy(tempLastName, bus[k+1].fullname);
                            strcpy(bus[k+1].fullname, bus[k].fullname);
                            strcpy(bus[k].fullname, tempLastName);
                            tempSeatNo = bus[k+1].seatNo;
                            bus[k+1].seatNo = bus[k].seatNo;
                            bus[k].seatNo = tempSeatNo;
                            for (m=0; m<10; m++){
                                swapTel[m] = bus[k+1].tel[m];
                            }
                            for (m=0; m<10; m++){
                                bus[k+1].tel[m] = bus[k].tel[m];
                            }
                            for (m=0; m<10; m++){
                                bus[k].tel[m] = swapTel[m];
                            }
                            break;
                        }
                        else if (bus[k].fullname[j] < bus[k+1].fullname[j]){
                            break;
                        }
                    }
                }
            }
            printf("Oi kratimenes theseis taksinomimenes kata onomatepwnymo einai oi eksis:\n");
            for (i=0; i<theseis; i++){
                if (strcmp(bus[i].fullname, "\0")!=0){
                    printf("On/mo: %s Thesi: %u Tilefwno: ", bus[i].fullname, bus[i].seatNo);
                    for (j=0; j<10; j++){
                        printf("%hu", bus[i].tel[j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return;
}
