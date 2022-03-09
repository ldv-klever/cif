# Build something like "((((x * 2 + 1) * 3 + 2) * 4 + 3) * 5 + 4)" to substitute to expr-recursion-limit.c nearby.
# Current value of UPPER_BOUND is the maximum one for getting output file from C back-end without errors. If you will
# increase it at least by one, you will catch error "expression recursion limit is reached".
UPPER_BOUND = 103

res = ""

for i in range(2, UPPER_BOUND):
    res += "("

res += "x"

for i in range(2, UPPER_BOUND):
    res += " * {} + {})".format(i, i - 1)

print(res)
