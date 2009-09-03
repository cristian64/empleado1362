/// Fichero de cabecera de la clase InterfazIA.
/** \file InterfazIA.h
 */

#ifndef _INTERFAZIA_H
#define _INTERFAZIA_H

//#include "MElopienso.h"
#include <iostream>

using namespace std;


/** Interfáz de la inteligencia artificial del juego que se ocupa de interactuar con MElopienso.
*/
class InterfazIA
{
	public:
		
		/// Obtiene la instancia.
		static InterfazIA* getInstancia();
	    
	    /// Destructor por defecto.
	    ~InterfazIA();
	
	    /// Inicia la interfaz.
	    void iniciar();
	    
	private:
	
		 /// Constructor por defecto.
	    InterfazIA();
	    
	    /// Instancia de la clase.
	    static InterfazIA* instancia;
	    
	protected:
	
};
		
#endif
