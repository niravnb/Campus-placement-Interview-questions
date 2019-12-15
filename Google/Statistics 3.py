from statistics import mean
m={}
while(1):
    try:
        a,b=input().split()
    except EOFError:
        break
    #print(a,b)
    b=int(b)
    
    try:
        m[a].append(b)
    except KeyError:
        m[a]=[b]
#print(m)

for i in m:
    m[i].sort()
    
#print(m)    

for i in m:
    print(i,m[i][0],m[i][-1],int(mean(m[i])))