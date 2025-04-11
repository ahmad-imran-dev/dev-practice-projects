arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


def passByValue(arr):
    for i in range(len(arr)):
        arr[i] += 5


def passByReference(arr):
    for i in range(len(arr)):
        arr[i] += 10


passByValue(arr)
passByReference(arr)

for val in arr:
    print(val)
print("Array outside the function")
