#include<iostream>
#include <bits/stdc++.h>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){
    double v1 = (double) a.first/a.second;
    double v2 = (double) b.first/b.second;

    return (v1 > v2);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pr(n);
    for(int i=0; i< n; i++){
        cin>> pr[i].first >> pr[i].second;
    }
    int w;
    cin>> w;
    sort(pr.begin(), pr.end(), compare);
    double ans =0;
    for(int i=0; i< n; i++){
        if(w >= pr[i].second){
            ans+= pr[i].first;
            w-= pr[i].second;
            continue;
        }
        double temp = (double) pr[i].first/pr[i].second;
        ans =ans + w * temp;
        break;
    }
    cout << ans<< endl;
    return 0;
}