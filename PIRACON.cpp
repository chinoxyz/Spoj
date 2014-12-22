#include<bits/stdc++.h>
using namespace std;

void MAIN()
{
    int cases;
    double n;
    scanf("%d",&cases);

    for(int t=1;t<=cases;++t)
    {
        cin>>n;
        printf("Pyramid E. Nro# %d: %.0f\n",t,n*(2*n*n+6*n-5)/3);
        printf("Tringus: %.0f\n",2*((n*n)-n));
    }
}


int main()
{
	freopen("Text/PIRACON.txt","r",stdin);

	MAIN();

	return 0;
}
