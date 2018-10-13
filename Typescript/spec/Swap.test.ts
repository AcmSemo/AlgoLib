import swap from "../Swap";

describe("Swap", () => {
	it("Swaps two numbers in an array", () => {
		const array = [2, 4, 6, 8]
		
		swap(array, 1, 3)
		
		expect(array).toEqual([2, 8, 6, 4])
	})

	it("Swaps two objects in an array", () => {
		const array = [
			{id: 1},
			{prop: 7}
		];
		
		swap(array, 1, 0);

		expect(array).toEqual([
			{prop: 7},
			{id: 1}
		])
	})
});