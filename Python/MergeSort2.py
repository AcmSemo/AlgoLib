def iterative_merge_sort(coll):
    """
    This version of merge sort is from p. 57 of Algorithms
    by S. Dasgupta, C. H. Papadimitriou and U. V. Vazirani
    """
    queue = [[x] for x in coll]
    while len(queue) > 1:
        queue.append(merge(queue.pop(0), queue.pop(0)))
    return queue.pop()


def merge(X, Y):
    if not X:
        return Y
    if not Y:
        return X
    x, *xs = X
    y, *ys = Y
    if x < y:
        return [x] + merge(xs, Y)
    else:
        return [y] + merge(X, ys)


if __name__ == '__main__':
    try:
        raw_input          # Python 2
    except NameError:
        raw_input = input  # Python 3

    user_input = raw_input('Enter numbers separated by a comma:\n').strip()
    unsorted = [int(item) for item in user_input.split(',')]
    print(iterative_merge_sort(unsorted))
