#include <iostream>

using namespace std;

struct MoonCake{
	int pomelo;
	int neko;
	int rabbit;
};

struct Customer{
	char name[20];
	int money;
	MoonCake mooncake;
};

bool moneyEnough(Customer customer); //是否有足夠的錢購買
bool fastEnough(Customer customer); //是否能買到想要的口味
/*your code*/
bool moneyEnough(Customer customer){
	if(customer.money < 50*(customer.mooncake.pomelo+customer.mooncake.neko+customer.mooncake.rabbit)){
		return false;
	}
	return true;
}

struct Current{
	int pomelo;
	int neko;
	int rabbit;
};

Current current;

bool fastEnough(Customer customer){
	if((customer.mooncake.neko > current.neko) || (customer.mooncake.pomelo > current.pomelo) || (customer.mooncake.rabbit > current.rabbit)){
		return false;
	}
	return true;
}
int main(){
	int N;
	cin >> N;
	Customer customer;
	current.neko = 1000;
	current.pomelo = 1000;
	current.rabbit = 1000;
	while(N--){ 
	//input
		cin >> customer.name;
		cin >> customer.money >> customer.mooncake.pomelo >> customer.mooncake.neko >> customer.mooncake.rabbit;
		if(!(fastEnough(customer))){
			cout << "Too slow.\n";
		}else if(!moneyEnough(customer)){
			cout << "Bring more money.\n";
		}else{
			current.neko -= customer.mooncake.neko;
			current.pomelo -= customer.mooncake.pomelo;
			current.rabbit -= customer.mooncake.rabbit;
			cout << customer.name << " got what the class wanted.\n";
		}
	}
}
