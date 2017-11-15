#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len = s.length();
        char ch[len]; int pos[len];
        int ac=0, bc=0;
        int k=-1;
        for(int i=0; i<len; i++)
        {
            if(s[i] != '.')
            {
                ch[++k]=s[i];
                pos[k]=i;
                if(s[i]=='A')
                    ++ac;
                else
                    ++bc;
            }
        }

        for(int i = 0; i<k; i++)
        {
            if(ch[i]=='A' && ch[i+1]== 'A')
            {
                ac = ac + (pos[i+1] - pos[i]);
                ac-=1;
            }
        }
        for(int i = 0; i<k; i++)
        {
            if(ch[i]=='B' && ch[i+1]== 'B')
            {
                bc = bc + (pos[i+1] - pos[i]);
                bc-=1;
            }
        }

        cout<<ac<<" "<<bc<<endl;
    }
    return 0;
}
