#include <bits/stdc++.h>
#include <random>
#include <fstream>
#include <assert.h>
using namespace std ;

const int N = (int)1e6 + 6 ;
const long long MOD = (long long)1e18 ;
const long long Mod = (long long)1e12 ;

typedef mt19937 myrng ;
myrng rng ;

ofstream input[100], output[100] ;

string get(string name, int n) {
	name += (char)((n / 10) + '0') ;
	name += (char)((n % 10) + '0') ;
	name += ".txt" ;
	return name ;
}

vector < int > pm ; 
bitset <N> bs ;  

struct Solution{

	void sieve(){
		for(int i = 2 ; i < N ; ++i){
			if(!bs[i])pm.push_back(i) ;
			for(int j = 0 ; j < pm.size() and i * pm[j] < N ; ++j){
				bs[i * pm[j]] = 1 ;
				if(i % pm[j] == 0)break ; 
			}
		}
	}

	long long solution(long long a, long long d, long long n){
		vector < long long > factor ; 
		int tot = 0 ;
		for(int i : pm){
			if(d % i == 0){
				factor.push_back(i) ;
				++tot ; 
				while(d % i == 0)d /= i ;
			}
		}
		if(d > 1)factor.push_back(d), ++tot ; 
		long long res = 0 ; 
		for(int mask = 1 ; mask < (1 << tot) ; ++mask){
			long long cur = 1 ;
			for(int i = 0 ; i < tot ; ++i){
				if((mask >> i) & 1)cur *= factor[i] ;
			}
			if(__builtin_popcount(mask) & 1)res += n / cur ; 
			else res -= n / cur ;
		}
		return n - res ; 
	}
} var ; 


int main() {
	var.sieve() ;
	//for(int i = 0 ; i < 11 ; ++i)cout << get(i) << '\n' ;
	int t, c = 43 ; cin >> t ;
	string in = "input", out = "output" ;
	while (t--) {
		rng.seed(t - 10) ;
		uniform_int_distribution<uint32_t> uint_dist ;
		uniform_int_distribution<uint32_t> uint_dist10(1, 20000) ;
		int test = uint_dist10(rng) ;
		test = test > 2000 ? 2000 : test ;
		input[c].open(get(in, c)) ;
		output[c].open(get(out, c)) ;
		input[c] << test << '\n' ;
		for (int i = 1 ; i <= test ; ++i) {
			// unsigned long long n = uint_dist(rng) ;
			// unsigned long long nn = uint_dist(rng) ;
			// unsigned long long d = uint_dist(rng) ;
			// unsigned long long dd = uint_dist(rng) ;
			// unsigned long long a = uint_dist(rng) ;
			// unsigned long long aa = uint_dist(rng) ;
			// a = (a * aa) % MOD + 1 ;
			// n = (n * nn) % MOD + 1 ;
			// d = (d * dd) % Mod + 1 ;
			long long a = 1000000000000000000, d = 802241960520, n = 1000000000000000000 ;
			assert(a >= 1 and a <= MOD) ;
			assert(d >= 1 and d <= Mod) ;
			assert(n >= 1 and n <= MOD) ;
			input[c] << a << ' ' << d << ' ' << n << '\n' ;
			output[c] << var.solution(a, d, n) << '\n' ; 
		}
		++c ; 
	}
}