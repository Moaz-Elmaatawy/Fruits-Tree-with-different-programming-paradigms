object Main {
  def main(args: Array[String]): Unit = {
    var tree:BST=new BST
    tree.insert(new banana(10))
    tree.insert(new avocado(20))
    tree.insert(new apple(25))
    tree.insert(new kiwi(8))

    tree.insert(new banana(7))
    tree.insert(new banana(11))
    tree.insert(new banana(13))
    tree.insert(new banana(17))

    tree.insert(new raspberry(3,5))
    tree.insert(new balckberry(50,10))
    tree.insert(new balckberry(100,20))

    println("Iterate : ")
    tree.Iterate()
    println()

    println("filterByType(banana) :")
    tree.filterByType("banana")
    println()

    println("filterByWeight(10) :")
    tree.filterByWeight(10)
    println()

    println("magnifyByType(banana, 1000) :")
    tree.magnifyByType("banana",1000)
    println()

    println("Iterate : ")
    tree.Iterate()
    println()

    println("findHeaviest() :")
    println(tree.findHeaviest().weight)
    println()

    println("findLightest() :")
    println(tree.findLightest().weight)
    println()
  }
}
