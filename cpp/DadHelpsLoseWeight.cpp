#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define lli unsigned long long int
#define F first
#define S second
using namespace std;
const ll L = 1e9+7;
vector<ll> div(ll n){
    vector<ll> ans;
    for(ll i = 2; i*i <= n; ++i){
        if(n % i == 0){
            ans.pb(i);
            ans.pb(n/i);
        }
    }
    ans.pb(n);
    return ans;
}
int main() {   
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> g = div(v[1]-v[0]);
    bool b = false, C = false;
    for(int j = 0; j < g.size(); ++j){
        b = true;
        ll q = 0;
        for(int i = 1; i < n; ++i){
            if((v[i]-v[i-1]) % g[j] == 0){
                q = g[j];
                continue;
            }
            else{
                b = false;
            }
        }
        if(b){
            C = true;
        }
    }
    if(C && v[1]-v[0] != 1 && v[1]-v[2] != 0) cout << "1\n";
    else cout << "2\n";
   
}
