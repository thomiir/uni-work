a = int(input("scrie prima valoare:"))
b = int(input("scrie a doua valoare:"))
if b==0:
    print("imposibil")
else:
    r = a % b
    while r!=0:
        a = b
        b = r
        r = a % b
    print (b)
        
