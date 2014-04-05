#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include<string>
#include <set>

using namespace std;
#define i64 long long

#define pii pair< int,int >
#define piii pair< pii,int >
#define ff first.first
#define fs first.second

int n;

class comp {
    public:
        inline bool operator() (const piii &a, const piii &b) const {
        return a.ff < b.ff && a.fs < b.fs;
    }
};

set<piii,comp> wall;
set<piii,comp>::iterator st,en,it;

bitset<40003> bb;
int countt;

int main()
{
    //freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/POSTERS.txt","r",stdin);

    int i,j,cases,x1,y1,x2,y2,x3,y3,x,y,z1,z2,z3;

    scanf("%d",&cases);

    while(cases--)
    {
        countt=0;
        bb.reset();
        wall.clear();
        scanf("%d",&n);

        scanf("%d %d",&x,&y);
        wall.insert(piii(pii(x,y),1));

        for(i=2;i<=n;++i)
        {
            x1=y1=x2=y2=x3=y3=z1=z2=z3=-1;

            scanf("%d %d",&x,&y);

            st=wall.upper_bound(piii(pii(x,x),0));
            en=wall.upper_bound(piii(pii(y,y),0));
            z2=i;


            if(en==wall.begin())
            {
                x2=x;
                y2=y;
            }
            else if(st==wall.begin())
            {
                --en;

                x2=x;
                y2=y;

                if(en->fs>y)
                {
                    x3=en->fs+1;
                    y3=y;
                    z3=en->second;
                }

                wall.erase(st,en);
            }
            else if(st==en)
            {
                --st;
                --en;

                if(st->ff<x && st->fs>y)
                {
                    x1=st->ff;
                    y1=x-1;
                    z1=st->second;

                    x2=x;
                    y2=y;

                    x3=y+1;
                    y3=st->fs;
                    z3=st->second;

                    ++en;
                    wall.erase(st,en);
                }
                else if(st->ff==x && st->fs<=y)
                {
                    x2=x;
                    y2=y;

                    ++en;
                    wall.erase(st,en);
                }
                else if(st->ff<x && st->fs<=y)
                {
                    x1=st->ff;
                    y1=x-1;
                    z1=st->second;

                    x2=x;
                    y2=y;

                    ++en;
                    wall.erase(st,en);
                }
                else if(st->ff==x && st->fs>y)
                {
                    x2=x;
                    y2=y;

                    x3=y+1;
                    y3=st->fs;
                    z3=st->second;

                    ++en;
                    wall.erase(st,en);
                }
            }
            else
            {
                --st;
                --en;

                if(st->fs >=x)
                {
                    if(st->ff<x)
                    {
                        x1=st->ff;
                        y1=x-1;
                        z1=st->second;
                    }

                    x2=x;
                    y2=y;
                }
                else
                {
                    x2=x;
                    y2=y;
                }

                if(en->ff==y && en->fs==y)
                {
                    ++en;
                    wall.erase(st,en);
                }
                else if(en->ff==y && en->fs>y)
                {
                    x3=y+1;
                    y3=en->fs;
                    z3=en->second;

                    ++en;
                    wall.erase(st,en);
                }
                else if(en->ff<y && en->fs<=y)
                {
                    ++en;
                    wall.erase(st,en);
                }
                else if(en->ff<y && en->fs>y)
                {
                    x3=y+1;
                    y3=en->fs;
                    z3=en->second;

                    ++en;
                    wall.erase(st,en);
                }

            }



            if(x1!=-1 && y1!=-1)
            {
                wall.insert(piii(pii(x1,y1),z1));
            }

            if(x2!=-1 && y2!=-1)
            {
                wall.insert(piii(pii(x2,y2),z2));
            }

            if(x3!=-1 && y3!=-1)
            {
                wall.insert(piii(pii(x3,y3),z3));
            }

        }

        for(it=wall.begin();it!=wall.end();++it)
        {
            x=it->second;
            if(!bb.test(x))
            {
                ++countt;
                bb.set(x);
            }
        }

        printf("%d\n",countt);
    }
    return 0;
}

