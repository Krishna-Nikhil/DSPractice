#include <stdio.h>
#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* next;
};

void printlist(node* n) {
    while(n!=NULL) {
        cout << n->key << " ";
        n = n->next;
    } cout << endl;
}

node* insertElement(node* n, int value, int position) {
    struct node* newnode = new node;
    struct node* temp = new node;
    struct node* head = n;
    int count = 1;
    if(position == 1) {
        newnode->key = value;
        newnode->next = n;
        n = newnode;
    } else {
        while(count < position-1) {
            n = n->next;
            count++;
        }
        temp = n->next;
        n->next = newnode;
        newnode->key = value;
        newnode->next = temp;
        n = head;
    }
    return n;
}

node* deleteElement(node* n, int value) {
    struct node* del_node = new node;
    while(n != NULL) {
        if(n->next->key == value) {
            del_node = n->next;
            n->next = n->next->next;
            delete del_node;
            break;
        }
        else if(n->key == value) {
            del_node = n;
            n = n->next;
            delete del_node;
            break;
        }
        n = n->next;
    }
    return n;
}

node* swapElements(node* n, int a, int b) {
    struct node *a_prev=NULL, *b_prev=NULL, *temp, *node_a=n, *node_b=n;
    if(a==b) // if same values
        return n;

    while(node_a != NULL && node_a->key != a) { //find node a
            a_prev = node_a;
            node_a = node_a->next;
    }
    while(node_b != NULL && node_b->key != b) { //find node b
            b_prev = node_b;
            node_b = node_b->next;
    }
    
    if(node_b == NULL || node_a == NULL) // If elements dont exist
        return n;
    
    if(a_prev != NULL) // If node_a is not 1st element.
        a_prev->next = node_b;
    else
        n = node_b;
    
    if(b_prev != NULL) // If node b is not 1st element.
        b_prev->next = node_a;
    else
        n = node_a;
    
    temp = node_b->next;
    node_b->next = node_a->next;
    node_a->next = temp;

    return n;
}

int main()
{
    struct node* head = new node;
    struct node* temp = new node;
    head->key = 1;
    head->next = NULL;
    temp = head;
    for(int i=2; i<6; i++) {
        struct node* newnode = new node;
        head->next = newnode;
        newnode->key = i;
        head = newnode;
    }
    head->next = NULL;
    head = temp;
    
    printlist(head);
    head = swapElements(head,1,2);
    printlist(head);
    head = insertElement(head,4,6);
    printlist(head);
    head = deleteElement(head,1);
    printlist(head);
    
    return 0;
}
