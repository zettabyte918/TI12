d1 = {'a': 100, 'b': 200, 'c':300}
d2 = {'a': 300, 'b': 200, 'd':400}
d3 = {}
for (dic1,v), (dic2,v2) in zip(d1.items(), d2.items()):
    if(dic1 == dic2):
        d3[dic1] = int(v+v2)
    else:
        d3[dic1] = d1[dic1]
        d3[dic2] = d2[dic2]
print(d3)
            