#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node{
public:
	bool mark;
	string name;
public:
	node():mark(false),name(""){}
	node(string n):mark(false),name(n){}
	// ~node();
	void marc(){
		mark=true;
	}
	void desmarc(){
		mark=false;
	}
};

class arista
{
public:
	vector <char> valor;
public:
	arista(){
		char s=' ';
		valor.push_back(s);
	};
	arista(char s){
		valor.push_back(s);
	};
	void colocar(char s){
		if (valor.size()==1 && valor[0]==' ')
		{
			valor[0]=s;
		}
		else{
			valor.push_back(s);
		}
	}
	// ~arista();

	/* data */
};

class grafo{
public:
	vector <vector<arista> > aristas;
	vector <int> inicial;
	vector <int> final;
	vector <node> nodos;
public:
	grafo(){
		int x,y,z;
		char s;
		cin>>x>>y;
		aristas.resize(x);
		for (int i = 0; i < aristas.size(); ++i)
		{
			aristas[i].resize(x);
		}
		for (int i = 0; i < y; ++i)
		{
			cin>>x>>z>>s;
			aristas[x][z].colocar(s);	
		}
		cin>>x>>y;
		for (int i = 0; i < x; ++i)
		{
			cin>>z;
			inicial.push_back(z);
		}
		for (int i = 0; i < y; ++i)
		{
			cin>>z;
			final.push_back(z);
		}
	}
	void addarista(int x, int y, char valor){
		aristas[x][y].colocar(valor);
	}
	void print(){
		for (int i = 0; i < aristas.size(); ++i)
		{
			for (int j = 0; j < aristas[i].size(); ++j)
			{
				cout<<aristas[i][j].valor[0];
				cout<<"||";
			}
			cout<<endl;
			cout<<"======================================================="<<endl;
		}
	}

	bool acepta(string s,int iterator=0,int state=0, bool init=true){
		if (init)
		{
			for (int i = 0; i < inicial.size(); ++i)
			{
				state=inicial[i];//escoge uno de los nodos iniciales
				for (int j = 0; j <aristas[state].size() ; ++j) //buscar entre las aristas del nodo inicial
				{
					for (int k = 0; k < aristas[state][j].valor.size(); ++k) //busca entre la arista, las posibles sub aristas a probar
					{
						if (aristas[state][j].valor[k]==s[iterator]) //una arista cumple la condicion, entonces tira un proceso alli
						{
							if(acepta(s,iterator++,state=j,init=false))
								return true;
						}
					}
				}
			}
		}
		else{
			if (iterator == s.size()-1)
			{
				if (find(final.begin(),final.end() ,state)!= final.end())
				{
					return false;	
				}
				else{
					return true;
				}
			}
			else{
				for (int j = 0; j <aristas[state].size() ; ++j) //buscar entre las aristas del nodo inicial
				{
					for (int k = 0; k < aristas[state][j].valor.size(); ++k) //busca entre la arista, las posibles sub aristas a probar
					{
						if (aristas[state][j].valor[k]==s[iterator]) //una arista cumple la condicion, entonces tira un proceso alli
						{
							if(acepta(s,iterator++,state=j,init=false))
								return true;
						}
					}
				}
			}
		}
		return false;
	}
};

// class automata
// {
// public:
// 	automata();
// 	~automata();

// 	/* data */
// };

int main(int argc, char const *argv[])
{
	grafo g;
	g.print();
	cout<<"miow"<<endl;
	string s;
	cin >> s;
	if (g.acepta(s))
	{
		cout<<"yes!"<<endl;
	}
	else{
		cout<<"no D:"<<endl;
	}
	return 0;
}