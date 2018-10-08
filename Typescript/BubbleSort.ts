function bubbleSort (arr : number[]): number[] {
    const _arr = arr.slice(0); // clone the array, so we don't change input data
    let temp, i, j;

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

export default bubbleSort;