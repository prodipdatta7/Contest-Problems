#include <iostream>
#include <random>
#include <fstream>
#include <assert.h>
using namespace std ;

const int N = (int)1e6 + 6 ;

typedef mt19937 myrng ;
myrng rng ;

ofstream input[100], output[100] ;

string get(string name, int n) {
	name += (char)((n / 10) + '0') ;
	name += (char)((n % 10) + '0') ;
	name += ".txt" ;
	return name ;
}

int dp[N][26] ;

long long solution(int n, int m, string s, string T) {
	if (m > n)return 0 ;
	long long res = 0 ;
	for (int i = 0 ; i <= n ; ++i) {
		for (int j = 0 ; j < 26 ; ++j)
			dp[i][j] = 0 ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		dp[i][s[i - 1] - 'a']++ ;
		for (int j = 0 ; j < 26 ; ++j) {
			dp[i][j] += dp[i - 1][j] ;
		}
	}
	for (int i = 1 ; i <= m ; ++i) {
		int r = n + i - m, cur_char = T[i - 1] - 'a' ;
		int match = dp[r][cur_char] - dp[i - 1][cur_char] ;
		res += (r - i + 1) - match ;
	}
	return res ; 
}


int main() {
	//for(int i = 0 ; i < 11 ; ++i)cout << get(i) << '\n' ;
	int t, c = 70 ; cin >> t ;
	string in = "input_", out = "output_" ;
	while (t--) {
		rng.seed(t) ;
		uniform_int_distribution<uint32_t> uint_dist(1, 10) ;
		uniform_int_distribution<uint32_t> uint_dist10(97, 122) ;
		int n = uint_dist(rng) ;
		// int n = 1000000 ;
		string s = "", T = "" ;
		input[c].open(get(in, c)) ;
		for (int i = 1 ; i <= n ; ++i) {
			int f = uint_dist10(rng) ;
			//int f = 97 ;
			s += (char)f ;
		}
		assert(n == (int)s.size()) ;
		int m = uint_dist(rng) % n + 1 ;
		//int m = 100 ;
		for (int i = 1 ; i <= m ; ++i) {
			int f = uint_dist10(rng) ;
			//int f = 100 ;
			T += (char)f ;
		}
		assert(m == (int)T.size()) ;
		input[c] << n << ' ' << m << '\n' << s << ' ' << T << '\n' ;
		long long res = solution(n, m, s, T) ;
		output[c].open(get(out, c)) ;
		output[c] << res << '\n' ;
		++c ;
	}
}