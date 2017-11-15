#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        if(p==1)
        {
            cout<<n<<" ";
            for(int i=0; i<n; i++)
                cout<<'a';
        }
        if(p>2)
        {
            if(n<=p)
            {
                char ch = 'a';
                cout<<1<<" ";
                for(int i=0; i<n; i++)
                    cout<<ch++;
            }
            if(n>p)
            {
                char ch = 'a';
                cout<<1<<" ";
                int k=0;
                for(int i=1; i<=n; i++)
                {
                    cout<<ch++; ++k;
                    if(k==p)
                    {
                        k=0; ch='a';
                    }
                }

            }
        }
        if(p == 2)
        {
            if( n == 1)
                cout<<1<<" "<<'a';
            if(n>=2 && n<=6)
            {
                int mid = n/2;
                cout<<n-mid<<" ";
                for(int i=0; i<mid; i++)
                    cout<<'a';
                for(int i= mid; i<n; i++)
                    cout<<'b';
            }
            if(n == 7)
            {
                cout<<3<<" "<<"aaababb";
            }
            if(n==8)
            {
                cout<<3<<" "<<"aaababbb";
            }
            if(n>=9)
            {
                char ch[]="aababb";
                int k=-1;
                cout<<4<<" ";
                for(int i=0; i<n; i++)
                {
                    cout<<ch[++k];
                    if(k==5)
                        k=-1;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
