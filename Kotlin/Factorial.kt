fun main(args: Array<String>) {
    println(Factorial.factorial(-1))
}

object Factorial {
    fun factorial(number: Int): Int {
        if (number >= 1) return number * factorial(number - 1)
        return 1
    }
}
