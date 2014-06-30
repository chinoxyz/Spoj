#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	int r,c;
	scanf("%d",&t);		
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&r,&c);
		int arr[r][c];
		int ans[r][c];

		for(int j=0;j<r;j++)
		{
			for(int k=0;k<c;k++)
			{
				scanf("%d",*(arr+j)+k);
			}
		}


		ans[r-1][c-1] = 1;
		for(int j=c-2;j>=0;j--)
		{
			ans[r-1][j] = max(1,ans[r-1][j+1] - arr[r-1][j]);
		}
		for(int k=r-2;k>=0;k--)
		{
			ans[k][c-1] = max(1,ans[k+1][c-1] - arr[k][c-1]);
		}

		for(int j=r-2;j>=0;j--)
		{
			for(int k=c-2;k>=0;k--)
			{
				ans[j][k] = max(1,min(ans[j+1][k] - arr[j][k],ans[j][k+1] - arr[j][k]));
			}
		}

		printf("%d\n",ans[0][0]);
	}
	return 0;
}