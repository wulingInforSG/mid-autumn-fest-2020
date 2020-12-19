#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    bool flag = false;
    while(t--){
        int m, d;
        cin >> m >> d;
        if(flag) {cout << "Don't ask me again!" << endl;continue;}
        if(m == 10 && d == 1){
            cout << "Today is Mid-Autumn Festival!" << endl;
            flag = true;
        } else if(m >= 10){
            cout << "Mid-Autumn Festival has passed." << endl;
        } else {
            cout << "Mid-Autumn Festival hasn't come yet." << endl;
        }
    }
}

