import sys

sys.stdin=open("Text/NDIVPHI.txt")



primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
        61,67,71,73,79,83,89,97,101,103]

for x in range(20):
    n =input()

    prod = 1

    for p in primes:
        tmp = prod*p

        if tmp > n:
            break

        prod = tmp

    print prod

