price = input("price: ")

if(int(price)>500):
    price = str(int(price) - float(price)* 0.5)

elif(200 <= int(price) <= 500):
    price = str(int(price) - float(price)* 0.3)

elif(int(price)<200):
    price = str(int(price) - float(price)*0.1)
print(price)