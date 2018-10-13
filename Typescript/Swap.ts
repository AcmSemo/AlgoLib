// Swap two items in an array
export default function swap<T>(input : T[], index_A : number, index_B : number) {
    var temp = input[index_A];
 
    input[index_A] = input[index_B];
    input[index_B] = temp;
 }