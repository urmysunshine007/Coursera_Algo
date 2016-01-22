#include<iostream>
#include<bitset>
#include<math.h>
using namespace std;

struct Node{
	int value;
	int fathervalue;
	int step;
	int movei, movej; // move from father
	Node(int v, int f, int s, int i, int j) :value(v), fathervalue(f), step(s),movei(i), movej(j){}
	Node(){}
};

const int maxi = pow(2, 16) - 1;
bitset<200000> flags;
Node myQueue[200000]; // queue
int qHead; int qTail; // pointer

int flip(int fathervalue, int i, int j){
	bitset<16> ft(fathervalue);
	ft[4 * i + j].flip();
	if (i == 0){
		ft[4 * (i + 1) + j].flip();
	}
	else if (i == 3){
		ft[4 * (i - 1) + j].flip();
	}
	else{
		ft[4 * (i + 1) + j].flip();
		ft[4 * (i - 1) + j].flip();
	}
	if (j == 0){
		ft[4 * i + j + 1].flip();
	}
	else if (j == 3){
		ft[4 * i + j - 1].flip();
	}
	else{
		ft[4 * i + j + 1].flip();
		ft[4 * i + j - 1].flip();
	}
	return ft.to_ulong();
}

int Bfs(int number, int allon){ //allon == 1 turn all on
	flags.reset();
	qHead = 0; qTail = 1;
	myQueue[qHead] = Node(number, -1, 0, -1, -1);
	while (qHead < qTail){
		int value = myQueue[qHead].value;
		if (value == 0 || value == maxi){
			return true;
		}
		bitset<16> bsvalue(value);
		for (int i = 0; i<4; i++){
			for (int j = 0; j<4; j++){
					int newvalue = flip(value, i, j);
					if (flags[newvalue] == 1) continue;
					bitset<16> temp(newvalue);
					myQueue[qTail++] = Node(newvalue, value, myQueue[qHead].step+1, i, j);
					flags[newvalue] = 1;
			}
		}
		qHead++;
	}
	return false;
}

int main(){
	bitset<16> bst;
	int a;
	for (int i = 0; i<4; i++){
		char a[5];
		cin >> a;
		for (int j = 0; j<4; j++){
			if (a[j] == 'w') bst[4 * i + j] = 1;
		}
	}

	int b = flip(bst.to_ulong(), 1, 2);
	bitset<16> bst1(b);
	int s1 = -1, s2 = -1;
	if (Bfs(bst.to_ulong(), 1)) {
		s1 = myQueue[qHead].step;
	}
	if (Bfs(bst.to_ulong(), 0)) {
		s2 = myQueue[qHead].step;
	}
	if(s1<0 && s2<0){
		cout << "Impossible" << endl;
	}
	else
	{
		if (s1 < 0) cout << s2 << endl;
		else if (s2 < 0) cout << s1 << endl;
		else if (s1 < s2) cout << s1 << endl;
		else cout << s2<<endl;
	}
	return 0;
}