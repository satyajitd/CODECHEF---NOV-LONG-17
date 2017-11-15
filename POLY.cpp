//30 Points
//Reference for Convex Hull Trick : Codeforces.com
#include<bits/stdc++.h>
#include<set>
#include<cmath>
#include<algorithm>

#define ll long long int

using namespace std;


class Dconvexhull
{
    typedef long long co_eff;
    typedef long long co_ord;
    typedef long long setval;

    private:

    struct Line
    {
        co_eff a, b;
        double xLeft;

        enum Type {line, maxqry, minqry} type;
        co_ord val;

        explicit Line(co_eff a1=0, co_eff b1=0) : a(a1), b(b1), xLeft(-INFINITY), type(Type::line), val(0) {}

        setval value_at(co_ord x) const
        { return a*x+b; }

        friend bool areParallel(const Line& l1, const Line& l2)
        { return l1.a==l2.a; }

        friend double intersectX(const Line& l1, const Line& l2)
        { return areParallel(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }

        bool operator<(const Line& l2) const
        {
            if (l2.type == line)
                return this->a     < l2.a;
            if (l2.type == maxqry)
                return this->xLeft < l2.val;
            if (l2.type == minqry)
                return this->xLeft > l2.val;
        }
    };

    private:

        bool isMax;
        std::set<Line>  hull;

    private:

    bool hasPrev(std::set<Line>::iterator it)
    { return it!=hull.begin(); }

    bool hasNext(std::set<Line>::iterator it)
    { return it!=hull.end() && std::next(it)!=hull.end(); }

    bool irrelvt(const Line& l1, const Line& l2, const Line& l3)
    { return intersectX(l1,l3) <= intersectX(l1,l2); }

    bool irrelvt(std::set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
               && (    isMax && irrelvt(*std::prev(it), *it, *std::next(it))
                       || !isMax && irrelvt(*std::next(it), *it, *std::prev(it)) );
    }

    std::set<Line>::iterator update_l_b(std::set<Line>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;

        double val = intersectX(*it, isMax?*std::prev(it):*std::next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }

public:

    explicit Dconvexhull(bool isMax): isMax(isMax) {}

    void add_Line(co_eff a, co_eff b)
    {
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = hull.erase(it);
            else
                return;
        }

        it = hull.insert(it, l3);
        if (irrelvt(it)) { hull.erase(it); return; }

        while (hasPrev(it) && irrelvt(std::prev(it))) hull.erase(std::prev(it));
        while (hasNext(it) && irrelvt(std::next(it))) hull.erase(std::next(it));

        it = update_l_b(it);
        if (hasPrev(it))
            update_l_b(std::prev(it));
        if (hasNext(it))
            update_l_b(std::next(it));
    }

    setval Min_val_at(co_ord x) const
    {
        Line q;
        q.val = x;
        q.type = isMax ? Line::Type::maxqry : Line::Type::minqry;
        //cout << isMax << "\n";
        auto bestLine = hull.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->value_at(x);
    }
};

int main()
{
    ll t=0;
    cin >>t;
    while(t--)
    {
        ll N,qry,Q;
        Dconvexhull h(false);
        cin>>N;
        ll count=0;
        ll arr[N][4];
        for(ll i=0; i<N; i++)
        {
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
            h.add_Line(arr[i][1],arr[i][0]);

            if(arr[i][2]==0 && arr[i][3]==0)
                ++count;
        }
        cin>>Q;
        while(Q--)
        {
            cin>>qry;
            /* When count == n then we get co-efficients such that they will become straight lines.
            So using Dconvexhull we can find minimise the value. */
            if(count==N)
            {
                cout<<h.Min_val_at(qry)<<endl;
            }
            else
            {
                ll result =0, min=0;
                for(int i=0; i<N; i++)
                {
                    result= arr[i][0] + (arr[i][1] *qry) +(arr[i][2]*(qry*qry)) + (arr[i][3] * (qry*qry*qry));
                    if(i == 0)
                        min = result;
                    else if(result<min)
                        min = result;
                }
                cout<<min<<endl;
            }
        }
    }
    return 0;
}
