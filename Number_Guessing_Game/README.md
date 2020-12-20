# Number_Guessing_Game.c
## 日本語
### 概要
機会が用意している3桁の数字を推理するゲームです。

ゲームルール参考サイト
[https://www.roomie.jp/2012/07/14669/]

### 使用方法
+ 0~9の重複のない3つの整数を連続で入力する。例(490)
+ 含まれている数字の数、また数字の位置が合っている数が表示される、
+ 表示されたヒントを元に、機械が用意している3桁の数字を当てる。
+ 最後は、正解までに、何回回答されたか表示される。

### コンパイル方法
	gcc -Wextra -Werror -Wall Number_Guessing_Game.c

## English
### Summary
This is a game of guessing the 3-digit number provided by the opportunity.

Game rule reference site
[https://www.roomie.jp/2012/07/14669/]

### Usage.
+ Enter three non-overlapping integers of 0~9 in succession. Example (490).
+ The number of numbers in the sequence and the number of correct positions of the numbers will be displayed.
+ Guess the 3-digit number provided by the machine, based on the clues shown.
+ At the end, the number of times the answer is given before the correct answer is displayed.

### How to compile
	gcc -Wextra -Werror -Wall Number_Guessing_Game.c

## PlayPage
![pic-1](https://i.gyazo.com/5ed9afed011349b113e0887ab564c011.png)