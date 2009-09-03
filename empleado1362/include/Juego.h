#ifndef _Juego_H_
#define _Juego_H_

#include "InterfazGFX.h"
#include "InterfazIA.h"
#include "InterfazPSX.h"
#include "InterfazINF.h"
#include "InterfazSND.h"
//#include "ManejadorEventos.h"
#include <iostream>

using namespace std;

/** Clase base del juego
*/
class Juego
{
	public:
	
	    /// Constructor por defecto
	    Juego();
	    
	    /// Destructor por defecto
	    ~Juego();
	
	    /// Inicia el juego
	    void iniciar();
	
	private:
		
		/// Barrera de abstracción para los gráficos del juego.
		InterfazGFX* interfazGFX;
		
		/// Barrera de abstracción para la IA del juego.
		InterfazIA* interfazIA;
		
		/// Barrera de abstracción para la física del juego.
		InterfazPSX* interfazPSX;
		
		/// Barrera de abstracción para la información del juego.
		InterfazINF* interfazINF;
		
		/// Barrera de abstracción para el sonido del juego.
		InterfazSND* interfazSND;
		
		/// Manejador de eventos.
		//ManejadorEventos manejadorEventos;
		
	protected:
	
};
		
#endif
