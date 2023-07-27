def bubblesort(array):
    for idx, i in enumerate(array):
        for j in range(0, (len(array)-idx-1)):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array

if __name__ == "__main__":
    array = [17, 9, 13, 18, 8, 7, -5, 18, 6, 11, 3, 4, 1, 2]
    print(bubblesort(array))
