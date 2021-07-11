//level 0 the fruit abstract class
abstract class Fruit(var weight : Int = 0){
  var left : Fruit = null ;
  var right : Fruit = null ;

  def getWeight : Int = weight
  def setWeight(Weight: Int) {this.weight = Weight}

  def getLeft : Fruit = left
  def setLeft(Left : Fruit) {this.left = Left}

  def getRight : Fruit = right
  def setRight(Right : Fruit){this.right = Right}

  def getType : String = "still undefined"
  def getCategory : String = "just Fruit"

}

//level 1 calsses
class tinyFruit (var Weight : Int, var price : Int) extends Fruit(Weight){

  def getPrice : Int = price
  def setPrice (Price : Int){this.price = Price}

  override def getCategory: String = "Tiny Fruit"
}


class ovalShape (var Weight : Int, var peelable : Boolean) extends Fruit(Weight){

  def isPeelable: Boolean = peelable
  def setPeelable (Peelable : Boolean){this.peelable = Peelable}

  override def getCategory: String = "OvalShape Fruit"
}


class withSeedInside (var Weight : Int, var seedSize : String) extends Fruit(Weight){

  def getSeedSize: String = this.seedSize
  def setSeedSize (seedSize : String){this.seedSize = seedSize}

  override def getCategory: String = "withSeedInside Fruit"
}


class bigFruit (var Weight : Int, var eatingSeason : String) extends Fruit(Weight){

  def getEatSeason: String = this.eatingSeason
  def setEatSeason (EatingSeason : String){this.eatingSeason = EatingSeason}

  override def getCategory: String = "Big Fruit"
}

//level 2 calss
class berry(var W : Int, var Price : Int,var origin : String) extends tinyFruit(W,Price){

  def getOrigin : String = this.origin
  def setOrigin(Origin : String){this.origin = Origin}

  override def getCategory: String = "berry and Tiny"
}


//level 3 calsses "fruits' calsses"
class grapes(var W : Int,var Price : Int = 15) extends tinyFruit(W,Price){
  override def getType: String = "grapes"

  def howmany() : Int = new howManyInKg().howMany(this.W)
}

class raspberry(var Weigt : Int,var Pric : Int,Origin: String = "Europe") extends berry(Weigt,Pric,Origin){
  override def getType: String = "raspberry"
}

class blueberry(var Weigt : Int,var Pric : Int,Origin: String = "Europe") extends berry(Weigt,Pric,Origin){
  override def getType: String = "blueberry"
}

class balckberry(var Weigt : Int,var Pric : Int,Origin: String = "Europe") extends berry(Weigt,Pric,Origin){
  override def getType: String = "balckberry"
}

class orange(var WEight : Int,var Peelable : Boolean = true) extends ovalShape(WEight,Peelable){
  override def getType: String = "orange"
}

class kiwi(var WEight : Int,var Peelable : Boolean = true) extends ovalShape(WEight,Peelable){
  override def getType: String = "kiwi"
}

class mango(var WEight : Int,var SeedSize : String = "big") extends withSeedInside(WEight,SeedSize){
  override def getType: String = "mango"
}

class apple(var WEight : Int,var SeedSize : String = "small") extends withSeedInside(WEight,SeedSize){
  override def getType: String = "apple"
}

class avocado(var WEight : Int,var SeedSize : String = "medium") extends withSeedInside(WEight,SeedSize){
  override def getType: String = "avocado"
}

class banana(var WEight : Int,var EatingSeason : String = "winter and summer") extends bigFruit(WEight,EatingSeason){
  override def getType: String = "banana"
}

class watermelon(var WEight : Int,var EatingSeason : String = "summer") extends bigFruit(WEight,EatingSeason){
  override def getType: String = "watermelon"
}

class pineapple(var WEight : Int,var EatingSeason : String = "summer and spring") extends bigFruit(WEight,EatingSeason){
  override def getType: String = "pineapple"
}

//========================this class to use in delegation==============
class howManyInKg() {
  def howMany(x : Int) : Int = 1000/x
}
