
#include "vida.h"

	 
	int Ccelula::buscarVecinos(int posfil, int poscol,const Tablero& i)
	{
	    
	    vecinos = 0;
	    if(posfil-1 >= 0 and poscol-1 >= 0)
	        if(i.celula[posfil-1][poscol-1]->vida == 1)
	            vecinos++;
	    if(posfil-1 >= 0)
	        if(i.celula[posfil-1][poscol]->vida == 1)
	            vecinos++;
	    if(posfil-1 >= 0 and poscol+1 <= i.col-1)
	        if(i.celula[posfil-1][poscol+1]->vida == 1)
	            vecinos++;
	    if(poscol-1 >= 0)
	        if(i.celula[posfil][poscol-1]->vida == 1)
	            vecinos++;
	    if(poscol+1 <= i.col-1)
	        if(i.celula[posfil][poscol+1]->vida == 1)
	            vecinos++;
	    if(posfil+1 <= i.fil-1 and poscol-1 >= 0)
	        if(i.celula[posfil+1][poscol-1]->vida == 1)
	            vecinos++;
	    if(posfil+1 <= i.fil-1)
	        if(i.celula[posfil+1][poscol]->vida == 1)
	            vecinos++;
	    if(posfil+1 <= i.fil-1 and poscol+1 <= i.col-1)
	        if(i.celula[posfil+1][poscol+1]->vida == 1)
	            vecinos++;
	    
	    return vecinos;
    }
	
	class celulaA: public Ccelula
	{
			
			int actualizarEstado(int posfil, int poscol,const Tablero& i)
			{
				int num_vecinos=0;
				num_vecinos=buscarVecinos(posfil, poscol,i);
				if(num_vecinos == 2 || num_vecinos == 3)  //regla supervivencia tipo A
					return 0;  //tipo A
				else 
					return -1;
			}
	};
	
	class celulaB: public Ccelula
	{
			
			int actualizarEstado(int posfil, int poscol,const Tablero& i)
			{
				int num_vecinos=0;
				num_vecinos=buscarVecinos(posfil, poscol,i);
				if(num_vecinos == 3 || num_vecinos == 4)  //regla supervivencia tipo B
					return 1;  //tipo B
				else 
					return -1;		
			}
	};
	
	class celulaC: public Ccelula
	{
			
			int actualizarEstado(int posfil, int poscol,const Tablero& i)
			{
				int num_vecinos=0;
				num_vecinos=buscarVecinos(posfil, poscol,i);
				if(num_vecinos >= 5)                       //regla supervivencia tipo C
					return 2;  //tipo C
				else 
					return -1;		
			}
	};
	
	
	Tablero::Tablero(int f, int c)
	{
	    fil = f;
	    col = c;
	    
	    
	    
	    celula = new Ccelula **[f];
	    for(int i=0;i<f;i++)
	    {
			celula[i] = new Ccelula*[c];
			for(int j=0;j<c;j++)     
			  celula[i][j]=new celulaA;
	    }
			
	}
	 
	void Tablero::dibujar()
	{
		int tipo=0;
		
		
		for(int f=0; f<fil; f++)
		{
	        for(int c=0; c<col; c++)
	        {
	            if(celula[f][c]->vida == 1)
	            {
					tipo=celula[f][c]->actualizarEstado(f,c,*this);
					//cout << tipo << endl; cin >> tipo;
		
					if(tipo != -1)
					{
						switch(tipo)
						{
							case(0):
							cout << "A";
							break;
							case(1):
							cout << "B";
							break;
							case(2):
							cout << "C";
							break;
							
						}				
					}
		    }					
	            else
	                cout << ". ";
	        }    
	        }
	        cout << endl;
	}
	    
	
	 
	
	 
	void Tablero::vivas_ramdom()
	{
		for(int f=0; f<fil; f++)
	    {
	        for(int c=0; c<col; c++)   //todas las celulas con turno z "no actualizado"
	        {
	            celula[f][c]->vida = rand()%2;
	            celula[f][c]->turno = 'z';
	        }
	    }
	}
		
	void Tablero::sustituyeCelula(int f, int c, int tipo)
	{
		
	  int num_vecinos=celula[f][c]->buscarVecinos(f, c,*this);
	  
	  switch(tipo)  
	  {
		  case(0): //celula tipo A
		  
		  if(celula[f][c]->vida == 0 && celula[f][c]->turno=='z')
					  {
						  if(num_vecinos == 3)
						  {
							  celula[f][c]->turno=='y';
							  celula[f][c]->vida = 1;
							  delete celula[f][c];
							  celula[f][c] = new celulaA;
						  }
						  else
						  {
							  celula[f][c]->vida = 0;
							  celula[f][c]->turno=='y';
						  }
					  }
				  if (celula[f][c]->vida == 1)
					  {
						  if(num_vecinos == 2 || num_vecinos == 3 && celula[f][c]->turno=='z')
						  {
							  celula[f][c]->turno=='y';
							  celula[f][c]->vida = 1;
							  
						  }
						  else
						  {
							  celula[f][c]->vida = 0;
							  celula[f][c]->turno=='y';
						  }
					  }
		  break;
		  case(1):  //celula tipo B
		  
		  if(celula[f][c]->vida == 0 && celula[f][c]->turno=='z')
					  {
						  if(num_vecinos == 3 || num_vecinos == 4)
						  {
							  celula[f][c]->turno=='y';
							  celula[f][c]->vida = 1;
							  delete celula[f][c];
							  celula[f][c] = new celulaB;
						  }
						  else
						  {
							  celula[f][c]->vida = 0;
							  celula[f][c]->turno=='y';
						  }
					  }
				  if (celula[f][c]->vida == 1)
					  {
						  if(num_vecinos == 3 || num_vecinos == 4 && celula[f][c]->turno=='z')
						  {
							  celula[f][c]->turno=='y';
							  celula[f][c]->vida = 1;
						  }
						  else
						  {
							  celula[f][c]->vida = 0;
							  celula[f][c]->turno=='y';
						  }
					  }
		  break;
		  
		case(2):   //celula tipo C
		
		if(celula[f][c]->vida == 0 && celula[f][c]->turno=='z')
					{
						if(num_vecinos == 3 || num_vecinos == 4 || num_vecinos == 6)
						{
							celula[f][c]->turno=='y';
							celula[f][c]->vida = 1;
							delete celula[f][c];
							celula[f][c] = new celulaC;
						}
						else
						{
							celula[f][c]->vida = 0;
							celula[f][c]->turno=='y';
			{			}
					}
				if (celula[f][c]->vida == 1)
					{
						if(num_vecinos >= 5  && celula[f][c]->turno=='z')
						{
							celula[f][c]->turno=='y';
							celula[f][c]->vida = 1;
						}
						else
						{
							celula[f][c]->vida = 0;
							celula[f][c]->turno=='y';
						}
					}
		break;
		
		 
		  
		  
		  
	  }            	
	}
	}
	
	void Tablero::ciclo()
	{    
		int tipo=-1;
	    for (int f=0; f<fil; f++)	
	    {
	        for(int c=0; c<col; c++)
	        {
	            tipo=celula[f][c]->actualizarEstado(f,c,*this);	           
	            if(tipo != -1)
		      sustituyeCelula(f,c,tipo);  				
	        }
	    }
	 
	    
	}
	
	
	
	Tablero::~Tablero()
	{
		
		for(int i = 0; i < fil; i++) 
			delete[] celula[i]; 
			
		delete[] celula; 
	};
	
	
