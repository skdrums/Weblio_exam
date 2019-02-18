#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<random>
using namespace std;      
#define M 100

int seifu(void){
    random_device rnd;//非決定的な生成乱数
    mt19937 mt(rnd());//決定的な生成乱数
    
    if(mt()%2==0) return 1;
    else return -1;
}
int main(void){

    struct zahyo{
        int x;
        int y;
    } z[M];

    random_device rnd;//非決定的な生成乱数
    mt19937 mt(rnd());//決定的な生成乱数
    
    //乱数によるデータの入力
    for(int i = 0; i < M; i++){
            z[i].x=(mt())%100*seifu();
            z[i].y=(mt())%100*seifu();
    }
    
    for(int i = 0; i < M; i++)
    {
        cout << z[i].x << " " << z[i].y << endl;
    }
    










}