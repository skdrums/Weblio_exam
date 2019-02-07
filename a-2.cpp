#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define N 8
#define MAX 2048


// CNA	16	7	3
// FRA	2	4	9
// GER	7	5	2
// ITA	3	8	2
// JPN	4	4	3
// KOR	6	15	2
// RUS	7	5	2
// USA	16	6	13


struct medal
{
        string name;
        int gold;
        int silver;
        int bronze;
};


void SortByMedal(struct medal *p){

    struct medal t;
    for(int i = 0; i < N-1; i++)
    {
        for(int j = N-1; j > i; j--)
        {
            if(strcmp((p+j)->name.c_str(),(p+(j-1))->name.c_str())<0){
                
                t=*(p+j);
                *(p+j)=*(p+j-1);
                *(p+j-1)=t;
            }
        }
        
    }
    

    for(int i = 0; i < N-1; i++)
    {
        for(int j = N-1; j > i; j--)
        {
            if((p+j)->bronze>(p+(j-1))->bronze){
                t=*(p+j);
                *(p+j)=*(p+j-1);
                *(p+j-1)=t;
            }
        }
        
    }

    for(int i = 0; i < N-1; i++)
    {
        for(int j = N-1; j > i; j--)
        {
            if((p+j)->silver>(p+(j-1))->silver){
                t=*(p+j);
                *(p+j)=*(p+j-1);
                *(p+j-1)=t;
            }
        }
        
    }

    for(int i = 0; i < N-1; i++)
    {
        for(int j = N-1; j > i; j--)
        {
            if((p+j)->gold>(p+(j-1))->gold){
                t=*(p+j);
                *(p+j)=*(p+j-1);
                *(p+j-1)=t;
            }
        }
        
    }
    




}

int main(void){
    
    struct medal *p,a[N];

    FILE *fp ;
    char buf[MAX]={0};
    if((fp=fopen("medal_results.tsv","r"))!=NULL){
        /*ファイルの終わりまで繰り返し読み込む*/
        for(int i=0; fgets(buf,MAX,fp) != NULL; i++ ){
            a[i].name=strtok(buf,"\t");
            a[i].gold = atoi(strtok(NULL,"\t"));
            a[i].silver = atoi(strtok(NULL,"\t"));
            a[i].bronze = atoi(strtok(NULL,"\t"));
            
        cout<<a[i].name<<endl;
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout<<a[i].name<<endl;

    }
    
    p=a;

    SortByMedal(p);

    for(int i = 0; i < N; i++)
    {
        cout<<(p+i)->name<<" "<<(p+i)->gold<<" "<<
        (p+i)->silver<<" "<<(p+i)->bronze<<endl;
    }
    



}





