#include"Prime.h"
#include<math.h>

Prime::Prime(int x)
{
    if(judgePrime(x))p.push_back(x);
}

bool Prime::isPrime()
{
    return !p.empty();
}

Prime::Prime(int low,int high)
{
    for(int i=low;i<=high;i++)
    {
        if(judgePrime(i))p.push_back(i);
    }
}

bool Prime::judgePrime(int a)
{
    if(a==2)return true;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)return false;
    }
    return true;
}

void Prime::showPrime()
{
    for(auto x:p)cout<<x<<' ';
    cout<<endl;
}

int Prime::getSize()
{
    return p.size();
}

superPrime::superPrime(int low,int high):Prime(0,-1)
{
    findPrime(low,high);
}

superPrime::superPrime(int x):Prime(0,-1)
{
    findPrime(x,x);
}

bool superPrime::judgePrime(int a)
{
    int sum=0,largesum=0,k=0;
    while(a)
    {
        k=a%10;
        sum+=k;
        largesum+=k*k*k;
        a/=10;
    }
    if(Prime::judgePrime(a)&&Prime::judgePrime(sum)&&Prime::judgePrime(largesum))return true;
    else return false;
}

void superPrime::findPrime(int low , int high)
{
    vector<int> prime;
    for(int i = low ; i <= high ; i++){
        if(Prime::judgePrime(i)){
            prime.push_back(i);//push进容器中
        }
    }

    for(int i = 0 ; i < prime.size() ; i++){
        if(superPrime::judgePrime(prime[i])){
            p.push_back(prime[i]);
        }
    }
}

bool superPrime::isPrime()
{
    return !p.empty();
}
