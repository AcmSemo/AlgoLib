import scala.annotation.tailrec

def slowerFactorial(n: Long): Long = n match {
    case 1 => 1
    case n => n * slowerFactorial(n - 1)
}

def fasterFactorial(n: Long): Long = {
    @tailrec
    def inner(n: Long, acc: Long): Long = n match {
        case 1 => acc
        case n => inner(n - 1, acc * n)
    }

    inner(n, 1)
}
print("Please hit enter to run slower factorial.")
scala.io.StdIn.readLine()

print("slowerFactorial(20) = ")
println(slowerFactorial(20))

print("Please hit enter to run faster factorial.")
scala.io.StdIn.readLine()

print("fasterFactorial(20) = ")
println(fasterFactorial(20))

/*
    To run:
        scala factorial.scala
    Output:
    Please hit enter to run slower factorial.
    slowerFactorial(20) = 2432902008176640000
    Please hit enter to run faster factorial.
    fasterFactorial(20) = 2432902008176640000
*/