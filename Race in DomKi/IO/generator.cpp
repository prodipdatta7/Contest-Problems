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
    int test = 1, file_no = 101 ;
    string in = ".in", out = ".out" ;
    input[file_no].open(FileName(in, file_no)) ;
    cin >> test ;
    input[file_no] << test << '\n' ;
    while (test--) {
        int n = N(rng) ;
        //cout << "n = " << n << '\n' ;
        input[file_no] << n << '\n' ;
        for (int i = 0 ; i < n ; ++i) {
            int v = val(rng) ;
            if (!test)v = val1(rng) ;
            input[file_no] << v << ((i == n - 1) ? '\n' : ' ') ;
            //cout << "v = " << v << '\n' ;
        }
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
        //int
        int seed = len(rng) ;
        input[file_no] << 200000 << '\n' ;
        for (int i = 0 ; i < 60000 ; ++i) {
            int id = len(rng) ;
            seed = len(rng) ; 
            id = (id + seed) % n + 1 ;
            int k = (i + seed + id) % n + 1 ;
            input[file_no] << 1 << ' ' << k << ' ' << id << '\n' ;
        }
        seed = len(rng) ;
        for (int i = 60000 ; i < 120000 ; ++i) {
            int id = len(rng) ;
            seed = len(rng) ; 
            id = (id + seed) % n + 1 ;
            int k = (i + seed + id) % n + 1 ;
            input[file_no] << 2 << ' ' << k << ' ' << id << '\n' ;
        }
        seed = len(rng) ;
        for (int i = 120000 ; i < 150000 ; ++i) {
            int id = len(rng) ;
            seed = len(rng) ; 
            id = (id + seed) % n + 1 ;
            int k = (i + seed + id) % n + 1 ;
            input[file_no] << 3 << ' ' << k << ' ' << id ; 
            id = len(rng) ; 
            id = (id + seed) % n + 1 ; 
            k = (k + id) % n + 1 ; 
            input[file_no] << ' ' << id << ' ' << k << '\n' ; 
        }
        for(int i = 150000 ; i < 200000 - 5 ; ++i){
            int a = len(rng), b = len(rng), c = len(rng), d = len(rng) ; 
            input[file_no] << 3 << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n' ; 
        }
        for(int i = 0 ; i < 5 ; ++i){
            int a = len(rng), b = len(rng) ; 
            input[file_no] << 3 << ' ' << a << ' ' << b << ' ' << a << ' ' << b << '\n' ; 
        }
    }
}