def is_subset_or_not(arr,arr2):
    newarr = set(arr)

    for i in range(len(arr2)):
        if arr2[i] not in newarr:
            return 0

    return 1



arr = [1,2,3,4,5,6]
arr2 = [2,3,4,1]
if is_subset_or_not(arr,arr2):
    print("SUBSET")
else:
    print("NOT SUBSET")


