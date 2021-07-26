/**
 *  \file insertion-sort.cc
 *
 *  \brief Implement your insertion sort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void
mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
  int key, i;
  for(int j = 1; j < N; j++){
    key = A[j];
    i = j - 1;
    //The following while loop moves all elements greater
    //than the key one slot back
    while((i > 0) && (A[i] > key)){
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = key;
  }
}

/* eof */
