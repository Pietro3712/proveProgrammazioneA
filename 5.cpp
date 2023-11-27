#include <iostream>
#include <cstring>
using namespace std;

struct S{
	int R;
	char C;
};

bool CONTROLLA(S *M, int d){
	for(int i=0;i<d;i+=2){
			if(i!=0 && M[i].C==M[i-1].C)
				return false;
			if(i!=d-1 && M[i].C==M[i+1].C)
				return false;
	}
	return true;
}	

void INIZIALIZZA(S *M, int n, char k, int x){
	for(int i=0;i<n;i++)
		if(M[i].R==x)
			M[i].C=k;
}

int main(){
	S Mappa[100];
	int x;
	int n=0;
	cout << "inserisci x: ";
	cin >> x;
	while(x>=0){
		Mappa[n++].R=x;
		cout << "inserisci x: ";
		cin >> x;
	}
	do{
		cout << endl << endl;
		for(int i=0;i<n;i++){
			cout << "Inserisci y: ";
			cin >> Mappa[i].C;
		}
	} while(CONTROLLA(Mappa,n));

	return 0;
}