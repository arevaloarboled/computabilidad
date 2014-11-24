#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class node{
public:
	bool mark;
	bool supermark;
	string name;
public:
	node():mark(false),name(""){}
	node(string n):mark(false),name(n){}
	// ~node();
	void marc(){
		mark=true;
	}

	void supermarc(){
		supermark=true;
	}

	void desmarc(){
		mark=false;
	}

	void desmarcs(){
		mark=false;
		supermark=false;
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
	vector<char> lenguaje;
	vector <node> nodos;
public:
	grafo(){
		int x;
		cin>>x;
		nodos.resize(x);
		aristas.resize(x);
		for (int i = 0; i < aristas.size(); ++i)
		{
			aristas[i].resize(x);
		}
	}

	grafo(int x){
		nodos.resize(x);
		aristas.resize(x);
		for (int i = 0; i < aristas.size(); ++i)
		{
			aristas[i].resize(x);
		}
	}

	void crear(){
		int x,y,z;
		cin>>y;
		char s;
		for (int i = 0; i < y; ++i)
		{
			cin>>x>>z>>s;
			aristas[x][z].colocar(s);
			if (find(lenguaje.begin(),lenguaje.end(),s)==lenguaje.end() && s!='#')
			{
				lenguaje.push_back(s);
			}
		}
		cout<<"lenguaje"<<endl;
		for (int i = 0; i < lenguaje.size(); ++i)
		{
			cout<<lenguaje[i];
		}
		cout<<endl;
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

	void desmarcgrafo(){
		for (int i = 0; i < nodos.size(); ++i)
		{
			nodos[i].desmarc();
		}
	}

	void desmarcsgrafo(){
		for (int i = 0; i < nodos.size(); ++i)
		{
			nodos[i].desmarcs();
		}
	}

	void print(){
		for (int i = 0; i < aristas.size(); ++i)
		{
			for (int j = 0; j < aristas[i].size(); ++j)
			{
				for (int k = 0; k < aristas[i][j].valor.size(); ++k)
				{
					cout<<aristas[i][j].valor[k]<<" ";
				}
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
				//cout<<"1"<<endl;
				for (int j = 0; j <aristas[state].size() ; ++j) //buscar entre las aristas del nodo inicial
				{
					//cout<<"2"<<endl;
					for (int k = 0; k < aristas[state][j].valor.size(); ++k) //busca entre la arista, las posibles sub aristas a probar
					{
						//cout<<"3"<<endl;
						//cout<<iterator<<" "<<s.size()<<" "<<j<<" "<<state<< endl;
						if (aristas[state][j].valor[k]==s[iterator]) //una arista cumple la condicion, entonces tira un proceso alli
						{
							//cout<<"4"<<endl;
							int m=iterator+1;
							//cout<<iterator<<" "<<s.size()<<" "<<j<<" "<<" "<<state<< endl;
							//if (find(final.begin(),final.end() ,j)!=final.end() && m==s.size())
							//cout<<"iterator: "<<iterator<<endl;
							int stmp=state;
							if (find(final.begin(),final.end() ,j)!=final.end() && m==s.size())
							{
								return true;
							}
							else if(acepta(s,iterator=m,state=j,init=false)){
								return true;
							}
							state=stmp;
							//cout<<"iterator: "<<iterator<<endl;
							iterator--;
						}
						else if(aristas[state][j].valor[k]=='#')
						{
							//cout<<"5"<<endl;
							int m=iterator;
							int stmp=state;
							if(acepta(s,iterator=m,state=j,init=false))
								return true;
							state=stmp;
						}
					}
				}
			}
		}
		else{
			//cout<<"6"<<endl;
			//cout<<iterator<<" "<<s.size()<<" "<<state<< endl;
			if (iterator == s.size())
			{
				//cout<<"7"<<endl;
				//cout<<"miow"<<" "<<iterator<<" "<<s.size()<<" "<<state<< endl;
				//std::vector<int>::iterator it=find(final.begin(),final.end() ,state);
				//cout<<*it<<" "<<state<<endl;
				//cout<<*final.begin()<<" "<<*final.end()<<endl;
				if (find(final.begin(),final.end() ,state) == final.end())
				{
					//cout<<"8"<<endl;
					return false;
				}
				else{
					//cout<<state<<endl;
					//cout<<"9"<<endl;
					return true;
				}
			}
			else{
				for (int j = 0; j <aristas[state].size() ; ++j) //buscar entre las aristas del nodo inicial
				{
					//cout<<"10"<<endl;
					for (int k = 0; k < aristas[state][j].valor.size(); ++k) //busca entre la arista, las posibles sub aristas a probar
					{
						//cout<<"11"<<endl;
						//cout<<iterator<<" "<<s.size()<<" "<<state<< endl;
						if (aristas[state][j].valor[k]==s[iterator]) //una arista cumple la condicion, entonces tira un proceso alli
						{
							//cout<<"12"<<endl;
							int m=iterator+1;
							int stmp=state;
							if(acepta(s,iterator=m,state=j,init=false))
								return true;
							state=stmp;
						}
						else if(aristas[state][j].valor[k]=='#')
						{
							//cout<<"13"<<endl;
							int m=iterator;
							int stmp=state;
							if(acepta(s,iterator=m,state=j,init=false))
								return true;
							state=stmp;
						}

					}
				}
			}
		}
		//cout<<"14"<<endl;
		return false;
	}

	string exprecion(int state=0, bool init=true){
		string s;
		if (init)
		{
			for (int i = 0; i < inicial.size(); ++i)
			{
				state=inicial[i];//escoge uno de los nodos iniciales
				desmarcgrafo();
				//cout<<"1"<<endl;
				for (int j = 0; j <aristas[state].size() ; ++j) //buscar entre las aristas del nodo inicial
				{
					//cout<<"2"<<endl;
					for (int k = 0; k < aristas[state][j].valor.size(); ++k) //busca entre la arista, las posibles sub aristas a probar
					{
						//cout<<"3"<<endl;
						//cout<<iterator<<" "<<s.size()<<" "<<j<<" "<<state<< endl;
						if (aristas[state][j].valor[k]!='#' && aristas[state][j].valor[k]!=' ') //una arista cumple la condicion, entonces tira un proceso alli
						{
							//cout<<"4"<<endl;
							nodos[state].marc();
							s+=aristas[state][j].valor[k];
							if (find(final.begin(), final.end(),state)!=final.end())
							{
								s+='+';
							}
							int stmp=state;
							s.append(exprecion(state=j,init=false));
							state=stmp;
						}
					}
				}
			}
		}
		else{
			//cout<<"6"<<endl;
			//cout<<iterator<<" "<<s.size()<<" "<<state<< endl;
			if (nodos[state].mark==true)
			{
				s+='*';
				return s;
			}
			else{
				for (int j = 0; j <aristas[state].size() ; ++j) //buscar entre las aristas del nodo inicial
				{
					//cout<<"10"<<endl;
					for (int k = 0; k < aristas[state][j].valor.size(); ++k) //busca entre la arista, las posibles sub aristas a probar
					{
						//cout<<"11"<<endl;
						//cout<<iterator<<" "<<s.size()<<" "<<state<< endl;
						if (aristas[state][j].valor[k]!='#' && aristas[state][j].valor[k]!=' ') //una arista cumple la condicion, entonces tira un proceso alli
						{
							//cout<<"4"<<endl;
							nodos[state].marc();
							s+=aristas[state][j].valor[k];
							if (find(final.begin(), final.end(),state)!=final.end())
							{
								s+=aristas[state][j].valor[k];
								s+='+';
							}
							int stmp=state;
							s.append(exprecion(state=j,init=false));
							state=stmp;
						}
					}
				}
			}
		}
		//s+='+';
		return s;
	}

	bool desm(){
		for (int i = 0; i < nodos; ++i)
		{
			if (nodos[i].mark==true)
			{
				return false;
			}
		}
		return true;
	}

	vector<int> what(int x,char y){
		vector<int> v;
		for (int i = 0; i < aristas[x].size(); ++i)
		{
			for (int j = 0; j < aristas[x][i].valor.size(); ++j)
			{
				if (aristas[x][i].valor[j]==y)
				{
					v.push_back(i);
				}
			}
		}
		return v;
	}

	bool determinista(){
		grafo gg(nodos.size());
		vector<int> v;
		vector< vector<int>> dstate;
		desmarcsgrafo();
		string s;
		vector <string> yea;
		ostringstream temp;
		//vector< vector< vector<int>>> dtrans;

		for(int j=0;j<nodos.size();++j){
			nodos[j].marc();
			for (int i = 0; i < lenguaje.size(); ++i)
			{
				v=what(j,lenguaje[i]);
				if (v.size()!=0)
				{
					s="";
					for (int i = 0; i < v.size(); ++i)
					{
						temp<<c[i];
						s+=temp.str();
						s+=' ';
					}
					s+="* ";
					temp<<j;
					s+=tmep.str();
					s+=' ';
					
					if (v.size()>=2)
					{
						dstate.push_back(v);
					}
				}
			}
		}
		int tmp;
		for (int i = 0; i < nodos.size(); ++i)
		{
			for (int j = 0; j < dstate; ++j)
			{
				for (int k = 0; k < dstate[j].size(); ++k)
				{
					for (int l = 0; l < aristas[dstate[j][k]].size(); ++l)
					{
						for (int m = 0; m < aristas[dstate[j][k]][l].valor.size(); ++m)
						{
							for (int n = 0; n < gg.aristas[i][l].valor.size(); ++n)
							{
								if (gg.aristas[i][l].valor[n]!=aristas[dstate[j][k]][l].valor[m])
								{
									gg.aristas[i][l].valor[n].push_back(aristas[dstate[j][k]][l].valor[m]);
								}
							}							
						}						
					}
				}
			}
			tmp=i;
		}
		for (int i = 0; i <nodos.size() ; ++i)
		{
			if (nodos[i].mark!=true)
			{
				gg.aristas[tmp]=aristas[i];
			}
		}

		//solapan D:
		for (int i = 0; i < dstate.size(); ++i)
		{
			for (int j = 0; j < dstate[i].size(); ++j)
			{
				if (find(inicial.begin(), inicial.end(),dstate[i][j])!=inicial.end())
				{
					gg.inicial.push_back(i);
				}
				if (find(final.begin(), final.end(),dstate[i][j])!=final.end())
				{
					gg.inicial.push_back(i);
				}
			}
		}
		return gg;		
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
	g.crear();
	g.print();
	// cout<<"miow"<<endl;
	string s;
	cin >> s;
	cout<<g.exprecion()<<endl;
	if (g.acepta(s))
	{
		cout<<"yes!"<<endl;
	}
	else{
		cout<<"no D:"<<endl;
	}
	return 0;
}
