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
    uniform_int_distribution < int > val(1, 1000000), N(100000, 100000) ;
    uniform_int_distribution < int > S(1, 200000), Q(1, 500000), tmpI(1, 5000), tmpQ(1, 20), ch(0, 25) ;
    int test = 1, file_no = 17 ;
    cin >> test ;
    string in = ".in" ;
    while (test--) {
        int n = N(rng) ;
        //cout << "n = " << n << '\n' ; 
        input[file_no].open(FileName(in, file_no)) ;
        input[file_no] << n << '\n' ; 
        for(int i = 0 ; i < n ; ++i){
            int v = val(rng) ; 
            input[file_no] << v << ((i == n - 1) ? '\n' : ' ') ; 
            //cout << "v = " << v << '\n' ; 
        }
        vector < int > len(n, 0) ; 
        int sum = 0 ; 
        for(int i = 0 ; i < n ; ++i){
            int x = tmpI(rng) ; 
            len[i] = x ; 
            sum += x ; 
        }
        uniform_int_distribution < int > T(1, 500000) ; 
        int threshold = T(rng) ; 
        if(sum > threshold){
            sort(len.rbegin(), len.rend()) ; 
            for(int i = 0 ; i < n and sum > threshold ; ++i){
                int mx = len[i] - 1 ; 
                while(sum > threshold and mx > 0){
                    --len[i] ; 
                    --mx ; 
                    --sum ; 
                }
            }
        }
        shuffle(len.begin(), len.end(), rng) ; 
        vector < string > bucket ; 
        for(int i = 0 ; i < n ; ++i){
            string t = "" ; 
            for(int j = 0 ; j < len[i] ; ++j){
                int c = ch(rng) ; 
                t += (char)(c + 'a') ;
            }
            sort(t.begin(), t.end()) ;
            bucket.push_back(t) ; 
            input[file_no] << t << '\n' ; 
        }
        //int size = Q(rng), st = 0 ;
        //cout << "size = " << size << '\n' ; 
        vector < int > a, b ; 
        uniform_int_distribution < int > L(1, 5000), R(50000, n) ; 
        for(int i = 0 ; i < n ; ++i){
            int l = L(rng), r = R(rng) ; 
            if(l > r)swap(l, r) ;
            a.push_back(l); 
            b.push_back(r); 
            //st += (int)t.size() ; 
            //cout << t << ' ' << l << ' ' << r << '\n' ; 
            //cout << "size = " << size << '\n' ;
        }
        //cout << "st = " << st << '\n' ;
        int q = (int)bucket.size() ; 
        //cout << "q = " << q << '\n' ; 
        shuffle(bucket.begin(), bucket.end(), rng) ;
        input[file_no] << n << '\n' ; 
        for(int i = 0 ; i < n ; ++i){
            input[file_no] << bucket[i] << ' ' << a[i] << ' ' << b[i] << '\n' ; 
        }
        ++file_no ;
    }
}