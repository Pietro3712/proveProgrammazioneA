#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct interval{
	int inf;
	int sup;
};

bool disgiunti(interval i1, interval i2){
	for(int i=i1.inf;i<=i1.sup;i++)
		for(int j=i2.inf;j<=i2.sup;j++)
			if(i==j)
				return false;

	return true;
}

interval fondi(interval i1, interval i2){		// non sono disgiunti
	interval i3;
	if(i1.inf<=i2.inf)
		i3.inf=i1.inf;
	else i3.inf=i2.inf;
	if(i1.sup>=i2.sup)
		i3.sup=i1.sup;
	else i3.sup=i2.sup;
	return i3;
}

bool leggi_file(char* nome, int n, int* dati){
	ifstream in1;
	char num[10];
	itoa(n,num,10);
	strcat(nome,num);
	in1.open(strcat(nome,".txt"));
	if(in1.fail())
		return false;
	int k=0;
	while(!in1.eof() && k<31){
		in1 >> dati[k++];
	}
	in1.close();
	return true;
}

int main(){
	/*int M[12][31];
	for(int i=0;i<12;i++)
		for(int j=0;j<31;j++)
			M[i][j]=0;
	for(int i=0;i<12;i++){
		int somma=0;
		char nome[101]="mese";
		if(!leggi_file(nome,i+1,M[i])){
			cout << endl << "errre apertura file termino esecuzione";
			return 0;
		}
		for(int j=0;j<31;j++)
			somma+=M[i][j];
		cout << endl << "somma " << i+1 << ": " << somma;
	}*/
	interval a,b;
	do{
	cout << endl << "inserire intervallo a: [inf - sup] ";
	cin >> a.inf >> a.sup;
	cout << endl << "inserire intervallo b: [inf - sup] ";
	cin >> b.inf >> b.sup;
	} while(a.sup<a.inf || b.sup<b.inf);
	interval c;
	if(!disgiunti(a,b)){
		c=fondi(a,b);
		cout << endl << endl << "c: [" << c.inf << " - " << c.sup << "] ";
	}
	else cout << endl << "i due intervalli sono disgiunti";
	return 0;
}