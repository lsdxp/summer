import math as math
def find_prime(n):
    prime=[]
    prime.append(False)
    prime.append(False)

    for i in xrange(2,n+1):
        prime.append(True)

    limit = int(math.sqrt(n))
    for i in xrange(2,limit+1):
        if (prime[i]) :
            j=i*i
            while j<=n:
                prime[j] = False
                j=j+i
    return prime
list=find_prime(10)
for i in range(0,len(list)):
    if(list[i]==True):
        print i
