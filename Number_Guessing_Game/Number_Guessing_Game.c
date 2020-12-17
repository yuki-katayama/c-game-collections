//
// Number_Guess_Game.c
//
//  Created by 片山優希 on 2020/01/20.
//  Copyright © 2020 片山優希. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#define keta 3

void seisuu(int *a, int n)
{
    int i,j;
    for(i = 0; i < n; i++){
        do{
            a[i] = rand() % 10;
            for(j = 0; j < i; j++)
                if(a[i] == a[j])
                    break;
        }while(j < i);
    }
}


int check_k(char *a)
{
    int i,j;

    if(strlen(a) != 3)   //長さが3ではないとき
        return 1;
    for(i = 0; i < keta; i++){
        if(!isdigit(a[i]))
            return 2; //整数以外が入力慣れているとき
        for(j = 0; j < i; j++)
            if(a[i] == a[j])   //同一の文字があるとき
                return 3;
    }
    return 0;
}

void judge(char s[], int no[], int *hit, int *blow)
{
    int i,j;
    *hit = *blow = 0;  //*の必要性
    for(i = 0; i < keta; i++){
        for(j = 0; j < keta; j++){
            if(s[i] == '0' + no[j]){
                if(i == j)
                    (*hit)++;  //*の必要性
                else (*blow)++;
            }
        }
    }
}

void print_result(int a, int b)
{
    if(b == 3)
        puts("おめでとうございます。正解です");
    else if(a == 0)
        puts("全く含まれていません");
    else{
        printf("それらの数字中 %d 個の数字が含まれています\n",a);
        if(b == 0)
            printf("ただし位置が合っている数字がありません\n");
        else
            printf("その中の %d 個は位置があっています\n", b);
    }
    putchar('\n');
}

int main(void)
{
    int a[keta];
    char fuman[10];
    int check;
    int hit;
    int blow;
    int trycount = 0;
    clock_t start,finish;

    srand(time(NULL));
    seisuu(a,keta);
    printf("3つの整数を入力して下さい :");
    start = clock();
    do{
        do{
            scanf("%s",fuman);
            check = check_k(fuman);
            switch(check){
                case 1:
                    puts("整数をを3個入力して下さい");
                    break;
                case 2:
                    puts("整数をのみを入力して下さい");
                    break;
                case 3:
                    puts("同じ数字を入力しないでください");
                    break;
            }
        }while(check != 0);
        trycount++;
        judge(fuman, a, &hit, &blow);
        print_result(hit + blow, hit);
    }while(hit < 3);
    finish = clock();
    printf("%d回 かかりました。\n 所要時間は %.f秒でした\n", trycount, (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}
