const factorialOf = require("../FactorialRecursive");

describe("Factorial", () => {
	it("Returns the factorial of 5", () => {
		// 5! == 5 * 4 * 3 * 2 * 1 == 120
		const result = factorialOf(5);

		expect(result).toEqual(120);
	})
})