/* 

INSERTION SORT!
The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct position in the sorted part.
1st element is considered first and kept in the sorted part, second element is compared with it and is kept accordingly in the sorted part.
This continues till all elements are placed correctly.

Time complexities:  
    worst case: O(n²)         //array is in desending order
    average case: O(n²)       
    best case: O(n)           //already sorted array           

*/

#include <iostream>
using namespace std;


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
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    //insertion-sorting
    for(int i=1;i<n;i++){                                  //[10,33,23,4,1]
        int current = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    //printing insertion-sorted array.
    cout<<"\nThe Insertion Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}



/*
   Illustration:
   array ->   {12, 4, 1, 10}
               ^   ^
              {4, 12, 1, 10}
                  ^   ^
              {4, 1, 12, 10}
               ^  ^
              {1, 4, 12, 10}
                     ^   ^
              {1, 4, 10, 12}      //completely sorted array
                                 // no need of further comparisons
*/


/*
code written by Aditya Bijapurkar
*/