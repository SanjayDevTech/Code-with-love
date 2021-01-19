#Implementation of Closest sum pair in python
#Given a target and two arrays, find the index of elements whose sum is closest to the target
#Written by PeeyushKumar

def closestPairHelper(M, i, j, target):

    closest_sum = M[i][j]
    closest_pair = (i,j)

    while i < len(M) and j >= 0:

        if abs(target-M[i][j]) < abs(target-closest_sum):
            closest_sum = M[i][j]
            closest_pair = (i,j)

        if M[i][j] < target:
            i += 1
        elif M[i][j] > target:
            j -= 1
        else:
            return (i,j)

    return(closest_pair)

def closestPair(list1, list2, target):
    x = list1.copy()
    y = list2.copy()

    x.sort()
    y.sort()
    M = []

    for row in x:
        lrow = []
        for col in y:
            lrow.append(row+col)
        M.append(lrow)
    
    i, j = closestPairHelper(M, 0, len(M[0])-1, target)


    return (list1.index(x[i]), list2.index(y[j]))


x = [6, 1, 4, 3]
y = [9, 2, 6, 3]
target = 11

print(closestPair(x, y, target))
