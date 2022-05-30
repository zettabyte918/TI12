def sum(l):
    s = 0
    for i in l:
        s+=i
    return s

def multiply(l):
    m = 1
    for i in l:
        m*=i
    return m

def sum_multiply(l):
    l1 = []
    l2 = []
    j = 0
    k = 0
    for i in l:
        if(i%2==0):
            l1.insert(j,i)
            j=j+1
        else:
            l2.insert(k,i)
            k=k+1
    return sum(l1),multiply(l2)

print("sum", sum([2,5,5]))
print("mult", multiply([2,5,5]))

x1,x2 = sum_multiply([2,2,5,5])

print("even sum_mul", x1,x2)
