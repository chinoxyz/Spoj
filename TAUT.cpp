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
#define u64 unsigned i64


int len,pos[26];
char arr[1000];
bool val[26];
stack<bool> st;

int main() {

	freopen("Text/TAUT.txt","r",stdin);

	int cases,n;
	bool l,r;

	scanf("%d",&cases);

	while(cases--)
    {
        scanf("%s",arr);
        len=strlen(arr);
        n=0;

        for(int i=0;i<26;++i)
        {
            pos[i]=-1;
        }


            for(int i=0;i<len;++i)
            {
                if(arr[i]>='a' && pos[arr[i]-'a']==-1)
                {
                    pos[arr[i]-'a']=n++;
                }
            }


        bool ans=true;

        for(int i=0;i<(1<<n);++i)
        {
            for(int j=0;j<n;++j)
            {
                val[j]=(1<<j)&i;
            }

            for(int j=len-1;j>=0;--j)
            {
                if(arr[j]>='a')
                {
                    st.push(val[pos[arr[j]-'a']]);
                }
                else if(arr[j]=='D')
                {
                    l=st.top();
                    st.pop();
                    r=st.top();
                    st.pop();
                    st.push(l|r);
                }
                else if(arr[j]=='C')
                {
                    l=st.top();
                    st.pop();
                    r=st.top();
                    st.pop();
                    st.push(l&r);
                }
                else if(arr[j]=='N')
                {
                    l=st.top();
                    st.pop();
                    st.push(!l);
                }
                else if(arr[j]=='I')
                {
                    l=st.top();
                    st.pop();
                    r=st.top();
                    st.pop();
                    st.push(!(l & (!r)));
                }
                else if(arr[j]=='E')
                {
                    l=st.top();
                    st.pop();
                    r=st.top();
                    st.pop();
                    st.push(l==r);
                }
            }

            ans=st.top();
            st.pop();
            if(!ans)
            {
                ans=false;
                break;
            }

        }

        if(ans)
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
