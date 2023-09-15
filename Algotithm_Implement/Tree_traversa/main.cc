#include<bits/stdc++.h>

using namespace std;

typedef struct node *nodePointer;
typedef struct node{
    int data;
    nodePointer *left, *right;
} node;

vector<node> tree[10];

void preorder(nodePointer pointer) {
    
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        node trees;
        int a;
        cin >> a;
        trees.data = a;
        trees.left = NULL;
        trees.right = NULL;
        tree->push_back(trees); 
    }

    preorder(tree[0]);
}