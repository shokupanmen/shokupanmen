#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

unsigned int coin;/*コイン枚数*/
 int stagelv;/*ステージレベル*/
 int stagere;
 int selec; /*ステー時セレクト*/
unsigned int deme;/*ランダムで出たやつ*/
unsigned int kakekin;/*掛け金*/
unsigned int yosou;/*プレイヤーの予想*/
unsigned int i=0;/*時間（ターン）*/
 char end[]="end";
 char endp[10];
unsigned int goukeip=0;
unsigned int goukeig=0;
unsigned int atari;
 int motikin;
int kn=52;  /*キーの番号*/
char nyuuryoku='L';/*入力されたキー*/
int enter=1;/*enter*/
int owari=0;/*終わるかの判定に使う*/

int game(void){

do{
printf("掛け金を入力してください(%d倍)\n",stagere);
printf("持ち金 %d枚\n",coin);
scanf("%d",&kakekin);
motikin=coin-kakekin;
printf("掛け金 %d枚",kakekin);
printf("持ち金 %d枚\n",motikin);

atari=kakekin*stagere;

if(motikin<0){printf("コインがたりません！ \n");continue;}}while(motikin<0);

goukeip=goukeip+kakekin;
coin-=kakekin;

srand(time(NULL));
deme=rand()%stagelv+1;

printf("何にかける？(1～%dです。)\n",stagelv);
scanf("%d",&yosou);

printf("%dがでました！",deme);

if(yosou==deme){coin+=kakekin*stagere;goukeig+=kakekin*stagere;
printf("おめでとう。 %d枚のコインがあたりました！\n",atari);}
else{printf("ざまぁ見ろwww！\n");}

}

int main(void){
   while(owari==0) {
     i=0;
    /* code */
printf("数字当てクソゲー\n");
coin+=2000;
sleep(3);
while(coin>0){
i++;
printf("%d時間目",i);
printf("どれで遊ぶ？数字を入力して選んでね\n (確率,倍率)\n1 1/3,2\n2 1/4,3 \n3 1/5.6\n4 1/20,27\n5 1/200,600\n現在 %d枚持っています。\n",coin);
scanf("%d",&selec);

switch (selec){
  case 1:
stagelv=3;
stagere=2;
break;

  case 2:
stagelv=4;
stagere=3;
break;

  case 3:
stagelv=5;
stagere=6;
break;

  case 4:
stagelv=20;
stagere=25;
break;

 case 5:
stagelv=200;
stagere=600;
break;

 case 94:
stagelv=1;
stagere=100;
break;

case 16:
stagelv=300;
stagere=1090;
break;

case 17:
stagelv=500;
stagere=2000;
printf("りんとが数字決めたんやで、僕じゃないです\n");
break;

default:
printf("真面目に選べw\n");
continue;
}
game();
printf("現在 %d枚あります。\n",coin);
if(coin==0){printf("コインが0枚になりました。ゲームオーバーです\n");break;}


printf("やめるなら end と入力してEnterを押してください。\n続けるなら何でもいいから入力してEnterを押してください。\n");

scanf("%s", &endp);

if(strcmp(endp,end)==0){break;}
}

printf("    戦歴\n\n");
printf("最終所持コイン %d枚\n\n",coin);
printf("プレイ時間 %d時間(ゲーム内で)\n\n",i);
printf("賭けたコイン %d枚\n\n",goukeip);
printf("手に入れたコイン %d枚\n\n",goukeig);
getch();
printf("本当にここでおわっていいの？\n");

enter=1;

for(;;){
  system("cls");


  printf("本当におわっていいの?\n");
  if (/*nyuuryoku=='L'*/kn==52)    {printf(" ー＞ だめだ！ 　　 いいんです！\n");owari=0;}
  else/* if(nyuuryoku=='R')*/if (kn==54){printf(" 　　 だめだ！ ー＞ いいんです！\n");owari=1;}
  else continue;
  if(enter!=1){break;}
  printf("テンキーの　←　→　で操作してね\n");





  kn=getch();
  /*if(kn==52){nyuuryoku='L';}
  if(kn==54){nyuuryoku='R';}*/
  if(kn==13){enter=2;}
}

if(/*nyuuryoku=='L'*/kn==52){
  printf("OK やり直すんだね。\n");
  }

sleep(1);


}
printf("\n渡邉でした\n");
return 0;
}
