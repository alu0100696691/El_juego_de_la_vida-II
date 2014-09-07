#include "vida.h"

int main()
	{
	    int fil,col,num_celulas,i;
	    char resp;
	    
	    
	    system("clear");  //limpiamos pantalla
	    cout << "\n\n\nJUEGO DE LA VIDA\n________________\n\n";
	    cout << "DIMENSION DEL TABLERO: \n";
	    cout << "FILA:    ";
	    cin >> fil;
	    cout << "\nCOLUMNA: ";
	    cin >> col;
	                     
	    Tablero obtablero(fil, col);
	    
	    cout << "\n\nVIDAS CELULAS ALEATORIAS(Y/N): ";
	    cin >> resp;
	    if(resp=='y' || resp=='Y')
			obtablero.vivas_ramdom();
		else
		{
			system("clear");  //limpiamos pantalla
			cout << "\n\nCUANTAS CELULAS: ";
			cin >> num_celulas;
			for(i=0;i<num_celulas;i++)
			{
				cout << "\nFILA: ";
				cin >> fil;
				cout << "\nCOLUMNAS: ";
				cin >> col;
				obtablero.celula[fil][col]->vida==1;
			}
		}
			
	    while(1)
	    {
	        obtablero.dibujar();
	        usleep(1000000);		   //esperamos 100000ms	
	        system("clear");  //limpiamos pantalla
	        obtablero.ciclo();	        
    }
}

