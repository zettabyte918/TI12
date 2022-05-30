from cmath import sqrt


def cal(l):
    res = []
    k = 0
    for i in l:
        res.insert(k,int(sqrt((2*50*i)/30).real))
        k = k+1
    return res
print(cal([100,150,180]))