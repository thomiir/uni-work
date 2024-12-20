import datetime
ziua_nasterii=int(input("Introduceti ziua nasterii:"))
luna_nasterii=int(input("Introduceti luna nasterii:"))
anul_nasterii=int(input("Introduceti anul nasterii:"))
data_curenta=datetime.datetime.now()
ziua_curenta=data_curenta.day
luna_curenta=data_curenta.month
anul_curent=data_curenta.year
ok=1
if anul_nasterii > anul_curent: 
    print("Data invalida")
    ok=0
elif anul_nasterii==anul_curent: 
    if luna_nasterii > luna_curenta:
        print("Data invalida")
        ok=0
    elif luna_nasterii==luna_curenta:
        if ziua_nasterii>ziua_curenta: 
            print("Data invalida")
            ok=0
if luna_nasterii<1 or luna_nasterii>12:
    print ("Data invalida")
    ok=0
if luna_nasterii==2: 
    if anul_nasterii%4==0 and anul_nasterii%100!=0 or anul_nasterii%400==0:
        if ziua_nasterii>29:
            print("Data invalida")
            ok=0
    elif ziua_nasterii>28:
        print("Data invalida")
        ok=0
elif luna_nasterii==1 or luna_nasterii==3 or luna_nasterii==5 or luna_nasterii==7 or luna_nasterii==8 or luna_nasterii==10 or luna_nasterii==12: 
    if ziua_nasterii>31: 
        print("Data invalida")
        ok=0
elif ziua_nasterii>30:
    print("Data invalida")
    ok=0

if ok==1:
    numar_zile=0
    if anul_curent>anul_nasterii:
        for i in range(anul_nasterii+1,anul_curent): #adunam zilele anilor [anul_nasterii+1,anul_curent-1], sunt ani "plini"
            if i%4==0 and i%100!=0 or i%400==0: numar_zile+=366
            else: numar_zile+=365
        for i in range(1,luna_curenta): #adunam lunile "pline"
            if i==2:
                if anul_curent%4==0 and anul_curent%100!=0 or anul_curent%400==0: numar_zile+=29
                else: numar_zile+=28
            elif i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12: numar_zile+=31
            else: numar_zile+=30
        numar_zile+=ziua_curenta #adunam zilele din luna curenta
        for i in range(luna_nasterii+1,13): #adunam lunile "pline"
            if i==2:
                if anul_nasterii%4==0 and anul_nasterii%100!=0 or anul_nasterii%400==0: numar_zile+=29
                else: numar_zile+=28
            elif i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12: numar_zile+=31
            else: numar_zile+=30
        if luna_nasterii==2: #adunam zilele ramase in luna nasterii
            if anul_nasterii%4==0 and anul_nasterii%100!=0 or anul_nasterii%400==0: numar_zile+=29-ziua_nasterii
            else: numar_zile+=28-ziua_nasterii
        elif luna_nasterii==1 or luna_nasterii==3 or luna_nasterii==5 or luna_nasterii==7 or luna_nasterii==8 or luna_nasterii==10 or luna_nasterii==12: numar_zile+=31-ziua_nasterii
        else: numar_zile+=30-ziua_nasterii
    else:
        for i in range (luna_nasterii+1,luna_curenta): #adunam lunile pline
            if i==2:
                if anul_nasterii%4==0 and anul_nasterii%100!=0 or anul_nasterii%400==0: numar_zile+=29
                else: numar_zile+=28
            elif i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12: numar_zile+=31
            else: numar_zile+=30
        if luna_curenta>luna_nasterii:
            if luna_nasterii==2: #adunam zilele ramase in luna nasterii
                if anul_nasterii%4==0 and anul_nasterii%100!=0 or anul_nasterii%400==0: numar_zile+=29-ziua_nasterii
                else: numar_zile+=28-ziua_nasterii
            elif luna_nasterii==1 or luna_nasterii==3 or luna_nasterii==5 or luna_nasterii==7 or luna_nasterii==8 or luna_nasterii==10 or luna_nasterii==12: numar_zile+=31-ziua_nasterii
            else: numar_zile+=30-ziua_nasterii
            numar_zile+=ziua_curenta
        else: numar_zile+=ziua_curenta-ziua_nasterii
    print(numar_zile)
#10/10/2024 - Data invalida
#29/02/2023 - Data invalida
#22/04/2004 - 7110
#04/06/2023 - 128