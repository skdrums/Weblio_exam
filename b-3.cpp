#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define N 10

class SortCollections{
    public:
        static void bubbleSort(int[]);
        static void mergeSort(int[]);
        static void merge(int[]);
        static void quicksort(int[]);
        static void sort(int[]);
}


static void bubbleSort(int a[N]){

        int s;
        for(int i = 0; i < N-1; i++)
        {
        for(int j = N-1; j > i; j--)
            {
                if(a[j]<a[j-1]){
                    s=j;
                    a[j]=a[j-1];
                    a[j-1]=a[s];
                }
            }
        }

}

static void mergeSort(int a[N]){
    int i,mid,left,right;
    left=0;right=sizeof(a)/sizeof(a[0]);
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(a);
        mergeSort(a);
        merge(a);
    }

}

static void merge(int A[N]){
  int n1,n2,i,j,k,count,left,right,mid;
  int *L,*R;
  count=0;left=0;right=sizeof(a)/sizeof(a[0]);
  mid=(right+left)/2;
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


static void quicksort(int a[N])
{
    int left,right;
    left=0;right=sizeof(a)/sizeof(a[0]);
    if (left < right) {
        int i = left, j = right;
        value_type tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]); /* (i+j)/2ではオーバーフローしてしまう */
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[i] < pivot) i++; /* a[i] >= pivot となる位置を検索 */
            while (pivot < a[j]) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i],a[j] を交換 */
            i++; j--;
        }
        quicksort(a, left, i - 1);  /* 分割した左を再帰的にソート */
        quicksort(a, j + 1, right); /* 分割した右を再帰的にソート */
    }

}

static void sort(int a[N]){

}

int main(void){
    int a[]={80,40,35,12,88,1,56,33,50,23};

    SortCollections::quicksort(a);
    for(int i = 0; i < N; i++)
    {
        cout<<a[i]<<" ";
    }
    
}