//
//  Advanced_Calender.c
//
//  Created by 片山優希 on 2020/01/25.
//  Copyright © 2020 片山優希. All rights reserved.
//

#include <stdio.h>
#include<string.h>

int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


int dayofweek(int year, int month, int day) //ツェラーの公式
{
    if(month == 1 || month == 2){
        year--;
        month += 12;
    }
    return (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + day) % 7;
}

int uruu(int year) //閏年の関数
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}


int mday(int y, int m) //閏年だった場合2月に1をたす関数
{
    if(m-- != 2)
        return mdays[m];
    return mdays[m] + uruu(y);
}



void make_calendar(int y, int m, char s[7][22])
{
    int i,k;
    int wd = dayofweek(y, m, 1);
    int mdays = mday(y, m);
    char tmp[4];

    sprintf(s[0], "%10d / %02d      ", y, m); //タイトル(年 / 月)
    for (k = 1; k < 7; k++)
        s[k][0] = '\0';   //タイトル以外全てクリア
    //strcpy(s[k],"") でクリアできるが、[記憶域の浪費]と、[構造上負荷がかかる]からおすすめしない
    k = 1;
    //[k]は日付を格納している行のこと
    sprintf(s[k], "%*s",3 * wd, "");   //第一日の横の空白を作る
    for(i = 1; i <= mdays; i++){
        sprintf(tmp, "%3d", i);
        strcat(s[k], tmp);  //s[k](空白)の後にtmp(日付)を連結させる
        if(++wd % 7 == 0)
            k++;
    }
    if(wd % 7 == 0)
        k--;
    else{
        for(wd %= 7; wd < 7; wd++)
            strcat(s[k],"   ");   //最後に土曜日まで空白を入れる
    }
    while(++k < 7)
        sprintf(s[k],"%21s", ""); //一番最後の何も使われていない行を空白で埋め尽くす
}


void print(char sbuf[3][7][22], int n)
{
    int i,j;
    for(i = 0; i < n; i++)
        printf("%s   ", sbuf[i][0]);
    putchar('\n');
    for(i = 0; i < n; i++)
        printf(" 日 月 火 水 木 金 土   ");
    putchar('\n');
    for(i = 0; i < n; i++)
        printf("----------------------- ");
    putchar('\n');
    //カレンダー連続三つ表示する
    for(i = 1; i < 7; i++){  //カレンダー本体部
        for(j = 0; j < n; j++)   //横にn個並べる
            printf("%s   ",sbuf[j][i]);
        putchar('\n');
    }
    putchar('\n');
}


void put_calender(int y1, int m1, int y2, int m2)
{
    int y = y1;
    int m = m1;
    int n = 0;
    char sbuf[3][7][22];
    while (y <= y2){
        if(y == y2 && m > m2) break;
        make_calendar(y, m, sbuf[n++]);
        if(n == 3){
            print(sbuf,n); //カレンダー３ヶ月分貯まれば表示
            n = 0;
        }
        m++;
        if(m == 13 && y < y2){
            y++;
            m = 1;
        }
    }
    if(n)  //未表示の月があれば. 最後に n = 0 ~ 2で止まるなど
        print(sbuf,n);  //残ったものの表示
}


int main(void)
{
    int y1,m1,y2,m2;

    printf("カレンダーを表示します\n");
    printf("開始年月を入力して下さい\n");
    printf("年 :"); scanf("%d",&y1);
    printf("月 :"); scanf("%d",&m1);
    puts("終了年月を入力して下さい");
    printf("年 :"); scanf("%d",&y2);
    printf("月 :"); scanf("%d",&m2);
    putchar('\n');
    put_calender(y1,m1,y2,m2);

    return 0;
}
