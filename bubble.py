def bubblesort(l):
    for i in range(len(l)):
        swaps = False
        for j in range(len(l)-i-1):
            if(l[j]>l[j+1]):
                l[j],l[j+1] = l[j+1],l[j]
                swaps = True
        if(swaps==False):
            break
    print(l)
bubblesort([1,2,3,98,4,5,6])