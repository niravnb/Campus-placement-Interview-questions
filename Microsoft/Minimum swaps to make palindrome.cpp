// Minimum swaps to make palindrome

#include<bits/stdc++.h>
using namespace std;

int c[256];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin>>s) {
        if(s[0]=='0') break;
        memset(c,0,sizeof(c));
        int ns=s.length();
        for(int i=0;i<ns;i++) {
            c[(int)s[i]]++;
        }
        int d=0;
        for(int i=0;i<256;i++) {
            d+=c[i]%2;
        }
        if(d>1) {
            printf("Impossible\n");
            continue;
        }
        d=0;
        for(int i=0;i<ns/2;i++) 
        {
            if(s[i]!=s[ns-i-1])
            {
                int j,k;
                for(j=i+1;s[j]!=s[ns-i-1];j++);
                for(k=ns-2-i;s[k]!=s[i];k--);
                d+=min(j-i,ns-i-1-k);
                if(j-i<=ns-i-k-1)
                {
                    char a=s[j];
                    for(int l=j;l>i;l--) 
                    {
                        s[l]=s[l-1];
                    }
                    s[i]=a;
                } 
                else 
                {
                    char a=s[k];
                    for(int l=k;l<ns-i-1;l++)
                    {
                        s[l]=s[l+1];
                    }
                    s[ns-i-1]=a;
                }
            }
        }
        //cout<<d<<" "<<s<<endl;
        cout<<s<<endl;
        cout<<d<<endl;
    }
    return 0;
}
