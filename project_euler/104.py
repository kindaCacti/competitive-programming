# flake8: noqa
import sys
sys.set_int_max_str_digits(1000000)


def is_filled(a, target):
    for i in a:
        if i != target:
            return False
    return True

def is_good(a):
    tmp = str(a)
    if len(tmp) < 9:
        return False
    used = [0 for i in range(9)]

    for i in range(9):
        used[int(tmp[i])-1]+=1

    if not is_filled(used, 1):
        return False
    
    for i in range(9):
        #print(f'{len(tmp)-1-i} : {len(tmp)}')
        used[int(tmp[len(tmp)-1-i])-1]+=1
    
    if not is_filled(used, 2):
        return False
    
    return True

fib = [1,1,2]
k = 3

print(is_good(123456789))
while(not is_good(fib[2])):
    fib[0] = fib[1]
    fib[1] = fib[2]
    fib[2] = fib[0] + fib[1]
    k+=1
    if k==541:
        print(fib[2])

print(fib[2])
print(k)