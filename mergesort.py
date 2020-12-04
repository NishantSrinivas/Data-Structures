def mergesort(l):
    if(len(l)<=1):
        return(l)
    return merge(mergesort(l[0:len(l)//2]),mergesort(l[len(l)//2::]))
def merge(l,m):
    arr = []
    i = 0; j=0
    while(i<len(l) and j<len(m)):
        if(l[i]<m[j]):
            arr.append(l[i])
            i+=1
        else:
            arr.append(m[j])
            j+=1
    if(i<=len(l)-1):
        arr += l[i::]
    else:
        arr += m[j::]
    return arr
print(mergesort([99,98,97,96,95,100,109]))