/// Fichero de definición de la clase InterfazSND.
/** \file InterfazSND.cpp
 */

#include "InterfazSND.h"
#include "assert.h"
#include <iostream>

using namespace std;

// Inicializamos las variables estáticas.
InterfazSND* InterfazSND::instancia = NULL;

// Constructor por defecto.
InterfazSND::InterfazSND()
{
	engine = createIrrKlangDevice();
	activado = true;
	posicionOyente[0]=0;
	posicionOyente[1]=0;
	posicionOyente[2]=0;
	minimaDistancia = 0;
	maximaDistancia = 300;
	assert (engine != NULL);
}

// Destructor por defecto.
InterfazSND::~InterfazSND()
{
	engine->drop();
	activado = false;
}

// Devuelve la instancia de la clase singleton.
InterfazSND* InterfazSND::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazSND();
	return instancia;
}

// Inicia la interfaz.
void InterfazSND::iniciar()
{

}

// Reproduce el sonido.
void InterfazSND::reproducir (string ficheroSonido, bool bucle)
{
	if (activado)
		engine->play2D (ficheroSonido.c_str(), bucle);
}

// Reproduce el sonido.
void InterfazSND::reproducir (string ficheroSonido, float x, float y, float z, bool bucle)
{
	if (activado)
	{
		//engine->play3D (ficheroSonido.c_str(), vec3df(x/10, y/10, z/10), bucle);

		// Calculamos distancia entre la posición del oyente y el emisor del sonido.
		float distancia = (x-posicionOyente[0])*(x-posicionOyente[0])+(y-posicionOyente[1])*(y-posicionOyente[1])+(z-posicionOyente[2])*(z-posicionOyente[2]);
		if (distancia < 0) distancia = distancia*-1;
		distancia = sqrt(distancia);

		// Si la distancia es mayor que la distancia mínima (200, pero debería ser atributos de clase), se reproduce
		// con máximo volumen, si no, vamos reduciéndole el volumen progresivamente. En este caso, hasta 400. A partir
		// de 400, el volumen comienza a ser 0 (incluso negativo); también debería ser un atributo de clase la distancia
		// máxima de escucha.
		float volumen = 1;
		if (distancia > minimaDistancia)
		{
			volumen -= (distancia-minimaDistancia)/(maximaDistancia-minimaDistancia);
		}

		if (volumen > 0)
		{
			ISound* sonido = engine->play2D(ficheroSonido.c_str(), bucle, false, true, ESM_AUTO_DETECT, true);
			assert (sonido != NULL);
			sonido->setVolume(volumen);
			sonido->drop();
		}
	}
}

// Comprueba si el sonido está reproduciéndose actualmente.
bool InterfazSND::reproduciendose (string ficheroSonido) const
{
	return engine->isCurrentlyPlaying (ficheroSonido.c_str());
}

// Detiene el sonido.
bool InterfazSND::detener (string ficheroSonido)
{
	bool aux = reproduciendose(ficheroSonido);
	if (aux)
	{
		engine->removeSoundSource (ficheroSonido.c_str());
	}
	return aux;
}

// Comprueba si el sonido está cargado.
bool InterfazSND::cargado (string ficheroSonido) const
{
	if (engine->getSoundSource (ficheroSonido.c_str(), false) != NULL)
		return true;
	else
		return false;
}

// Modifica el estado del sonido.
void InterfazSND::setActivado (bool activado)
{
	this->activado = activado;
	engine->setAllSoundsPaused (!activado);
}

// Comprueba si el sonido está activado.
bool InterfazSND::getActivado () const
{
	return activado;
}

// Modifica el volumen del dispositivo de sonido.
void InterfazSND::setVolumen (float volumen)
{
	engine->setSoundVolume (volumen);
}

// Obtiene el volumen actual del dispositivo de sonido.
float InterfazSND::getVolumen () const
{
	return engine->getSoundVolume ();
}

// Establece la posición del oyente.
void InterfazSND::setPosicionOyente (float x, float y, float z)
{
	//engine->setListenerPosition (vec3df(x/10,y/10,z/10), vec3df(x/10,y/10,z/10));
	posicionOyente[0] = x;
	posicionOyente[1] = y;
	posicionOyente[2] = z;
}

// Obtiene la posición del oyente.
float* InterfazSND::getPosicionOyente ()
{
	return posicionOyente;
}

// Establece la mínima distancia para comenzar la atenuación de sonido.
void InterfazSND::setMinimaDistancia (float minimaDistancia)
{
	this->minimaDistancia = minimaDistancia;
}

// Establece la máxima distancia a la que un sonido puede reproducirse.
void InterfazSND::setMaximaDistancia (float maximaDistancia)
{
	this->maximaDistancia = maximaDistancia;
}
