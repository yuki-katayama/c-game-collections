//
// Memory_Alphabet.c
//
//  Created by 片山優希 on 2020/01/22.
//  Copyright © 2020 片山優希. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
#define MAX_STAGE 10
#define level_m 10
#define level_s 3

int sleeps(unsigned long x)
{
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t) - 1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void)
{
    int stage;
    int success = 0;
    int level;
    time_t start,end;
    char eizi[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                  "abcdefghijklmnopqrstuvwxyz";
    int i;

    srand(time(NULL));
    printf("英字記憶トレーニング開始\n");
    do{
        printf("ステージ%d ~ %d 選択して下さい\n", level_s, level_m);
        scanf("%d",&level);
    }while(level < level_s || level > level_m);
    start = time(NULL);
    for(stage = 0; stage < MAX_STAGE; stage++){
        char no[level_m + 1];
        char x[level_m * 2];
        for(i = 0; i < level; i++)
            no[i] = eizi[rand() % strlen(eizi)];
        no[level] = '\0';
        printf("%s",no);
        fflush(stdout);
        sleeps(250 * level);
        printf("\r%*s\r入力 :", level,""); //複雑
        scanf("%s",x);
        if(strcmp(no,x) == 0){
            printf("正解です!\n");
            success++;
        }
        else
            printf("間違いです\n");
    }
    end = time(NULL);
    printf("%d 回中 %d 回成功しました。 %.0f秒かかりました\n", MAX_STAGE, success,difftime(end,start));
    return 0;
}

//二つとも数字に変換バージョンも考える. int no にしてからやってみる
