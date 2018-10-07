
import BubbleSort from '../BubbleSort';
import HeapSort from '../HeapSort';
import QuickSort from '../QuickSort';
import InsertSort from '../InsertSort';
import SelectionSort from '../SelectionSort';

describe("Bubble Sort", () => {
	it("Sorts an array of 10 integers into ascending order", () => {
		const array = [8,6,7,5,3,0,9,2,4,1]

		const sorted = BubbleSort(array)

		expect(sorted).toEqual([0,1,2,3,4,5,6,7,8,9])
	})
})

describe("Heap Sort", () => {
	it("Sorts an array of 10 integers into ascending order", () => {
		const array = [8,6,7,5,3,0,9,2,4,1]

		const sorted = HeapSort(array)

		expect(sorted).toEqual([0,1,2,3,4,5,6,7,8,9])
	})
})

describe("Quick Sort", () => {
	it("Sorts an array of 10 integers into ascending order", () => {
		const array = [8,6,7,5,3,0,9,2,4,1]

		const sorted = QuickSort(array)

		expect(sorted).toEqual([0,1,2,3,4,5,6,7,8,9])
	})

	it("Sorts an array including negative numbers", () => {
		var array = [3, 0, 2, 5, -1, 4, 1 ]
		
		const sorted = QuickSort(array)

		expect(sorted).toEqual([-1, 0, 1, 2, 3, 4, 5])
	})
})

describe("Insert Sort", () => {
	it("Sorts an array of 10 integers into ascending order", () => {
		const array = [8,6,7,5,3,0,9,2,4,1]

		const sorted = InsertSort(array)

		expect(sorted).toEqual([0,1,2,3,4,5,6,7,8,9])
	})
})


describe("Selection Sort", () => {
	it("Sorts an array of 10 integers into ascending order", () => {
		const array = [8,6,7,5,3,0,9,2,4,1]

		const sorted = SelectionSort(array)

		expect(sorted).toEqual([0,1,2,3,4,5,6,7,8,9])
	})
})
