#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e8 + 100;
typedef long long ll;
vector<bool>primes(MAX,true);
void Sieve(){
  for (ll i = 2; i*i <= MAX; i++) {
    if (primes[i]) {
      for (ll j = i*i; j<= MAX; j+=i)  primes[j] = false;  
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  Sieve();

  return 0;
}

//pre compute all primes upto 10^8
