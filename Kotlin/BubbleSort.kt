/**
 * @author trol
 * @since 10/2/18
 */

fun main(args: Array<String>) {
    val array = arrayOf(4,7,1,9,1,7,2,9)


    BubbleSort.sort(array)

    array.forEach{ println(it)}
}
object BubbleSort {




    fun sort(array: Array<Int>) {

        for(i in 0 until array.size -1) {
            for(j in 0 until array.size - i - 1) {
                if(array[j] < array[j + 1]) {
                    val temp = array[j + 1]
                    array[j + 1] =  array[j]
                    array[j] = temp
                }
            }
        }
    }
}