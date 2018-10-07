function bubbleSort (arr : number[]): number[] {
    var _arr = arr.slice(0), // clone the array, so we don't change input data
        temp,
        i,
        j;

    // sorting
    for (i = 0; i < _arr.length - 1; ++i) {
        for (j = 0; j < _arr.length - 1 - i; ++j) {
            if (_arr[j] > _arr[j + 1]) {
                temp = _arr[j];
                _arr[j] = _arr[j + 1];
                _arr[j + 1] = temp;
            }
        }
    }

    return _arr;

}

/* usage

var arr1 = [1, 20, 1000, 2, 44, 23, 3, 6, 56, 78, 43, 22, 21, 20, 10, 100, 101, 102, 103, 104, 20000];
var arr2 = bubbleSort(arr1);
console.log(arr1);
console.log(arr2);

*/

export default bubbleSort;