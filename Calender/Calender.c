//
//  Calender.c
//
//  Created by 片山優希 on 2020/01/24.
//  Copyright © 2020 片山優希. All rights reserved.
//

#include <stdio.h>

int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int dayofweek(int year, int month, int day) //ツェラーの公式
{
    if (month == 1 || month == 2)
	{
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
    if (m-- != 2)
        return mdays[m];
    return mdays[m] + uruu(y);
}


void put_calender(int y, int m)
{
    int i;
    int wd = dayofweek(y,m,1); // 1日が何曜日か
    int mday1 = mday(y,m);  //指定の月は何日あるか

    printf(" 日 月 火 水 木 金 土 \n");
    puts("------------------------");
    printf("%*s", 3/*←1日%3dの計算だから*/ * wd, "");

    for (i = 1; i <= mday1; i++){
        printf("%3d",i);
        if(++wd /*1個目はもう表示しているから*/ % 7 == 0)
            putchar('\n');
    }
    if (wd % 7 != 0) //一番最後の日の次に改行！！
        putchar('\n');
}

int main(void)
{
    int y1,m1;

    printf("開始年月を入力して下さい\n");
    printf("年 :"); scanf("%d",&y1);
    printf("月 :"); scanf("%d",&m1);
    put_calender(y1,m1);
    return 0;
}
