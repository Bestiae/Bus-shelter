#include <stdio.h>
#include "cp_data1.h"

#define Pocet_zastavok 10

int vyber_zastavky(){
    int cislo;
    printf("\n\t\t\tZadaj cislo: ");
    scanf("%d", &cislo);

    return cislo;
}

void vypis_CP(int cislo){
    int rozdiel = cislo * DELTA;
    rozdiel -= DELTA;
    //printf("rozdiel je %d\n", rozdiel);

    printf("\t Hodina | Minuta\n");
    printf("\t............................................\n");

    int j = PRVY_SPOJ_M + rozdiel;
    int i;
    for(i = PRVY_SPOJ_H; i <= POSLED_SPOJ_H; i++){
        if(i < 10){
            printf("\t     0%d | ", i);
        } else{
            printf("\t     %d | ", i);
        }

        if((i >= RANO_START) && (i <= RANO_END)){
            for(j; j <= 60; j+=INTERVAL_RANO){

                if(j == 60){
                    //printf("%d ", j);
                    break;
                }
                if(j < 10){
                    printf("0%d ", j);
                } else{
                    printf("%d  ", j);
                }
            }
        }else if((i >= POOBEDE_START) && (i <= POOBEDE_END)){
            for(j; j <= 60; j += INTERVAL_POOBEDE){
                if(j == 60){
                    //printf("%d ", j);
                    break;
                }
                if(j < 10){
                    printf("0%d ", j);
                } else{
                    printf("%d  ", j);
                }
            }
        }else{
            for(j; j <= 60; j += INTERVAL_NORMAL){
                if(j == 60){
                    //printf("%d ", j);
                    break;
                }
                if(j < 10){
                    printf("0%d ", j);
                } else{
                    printf("%d  ", j);
                }
            }
        }
        j-=60;

        printf("\n");
    }
    getchar();
    getchar();
}

// vypis len casu
int vypis_CP2(int cislo){
    int H, M;
    printf("Zadaj hodinu a minutu(hh mm): ");
    scanf("%d %d", &H, &M);
    printf("%d %d\n", H, M);
    int rozdiel = cislo * DELTA;
    rozdiel -= DELTA;
    //printf("rozdiel je %d\n", rozdiel);

    int j = PRVY_SPOJ_M + rozdiel;
    int i;

    // if((i >= H)&&(j>=M)){
    //                        printf("Cas %d:%d\n", i, j);
    //                        return 0;
    //                    }
    for(i; i <= POSLED_SPOJ_H; i++){
        if((i < 10)&&(i == H)){
            printf("\t0%d | ", i);
        } else if((i >= 10)&&(i == H)){
            printf("\t%d | ", i);
        }

        if((i >= RANO_START) && (i <= RANO_END)){
            for(j; j <= 60; j+=INTERVAL_RANO){
                if((i >= H)&&(j>=M)){
                    printf("Cas %d:%d\n", i, j);
                    return 0;
                }
            }
        }else if((i >= POOBEDE_START) && (i <= POOBEDE_END)){
            for(j; j <= 60; j += INTERVAL_POOBEDE){
                if((i >= H)&&(j>=M)){
                    printf("Cas %d:%d\n", i, j);
                    return 0;
                }
            }
        }else{
            for(j = PRVY_SPOJ_M + rozdiel; j <= 60; j += INTERVAL_NORMAL){
                if((i >= H)&&(j>=M)){
                    printf("Cas %d:%d\n", i, j);
                    return 0;
                }
            }
        }
        j-=60;

        //printf("\n");
    }
    //printf("Cas: %d", H_p);
    getchar();
    getchar();
}

int main() {
    int H, M;
    int end = 1;
    int cislo_menu, cislo_P = 0;
    //cislo = vyber_zastavky();
    //printf("Si vybral cislo %d\n", cislo);
    //vypis_CP(cislo);

    while(end == 1) {
        CLEAR_SCREEN();
        printf("\n");
        printf("\n\t\t\t1. Vyber zastavky.\n");
        printf("\t\t\t2. Zobrazenie CP.\n");
        printf("\t\t\t3. Zistenie najbližšieho spoja.\n");
        printf("\t\t\t4. Vypis CP vsetkych zastavok.\n");
        printf("\t\t\t5. Ukoncenie programu\n");
        cislo_menu = vyber_zastavky();
        printf("\n");
        switch (cislo_menu) {
            case 1:
                CLEAR_SCREEN();
                int i;
                printf("\t\t\tExistuju take zastavky:\n\n");
                for(i = 1; i <= Pocet_zastavok; i++){
                    printf("\t\t\tZastavka cislo %d\n", i);
                }
                printf("\n\t\t\tZadaj cislo zastavky: ");
                scanf("%d", &cislo_P);
                break;
            case 2:
                CLEAR_SCREEN();
                if(cislo_P == 0){
                    printf("\n\t\t\tZadaj cislo zastavky: ");
                    scanf("%d", &cislo_P);
                    vypis_CP(cislo_P);
                }else {
                    printf("\t\tCislo zastavky je: %d\n\n", cislo_P);
                    vypis_CP(cislo_P);
                }
                break;
            case 3:
                CLEAR_SCREEN();
                if(cislo_P == 0){
                    printf("\n\t\t\tZadaj cislo zastavky: ");
                    scanf("%d", &cislo_P);
                    //printf("Zadaj hodinu a minutu(hh mm): ");
                    //scanf("%d %d", &H, &M);
                    //printf("%d %d\n", H, M);
                    vypis_CP2(cislo_P);
                    break;
                }else{
                    //printf("Zadaj hodinu a minutu(hh mm): ");
                   // scanf("%d %d", &H, &M);
                    //printf("%d %d\n", H, M);
                    vypis_CP2(cislo_P);
                    break;
                }
            case 4:
                CLEAR_SCREEN();
                for(i = 1; i <= Pocet_zastavok; i++){
                    printf("\n\t\t\tZastavka cislo %d\n\n", i);
                    vypis_CP(i);
                }
                break;
            case 5:
                end -= 1;
        }
    }

    return 0;
}