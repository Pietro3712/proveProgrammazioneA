#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct S{
	char* a;
	float b;
	float c;
};

int elimina_estremi(int* A, int n, int* C){
	int min=A[0];
	int max=A[0];
	for(int i=0;i<n;i++){
		if(A[i]>=max)
			max=A[i];
		if(A[i]<min)
			min=A[i];
	}
	int k=0;
	for(int i=0;i<n;i++)
		if(A[i]!=max && A[i]!=min)
			C[k++]=A[i];
	return k;
}

bool trova(S* P[], int n, char* str, int& index){
	for(int i=0;i<n;i++)
		if(strcmp(P[i]->a,str)==0){
			index=i;
			return true;
		}
	index=0;
	return false;
}

int main(){
	char nomefile[65];
	char nomecopia[80];
	cout << endl << "dai nome al file (senza estensione) ";
	cin.getline(nomefile,65);
	while(cin.fail()){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << endl << "dai nome al file (senza estensione) ";
		cin.getline(nomefile,65);
	}
	strcpy(nomecopia,nomefile);
	int Numeri[10000];
	int k1=0;
	ifstream f1;
	f1.open(strcat(nomefile,".txt"));
	if(f1.fail())
		return 1;
	while(!f1.eof())
		f1 >> Numeri[k1++];
	f1.close();
	int Numeri_rimasti[10000-2];
	int k2=elimina_estremi(Numeri,k1,Numeri_rimasti);
	ofstream f2;
	f2.open(strcat(nomecopia,"-ridotti.txt"));
	for(int i=0;i<k2;i++)
		f2 << Numeri_rimasti[i] << " ";
	return 0;
}