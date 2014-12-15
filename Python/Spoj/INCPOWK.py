import sys
import math

sys.stdin=open("Text/INCPOWK.txt")

cases = input()

while cases:
    cases-=1
    line=raw_input()
    k, n = line.split()
    k= long(k)
    ti2=1
    n = long(n)
    ret = 0
    ti=long(math.log(n,2)+1)
    for i in range(0,ti):
        if(n & 1<<i):
            ret +=ti2

        ti2*=k
    print(ret)
