#include <iostream>
#include <bits/stdc++.h>

//fruits classes
#include "fruits.h"
using namespace std;

class BST{
private:
    Fruit* root=NULL;
public:
    BST(){
    }
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
        if (root->getWeight() > node->getWeight())
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
        cout<<endl;
    }

    //a method that prints the nodes that have weight larger than the given amount ordered by wright. For example, get an ordered list of all fruits in
    //the tree that are heavier than 500 grams.
    void filterByWeight(int Weight){
        inOrderTraversal(root,"",Weight);
        cout<<endl;
    }
//===================================================================================================================
    //a method that increases the weight of the nodes of a given fruit type by the given amount.
    // For example, add 200 grams to all bananas in the tree.
    Fruit* Delete(Fruit*root,string Type,vector<Fruit*>&modifiable){
        if(root==NULL)return NULL;
        root->setLeftChild(Delete(root->getLeftChild(),Type,modifiable));

        if(root->getType()==Type){
            modifiable.push_back(root);
            if(root->getLeftChild()==NULL && root->getRightChild()==NULL){
                return NULL;
            }
            else if(root->getLeftChild()==NULL){
                return root->getRightChild();
            }
            else if(root->getRightChild()==NULL){
                return root->getLeftChild();
            }
            Fruit* temp=getMin(root->getRightChild());
            temp->setLeftChild(root->getLeftChild());
            temp->setRightChild(root->getRightChild());
            return temp;
        }

        root->setRightChild(Delete(root->getRightChild(),Type,modifiable));
    }

     void addToType(Fruit*root,string Type,vector<Fruit*>&modifiable , int Weight){
        if(root==NULL)return ;
        addToType(root->getLeftChild(),Type,modifiable,Weight);

        if(root->getType()==Type){
            root->setWeight(root->getWeight()+Weight);
        }
        modifiable.push_back(root);
        addToType(root->getRightChild(),Type,modifiable,Weight);
    }

    void magnifyByType(string Type,int Weight){
        vector<Fruit*>modifiable;
        addToType(root,Type,modifiable,Weight);
        root=NULL;
        int n=modifiable.size();
        for(int i=0;i<n;++i){
            modifiable[i]->setLeftChild(NULL);
            modifiable[i]->setRightChild(NULL);
            insert(modifiable[i]);
        }

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
    Fruit* findLightest(){
        return getMin(root);
    }
};

int main()
{
    grapes* a=new grapes();
    mango* b=new mango();
    apple* c=new apple();
    avocado* d=new avocado();
    raspberry* e=new raspberry();
    blueberry* f=new blueberry();
    blackberry* g=new blackberry();
    kiwi* h=new kiwi();

    banana* i=new banana();
    banana* i1=new banana();
    banana* i2=new banana();
    banana* i3=new banana();

    watermelon* j=new watermelon();
    pineapple* k=new pineapple();

    a->setWeight(50);
    b->setWeight(20);
    c->setWeight(15);
    d->setWeight(30);
    e->setWeight(4);
    f->setWeight(8);
    g->setWeight(154);
    h->setWeight(68);

    i->setWeight(11);
    i1->setWeight(3);
    i2->setWeight(7);
    i3->setWeight(13);

    j->setWeight(200);
    k->setWeight(1000);

    BST fruitTree;
    fruitTree.insert(a);
    fruitTree.insert(b);
    fruitTree.insert(c);
    fruitTree.insert(d);
    fruitTree.insert(e);
    fruitTree.insert(f);
    fruitTree.insert(g);
    fruitTree.insert(h);
    fruitTree.insert(i);
    fruitTree.insert(i1);
    fruitTree.insert(i2);
    fruitTree.insert(i3);
    fruitTree.insert(j);
    fruitTree.insert(k);

    cout<<"Iterate : \n";
    fruitTree.Iterate();

    cout<<"filterByType(banana) : \n";
    fruitTree.filterByType("banana");

    cout<<"filterByWeight(50) : \n";
    fruitTree.filterByWeight(50);

    cout<<"magnifyByType(banana, 1000) : \n";
    fruitTree.magnifyByType("banana", 1000);

    cout<<"Iterate : \n";
    fruitTree.Iterate();

    cout<<"findHeaviest() : \n";
    cout<<fruitTree.findHeaviest()->getWeight()<<endl;

    cout<<"findLightest() : \n";
    cout<<fruitTree.findLightest()->getWeight()<<endl;


    return 0;
}
