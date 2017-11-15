//20 Points
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void EE(int a, int b, int& x, int& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}

int inverse(int a, int m)
{
    int x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

void prefixproduct(ll *arr, ll n, ll *prefixprod,ll *modinv,ll p)
{
    prefixprod[0] = arr[0]%p;
    modinv[0] = inverse(prefixprod[0],p);
    for (ll i = 1; i < n; i++)
        {prefixprod[i] = ((prefixprod[i-1]%p)*(arr[i]%p))%p;
        modinv[i] = inverse(prefixprod[i], p);
        }
}


int main()
{
    ll t=0;
	cin>>t;
    while(t--)
    {
        ll N, P, Q,qry=0;
        ll result;
        ll x=0;
        cin>>N>>P>>Q;
        ll Li, Ri;
        ll ar[N];
        ll prefixprod[N];
        ll modinv[N];
        for(ll i =0; i<N; i++)
            cin>>ar[i];
        prefixproduct(ar, N, prefixprod,modinv, P);
        ll k = Q/64 + 2;
        ll B[k];
        for(ll j=0; j<k; j++)
            cin>>B[j];
        ll L,R;
        while(qry<Q)
        {
        	result=1;
        if(qry%64 == 0)
        {
            L = (B[qry/64] + x) % N;
            R = (B[qry/64 + 1] +x) %N;
            if(L>R)
            {
                ll temp = L;
                L=R;
                R=temp;
            }
            result = (prefixprod[R]*modinv[L-1])%P;
            if(L==0)
                result=prefixprod[R];
            if( prefixprod[R] == 0)
            	result = 0;

        }
        else
        {
            L = (Li +x ) % N;
            R = (Ri + x)% N;
            if(L>R)
            {
                ll temp = L;
                L=R;
                R=temp;
            }
            result = (prefixprod[R]*modinv[L-1])%P;
            if(L==0)
                result=prefixprod[R];
            if( prefixprod[R] == 0)
            	result = 0;

        }
        Li=L;
        Ri=R;
        ++qry;
        x =result;
        x=(x+1)%P;

    }
    cout << x << "\n";

    }
}
