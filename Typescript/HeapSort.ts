var array_length : number;
/* to create MAX  array */
function heap_root(input : number[], i : number) {
   var left = 2 * i + 1;
   var right = 2 * i + 2;
   var max = i;

   if (left < array_length && input[left] > input[max]) {
       max = left;
   }

   if (right < array_length && input[right] > input[max])     {
       max = right;
   }

   if (max != i) {
       swap(input, i, max);
       heap_root(input, max);
   }
}

function swap(input : number[], index_A : number, index_B : number) {
   var temp = input[index_A];

   input[index_A] = input[index_B];
   input[index_B] = temp;
}

function heapSort(input : number[]) : number[] {

   array_length = input.length;

   for (var i = Math.floor(array_length / 2); i >= 0; i -= 1)      {
       heap_root(input, i);
     }

   for (i = input.length - 1; i > 0; i--) {
       swap(input, 0, i);
       array_length--;


       heap_root(input, 0);
   }

   return input;
}

export default heapSort;