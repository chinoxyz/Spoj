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


#define MAXL 1000005


int len,m,cs,bestt,ct=0;

map<char,int> mp;


int main(){

    freopen("Text/BROKEN.txt","r",stdin);

    int j;
    //string str;
    char str[MAXL];

    while(true)
    {
        scanf("%d",&m);
        //cin>>m;

        if(m==0)
        {
            break;
        }

        //printf("MM\t%d\n",m);

        cs=0;
        ct=1;
        bestt=1;
        mp.clear();
        //scanf("%s",str);
        //gets(str);
        scanf(" %[^\n]s",str);
        //cin>>str;
        //printf("%s\n",str.c_str());
        //printf("%s\n",str);
        //cout<<"DD"<<str<<"DD"<<endl;
        len=strlen(str);
        //len=str.length();
        ++mp[str[0]];

        for(int i=1;i<len;++i)
        {

/*
            printf("%d\t%d\t%d\n",cs,i-1,bestt);
            for(int k=cs;k<i;++k)
            {
                printf("%c",str[k]);
            }
            printf("\n");

*/
            if(mp[str[i]]>0)
            {
                ++mp[str[i]];
                bestt=max(bestt,i-cs+1);
                continue;
            }

            if(ct<m)
            {
                ++ct;
                ++mp[str[i]];
                bestt=max(bestt,i-cs+1);
                continue;
            }

            ++mp[str[i]];

            for(j=cs;j<i;++j)
            {
                --mp[str[j]];
                if(mp[str[j]]==0)
                {
                    break;
                }
            }
            cs=j+1;
            bestt=max(bestt,i-cs+1);
        }

        printf("%d\n",bestt);

    }


    return 0;
}
