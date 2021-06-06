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
    struct node *a_prev, *a_next,  *b_prev, *b_next, *temp, *head, *node_a, *node_b, *temp2;
    head = n;
    while(n != NULL && n->next != NULL) {
        if(n->next->key == a) {
            a_prev = n;
            node_a = n->next;
            a_next = node_a->next;
        }
        else if(n->next->key == b) {
            b_prev = n;
            node_b = n->next;
            b_next = node_b->next;
        }
        n = n->next;
    }

    temp = a_prev->next;
    a_prev->next = node_b;
    temp2 = node_b->next;
    node_b->next = temp;
    b_prev->next = temp2;
    n = head;
    return head;
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
    head = swapElements(head,2,3);
    printlist(head);
    head = insertElement(head,4,6);
    printlist(head);
    head = deleteElement(head,1);
    printlist(head);
    
    return 0;
}
