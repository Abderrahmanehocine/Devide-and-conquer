#include <stdio.h>
#include <stdlib.h>

void conquer(int* a, int s1 ,int e1 ,int s2 ,int e2){
  int* cp=(int*)malloc(e2*sizeof(int));
  int start=s1,k=0;
  while(s1<=e1 && s2<=e2)
    if(a[s1] < a[s2]) cp[k++]=a[s1++];
    else cp[k++]=a[s2++];
  while(s1<=e1) cp[k++]=a[s1++];
  while(s2<=e2) cp[k++]=a[s2++];
  for(int i=0 ; i<k ; i++,start++) a[start]=cp[i];
}

void devide(int* a, int start, int end){
  if(start == end) return;
  devide(a, start, (start+end)/2);
  devide(a, ((start+end)/2)+1, end);
  conquer(a,start, (start+end)/2, ((start+end)/2)+1, end);
}

int main() {
  int size;
  printf("Enter size of the array: ");
  scanf("%d",&size);
  int a[size];
  printf("\n");
  for(int i=0 ; i<size ; i++){
    printf("Enter number: ");
    scanf("%d",&a[i]);
  }
  devide(a,0,size-1);
  for(int i=0 ; i<size ; i++) printf("%d ",a[i]);
  printf("\n");
  return 0;
}
