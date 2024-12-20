x=int(input("Introduceti numarul:"))
ok=0
y=x+1
while ok==0:
    prim=1
    if y==0 or y==1: prim=0
    for d in range (2,y):
        if y%d==0: 
            prim=0
            break
    if prim==1: ok=1
    else: y=y+1
print (y)
# 2 - 3
# 0 - 2
# 4 - 5
# 13 - 17