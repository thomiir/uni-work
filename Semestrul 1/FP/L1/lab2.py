x = int(input("scrie o valoare:"))
if x==0 or x==1:
    print("nu este prim")
else:
    ok = 1
    for d in range (2,x):
        if x%d==0:
            print ("nu este prim")
            ok = 0
            break
    if ok==1:
        print ("este prim")
