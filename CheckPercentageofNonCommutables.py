#way to check the percentage of non commutable lists using itertools
import itertools

commuteTot = 0
nonCommuteTot = 0

def checkIfCommutable(lst1, lst2):

    for i in range(len(lst1)):
        if lst2[(lst1[i])] == lst1[(lst2[i])]:
            pass
        else:
            return "not commutable"
    return "commutable"

#change range to test for different sizes of lists
arr = []
for i in range(3):
    arr.append(i)

#for now using itertools, may be a faster way since itertools takes N time and checking all permutations takes (N - 1)! time.
arrPermutations = list(itertools.permutations(arr))
size = len(arrPermutations)
while len(arrPermutations) > 1:
    for i in range(len(arrPermutations) - 1):
        #print(checkIfCommutable(arrPermutations[0], arrPermutations[i + 1]))
        if (checkIfCommutable(arrPermutations[0], arrPermutations[i + 1])) == "commutable":
            commuteTot += 1
        else:
            nonCommuteTot += 1
    arrPermutations.pop(0)

print("nonCommutable total = " + str(nonCommuteTot) + ", Commutable total = " + str(commuteTot) + ", Percentage of nonCommutable = " + str(nonCommuteTot / (nonCommuteTot + commuteTot)))
