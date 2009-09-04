/// Fichero de definición de la clase Coordenada.
/** \file Coordenada.cpp
 */

#include "Coordenada.h"
#include <iostream>

using namespace std;

Coordenada::Coordenada(float x, float y, float z)
{
	coordenada[0] = x;
	coordenada[1] = y;
	coordenada[2] = z;
}

Coordenada::Coordenada(const Coordenada &origen)
{
	*this = origen;
}


Coordenada& Coordenada::operator= (const Coordenada &origen)
{
	if (this != &origen)
	{
		coordenada[0] = origen.coordenada[0];
		coordenada[1] = origen.coordenada[1];
		coordenada[2] = origen.coordenada[2];
	}
	return *this;
}

Coordenada::~Coordenada()
{
	// No hemos reservado memoria dinámica
}

void Coordenada::setX(float x)
{
	coordenada[0] = x;
}

void Coordenada::setY(float y)
{
        coordenada[1] = y;
}

void Coordenada::setZ(float z)
{
        coordenada[2] = z;
}

float Coordenada::getX() const
{
	return coordenada[0];
}

float Coordenada::getY() const
{
	return coordenada[1];
}

float Coordenada::getZ() const
{
	return coordenada[2];
}

float* Coordenada::getCoordenada()
{
        return coordenada; 
}

float Coordenada::distancia (const Coordenada &coordenada) const
{
	float x = this->coordenada[0]-coordenada.coordenada[0];
	float y = this->coordenada[1]-coordenada.coordenada[1];
	float z = this->coordenada[2]-coordenada.coordenada[2];
	return sqrt (x*x+y*y+z*z);
}

float Coordenada::modulo () const
{
	return distancia(Coordenada (0,0,0));
}

ostream& operator<<(ostream& os, const Coordenada &coordenada)
{
        os << "[" << coordenada.coordenada[0] << " , " << coordenada.coordenada[1] << " , " << coordenada.coordenada[2] << "]";
        return os;
}

void Coordenada::inicializar(float x, float y, float z)
{
	coordenada[0] = x;
	coordenada[1] = y;
	coordenada[2] = z;
}

void Coordenada::normalizar()
{
	float modulo = sqrt (pow (coordenada[0],2)+pow(coordenada[1],2)+pow(coordenada[2],2));
	if (modulo>0)
	{
		coordenada[0] /= modulo;
		coordenada[1] /= modulo;
		coordenada[2] /= modulo;
	}
}

float Coordenada::angulo (const Coordenada &coordenada) const
{
	Coordenada vector = coordenada-(*this);
	float cateto = vector.getX();
	if (vector.getZ()<0) cateto*=-1;
	
	float radianes = 0;
	if (vector.modulo() != 0)
		radianes = acos (cateto/vector.modulo());
	
	float grados = radianes/0.0175;
	
	if (vector.getZ()<0) grados+=180;
	
	return grados-180;	// Cuando los objetos estén mirando todos hacia el eje positivo Z, será -90 en vez de -180.
}

Coordenada Coordenada::operator+ (const Coordenada &origen) const
{
	Coordenada aux;
	aux.coordenada[0] = this->coordenada[0] + origen.coordenada[0];
	aux.coordenada[1] = this->coordenada[1] + origen.coordenada[1];
	aux.coordenada[2] = this->coordenada[2] + origen.coordenada[2];
	return aux;
}

Coordenada Coordenada::operator- (const Coordenada &origen) const
{
	Coordenada aux;
	aux.coordenada[0] = this->coordenada[0] - origen.coordenada[0];
	aux.coordenada[1] = this->coordenada[1] - origen.coordenada[1];
	aux.coordenada[2] = this->coordenada[2] - origen.coordenada[2];
	return aux;
}

Coordenada Coordenada::operator* (float escalar) const
{
	Coordenada aux;
	aux.coordenada[0] = this->coordenada[0] * escalar;
	aux.coordenada[1] = this->coordenada[1] * escalar;
	aux.coordenada[2] = this->coordenada[2] * escalar;
	return aux;
}

bool Coordenada::operator== (const Coordenada &origen) const
{
	bool iguales = false;
	if(coordenada[0] == origen.coordenada[0])
		if(coordenada[1] == origen.coordenada[1])
			if(coordenada[2] == origen.coordenada[2])
				iguales = true;
	return iguales;
}

bool Coordenada::operator!= (const Coordenada &origen) const
{
	if(*this == origen)
		return false;
	else 
		return true;
}
