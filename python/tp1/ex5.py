x = input("number: ")
f=1
l="!"+x+"="
for i in range(int(x),0,-1):
    f=f*i
    if(i!=1):
        l = l + str(i) + "*"
    else: l = l + str(i)

print(l)