#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e8 + 10;

typedef long long ll;
vector<int> primes;

void sieve() {
  bitset<MAX>marks;
  marks.set();
  primes.push_back(2);
  for (ll i = 3 ; i <= MAX; i+=2) {
  if (marks[i]) {
  primes.push_back(i);
  for (ll j = i*i; j <= MAX; j += i) marks[j] = false;
    }
  }

}
void segSieve (ll l, ll r) {
  vector<bool>isPrime(r - l + 1, true);
   ll base = 0;
  for (ll i : primes) {
    base = max (i * i, (l + i - 1) / i * i);
    for (ll j = base; j <= r; j += i)  isPrime[j - l] = false;       
  }
  for (int i = 0; i < r - l + 1; ++i) {
    if (i + l == 1) continue;
    if (isPrime[i]) cout << i + l << "\n";
  }
  
}

int main() {
    sieve();
    int t;
    cin >> t;
    ll l, r;
    while (t--) {
      cin >> l >> r;
      segSieve(l, r);
      cout<<"\n";
    }
    return 0;
}
