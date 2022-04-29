/*Hocine Abderrahmane: quick sort implemantation*/

#include <stdio.h>

int partition(int* a, int start, int end){
  int pivot=a[end];
  int partitionIndex=start;
  for(int i=start ; i<end ; i++)
    if(a[i] <= pivot){
     int swap=a[i];
     a[i]=a[partitionIndex];
     a[partitionIndex++]=swap;
    }
  int swap=a[partitionIndex];
  a[partitionIndex]=a[end];
  a[end]=swap;
  return partitionIndex;
}

void quickSort(int* a, int start, int end){
 if(start >= end) return;
  int partitionIndex=partition(a, start, end);
  quickSort(a, start, partitionIndex-1);
  quickSort(a, partitionIndex+1, end);
}

int main(){
  int size;
  printf("Enter size of the array: ");
  scanf("%d",&size);
  int a[size];
  printf("\n");
  for(int i=0 ; i<size ; i++){
    printf("Enter number: ");
    scanf("%d",&a[i]);
  }
  quickSort(a,0,size-1);
  for(int i=0 ; i<size ; i++) printf("%d ",a[i]);
  printf("\n");
  return 0;
}
