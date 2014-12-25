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

#define MAXQ 512

static int h[MAXQ][MAXQ] ;
static int fx[MAXQ][MAXQ],fy[MAXQ][MAXQ] ;
static int f[MAXQ][MAXQ] ;

int dx[]={0,0,1,-1} ;
int dy[]={1,-1,0,0} ;

int bx,by,lx,ly ;

int p,q ;

int solveX(int x1,int y1,int x2,int y2)
{
  int z,edge ;
  int dx,z1,z2,dz,ry,t,y,dy,ry2 ;

  dx=x2-x1 ; z1=h[x1-1][y1-1] ; z2=h[x2-1][y2-1] ;
  dz=z2-z1 ; dy=y2-y1 ;
  z=(2*z1+1)*dx+dz ;
  y=2*dx*y1+dy ;

  for(t=x1;t<x2;t++)
  {
    ry=(y+dx-(dy>0))/(2*dx) ;
    ry2=(y+dx-(1-(dy>0)))/(2*dx) ;

    if (z<h[t-1][ry-1]*2*dx)
	{
		return 0 ;
	}
    if (z<h[t][ry2-1]*2*dx)
	{
		return 0 ;
	}

    z+=2*dz ; y+=2*dy ;

  }
  return 1;
}

int solveY(int x1,int y1,int x2,int y2)
{
  int z,edge ;
  int dy,z1,z2,dz,rx,t,x,dx,rx2 ;

  dy=y2-y1 ; z1=h[x1-1][y1-1] ; z2=h[x2-1][y2-1] ;
  dz=z2-z1 ; dx=x2-x1 ;
  z=(2*z1+1)*dy+dz ;
  x=2*dy*x1+dx ;
  for (t=y1;t<y2;t++)
  {
    rx=(x+dy-(dx>0))/(2*dy) ;
    rx2=(x+dy-(1-(dx>0)))/(2*dy) ;

    if (z<h[rx-1][t-1]*2*dy)
	{
		return 0 ;
	}
    if (z<h[rx2-1][t]*2*dy)
	{
		return 0 ;
	}
    z+=2*dz ; x+=2*dx ;
  }
  return 1 ;
}

int isVisible(int x1,int y1,int x2,int y2)
{
  int l ;

  if (x1<x2)
  {
	l=solveX(x1,y1,x2,y2) ;
  }
  else if (x2<x1)
  {
	l=solveX(x2,y2,x1,y1) ;
  }
  else
  {
	l=1 ;
  }

  if (l)
  {
    if (y1<y2)
	{
		l=solveY(x1,y1,x2,y2) ;
	}
    else if (y2<y1)
	{
		l=solveY(x2,y2,x1,y1) ;
	}
  }
  return l ;
}

int checkk(int x1,int y1,int x2,int y2,int xi,int yi, int xt,int yt)
{
  int l ;

  if (h[x2-1][y2-1]>h[x1-1][y1-1]+1)
  {
	return 0 ;
  }
  if (h[x2-1][y2-1]<h[x1-1][y1-1]-3)
  {
	return 0 ;
  }

  return isVisible(x2,y2,xi,yi) || isVisible(x2,y2,xt,yt) ;
}

int bfs(int x1,int y1,int x2,int y2)
{
  int i,j,k ;

  for (i=0;i<p;i++)
  {
	for (j=0;j<q;j++)
	{
		fx[i][j]=fy[i][j]=-1 ;
		f[i][j]=-1 ;
	}
  }

  if (x1==x2 && y1==y2)
  {
	return 0 ;
  }

  bx=lx=x1 ; by=ly=y1 ;
  f[x1-1][y1-1]=0 ;

  while(true)
  {
    for (k=0;k<4;k++)
	{
      i=bx+dx[k] ; j=by+dy[k] ;

      if (i<1 || i>p || j<1 || j>q)
	  {
		continue ;
	  }

      if (f[i-1][j-1]>-1)
	  {
		continue ;
	  }
      if (!checkk(bx,by,i,j,x1,y1,x2,y2))
	  {
		continue ;
	  }

      f[i-1][j-1]=f[bx-1][by-1]+1 ;

	  if (i==x2 && j==y2)
	  {
		return f[i-1][j-1] ;
	  }

      fx[lx-1][ly-1]=i  ; fy[lx-1][ly-1]=j  ; lx=i ; ly=j ;

	}

    i=fx[bx-1][by-1] ; j=fy[bx-1][by-1] ; bx=i ; by=j ;

	if (bx==-1)
	{
		return -1 ;
	}
  }
}


void solve()
{
  int s,i,j,x1,x2,y1,y2 ;
  int l ;

  scanf("%d %d",&p,&q) ;

  for(i=0;i<p;i++)
  {
    for (j=0;j<q;j++)
	{
		scanf("%d",&h[i][j]) ;
	}
  }

  scanf("%d %d %d %d",&x1,&y1,&x2,&y2) ;

  l=bfs(x1,y1,x2,y2) ;

  if (l<0)
  {
	printf("Mission impossible!\n") ;
  }
  else
  {
	printf("The shortest path is %d steps long.\n",l) ;
  }
}

int main()
{
  freopen("Text/DIRVS.txt","r",stdin);

  int cases ;
  scanf("%d",&cases) ;
  while(cases--)
  {
	solve() ;
  }

  return 0 ;
}

