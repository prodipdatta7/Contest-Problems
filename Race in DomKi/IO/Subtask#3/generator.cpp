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

struct query {
    int tp, a, b, c, d ;
    query(int tp = 0, int a = 0, int b = 0, int c = 0, int d = 0) : tp(tp), a(a), b(b), c(c), d(d) {}
} ;

vector < query > Q ;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution < int > val(1, 60), val1(40, 45), N(20000, 20000), len(10000, 20000) ;
    int test = 1, file_no = 6 ;
    string in = ".in", out = ".out" ;
    input[file_no].open(FileName(in, file_no)) ;
    // cin >> test ;
     input[file_no] << test << '\n' ;
    while (test--) {
        int n = 20000 ; 
        input[file_no] << n << '\n' ; 
        vector < int > nodes ; 
        for(int i = 1 ; i <= n ; ++i){
            int v = val1(rng) ; 
            nodes.push_back(i) ; 
            input[file_no] << v << " \n"[i == n] ; 
        }
        shuffle(nodes.begin(), nodes.end(), rng) ; 
        for(int i = 0 ; i < n - 1 ; ++i)
            input[file_no] << nodes[i] << ' ' << nodes[i + 1] << '\n' ; 
        int seed = len(rng) ;
        input[file_no] << 20000 << '\n' ;
        for (int i = 0 ; i < 3000 ; ++i) {
            int id = len(rng) ;
            int k = __builtin_popcount(id) ; 
            k = (id + k) % n + 1 ; 
            //input[file_no] << 1 << ' ' << k << ' ' << id << '\n' ;
            Q.push_back(query(1, k, id)) ; 
        }
        seed = len(rng) ;
        for (int i = 3000 ; i < 15000 ; ++i) {
            int id = len(rng) ;
            int k = __builtin_popcount(id) ; 
            k = (id + k) % n + 1 ; 
            //input[file_no] << 2 << ' ' << k << ' ' << id << '\n' ;
            Q.push_back(query(2, k, id)) ; 
        }
        seed = len(rng) ;
        for (int i = 15000 ; i < 20000 ; ++i) {
            int a = len(rng) ;
            int b = (__builtin_popcount(a) + a) % n + 1 ; 
            int c = len(rng) ; 
            int d = (__builtin_popcount(c) + c) % n + 1 ; 
            Q.push_back(query(3, a, b, c, d)) ; 
        }
        // for (int i = 180000 ; i < 200000 - 5 ; ++i) {
        //     int a = len(rng), b = len(rng), c = len(rng), d = len(rng) ;
        //     //input[file_no] << 3 << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n' ;
        //     Q.push_back(query(3, a, b, c, d)) ; 
        // }
        // for (int i = 0 ; i < 5 ; ++i) {
        //     int a = len(rng), b = len(rng) ;
        //     //input[file_no] << 3 << ' ' << a << ' ' << b << ' ' << a << ' ' << b << '\n' ;
        //     Q.push_back(query(3, a, b, a, b)) ; 
        // }
        shuffle(Q.begin(), Q.end(), rng) ; 
        for(query i : Q){
            input[file_no] << i.tp << ' ' << i.a << ' ' << i.b ; 
            if(i.tp == 3)input[file_no] << ' ' << i.c << ' ' << i.d ; 
            input[file_no] << '\n' ; 
        }
    }
}