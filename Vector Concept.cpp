#include<bits/stdc++.h>
using namespace std;

int main(){


    //vector is dynamic and array is static.


    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);


    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl; /// 1 2 3

    v[0]=3;

    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl; ///3 2 3

    //size of vectopr

    cout<<v.size()<<endl; ///3


    for(int i=0; i<v.size(); i++)cout<<v[i]<<" "; ///3 2 3
    cout<<endl;


    vector<int> v1 = {2,3,4};

    cout<<"Vector size of v1: "<<v1.size()<<endl; ///3

    for(int i=0; i<v1.size(); i++)cout<<v1[i]<<" "; /// 2 3 4
    cout<<endl;


    //clear vector and check if empty or not

    v.clear();

    cout<<"vector is empty or not"<<endl;
    cout<<v.size()<<endl; ///0

    cout<<v.empty()<<endl; ///1
    cout<<v1.empty()<<endl; ///0


    //resizing vector into specific size;

    v1.resize(5);

    cout<<"after resizing: "<<v1.size()<<endl;; ///5

    for(int i=0; i<v1.size(); i++)cout<<v1[i]<<" "; /// 2 3 4 0 0
    cout<<endl;



    vector<int> a(5);

    cout<<"size of vector a: "<<a.size()<<endl; ///5

    for(int i=0; i<a.size(); i++)cout<<a[i]<< " "; /// 0 0 0 0 0
    cout<<endl;


    //directly assigning vector into another one
    a=v1;


    //printing using auto
    for(auto u: a)cout<<u<<" "; /// 2 3 4 0 0
    cout<<endl;

    //with iterator
    cout<<"vector Iterator : \n";

    vector<int>:: iterator it;

    for(it = a.begin(); it!=a.end(); it++)cout<<*it<< " "; /// 2 3 4 0 0
    cout<<endl;


    //choto theke boro sorting
    a = {3,4,5,1,2};

    sort(a.begin(),a.end()); // o(n*log2(n))

    cout<<"After sorting : \n";

    for(auto u: a)cout<<u<<" ";  /// 1 2 3 4 5
    cout<<endl;

    //boro theke choto sorting

    sort(a.rbegin(),a.rend());

    for(auto u: a)cout<<u<<" "; /// 5 4 3 2 1
    cout<<endl;

    //boro theke choto sorting part 2

    sort(a.begin(),a.end(),greater<int>()); /// 5 4 3 2 1
    for(auto u: a)cout<<u<<" ";
    cout<<endl;



    //vector reversing
    a = {3,4,5,1,2};

    reverse(a.begin(),a.end());

    cout<<"Vector after reversing : 3,4,5,1,2 \n";
    for(auto u: a)cout<<u<<" "; /// 2 1 5 4 3
    cout<<endl;


    cout<<"Showing and poping last item of vector \n";
    //gives the last item of vector;
    cout<<a.back()<<endl; /// 3
    //pops the last item
    a.pop_back();
    //gives the last item of vector
    cout<<a.back()<<endl; /// 4



    a = {3,4,5,1,2};
    cout<<"The first item of 3,4,5,1,2 is :\n";
    cout<< *a.begin()<<endl; /// 3


    //erases the first item
    a.erase(a.begin());

    for(auto u: a)cout<<u <<" "; /// 4 5 1 2
    cout<<endl;


    //erases the last index of 0+2;
    a.erase( a.begin()+2 );
    for ( auto u : a ) cout << u << " "; /// 4 5 2
    cout << endl;


    //unique item sort from first and keep the
    //rest of the item in last;

    a = {1,1,2,2,2,3,3};
    unique(a.begin(),a.end());


    for(auto u: a)cout<<u<<" "; /// 1 2 3 2 2 3 3

    cout<<endl;


    a = {1,1,2,2,2,3,3};
    int n = unique(a.begin(),a.end()) - a.begin();

    //gives the count of unique item
    cout<<"the count of unique item is :\n"<<n<<endl; /// 3


    for(int i=0; i<n; i++)cout<<a[i]<< " "; /// 1 2 3
    cout<<endl;


    a = {2,3,1,5};

    cout<<"The max element and index of  {2,3,1,5} \n";

    //gives max elements index
    cout<< max_element(a.begin(),a.end()) - a.begin()<<endl; ///3
    //gives max elements value
    cout<< *max_element(a.begin(),a.end())<<endl; ///5

}
