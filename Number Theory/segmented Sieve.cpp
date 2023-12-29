#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;

typedef long long ll;
bitset<MAX>marks;
vector<int> primes;
void Sieve() {
  marks.set();
  marks[0] = marks[1] = 0;
  for (ll i = 2; i <= MAX; i++) {
    if (marks[i]) {
      primes.push_back(i);
      for ( ll j = i*i ; j <= MAX; j += i)  marks[j] = 0;    
    }
  }
}

void segSieve (ll l, ll r) {
  vector<bool>isPrime(r - l + 1,true);
  ll base = 0;
  for (ll i : primes) {
  	base = max (i * i, (l + i - 1) / i * i);
    for (ll j = base; j <= r; j += i) isPrime[j] = false;
  }
  for (ll i = 0 ; i <= r - l + 1; i++) {
  	if (i + l == 1) continue;
  	if (isPrime[i + l]) cout << i + l<< "\n";
  }

}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  Sieve();
  int t; cin >> t;
  while(t--) {
  	ll l , r ; cin >> l >> r; 
    segSieve(l, r);
    cout<<"\n";
  }
  return 0;
}
