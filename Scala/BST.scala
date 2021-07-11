import scala.collection.mutable.ArrayBuffer

class BST {
  var root :Fruit=_
  def insert(node : Fruit): Unit ={
    if(root==null)
      root=node
    else
      BSTinsert(root,node)
  }
  private def BSTinsert(root : Fruit , node:Fruit): Fruit={
    if(root==null){
      node
    }else {
      if (root.weight > node.weight)
        root.setLeft(BSTinsert(root.getLeft, node))
      else
        root.setRight(BSTinsert(root.getRight, node))
      root
    }
  }
  //helper function
  private def inOrderTraversal(root :Fruit ,funToDo: Any =null):Unit={
    if(root!=null){
      inOrderTraversal(root.getLeft,funToDo)
      funToDo match{
        case x : String => if(root.getType==x){
          print(root.weight + " ")
        }
        case y:Int =>if(root.weight>y){
          print(root.weight + " ")
        }
        case z:(String,Int) =>if(root.getType==z._1){
          root.weight =root.weight+ z._2
        }
        case list:ArrayBuffer[Fruit] =>list+=root
        case _ => print(root.weight + " ")
      }
      inOrderTraversal(root.getRight,funToDo)
    }
  }
  //a method that prints the in-order traversal of the tree.
  def Iterate() : Unit={
    inOrderTraversal(root)
    println()
  }
  //a method that prints the nodes of a given fruit type ordered by weight. For example, get an ordered list of all apples in the tree
  def filterByType(Type:String) : Unit={
    inOrderTraversal(root,Type)
    println()
  }
  //a method that prints the nodes that have weight larger than the given amount ordered by wright. For example, get an ordered list of all fruits in
  //the tree that are heavier than 500 grams.
  def filterByWeight(Weight:Int) : Unit={
    inOrderTraversal(root,Weight)
    println()
  }

  //===================================================================================================================
  //a method that increases the weight of the nodes of a given fruit type by the given amount.
  // For example, add 200 grams to all bananas in the tree.

  def magnifyByType(Type:String, Weight:Int):Unit={
    inOrderTraversal(root,(Type,Weight))
    var temp:ArrayBuffer[Fruit]=ArrayBuffer()
    inOrderTraversal(root,temp)
    root=null
    temp.foreach(u=>{
      u.setLeft(null)
      u.setRight(null)
    })
    temp.foreach(insert)
  }
  //===================================================================================================================
  //a method that finds the node with the greatest weight in the tree.
  private def getMax(root:Fruit):Fruit={
    if(root==null)null
    else if(root.getRight==null)
      root
    else
      getMax(root.getRight)
  }
  def findHeaviest():Fruit={
    getMax(root)
  }
  //a method that finds the node with the least weight in the tree.
  private def getMin(root:Fruit):Fruit={
    if(root==null)null
    else if(root.getLeft==null)
      root
    else
      getMax(root.getLeft)
  }
  def findLightest():Fruit={
    getMin(root)
  }
}
