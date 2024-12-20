def printeaza_meniu():
    print ("1. Citeste o lista de numere intregi. ")
    print ("2. Gaseste o secventa de lungime maxima care contine cel mult trei valori distincte. ")
    print ("3. Gaseste o secventa de lungime maxima care sa fie sub forma de munte (valorile cresc pana la un moment dat si apoi descresc). ")
    print ("4. Gaseste o secventa de lungime maxima in care diferentele x[j+1]-x[j] si x[j+2]-x[j+1] au semne contrare. ")
    print ("5. Iesire din aplicatie. ")

def citeste_lista():
    lst=[]
    n=int(input("Introduceti numarul de elemente, apoi elementele listei: "))
    for i in range (0,n): #citim de la tastatura lista de la 0 la n-1
        lst.append(int(input()))
    return n,lst

def optiunea_2(n,lst):
    v=[]
    max=0
    for i in range(0,n):
        v.clear() #formam o lista noua pentru a verifica proprietatea ceruta
        v.append(lst[i]) #adaugam in aceasta primul element din secventa
        for j in range(i+1,n):
            if lst[j] not in v: #daca elementul curent nu este in v inseamna ca este diferit de elementele din secventa curenta si il adaugam
                v.append(lst[j])
            if (len(v)>3): #daca avem mai mult de 3 elemente in v inseamna ca secventa nu respecta proprietatea ceruta
                j=j-1 #ne intoarcem cu o pozitie in urma
                break #oprim executia pentru secventa curenta
        if j-i+1>max: #daca lungimea curenta este mai mare decat maximul anterior
            max=j-i+1
            poz=i
    return lst[poz:poz+max]

def optiunea_3(lst):
#sens = 0 inseamna ca numerele sunt in ordine crescatoare, sens = 1 inseamna ca numerele sunt in ordine descrescatoare
    sens=0
    nr=1
    poz=0
    max=0
    i=0
    while (i<len(lst)-1):
        if lst[i]<lst[i+1] and sens== 1: #daca am trecut la o noua secventa candidat
            if nr>max: 
                max=nr
                poz=i
                sens=0 #ne intoarcem la sensul crescator
                nr=1 #initializam nr cu 1
                i=i-1 #ne intoarcem cu o pozitie pentru a cauta o noua secventa
        elif lst[i]<lst[i+1] and sens==0 or lst[i]>lst[i+1] and sens== 1: #daca respecta proprietatile cerute, incrementam nr
            nr=nr+1
        elif lst[i]>lst[i+1] and sens==0: #trecem de la crescator la descrescator
            nr=nr+1
            sens=1 #schimbam sensul secventei
        i=i+1
    if nr>max and sens == 1: #actualizam daca este cazul max, poz (doar daca secventa maxima este pe ultimele pozitii, iar sens=1)
        max=nr
        poz=i
    return lst[poz-max+1:poz+1]

def optiunea_4(lst):
    nr=1
    poz=0
    max=0
    for i in range(0,len(lst)-2):
        if lst[i+1]-lst[i]>0 and lst[i+2]-lst[i+1]<0 or lst[i+1]-lst[i]<0 and lst[i+2]-lst[i+1]>0: #verificam daca respecta conditia ceruta
            nr=nr+1 #in caz afirmativ, crestem numarul de elemente din secventa
        else:
            if nr>max: #cand am trecut la o alta secventa, comparam nr cu max
                max=nr #schimbam lungimea maxima
                poz=i  #si pozitia de unde incepe secventa
                nr=1   #resetam nr la 1
    if nr>max:
        max=nr #schimbam max si poz daca este cazul
        poz=i+1 #doar daca ultima secventa este cea cautata
    if (max!=1): return lst[poz-max+1:poz+2] #daca avem mai mult de un element, returnam lista 
    else: return lst[poz] #daca nu, returnam doar elementul

def test_optiunea_2():
    assert optiunea_2(9, [39, 39, 23, 23, 23, 41, 42, 42, 42]) == [23,23,23,41,42,42,42]
    assert optiunea_2(8, [39, 23, 23, 39, 41, 42, 42 ,42]) == [39, 23, 23, 39, 41]
    assert optiunea_2(9, [1, 2, 3, 1, 2, 3, 1, 2, 3]) == [1, 2, 3, 1, 2, 3, 1, 2, 3]
    assert optiunea_2(13, [41, 41, 20, 14, 14, 20, 41, 52, 52, 41, 20, 41, 41]) == [20, 41, 52, 52, 41, 20, 41, 41]

def test_optiunea_3():
    assert optiunea_3([5, 7, 0, 1, 2, 3, 4, 5, 4, 3, 2, 7, 8]) == [0, 1, 2, 3, 4, 5, 4, 3, 2]
    assert optiunea_3([1, 3, 5, 4, 2]) == [1, 3, 5, 4, 2]
    assert optiunea_3([1, 3, 4, 5, 2, 0 , 6, 7, 8, 9, 10, 11, 5]) == [0, 6, 7, 8, 9, 10, 11, 5]
    assert optiunea_3([1, 2, 1, 0]) == [1, 2, 1, 0]

def test_optiunea_4():
    assert optiunea_4([1, 2, 3, 4, 5, 6]) == 1
    assert optiunea_4([6, 10, 8, 9, 11, 13]) == [6, 10, 8, 9]
    assert optiunea_4([12, 2, 4, 3, 5, 2, 10, 8]) == [12, 2, 4, 3, 5, 2, 10, 8]
    assert optiunea_4([5, 7, 4, 6, 8]) == [5, 7, 4, 6]

def start():
    lst=[]
    new_lst=[]
    n=0
    while True:
        printeaza_meniu()
        print("Lista curenta este:")
        print(lst)
        optiune = int(input("Optiunea aleasa este:"))
        if optiune == 1:
            n, lst = citeste_lista() #citim lista de la tastatura
        elif optiune == 2:
            print("Secventa de lungime maxima care contine cel mult trei valori distincte este:")
            new_lst = optiunea_2(n,lst) #calculam secventa maxima care sa contina maxim 3 numere diferite
            print(new_lst) #afisam secventa obtinuta 
        elif optiune == 3:
            print("Secventa de lungime maxima care sa fie sub forma de munte (valorile cresc pana la un moment dat si apoi descresc) este:")
            new_lst = optiunea_3(lst) #calculam secventa maxima de tip munte
            print(new_lst)
        elif optiune == 4:
            print("Secventa de lungime maxima in care diferentele x[j+1]-x[j] si x[j+2]-x[j+1] au semne contrare este")
            new_lst = optiunea_4(lst) #calculam secventa maxima care sa respecte conditia ceruta
            print(new_lst)
        elif optiune == 5: 
            break #oprim executia programului

test_optiunea_2()
test_optiunea_3()
test_optiunea_4()
start()
