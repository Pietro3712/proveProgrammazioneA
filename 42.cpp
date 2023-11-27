#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct ind{
	char nome[81];
	char cognome[81];
	char email[81];
};

bool aggiungi(ind* lista, int &n, ind s){
	bool found=false;
	for(int i=0;i<n;i++)
		if(strcmp(lista[i].nome,s.nome)==0 && strcmp(lista[i].cognome,s.cognome)==0){
			strcpy(lista[i].email,s.email);
			return false;
		}
	lista[n++]=s;
	return true;
}
int main(){
	ind m1[1000];
	ifstream in1;
	ifstream in2;
	in1.open("mailinglist.txt");
	in2.open("nuovi.txt");
	if(in1.fail() || in2.fail())
		return 1;
	int k=0;
	while(!in1.eof()){
		in1 >> m1[k].nome;
		in1 >> m1[k].cognome;
		in1 >> m1[k].email;
		k++;
	}
	in1.close();
	ind supporto;
	int modified=0;
	int added=0;
	while(!in2.eof()){
		in2 >> supporto.nome;
		in2 >> supporto.cognome;
		in2 >> supporto.email;
		if(aggiungi(m1,k,supporto))
			added++;
		else modified++;
	}
	in2.close();
	cout << endl << "modificati: " << modified;
	cout << endl << "aggiunti: " << added;
	ofstream fout;
	fout.open("mailinglist_new.txt");
	for(int i=0;i<k;i++)
		fout << m1[i].nome << " " << m1[i].cognome << " " << m1[i].email << endl;
	fout.close();
	bool M[10][40];
	for(int i=0;i<10;i++)
		for(int j=0;j<40;j++)
			M[i][j]=false;
	while(1){
		int x1,y1,x2,y2;
		cout << endl << "inserire prima coppia: ";
		cin >> x1 >> y1;
		cout << endl << "inserire seconda coppia: ";
		cin >> x2 >> y2;
		if(( x1 <0 || y1 <0 || x1> 10 || y1>40 ) || ( x2 < 0 || y2 <0 || x2> 10 || y2>40 )){
			for(int i=0;i<10;i++){		// ^ se almeno uno non e' indice valido
				for(int j=0;j<40;j++)
					if(M[i][j]==true)
						cout << "*" << " ";
					else cout << "  ";
				cout << endl;
			}
			return 0;
		}
		if(x1==x2 && y1<=y2){
			for(int i=0;i<10;i++)
				for(int j=0;j<40;j++)
					if(i==x1 && j>=y1 && j<=y2)
						M[i][j]=true;
		}
		else if(y1==y2 && x1<=x2){	
			for(int i=0;i<10;i++)	
				for(int j=0;j<40;j++)
					if(j==y1 && i>=x1 && i<=x2)
						M[i][j]=true;				
		}
	}
}
// attenzione che else si riferisce all'ultimo if del programma "visibile"
// per cui usare le graffe oppure non usare else if (dipende dal contesto)