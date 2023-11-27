#include <iostream>
#include <cstring>

using namespace std;

struct S{
	int Occ;
	char Car;
	float PerCento;
};

int CONTA(char *T, int d, char C){
	int counter=0;
	for(int i=0;i<d;i++)
		if(T[i]==C)
			counter++;
	return counter;
}
float PERCENTUALE(int X, int Y){
	if(X==0)
		return -1;
	else return (Y*100)/X;
}

int main(){
	S A[128];
	char c;
	char Testo[10000];
	cout << endl << "inserire carattere: ";
	cin >> c;
	int counter=0;
	do{
		Testo[counter++]=c;
		cout << endl << "inserire carattere: ";
		cin >> c;
	} while(c!='.' || Testo[counter-1]!='.');
	int counter2=0;
	bool alreadythere=false;
	cout << endl << "inserire carattere(parte 2): ";
	cin >> c;
	while(c!='#'){
		alreadythere=false;
		for(int i=0;i<counter2;i++)
			if(A[i].Car==c){
				alreadythere=true;	
				cout << endl << "carattere gia' presente";
			}
		if(!alreadythere){
			A[counter2++].Car=c;
		}
		cout << endl << "inserire carattere(parte 2): ";
		cin >> c;
	}
	cout << endl << endl;
	for(int i=0;i<counter2;i++){
		A[i].Occ=CONTA(Testo, counter, A[i].Car);
		A[i].PerCento=PERCENTUALE(counter,A[i].Occ);
		cout << A[i].Car << " " << A[i].Occ << " " <<A[i].PerCento << "%" << endl;
	}
	return 0;
}