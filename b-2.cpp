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

struct zahyo{
    double x;
    double y;
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
double Distance_DotAndDot(zahyo,zahyo);

int main(void){

    struct min_line{
        double min;
        zahyo start;
        zahyo end;
    } min_line[10];

    zahyo z[M];
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

    min_line[0].min=Distance_DotAndDot(z[0],z[1]);
    min_line[0].start=z[0];
    min_line[0].end=z[1];
    
    int line_number=1;
    for(int i=0;i<M-1;i++){
        for(int j=i+1;j<M;j++){
            if(min_line[0].min>Distance_DotAndDot(z[i],z[j])){
                min_line[0].min=Distance_DotAndDot(z[0],z[1]);
                min_line[0].start=z[i];
                min_line[0].end=z[j];

            }
            else if(min_line[0].min==Distance_DotAndDot(z[i],z[j])){
                min_line[line_number].min=Distance_DotAndDot(z[0],z[1]);
                min_line[line_number].start=z[i];
                min_line[line_number++].end=z[j];
            }
        }
    }


    for(int i=0;i<line_number;i++){
        cout<<min_line[i].min<<" "<<min_line[i].start.x<<" "<<min_line[i].end.x<<endl;
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

double Distance_DotAndDot(zahyo a,zahyo b){
    double m,n;
    m=pow(a.x-b.x,2);
    n=pow(a.y-b.y,2);
    return sqrt(m+n);
}