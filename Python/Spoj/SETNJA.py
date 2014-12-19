import sys
import math

sys.stdin=open("Text/SETNJA.txt")

if __name__ == '__main__':
    x = raw_input().strip()
    ans = 1
    ct = 1

    for c in x:
        leftt = 2*ans
        if c=='R':
            ans = leftt + ct
        elif c=='L':
            ans = leftt
        elif c=='P':
            ans = ans
        elif c=='*':
            ans = (leftt +leftt + ct +ans)
            ct *= 3

    print ans
