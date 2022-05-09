lt = [(2, 5), (1, 2), (4, 4), (2, 3), (2, 1)]
l = len(lt)
for i in range(0, l):
    for j in range(0, l-i-1):
        if (lt[j][1] > lt[j + 1][1]):
            x = lt[j]
            lt[j]= lt[j + 1]
            lt[j + 1]= x
print(lt)
