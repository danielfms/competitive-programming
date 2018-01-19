from sys import stdin, stdout
while True:
    cds = set()
    ans = 0
    n , m = map(int, stdin.readline().split())
    if n == 0 and m == 0:
        break

    for i in range(n):
        x = int(stdin.readline())
        cds.add(x)
    
    for i in range(m):
        x = int(stdin.readline())
        if x in cds :
            ans = ans + 1
    
    stdout.write('{}\n'.format(ans))
    
