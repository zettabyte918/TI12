nb = [121,110,99]
def max(l):
    max = l[0]
    for i in range(1,len(l)):
        if(max<l[i]):
            max = l[i]
    print(max)

max(nb)