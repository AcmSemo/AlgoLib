/**
 *
 * @param {int} number
 *
 * This function calculates the factorial of a number recursively
 *
 * A factorial of a number is the number multiplied by all numbers between the choosen number and 1
 * Or it's the number multiplied by the factorial of number-1
 *
 * You should be able to run this righ in the browser! just copy and paste everything in the developer's console
 *
 */
function factorialOf(number){

  //So first we ask if the number is not negative because we can't calculate the factorial of a negative number
  if (number >= 1){
    //If it isn't we return the number multiplied by the factorial of that number - 1
    return number * factorialOf(number-1);
  }
  //Once the actual number is 1, we return that value because 1! == 1
  return 1;
}

if(typeof module !== 'undefined'){
	module.exports = factorialOf;
}