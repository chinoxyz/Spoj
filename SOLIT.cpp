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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXN 8

int dx[]={-1,0,1,0,-2,0,2,0};
int dy[]={0,1,0,-1,0,2,0,-2};
bool poss;

bool st[MAXN][MAXN],en[MAXN][MAXN],curr[MAXN][MAXN];

bool is_valid(int x,int y)
{
    if(x<0 || y<0 || x>=MAXN || y>=MAXN)
    {
        return false;
    }

    return true;
}

u64 encode(bool arr[MAXN][MAXN])
{
    u64 ret=0ULL;

    for(int i=0;i<MAXN;++i)
    {
        for(int j=0;j<MAXN;++j)
        {
            if(arr[i][j])
            {
                ret|=(1ULL<<(i*MAXN+j));
            }
        }
    }

    return ret;
}


void decode(u64 conn,bool ret[MAXN][MAXN])
{
    for(int i=0;i<MAXN;++i)
    {
        for(int j=0;j<MAXN;++j)
        {
            ret[i][j]=0;
            if( conn & (1ULL << (i*8+j)))
            {
                ret[i][j]=1;
            }
        }
    }
}

void meet_in_middle(u64 conn,set<u64> &vis)
{
    queue<u64> q;
    queue<int> distt;

    q.push(conn);
    distt.push(0);
    int d;

    while(!q.empty())
    {
        conn=q.front();
        d=distt.front();

        q.pop();
        distt.pop();

        if(d==4)
        {
            continue;
        }

        decode(conn,curr);

        for(int i=0;i<MAXN;++i)
        {
            for(int j=0;j<MAXN;++j)
            {
                if(!curr[i][j])
                {
                    continue;
                }

                for(int k=0;k<4;++k)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];

                    if(!is_valid(nx,ny))
                    {
                        continue;
                    }

                    if(curr[nx][ny])
                    {
                        nx=i+dx[k+4];
                        ny=j+dy[k+4];

                        if(!is_valid(nx,ny) || curr[nx][ny])
                        {
                            continue;
                        }
                    }

                    curr[nx][ny]=1;
                    curr[i][j]=0;

                    u64 maskk=encode(curr);

                    if(vis.count(maskk)==0)
                    {
                        vis.insert(maskk);
                        q.push(maskk);
                        distt.push(d+1);
                    }

                    curr[nx][ny]=0;
                    curr[i][j]=1;
                }
            }
        }
    }
}




int main()
{
    freopen("Text/SOLIT.txt","r",stdin);
    int cases;
    int x,y;
    scanf("%d",&cases);
    set<u64>::iterator it;

    while(cases--)
    {
        MSET(st,0);
        MSET(en,0);

        for(int i=0;i<4;++i)
        {
            scanf("%d %d",&x,&y);
            --x;
            --y;
            st[x][y]=1;
        }

        for(int i=0;i<4;++i)
        {
            scanf("%d %d",&x,&y);
            --x;
            --y;
            en[x][y]=1;
        }

        set<u64> forr;
        set<u64> backk;

        u64 conn1=encode(st);
        u64 conn2=encode(en);

        forr.insert(conn1);
        backk.insert(conn2);

        meet_in_middle(conn1,forr);
        meet_in_middle(conn2,backk);

        poss=false;

        it=forr.begin();

        while(it!=forr.end())
        {
            if(backk.count(*it))
            {
                poss=true;
                break;
            }
            ++it;
        }

        if(poss)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
