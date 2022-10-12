#include<bits/stdc++.h>
using namespace std;

//Structure of Tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}*root=NULL;


//Function to find right most node
TreeNode* rightmost(TreeNode* root){
    if (root->right==NULL) return root;
    return rightmost(root->right);
}

//Function to flatten the tree into linked list   
void flatten(TreeNode* root) {
    if (root==NULL) return;
    TreeNode* nextright;
    TreeNode* rightMOST;
        
    while (root){
        if (root->left){
            rightMOST = rightmost(root->left);
            nextright = root->right;
            root->right = root->left;
            root->left=NULL;
            rightMOST->right=nextright;
        }
        root=root->right;
    }
}


int main(){
    int n,item,i=0;  
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    while(i<n) 
    {  
        i++;
        printf("\nEnter the %d itme ",i);  
        scanf("%d",&item);  
        insert(item); 
    }
    flatten(root);
    return 0;
}


//function to insert new node in tree
void insert(int item)  
{  
    struct TreeNode *ptr, *parentptr , *nodeptr;  
    ptr = (struct TreeNode *) malloc(sizeof (struct TreeNode));  
    if(ptr == NULL) {  
        printf("can't insert");  
    }  
    else{  
    ptr -> val = item;  
    ptr -> left = NULL;  
    ptr -> right = NULL;   
    if(root == NULL){  
        root = ptr;  
        root -> left = NULL;  
        root -> right = NULL;  
    }  
    else{  
        parentptr = NULL;  
        nodeptr = root;   
        while(nodeptr != NULL) {  
            parentptr = nodeptr;   
            if(item < nodeptr->val){  
                nodeptr = nodeptr -> left;   
            }   
            else{  
                nodeptr = nodeptr -> right;  
            }  
        }  
        if(item < parentptr -> val){  
            parentptr -> left = ptr;   
        }  
        else{  
            parentptr -> right = ptr;   
        }  
    }  
    printf("Node Inserted");  
    }  
}  