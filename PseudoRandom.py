# Python Program to shuffle a given array
import random

lstlst = []
# A function to generate a random permutation of arr[]
def randomize(arr, n):
    # Start from the last element and swap one by one. We don't
    # need to run for the first element that's why i > 0
    for i in range(n - 1, 0, -1):
        # Pick a random index from 0 to i
        j = random.randint(0, i)

        # Swap arr[i] with the element at random index
        arr[i], arr[j] = arr[j], arr[i]
    lstlst.append(arr)
    return arr

def checkIfCommutable(lst1, lst2):
    for i in range(len(lst1)):
        if lst2[(lst1[i])] == lst1[(lst2[i])]:
            pass
        else:
            return "commutable"
    return "not commutable"

# Driver program to test above function.
arr = []
for i in range(10):
    arr.append(i)
for i in range(10):
    n = len(arr)
    print(randomize(arr, n))
for i in range(len(lstlst) - 1):
    print(checkIfCommutable(lstlst[i], lstlst[i+1]))    
