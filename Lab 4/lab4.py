# 2. In Python, write a function find(L, e) that takes in a sorted list L and an element e, and returns the lowest index in L such that L[i] == e. (-1 if there is no such index)
#    Write a function that takes in a sorted linst L and an element e, and returns the index of the highest index in L such that L[i] == e. (-1 if there is no such index).
#    The function should run in O(log(n)) time.
#    This should help you with Project 1.


def find(L, e):
    start = 0
    end = len(L)-1

    while start<=end:
        mid = (start+end) // 2
        if L[start] == e:
            return start
        elif L[mid] < e:
            start = mid + 1
        else:
            end = mid

    return -1


def find2(L, e):
    start = 0
    end = len(L)-1

    while start<=end:
        mid = (start+end) // 2
        if L[end] == e:
            return end
        elif L[mid] <= e:
            start = mid
        else:
            end = mid - 1

    return -1