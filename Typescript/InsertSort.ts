function insertionSort(arr : number[]) : number[]{
  const len = arr.length;
  let element;
  let j;

  for(let i = 1; i<len; i++){
    element = arr[i];
    j = i;

    while(j > 0 && arr[j-1] > element){
      arr[j] = arr[j-1];
      j--;
   }

   arr[j] = element;
  }

  return arr;
}

export default insertionSort;