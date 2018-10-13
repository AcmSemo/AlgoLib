function factorial(number: number): number{

  //So first we ask if the number is not negative because we can't calculate the factorial of a negative number
  if (number >= 1){
    //If it isn't we return the number multiplied by the factorial of that number - 1
    return number * factorial(number-1);
  }
  //Once the actual number is 1, we return that value because 1! == 1
  return 1;
}

export default factorial;