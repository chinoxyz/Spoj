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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 33
char arr[MAXN][MAXN];
int n,m;
int xm,xz,ym,yz;

int cx,cy,px,py;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char ans;



bool isValid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return 0;
    }
    return 1;
}

bool toLeft(int px,int py,int cx,int cy)
{
    if((py-cy)==1)
    {
        return 1;
    }

    return 0;
}

bool toRight(int px,int py,int cx,int cy)
{
    if((py-cy)==-1)
    {
        return 1;
    }

    return 0;
}

bool toDown(int px,int py,int cx,int cy)
{
    if((px-cx)==-1)
    {
        return 1;
    }

    return 0;
}



bool checkUp(int nx,int ny)
{
    if(arr[nx][ny]=='+' || arr[nx][ny]=='|' || arr[nx][ny]=='1' || arr[nx][ny]=='4')
    {
        return 1;
    }
    return 0;
}

bool checkRight(int nx,int ny)
{
    if(arr[nx][ny]=='+' || arr[nx][ny]=='-' || arr[nx][ny]=='3' || arr[nx][ny]=='4')
    {
        return 1;
    }
    return 0;
}

bool checkDown(int nx,int ny)
{
    if(arr[nx][ny]=='+' || arr[nx][ny]=='|' || arr[nx][ny]=='2' || arr[nx][ny]=='3')
    {
        return 1;
    }
    return 0;
}


bool checkLeft(int nx,int ny)
{
    if(arr[nx][ny]=='+' || arr[nx][ny]=='-' || arr[nx][ny]=='1' || arr[nx][ny]=='2')
    {
        return 1;
    }
    return 0;
}



bool solve1(int px,int py,int cx,int cy)
{
    int i,nx,ny;

    for(i=0;i<4;++i)
    {
        nx=cx+dx[i];
        ny=cy+dy[i];

        if(!isValid(nx,ny) || arr[nx][ny]=='.')
        {
            return 0;
        }
    }



    nx=cx-1;
    ny=cy;

    if(!checkUp(nx,ny))
    {
        return 0;
    }





    nx=cx;
    ny=cy+1;

    if(!checkRight(nx,ny))
    {
        return 0;
    }









    nx=cx+1;
    ny=cy;

    if(!checkDown(nx,ny))
    {
        return 0;
    }











    nx=cx;
    ny=cy-1;

    if(!checkLeft(nx,ny))
    {
        return 0;
    }

    ans='+';
    return 1;
}


bool solve2(int px,int py,int cx,int cy)
{
    if(py!=cy)
    {
        return 0;
    }

    int i,nx,ny;

    nx=cx-1;
    ny=cy;

    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }

    nx=cx+1;
    ny=cy;
    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }



    nx=cx-1;
    ny=cy;

    if(nx==px && ny==py)
    {
        nx=cx+1;
        ny=cy;

        if(!checkDown(nx,ny))
        {
            return 0;
        }
    }
    else
    {
        if(!checkUp(nx,ny))
        {
            return 0;
        }
    }


    ans='|';
    return 1;
}



bool solve3(int px,int py,int cx,int cy)
{
    if(px!=cx)
    {
        return 0;
    }
    int i,nx,ny;

    nx=cx;
    ny=cy-1;

    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }

    nx=cx;
    ny=cy+1;
    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }



    nx=cx;
    ny=cy-1;

    if(nx==px && ny==py)
    {
        nx=cx;
        ny=cy+1;

        if(!checkRight(nx,ny))
        {
            return 0;
        }
    }
    else
    {
        if(!checkLeft(nx,ny))
        {
            return 0;
        }
    }


    ans='-';
    return 1;
}




bool solve4(int px,int py,int cx,int cy)
{
    if(px-cx==-1)
    {
        return 0;
    }

    if(py-cy==-1)
    {
        return 0;
    }

    int i,nx,ny;

    nx=cx+1;
    ny=cy;

    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }

    nx=cx;
    ny=cy+1;
    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }



    nx=cx+1;
    ny=cy;

    if(nx==px && ny==py)
    {
        nx=cx;
        ny=cy+1;

        if(!checkRight(nx,ny))
        {
            return 0;
        }
    }
    else
    {
        if(!checkDown(nx,ny))
        {
            return 0;
        }
    }


    ans='1';
    return 1;
}





bool solve5(int px,int py,int cx,int cy)
{
    if(px-cx==1)
    {
        return 0;
    }

    if(py-cy==-1)
    {
        return 0;
    }

    int i,nx,ny;

    nx=cx-1;
    ny=cy;

    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }

    nx=cx;
    ny=cy+1;
    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }



    nx=cx-1;
    ny=cy;

    if(nx==px && ny==py)
    {
        nx=cx;
        ny=cy+1;

        if(!checkRight(nx,ny))
        {
            return 0;
        }
    }
    else
    {
        if(!checkUp(nx,ny))
        {
            return 0;
        }
    }


    ans='2';
    return 1;
}






bool solve6(int px,int py,int cx,int cy)
{
    if(px-cx==1)
    {
        return 0;
    }

    if(py-cy==1)
    {
        return 0;
    }

    int i,nx,ny;

    nx=cx-1;
    ny=cy;

    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }

    nx=cx;
    ny=cy-1;
    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }



    nx=cx-1;
    ny=cy;

    if(nx==px && ny==py)
    {
        nx=cx;
        ny=cy-1;

        if(!checkLeft(nx,ny))
        {
            return 0;
        }
    }
    else
    {
        if(!checkUp(nx,ny))
        {
            return 0;
        }
    }


    ans='3';
    return 1;
}



bool solve7(int px,int py,int cx,int cy)
{
    if(px-cx==-1)
    {
        return 0;
    }

    if(py-cy==1)
    {
        return 0;
    }

    int i,nx,ny;

    nx=cx;
    ny=cy-1;

    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }

    nx=cx+1;
    ny=cy;
    if(!isValid(nx,ny) || arr[nx][ny]=='.')
    {
        return 0;
    }



    nx=cx;
    ny=cy-1;

    if(nx==px && ny==py)
    {
        nx=cx+1;
        ny=cy;

        if(!checkDown(nx,ny))
        {
            return 0;
        }
    }
    else
    {
        if(!checkLeft(nx,ny))
        {
            return 0;
        }
    }


    ans='4';
    return 1;
}




void MAIN()
{

    //scanf("%d %d",&n,&m);
    cin>>n>>m;
    int i,j;
    bool foundd=0;

    int nx,ny;
    int tx,ty;

    for(i=0;i<n;++i)
    {
        //scanf("%s",&arr[i]);
        cin>>arr[i];
        for(j=0;j<m;++j)
        {
            if(arr[i][j]=='M')
            {
                xm=i;
                ym=j;
                //arr[i][j]='+';
            }
            else if(arr[i][j]=='Z')
            {
                xz=i;
                yz=j;
                //arr[i][j]='+';
            }
        }
    }

    px=xm;
    py=ym;

    for(i=0;i<4;++i)
    {
        nx=xm+dx[i];
        ny=ym+dy[i];

        if(!isValid(nx,ny))
        {
            continue;
        }

        if(!(arr[nx][ny]=='.'))
        {
            if(i==0)
            {
                if(checkUp(nx,ny))
                {
                    cx=nx;
                    cy=ny;
                    foundd=1;
                    break;
                }
            }
            else if(i==1)
            {
                if(checkRight(nx,ny))
                {
                    cx=nx;
                    cy=ny;
                    foundd=1;
                    break;
                }
            }
            else if(i==2)
            {
                if(checkDown(nx,ny))
                {
                    cx=nx;
                    cy=ny;
                    foundd=1;
                    break;
                }
            }
            else
            {
                if(checkLeft(nx,ny))
                {
                    cx=nx;
                    cy=ny;
                    foundd=1;
                    break;
                }
            }

        }
    }

    if(foundd)
    {
        while(!(arr[cx][cy]=='.'))
        {
            if(toLeft(px,py,cx,cy))
            {
                if(arr[cx][cy]=='-' || arr[cx][cy]=='+')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx;
                    cy=cy-1;
                    px=tx;
                    py=ty;
                }
                else if(arr[cx][cy]=='1')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx+1;
                    cy=cy;
                    px=tx;
                    py=ty;
                }
                else
                {
                    tx=cx;
                    ty=cy;
                    cx=cx-1;
                    cy=cy;
                    px=tx;
                    py=ty;
                }
            }
            else if(toRight(px,py,cx,cy))
            {
                if(arr[cx][cy]=='-' || arr[cx][cy]=='+')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx;
                    cy=cy+1;
                    px=tx;
                    py=ty;
                }
                else if(arr[cx][cy]=='3')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx-1;
                    cy=cy;
                    px=tx;
                    py=ty;
                }
                else
                {
                    tx=cx;
                    ty=cy;
                    cx=cx+1;
                    cy=cy;
                    px=tx;
                    py=ty;
                }
            }
            else if(toDown(px,py,cx,cy))
            {
                if(arr[cx][cy]=='|' || arr[cx][cy]=='+')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx+1;
                    cy=cy;
                    px=tx;
                    py=ty;
                }
                else if(arr[cx][cy]=='2')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx;
                    cy=cy+1;
                    px=tx;
                    py=ty;
                }
                else
                {
                    tx=cx;
                    ty=cy;
                    cx=cx;
                    cy=cy-1;
                    px=tx;
                    py=ty;
                }
            }
            else
            {
                if(arr[cx][cy]=='|' || arr[cx][cy]=='+')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx-1;
                    cy=cy;
                    px=tx;
                    py=ty;
                }
                else if(arr[cx][cy]=='1')
                {
                    tx=cx;
                    ty=cy;
                    cx=cx;
                    cy=cy+1;
                    px=tx;
                    py=ty;
                }
                else
                {
                    tx=cx;
                    ty=cy;
                    cx=cx;
                    cy=cy-1;
                    px=tx;
                    py=ty;
                }
            }
        }


        if(!solve1(px,py,cx,cy))
        {
            if(!solve2(px,py,cx,cy))
            {
                if(!solve3(px,py,cx,cy))
                {
                    if(!solve4(px,py,cx,cy))
                    {
                        if(!solve5(px,py,cx,cy))
                        {
                            if(!solve6(px,py,cx,cy))
                            {
                                solve7(px,py,cx,cy);
                            }
                        }
                    }
                }
            }
        }

    }
    else
    {
        for(i=0;i<4;++i)
        {
            nx=px+dx[i];
            ny=py+dy[i];

            if(!isValid(nx,ny))
            {
                continue;
            }

            if(arr[nx][ny]!='.')
            {
                continue;
            }

            cx=nx;
            cy=ny;

            if(solve1(px,py,cx,cy))
            {
                break;
            }
            else if(solve2(px,py,cx,cy))
            {
                break;
            }
            else if(solve3(px,py,cx,cy))
            {
                break;
            }
            else if(solve4(px,py,cx,cy))
            {
                break;
            }
            else if(solve5(px,py,cx,cy))
            {
                break;
            }
            else if(solve6(px,py,cx,cy))
            {
                break;
            }
            else if(solve7(px,py,cx,cy))
            {
                break;
            }
        }
    }

    printf("%d %d %c\n",cx+1,cy+1,ans);


}

int main()
{
	freopen("Text/CIJEVI.txt","r",stdin);

    MAIN();

	return 0;
}
