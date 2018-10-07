import swap from "./Swap";

/* to create MAX  array */
function heap_root(input : number[], i : number, array_length : number) {
   const left = 2 * i + 1;
   const right = 2 * i + 2;
   let max = i;

   if (left < array_length && input[left] > input[max]) {
       max = left;
   }

   if (right < array_length && input[right] > input[max])     {
       max = right;
   }

   if (max != i) {
       swap(input, i, max);
       heap_root(input, max, array_length);
   }
}

function heapSort(input : number[]) : number[] {
   let array_length = input.length;

   for (var i = Math.floor(array_length / 2); i >= 0; i -= 1)      {
       heap_root(input, i, array_length);
     }

   for (i = input.length - 1; i > 0; i--) {
       swap(input, 0, i);
       array_length--;


       heap_root(input, 0, array_length);
   }

   return input;
}

export default heapSort;