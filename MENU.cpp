    #include <iostream>
    #include <algorithm>
    #include<string.h>
    #include <list>
    #include<queue>
    #include<vector>
    #include <cmath>
    #define mp make_pair
    using namespace std;
    #define pii pair<int,int>
    #define x first
    #define y second
    #define INF 999999999
    #define N 35
    int poss[51][101][22],prevv[51][101][22],a[51],b[51];
    double dp[51][101][22];
    int main()
    {
		int i,j,k,l,m,n,c;double v;

		freopen("Text/MENU.txt","r",stdin);

		while(~scanf("%d%d%d",&l,&n,&m))
		{
			if(n==0&&m==0&&l==0)break;
			double mx=INF;int tt,ss;
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&a[i],&b[i]);
				if(mx>a[i])
				{
					mx=a[i];
				}
			}

			if(mx*l>m)
			{
				printf("0.0\n");
				continue;
			}

			mx=0;
			for(i=0;i<n;i++)
			for(j=0;j<=m;j++)
			for(k=0;k<=l;k++)
			{
				dp[i][j][k]=prevv[i][j][k]=0;
			}

			memset(poss,0,sizeof(poss));
			for(i=0;i<n;i++)
			{
				poss[i][m][0]=1;
			}

			for(c=m;c>=0;c--)for(k=0;k<l;k++)
			for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			if(poss[i][c][k]&&c>=a[j])
			{
				v=b[j];
				if(i==j)
				{
					if(k)v/=2;

					if(k>1&&prevv[i][c][k]==i)v=0;
				}

				if(dp[j][c-a[j]][k+1]<dp[i][c][k]+v)
				{
					dp[j][c-a[j]][k+1]=dp[i][c][k]+v;
					if(k)prevv[j][c-a[j]][k+1]=i;

					poss[j][c-a[j]][k+1]=1;
				}
				if(k+1==l&&poss[j][c-a[j]][k+1])
				if(mx<dp[j][c-a[j]][k+1])
				{
					mx=dp[j][c-a[j]][k+1];ss=j;tt=c-a[j];
				}
			}

			printf("%.1lf\n",mx);
			if(mx)
			{
				while(l)
				{
					printf("%d ",ss+1);
					j=a[ss];
					ss=prevv[ss][tt][l--];tt+=j;
				}
				puts("");
			}
		}

		return 0;
    }
