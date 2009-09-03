#ifndef _InterfazINF_H_
#define _InterfazINF_H_

//#include "Mysql.h"
#include <iostream>

using namespace std;


/** Interfáz de la información que se encarga de interactuar con la base de datos.
*/
class InterfazINF
{
	public:
		
		/// Obtiene la instancia.
		static InterfazINF* getInstancia();
	    
	    /// Destructor por defecto.
	    ~InterfazINF();
	
	    /// Inicia la interfaz.
	    void iniciar();
	    
	private:
	
		 /// Constructor por defecto.
	    InterfazINF();
	    
	    /// Instancia de la clase.
	    static InterfazINF* instancia;
	    
	protected:
	
};
		
#endif
