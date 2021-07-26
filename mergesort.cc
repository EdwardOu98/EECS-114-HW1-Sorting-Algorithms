/**
 *  \file mergesort.cc
 *
 *  \brief Implement your mergesort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void
mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
  //Do merge sort only if the size of the array
  //is bigger than 1
  if(N != 1){
    int mid1, mid2, k;
    //Find the size of the first sub-array
    //which is half of the length of the 
    //original array
    mid1 = N/2;
    //Find the size of the second sub-array
    mid2 = N-mid1;

    keytype a[mid1];//the first sub-array
    keytype b[mid2];//the second sub-array
    
    //Copy the values of the first half of the
    //array into the first sub-array
    for(int i = 0; i < mid1; i++){
      a[i] = A[i];
    }

    //Copy the values of the second half of the array
    //in to the second sub-array
    k = 0;
    for(int j = mid1; j < N; j++){
      b[k] = A[j];
      k++;
    }
    //If the size of the first sub-array is not 1,
    //do merge sort for the first sub-array
    if(mid1 != 1){
      mySort(mid1, a);
    }
    //If the size of the second sub-array is not 1,
    //do merge sort for the second sub-array
    if(mid2 != 1){
      mySort(mid2, b);
    }

    k = 0;
    int l = 0;
    int p = 0;
    //Merge the two sorted sub-arrays
    while((k < mid1) && (l < mid2)){
      if(a[k] <= b[l]){
        A[p] = a[k];
        k++;
      }
      else{
        A[p] = b[l];
        l++;
      }
      p++;
    }

    //If there's any other elements left in the first
    //sub-array, put them at the end of the sorted array
    while(k < mid1){
      A[p] = a[k];
      p++;
      k++;
    }

    //If there's any other elements left in the second
    //sub-array, put them at the end of the sorted array
    while(l < mid2){
      A[p] = b[l];
      p++;
      l++;
    }

  }
}

/* eof */
