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
}

void bubbleSort(int ar[], int size) {
    for(int i = 0; i<size; i++) {
        for(int j =0; j<size-1; j++) {
            if(ar[j] > ar[j+1]) {
                swap(ar[j], ar[j+1]);
            }
        }
    }
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
}

void merge(int ar[], int low, int med, int high) {
    int lc = med-low+1; int rc = high-med;
    int left[lc]; int right[rc];
    
    for(int i = 0; i<lc; i++) {
        left[i] = ar[i+low];
    }
    for(int j=0; j<rc; j++) {
        right[j] = ar[j+med+1];
    }
    
    int i = 0;
    int j = 0;
    int k = low;

    for(k=low; (i<lc && j<rc); k++) {
        if(left[i] < right[j]) {
            ar[k] = left[i];
            i++;
        }
        else {
            ar[k] = right[j];
            j++;
        }
    }
    
    while(j<rc) {
            ar[k] = right[j];
            j++; k++;
    }
    
    while(i<lc) {
        ar[k] = left[i];
        i++; k++;
    }
}

void mergeSort(int ar[], int low, int high) {
    if(low>=high)
    return;
    
    int med = (low+high)/2;
    
    mergeSort(ar,low,med);
    mergeSort(ar,med+1,high);
    merge(ar,low,med,high);
}

int Partition(int ar[], int low, int high) {
    int pivot = ar[low];
    int i = low; int j = high;
    while (i<j) {
        do {
            i++;
        }while(ar[i] <= pivot);
        
        do {
            j--;
        }while(ar[j] > pivot);
        
        if(i<j)
            swap(ar[i],ar[j]); 
    }
    swap(ar[low],ar[j]);
    return j;
}

void quickSort(int ar[], int low, int high) {
    if(low < high) {
        int pi = Partition(ar,low,high);
        quickSort(ar,low,pi);
        quickSort(ar,pi+1,high);
    }
}

void heapify(int ar[], int n, int head) {
    // n is number of elements, head is the 1st elements
    int node = head;
    int left = 2*head + 1;
    int right = 2*head + 2;
    int largest = head;
    
    if((left < n) && (ar[left] > ar[largest])) {
        largest = left;
    }
    if((right < n) && (ar[right] > ar[largest])) {
        largest = right;
    }
    
    if(largest != head) {
        swap(ar[head], ar[largest]);
        heapify(ar,n,largest);
    }
}

void heapSort(int ar[], int n) {
    //Heapifying the 1st childs of the root node.
    for(int i = n/2 -1; i >=0; i--) {
        heapify(ar,n,i);
    }
    
    //Remove the last node and re-heapify
    for(int i = n-1; i>0; i--) {
        swap(ar[i], ar[0]);
        heapify(ar,i,0);
    }
}

int main() {
    int n;
    cout << "Enter No. of Elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    cout << "Elements before sorting are: ";
    print(arr,n);
    
    cout << endl << "Select the Sorting Technique you want to use:" << endl;
    cout << "1.Selection Sort" << endl;
    cout << "2.Bubble Sort" << endl;
    cout << "3.Insertion Sort" << endl;
    cout << "4.Merge Sort" << endl;
    cout << "5.Quick Sort" << endl;
    cout << "6.Heap Sort" << endl << endl;
    
    int input; cin >> input; cout <<endl;
    
    switch(input) {
        case 1:
            selectionSort(arr,n);
            cout << "Elements after Selection sort are: ";
            break;
        case 2:
            bubbleSort(arr,n);
            cout << "Elements after Bubble sort are: ";
            break;
        case 3:
            insertionSort(arr,n);
            cout << "Elements after Insertion sort are: ";
            break;
        case 4:
            mergeSort(arr,0,n-1);
            cout << "Elements after Merge sort are: ";
            break;
        case 5:
            quickSort(arr,0,n);
            cout << "Elements after Quick sort are: ";
            break;
        case 6:
            heapSort(arr,n);
            cout << "Elements after Heap sort are: ";
            break;
        default:
            cout << "Incorrect Input";
            return 0;
    }
    
    print(arr,n);
    return 0;
}
