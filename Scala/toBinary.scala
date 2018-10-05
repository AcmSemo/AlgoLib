import scala.annotation.tailrec

def toBinary(num: Int): List[Int] = {
  @tailrec // tail recursive form allowing the compiler to
           // convert the recursion to a fast for loop.
  def inner(num: Int, acc: List[Int]): List[Int] = {
    if (num == 0) acc
    else inner(num / 2, (num % 2) :: acc)
  }

  inner(num, List())
}

println("Converting the numbers 1 - 1000 into binary")
println(1.to(1000).map(num => toBinary(num).mkString("")).mkString("\n"))

// To run type 'scala toBinary.scala'
//
// Result:
// 1
// 10
// 11
// 100
// 101
// 110
// 111
// ...
