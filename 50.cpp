#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct elem{
	char nome[51];
	int x_1;
	int x_2;
	int x_3;
};

void aggiungi_suffisso(char* A,char* B){
	int Alen=strlen(A);
	int indexpointer=-1;
	for(int i=0;i<Alen;i++)
		if(A[i]=='.')
			indexpointer=i;
	int i=0;
	if(indexpointer!=-1){
		for(i=0;i<indexpointer;i++)
			B[i]=A[i];
		B[indexpointer]='\0';
		strcat(B," - REV");
		for(;i<Alen;i++)
			B[i+6]=A[i];
	}
	else{
		strcpy(B,A);
		strcat(B," - REV");
	}
}

float arrotonda(float x){
	int i=x;
	float d=x-i;
	if(d<=0.3)
		return i;
	else if(d<0.7)
		return i+0.5;
	else
		return i+1;
}

int media(elem* A, int n, int i){	// 1<=i<=3
	int sum=0;
	switch(i){
		case 1:
			for(int j=0;j<n;j++)
				sum+=A[j].x_1;
			break;
		case 2:
			for(int j=0;j<n;j++)
				sum+=A[j].x_2;
			break;
		case 3:
			for(int j=0;j<n;j++)
				sum+=A[j].x_3;
			break;
	}
	return sum/n;
}

int main(){
	char nomefile[33];
	cout << "dai un nome al file: ";
	cin.getline(nomefile,33);
	ifstream in1;
	in1.open(nomefile);
	if(in1.fail())
		return 1;
	ofstream out1;
	char nomeoutput[50];
	aggiungi_suffisso(nomefile,nomeoutput);
	out1.open(nomeoutput);
	while(!in1.eof()){
		char cognome[33];
		float a,b,c;
		in1 >> cognome;
		in1 >> a;
		in1 >> b;
		in1 >> c;
		float sum=a+b+c;
		sum=arrotonda(sum);
		out1 << cognome << " " << sum << endl;
	}
	in1.close();
	out1.close();
	elem A[3] = {{"alfa",3,4,5},{"beta",5,6,7},{"gamma",7,8,9}};
	cout << endl << "media: " << media(A,3,2);
	return 0;
}