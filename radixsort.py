def getDigit(num,p):
    pos = 10 ** (p+1)
    return((num%pos)//(pos//10))
def digitCount(num):
    if(num==0): return 1
    count = 0
    while(num!=0):
        count+=1
        num = num//10
    return(count)
def mostDigits(l):
    mostdigits = 1
    for i in l:
        digits = digitCount(i)
        if(digits>mostdigits):
            mostdigits = digits 
    return mostdigits
def radixsort(l):
    md = mostDigits(l)
    for i in range(md):
        sl = [[],[],[],[],[],[],[],[],[],[]]
        for j in l:
            sl[getDigit(j,i)].append(j)
        p = []
        for k in sl:
            p.extend(k)
        l = p[::]
    return(l) 
print(radixsort([5,4,3,2,1]))

