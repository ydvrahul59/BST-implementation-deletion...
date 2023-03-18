#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
//tree ko print krne ke liye traversal krni pdegi inorder, preorder,postorder ya levelorder
void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
               q.push(NULL);
            }
        

        }
        else{
            cout<<temp->data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}
void inorder(Node* root){//LRN
    //base case
    if(root == NULL){
        return ;
    }
    inorder(root ->left);
    cout<<root->data<<" ";
    inorder(root -> right);

}
void preorder(Node* root){//NLR
     //base case
     if(root == NULL){
        return ;
     }
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);


}
void postorder(Node* root){//LRN
    //base case
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
Node* insertIntoBST(Node*root,int d){

    //ab bst mein insert kaise karna hai
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;

    }
    if(d>root ->data){
        //right part mein insert karna hai
        root ->right = insertIntoBST(root->right,d);

    }else{
        //left part mein inssert karna hai
        root -> left = insertIntoBST(root->left,d);

    }
    return root;
}
Node* minvalue(Node* root){
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}
Node* maxvalue(Node* root){
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}
// BST mein deletion interview mwin bhut puchen jaten hain so, vvvviiiii

Node* deleteFromBST(Node* root, int val){
    //base case yhn 2 bse cse ho jynge
    if(root == NULL){
       return root; 
    }  
    if(root -> data == val){
        //toh iske andar pura delete ka logic likhna hai
        //case 1: 0 child wle node ko delte krna hai
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        //case 2 : 1 child ho toh iske two cse bnge ek left child wla node and el right child wla node
        //(a)left child wla node
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root->left; // pahle temp mein us node ko stor kr liya
            delete root;//jo bhi root hai delte kr diya /memory free kr diya
            return temp;
        }
        //(b)right child wla node
        if(root ->left == NULL && root ->right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        //case 3 : 2 child wla node ho toh iske 2 trike hain solve krne ke
        /*1st method left subtree mein se max value nikal kar laao & jo node delte krna hai use sth cop kr do
        fir max wle node ko delte kr do*/ 
        /* 2nd method right subtree mein se min value nikalkar*/
        if(root -> left != NULL && root -> right != NULL){
            int mini = minvalue(root -> right)->data; //ye min value ko save kr liya
            //ab ye jo value save kioyen hai isko copy krnge jo node ke 2 child haim ya jisko deltye krna hai
            root-> data =mini;
            // ab mini wle subtree prt ko delte kr diyen
            root -> right = deleteFromBST(root -> right,mini);
            return root;
        }
    }
    else if(root->data>val){
        //left part meion jaao
        root ->left = deleteFromBST(root -> left,val);
        return root;
    }
    else{
        // root-> data < val , toh right part mein jynge
        root ->right = deleteFromBST(root->right,val);
        return root;


    }
    

}
void takeinput(Node* &root){  // yhn par & ye important hai hi toh elmnt enter krne ke bbad kuch bhi show nhi hoga
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>> data;
    }
}

int main(){

    Node* root  = NULL;
    cout<<"enter data to create BST"<<endl;
    takeinput(root);
    
    cout<<"printing BST"<<endl;
    LevelOrderTraversal(root);

    cout<<"printing Inorder"<<endl;
    inorder(root);

    cout<<endl<<"printing preorder"<<endl;
    preorder(root);

    cout<<endl<<"printing postorder"<<endl;
    postorder(root);

    cout<<endl<<"min value of BST is "<<minvalue(root)->data<<endl;
    cout<<"max valur of BST is "<<maxvalue(root)->data<<endl; 

    // deleting function ya jisko delte krna hai
    root = deleteFromBST(root, 90);

    cout<<"printing BST"<<endl;
    LevelOrderTraversal(root);

    cout<<"printing Inorder"<<endl;
    inorder(root);

    cout<<endl<<"printing preorder"<<endl;
    preorder(root);

    cout<<endl<<"printing postorder"<<endl;
    postorder(root);

    cout<<endl<<"min value of BST is "<<minvalue(root)->data<<endl;
    cout<<"max valur of BST is "<<maxvalue(root)->data<<endl;

    return 0;

}
//  10 8 21 7 27 5 43 -1 lst mein de denge while loop ko end krne ke liye)
// 50 20 70 10 30 90 110 -1