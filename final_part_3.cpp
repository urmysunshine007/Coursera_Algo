#include<iostream>
using namespace std;

int num(int n, int m){
	if (n == 1) return 1;
	if (m == 1) return 1;
	if (m>n) return num(n, n);
	if (m<n) return (num(n - m, m) + num(n, m - 1));
	if (m == n) return (num(n, n - 1) + 1);
}

int main(){
	int n;
	while (cin >> n){
		cout << num(n, n) << endl;
	}
	return 0;
}