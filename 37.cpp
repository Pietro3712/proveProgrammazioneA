#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;
struct S{
	float n1;
	float n2;
	char d[11];
};

int max_diff(S* A, int n){
int max=0;
int indice=0;
	for(int i=0;i<n;i++)
		if((abs(A[i].n1-A[i].n2))>max){
			max=abs(A[i].n1-A[i].n2);
			indice=i;
		}
	return indice;
}

int main(){
	/*ifstream f1;
	f1.open("temperature.txt");
	if(f1.fail())
		return 1;
	S T[100];
	int k=0;
	while(!f1.eof() && k<100){
		f1 >> T[k].n1;
		f1 >> T[k].n2;
		f1 >> T[k].d;
		k++;
	}
	f1.close();
	int indice=max_diff(T,k);
	cout << "Massima escursione termica: giorno ";
	int i;
	for(i=0;(T[indice].d)[i]!='/';i++)
		cout << (T[indice].d)[i];
	cout << " del mese ";
	for(i++;(T[indice].d)[i]!='/';i++)
		cout << (T[indice].d)[i];*/
	char M[10][15];
	bool risposta=0;
	do{
		for(int i=0;i<10;i++)
			for(int j=0;j<15;j++)
				M[i][j]=' ';
		int i=0;
		int j=0;
		do{
			cout << endl << "inserire i: ";
			cin >> i;
			cout << endl << "inserire j: ";
			cin >> j;
			while(i<0 || j<0 || i>10 || j>15){
				if(i<0 && j<0)
					break;
				cout << endl << "errore";
				cout << endl << "inserire i: ";
				cin >> i;
				cout << endl << "inserire j: ";
				cin >> j;
			}
			M[i][j]='*';
		} while(i>=0 || j>=0);
		cout << endl << endl;
		for(int i=0;i<10;i++){
			for(int j=0;j<15;j++)
				cout << M[i][j] << " ";
			cout << endl;
		}

		cout << endl << endl << "continuare?: [1/0]   ";
		cin >> risposta;
	} while(risposta==1);
	cout << endl << "fine";
	return 0;
}