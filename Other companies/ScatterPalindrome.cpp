input string = s
ans = 0
n = s.length

for i=1:n
    A[i]=A[i-1]^(1<<(s[i-1]-97))

for i=1:n
    for j=i;n
        x=A[j]^A[i-1]
        if (x&(x-1)) == 0    //if x is a power of 2 or not 
            ans++;
        endif
    endfor
endfor
