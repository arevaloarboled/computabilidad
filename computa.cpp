#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <fstream>
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


bool desmm(vector <node> v){
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].mark==false)
		{
			return true;
		}
	}
	return false;
}

string to_string(int x){
	string Result;       
	ostringstream convert; 
	convert << x;     
	Result = convert.str();
	return Result;
}

class grafo{
public:
	vector <vector<arista> > aristas;
	vector <int> inicial;
	vector <int> final;
	vector<char> alfabeto;
	vector <node> nodos;
public:
	grafo(){
		int x=0;
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
		cout<<"numero de aristas: ";
		cin>>y;
		char s;
		for (int i = 0; i < y; ++i)
		{
			cout<<"introdusca arista( origen destino transicion ): ";
			cin>>x>>z>>s;
			aristas[x][z].colocar(s);
			if (find(alfabeto.begin(),alfabeto.end(),s)==alfabeto.end() && s!='#')
			{
				alfabeto.push_back(s);
			}
		}
		cout<<"alfabeto"<<endl;
		for (int i = 0; i < alfabeto.size(); ++i)
		{
			cout<<alfabeto[i];
		}
		cout<<endl;
		cout<<"numero de nodos iniciales: ";
		cin>>x;
		for (int i = 0; i < x; ++i)
		{
			cout<<"nodo inicial: ";
			cin>>z;
			inicial.push_back(z);
		}
		cout<<"numero de nodos finales: ";
		cin>>y;
		for (int i = 0; i < y; ++i)
		{
			cout<<"nodo final: ";
			cin>>z;
			final.push_back(z);
		}
	}

	void addarista(int x, int y, char valor){
		aristas[x][y].colocar(valor);
	}
	void agregarista(){
		// cout<<"m"<<endl;
		vector <arista> v;
		// cout<<"mm"<<endl;
		v.resize(nodos.size()+1);
		// cout<<"mmm"<<endl;
		for (int i = 0; i < aristas.size(); ++i)
		{
			// cout<<"mmmm"<<endl;
			arista a;
			aristas[i].push_back(a);
		}
		// cout<<"mmmmm"<<endl;
		aristas.push_back(v);
		// cout<<"mmmmmm"<<endl;
		node m;
		nodos.push_back(m);
		// cout<<"mmmmmmm"<<endl;
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
		for (int i = 0; i < inicial.size(); ++i)
		{
			cout<<inicial[i]<<"||";
		}
		cout<<endl;
		for (int i = 0; i < final.size(); ++i)
		{
			cout<<final[i]<<"||";	
		}
		cout<<endl;
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
							// int stmp=state;
							if (find(final.begin(),final.end() ,j)!=final.end() && m==s.size())
							{
								return true;
							}
							else if(acepta(s,iterator=m,state=j,init=false)){
								return true;
							}
							// state=stmp;
							//cout<<"iterator: "<<iterator<<endl;
							iterator--;
						}
						else if(aristas[state][j].valor[k]=='#')
						{
							//cout<<"5"<<endl;
							int m=iterator;
							// int stmp=state;
							if(acepta(s,iterator=m,state=j,init=false))
								return true;
							// state=stmp;
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
							// int stmp=state;
							if(acepta(s,iterator=m,state=j,init=false))
								return true;
							// state=stmp;
						}
						else if(aristas[state][j].valor[k]=='#')
						{
							//cout<<"13"<<endl;
							int m=iterator;
							// int stmp=state;
							if(acepta(s,iterator=m,state=j,init=false))
								return true;
							// state=stmp;
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
		for (int i = 0; i < nodos.size(); ++i)
		{
			if (nodos[i].mark==false)
			{
				return true;
			}
		}
		return false;
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

	vector <int> whate(int x){
		vector<int> v;
		for (int i = 0; i < aristas[x].size(); ++i)
		{
			for (int j = 0; j < aristas[x][i].valor.size(); ++j)
			{
				if (aristas[x][i].valor[j]=='#')
				{
					v.push_back(i);
				}
			}
		}
		return v;
	}

	grafo determinista(){
		grafo gg(1);
		vector < vector<int> > v;
		vector <int> tmp;
		vector <int> tmpp;
		gg.inicial.push_back(0);
		gg.alfabeto=alfabeto;
		bool o=false;
		// cout<<"1"<<endl;
		for (int i = 0; i < inicial.size(); ++i)
		{
			tmp.push_back(inicial[i]);
			tmpp=whate(inicial[i]);
			// cout<<"2"<<endl;
			for (int j = 0; j < tmpp.size() ; ++j)
			{
				// cout<<"3"<<endl;
				tmp.push_back(tmpp[j]);
			}
		}
		v.push_back(tmp);
		tmp.clear();
		// cout<<"4"<<endl;
		for (int i = 0; i < gg.nodos.size(); ++i)
		{
			// cout<<"5"<<endl;
			for (int k = 0; k < v[i].size(); ++k)
			{
				tmpp=whate(v[i][k]);
				for (int w = 0; w < tmpp.size() ; ++w)
				{
					tmp.push_back(tmpp[w]);
					o=true;
					// cout<<"10"<<endl;
				}
			}
			// cout<<"9"<<endl;
			// for (int j = 0; j < alfabeto.size(); ++j)
			// {
			// 	cout<<alfabeto[j]<<endl;
			// }
			for (int j = 0; j < alfabeto.size(); ++j)
			{
				// cout<<"6"<<endl;
				for (int k = 0; k < v[i].size(); ++k)
				{
					tmpp=what(v[i][k],alfabeto[j]);
					// cout<<"7"<<endl;
					for (int w = 0; w < tmpp.size(); ++w)
					{
						// cout<<"8"<<endl;
						tmp.push_back(tmpp[w]);
					}
					// tmpp=whate(v[i][k]);
					// // cout<<"9"<<endl;
					// for (int w = 0; w < tmpp.size() ; ++w)
					// {
					// 	tmp.push_back(tmpp[w]);
					// 	// cout<<"10"<<endl;
					// }
				}
				if (tmp.size()>0)
				{
					// cout<<"11"<<endl;
					int h=0;
					bool b=false;
					int q;
					for (int c = 0; c < v.size(); ++c)
					{
							for (int w = 0; w < v[c].size(); ++w)
							{
								for (int d = 0; d < tmp.size(); ++d)
								{
									// cout<<"asdfsadf: "<<v[c][w]<<" "<<tmp[d]<<endl;;
									if (find(v[c].begin(), v[c].end(),tmp[d])!=v[c].end())
									if(v[c][w]==tmp[d])
									{
										h++;
										// cout<<"snfsjf "<<h<<endl;
										break;
									}	
								}
							}
							if (h==tmp.size() && h==v[c].size())
							{
								b=true;
								q=c;
								break;
							}	
							else{
								h=0;
							}
					}
					// if (find(v.begin(), v.end(),tmp)==v.end())
					if(!b)
					{
						// cout<<"12"<<endl;
						// node m;
						// gg.nodos.push_back(m);
						gg.agregarista();
						// cout<<"nodos: "<<gg.aristas.size()<<" "<<gg.nodos.size()<<endl;
						v.push_back(tmp);
						// cout<<"por aki"<<endl;
						gg.addarista(i,gg.nodos.size()-1,alfabeto[j]);
						// cout<<":D"<<endl;
					}
					else{
						// cout<<"13"<<endl;
						if (o)
						{
							gg.addarista(i,q+1,alfabeto[j]);
							o=false;
						}
						else{
							gg.addarista(i,q,alfabeto[j]);							
						}
						// for (int l = 0; l < v.size(); ++l)
						// {
						// 			// cout<<"14"<<endl;
						// 	// int h=0;
						// 	// bool b=false;
						// 	// // for (int c = 0; c < v.size(); ++c)
						// 	// // {
						// 	// 		for (int w = 0; w < v[l].size(); ++w)
						// 	// 		{
						// 	// 			for (int d = 0; d < tmp.size(); ++d)
						// 	// 			{
						// 	// 				// cout<<"asdfsadf: "<<v[c][w]<<" "<<tmp[d]<<endl;;
						// 	// 				// if (find(v[c].begin(), v[c].end(),tmp[d])!=v[c].end())
						// 	// 				if(v[l][w]==tmp[d])
						// 	// 				{
						// 	// 					h++;
						// 	// 					// cout<<"snfsjf "<<h<<endl;
						// 	// 					break;
						// 	// 				}	
						// 	// 			}
						// 	// 		}
						// 	// 		if (h==tmp.size() && h==v[l].size())
						// 	// 		{
						// 	// 			b=true;
						// 	// 			// break;
						// 	// 		}	
						// 	// 		else{
						// 	// 			h=0;
						// 	// 		}
						// 	// // }
						// 	// if (v[l]==tmp)
						// 	if(b)
						// 	{
						// 		// cout<<"lol"<<endl;
						// 		// cout<<"size: "<<v.size()<<" "<<gg.aristas.size()<<endl;
						// 		gg.addarista(i,l,alfabeto[j]);			
						// 		// cout<<"15"<<endl;
						// 		break;
						// 	}
						// }
					}
					tmp.clear();
				}
			}
		}
		// cout<<"16"<<endl;
		for (int i = 0; i < v.size(); ++i)
				{
					// cout<<"17"<<endl;
					for (int j = 0; j <v[i].size() ; ++j)
					{
						// cout<<"18"<<endl;
						if (find(final.begin(), final.end(),v[i][j])!=final.end())
						{
							gg.final.push_back(i);
							// cout<<"19"<<endl;
							break;
						}
					}
				}
				// cout<<"miow"<<endl;
		return gg;		
	}

	grafo reverso(){
		vector <vector<arista> > arist;
		vector <int> ini;
		vector <int> fin;
		ini=final;
		fin=inicial;
		arist.resize(nodos.size());
		for (int i = 0; i < arist.size(); ++i)
		{
			arist[i].resize(nodos.size());
		}
		for (int i = 0; i < arist.size(); ++i)
		{
			for (int j = 0; j <arist.size() ; ++j)
			{
				for (int k = 0; k <aristas[i][j].valor.size() ; ++k)
				{
					arist[j][i].colocar(aristas[i][j].valor[k]);
		// cout<<"asdfasfasfasf"<<endl;
				}
			}
		}
		grafo gg(nodos.size());
		// cout<<"alfabet! ";
		// for (int i = 0; i < alfabeto.size(); ++i)
		// {
		// 	cout<<alfabeto[i];
		// }
		// cout<<endl;
		gg.alfabeto=alfabeto;
		gg.nodos=nodos;
		gg.inicial=ini;
		// cout<<"miow"<<endl;
		gg.final=fin;
		gg.aristas=arist;
		return gg;
	}

	void complemento(){
		vector <int> v;
		for (int i = 0; i < nodos.size(); ++i)
		{
			if (find(final.begin(), final.end(),i)==final.end())
			{
				v.push_back(i);
			}
		}
		final=v;
	}

	void expor(){
		string expor;
		expor += "digraph g{ \n rankdir=LR; \n";
		for (int i = 0; i < nodos.size(); ++i)
		 {
		 	if (find(inicial.begin(), inicial.end(),i)!=inicial.end() && find(final.begin(), final.end(),i)!=final.end())
		 	{
		 		expor += "node [shape = doublecircle, label=\" q";
		 		expor += to_string(i);
		 		expor += "\" ] q";
				expor += to_string(i);
				expor += ";";
		 		expor += "node [shape = point ] qq";
		 		expor += to_string(i);
		 		expor += ";";
		 		expor += "\n qq";
		 		expor += to_string(i);
		 		expor += " -> q";
		 		expor += to_string(i);
		 		expor += "; \n";
		 	}
		 	else if (find(inicial.begin(), inicial.end(),i)!=inicial.end())
		 	{
		 		expor += "node [shape = circle, label=\" q";
		 		expor += to_string(i);
		 		expor += "\" ] q";
				expor += to_string(i);
				expor += ";\n";
		 		expor += "node [shape = point ] qq";
		 		expor += to_string(i);
		 		expor += ";";
		 		expor += "\n qq";
		 		expor += to_string(i);
		 		expor += " -> q";
		 		expor += to_string(i);
		 		expor += ";\n";
		 	}
		 	else if (find(final.begin(), final.end(),i)!=final.end())
		 	{
		 		expor += "node [shape = doublecircle, label=\" q";
		 		expor += to_string(i);
		 		expor += "\" ] q";
				expor += to_string(i);
				expor += ";\n";
		 	}
		 	else{
		 		expor += "node [shape = circle, label=\" q";
		 		expor += to_string(i);
		 		expor += "\" ] q";
				expor += to_string(i);
				expor += ";\n";
		 	}
		 } 

		 for (int i = 0; i < aristas.size(); ++i)
		 {
		 	for (int j = 0; j < aristas.size(); ++j)
		 	{
		 		for (int k = 0; k < aristas[i][j].valor.size(); ++k)
		 		{
		 			if (aristas[i][j].valor[k]!=' ')
			 		{
			 			expor += "q";
			 			expor += to_string(i);
			 			expor += " -> q";
			 			expor += to_string(j);
			 			expor += " [ label = \"";
			 			expor += aristas[i][j].valor[k];
			 			expor += " \" ];\n";
			 		}
		 		}
		 	}
		 }
		 expor += " }";
		 ofstream output;
		 output.open("img.dot");
		 output << expor;
		 output.close();
		 system("dot -Tpng img.dot -o img.png");
	}

	void cargar(string name){
		string s;
		ifstream inp;
		inp.open(name.c_str());
		inp>>s;
		grafo gg(1);
		for (int i = 0; i < s.size(); ++i)
		{
			// cout<<s[i]<<endl;
			gg.alfabeto.push_back(s[i]);
		}
		// cout<<alfabeto.size()<<endl;
		// int i=0;
		// while(s[i]!=' '){
		// 	gg.alfabeto.push_back(s[i]);
		// 	i++;
		// }
		int x,y,a,b;
		char c;
		inp>>s;
		x=atoi(s.c_str());
		grafo ggg(x);
		ggg.alfabeto=gg.alfabeto;
		gg=ggg;
		inp>>s;
		y=atoi(s.c_str());
		for (int i = 0; i < y; ++i)
		{
			inp>>s;
			a=atoi(s.c_str());
			inp>>s;
			b=atoi(s.c_str());
			inp>>c;
			gg.addarista(a,b,c);
		}
		inp>>s;
		y=atoi(s.c_str());
		for (int i = 0; i < y; ++i)
		{
			inp>>s;
			a=atoi(s.c_str());
			gg.inicial.push_back(a);
		}
		inp>>s;
		y=atoi(s.c_str());
		for (int i = 0; i < y; ++i)
		{
			inp>>s;
			a=atoi(s.c_str());
			gg.final.push_back(a);
		}

		inp.close();
		nodos=gg.nodos;
		aristas=gg.aristas;
		inicial=gg.inicial;
		final=gg.final;
		alfabeto=gg.alfabeto;


		// char s[100000];
		// inp.open(name.c_str());
		// // inp>>s;
		// // cout<<s<<endl;
		// inp.getline(s,100000);
		// int i=0;
		// grafo gg(0);
		// // cout<<s[i]<<endl;
		// // vector <vector<arista> > aristass;
		// // vector <int> iniciall;
		// // vector <int> finall;
		// // vector<char> alfabetoo;
		// // vector <node> nodoss;
		// while(s[i]!=' '){
		// 	// cout<<s[i]<<endl;
		// 	gg.alfabeto.push_back(s[i]);
		// 	i++;
		// }
		// // i=0;
		// inp>>s;
		// i++;
		// string tmp;
		// while(s[i]!=' '){
		// 	// cout<<s[i]<<endl;
		// 	tmp+=s[i];
		// 	// inp>>s;
		// 	i++;
		// }
		// i++;
		// // cout<<s<<endl;
		// // cout<<s[i]<<endl;
		// gg.nodos.resize(atoi(tmp.c_str()));
		// gg.aristas.resize(atoi(tmp.c_str()));
		// for (int i = 0; i < gg.aristas.size(); ++i)
		// {
		// 	gg.aristas[i].resize(atoi(tmp.c_str()));
		// }
		// tmp.clear();
		// while(s[i]!=' '){
		// 	// cout<<s[i]<<endl;
		// 	tmp+=s[i];
		// 	// inp>>s;
		// 	i++;
		// }
		// i++;
		// // cout<<s[i]<<endl;
		// int n=atoi(tmp.c_str());
		// for (int j = 0; j < n; ++j)
		// {
		// 	int x,y,z;
		// 	tmp.clear();
		// 	while(s[i]!=' '){
		// 		// cout<<s[i]<<endl;
		// 		tmp+=s[i];
		// 		// inp>>s;
		// 		i++;
		// 	}	
		// 	x=atoi(tmp.c_str());
		// 	i++;
		// 	// cout<<s[i]<<endl;
		// 	tmp.clear();
		// 	while(s[i]!=' '){
		// 		// cout<<s[i]<<endl;
		// 		tmp+=s[i];
		// 		// inp>>s;
		// 		i++;
		// 	}
		// 	y=atoi(tmp.c_str());
		// 	i++;
		// 	// cout<<s[i]<<endl;
		// 	tmp.clear();
		// 	gg.addarista(x,y,s[i]);
		// 	i++;
		// }
		// while(s[i]!=' '){
		// 	// cout<<s[i]<<endl;
		// 	tmp+=s[i];
		// 	// inp>>s;
		// 	i++;
		// }
		// i++;
		// // cout<<s[i]<<endl;
		// n=atoi(tmp.c_str());
		// tmp.clear();
		// for (int i = 0; i < n; ++i)
		// {
		// 	while(s[i]!=' '){
		// 		// cout<<s[i]<<endl;
		// 		tmp+=s[i];
		// 		// inp>>s;
		// 		i++;
		// 	}	
		// 	i++;
		// 	// cout<<s[i]<<endl;
		// 	gg.inicial.push_back(atoi(tmp.c_str()));
		// 	tmp.clear();
		// }
		// while(s[i]!=' '){
		// 	// cout<<s[i]<<endl;
		// 	tmp+=s[i];
		// 	// inp>>s;
		// 	i++;
		// }
		// i++;
		// // cout<<s[i]<<endl;
		// n=atoi(tmp.c_str());
		// tmp.clear();
		// for (int i = 0; i < n; ++i)
		// {
		// 	while(s[i]!=' '){
		// 		// cout<<s[i]<<endl;
		// 		tmp+=s[i];
		// 		// inp>>s;
		// 		i++;
		// 	}	
		// 	i++;
		// 	// cout<<s[i]<<endl;
		// 	gg.final.push_back(atoi(tmp.c_str()));
		// 	tmp.clear();
		// }
		// inp.close();
		// nodos=gg.nodos;
		// aristas=gg.aristas;
		// inicial=gg.inicial;
		// final=gg.final;
		// alfabeto=gg.alfabeto;
		// // while(!inp.eof()){
		// // 	inp >> s;
		// // }
	}

	void grabar(string name){
		string expor;
		for (int i = 0; i < alfabeto.size(); ++i)
		{
			expor+=alfabeto[i];
		}
		expor+=" ";
		expor+=to_string(nodos.size());
		expor+=" ";
		string tmp;
		int n=0;
		for (int i = 0; i < nodos.size(); ++i)
		{
			for (int j = 0; j < nodos.size(); ++j)
			{
				for (int k = 0; k < aristas[i][j].valor.size(); ++k)
				{
					if (aristas[i][j].valor[k]!=' ')
					{
						n++;
						tmp+=to_string(i);
						tmp+=" ";
						tmp+=to_string(j);
						tmp+=" ";
						tmp+=aristas[i][j].valor[k];
						tmp+=" ";
					}
				}
			}
		}
	expor+=to_string(n);
	expor+=" ";
	expor+=tmp;
	expor+=to_string(inicial.size());
	expor+=" ";
	for (int i = 0; i < inicial.size(); ++i)
	{
		expor+=to_string(inicial[i]);
		expor+=" ";
	}
	expor+=to_string(final.size());
	expor+=" ";
	for (int i = 0; i < final.size(); ++i)
	{
		expor+=to_string(final[i]);
		expor+=" ";
	}
	ofstream output;
	name+=".puj";
	output.open(name.c_str());
	output << expor;
	output.close();
	}
};

grafo minimizacion(grafo g){
	// cout<<"asdf"<<endl;
	g=g.reverso();
	// g.print();
	// cout<<"step 1"<<endl;
	g=g.determinista();
	// g.print();
	// cout<<"step 2"<<endl;
	g=g.reverso();
	// g.print();
	// cout<<"step 3"<<endl;
	g=g.determinista();
	return g;
}


grafo nion(grafo g , grafo go ){
	grafo gg(2+g.nodos.size()+go.nodos.size());
	gg.addarista(0,1,'#');
	gg.inicial.push_back(0);
	int n=1;
	for (int i = 0; i < g.nodos.size(); ++i)
	{
		for (int j = 0; j < g.nodos.size(); ++j)
		{
			gg.aristas[i+n][j+n]=g.aristas[i][j];
			// if (find(g.inicial.begin(), g.inicial.end(),i)!=g.inicial.end())
			// {
			// 	gg.inicial.push_back(i+n);
			// }
			if (find(g.final.begin(), g.final.end(),i)!=g.final.end())
			{
				gg.final.push_back(i+n);
			}
		}
	}
	n=n+g.nodos.size();
	gg.addarista(0,n+1,'#');
	n++;
	for (int i = 0; i < go.nodos.size(); ++i)
	{
		for (int j = 0; j < go.nodos.size(); ++j)
		{
			gg.aristas[i+n][j+n]=go.aristas[i][j];
			// if (find(go.inicial.begin(), go.inicial.end(),i)!=go.inicial.end())
			// {
			// 	gg.inicial.push_back(i+n);
			// }
			if (find(go.final.begin(), go.final.end(),i)!=go.final.end())
			{
				gg.final.push_back(i+n);
			}
		}
	}
	gg.print();
	// vector <char> miow;
	// for (int i = 0; i < g.alfabeto.size(); ++i)
	// {
	// 	// cout<<"sdkhfdsahfsda"<<endl;
	// 	// miow.push_back(g.alfabeto[i]);
	// 	gg.alfabeto.push_back(g.alfabeto[i]);
	// }
	gg.alfabeto=g.alfabeto;
	for (int i = 0; i < go.alfabeto.size(); ++i)
	{
		if (find(gg.alfabeto.begin(), gg.alfabeto.end(),go.alfabeto[i])==gg.alfabeto.end())
		{
			// miow.push_back(go.alfabeto[i]);
			// cout<<"sdksandjfkdshajkfshlfs"<<endl;
			gg.alfabeto.push_back(go.alfabeto[i]);
		}
	}

	// gg.alfabeto=miow;
	return gg;
}

// class automata
// {
// public:
// 	automata();
// 	~automata();

// 	/* data */
// };

int main(int argc, char const *argv[])
{
	int a,b,c;
	grafo g(0);
	while(1){
		while(1){
			cout<<"¿que desea hacer?"<<endl;
			cout<<"1.crear automata: "<<endl;
			cout<<"2.cargar automata: "<<endl;
			cin>>a;
			if (a==1)
			{
				cout<<"numero de estados: ";
				cin>>b;
				grafo gg(b);
				g=gg;
				g.crear();
				break;
			}
			if (a==2)
			{
				cout<<"cual desea cargar? "<<endl;
				// system("ls >> tmp.txt");
				// ifstream ip;
				//  ip.open("tmp.txt");
				//  string line;
				//  vector <string> vs;
				//  // while(getline(output,line)){
				//  ip>>line;
				//  	if (substr)
				//  	{
				//  		vs.push_back(line);
				//  		cout<<vs.size()<<") "<<line<<endl;
				//  	}
				//  // }
				//  cin>>c;
				//  cout<<vs[c]<<endl;
				string ss;
				cin>>ss;
				g.cargar(ss);
				for (int i = 0; i < g.alfabeto.size(); ++i)
				{
					cout<<g.alfabeto[i]<<endl;
				}
				// g.expor();
				// system("display img.png");
				break;
			}
		}
		while(1){
			int n;
			cout<<"que desea hacer?"<<endl;
			cout<<"1) grabar"<<endl;
			cout<<"2) determinismo"<<endl;
			cout<<"3) minimizacion"<<endl;
			cout<<"4) ver"<<endl;
			cout<<"5) complemento"<<endl;
			cout<<"6) cadena"<<endl;
			cout<<"7) union"<<endl;
			cout<<"8) reverso(plus)"<<endl;
			cout<<"0) salir"<<endl;
			cin>>n;
			if (n==0)
			{
				break;
			}
			if (n==1)
			{
				cout<<"como lo deseas guardar?"<<endl;
				string ss;
				cin>>ss;
				g.grabar(ss);
			}
			if (n==4)
			{
				g.expor();
				system("display img.png");
			}
			if (n==2)
			{
				grafo gg(0);
				gg=g.determinista();
				bool bb=false;
				for (int i = 0; i < g.aristas.size(); ++i)
				{
					for (int j = 0; j < g.aristas.size(); ++j)
					{
						for (int k = 0; k < g.aristas[i][j].valor.size(); ++k)
						{
							if (g.aristas[i][j].valor[k]!=gg.aristas[i][j].valor[k])
							{
								b=true;
							}
						}
					}
				}
				// if (equal(g.nodos.begin(),g.nodos.end(),gg.nodos.begin()) && equal(g.aristas.begin(), g.aristas.end(), gg.aristas.begin()) && equal(g.alfabeto.begin(),g.alfabeto.end(), gg.alfabeto.begin()) && equal(g.inicial.begin(),g.inicial.end(),gg.inicial.begin()) && equal(g.final.begin(),g.final.end(),gg.final.begin()))
				if(bb)
				{
					cout<<"ERROR!, ya es determinista"<<endl;
				}
				else{
					g=gg;
				}
			}
			if (n==6)
			{
				cout<<"ingrese cadena: ";
				string s;
				cin>>s;
				if (g.acepta(s))
				{
					cout<<"yes!"<<endl;
				}
				else{
					cout<<"no!"<<endl;
				}
			}
			if (n==3)
			{
				g=g.determinista();
				g=minimizacion(g);
			}
			if (n==5)
			{
				g.complemento();
			}
			if (n==7)
			{
				string ss;
				grafo gg(0);
				cout<<"cual desea unir?"<<endl;
				cin>>ss;
				gg.cargar(ss);
				g=nion(g,gg);
			}
			if (n==8)
			{
				g=g.reverso();
			}
		}
	}
	// grafo g;
	// g.crear();
	// g.print();
	// // // cout<<"miow"<<endl;
	// string s;
	// cin >> s;
	// if (g.acepta(s))
	// {
	// 	cout<<"yes!"<<endl;
	// }
	// else{
	// 	cout<<"no D:"<<endl;
	// }
	// g=g.determinista();
	// g.print();
	// // g=minimizacion(g);
	// // g=g.determinista();
	// g.print();
	// // if (g.acepta(s))
	// // {
	// // 	cout<<"yes!"<<endl;
	// // }
	// // else{
	// // 	cout<<"no D:"<<endl;
	// // }
	// g.expor();
	return 0;
}
