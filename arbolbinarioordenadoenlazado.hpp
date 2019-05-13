#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"

using namespace std;
namespace ed{
template<class G>
class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>{


private:

	class NodoArbolBinario{
	private:
		G _info;//información que contiene el nodo
		NodoArbolBinario * _izquierdo;//hijo izquierdo del nodo
		NodoArbolBinario * _derecho;//hijo derecho del nodo

	public:

		NodoArbolBinario(const G &info){
			this->_info = info;
			this->_izquierdo = this->_derecho = NULL;
			#ifndef NDEBUG
				assert(this->_izquierdo == NULL && this->_derecho == NULL);
			#endif
		}

		NodoArbolBinario(const NodoArbolBinario &n){
			this->setInfo(n._info);
			this->setIzquierdo(n._izquierdo);
			this->setDerecho(n._derecho);
			#ifndef NDEBUG
				assert(this->_info == n._info);
				assert(this->_izquierdo == n._izquierdo);
				assert(this->_derecho == n._derecho);
			#endif
		}
		const G & getInfo()const{
			return this->_info;
		}

		NodoArbolBinario *getIzquierdo()const{
			return this->_izquierdo;
		}

		NodoArbolBinario *getDerecho()const{
			return this->_derecho;
		}

		bool esHoja()const{
			if (this->_izquierdo == NULL && this->_derecho == NULL){
				return true;
			}
			return false;
		}

		void recorridoPreOrden(OperadorNodo<G> &operador)const{
			operador.aplicar(getInfo());//comprobamos con el campo del nodo
			if (getIzquierdo() != 0){//tiene hijo izquierdo
				getIzquierdo()->recorridoPreOrden(operador);//seguimos bajando por la izquierda
			}
			if (getDerecho() != 0){//tiene hijo derecha
				getDerecho()->recorridoPreOrden(operador); //Seguimos bajando por la derecha
			}
		}
		
		void recorridoPostOrden(OperadorNodo<G> &operador)const{
			if (getIzquierdo() != 0){//tiene hijo izquierdo
				getIzquierdo()->recorridoPostOrden(operador); //Seguimos bajando por la izquierda
			}
			if (getDerecho() != 0){//tiene hijo derecha
				getDerecho()->recorridoPostOrden(operador); //Seguimos bajando por la derecha
			}
			operador.aplicar(getInfo());//comprobamos con el campo del nodo
		}
		
		void recorridoInOrden(OperadorNodo<G> &operador) const{	
			if (getIzquierdo() != 0){//tiene hijo izquierdo
				getIzquierdo()->recorridoInOrden(operador); //Seguimos bajando por la izquierda
			}
			operador.aplicar(getInfo());//comprobamos con el campo del nodo
			if (getDerecho() != 0){//tiene hijo derecho
				getDerecho()->recorridoInOrden(operador); //Seguimos bajando por la derecha
			}
		}

		void setInfo(const G &info){
			this->_info = info;
		}

		void setIzquierdo(NodoArbolBinario *n){
			this->_izquierdo = n;
		}

		void setDerecho(NodoArbolBinario *n){
			this->_derecho = n;
		}

		NodoArbolBinario & operator=(const NodoArbolBinario &n){
			#ifndef NDEBUG
				assert(n._info != this->_info);
				assert(n._izquierdo != this->_izquierdo);
				assert(n._derecho != this->_derecho);
			#endif
			this->setInfo(n._info);
			this->setIzquierdo(n._izquierdo);
			this->setDerecho(n._derecho);
			#ifndef NDEBUG
				assert(this->_info == n._info);
				assert(this->_izquierdo == n._izquierdo);
				assert(this->_derecho == n._derecho);
			#endif
			return *this;
		}

	}; //Fin clase NodoArbolBinario

	NodoArbolBinario * _raiz;
	NodoArbolBinario * _actual; 
	NodoArbolBinario * _padre;

public:

	ArbolBinarioOrdenadoEnlazado(){
		this->_raiz = NULL;
		this->_actual = NULL;
		this->_padre = NULL;
		#ifndef NDEBUG
			assert(this->estaVacio());
		#endif
	}

	ArbolBinarioOrdenadoEnlazado(const ArbolBinarioOrdenadoEnlazado<G> &a){
		this->_raiz = NULL;
		this->_actual = NULL;
		this->_padre = NULL;
		*this = a;
	}

	~ArbolBinarioOrdenadoEnlazado(){
		if(!this->estaVacio()){
			this->borrarArbol();
		}
		cout << "Destructor Usado \n";
	}

	bool estaVacio()const{
		if(this->_raiz != NULL)
			return false;
		if(this->_actual != NULL)
			return false;
		if(this->_padre != NULL)
			return false;
		return true;
	}

	G raiz()const{
		#ifndef NDEBUG
			assert(not this->estaVacio());
		#endif
		return this->getRaiz()->getInfo();
	}

	bool existeActual()const{
		#ifndef NDEBUG
			assert(not this->estaVacio());
		#endif
		if(this->_actual == NULL){
			return false;
		}
		return true;
	}

	G actual()const{
		#ifndef NDEBUG
			assert(this->_actual != NULL);
		#endif
		return this->_actual->getInfo();
	}

	bool buscar(const G& x){
		if(estaVacio()){
			return false;//no lo ha encontrado
		}
		NodoArbolBinario *n = this->getRaiz();
		NodoArbolBinario * aux = this->getRaiz();
		while(1){
			if(x > n->getInfo()){ // si es mayor bajamos por la derecha
				if(n->getDerecho()){
					aux=n;
					n = n->getDerecho();
				}
				else{
					return false;//no se ha encontrado el nodo
				}
			}
			else if(x < n->getInfo()){//si es menor bajamos por la izquierda
				if(n->getIzquierdo()){
					aux=n;
					n = n->getIzquierdo();
				}
				else{
					return false;//no se ha encontrado el nodo
				}
			}
			else{//si no ha salido en ninguno de los else es que lo hemos encontrado
				this->_padre = aux;
				this->_actual = n;
				return true;
			}
		}
	}

	bool insertar(G const &x){
		if(this->estaVacio()){
			this->_raiz = new NodoArbolBinario(x);
			this->_actual = this->_raiz;
			this->_padre = this->_raiz;
			return true;
		}
		NodoArbolBinario *n = this->_raiz;
		while (1){
			if(x > n->getInfo()){
				if (n->getDerecho()){
					n = n->getDerecho();
				}
				else{
					n->setDerecho(new NodoArbolBinario(x));
					return true;
				}
			}
			else if(x < n->getInfo()){
				if (n->getIzquierdo()){
					n = n->getIzquierdo();
				}
				else{
					n->setIzquierdo(new NodoArbolBinario(x));
					return true;
				}
			}
			else{
				return false;
			}
		}
	}

	bool borrar(){
		#ifndef NDEBUG
			assert(this->_actual!=NULL);
		#endif

		if(!this->_actual->getIzquierdo() ||  !this->_actual->getDerecho()){ //el nodo que quiero borrar solo tiene un hijo, izq o derecho
			if (this->_actual->getIzquierdo()){//tiene un unico hijo izquierdo
				if(this->_raiz == this->_actual){ //actual es la raiz
					this->_padre=NULL;
					this->_raiz=this->_actual->getIzquierdo();//padre apunta a null y nueva raiz es el hijo izq
				}
				else if(this->_raiz != this->_actual){ //no es la raiz
					if(this->_actual->getInfo() > this->_padre->getInfo()){//es mas grande que el padre
						this->_padre->setDerecho(this->_actual->getIzquierdo());
					}	
					else if(this->_actual->getInfo() < this->_padre->getInfo()){ // es mas pequeño que el padre
						this->_padre->setIzquierdo(this->_actual->getIzquierdo());
					}
				}
				delete this->_actual;
				this->_actual=NULL;
				this->_padre=NULL;
				return true;			
			}

			else{ //tiene un unico hijo derecho
				if(this->_raiz == this->_actual){ // es la raiz
					this->_padre=NULL;
					this->_raiz=this->_actual->getDerecho();//padre apunta a null y nueva raiz es el hijo derecho
				}
				else if(this->_raiz != this->_actual){ //no es la raiz
					if(this->_actual->getInfo() > this->_padre->getInfo()){
						this->_padre->setDerecho(this->_actual->getDerecho());
					}
					else if(this->_actual->getInfo() < this->_padre->getInfo()){
						this->_padre->setIzquierdo(this->_actual->getDerecho());
					}
				}
				delete this->_actual;
				this->_actual=NULL;
				this->_padre=NULL;
				return true;
			}
		}
		else if(this->_actual->esHoja()){//el nodo que quiero borrar es un nodo hoja
            if(this->_actual == this->_raiz){//si es la raiz
                delete this->_actual;
                this->_actual=NULL;
                this->_raiz=NULL;
                this->_padre=NULL;
            }
			else if(this->_padre->getIzquierdo()){//compruebo si mi padre tiene hijo izquierdo y si ese hijo izquierdo es el que buscamos
				if(this->_padre->getIzquierdo()->getInfo() == this->_actual->getInfo()){
                    this->_padre->setIzquierdo(0);
                }
                else{//es el hijo derecho
                    this->_padre->setDerecho(0);
                }
			}
            else{//soy el hijo derecho
                this->_padre->setDerecho(0);
            }
			this->_padre=NULL;
			delete this->_actual;
			this->_actual=NULL;
			return true;
		}

		else{// el nodo tiene dos hijos
			NodoArbolBinario *mayor = this->_actual->getIzquierdo();
			NodoArbolBinario *ancla = mayor; //creamos dos punteros, el primero lo iremos bajando y el segundo anclandolo encima
			while(mayor->getDerecho()){//vamos bajando el puntero lo maximo que podamos a la derecha
				ancla = mayor;
				mayor = mayor->getDerecho();//mayor lo bajamos a la derecha y ancla siempre la mantenemos encima de mayor
			}
            if(mayor == this->_actual->getIzquierdo()){
                this->_actual->setIzquierdo(mayor->getIzquierdo());
            }
            else if(mayor != this->_actual->getIzquierdo()){
			    ancla->setDerecho(mayor->getIzquierdo());
            }
			this->_actual->setInfo(mayor->getInfo()); //copiamos en actual la informacion que hay en mayor
			delete mayor;
			this->_actual=NULL;//dejamos actual y padre a null
			this->_padre=NULL;
			return true;
		}
	}

	void borrarArbol(){
		#ifndef NDEBUG
			assert(not this->estaVacio());
		#endif
		while(!this->estaVacio()){
			this->buscar(this->_raiz->getInfo());
			this->borrar();
		}
		#ifndef NDEBUG
			assert(this->estaVacio());
		#endif
	}

	void recorridoPreOrden(OperadorNodo<G> &operador) const{
		if (!estaVacio()){
			this->getRaiz()->recorridoPreOrden(operador);//reutilizamos el codigo
		}
	}
	
	void recorridoPostOrden (OperadorNodo<G> &operador)const{						
		if (!estaVacio()){
			this->getRaiz()->recorridoPostOrden(operador);//reutilizamos el codigo
		}
	}
	
	void recorridoInOrden (OperadorNodo<G> &operador) const{						
		if (!estaVacio()){
			this->getRaiz()->recorridoInOrden(operador);//reutilizamos codigo
		}
	}

	ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado &a){
		if (this != &a){
			if (!this->estaVacio()){
				this->borrarArbol();
			}
			if (!a.estaVacio()){
				this->_raiz = NULL;
				this->_actual = NULL;
				this->_padre = NULL;
			}
		}
	}

	NodoArbolBinario* getRaiz()const{
		return this->_raiz;
	}
};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
