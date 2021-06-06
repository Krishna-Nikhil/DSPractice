#include <iostream>
using namespace std;

int StackCount = 0;
int QueueCount = 0;
int queue_head = 0;

void arr_push(int (&ar)[10], int value) {
    if(StackCount == 10)
        cout << "Stack Over Flow" << endl;
    else
        ar[++StackCount] = value;
}

void arr_pop(int (&ar)[10]) {
    if(StackCount == 0) 
        cout << "Stack Under Flow" << endl;
    else
        ar[StackCount--] = -1;
}

void printStack(int (&ar)[10]) {
    for(int i =0; i<StackCount; i++)
        cout << ar[i] << " ";
    cout << endl;
}

void queue_push(int (&ar)[10], int value) {
    if(QueueCount == 10)
        cout << "Queue Over Flow" << endl;
    else 
        ar[QueueCount++] = value;
}

void queue_pop(int (&ar)[10]) {
    if(QueueCount == 0)
        cout << "Queue Under Flow" << endl;
    else {
        ar[queue_head++] = -1;
        QueueCount--;
    }
}

void printQueue(int (&ar)[10]) {
    for(int i =queue_head; i<10; i++)
        cout << ar[i] << " ";
    cout << endl;
}

int main() {
    int stack_ar[10] = {};
    int queue_ar[10] = {};

    for(int i=1; i<11; i++) {
        arr_push(stack_ar,2*i);
    }
    
    cout << "StackCount: " << StackCount << endl;
    printStack(stack_ar);
    
    for(int i = 0; i < 5; i++)
        arr_pop(stack_ar);
    
    cout << "StackCount: " << StackCount << endl;
    printStack(stack_ar);
    
    //////////////////////////////////////////////////////
    
    for(int i=0; i<10; i++) {
        queue_push(queue_ar,2*i);
    }
    
    cout << "QueueCount: " << QueueCount << " QueueHead: " << queue_head << endl;
    printQueue(queue_ar);
    
    for(int i = 0; i < 5; i++)
        queue_pop(queue_ar);
    
    cout << "QueueCount: " << QueueCount << " QueueHead: " << queue_head << endl;
    printQueue(queue_ar);
    
    return 0;
}
