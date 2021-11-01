/*

SELECTION SORT!
In the same array, two sub-arrays (sorted and unsorted) are maintained. (initially sorted array is only of 1 element)
Find the element with minimum value and swap it with the 1st element of the unsorted array.
Increase the size of sorted array by 1 and decrease size of unsorted array by 1.
Continue till the entire array is sorted.

Time complexities: 
    worst case: O(n²)
    average case: O(n²)
    best case: O(n²)   


*/

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1; i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    
    //creating an array
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<" element of the array: ";
        cin>>arr[i];
    }
    cout<<"The given array is: ";
    printArray(arr, n);
    
    //calling selection-sort function
    cout<<"\nThe Selection Sorted array is: ";
    selectionSort(arr,n);
    printArray(arr,n);

    return 0;
}



/*
   Illustration:
   array -> {21,7,87,8,1}
            sorted array is of size 0, unsorted array is of n-sorted size.
            smallest element is searched  (number 1 index 4)
            it is swapped with index 0 and size of sorted array is increased by 1
            {1,7,87,8,21}
              |                 //1 and 21 swapped, sorted arr size = 1 
            {1,7,87,8,21} 
                |               //7 and 7 swapped, sorted arr size = 2
            {1,7,8,87,21}
                  |             //8 and 87 swapped, sorted arr size = 3
            {1,7,8,21,87}       
                     |          //21 and 87 swapped, sorted arr size = 4 
            {1,7,8,21,87}      
                        |       //87 and 87 swapped, completely sorted array
*/


/*
code written by Aditya Bijapurkar
*/
