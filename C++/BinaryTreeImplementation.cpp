#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* root;

class Btree{


public:
    Btree()
    {
      root=NULL;
    }

    void insertNode(int data,node *leaf)
    {
        if(root==NULL)
        {
                root = new node;
                root->data=data;
                root->left=NULL;
                root->right=NULL;

        }

        else if(data < leaf->data)
        {
            if(leaf->left!=NULL)
                insertNode(data,leaf->left);
            else
            {
                node* temp=new node;
                temp->data=data;
                temp->left=NULL;
                temp->right=NULL;
                leaf->left=temp;
            }

        }

       else if(data >= leaf->data)
        {
            if(leaf->right!=NULL)
                insertNode(data,leaf->right);
            else
            {
                node* temp=new node;
                temp->data=data;
                temp->left=NULL;
                temp->right=NULL;
                leaf->right=temp;
            }

        }

    }

    void preorder(node* leaf)
    {
        if(root==NULL)
        {
            cout<<"Empty tree\n";
        }
        else if(leaf!=NULL){
        cout<<leaf->data<<" ";
        preorder(leaf->left);
        preorder(leaf->right);
    }
    }

    void postorder(node *leaf)
    {
        if(root==NULL)
        {
            cout<<"Empty tree\n";
        }
        else if(leaf!=NULL){
            postorder(leaf->left);
            postorder(leaf->right);
            cout<<leaf->data<<" ";
        }

    }


    void inorder(node *leaf)
    {
        if(root==NULL)
        {
            cout<<"Empty tree\n";
        }
        else if(leaf!=NULL){
            inorder(leaf->left);
            cout<<leaf->data<<" ";
            inorder(leaf->right);

        }
    }

    node* searchData(node *leaf,int ser)
    {
        if(leaf!=NULL)
        {
            if(leaf->data==ser)
            {
                cout<<"found\n";
                return leaf;
            }
            else
            {
                if(ser<leaf->data)
                {
                    searchData(leaf->left,ser);
                }
                else
                    searchData(leaf->right,ser);
            }
        }
        else
            cout<<"Not Found\n";
    }
};

int main()
{
    Btree t;
    while(1)
    {
        int ch;
        cout<<"1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search Element\n6. Exit\n";
        cin>>ch;
            switch(ch)
            {
            case 1:
                {
                    int data;
                    cout<<"Enter data: ";
                    cin>>data;
                    t.insertNode(data,root);
                    break;
                }
            case 2:
                {
                    t.preorder(root);
                    cout<<"\n";
                    break;
                }
            case 3:
                {
                    t.postorder(root);
                    cout<<"\n";
                    break;
                }
            case 4:
                {
                    t.inorder(root);
                    cout<<"\n";
                    break;
                }
            case 5:
                {
                    cout<<"Enter search value: ";
                    int ser;
                    cin>>ser;
                    t.searchData(root,ser);
                    break;
                }

            case 6:
                {
                    exit(0);
                    break;
                }

            }
    }

    return 0;

}
