# flake8: noqa
MOD = int(1e9+7)

def powe(a, b):
    return a**b

def dwmn(a, b):
    tmp = 1
    k = 1
    for i in range(b+1, a + 1):
        tmp *= i
        tmp //= k
        k += 1
    return tmp

def mini(a, b):
    if(a < b): return a
    return b

inp = input()
inp = inp.split(' ')
n = int(inp[0])
k = int(inp[1])

div = powe(2, k)

co = 0
for i in range(0, k):
    tmp = dwmn(k-1, i)
    sp = mini(i + 1, n)
    sp += sp - 1
    tmp *= sp
    co += tmp

out = float(co)/div
print(out)
