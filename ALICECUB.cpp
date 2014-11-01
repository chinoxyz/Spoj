#include <bits/stdc++.h>

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

#define MAXN 1<<16

int distt[MAXN];
int adjj[16][16]=
{
 { 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
 { 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
 { 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
 { 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
 { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
 { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
 { 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
 { 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
 { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0 },
 { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 },
 { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
 { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
 { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
 { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
 { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0 },
};

void flipp(int &a,int b)
{
    a^=(1<<b);
}


void pre_process()
{
    MSET(distt,-1);

    int st=(1<<8)-1;
    distt[st]=0;
    queue<PII > q;
    q.push(MP(st,0));
    int i,j,b1,b2;
    int ts;
    int d;

    while(!q.empty())
    {
        st=q.front().first;
        d=q.front().second;
        q.pop();

        for(i=0;i<16;++i)
        {
            for(j=i+1;j<16;++j)
            {
                if(!adjj[i][j])
                {
                    continue;
                }
                ts=st;

                b1=ts&(1<<(16-i-1));
                b2=ts&(1<<(16-j-1));
                if(b1==b2)
                {
                    continue;
                }

                flipp(ts,16-i-1);
                flipp(ts,16-j-1);

                if(distt[ts]==-1 && d<3)
                {
                    distt[ts]=d+1;
                    q.push(MP(ts,d+1));
                }
            }
        }
    }
}

int main()
{
    freopen("Text/ALICECUB.txt","r",stdin);

    pre_process();

    int cases;
    int ti,st;
    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        st=0;
        for(int i=0;i<16;++i)
        {
            scanf("%d",&ti);
            if(ti)
            {
                st=st | ( 1<< (16-i-1));
            }
        }

        if(distt[st]==-1)
        {
            printf("Case #%d: more\n",t);
        }
        else
        {
            printf("Case #%d: %d\n",t,distt[st]);
        }
    }



    return 0;
}

