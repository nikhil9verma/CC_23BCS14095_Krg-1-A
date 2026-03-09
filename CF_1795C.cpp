#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<ll> pref(n+1, 0);
    for(int i = 0; i < n; i++){
      pref[i+1] = pref[i]+b[i];
    }
    vector<ll> cnt(n+1, 0), spare(n+1,0);
    for(int i = 0; i < n; i++){
      ll tmp = upper_bound(pref.begin(), pref.end(), a[i]+pref[i]) - pref.begin()-1;
      cnt[i]++;
      cnt[tmp]--;
      spare[tmp] += a[i]+pref[i]-pref[tmp];
    }
    for(int i = 0; i < n; i++){
      cout << cnt[i]*b[i] + spare[i] << " ";
      cnt[i+1] += cnt[i];
    }
    cout << endl;
  }
}