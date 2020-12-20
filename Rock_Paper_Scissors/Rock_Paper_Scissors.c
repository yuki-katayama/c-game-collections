//
// Rock_Paper_Scissors.c
//
//  Created by 片山優希 on 2020/01/20.
//  Copyright © 2020 片山優希. All rights reserved.
//

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int people;
int computer;
int judge;
int retry;

int win;
int draw;
int lose;
char *hd[] = {"グー", "チョキ", "パー"};

void syokiti(void)
{
    srand(time(NULL));
    puts("ジャンケンを始めます");
}

void start_k(void)
{
    int i;

    computer = rand() % 2;
    do{
        for(i = 0; i < 3; i++)
            printf("(%d)%s :", i, hd[i]);
            scanf("%d", &people);
    }while(people < 0 || people > 2);
}

void judge_k (int a)
{
    switch(a){
        case 0:
            puts("引き分けです");
            break;
        case 1:
            puts("あなたの負けです");
            break;
        case 2:
            puts("あなたの勝ちです");
            break;
        default:
            puts("存在しない手段です");
            break;
    }
}

void count(int a)
{
    switch(a){
        case 0:
            draw++;
            break;
        case 1:
            lose++;
            break;
        case 2:
            win++;
            break;
    }
}

int retry_k(void)
{
    int retry;

    printf("もう1度続けますか？ はい..1 : いいえ..2\n");
    scanf("%d", &retry);
    return retry;
}

int main(void)
{
    // clock_t start,end;

	syokiti();
    // start = clock();
    // printf( "開始時間:%lu\n", start );
    do{
        start_k();
        printf("あなたは %s で機械は %s です\n", hd[people], hd[computer]);
        judge = (people - computer + 3) % 3;
        judge_k(judge);
        count(judge);
    }while(!(win == 3 || lose == 3));
    // end = clock();
    // printf( "終了時間:%lu\n", end );
    printf("あなたは %d勝 : %d負 : %d分 でした\n", win, lose, draw);
    printf("機械は %d勝 : %d負 : %d分 でした\n", lose, win, draw);
    // printf( "処理時間:%lu[ms]\n", end - start );
    return 0;
}
