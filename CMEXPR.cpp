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



#define MAXL 256

struct Node
{
    int left,right;
    char ch;
};

char infix[MAXL],ans[MAXL],postfix[MAXL];
Node tree[MAXL];
int idx;

inline bool is_operator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

inline bool is_variable(char ch)
{
    return (ch>='a' && ch<='z');
}


inline int precedence(char ch)
{
    switch(ch)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        default : return 3;

    }
}

void get_postfix(char *post,int &plen,char *inp,int ilen)
{
    plen=0;

    stack<int> st;
    int i;

    REP(i,ilen)
    {
        if(is_variable(inp[i]))
        {
            post[plen++]=inp[i];
        }
        else if(inp[i]=='(')
        {
            st.push('(');
        }
        else if(inp[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                post[plen++]=st.top();
                st.pop();
            }

            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && st.top()!='(' && precedence(st.top())>=precedence(inp[i]))
            {
                post[plen++]=st.top();
                st.pop();
            }
            st.push(inp[i]);
        }
    }

    while(!st.empty())
        {
            post[plen++]=st.top();
            st.pop();
        }
}

int build_tree(char *post,int len)
{
    stack<int> st;

    int idl,idr,nodes;
    int i;

    REP(i,len)
    {
        if(islower(post[i]))
        {
            tree[nodes].left=tree[nodes].right=-1;
            tree[nodes].ch=post[i];
            st.push(nodes++);
        }
        else
        {
            idr=st.top();
            st.pop();
            idl=st.top();
            st.pop();

            tree[nodes].left=idl;
            tree[nodes].right=idr;
            tree[nodes].ch=post[i];
            st.push(nodes++);
        }
    }


    return st.top();
}


void print_tree(int root) {
	bool br;
	char ch;
	switch(tree[root].ch) {
		case '+':
			print_tree(tree[root].left);
			ans[idx++] = '+';
			print_tree(tree[root].right);
		break;
		case '-':
			print_tree(tree[root].left);
			ans[idx++] = '-';
			ch = tree[tree[root].right].ch;
			br = (ch=='+') | (ch=='-');
			if(br) ans[idx++] = '(';
			print_tree(tree[root].right);
			if(br) ans[idx++] = ')';
		break;
		case '*':
			ch = tree[tree[root].left].ch;
			br = (ch=='+') | (ch=='-');
			if(br) ans[idx++] = '(';
			print_tree(tree[root].left);
			if(br) ans[idx++] = ')';
			ans[idx++] = '*';
			ch = tree[tree[root].right].ch;
			br = (ch=='+') | (ch=='-');
			if(br) ans[idx++] = '(';
			print_tree(tree[root].right);
			if(br) ans[idx++] = ')';
		break;
		case '/':
			ch = tree[tree[root].left].ch;
			br = (ch=='+') | (ch=='-');
			if(br) ans[idx++] = '(';
			print_tree(tree[root].left);
			if(br) ans[idx++] = ')';
			ans[idx++] = '/';
			ch = tree[tree[root].right].ch;
			br = !islower(ch);
			if(br) ans[idx++] = '(';
			print_tree(tree[root].right);
			if(br) ans[idx++] = ')';
		break;
		default : ans[idx++] = tree[root].ch;
	}
}



int main()
{
    freopen("Text/CMEXPR.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int ilen,plen,root;

    while(cases--)
    {
        scanf("%s",infix);
        ilen=strlen(infix);

        get_postfix(postfix,plen,infix,ilen);
        root=build_tree(postfix,plen);
        idx=0;
        print_tree(root);
        ans[idx]=0;
        puts(ans);
    }

    return 0;
}



