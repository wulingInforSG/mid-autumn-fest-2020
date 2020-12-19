#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sz;
vector<string> ans;


void perm(string s, int r){
    if(r == sz){
        ans.push_back(s);
    } else {
        for(int i=r;i<sz;i++){
            swap(s[i], s[r]);
            perm(s, r+1);
            swap(s[i], s[r]);            
        }
    }
}

int main(){
    string s;
    cin >> sz >> s;
    perm(s, 0);
    sort(ans.begin(), ans.end());
    int asz = ans.size();
    for(int i=0;i<asz;i++){
        cout << ans[i] << endl;
    }

}
