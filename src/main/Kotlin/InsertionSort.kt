fun insertionSort(array: IntArray) {
    for ((index) in array.withIndex()) {
        var j = index

        while (j > 0) {
            // swap if smaller than sorted[j]
            if (array[j] < array[j - 1]) {
                val temp = array[j]
                array[j] = array[j - 1]
                array[j - 1] = temp

            }
            j--
        }

    }

}

fun main(args: Array<String>) {
    val array = intArrayOf(4, 3, 5, 6, 2, 1)
    array.forEach { i -> println(i) }
    insertionSort(array)
    array.forEach { i -> println(i) }
}
