#include <iostream>
using namespace std;

void print(int ar[], int size) {
    for(int i =0; i<size; i++)
        cout << ar[i] << " ";
    cout << endl;
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void selectionSort(int ar[], int size) {
    for(int i=0; i< size; i++) {
        for(int j = i+1; j<size; j++) {
            if(ar[j] < ar[i]) {
                swap(ar[j],ar[i]);
            }
        }
    }
    cout << "Elements after Selection sort are: ";
    print(ar,size);
}

void bubbleSort(int ar[], int size) {
    for(int i = 0; i<size; i++) {
        for(int j =0; j<size-1; j++) {
            if(ar[j] > ar[j+1]) {
                swap(ar[j], ar[j+1]);
            }
        }
    }
    cout << "Elements after Bubble sort are: ";
    print(ar,size);
}

void insertionSort(int ar[], int size) {
    int key,i,j;
    for(i =1; i < size; i++) {
        key = ar[i];
        j = i-1;
        ///////////// This //////////////
        for(j = i-1; (j>=0 && key<ar[j]); j--) {
                ar[j+1] = ar[j];
        }
        
        ////////////// Or This ///////////
        // while(j>=0 && key < ar[j]) {
        //     ar[j+1] = ar[j];
        //     j--;
        // }
        
        ar[j+1] = key;
    }
    cout << "Elements after Insertion sort are: ";
    print(ar,size);
}

int main() {
    int arr[] = {6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Elements before sorting are: ";
    print(arr,n);
    
    // selectionSort(arr,n);
    
    // bubbleSort(arr,n);
    
    insertionSort(arr,n);
    

    return 0;
}
