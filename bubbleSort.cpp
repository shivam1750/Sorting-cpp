/*

BUBBLE SORT!
Bubble sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
After every pass (transversing) the array is passed from next element, continued till 2nd last element in array.
Maximum number of passes = (n-1).

Time complexities:

   worst case: O(n²)
   average case: O(n logn)
   best case: O(n)   //alerady sorted

*/

#include <iostream>
using namespace std;                                       

void swap(int *a, int *b){
    //two elements are swapped using pointers as actual value has to be changed.
    int temp=*a;
    *a=*b;
    *b=temp;                                                      
}                                                             

void bubbleSort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){       //after every i'th element, array is transversed for next j elements. 
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    cout<<"\nThe Bubble Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    //creating an array.
    int n;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value of "<<i<<" element: ";
        cin>>arr[i];
    }
    //printing the array.
    cout<<"\nThe array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(arr,n);
    return 0;
}

/*
   Illustration:
   array -> {41,66,32,2}       1st pass 
            {(41,66),32,2}     (41 & 66 are compared and swapped if required)
            {41,(32,66),2}
            {41,32,(2,66)}

            {32,2,41,66}       2nd pass
            {2,32,41,66}       3rd pass   //sorted array

            total passes required = n-1  (here 4-1=3)

*/

/*
code written by Aditya Bijapurkar
*/