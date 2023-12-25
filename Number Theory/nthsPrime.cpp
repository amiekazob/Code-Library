#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e8 + 100;
bitset<MAX>primes;
vector<int>pth;

void bitsetSieve() {
  primes.set();
  primes[0] = primes[1] = 0;
  pth.push_back(0);
  for (ll i = 2; i <= MAX; i++) {
    if (primes[i]) {
      pth.push_back(i);
      for ( ll j = i*i ; j <= MAX; j += i) primes[j] = 0;
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  bitsetSieve();
  //int n; cin >> n;        // for nth prime
  //cout << pth[n] << "\n"; // for nth prime
  for (int i = 1; i <= pth.size(); i+=100) {
    cout << pth[i] << "\n";
  }
  return 0;
}
// find nth primes between the range of 1 to 10^8 
// problem: https://www.spoj.com/problems/TDPRIMES/
