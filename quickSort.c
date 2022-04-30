/*Hocine Abderrahmane: quick sort implemantation*/
// if you want to run the code read the README.md file

#include <stdio.h>

// swap function between two elements in the array
void swap(int* a, int num1, int num2){
  int swap=a[num1];
  a[num1]=a[num2];
  a[num2]=swap;
}

/* partition function put the pivot in the right place in sorted sorted array and put smaller elements then the pivot befor the pivot and greater 
elements then the pivot after the pivot*/
int partition(int* a, int start, int end){
  int pivot=a[end];
  int partitionIndex=start;
  for(int i=start ; i<end ; i++) 
    if(a[i] <= pivot) swap(a, i, partitionIndex++);
  swap(a, partitionIndex, end);
  return partitionIndex;
}

//quickSort function divide the array into sub elements by store the index of the start of the sub-array of a and the end index
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
