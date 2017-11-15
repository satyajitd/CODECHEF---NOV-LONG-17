#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int n=0, r=0;
        cin>>n>>r;

        vector <int> v;
        int rating;

        for(int i=0; i<n; i++)
        {
            cin>>rating;
            v.push_back(rating);
        }

        int ub = *max_element( v.begin(), v.end() );
        int lb = *min_element( v.begin(), v.end() );

        int flag = 0;

        for(int i=0; i<n-1; i++)
        {
            if(v[i] > r)
            {
                if(v[i] <= ub)
                    ub=v[i];
                else
                {
                    flag=1; break;
                }
            }
            else
            {
                if(v[i] >= lb)
                    lb = v[i];
                else
                {
                    flag=1; break;
                }
            }
        }
        if(flag == 0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
