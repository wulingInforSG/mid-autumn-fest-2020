#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a, b, c;
        a = n / 100;
        n %= 100;
        b = n / 13;
        n %= 13;
        c = n / 2;
        n %= 2;
        cout << a << " " << b << " " << c << endl;
    }
}