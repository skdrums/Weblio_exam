#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<random>
#include <math.h>
#include <cmath>
using namespace std;      
#define M 100
#define N 3

int seifu(void);

//頂点の定義
struct Vertex2D{
	double x;
	double y;
};

struct min_triangle{
    double min;
    Vertex2D dot[4];
}; 

//ベクトルの定義(頂点と同じ)
#define Vector2D Vertex2D

//点間距離
double distance_vertex(Vertex2D p1, Vertex2D p2) {
	return pow( ( p2.x - p1.x ) * ( p2.x - p1.x ) + ( p2.y - p1.y ) * ( p2.y - p1.y ), 0.5 );
}

//ベクトル外積
double cross_vector(Vector2D vl, Vector2D vr) {
	return vl.x * vr.y - vl.y * vr.x;
}

//点Pと線(AB)の距離
double Distance_DotAndLine(Vertex2D, Vertex2D, Vertex2D);
double Distance_DotAndDot(Vertex2D,Vertex2D);
double Area_Triangle(Vertex2D,Vertex2D,Vertex2D);
void CmpEachSide(double a[]);

int main(void){

    struct min_line{
        double min;
        Vertex2D start;
        Vertex2D end;
    } min_line[10]={0,{0,0},{0,0}};

    min_triangle min_tri[10]={{0,0},{0,0},{0,0}};

    Vertex2D z[M];
    double m,n;
    Vertex2D p={0,10},a={0,0},b={10,3};

    random_device rnd;//非決定的な生成乱数
    mt19937 mt(rnd());//決定的な生成乱数
    uniform_int_distribution<> rand100(0,99);//0-99の一様乱数

    //乱数によるデータの入力
    for(int i = 0; i < M; i++){
            z[i].x=rand100(mt)*seifu();
            z[i].y=rand100(mt)%100*seifu();
    }

    //最短距離の２点の組み合わせ
    min_line[0].min=Distance_DotAndDot(z[0],z[1]);
    min_line[0].start=z[0];
    min_line[0].end=z[1];
    
    int line_number=1;
    for(int i=0;i<M-1;i++){
        for(int j=i+1;j<M;j++){
            if(min_line[0].min>Distance_DotAndDot(z[i],z[j])&&Distance_DotAndDot(z[i],z[j])!=0){
                min_line[0].min=Distance_DotAndDot(z[i],z[j]);
                min_line[0].start=z[i];
                min_line[0].end=z[j];
                for(int k=1;k<=line_number;k++) min_line[k]=min_line[9];
            }
            else if(min_line[0].min==Distance_DotAndDot(z[i],z[j])){
                min_line[line_number].min=Distance_DotAndDot(z[0],z[1]);
                min_line[line_number].start=z[i];
                min_line[line_number++].end=z[j];
            }
        }
    }
    int line_flag;
    for(int i=0;i<10;i++){
        if(min_line[i].min==0){
            line_flag=i;
            break;
        }
    }
    //確認
    for(int i=0;i<line_number;i++){
        cout<<min_line[i].min<<" "<<min_line[i].start.x<<" "<<min_line[i].start.y<<" "<<min_line[i].end.x<<" "<<min_line[i].end.y<<endl;
    }
    cout<<line_flag<<endl;

    //上の２点による線と最小の距離を取る点を探す
    
    //min_tri.minの初期値の入力
    Vertex2D vertex;
    if((min_line[0].start.x!=z[0].x&&min_line[0].start.y!=z[0].y)&&(min_line[0].end.x!=z[0].x&&min_line[0].end.y!=z[0].y)) vertex=z[0];
    else if((min_line[0].start.x!=z[1].x&&min_line[0].start.y!=z[1].y)&&(min_line[0].end.x!=z[1].x&&min_line[0].end.y!=z[1].y)) vertex=z[1];
    else vertex=z[2];
    
    min_tri[0].min=Distance_DotAndLine(vertex,min_line[0].start,min_line[0].end);
    min_tri[0].dot[0]=min_line[0].start;
    min_tri[0].dot[1]=min_line[0].end;
    min_tri[0].dot[2]=vertex;
    min_tri[0].dot[3]=min_tri[0].dot[0];
    int tri_number=1;
    for(int i=0;i<line_flag;i++){
        
        for(int j=1;j<M;j++){
            if((min_line[i].start.x==z[j].x&&min_line[i].start.y==z[j].y)||(min_line[i].end.x==z[j].x&&min_line[i].end.y==z[j].y)) continue;
            if(min_tri[0].min>Distance_DotAndLine(z[j],min_line[i].start,min_line[i].end)&&Distance_DotAndLine(z[j],min_line[i].start,min_line[i].end)!=0){
                min_tri[0].min=Distance_DotAndLine(z[j],min_line[i].start,min_line[i].end);
                min_tri[0].dot[0]=min_line[i].start;
                min_tri[0].dot[1]=min_line[i].end;
                min_tri[0].dot[2]=z[j];
                min_tri[0].dot[3]=min_tri[0].dot[0];

                //いままでのmin_tri[1]-[9]の初期化
                for(int k=1;k<=tri_number;k++) min_tri[k]=min_tri[9];
            }
            else if(min_tri[0].min==Distance_DotAndLine(z[j],min_line[i].start,min_line[i].end)){
                min_tri[tri_number].min=Distance_DotAndLine(z[j],min_line[i].start,min_line[i].end);
                min_tri[tri_number].dot[0]=min_line[i].start;
                min_tri[tri_number].dot[3]=min_tri[tri_number].dot[0];
                min_tri[tri_number].dot[1]=min_line[i].end;
                min_tri[tri_number++].dot[2]=z[j];

            };
        }
    }

    //確認
    for(int i=0;i<tri_number;i++){
        cout<<min_tri[i].min<<" "<<min_tri[i].dot[0].x<<" "<<min_tri[i].dot[0].y<<" "<<min_tri[i].dot[1].x<<" "<<min_tri[i].dot[1].y
        <<" "<<min_tri[i].dot[2].x<<" "<<min_tri[i].dot[2].y<<endl;
    }

    //全ての辺の長さを出す
    double side_len[tri_number][3];
    for(int i=0;i<tri_number;i++){
        for(int j=0;j<3;j++){
            side_len[i][j]=Distance_DotAndDot(min_tri[i].dot[j],min_tri[i].dot[j+1]);
        }
    }
    
    //確認
    for(int i=0;i<tri_number;i++){
        for(int j=0;j<3;j++){
            cout<<"length"<<side_len[i][j]<<endl;
        }
    }

    CmpEachSide(side_len[0]);
    for(int i=0;i<tri_number;i++){
        for(int j=0;j<3;j++){
            cout<<"length"<<side_len[i][j]<<endl;
        }
    }
}

int seifu(void){
    random_device rnd;//非決定的な生成乱数
    mt19937 mt(rnd());//決定的な生成乱数
    
    if(mt()%2==0) return 1;
    else return -1;
}

double Distance_DotAndLine(Vertex2D P, Vertex2D A, Vertex2D B )
{
	Vector2D AB,AP;

	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	AP.x = P.x - A.x;
	AP.y = P.y - A.y;

	//ベクトルAB、APの外積の絶対値が平行四辺形Dの面積になる
	double D = abs( cross_vector( AB, AP ) );

	double L = distance_vertex( A, B );	//AB間の距離

	double H = D / L;
	return H;

}

double Distance_DotAndDot(Vertex2D a,Vertex2D b){
    double m,n;
    m=pow(a.x-b.x,2);
    n=pow(a.y-b.y,2);
    return sqrt(m+n);
}

double Area_Triangle(Vertex2D m,Vertex2D n,Vertex2D l){

    /* 三角形の面積 */
    double S, s;
    /* 三角形の辺 */
    double a, b, c;
    
    a=Distance_DotAndDot(m,n);
    b=Distance_DotAndDot(n,l);
    c=Distance_DotAndDot(l,m);
    /* 三角形の面積を計算・出力 */
    s = (a + b + c) / 2.0;
    S  = sqrt(s*(s-a)*(s-b)*(s-c));
    
    return S;

}

void CmpEachSide(double a[]){
    double t;
    for(int i = 0; i < N-1; i++)
    {
        double min=a[i];
        int s=i;
        for(int j = i+1; j < N; j++)
        {
            if (a[j]<min) {
                min=a[j];
                s=j;
            }
            

        }
        t=a[i];
        a[i]=min;
        a[s]=t;
    }
}