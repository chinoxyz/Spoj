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

#define MAXN 10006

char arr[MAXN];

int len;


int leftt[MAXN],rightt[MAXN],val[MAXN];


void solve()
{
    queue<int> q;
    stack<int> st;
    int x,y;

    for(int i=0;i<len;++i)
    {

        if(islower(arr[i]))
        {
            st.push(i);
            leftt[i]=rightt[i]=-1;
        }
        else
        {
            //printf("DD\n");
            y=st.top();
            st.pop();
            x=st.top();
            st.pop();
            st.push(i);
            leftt[i]=x;
            rightt[i]=y;
        }


    }



    string ret="";


    q.push(len-1);
    int pos;

    while(!q.empty())
    {
        pos=q.front();
        q.pop();
        ret+=arr[pos];

        if(leftt[pos]!=-1)
        {
            q.push(leftt[pos]);
        }

        if(rightt[pos]!=-1)
        {
            q.push(rightt[pos]);
        }

    }

    reverse(ret.begin(),ret.end());

    cout<<ret<<endl;

}


int main()
{
    freopen("Text/EXPRESS.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%s",arr);
        len=strlen(arr);
        //printf("%s\n",arr);

        solve();
    }



    return 0;
}
