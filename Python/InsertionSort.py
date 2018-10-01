from __future__ import print_function


def insertion_sort(collection):
    length = len(collection)
    # Starts at 1, assume index 0 is sorted
    for index_ in range(1, length):
        # current value of item to be sorted in
        current_value = collection[index_]
        prev_position = index_

        while prev_position > 0 and \
                collection[prev_position - 1] > current_value:
            collection[prev_position] = collection[prev_position - 1]
            prev_position -= 1
        collection[prev_position] = current_value
    return collection


if __name__ == '__main__':
    try:
        raw_input  # Python 2
    except NameError:
        raw_input = input  # Python 3

    user_input = raw_input('Enter numbers separated by a comma:\n').strip()
    unsorted = [int(item) for item in user_input.split(',')]
    print(insertion_sort(unsorted))
