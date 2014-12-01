// cout<<system("zenity --file-selection $HOME")<<endl;
	// string s0;
	// grafo g;
	// a:
	// system("zenity --list --title \"automatom\" --column \" opciones \" \"crear\" \"cargar\"");
	// cin>>s0;
	// cout<<s0<<endl;
	// if (s0=="crear")
	// {
	// 	string s,tmp;
	// 	int step=0,m,x,y,a,b;
	// 	char c;
	// 	s=system("zenity --title \"automatom\" --forms --text=\"ingrese datos del automata(recuerde que el primer estado es 0)\" --separator=\";\" --add-entry=\"numero de nodos\"  --add-entry=\"numero de aristas\"  --add-entry=\"numero de nodos iniciales\" --add-entry=\"numero de nodos finales\"");
	// 	for (int i = 0; i < s.length(); ++i)
	// 	{
	// 		while(s[i]!=';'){
	// 			tmp+=s[i];
	// 			i++;
	// 		}
	// 		x=atoi(tmp.c_str());
	// 		tmp.clear();
	// 		grafo gg(x);
	// 		g=gg;
	// 		i++;
	// 		while(s[i]!=';'){
	// 			tmp+=s[i];
	// 			i++;
	// 		}
	// 		y=atoi(tmp.c_str());
	// 		tmp.clear();
	// 		i++;
	// 		while(s[i]!=';'){
	// 			tmp+=s[i];
	// 			i++;
	// 		}
	// 		a=atoi(tmp.c_str());
	// 		tmp.clear();
	// 		i++;
	// 		while(s[i]!=';'){
	// 			tmp+=s[i];
	// 			i++;
	// 		}
	// 		b=atoi(tmp.c_str());
	// 		tmp.clear();
	// 	}
	// 	for (int i = 0; i < y; ++i)
	// 	{
	// 		s=system("zenity --title \"automatom\" --forms --text=\"ingrese datos de arista\" --separator=\";\" --add-entry=\"origen\"  --add-entry=\"destino\" --add-entry=\"transicion\"");
	// 		for (int j = 0; j < s.length(); ++j)
	// 		{
	// 			while(s[j]!=';'){
	// 				tmp+=s[j];
	// 				j++;
	// 			}
	// 			x=atoi(tmp.c_str());
	// 			tmp.clear();
	// 			while(s[j]!=';'){
	// 				tmp+=s[j];
	// 				j++;
	// 			}
	// 			m=atoi(tmp.c_str());
	// 			tmp.clear();
	// 			c=s[j+1];
	// 			g.addarista(x,m,c);
	// 		}
	// 	}
	// 	for (int i = 0; i < a; ++i)
	// 	{
	// 		s=system("zenity --title \"automatom\" --text=\"nodo inicial\" --entry=\"nodo\"");
	// 		for (int j = 0; j < s.length(); ++j)
	// 		{
	// 				tmp+=s[j];
	// 		}
	// 		x=atoi(tmp.c_str());
	// 		g.inicial.push_back(x);
	// 	}
	// 	for (int j = 0; j < a; ++j)
	// 	{
	// 		s=system("zenity --title \"automatom\" --text=\"nodo final\" --entry=\"nodo\"");
	// 		for (int j = 0; j < s.length(); ++j)
	// 		{
	// 				tmp+=s[j];
	// 		}
	// 		x=atoi(tmp.c_str());
	// 		g.final.push_back(x);
	// 	}
		// for (int i = 0; i < s.length(); ++i)
		// {
		// 	switch (step){
		// 		case 0:
		// 			while(s[i]!=';'){
		// 				tmp+=s[i];
		// 				i++;
		// 			}
		// 			grafo gg(atoi(tmp.c_str());
		// 			g=gg;
		// 			tmp.clear();
		// 			step++;
		// 			break;
		// 		case 1:	
		// 			while(s[i]!=';'){
		// 				tmp+=s[i];
		// 				i++;
		// 			}
		// 			m=atoi(tmp.c_str());
		// 			tmp.clear();
		// 			step++;
		// 			break;
		// 		case 2:
		// 			for (int j = 0; j < m; ++j)
		// 			{
		// 				while(s[i+j]!='-'){
		// 					tmp+=s[i+j];
		// 					i++;
		// 				}
		// 				x=atoi(tmp.c_str());
		// 				tmp.clear();
		// 				while(s[i+j]!=','){
		// 					tmp+=s[i+j];
		// 					i++;
		// 				}
		// 				y=atoi(tmp.c_str());
		// 				tmp.clear();
		// 				i++;
		// 				c=s[i+j];
		// 				g.addarista(x,y,c);
		// 				i=i+j;
		// 			}
		// 		case 3:

		// 	}
		// }
	}