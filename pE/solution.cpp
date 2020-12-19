#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool map[3002][3002];//start point
int smoke_x[3002],smoke_y[3002];
char d;
int pos_x[8] = {-1,-1,-1,0,0,1,1,1};
int pos_y[8] = {-1,0,1,-1,1,-1,0,1};

void wind(int x, int y){
	if(d == 'W'){
		smoke_x[x] = min(smoke_x[x], y);
	}else if(d == 'E'){
		smoke_x[x] = max(smoke_x[x], y);
	}else if(d == 'N'){
		smoke_y[y] = min(smoke_y[y], x);
	}else if(d == 'S'){
		smoke_y[y] = max(smoke_y[y], x);
	}
}

bool check_near(int x, int y){
	for(int i=0;i<8;i++){
		if(map[x+pos_x[i]][y+pos_y[i]] == 1)return 1;
	}
	return 0;
}

bool check_wind(int x, int y){
	if(d == 'W'){
		if(y >= smoke_x[x])return 1;
	}else if(d == 'E'){
		if(y <= smoke_x[x])return 1;
	}else if(d == 'N'){
		if(x >= smoke_y[y])return 1;
	}else if(d == 'S'){
		if(x <= smoke_y[y])return 1;
	}
	return 0;	
}

int main(){
	int n, m, k, x, y;
	memset(smoke_x, 0, sizeof(smoke_x));
	memset(smoke_y, 0, sizeof(smoke_y));
	
	cin >> n >> m >> k >> d;
	if(d == 'W'){
		memset(smoke_x, m, sizeof(smoke_x));
	}else if(d == 'N'){
		memset(smoke_y, n, sizeof(smoke_y));
	}
	for(int i=0;i<k;i++){
		cin >> x >> y;
		map[x][y] = 1;
		wind(x, y);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!map[i][j] && !check_near(i, j) && !check_wind(i, j))cout << i <<" "<< j <<endl;
		}
	}
	return 0;
}