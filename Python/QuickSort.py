# coding=utf-8
import random


n = 10
A = [random.randint(0, 10) for i in range(0, n)]


def partition(array, start, end):
    pivot = array[(start + end) // 2]
    i = start
    j = end

    while i <= j:
        while array[i] < pivot:
            i += 1
        while array[j] > pivot:
            j -= 1
        if i <= j:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp

            i += 1
            j -= 1

    return i


def qSort(array, start, end):
    if start < end:
        temp = partition(array, start, end)

        qSort(array, start, temp - 1)
        qSort(array, temp, end)


if __name__ == "__main__":
    print(A)
    qSort(A, 0, len(A) - 1)
    print(A)
