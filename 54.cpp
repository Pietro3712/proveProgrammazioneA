#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct coppia{
	char parola1[101];
	char parola2[101];
	int ris;
};

int cerca(coppia* coppie, int n, char* parola){
	for(int i=0;i<n;i++)
		if(strcmp(coppie[i].parola1,parola)==0)
			return i;
	return -1;
}

int main(){
	ifstream f1;
	f1.open("dizionario.txt");
	if(f1.fail())
		return 1;
	coppia elenco[1000];
	int k=0;
	while(!f1.eof()){
		if(k==1000)
			return 1;
		f1 >> elenco[k].parola1;
		f1 >> elenco[k++].parola2;
	}
	f1.close();
	char parola[33];
	cout << "dai una parola in italiano: ";
	cin.getline(parola,33);
	while(strcmp(parola,"stop")!=0){
		int f=cerca(elenco,k,parola);
		if(f!=-1){
			char parolasupp[33];
			cout << "dai la corrispondente parola in inglese: ";
			cin.getline(parolasupp,33);
			if(strcmp(elenco[f].parola2,parolasupp)==0){
				elenco[f].ris=1;
				cout << "Corretto";
			}
			else{
				elenco[f].ris=-1;
				cout << "Sbagliato";
			}
		}
		else cout << "la parola " << parola << " non e' contenuta nel dizionario";
		cout << endl << "dai una parola: ";
		cin.getline(parola,33);
	}
	cout << "Tradotte correttamente:";
	for(int i=0;i<k;i++)
		if(elenco[i].ris==1)
			cout << endl << "\t" << elenco[i].parola1;

	float M[4][8];
	ifstream in1;
	in1.open("dati1.txt");
	if(in1.fail())
		return 1;
	int i=0;
	int j=0;
	while(!in1.eof() && i<4){
		if(j==8){
			i++;
			j=0;
		}
		in1 >> M[i][j++];
	}
	in1.close();
	float M_rid[2][4];
	int k1=0;
	int k2=0;
	for(int i=0;i<4;i+=2)
		for(int j=0;j<8;j+=2){
			float media=0;
			media=M[i][j]+M[i][j+1]+M[i+1][j]+M[i+1][j+1];
			if(k2==4){
				k2=0;
				k1++;
			}
			M_rid[k1][k2++]=media/4;
		}
	char nomefile[81];
	cout << endl << "dai nome al file: ";
	cin.getline(nomefile,81);
	ofstream f2;
	f2.open(nomefile);
	for(int i=0;i<=k1;i++){
		for(int j=0;j<k2;j++)
			f2 << M_rid[i][j] << " ";
		f2 << endl;
	}
	return 0;
}