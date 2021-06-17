#include <iostream>
#include <bits/stdc++.h>

#include "fruits.h"
using namespace std;

class BST{
private:
    Fruit* root=NULL;
public:
    // insert a new fruit in the tree
    void insert(Fruit* node){
        if(root==NULL)
            root=node;
        else
            BSTinsert(root,node);
    }
    Fruit* BSTinsert(Fruit* root,Fruit* node){
        if(root == NULL){
            return node;
        }
        if (root->getWeight() < node->getWeight())
            root->setLeftChild(BSTinsert(root->getLeftChild(), node));
        else
            root->setRightChild(BSTinsert(root->getRightChild(), node));
        return root;
    }
    //helper function
    void inOrderTraversal (Fruit* root ,string type,int weight){
        if(root==NULL)return;
        inOrderTraversal(root->getLeftChild(),type,weight);
        if((type=="" || root->getType()==type)&&(weight==-1 || root->getWeight()>weight))
            cout<<root->getWeight()<<" ";
        inOrderTraversal(root->getRightChild(),type,weight);
    }
    //a method that prints the in-order traversal of the tree.
    void Iterate(){
        inOrderTraversal(root,"",-1);
        cout<<endl;
    }

    //a method that prints the nodes of a given fruit type ordered by weight. For example, get an ordered list of all apples in the tree
    void filterByType(string Type){
        inOrderTraversal(root,Type,-1);
    }

    //a method that prints the nodes that have weight larger than the given amount ordered by wright. For example, get an ordered list of all fruits in
    //the tree that are heavier than 500 grams.
    void filterByWeight(int Weight){
        inOrderTraversal(root,"",Weight);
    }
//===================================================================================================================
    //a method that increases the weight of the nodes of a given fruit type by the given amount.
    // For example, add 200 grams to all bananas in the tree.
    void addToType(Fruit* node ,string Type ,int Weight){
        addToType(node->getLeftChild(),Type,Weight);
        if(node->getType()==Type){
            node->setWeight(node->getWeight() + Weight);
        }
        addToType(node->getRightChild(),Type,Weight);
    }
    void magnifyByType(string Type,int Weight){
        addToType(root,Type,Weight);
    }
//===================================================================================================================
    //a method that finds the node with the greatest weight in the tree.
    Fruit* getMax(Fruit* root){
        if(root == NULL)
            return NULL;
        else if(root->getRightChild()== NULL)
            return root;
        else
            return getMax(root->getRightChild());
    }
    Fruit* findHeaviest(){
        return getMax(root);
    }

    //a method that finds the node with the least weight in the tree.
    Fruit* getMin(Fruit* root){
        if(root == NULL)
            return NULL;
        else if(root->getLeftChild()== NULL)
            return root;
        else
            return getMin(root->getLeftChild());
    }
    Fruit* findLightest(Fruit* root){
        return getMin(root);
    }
};
void dfs(Fruit* root){
    if(root==NULL)return;

    dfs(root->getLeftChild());
        cout<<root->getWeight()<<" ";
    dfs(root->getRightChild());
}
int main()
{
    Banana a,b;
    Mango m ,n;

    b.setWeight(2);
    a.setWeight(12);
    m.setWeight(20);
    n.setWeight(100);

    a.setRightChild(&b);
    a.setLeftChild(&m);
    m.setLeftChild(&n);

    dfs(&a);

    return 0;
}
