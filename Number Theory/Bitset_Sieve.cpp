#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e8 + 100;

typedef long long ll;
bitset<MAX>primes;

void bitsetSieve() {
  primes.set();
  primes[0] = primes[1] = 0;
  for (ll i = 2; i <= MAX; i++) {
    if (primes[i]) {
      for ( ll j = i*i ; j <= MAX; j += i) {
        primes[j] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  //int n; cin >> n;
  //bitsetSieve(n);
  bitsetSieve();
  /*
  for ( int i = 1; i <= n; i++) {
    if (primes[i]) cout << i << " ";
  }
  */

  return 0;
}

//pre compute all primes upto 10^8
