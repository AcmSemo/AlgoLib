function swap(input, index_A, index_B) {
    var temp = input[index_A];
 
    input[index_A] = input[index_B];
    input[index_B] = temp;
 }

function selectionSort(items){
  var len = items.length,
      min;
  for (i=0; i < len; i++){
      //set minimum to this position
      min = i;
      //check the rest of the array to see if anything is smaller
      for (j=i+1; j < len; j++){
          if (items[j] < items[min]){
              min = j;
          }
      }
      //if the minimum isn't in the position, swap it
      if (i != min){
          swap(items, i, min);
      }
  }
  return items;
}

if(typeof module !== 'undefined'){
    module.exports = selectionSort;
}