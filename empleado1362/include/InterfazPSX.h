#ifndef _InterfazPSX_H_
#define _InterfazPSX_H_

//#include "PhysX.h"
#include <iostream>

using namespace std;


/** Interfáz física del juego que se ocupa de interactuar con PhysX.
*/
class InterfazPSX
{
	public:
		
		/// Obtiene la instancia.
		static InterfazPSX* getInstancia();
	    
	    /// Destructor por defecto.
	    ~InterfazPSX();
	
	    /// Inicia la interfaz.
	    void iniciar();
	    
	private:
	
		 /// Constructor por defecto.
	    InterfazPSX();
	    
	    /// Instancia de la clase.
	    static InterfazPSX* instancia;
	    
	protected:
	
};
		
#endif
