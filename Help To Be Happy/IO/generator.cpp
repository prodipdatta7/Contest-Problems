#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

const int N = (int)1e6;
const int inf = (int)1e9 ;


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
    uniform_int_distribution < int > AM(1, 1000000), H(1, 1000000) ; 
    uniform_int_distribution < int > T1(100000, 100000), T2(200000, 200000) ; 
    int test = 1, file_no = 8 ;
    cin >> test ;
    string in = ".in" ;
    while (test--) {
        int n = T1(rng), q = T2(rng) ; 
        input[file_no].open(FileName(in, file_no)) ;
        input[file_no] << n << ' ' << q << '\n' ; 
        for(int i = 0 ; i < n ; ++i){
            input[file_no] << AM(rng) << ((i == n - 1) ? '\n' : ' ') ; 
        }
        for(int i = 0 ; i < n ; ++i){
            input[file_no] << H(rng) << ((i == n - 1) ? '\n' : ' ') ; 
        }
        uniform_int_distribution < int > U(1, n), V(1, n) ; 
        map< pair< int, int>, int > mp ; 
        for(int i = 1 ; i <= q ; ){
             int u = U(rng), v = V(rng) ; 
             if(u == v)continue ; 
             int x = min(u, v), y = max(u, v) ; 
             if(mp[make_pair(x, y)])continue ; 
             mp[make_pair(x, y)] = 1 ;
             input[file_no] << u << ' ' << v << '\n' ; 
             ++i ; 
        }
        ++file_no ;
    }
}