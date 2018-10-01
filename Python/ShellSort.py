def shellSort(islisto):
    
    gap = len(islisto) / 2
    while gap > 0:

        for i in range(gap, len(islisto)):
            temp = islisto[i]
            j = i
            while j >= gap and islisto[j - gap] > temp:
                islisto[j] = islisto[j - gap]
                j = j-gap
            islisto[j] = temp

# Reduce the gap

        gap = gap/2

list = [19,2,31,45,30,11,121,27]

shellSort(list)
print(list)