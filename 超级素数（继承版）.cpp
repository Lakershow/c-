#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Prime
{
public:
    Prime(int a,int b){
        l=a,r=b;
    }
    void find_prime(){
        for(int i=l;i<=r;i++)
        {
            if(judge_prime(i))p.push_back(i);
        }
    }
    void show_prime(){
        for(auto i:p)cout<<i<<' ';
    }
    int get_size(){
        return p.size();
    }
protected:
    bool judge_prime(int x){
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)return false;
        }
        return true;
    }
    vector<int> p;
    int l,r;
};

class SuperPrime: public Prime
{
public:
    SuperPrime(int a,int b):Prime(a,b){
        l=a,r=b;
    }
    void find_superprime(){
        find_prime();
        for(auto it=p.begin();it!=p.end();)
        {
            int a,b,c,temp=*it;
            a=temp/100;
            b=(temp/10)%10;
            c=temp%10;
            int sum=a+b+c;
            int cube_sum=a*a*a+b*b*b+c*c*c;
            if(judge_prime(sum)&&judge_prime(cube_sum))it++;
            else p.erase(it);
        }
    }
};

int main()
{
    SuperPrime s(100,999);
    s.find_superprime();
    s.show_prime();
}