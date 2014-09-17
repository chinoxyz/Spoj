import sys

cases = int(sys.stdin.readline())

results = []

MOD = 1298074214633706835075030044377087L

curr_sum = 0L
two = 1L
for i in range(501):
	curr_sum += two
	two *= 2
	if curr_sum >= MOD:
		curr_sum %= MOD
	results.append(str(curr_sum) + '\n')

for x in range(cases):
	n = int(sys.stdin.readline())
	sys.stdout.write(results[n])
