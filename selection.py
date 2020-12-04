def selectionsort(l):
    for i in range(len(l)):
        min = i
        for j in range(i+1,len(l)):
            if(l[j]<l[min]):
                min = j
        l[min],l[i] = l[i],l[min]
    print(l)
selectionsort([98,3,21,6,-1,10,99,-3])