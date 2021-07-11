//level 0 the fruit class
function Fruit (Weight) {
    this.weight = Weight || 0;
    this.left = null ;
    this.right = null ;
}
Fruit.prototype =  {
    
    getWeight(){return this.weight;} , 
    setWeight(Weight){this.weight = Weight;},

    getLeft(){return this.left;},
    setLeft(Left){this.left = Left;},

    getRight(){return this.right;},
    setRight(Right){this.right = Right;},

    getType(){return "still undefined" ;},
    getCategory(){return "just fruit" ;}
}

//level 1 calsses
function tinyFruit(Weight,Price) {
    Fruit.call(this,Weight);
    this.price = Price || 0 ;
}
tinyFruit.prototype = {
    //extend from fruit
    __proto__ : Fruit.prototype,

    getPrice(){return this.price;},
    setPrice(Price){this.price = Price;},

    getCategory(){return "Tiny Fruit" ;}
} 


function ovalShape (Weight,peelable) {
    Fruit.call(this,Weight);
    this.peelable = peelable || true ;
}
ovalShape.prototype = {
    //extend from fruit
    __proto__ : Fruit.prototype,

    isPeelable(){return this.peelable;},
    setPeelable(Peelable){this.peelable = Peelable;},

    getCategory(){
        return "OvalShape Fruit" ;
    }
}


function withSeedInside(Weight,seedSize){
    Fruit.call(this,Weight);
    this.seedSize = seedSize || null;
}
withSeedInside.prototype = {
    //extend from fruit
    __proto__ : Fruit.prototype,

    getSeedSize(){return this.seedSize;},
    setSeedSize(SeedSize){this.seedSize = SeedSize;},

    getCategory(){return "withSeedInside Fruit" ;}
} 


function bigFruit (Weight,eatingSeason){
    Fruit.call(this,Weight);
    this.eatingSeason = eatingSeason || null ;
}
bigFruit.prototype = {
   //extend from fruit
   __proto__ : Fruit.prototype,

    getEatSeason(){return this.eatingSeason;},
    setEatSeason(EatingSeason){this.eatingSeason = EatingSeason;},

    getCategory(){return "Big Fruit" ;},
} 

//level 2 calss
function berry(weight,price,origin){
    tinyFruit.call(this,weight,price);
    this.origin = origin || null ;
}
berry.prototype = {
    //extend from tinyfruit
    __proto__ : tinyFruit.prototype,
        
    getOrigin(){return this.origin ;},
    setOrigin(Origin){this.origin = Origin ;},

    getCategory(){return "Tiny and berry Fruit" ;}
}

//level 3 calsses "fruits' calsses"
function grapes(weight,price = 15){
    tinyFruit.call(this,weight,price);
}
grapes.prototype = {
    //extend from tinyfruit
    __proto__ : tinyFruit.prototype,

    getType(){return "grapes" ; } ,
    getHowManyInKg (){
        return new howManyInKg().howmany(this.weight);
    }
}


function raspberry (weight,price = 150,origin = "Europe"){
    berry.call(this,weight,price,origin);
}
raspberry.prototype = {
    //extend from berry
    __proto__ : berry.prototype ,

    getType(){return "raspberry";}
}


function blueberry (weight,price = 60,origin = "North America"){
    berry.call(this,weight,price,origin);
}
blueberry.prototype = {
    //extend from berry
    __proto__ : berry.prototype ,

    getType(){return "blueberry";}
}


function balckberry (weight,price = 70,origin = "Europe and Asia"){
    berry.call(this,weight,price,origin);
}
balckberry.prototype = {
    //extend from berry
    __proto__ : berry.prototype ,
    getType(){return "balckberry";}
}


function orange (weight,peelable = true){
    ovalShape.call(this,weight,peelable);
}
orange.prototype = {
    //extend from ovalshape
    __proto__ : ovalShape.prototype ,

    getType(){return "orange";}
}


function kiwi (weight,peelable = false){
    ovalShape.call(this,weight,peelable);
}
kiwi.prototype = {
    //extend from ovalshape
    __proto__ : ovalShape.prototype ,

    getType(){return "kiwi";}
}


function mango (weight,seedSize = "big"){
    withSeedInside.call(this,weight,seedSize);
}
mango.prototype = {
    //extend from withSeedInside
    __proto__ : withSeedInside.prototype ,

    getType(){return "mango" ;}
}


function apple(weight,seedSize = "small"){
    withSeedInside.call(this,weight,seedSize);
}
apple.prototype = {
    //extend from withSeedInside
    __proto__ : withSeedInside.prototype ,

    getType(){return "apple" ;}
}


function avocado(weight,seedSize = "medium"){
    withSeedInside.call(this,weight,seedSize);
}
avocado.prototype = {
    //extend from withSeedInside
    __proto__ : withSeedInside.prototype ,

    getType(){return "avocado" ;}
}


function banana (weight,eatingSeason = "winter and summer"){
    bigFruit.call(this,weight,eatingSeason);
}
banana.prototype = {
    //extend from bigFruit
    __proto__ : bigFruit.prototype ,

    getType(){return "banana" ;}
}


function watermelon (weight,eatingSeason = "summer"){
    bigFruit.call(this,weight,eatingSeason);
}
watermelon.prototype = {
    //extend from bigFruit
    __proto__ : bigFruit.prototype ,
    
    getType(){return "watermelon" ;}
}


function pineapple (weight,eatingSeason = "summer and spring"){
    bigFruit.call(this,weight,eatingSeason);
} 
pineapple.prototype = {
    //extend from bigFruit
    __proto__ : bigFruit.prototype ,

    getType(){return "pineapple" ;}
}


//=========================
function howManyInKg (){}
howManyInKg.prototype = {
    howmany(weight){
        return 1000/weight ;
    }
}

//=========================================================================
//BSTree implementation


function BST(){
    this.root = null ;
}
BST.prototype =  {

    Iterate(){
        this.inOrder(this.root,this.print);
    },
    
    print (fruit,type,weight){
        console.log(fruit.getType() + " " + fruit.getWeight() + "    ");
    },

    filterByType(Type){
        this.inOrder(this.root,this.ByType,Type,null);
    },

    ByType(fruit,type,weight){
        if (fruit.getType() === type)
            console.log(fruit.getType() + " " + fruit.getWeight() + "    ");
    },

    filterByWeight(Weight){
        this.inOrder(this.root,this.ByWeight,null,Weight);
    },

    ByWeight(fruit,type,weight){
        if (fruit.getWeight() > weight)
            console.log(fruit.getType() + " " + fruit.getWeight() + "    ");
    },

    magnifyByType(Type, Weight){
        this.inOrder(this.root,this.editTree,Type,Weight);
        
        var listOfNodes = function(node,List){
            if (node === null) 
                return ;

            List.push(node) ;

            listOfNodes(node.getLeft(),List);
            listOfNodes(node.getRight(),List);
        };

        var List = [];
        listOfNodes(this.root,List);
        this.root = null ;

       
        for (let index = 0; index < List.length; index++) {
            let fruit = List[index];
            fruit.setLeft(null);
            fruit.setRight(null);
            this.insert(fruit);
        }
    },

    editTree(fruit,Type,Weight){
        if (fruit.getType() === Type){
            fruit.setWeight(fruit.getWeight()+Weight);
        }
    },

    inOrder(fruit,fucTODO,Type,Weight){
        if (fruit === null)
            return;
 
        // first recur on left child 
        this.inOrder(fruit.left,fucTODO,Type,Weight);
 
        // do the fuction
        fucTODO(fruit,Type,Weight);
 
        // now recur on right child
        this.inOrder(fruit.right,fucTODO,Type,Weight);
    },


    insert(newFruit) {
        let node = this.root;
      
        if (node === null) {
            this.root = newFruit;
            return;
        } 
      
        else {
            while (node !== null){
                if (newFruit.getWeight() < node.getWeight()) {
                    if (node.getLeft() === null) {
                        node.setLeft(newFruit);
                        return;
                    } else {
                        node = node.getLeft();
                    }
                } 
                else{
                    if (node.getRight() === null) {
                        node.setRight(newFruit);
                        return;
                    } 
                    else {
                        node = node.getRight();
                    }
                } 
            }  
        }
    },
    
    findHeaviest() {
        var current = this.root;
        while (current.getRight() !== null) {
            current = current.getRight();
        }
        return current;
    },
    
    findLightest() {
      let current = this.root;
      while (current.getLeft() !== null) {
        current = current.getLeft();
      }
      return current;
    },
}

let bs = new BST();

bs.insert(new kiwi(15,true));
bs.insert(new raspberry(14));
bs.insert(new banana(16,"summer"));
bs.insert(new banana(20,"summer"));
bs.insert(new grapes(17));
bs.insert(new pineapple(13,"summer"));

console.log(bs.findHeaviest().getWeight());
console.log(bs.findLightest().getWeight());



