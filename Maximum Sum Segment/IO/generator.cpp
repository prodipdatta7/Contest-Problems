#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

const int N = (int)1e5;
const int inf = (int)1e9 ;
const unsigned long long INF = (unsigned long long)1e15 ; 


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
    uniform_int_distribution < unsigned long long > K(1, INF) ; 
    uniform_int_distribution < int > Test(1, 2000000), A(1, inf) ;
    int test = 1, file_no = 14 ;
    cin >> test ;
    string in = ".in", out = ".out" ;
    int threshold = 1000 ; 
    std::vector< int > v(threshold + 1, 0);
    while (test--) {
        int T = Test(rng) ;
        if(T > threshold)T = threshold ; 
        input[file_no].open(FileName(in, file_no)) ;
        input[file_no] << T << '\n' ; 
        for(int i = 1 ; i <= T ; ++i){
            input[file_no] << A(rng) << " \n"[i == T] ; 
        }
        int q = Test(rng) ; 
        if(q > 100)q = 100 ; 
        input[file_no] << q << '\n' ; 
        uniform_int_distribution < int > L(1, T), R(1, T) ; 
        int mx = 0, mn = threshold + 1  ;
        set < long long > cnt ; 
        int big = 0 ;  
        for(int i = 1 ; i <= q ; ++i){
            int l = L(rng), r = R(rng) ; 
            long long k = K(rng) ; 
            cnt.insert(k) ; 
            if(l > r)swap(l, r) ; 
            if(mx < r - l)mx = r - l ; 
            if(mn > r - l)mn = r - l ; 
            if(r - l >= 10000)++big ; 
            v[r - l]++ ;
            input[file_no] << l << ' ' << r << ' ' << k << '\n' ; 
        }
        cout << "mx = " << mx << '\n' ;
        cout << "mn = " << mn << '\n' ;
        cout << "n = " << T << '\n' ;
        cout << "q = " << q << '\n' ;
        int on = 0, off = 0 ;
        for(int i = 0 ; i < threshold ; ++i){
            if(!v[i])++off ;
            else {
                ++on ; 
                //cout << "i = " << i << " v[i] = " << v[i] << '\n' ;
            }
        }
        double ON = 1.0 * on * 100 / threshold, OFF = 1.0 * off * 100 / threshold ; 
        double var = 100.0 * cnt.size() / q, TLE = 100.0 * big / q; 
        printf("%.2f %.2f %.2f %.2f\n",ON, OFF, var, TLE);
        ++file_no ;
    }
}