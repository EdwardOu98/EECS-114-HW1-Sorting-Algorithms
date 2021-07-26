/**
 *  \file insertion-sort-bisearch.cc
 *
 *  \brief Implement your insertion sort with binary search in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

int BinarySearch (keytype* A, int key, int low, int high){
  int mid = (low+high)/2;
  //If the upper bound is smaller than the lower bound,
  //return the upper bound or (upper bound+1) as the index we need
  //depending on whether the element at upper bound is greater than
  //the key value
  if(high <= low){
    return (A[low] < key) ? (low+1) : low;
  }
  //If the element at position mid is equal to the key value,
  //return the mid value as the index we need
  if(A[mid] == key){
    return mid;
  }
  //If the element at position mid is smaller than the key value,
  //look for the target index in the second half of the array. 
  //If the element at position mid is greater than the key value,
  //look for the target index in the first half of the array
  if(A[mid] < key){
    return BinarySearch(A, key, mid+1, high);
  }
  else{
    return BinarySearch(A, key, low, mid-1);
  }
}

void
mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
  int ind, key, i;
  for(int j = 1; j < N; j++){
    key = A[j];
    i = j - 1;
    //Instead of looking through the whole array,
    //use binary search to look for the target index
    //where we would insert the key value
    ind = BinarySearch(A, key, 0, j);
    //This while loop moves everything after the target
    //index one slot back
    while(i >= ind){
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = key;
  }
}

/* eof */
