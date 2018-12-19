import kotlin.system.measureTimeMillis

fun main(args: Array<String>) {
    val executionTime = measureTimeMillis {
    println(SelectionSort.selectionSort(mutableListOf(5, 7, 2, 3, -4, 1, 5, 3, 4, 6)))
    }
    println("Execution Time = $executionTime ms")
}

object SelectionSort {
    fun selectionSort(numbers: MutableList<Int>): MutableList<Int> {
        if (numbers.isEmpty()) {
            return numbers
        }
        for (number in 0..numbers.count()) {
            val subList = numbers.subList(0, numbers.size - number)
            val minNumber = subList.min()
            if (minNumber != null) {
                numbers.removeAt(subList.indexOf(minNumber))
                numbers.add(minNumber)
            }
        }
        return numbers
    }
}
