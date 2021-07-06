#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int i) {
        data = i;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node* root) {
    if(root == NULL)
        return;
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(Node* root) {
    if(root == NULL)
        return;
        
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node* root) {
    if(root == NULL)
        return;
        
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printLevelorder(Node* root) {
    if(root == NULL)
        return;
    
    std::queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        
        if(temp->left)
            q.push(temp->left);
            
        if(temp->right)
            q.push(temp->right);
    }
}

int main() {
    
/*    
              1 

         2         3 

     4       5  6     7
*/

    struct Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->left = new Node(6);
    node->right->right = new Node(7);
    
    cout << "Inorder: "; 
    printInorder(node);
    cout << endl;
    
    cout << "Preorder: "; 
    printPreorder(node);
    cout << endl;

    cout << "Postorder: "; 
    printPostorder(node);
    cout << endl;
    
    cout << "Levelorder: ";
    printLevelorder(node);
    cout << endl;

    return 0;
}
