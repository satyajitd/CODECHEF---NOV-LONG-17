//25 Points

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int N=0, Q=0, L=0, R=0;
    cin>>N>>Q>>L>>R;

    int ar[N];
    for(int i=0; i<N; i++)
        ar[i]=0;

    while(Q--)
    {
        int qn=0, x=0, y=0;
        cin>>qn>>x>>y;

        if(qn == 1)
        {
            ar[x-1] = y;
        }

        if(qn == 2)
        {
            int sum =0, elm=0;
            int les=0, k=0;
            int diff=0, conti=0;

            int pos[y-x+1]={-1};

            /* for(int i=0; i<N; i++)
                cout<<ar[i]<<" ";
            cout<<endl; */

            for(int j = x-1; j<y; j++)
            {
                if( ar[j] > R)
                {
                    pos[k] = j;
                    ++k;
                }
            }

            /*for(int j = 0; j<k; j++)
                cout<<ar[pos[j]]<<" ";
            cout<<endl; */

            int index=0,last;
            for(ll i = x-1; i<y; i++)
            {
                if(i != pos[index])
                {
                    ++elm;
                    if(ar[i] < L)
                        ++les;
                    if(ar[i]<L &&  ar[i+1]<L && i+1<=y-1)
                        ++conti;
                    else
                    {
                        diff+= ((conti) * (conti +1))/2;
                        conti =0;
                    }

                }
                else
                {
                    sum += (((elm)*(elm+1))/2);
                    sum-=diff; sum-=les;
                    elm=0; les=0; diff=0;
                    if(index < k-1)
                        ++index;
                }
                last =(((elm)*(elm+1))/2) - diff -les;
            }
            cout<<sum + last<<endl;
        }
    }
    return 0;
}
