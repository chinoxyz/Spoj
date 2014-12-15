#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 11


VI finn;
int fs;
int n;
bool fl[MAXN];
int tarr[MAXN];
int ct=0;

void solve(VI ans)
{
    sort(ans.begin(),ans.end());
    int sz=ans.size();

    if(sz>=fs)
    {
        return;
    }

    if(ct==n)
    {
        fs=sz;
        finn=ans;

        return;
    }

    int i,j,k,pos,ti;
    VI tv;
    VI::iterator it;


    for(i=0;i<n;++i)
    {
        if(fl[i])
        {
            continue;
        }
        ++ct;
        for(j=0;j<sz;++j)
        {
            fl[i]=0;

            pos=101;
            ti=tarr[i]+ans[j];
            for(k=j+1;k<sz;++k)
            {
                if(ans[k]==ti)
                {
                    fl[i]=1;
                    break;
                }
                else if(ans[k]>ti)
                {
                    pos=k;
                    break;
                }
            }

            if(fl[i])
            {
                tv=ans;
                solve(tv);
            }
            else
            {
                tv=ans;
                fl[i]=1;
                if(pos<101)
                {
                    it=lower_bound(tv.begin(),tv.end(),ti);
                    tv.insert(it,ti);
                    solve(tv);
                }
                else
                {
                    tv.PB(ti);
                    solve(tv);
                }

            }

            fl[i]=0;

        }

        --ct;
    }


    for(i=0;i<n;++i)
    {
        if(fl[i])
        {
            continue;
        }
        ++ct;
        for(j=1;j<sz;++j)
        {
            fl[i]=0;

            pos=101;
            ti=ans[j]-tarr[i];
            if(ti<0)
            {
                continue;
            }

            for(k=0;k<j;++k)
            {
                if(ans[k]==ti)
                {
                    fl[i]=1;
                    break;
                }
                else if(ans[k]>ti)
                {
                    pos=k;
                    break;
                }
            }

            if(fl[i])
            {
                tv=ans;
                solve(tv);
            }
            else
            {
                tv=ans;
                fl[i]=1;
                if(pos<101)
                {
                    it=lower_bound(tv.begin(),tv.end(),ti);
                    tv.insert(it,ti);
                    solve(tv);
                }
                else
                {
                    tv.PB(ti);
                    solve(tv);
                }

            }

            fl[i]=0;

        }

        --ct;
    }
}


int main()
{
    freopen("Text/EUROPEAN.txt","r",stdin);

    int cases;
    int ti;
    VI ans;

    scanf("%d",&cases);
    int i;

    for(int t=1;t<=cases;++t)
    {
        ct=0;
        MSET(fl,0);
        fs=111;
        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%d",&ti);
            tarr[i]=ti;
        }

        ans.clear();
        finn.clear();
        ans.PB(0);
        sort(tarr,tarr+n);

        solve(ans);

        printf("Scenario #%d\n",t);
        printf("%d:",finn.size());

        for(i=0;i<finn.size();++i)
        {
            printf(" %d",finn[i]);
        }

        printf("\n\n");


    }




    return 0;
}

