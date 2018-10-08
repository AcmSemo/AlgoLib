function quick_Sort(origArray : number[]) : number[] {
	if (origArray.length <= 1) { 
		return origArray;
	} 

	var left = [];
	var right = [];
	var newArray : number[] = [];
	var pivot = origArray.pop()!;
	var length = origArray.length;

	for (var i = 0; i < length; i++) {
		if (origArray[i] <= pivot) {
			left.push(origArray[i]);
		} else {
			right.push(origArray[i]);
		}
	}

	return newArray.concat(quick_Sort(left), pivot, quick_Sort(right));
}

export default quick_Sort;