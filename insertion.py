def insertionsort(l):
    for i in range(1,len(l)):
        ele = l[i]
        j = i-1
        while(ele<l[j] and j>=0):
            l[j+1] = l[j]
            j-=1
        l[j+1] = ele
    print(l)
insertionsort([19,2,5,8,-9,99,34,-1])
