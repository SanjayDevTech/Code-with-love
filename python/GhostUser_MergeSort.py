#Merge Sort implementation in python
#Written by GhostUser on 1.10.2020
def merge(S1,S2,S):
    print(S1,S2)
    i=j=0
    while i+j<len(S):
        if j==len(S2) or (i<len(S1) and S1[i]<S2[j]):
            S[i+j]=S1[i]
            i+=1
        else:
            S[i+j]=S2[j]
            j+=1
    return S 

def merge_sort(arr):
    if len(arr)<=2:
        return sorted(arr)
    mid=len(arr)//2
    S1=arr[:mid]
    S2=arr[mid:]
    S1=merge_sort(S1)
    S2=merge_sort(S2)
    return merge(S1,S2,arr)


arr=[4,6,5,7,8,1,3,2,9,11,12,10,15,14,13]
result=merge_sort(arr)
print(result)