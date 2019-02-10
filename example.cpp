#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;      

#define SENTINEL 1000000000

class SortCollections{
    public:
        static void mergeSort(int A[],size_t s);
        static void mergeSort(int A[],int left,int right);
        static void merge(int A[],int left,int mid,int right);
};


void SortCollections::merge(int A[],int left,int mid,int right){
  int count=0;
  int n1,n2,i,j,k;
  int *L,*R;
  n1=mid-left;
  n2=right-mid;
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[mid+j];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
   if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
  free(L);
  free(R);
}

void SortCollections::mergeSort(int A[],int left,int right){
  int i,mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void SortCollections::mergeSort(int A[],size_t s){
    int mid, left, right;
    left=0;right=s;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}




int main(){
    int A[10]={80,40,35,12,88,1,56,33,50,23};
    size_t size=sizeof(A)/sizeof(A[0]);

    SortCollections::mergeSort(A,size);
    for(int i=0;i<10;i++) cout<<A[i]<<" ";


}