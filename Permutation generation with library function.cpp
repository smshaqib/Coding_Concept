#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "abc";

    while( next_permutation(s.begin(),s.end()) ){

        cout<<s<<endl;
    }

    ///output:
    //    acb
    //    bac
    //    bca
    //    cab
    //    cba

}
