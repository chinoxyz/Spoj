import sys

sys.stdin=open("Text/CRAZYSK.txt")

for _ in input()*[0]:
    a=list(long(i) for i in raw_input().split())
    n,m,cnt,tmp=a[0],a[1],a[0],0
    ans=n+n/(m-1)
    if(n%(m-1)==0):
        ans-=1
    print(ans)
