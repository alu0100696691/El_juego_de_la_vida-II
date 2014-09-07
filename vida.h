#if !defined(_VIDA_H_)
#define _VIDA_H_
#include <iostream>
#include <cstdlib>




using namespace std;

// CONTENIDO DEL FICHERO DE CABECERA (VIDA.H)


class Tablero;

class Ccelula 
{
	public:	
		bool vida;  // 1 viva, 0 muerta
		char turno; // z sin actualizar y actualizada
		int vecinos;     //numeros de celulas vecinas
		int buscarVecinos(int posf, int posc,const Tablero& i);
		virtual int actualizarEstado(int posfil, int poscol,const Tablero& i) {};  // devuelve tipo de la celula, metodo virtual
		
		
		
};			



class Tablero
	{
	public:
	    int fil;
		int col;	
	 
	    Tablero(int f, int c);  //constructor
	    
	    void dibujar();
	    void ciclo();
	    void vivas_ramdom();   //ponemos celulas vivas ramdom
	    Ccelula ***celula;   //inclusion clase celula
	   
	    void sustituyeCelula(int f, int c, int tipo);   //cambia de tipo una celula dada por tipo A,B,C
	    
		~Tablero();   //destructor
	};

	

	
	 
#endif  //_VIDA_H_
