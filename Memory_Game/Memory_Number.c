//
//  main.c
//  プラスワントレーニング
//
//  Created by 片山優希 on 2020/01/23.
//  Copyright © 2020 片山優希. All rights reserved.
//

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX_STAGE 10
#define level_m 10
#define level_s 3
int sleep1(unsigned long x) //int型でも問題なかった
{
    clock_t s1 = clock(), s2;
    do{
        if((s2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (s2 - s1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void)
{
    int level;
    int i,j;
    int comp[level_m];
    int fuman[level_m * 2];
    int stage = 0,stage2;
    int seikai;
    int seikai_all = 0;
    int score[MAX_STAGE];
    int retry = 0;
    srand(time(NULL));
    
    puts("プラスパワートレーニング開始！");
    puts("２桁の数字を記憶します");
    
    //レベルの選択
    do{
        printf("挑戦するレベル (%d ~ %d)", level_s, level_m);
        scanf("%d",&level);
    }while(level < level_s || level > level_m);
    
    
    do{
        printf("%dステージ開始!\n",stage + 1);
        seikai = 0;
        
        //表示される数字
        for(i = 0; i < level; i++){
            comp[i] = 10 + rand() % 90;
            printf(" %d ",comp[i]);
        }
        //表示時間
        fflush(stdout);
        sleep1(500 * level);
        printf("\r%*s\r",3 * level, "");
        fflush(stdout); //無くても行けた
        
        //入力
        for(i = 0; i < level; i++){
            printf("%d番目の数 : ",i + 1);
            scanf("%d",&fuman[i]);
        }
        
        //○・×の判定
        for(i = 0; i < level; i++){
            if(comp[i] == fuman[i]){
                printf(" ○ ");
                seikai++;
            }else
            printf(" × ");
        }
        putchar('\n');
        
        //1問の正解数
        for(i = 0; i < level; i++)
            printf("%3d",comp[i]);
        printf("・・・・%d個正解です\n",seikai);
        
        //score = 各ステージの正解数を格納 と 全体の正解数の計算
        score[stage++ % MAX_STAGE] = seikai;
        seikai_all += seikai;
        
        //リトライするか
        printf("まだ続けますか? (0)..いいえ : (1)..はい");
        scanf("%d",&retry);
    }while(retry == 1);
    
    //全体の戦績
    printf("%d個中 %d個正解しました。\n", level * MAX_STAGE, seikai_all);
    
    //表示する先頭のステージの設定
    stage2 = stage - MAX_STAGE;
    if(stage2 < 0)
        stage2 = 0;
    
    //戦績
    for(i = stage2; i < stage; i++){
        printf("第%2d ステージ :",i + 1);
        printf("%d\n",score[i % MAX_STAGE]);
    }
    
    
    puts("---------------横向きグラフ-----------------");
    //複雑
    for(i = stage2; i < stage; i++){
        printf("第 %d ステージ :", i + 1);
        for(j = 0;j < score[i % MAX_STAGE]; j++)
            printf("⭐︎");
        putchar('\n');
    }
    
    puts("-----------------縦向きグラフ-----------------");
    //横向きと同様
    for(i = level; i > 0; i--){
        for(j = stage2; j < stage; j++)
            if(score[j % MAX_STAGE] >= i)
                printf(" * ");
        else
            printf("   ");
        putchar('\n');
    }
    puts("----------------------------------------");
    for(i = stage2; i < stage; i++)
        printf("%02d ",i + 1);

    return 0;
}
