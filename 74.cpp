#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct coppia{
	char primo[51];
	char secondo[51];
};

bool sostituisci(coppia *A, int n, char *s, char *r){
	for(int i=0;i<n;i++)
		if(strcmp(A[i].primo,s)==0){
			strcpy(r,A[i].secondo);
			return true;
		}
	return false;
}

bool permutazione(int *A, int *B, int n){		// con array booleani
	bool perm[n];
	for(int i=0;i<n;i++)
		perm[i]=false;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i]==B[j])
				perm[i]=true;
	for(int i=0;i<n;i++)
		if(!perm[i])
			return false;
	return true;
}

bool permutazione2(int* A, int* B, int n){		// senza array booleani
	bool perm=true;
	for(int i=0;i<n;i++){
		perm=false;
		for(int j=0;j<n;j++)
			if(A[i]==B[j]){
				perm=true;
				break;
			}
		if(!perm)
			return false;
	}
	return true;
}

bool permutazione3(int* A, int* B, int n, int i=0){		// ricorsiva
	if(i==n)
		return true;
	for(int j=0;j<n;j++)
		if(A[i]==B[j] && permutazione3(A,B,n,++i))
				return true;
	return false;
}

int main(){
	int A[5]={3,5,2,8,7};
	int B[5]={2,3,8,5,7};
	cout << endl << permutazione(A,B,5);
	cout << endl << permutazione2(A,B,5);
	cout << endl << permutazione3(A,B,5);
	/*int n;
	int M[100][5];
	cout << "inserire n: ";
	cin >> n;
	int k=0;
	int k2=0;
	while(n>=0){
		if(k2==5){
			k++;
			k2=0;
		}
		M[k][k2++]=n;
		cout << "inserire n: ";
		cin >> n;
	}
	int B[5];
	cout << "[ ";
	for(int j=0;j<5;j++){
			B[j]=M[0][j];
			cout << M[0][j] << " ";
		}
	cout << " ]" << endl;
	for(int i=0;i<=k;i++){
		if(!permutazione(M[i],B,5)){
			cout << "[ ";
			for(int j=0;j<5;j++)
				cout << M[i][j] << " ";
			cout << " ]" << endl;
		}
	}*/
	// ho modificato rispetto all'originale cosi' e' piu' figo
	/*coppia mappa[]={{"x","per"},{"cmq","comunque"},{"nn","non"},{"pk","perchè"},{"cn","con"},{"ke","che"},{"vlv","volevo"}};
	char nomefile[81];
	cout << endl << "inserire nomefile: ";
	cin.getline(nomefile,81);
	ifstream f1;
	char copia[81];
	strcpy(copia,nomefile);
	f1.open(strcat(nomefile,".txt"));
	ofstream f2;
	f2.open(strcat(copia,"_sviluppato.txt"));
	char s[100];
	char r[100];
	while(f1>>s){
		if(sostituisci(mappa,7,s,r))
			f2 << r;
		else
			f2 << s;
		f2.put(' ');
	}
	cout << endl << "finito" << endl;
	f1.close(); 
	f2.close();*/
	return 0;
}