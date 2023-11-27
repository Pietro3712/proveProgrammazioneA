#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct d{
	int num;
	char lett;
};

bool confronta(d* A, d* B, int n, int k){
	int samenumbers=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i].num==B[j].num && A[i].lett==B[j].lett)
				samenumbers++;
	if(samenumbers==k)
		return true;
	return false;
}

int main(){
	/*d Q1[3];
	d Q2[3];
	for(int i=0;i<3;i++){
		cout << "numero: ";
		cin >> Q1[i].num;
		cin.ignore(),
		cout << "carattere: ";
		cin >> Q1[i].lett;
	}
	cout << endl << endl;
	for(int i=0;i<3;i++){
		cout << "numero: ";
		cin >> Q2[i].num;
		cin.ignore(),
		cout << "carattere: ";
		cin >> Q2[i].lett;
	}
	cout << endl << confronta(Q1,Q2,3,2);*/
	char nomefile[71];
	cout << "dai nome al file: (con estensione) ";
	cin.getline(nomefile,71);
	ifstream f1;
	f1.open(nomefile);
	if(f1.fail()){
		cout << endl << "file non esistente";
		return 1;
	}
	int M[100][4];
	int i=0;
	int j=0;
	while(!f1.eof()){
		if(i==100){
			cout << endl <<"Matrice piena";
			return 1;
		}
		f1 >> M[i][j++];
		if(j==4){
			j=0;
			i++;
		}
	}
	f1.close();
	int m=0;
	cout << "inserire intero m: ";
	cin >> m;
	cin.ignore();
	int contatori[4];
	for(int i=0;i<4;i++)
		contatori[i]=0;
	for(int j=0;j<4;j++){
		for(int i=0;i<100;i++){
			if(M[i][j]==m)
				contatori[j]++;
		}
	}
	ofstream f2;
	char nomeoutput[111]="statistiche_per_";
	f2 << "Presenze del numero " << m <<":" << endl;
	f2.open(strcat(nomeoutput,nomefile));
	for(int i=0;i<4;i++)
		f2 << "colonna " << i+1 << ":\t" << contatori[i] << endl;
	f2.close();
}