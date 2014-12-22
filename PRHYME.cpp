#include<bits/stdc++.h>
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


#define MAXN 250005
#define MAXL 55
#define MAXC 26
#define INF 99999999


struct trie
{
    int en,nen1,nen2;
    struct trie *arr[MAXC];
};

trie *root;
map<string,int> mp;
int numm;

void init(trie * &tmp)
{
    tmp=new trie;
    tmp->en=tmp->nen1=tmp->nen2=INF;
    for(int i=0;i<MAXC;++i)
    {
        tmp->arr[i]=NULL;
    }
}


void insertt(string s,int pos)
{
    //cout<<s<<endl;
    trie *prs=root;
    trie *tmp;

    int lenn=s.length();
    int curr;

    for(int i=0;i<lenn;++i)
    {
        curr=s[i]-'a';
        if(prs->arr[curr]==NULL)
        {

            init(tmp);
            prs->arr[curr]=tmp;
        }
        else
        {
            //printf("DD\n");
        }
        prs=prs->arr[curr];
        if(i==(lenn-1))
        {
            prs->en=min(prs->en,pos);
        }
        else
        {
            if(prs->nen1!=INF)
            {
                if(prs->nen2==INF)
                {
                    prs->nen2=pos;
                }
            }
            else
            {
                prs->nen1=pos;
            }

        }
    }
}

char buff[MAXL];
string arr[MAXN];
int n;

int solve(string s)
{
    int lenn=s.length();
    int ret=INF;
    trie *prs=root;
    //printf("%d\n",lenn);

    for(int i=0;i<lenn;++i)
    {
        prs=prs->arr[s[i]-'a'];

        if(prs==NULL)
        {
            break;
        }
        if(i==lenn-1)
        {

            if( (prs->nen1) !=INF)
            {
                ret=prs->nen1;
            }

        }
        else
        {
            int x[3];
            x[0]=prs->en;
            x[1]=prs->nen1;
            x[2]=prs->nen2;
            sort(x,x+3);
            //printf("NNNN\t%d\n",numm);

            for(int j=0;j<3;++j)
            {
                if(x[j]!=numm && x[j]!=INF)
                {
                    ret=x[j];
                    break;
                }
            }

            //printf("DD\t%d\n",ret);
        }
    }



    return ret;
}

void MAIN()
{
    n=0;
    string s;
    int i;
    while(true)
    {
        init(root);
        cin.getline(buff,MAXL-1);
        if(strlen(buff)==0)
        {
            break;
        }
        ++n;
        s=buff;
        arr[n]=s;
    }

    sort(arr+1,arr+n+1);

    for(i=1;i<=n;++i)
    {
        s=arr[i];
        mp[s]=i;
        reverse(s.begin(),s.end());
        insertt(s,i);

    }

    while(true)
    {
        cin.getline(buff,MAXL-1);
        if(strlen(buff)==0)
        {
            break;
        }
        s=buff;
        numm=mp[s];
        reverse(s.begin(),s.end());
        //cout<<s<<endl;
        //printf("%d\n",solve(s));
        cout<<arr[solve(s)]<<endl;
    }

}


int main() {

	freopen("Text/PRHYME.txt","r",stdin);

    MAIN();

	return 0;
}
