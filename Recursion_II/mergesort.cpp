#include <iostream>
using namespace std;

void merge(int a[], int start, int end){
    int mid = (start + end)/2;
    int size = (end - start) + 1;
    int *output = new int[size];
    int i = start, j = mid + 1, k = 0;

    while(i <= mid && j <= end){

        if(a[i] <= a[j]){
            output[k] = a[i];
            i++;
        }
        else {
            output[k] = a[j];
            j++;
        }
        k++;
    }
    
    while(i <= mid){
        output[k] = a[i];
        i++;
        k++;
    }

    while(j <= end){
        output[k] = a[j];
        j++;
        k++;
    }

    for(i = start; i <= end ; i++){
        a[i] = output[i];
    }
    
    delete [] output;
}

void mergeSort(int a[], int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start + end)/2;

    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);

    merge(a, start, end);
}