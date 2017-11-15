//10 Points
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M; vector< pair <int, int> > v;

    cin>>N>>M;
    int p1,q1;
    int cnt=0;

    int A[M][N][N];
    int cn=0;

    for(int i=0; i<M; i++)
     {
         for(int j = 0; j<N; j++)
        {   for(int k =0; k<N; k++)
              {
                  cin>>A[i][j][k];
              }

        }

     }

    int mn =A[0][0][0];

    for(int i=0; i<M; i++)
    {
        for(int j = 0; j<N; j++)
        {
            for(int k =0; k<N; k++)
            {
                if(A[i][j][k] < mn)
                    mn=A[i][j][k];
            }

        }

    }



    for(int i=0; i<M; i++)
    {   for(int j = 0; j<N; j++)
         {   for(int k =0; k<N; k++)
            {
                if(A[i][j][k]>mn)
                {

                    p1=j+1; q1=k+1;
                    v.push_back(make_pair(p1,q1)); ++cn;
                }
            }
        }
    }

    sort(v.begin(), v.end());

    vector< pair <int, int> > v1;

    v1.push_back(make_pair(v[0].first,v[0].second));
    ++cnt;

    for(int i = 1; i<cn; i++)
    {
        int j=i-1;
        if(v[i].first != v[j].first || v[i].second != v[j].second)
        {
            v1.push_back(make_pair(v[i].first, v[i].second)); ++cnt;
        }
    }

    if(cnt<M)
    {
        for(int i=cnt-1; i>=0; i--)
        {
            cout<<v1[i].first<<" "<<v1[i].second<<endl;
        }
       cout<<-1<<" "<<-1<<endl;
    }
    else
    {
        for(int i=cnt-1; i>=cnt-M; i--)
        {
            cout<<v1[i].first<<" "<<v1[i].second<<endl;
        }
    }

    return 0;
}
