nom = input("nom: ")
nom2 = nom
prenom = input("prenom ")
prenom2 = prenom

n=list(nom)
n2=list(nom)
p=list(prenom)
p2=list(prenom)


for i in range(0,len(nom),1):
    n[i] = n2[-i-1]

for i in range(0,len(prenom),1):
    p[i] = p2[-i-1]

print("".join(n))
print("".join(p))
