//20 Points

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void addEdge(int u, int v, list<int> *adj)
{
    adj[u].push_back(v);

}

void DFSUtil(int v, int *k, int bank[], bool visited[], list<int> *adj, vector<int> *ar, int bk)
{
    visited[v-1] = true;
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i -1])
        {
            bk += bank[*i];
           // cout<< bk<<endl;
            if(bk>0)
            {
                ar->push_back(*i);
                ++(*k);
            }

            DFSUtil(*i,k,bank,visited, adj, ar,bk);
            bk-=bank[*i];
        }

    }
}

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int  N=0, M=0;
        cin>>N>>M;
        int u,v;
        list<int> adj[N+1];

        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            addEdge(u,v, adj);
            addEdge(v,u, adj);
        }
        int bank[N+1]={0};
        int ty=0, c=0;
        while(M--)
        {
            cin>>ty>>c;
            if(ty==1)
                ++bank[c];
            if(ty==2)
            {
                vector<int> ar; int k=0; int bk=bank[c];
                if(bk>0)
                {
                    ar.push_back(c); ++k;
                }
                bool *visited = new bool[N];
                for (int i = 0; i < N; i++)
                    visited[i] = false;
                DFSUtil(c,&k,bank,visited, adj, &ar,bk);

                if(k<2)
                    cout<<-1;
                else
                {
                    sort(ar.begin(), ar.end(), greater<int>());
                    cout<<ar[1];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
