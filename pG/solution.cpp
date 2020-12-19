#include <iostream>
using namespace std;

int pow(int a,int b){
	int result=1;
	while(b--)result*=a;
	return result;
}

int mooncake [243][243];

void eat(int l,int r,int t,int b,int depth){
	if(depth==0)return;
	
	int x1=(l*2+r*1)/3, x2=(l*1+r*2)/3;
	int y1=(t*2+b*1)/3, y2=(t*1+b*2)/3;
	
	for(int x=x1;x<x2;x++){
		for(int y=y1;y<y2;y++){
			mooncake[y][x]=0;
		}
	}
	eat(l,x1,t,y1,depth-1);
	eat(l,x1,y1,y2,depth-1);
	eat(l,x1,y2,b,depth-1);
	eat(x1,x2,t,y1,depth-1);
	eat(x1,x2,y2,b,depth-1);	
	eat(x2,r,t,y1,depth-1);
	eat(x2,r,y1,y2,depth-1);
	eat(x2,r,y2,b,depth-1);
}

int main(){
	int M,N;
	cin>>N>>M;
	
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)mooncake[i][j]=1;
	int depth=0;
	for(int sum=0;sum<M;depth++){
		sum+=N*N/pow(9,depth+1)*pow(8,depth);
	}
	eat(0,N,0,N,depth);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<(mooncake[i][j]?"@":" ");
		}
		cout<<endl;
	}
}