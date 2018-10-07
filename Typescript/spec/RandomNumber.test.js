const RandomNumber = require("../RandomNumber");

describe("RandomNumber", () => {
	it("Returns a long between 0 and 100", () => {
		const rand = RandomNumber(1, 100);

		expect(rand > 0).toBeTruthy();
		expect(rand < 100).toBeTruthy();

		expect(rand % 1 > 0).toBeTruthy();
	})

	it("Returns an int between 0 and 100", () => {
		const rand = RandomNumber(1, 100, true);

		expect(rand > 0).toBeTruthy();
		expect(rand < 100).toBeTruthy();

		expect(rand % 1 > 0).toBeFalsy();
	})
});