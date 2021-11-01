/*

SHELL SORT!      (a variation of insertion Sort)
The idea of shellSort is to allow exchange of far items. 
In shellSort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. 
Gap of n/2 is created and every element after gap number of elements are compared with each other and swapped if necessary. (gap is divided by 2 after each pass)

Time complexities:      //efficiency is dependant upon the gap taken 
    worst case: O(n logn)
    average case: O(n*log(n)^2) or O(n^(3/2))
    best case: O(n)   

*/

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;                             
    *b=temp;
}


int shellSort(int arr[], int n){
    for(int gap=n/2; gap>=1; gap=gap/2){
        for(int i=gap;i<n;i++){                           
            for(int j=i-gap; j>=0; j=j-gap){
                if(arr[j+gap]<arr[j]){
                    swap(&arr[j+gap], &arr[j]);
                }
                else{
                    break;
                }
            }
        }
    }
    return 0;
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    //making an array
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<" element of the array: ";
        cin>>arr[i];
    }
    cout<<"The given array is: ";
    printArray(arr,n);

    //calling the shell-sort function
    shellSort(arr,n);

    cout<<"\nThe Shell Sorted array is: ";
    printArray(arr, n);

    return 0;
}



/*
   Illustration:
   array -> {9,8,7,6,5,4,3,2,1,0}
            n=10, so gap= 10/2 = 5
            now element i will be gap i.e. 5 i.e 4th index
            so j will be i-gap i.e. 0th index
            {9,8,7,6,5,4,3,2,1,0}
             ^       ^             //swapping will be done
            {5,8,7,6,9,4,3,2,1,0}
               ^       ^           //now these will be compared

            after the whole loop is finished gap will be gap/2 i.e. 5/2 = 2  (base number)
            this process continues till gap value is 1.
*/


/*
code written by Aditya Bijapurkar
*/