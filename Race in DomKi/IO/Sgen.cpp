#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

//const int N = (int)1e6;
//const int inf = (int)1e9 ;


ofstream input[100], output[100] ;

string FileName(string ext, int n) {
	string name = "" ;
	if (n > 9)name += (char)((n / 10) + '0') ;
	name += (char)((n % 10) + '0') ;
	name += ext ;
	return name ;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution < int > val(1, 60), val1(1, 2), N(200000, 200000), len(1, 200000) ;
	int test = 1, file_no = 4 ;
	string in = ".in", out = ".out" ;
	input[file_no].open(FileName(in, file_no)) ;
	//cin >> test ;
	input[file_no] << test << '\n' ;
	while (test--) {
		int n = 2000 ;
		//cout << "n = " << n << '\n' ;
		input[file_no] << n << '\n' ;
		int cnt = 0 ;
		for (int i = 0 ; i < 600 ; ++i) {
			int v = (i % 60) + 1 ;
			input[file_no] << v << ' ' ;
			//cout << "v = " << v << '\n' ;
			++cnt ; 
		}
		for (int i = 600 ; i < 1200 ; ++i) {
			int v = 5 ;
			input[file_no] << v << ' ' ;
			++cnt ; 
		}
		for (int i = 1200, j = 0 ; i < 2000 ; ++i, ++j) {
			int v = (j % 60) + 1 ;
			input[file_no] << v << (i == 1999 ? '\n' : ' ') ; 
			++cnt ; 
		}
		assert(cnt == n) ; 
		cout << cnt << '\n' ; 
		vector < pair < int, int > > edges ;
		for (int i = 1 ; i < 600 ; ++i) {
			edges.emplace_back(i, 600) ;
		}
		for (int i = 600 ; i < 1200 ; ++i) {
			edges.emplace_back(i, i + 1) ;
		}
		for (int i = 1201 ; i <= 2000 ; ++i) {
			edges.emplace_back(i, 1200) ;
		}
		//cout << (edges.size()) << '\n' ; 
		shuffle(edges.begin(), edges.end(), rng) ;
		for (pair < int, int > i : edges)
			input[file_no] << i.first << ' ' << i.second << '\n' ;
		vector < int > types = {1, 2, 3} ;
		input[file_no] << 2000 << '\n' ;
		for (int i = 1, j = 1201, k = 2000 ; i <= 300 ; ++i, ++j, --k) {
			shuffle(types.begin(), types.end(), rng) ;
			input[file_no] << 1 << ' ' << i << ' ' << j << '\n' ;
			input[file_no] << 2 << ' ' << i << ' ' << j << '\n' ;
			input[file_no] << 1 << ' ' << i << ' ' << k << '\n' ;
			input[file_no] << 2 << ' ' << i << ' ' << k << '\n' ;
			input[file_no] << 3 << ' ' << i << ' ' << j << ' ' << j << ' ' << i << '\n' ;
			input[file_no] << 3 << ' ' << i << ' ' << k << ' ' << k << ' ' << i << '\n' ;
		}
		uniform_int_distribution< int > L(1, 600), R(1201, 2000) ;
		for (int i = 1 ; i <= 8000 ; ++i) {
			int a = L(rng), b = R(rng), c = L(rng), d = R(rng) ;
			if (i % 4 == 1) {
				input[file_no] << 1 << ' ' << a << ' ' << b << '\n' ;
				input[file_no] << 2 << ' ' << b << ' ' << a << '\n' ;
			}
			else if (i % 4 == 2) {
				input[file_no] << 1 << ' ' << b << ' ' << a << '\n' ;
				input[file_no] << 2 << ' ' << a << ' ' << b << '\n' ;
			}
			else if (i % 4 == 3) {
				input[file_no] << 1 << ' ' << a << ' ' << c << '\n' ;
				input[file_no] << 2 << ' ' << d << ' ' << b << '\n' ;
			}
			else {
				input[file_no] << 1 << ' ' << b << ' ' << c << '\n' ;
				input[file_no] << 2 << ' ' << a << ' ' << b << '\n' ;
			}

		}
		for (int i = 1 ; i <= 20 ; ++i) {
			int a = L(rng), b = R(rng), c = L(rng), d = R(rng) ;
			input[file_no] << 3 << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n' ;
			input[file_no] << 3 << ' ' << a << ' ' << d << ' ' << c << ' ' << b << '\n' ;
		}
	}
}