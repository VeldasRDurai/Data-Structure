#include <stdio.h>
#include <stdlib.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[p + i];
  for (int j = 0; j < n2; j++) M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) printf("%d  ", array[i]);
}

int* createArray(int size){
    int* data = (int *) malloc( size * sizeof(int) );
    for( int i =0; i<size; i++ ){
        printf("\nEnter the %dth element : ", i);
        scanf("%d", (data+i));
    }
    return data;
}

int main() {
    // int size;
    // printf("\nEnter the length of array to be created : ");
    // scanf("%d",&size);    
    // int *data = createArray(size);

    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);

    mergeSort(data, 0, size-1);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);
    
    // free(data);
    return 0;
}