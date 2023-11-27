#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct elem{
	char nome[51];
	int val;
};
int riduci(elem* A, elem* B, int n){
	int k=0;
	for(int i=0;i<n;i++){
		bool onemore=false;
		bool alreadythere=false;
		for(int j=0;j<n;j++)
			if(strcmp(A[i].nome,A[j].nome)==0 && i!=j){
				alreadythere=false;
				for(int l=0;l<k;l++)
					if(strcmp(A[i].nome,B[l].nome)==0)
						alreadythere=true;
				if(!alreadythere){
					strcpy(B[k].nome,A[i].nome);
					B[k].val=A[i].val+A[j].val;
					onemore=true;
				}
			}
		if(onemore)
			k++;
		else if(!onemore && !alreadythere){
			strcpy(B[k].nome,A[i].nome);
			B[k++].val=A[i].val;
		}
	}
	return k;
}
int main(){
	/*elem A[10];
	elem B[10];
	int k=0;
	bool end=false;
	do{
		char str[33];
		cout << endl << "Dai una stringa ( . per smettere): ";
		cin.getline(str,33);
		if(strcmp(str,".")!=0){
			strcpy(A[k].nome,str);
			cout << "Dai un numero intero: ";
			cin >> A[k].val;
			cin.ignore();
			k++;
		}
		else end=true;
	} while(!end);
	int Bsize=riduci(A,B,k);
	cout << endl << "Sequenza ridotta: ";
	for(int i=0;i<Bsize;i++)
		cout << "[" << B[i].nome << "," << B[i].val << "] ";*/
	char nome1[33];
	char nome2[33];
	char copia1[70];
	char copia2[33]="_";
	cout << "inserire nome del primo file : ";
	cin.getline(nome1,33);
	cout << "inserire nome del secondo file : ";
	cin.getline(nome2,33);
	strcpy(copia1,nome1);
	strcat(copia2,nome2);
	ifstream in1;
	in1.open(strcat(nome1,".txt"));
	ifstream in2;
	in2.open(strcat(nome2,".txt"));
	if(in1.fail() || in2.fail())
		return 1;
	int vect1[30];
	int k1=0;
	while(!in1.eof())
		in1 >> vect1[k1++];
	in1.close();
	while(!in2.eof())
		in2 >> vect1[k1++];
	in2.close();
	//bubble sort
	for(int i=0;i<k1-1;i++)
		for(int j=0;j<k1-1;j++)
			if(vect1[j]>vect1[j+1]){
				int tmp=vect1[j];
				vect1[j]=vect1[j+1];
				vect1[j+1]=tmp;
			}
	ofstream output;
	strcat(copia1,copia2);
	cout << endl << "copiati " << k1 << " numeri nel file " << copia1;
	output.open(strcat(copia1,".txt"));
	for(int i=0;i<k1;i++)
		output << vect1[i] << " ";
	output.close();
	return 0;
}