#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Ind{
	char nome[81];
	char cognome[81];
	char email[81];
};

int maggiori(float* A, int n, float s, int* M){
	int k=0;
	for(int j=0;j<n;j++)
		if(A[j]>s)
			M[k++]=j;
	return k;
}

bool add(Ind* v, int &n, Ind s){
	for(int i=0;i<n;i++)
		if(strcmp(v[i].nome,s.nome)==0 && strcmp(v[i].cognome,s.cognome)==0){
			strcpy(v[i].email,s.email);
			return false;
		}
	v[n++]=s;
	return true;
}

int main(){
	/*char nomefile[81];
	cout << "dai nome al file: ";
	cin.getline(nomefile,81);
	ifstream f1;
	f1.open(nomefile);
	if(f1.fail()){
		cout << endl << "file non trovato";
		return 1;
	}
	float Temp[7][24];
	int count1=0;
	int count2=0;
	while(!f1.eof() && count1<7){
		f1 >> Temp[count1][count2++];
		if(count2==24){
			count2=0;
			count1++;
		} 
	}
	if(count1!=7 || count2!=0){
		cout << endl << "non ho tutte le temperature";
		return 1;
	}
	f1.close();
	float v=0;
	cout << "inserire valore v: ";
	cin >> v;
	cin.ignore();
	for(int i=0;i<7;i++){
		cout << endl << "giorno " << i+1 << " - ore: ";
		int HoursIndex[24];
		int numore=maggiori(Temp[i],24,v,HoursIndex);
		for(int j=0;j<numore;j++)
			cout << HoursIndex[j] << " ";
	}*/
	Ind A[20];
	int n=0;
	for(int i=0;i<3;i++){
		Ind supporto;
		cout << "dai nome: ";
		cin.getline(supporto.nome,81);
		cout << "dai cognome: ";
		cin.getline(supporto.cognome,81);
		cout << "dai email: ";
		cin.getline(supporto.email,81);
		bool asd=add(A,n,supporto);
	}
	cout << endl << "risultato:";
	for(int i=0;i<n;i++)
		cout << endl << A[i].nome << " " << A[i].cognome << " " << A[i].email;
	return 0;
}