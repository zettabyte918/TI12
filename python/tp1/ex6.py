ch = input("ch: ")
l=list(ch)
l2=""

for i in range(0,len(ch),1):
    if(i%2 == 0) : l2=l2+l[i]
print(l2)