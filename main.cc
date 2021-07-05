#include <bits/stdc++.h>
#define speedup ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cout.precision(12)
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using pid =pair<int,double>;
using pld =pair<ll,double>;
using pdd =pair<double,double>;
using pldld =pair<ld,ld>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lb lower_bound
#define ub upper_bound
#define bk back
#define ft front
#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define pbk pop_back
#define pft pop_front
#define ins insert
#define em emplace
#define emb emplace_back
#define sz(x) int(x.size())
#define mp make_pair
#define sbc __builtin_popcount
#define msb __builtin_clz
#define lsb __builtin_ctz
template<typename T> using X_PQ = std::priority_queue<T>;
template<typename T> using N_PQ = std::priority_queue<T, vector<T>, greater<T>>;
const ll mod = 1e9+7;

mt19937_64 rang(chrono::steady_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0,lim-1); return uid(rang); }
//#include<functional>
//#include<utility>

namespace std {
 
	template<class Fun>
	class y_combinator_result {
		Fun fun_;
	public:
		template<class T>
		explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	 
		template<class ...Args>
		decltype(auto) operator()(Args &&...args) {
			return fun_(std::ref(*this), std::forward<Args>(args)...);
		}
	};
	 
	template<class Fun>
	decltype(auto) y_combinator(Fun &&fun) {
		return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
	}
 
} // namespace std
#define y_comb y_combinator

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T,class U=null_type> using pbds_s = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T,class U=null_type> using pbds_ms = tree<T, U, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T,class U=null_type> using pbds_rs = tree<T, U, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T,class U=null_type> using pbds_rms = tree<T, U, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ofk order_of_key
#define fbo find_by_order

template<typename T> void smax(T& a, T b) { if(a<b) a=b; }
template<typename T> void smin(T& a, T b) { if(a>b) a=b; }
template<class T, class U> T pw(T a,U b) { T p=1; U one=1; while(b) { if(b&one) p=p*a; a=a*a; b >>=1; } return p; }
template<class T, class U> T pwm(T a,U b,T md=mod) { T p=1; U one=1; while(b) { if(b&one) p=p*a%md; a=a*a%md; b >>=1; } return p; }

template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &it:v) is >> it; return is; }
template<typename T, size_t SZ> istream &operator>>(istream &is, array<T, SZ> &v) { for (auto &it : v) is >> it; return is; }
template<typename T, typename U> istream &operator>>(istream &is, pair<T, U> &it) { is >> it.first >> it.second; return is; }
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &it) { os << it.first << ' ' << it.second; return os; }
template<typename T, size_t SZ> ostream &operator<<(ostream &os, const array<T, SZ> &v) { for (auto &it : v) os << it << ' '; return os; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &it : v) os << it << ' '; return os; }

#ifndef ONLINE_JUDGE
class Timer { chrono::high_resolution_clock::time_point start_t, end_t; public: Timer() { start_t=chrono::high_resolution_clock::now(); } ~Timer() { end_t = chrono::high_resolution_clock::now(); auto duration = chrono::duration_cast<chrono::milliseconds>(end_t-start_t); cerr<<"\nRunTime: "<<duration.count()<<"ms"<<'\n'; } };
void debug() { cerr << '\n'; }
template<typename T, typename... Args> void debug(T print, Args... args) { cerr << ' ' << print; debug(args...); }
#define deb(...) cerr << "[" << #__VA_ARGS__ << "]" << " --> ", debug(__VA_ARGS__)
#else
#define deb(...) void(0)
#endif


void solve() {

}

int main() {
	srand(chrono::steady_clock::now().time_since_epoch().count());
	speedup;
	//int t; cin >> t; while (t--)
	solve();
}
