def quicksort(l,start,end):
    if(start<end):
        pivot_index = pivot(l,start,end)
        quicksort(l,start,pivot_index)
        quicksort(l,pivot_index+1,end)
    return l
def pivot(arr,start,end):
    pivot_index = start
    pivot_element = arr[start]
    for i in range(start,end):
        if(pivot_element>arr[i]):
            pivot_index+=1
            arr[pivot_index],arr[i] = arr[i],arr[pivot_index]
    arr[start],arr[pivot_index] = arr[pivot_index],arr[start]
    return pivot_index
l = [4,3,2,1]
print(quicksort(l,0,len(l)))