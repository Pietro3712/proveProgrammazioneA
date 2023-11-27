#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct S{
	int X1;
	int X2;
	int X3;
};

bool ordinato(int* A, int n){
	for(int i=0;i<n-1;i++)
		if(A[i]>=A[i+1])
			return false;
	return true;
}

int elimina_zeri(int* V, int n){
	int counter=0;
	int k=0;
	for(int i=0;i<n;i++)
		if(V[i]!=0)		
			V[k++]=V[i];	// testo ambiguo non si puo' eliminare una cella di mem 
		else counter++;		// usando vettore statico classico
	return counter;
}

//RELAZIONE DI ORDINE: a precede b se e solo se la somma 
//dei campi di a è minore della somma dei campi di b

bool precede(S a, S b){
	if((a.X1+a.X2+a.X3)<(b.X1+b.X2+b.X3))
		return true;	// a precede b
	else return false;
}

bool ordinato2(S* A, int n){
	for(int i=0;i<n-1;i++)
		if(!precede(A[i],A[i+1]))
			return false;
	return true;
}

int main(){
	int S[1000];
	int num=0;
	cout << "inserire num: ";
	cin >> num;
	for(int i=0;i<num;i++){
		cout << "inserire: ";
		cin >> S[i];
	}
	int numzeri=elimina_zeri(S,num);
	if(ordinato(S,(num-numzeri)))
		cout << endl << "ordinato" << endl;
	else cout << endl << "non ordinato" << endl;
    char nome1[33];
	char nome2[33];
	char nome3[101];
	cout << "dai un nome al primo file: ";
	cin.getline(nome1,33);
	cout << endl << "dai un nome al secondo file: ";
	cin.getline(nome2,33);
	strcpy(nome3,"somma_");
	strcat(nome3,nome1);
	strcat(nome3,"_");
	ifstream file1;
	ifstream file2;
	file1.open(strcat(nome1,".txt"));
	file2.open(strcat(nome2,".txt"));
	ofstream file3;
	file3.open(strcat(nome3,nome2));
	if(file1.fail() || file2.fail())
		return 1;
	while(!file1.eof() && !file2.eof()){
		float n1,n2;
		file1 >> n1;		// testo ambiguo (stessa posizione di inizio?)
		file2 >> n2;
		file3 << n1+n2 << " ";
	}
	file1.close();
	file2.close();
	file3.close();
	
	S dati[3];
	for(int i=0;i<3;i++){
		cout << endl << "inserire i 3 elems della prima struttura: ";
		cin >> dati[i].X1 >> dati[i].X2 >> dati[i].X3;
	}
	if(ordinato2(dati,3))
		cout << endl << "ordinato" << endl;
	else cout << endl << "non ordinato" << endl;
	return 0;
}