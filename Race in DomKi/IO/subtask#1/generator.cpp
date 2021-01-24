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
	uniform_int_distribution < int > val(1, 30), val1(1, 2), N(10, 1000), len(1, 1000) ;
	int test = 1, file_no = 10 ;
	string in = ".in", out = ".out" ;
	input[file_no].open(FileName(in, file_no)) ;
	cin >> test ;
	input[file_no] << test << '\n' ;
	while (test--) {
		int n ; cin >> n ;
		//cout << "n = " << n << '\n' ;
		input[file_no] << n << '\n' ;
		// for (int i = 0 ; i < n ; ++i) {
		// 	int v = val(rng) ;
		// 	//if (!test)v = val1(rng) ;
		// 	input[file_no] << v << ((i == n - 1) ? '\n' : ' ') ;
		// 	//cout << "v = " << v << '\n' ;
		// }
		vector < int > nodes ;
		for (int i = 1 ; i <= n ; ++i)
			nodes.push_back(i) ;
		vector < pair < int, int > > edges ;
		shuffle(nodes.begin(), nodes.end(), rng) ;
		for (int i = 0 ; i < n - 1 ; ++i) {
			edges.emplace_back(nodes[i], nodes[i + 1]) ;

		}
		shuffle(edges.begin(), edges.end(), rng) ;
		for (pair < int, int > i : edges)
			input[file_no] << i.first << ' ' << i.second << '\n' ;
	}
}