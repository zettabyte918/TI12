from math import floor

items= [('item1', '12.20'), ('item2', '15.10'), ('item3', '24.5')]

l = len(items)
for i in range(0, l):
    for j in range(0, l-i-1):
        x1 = float(items[j][1]) - floor(float(items[j][1]))
        x2 = float(items[j+1][1]) - floor(float(items[j+1][1]))
        if (x1 > x2):
            x = items[j]
            items[j]= items[j + 1]
            items[j + 1]= x
            
print(items)

