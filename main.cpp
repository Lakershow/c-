#include"Prime.cpp"

void func(Prime &a)
{
    //a.findPrime(100 , 999);
    cout << "素数为：" << endl;
    a.showPrime();
}

void func(Prime *p)
{
  cout << "素数为：" << endl;
  p->showPrime();
}

void prime(int a, int b)
{
    vector<Prime*> ps;
    for (int i = 100; i <= 999; ++i) {
        Prime* p = new Prime(i);
        if (p->isPrime())
            ps.push_back(p);
    else delete p;
  }
    for (Prime *p : ps) {
        p->showPrime();
        delete p;
    }
}

void superprime(int a, int b)
{
    vector<superPrime*> ps;
    for (int i = a; i <= b; i++) {
        superPrime * p = new superPrime(i);
        if (p->isPrime())
            ps.push_back(p);
    else
      delete p;
  }
    for (superPrime *p : ps) {
        p->showPrime();
        delete p;
    }
}

int main(){

  Prime pm(100, 999);
  func(pm);
  func(&pm);

  superPrime sp(100, 999);
  func(sp);
  func(&sp);

  prime(100, 999);
  superprime(100, 999);
  
  return 0;
}
