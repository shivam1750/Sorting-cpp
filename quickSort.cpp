/* 

QUICK SORT!
QuickSort is a Divide and Conquer algorithm. (It is fastest sorting methord for relativly small arrays)
It picks an element as pivot and partitions the given array around the picked pivot.
Pivot element can be first/last/median/random. (here I have taken last element as pivot) 
After 1st step, Pivot element is in the correct place, with all elements lesser in the left side and all elements greater on the right side (even though they might not be sorted within themselves).
This is done in linear time. 

Time complexities:  (depends on pivot element)
   worst case: O(n²)
   average case: O(n logn)
   best case: O(n logn)   
   
*/

#include <iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int check = (low-1);

    for(int i=low; i<=high; i++){
        if(arr[i]<pivot){
            check++;
            swap(arr,check,i);
        }
    }
    swap(arr,check+1,high);
    return check+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int par=partition(arr,low,high);
        quickSort(arr,low,par-1);
        quickSort(arr,par+1,high);
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){int n;
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

    //calling the merge-sort function
    int low=0, high=n-1;
    quickSort(arr,low,high);

    cout<<"\nThe Quick Sorted array is: ";
    printArray(arr, n);

    return 0;
}



/*
   Illustration:
                              - (last pivot element)
   array -> {30, 10, 90, 80, 70}
             ^               ^          //30 and 70 are compared and 10 is placed accordingly to pivot
            //simillarly all elements are searched
            
            {30, 10}, 70, {90, 80}     //70 is placed at the correct place even if the elements before and after are not sorted
            
            //now 10 and 80 become pivot elements for the individual sub-arrays and it is continued till the main array is fully sorted.

*/





/*
code written by Aditya Bijapurkar
*/
