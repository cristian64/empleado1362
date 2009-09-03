#ifndef _InterfazSND_H_
#define _InterfazSND_H_

//#include "Irklang.h"
#include <iostream>

using namespace std;


/** Interfáz del sonido juego que se ocupa de interactuar con Irklang.
*/
class InterfazSND
{
	public:
		
		/// Obtiene la instancia.
		static InterfazSND* getInstancia();
	    
	    /// Destructor por defecto.
	    ~InterfazSND();
	
	    /// Inicia la interfaz.
	    void iniciar();
	    
	private:
	
		 /// Constructor por defecto.
	    InterfazSND();
	    
	    /// Instancia de la clase.
	    static InterfazSND* instancia;
	    
	protected:
	
};
		
#endif
