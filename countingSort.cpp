/* 

COUNTING SORT!
Counting sort is a sorting technique based on keys between a specific range. 
It works by counting the number of objects having distinct key values (kind of hashing). 
Then doing some arithmetic to calculate the position of each object in the output sequence.

Time complexities:  
    worst case: O()  
    average case: O()       
    best case: O()

*/

#include <iostream>
using namespace std;

    
void countSort(int arr[], int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int count[max+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];       
    }
    int out[n+1];
    for(int i=n-1;i>=0;i--){
        out[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
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

    //calling the count-sort function
    
    countSort(arr,n);

    cout<<"\nThe Count Sorted array is: ";
    printArray(arr, n);

    return 0;
}



/*
   Illustration:

   given array: [9,3,2,1,5,1]
                max=9

                creating count array of 9+1 elements:
                count = [0,0,0,0,0,0,0,0,0]
            
    incrementing value of count array by travesing through given array:
                count= [0,2,1,1,0,5,0,0,0,1]
    adding count elements to the previous elements:
                count= [0,2,3,4,4,9,9,9,9,10]

    creating an output array of n+1 elements:
    taking last element from given array and comparing its position from count array and placing it at that (location-1) in output array:
                out=[1,1,2,3,5,5]
    copying elements from out array in given array:
                given=[1,1,2,3,5,5]

*/

/*
code written by Aditya Bijapurkar
*/
