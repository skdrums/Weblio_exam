#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MAX 2048
using namespace std;
struct medal
{
        char *name;
        int gold;
        int silver;
        int bronze;
};

int main(void){

    struct medal a[8];

    
    FILE *fp ;
    char buf[MAX]={0};
    if((fp=fopen("medal_results.tsv","r"))!=NULL){
        /*ファイルの終わりまで繰り返し読み込む*/
        for(int i=0; fgets(buf,MAX,fp) != NULL; i++ ){
            a[i].name=strtok(buf,"\t");
            a[i].gold = atoi(strtok(NULL,"\t"));
            a[i].silver = atoi(strtok(NULL,"\t"));
            a[i].bronze = atoi(strtok(NULL,"\t"));
            cout<<a[i].name << a[i].gold<<a[i].silver<<a[i].bronze<<endl;

        }
    }
}

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// #define MAX 2048
// int main(void){
//     FILE *fp ;
//     char buf[MAX]={0};
//     char *ary[3] ;
//     int da[3];
//     double data[3]={0};
//     if((fp=fopen("medal_results.tsv","r"))!=NULL){
//         /*ファイルの終わりまで繰り返し読み込む*/
//        for(int i=0; fgets(buf,MAX,fp) != NULL; i++ ){
//             /*文字列(char配列)をカンマで分割する*/
//             ary[0] = strtok(buf,"\t");
//             ary[1] = strtok(NULL,"\t");
//             ary[2] = strtok(NULL,"\t");
//             da[1]=atoi(ary[1]);
//             da[2]=atoi(ary[2]);
            
//             /*文字列(char配列)をdoubleに変換する*/
//             data[1] = atof(ary[1]);
//             data[2] = atof(ary[2]);
//             printf("文字⇒%s : %s : %s",ary[0],ary[1],ary[2]);

//             printf("int⇒ : %d : %d",da[1],da[2]);
//             printf("数値⇒%.2f : %.2f\n",data[1],data[2]);
//             printf("----------------\n");
//         }
//     }
//     return 0;
// }
