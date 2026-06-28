#include <iostream>
#include <vector>

using namespace std; 

class TreeNode{
public: 
    int data; 
    TreeNode *left, *right; 

    // 생성자
    TreeNode(int v): data(v){
        left = right = nullptr;
    }
};

TreeNode* makeTree(int *list, int s){
    if(s == 0) return nullptr; 

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(list[0]);
    q.push(root);

    int i=1; 
    while(i < s){
        TreeNode *current = q.front();
        q.pop();

        if(i < s){
            if(list[i] == 0) {
                current->left = nullptr; 
                i++;
            } else {
                current->left = new TreeNode(list[i++]);
                q.push(current->left);   
            }
        }
        
        if(i < s){
            if(list[i] == 0) {
                current->right = nullptr; 
                i++;
            } else {
                current->right = new TreeNode(list[i++]);
                q.push(current->right);  
            }
        }
    }
    return root;
}


void clearTree(TreeNode *root){
    if(root == nullptr) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;    
}

void inorderPrint(TreeNode *root){
    if(root == nullptr) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}


int main(){
    int size; 
    cin >> size; 

    int *list = new int[size];
    for(int i=0; i<size; i++){
        cin >> list[i];
    }

    TreeNode *root = makeTree(list, size); 
    inorderPrint(root);
    cout << endl;

    clearTree(root);
    delete[] list;
    return 0;
}