// wrote using help from the editorial for CSUBQ on CodeChef.
// find_answer function and assert statements are required to get rid of TLE in one case.
#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

struct node
{
    ll noos, len, lenol, lenor;
    node(ll value = 0)
    {
        assert(value == 0 || value == 1);
        len =1;
        noos = lenol = lenor =value;
    }
    static node no_value()
    {
        return node(0);
    }
};

node mergenode ( node a, node b)
{
    node res;

    res.len = a.len + b.len;
    res.noos = a.noos + b.noos + (a.lenor * b.lenol);

    res.lenol = a.lenol;
    if(a.len == a.lenol)
        res.lenol+= b.lenol;


    res.lenor = b.lenor;
    if(b.len == b.lenor)
        res.lenor+= a.lenor;

    return res;
}

class segmenttree
{
    public:

        ll n;
        vector<node>tree;
        ll bound;
        segmenttree(ll n, ll bound): n(n), bound(bound), tree(4*n)
        {
            for(ll i=0; i<n; i++)
                change(i,0);
        }

        void change(ll index, ll new_val)
        {
            Change(0, 0, n-1, index, new_val<bound? 1:0);
        }

        ll find_max_in_range(ll l, ll r)
        {
            node req = find_node(0, 0, n-1, l, r);
            return req.noos;
        }

    private:

        void Change(ll t, ll l, ll r, ll index, ll value)
        {
            if( l == r)
                return void(tree[t] = node(value));
            ll m = (l+r)/2;

            if(index<=m)
                Change(t*2 +1, l, m, index, value);
            else
                Change(t*2 +2, m+1, r, index, value);

            tree[t] = mergenode(tree[t*2 +1], tree[t*2 +2]);
        }

        node find_node(ll t, ll l, ll r, ll x, ll y)
        {
            if( y< l || x >r)
                return node::no_value();
            if (l >= x && r <= y)
                return tree[t];

            ll m = (l + r) / 2;
            return mergenode(find_node(t*2 + 1, l, m, x, y), find_node(t*2 + 2, m + 1, r, x, y));
        }
};

void find_answer()
{
    ll N, Q, L, R;
    cin>>N>>Q>>L>>R;

    segmenttree A(N, L), B(N, R + 1);

    while(Q--)
    {
        ll qtype;
        cin>>qtype;

        if (qtype == 1) {
            ll index, value;
            cin>>index>>value;
            index--;

            A.change(index, value);
            B.change(index, value);
        }
        else
        {
            ll l, r;
            cin>>l>>r;
            l--; r--;

            ll answer = B.find_max_in_range(l, r) - A.find_max_in_range(l, r);
            assert(answer >= 0);
            cout<<answer<<endl;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    find_answer();

    return 0;
}
