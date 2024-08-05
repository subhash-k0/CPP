#include<bits/stdc++.h>
using namespace std;

bool mycompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

int main(){

//vector< data_type > name(size, value)
vector<int >v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

vector<int >v1;
v1.push_back(7);
v1.push_back(8);
v1.push_back(9);


//2D vector
//initialised a grid with -1
// vector<vector<int>> grid(n, vector<int>(m, -1));

//Iterator
vector<int>::iterator it;
for (it = v.begin(); it != v.end(); it++){
    cout<<*it<<endl;
} // 1,2,3

//For each loop
for(auto element : v){
    cout<<element<<endl;
} //1,2,3

for(auto element : v1){
    cout<<element<<endl;
}

//vector::swap()
v.swap(v1);

//sort()
sort(v.begin(), v.end());

//To get The sum of vector
int sum = accumulate(v.begin(), v.end(), 0);
cout<<sum<<endl;

//To get Max_element/min_element
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());
cout<<mx<<" "<<mn<<endl;

//To convert the vector into a prefix sum vector
//eg- v ={1,2,3}
//Prefix_sum v ={1,2,3}
partial_sum(v.begin(), v.end(), v.begin());

//pairs
vector < pair<int, int> >v;
for (int i = 0; i<n; i++){
    v.push_back(make_pair(arr[i], i));
}
sort(v.begin(), v.end(), mycompare);

return 0;
}
