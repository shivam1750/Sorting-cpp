/*

MERGE SORT!
Merge Sort is a Divide and Conquer algorithm.   (best for large sized arrays)
It divides the input array into two halves, calls itself for the two halves untill is broken down to single seperate element, and then merges the two sorted halves.
Individual sorted arrays are merged by applying pointers on 1st elemts and comparing, pointer of the smaller element is moved forward and compared with previous pointer of the other array.

Time complexities:   T(n) = 2T(n/2) + θ(n)

   worst case/average case/best case:  θ(n logn)  //merge sort always divides the array into two halves and takes linear time to merge two halves.   

**Merge sort is fastest algorithm for large sized arrays.
  Because merge sort accesses data sequentially and the need of random access is low (which is required in quick sort).

*/

#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n1=mid-low+1;          //number of elements in left subarray 
    int n2=high-mid;           //number of elements in right subarray

    int leftArray[n1], rightArray[n2];    //temperory sub-arrays

    //copying data from main-array to sub-arrays
    for(int i=0;i<n1;i++){
        leftArray[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        rightArray[i]=arr[mid+1+i];
    }

    int pointLeft=0, pointRight=0, pointMain=low;  //pointers for comparison
    
    //sorting elements and putting in main array
    while(pointLeft<n1 && pointRight<n2){
        if(leftArray[pointLeft] < rightArray[pointRight]){
            arr[pointMain] = leftArray[pointLeft];
            pointLeft++, pointMain++;
        }
        else{
            arr[pointMain] = rightArray[pointRight];
            pointRight++, pointMain++;
        }
    }

    //if number of elements are more in any one sub-array
    while(pointLeft<n1){
        arr[pointMain] = leftArray[pointLeft];
        pointLeft++, pointMain++;
    }
    while (pointRight<n2){
        arr[pointMain] = rightArray[pointRight];
        pointRight++, pointMain++;
    }
}

void mergeSort(int arr[], int low, int high){
    if(high>low){
        int mid = low+(high-low)/2;
        //makinig two arrays by taking mid value
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        //merging two seperated arrays by sorting
        merge(arr,low,mid,high); 
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

    //calling the merge-sort function
    int low=0, high=n-1;
    mergeSort(arr,low,high);

    cout<<"\nThe Merge Sorted array is: ";
    printArray(arr, n);

    return 0;
}

/*
   Illustration:
   array -> {10,77,4,3,21,40,61,32}
            {10,77,4,3} {21,40,61,32}
            {10,77} {4,3} {21,40} {61,32}
            {10} {77} {4} {3} {21} {40} {61} {32}      //broken down to single elements
            {10,77} {3,4} {21,40} {32,61}              //comparison is done and sorted
            {3,4,10,77} {21,32,40,61}
            {3,4,10,21,32,40,61,77}                    //sorted array

*/


/*
code written by Aditya Bijapurkar
*/