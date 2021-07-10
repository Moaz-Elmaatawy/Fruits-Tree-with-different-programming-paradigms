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
    string color="NULL";

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
//======================================================================================================
class tinyFruit : public virtual subFruit{
public:
    int price;
};

class ovalShape : public virtual subFruit{
public:
    bool peelable;
};

class withSeedsInside : public virtual subFruit{
public:
    string seedSize;
};

class bigFruit : public virtual subFruit{
public:
    string eatSeason;
};

//======================================================================================================
class banana : public subFruit{
public:
    banana(){
        this->color=("Yellow");
    }
    string getType(){
        return "banana";
    }
};

class berry: public tinyFruit{
public:
    string origin;
};

class grapes : public tinyFruit{
public:
    grapes(){
        this->color="Red";
        this->price=15;
    }
    string getType(){
        return "grapes";
    }
};

class raspberry : public berry{
public:
    raspberry(){
        this->color="Red";
        this->price=150;
        this->origin="Europe";
    }
    string getType(){
        return "raspberry";
    }
};

class blueberry : public berry{
public:
    blueberry(){
        this->color="Blue";
        this->price=60;
        this->origin="North America";
    }
    string getType(){
        return "blueberry";
    }
};

class blackberry : public berry{
public:
    blackberry(){
        this->color="Black";
        this->price=70;
        this->origin="Europe";
    }
    string getType(){
        return "blackberry";
    }
};

class orange : public ovalShape{
public:
    orange(){
        this->color="Orange";
        this->peelable=true;
    }
    string getType(){
        return "orange";
    }
};

class kiwi : public ovalShape , public withSeedsInside{
public:
    kiwi(){
        this->color="Golden Brown";
        this->peelable=true;
        this->seedSize="small";
    }

    string getType(){
        return "kiwi";
    }
};

class mango : public ovalShape , public withSeedsInside{
public:
    mango(){
        this->color="Orange-Yellow";
        this->peelable=true;
        this->seedSize="big";
    }

    string getType(){
        return "mango";
    }
};


class apple : public ovalShape , public withSeedsInside{
public:
    apple(){
        this->color="Red";
        this->peelable=false;
        this->seedSize="small";
    }

    string getType(){
        return "apple";
    }
};

class avocado : public ovalShape , public withSeedsInside{
public:
    avocado(){
        this->color="Green";
        this->peelable=true;
        this->seedSize="medium";
    }
    string getType(){
        return "avocado";
    }
};

class watermelon : public bigFruit ,public ovalShape, public withSeedsInside{
public:
    watermelon(){
        this->color="Green-red";
        this->peelable=true;
        this->seedSize="small";
        this->eatSeason="summer";
    }
    string getType(){
        return "watermelon";
    }
};

class pineapple : public bigFruit ,public ovalShape{
public:
    pineapple(){
        this->color="Green-gray";
        this->peelable=true;
        this->eatSeason="summer";
    }
    string getType(){
        return "pineapple";
    }
};

