#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Fruit{
public:
    virtual int getWeight()=0;
    virtual void setWeight(int)=0;
    virtual string getType()=0;
    virtual Fruit* getLeftChild()=0;
    virtual Fruit* getRightChild()=0;
    virtual void setLeftChild(Fruit*)=0;
    virtual void setRightChild(Fruit*)=0;

};
class subFruit : public Fruit{
private:
    int weight;
    string type;
    Fruit *left=NULL,*right=NULL;
public:
    subFruit():weight(0),left(NULL),right(NULL){};
    subFruit(int val):weight(val),left(NULL),right(NULL){};
    subFruit(int val,string Type ,Fruit* left,Fruit* right):weight(val),type(Type),left(left),right(right){};
    virtual int getWeight(){
        return weight;
    }
    virtual void setWeight(int val){
        weight=val;
    }
    virtual string getType(){
        return type;
    }

    virtual Fruit* getLeftChild(){
        return this->left;
    }
    virtual Fruit* getRightChild(){
        return this->right;
    }
    virtual void setRightChild(Fruit* right){
        this->right=right;
    }
    virtual void setLeftChild(Fruit* left){
        this->left=left;
    }
};
class Mango : public subFruit{
private:
    string color;
public:
    virtual string getType(){
        return "Mango";
    }

};
class Banana : public subFruit{
private:
    string color;
public:
    virtual string getType(){
        return "Banana";
    }

};
