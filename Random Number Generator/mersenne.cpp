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

string filename(string name, int n) {
	name += (char)((n / 10) + '0') ;
	name += (char)((n % 10) + '0') ;
	name += ".txt" ;
	return name ;
}
struct Solution{

} var ; 


int main() {
	//for(int i = 0 ; i < 11 ; ++i)cout << get(i) << '\n' ;
	int t = 1, c = 8 ; cin >> t ;
	string in = "input_", out = "output_" ;
	while (t--) {
		rng.seed(t + 100000) ;
		uniform_int_distribution<uint32_t> uint_dist(2, 3) ;
		uniform_int_distribution<uint32_t> uint_dist10(1, 200000) ;
		//int test = uint_dist10(rng) ;
		input[c].open(filename(in, c), ios :: out) ;
		vector < vector < int > > v ; 
		int test = 0 ;
		while(test <= 200000) {
			int n = uint_dist(rng) ;
			if(test + n > 200000){
				n = 200000 - test ; 
				test++ ; 
			}
			vector < int > in ; 
			in.push_back(n) ; 
			for(int j = 0 ; j < n ; ++j){
				int b = uint_dist10(rng) ; 
				in.push_back(b) ; 
			}
			test += n ; 
			v.push_back(in) ; 
		}
		input[c] << v.size() << '\n' ; 
		for(auto i : v){
			int h = i.size() - 1 ;
			for(int j = 0 ; j <= h ; ++j){
				input[c] << i[j] << " \n"[j == h]; 
			}
		}
		input[c].close() ;
		++c ; 
	}
}