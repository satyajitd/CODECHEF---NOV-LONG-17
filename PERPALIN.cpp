#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int n, p;
        cin>>n>>p;
        if(p == 1 || p ==  2 || (n%p)!=0)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        char s[p];
        s[0]='a'; s[p-1]='a';
        for(int j=1; j<p-1; j++)
            s[j]='b';
        for(int i=0; i<(n/p); i++)
        {
            for(int x=0; x<p; x++)
                cout<<s[x];
        }
        cout<<endl;
    }
    return 0;
}
