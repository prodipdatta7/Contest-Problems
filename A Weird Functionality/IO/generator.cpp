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

string filename(string ext, int n) {
	string name = "" ; 
	name += (char)((n / 10) + '0') ;
	name += (char)((n % 10) + '0') ;
	name += ext ;
	return name ;
}
struct Solution{

} var ; 


int main() {
	//for(int i = 0 ; i < 11 ; ++i)cout << get(i) << '\n' ;
	int t = 1, c = 6 ; cin >> t ;
	string in = ".in", out = ".out" ;
	while (t--) {
		rng.seed(t + 100000) ;
		uniform_int_distribution<uint32_t> uint_dist(50000, 100000) ;
		uniform_int_distribution<uint64_t> uint_dist10(1, 1000000000000000000) ;
		uniform_int_distribution<uint64_t> uint_dist1(1, 10000000000) ;
		//int test = uint_dist10(rng) ;
		input[c].open(filename(in, c), ios :: out) ; 
		int test = uint_dist(rng) ;
		input[c] << test << '\n' ; 
		for(int i = 1 ; i <= test ; ++i){
			long long l = uint_dist1(rng) ; 
			long long r = uint_dist10(rng) ; 
			long long k = uint_dist10(rng) ;
			if(l > r)swap(l, r) ; 
			k = (k % 9) + 1 ; 
			input[c] << l << ' ' << r << ' ' << k << '\n' ; 
		}
		input[c].close() ;
		++c ; 
	}
}