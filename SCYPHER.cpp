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


#define MAXW 26
#define MAXM 100
#define MAXN 266

bool greaterr[MAXW][MAXW];
int nxt[MAXW],candidate_ct;
char ans[MAXW],msg[MAXN];
char word1[MAXM],word2[MAXM],*p1,*p2;

int ch,a,k,w1,top_ct,x,y;


void solve()
{
    MSET(greaterr,0);
    MSET(ans,0);
    MSET(msg,0);

    scanf("%d %d",&a,&k);

    w1=1;
    scanf("%s",word1);
    --k;

    while(k--)
    {
        if(w1)
        {
            scanf("%s",word2);
            p1=word1;
            p2=word2;
            w1=0;
        }
        else
        {
            scanf("%s",word1);
            p1=word2;
            p2=word1;
            w1=1;
        }

        while(*p1 && *p2 && *p1==*p2)
        {
            ++p1;
            ++p2;
        }

        if(*p1 && *p2)
        {
            greaterr[(*p1)-'a'][(*p2)-'a']=1;
        }
    }

    while(getchar()!='\n');

    gets(msg);
    //cout<<msg<<endl;

    ch=0;
    top_ct=0;

    for(int i=0;i<a;++i)
    {
        x=1;
        for(int j=0;j<a;++j)
        {
            if(greaterr[j][i])
            {
                x=0;
                break;
            }
        }
        if(x)
        {
            nxt[0]=i;
            candidate_ct=1;
            top_ct++;
        }
    }

    if(top_ct!=1)
    {
        //printf("DD\n");
        printf( "Message cannot be decrypted.\n");
        return;
    }

    do
    {
        top_ct=0;

        for(int i=0;i<candidate_ct;++i)
        {
            x=1;
            for(int j=0;j<a;++j)
            {
                if(greaterr[j][nxt[i]])
                {
                    x=0;
                    break;
                }
            }

            if(x)
            {
                y=nxt[i];
                ++top_ct;
            }
        }

        if(top_ct!=1)
        {
            printf( "Message cannot be decrypted.\n");
            return;
        }

        ans[y]=ch++;
        candidate_ct=0;

        for(int j=0;j<a;++j)
        {
            if(greaterr[y][j])
            {
                nxt[candidate_ct++]=j;
                greaterr[y][j]=0;
            }
        }
    }
    while(top_ct && ch<a);

    if(ch==a)
    {
        for(p1=msg;*p1;++p1)
        {
            if(*p1>='a' && *p1<='z')
            {
                *p1='a'+ans[(*p1)-'a'];
            }
        }

        printf("%s\n",msg);
    }
    else
    {
        printf( "Message cannot be decrypted.\n");
    }
}


int main()
{
    freopen("Text/SCYPHER.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        solve();
    }



    return 0;
}

