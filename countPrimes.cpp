class Solution {
public:

    bool isPrime(int n)
    {   
        if (n<=1)
            return false;
        else if(n==2)
            return true;
        else 
        {   int i=2;
            while(i<=sqrt(n))
                {   
                    if(n%i==0)
                      return false;
                     i++;
                }
            return true;
        }
    }
    int countPrimes(int n) {
        int count=0;
        for(int i=2;i<=n;i++)
        {
            if(isPrime(i))
                count++;
        }
        return count;
        
    }
};
