#include <bits/stdc++.h>

using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    int find(int value) {
        return __search(_root, value, 1);
    }

    void insert(int value) {
        if (find(value) == -1) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value) != -1) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }
    
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    int __search(BSTNode *root, int value, int depth) {
        if (root == NULL) return -1;
        
        if (root->key == value) return depth;
        
        if (value < root->key)
            return __search(root->left, value, depth + 1);
        else
            return __search(root->right, value, depth + 1);
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    int n;cin >> n;
    while(n--){
     string cmd;cin >> cmd;
     if(cmd == "INSERT"){
       int val;cin >> val;
       set.insert(val);
     } else if(cmd == "DELETE"){
       int val;cin >> val;
       set.remove(val);
     } else if(cmd == "PRINT"){
        if(set.isEmpty()) {
            cout << "EMPTY" << endl;
        } else {
            set.traverseInorder();
            cout << endl;
        }
     } else if(cmd == "SEARCH"){
       int val;cin >> val;
       int depth = set.find(val);
       cout << depth << endl;
     }
    }
    return 0;
}