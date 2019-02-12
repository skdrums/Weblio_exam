#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;      
#define N 10
#define SENTINEL 1000000000

class SortCollections{
    public:
        static void mergeSort(int A[]);
        static void mergeSort(int A[],int left,int right);
        static void merge(int A[],int left,int mid,int right);
        static void bubbleSort(int a[]);
        static void quickSort(int a[]);
        static void quickSort(int a[],int left,int right);
        static void sort(int a[]);

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

void SortCollections::mergeSort(int A[]){
    int mid, left, right;
    left=0;right=N;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

void SortCollections::bubbleSort(int a[]){

  int s;
  for(int i = 0; i < N-1; i++){
    for(int j = N-1; j > i; j--){
      if(a[j]<a[j-1]){
        s=a[j];
        a[j]=a[j-1];
        a[j-1]=s;
      }
    }
  }

}

void SortCollections::quickSort(int a[])
{
    int left,right,s,tmp;
    left=0;right=N-1;
    if (left < right) {
      s=a[(left+right)/2];
        int i = left-1, j = right+1;
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[++i]<s); /* a[i] >= pivot となる位置を検索 */
            while (s < a[--j]) ; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i],a[j] を交換 */
            i++; j--;
        }
        quickSort(a, left, i - 1);  /* 分割した左を再帰的にソート */
        quickSort(a, j + 1, right); /* 分割した右を再帰的にソート */
    }

}

void SortCollections::quickSort(int a[],int left,int right)
{
    int tmp,s,i,j;
    if (left < right) {
        s=a[(left+right)/2];
        i = left-1, j = right+1;
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[++i] < s); /* a[i] >= pivot となる位置を検索 */
            while (s < a[--j]); /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i],a[j] を交換 */
        }
        quickSort(a, left, i - 1);  /* 分割した左を再帰的にソート */
        quickSort(a, j + 1, right); /* 分割した右を再帰的にソート */
    }

}

void SortCollections::sort(int a[]){

}


int main(){
    int A[10]={80,40,35,12,88,1,56,33,50,23};
    SortCollections::quickSort(A);
    for(int i=0;i<10;i++) cout<<A[i]<<" ";


}