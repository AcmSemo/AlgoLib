
/**
 *
 * Returns a random number between min and max value, either a float or int
 * @param  {int|float} min           the minimum value
 * @param  {int|float} max           the maximum value
 * @param  {?bool} isInteger         If the returned value should be an integer or not
 * @return {int|float}               a random number between the min and max value
 *
 */
const randomNumber = (min, max, isInteger) => {
    const rndNumber = Math.random() * (max - min) + min;
    if (isInteger)
        return Math.round(rndNumber);

    return rndNumber;
}

if(typeof module !== 'undefined'){
	module.exports = randomNumber;
}