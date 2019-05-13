#include <iostream>
#include <cstdlib>

#include "generarpersona.hpp"

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"


using namespace ed;
using namespace std;
template<class G>
	void mostrarArbol(ArbolBinarioOrdenadoEnlazado<G> &a){
		if(a.estaVacio()){
			cout << "El árbol no se puede mostrar, esta vacío\n";
			return;
		}
		EscribirNodo<G> e; 
        cout << "Recorrido Pre-Orden"<<endl;
		a.recorridoPreOrden(e);
		cout << endl;

		cout << "Recorrido In-Orden"<<endl;
		a.recorridoInOrden(e);
        cout << endl;
		
		

		cout << "Recorrido Post-Orden"<<endl;
		a.recorridoPostOrden(e);
		cout << endl;
	}
int main(){

    ArbolBinarioOrdenadoEnlazado <int> a;
    EscribirNodo<int> e;
    cout<< "\t RELLENANDO EL ARBOL CON LA FUNCION insertar(num)"<<endl;
    cout << endl;
    cout << endl;
    a.insertar(10);
    a.insertar(5);
    a.insertar(1);
    a.insertar(9);
    a.insertar(7);
    a.insertar(6);
    a.insertar(8);
    a.insertar(20);
    a.insertar(15);
    a.insertar(25);
    a.insertar(22);
    a.insertar(27);
    cout << endl << endl;

    cout << "MOSTRANDO EL ARBOL CON LA FUNCION mostrarArbol(arbol)" <<endl;
    cout << endl;
    cout << endl;
    mostrarArbol(a);

    cout << endl << endl;
    cout << "\t BUSCANDO NODOS EN EL ARBOL CON LA FUNCION buscar(num)" <<endl;
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 10" << endl;
    if(a.buscar(10) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(10) == false){
        cout << "numero no encontrado" <<endl;
    }
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 30" << endl;
    if(a.buscar(30) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(30) == false){
        cout << "numero no encontrado" <<endl;
    }
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 15" << endl;
    if(a.buscar(15) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(15) == false){
        cout << "numero no encontrado" <<endl;
    }
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 56" << endl;
    if(a.buscar(56) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(56) == false){
        cout << "numero no encontrado" <<endl;
    }
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 200" << endl;
    if(a.buscar(200) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(200) == false){
        cout << "numero no encontrado" <<endl;
    }
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 25" << endl;
    if(a.buscar(25) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(25) == false){
        cout << "numero no encontrado" <<endl;
    }
    cout << endl;
    cout << endl;
    cout << "buscando el numero: 90" << endl;
    if(a.buscar(90) == true){
        cout << "numero encontrado" << endl;
    }else if(a.buscar(90) == false){
        cout << "numero no encontrado" <<endl;
    }
    

    cout << endl;
    cout << endl;
    cout << "\tBORRANDO NODOS DEL ARBOL CON LA FUNCION borrar()" <<endl;
    cout << endl;
    cout << endl;
    a.recorridoInOrden(e);
    cout << endl;
    cout << endl;
    cout << "Eliminando nodo hoja (1)" << endl;
    cout << endl;
    if(a.buscar(1)){
        if(a.borrar()){   
            cout << "Nodo 1 borrado exitosamente" << endl;
		    a.recorridoInOrden(e);
        }    
        else
            cout << "No se ha podido borrar el nodo 1" << endl << endl;
    }
    else
        cout << "No se ha encontrado el nodo 1" << endl << endl;
    cout << endl;
    cout << endl;
    cout << "Eliminando un nodo con un unico hijo izquierdo (9)" << endl;
    cout << endl;
    if(a.buscar(9)){
        if(a.borrar()){   
            cout << "Nodo 9 borrado exitosamente" << endl;
		    a.recorridoInOrden(e);
        }
        else
            cout << "No se ha podido borrar el nodo 9" << endl << endl;
    }
    else
        cout << "No se ha encontrado el nodo 9" << endl << endl;
    cout << endl;
    cout << endl;
    cout << "Eliminando un nodo con un unico hijo derecho (5)" << endl;
    cout << endl;
    if(a.buscar(5)){
        if(a.borrar()){   
            cout << "Nodo 5 borrado exitosamente" << endl << endl;
		    a.recorridoInOrden(e);
        }
        else
            cout << "No se ha podido borrar el nodo 5" << endl << endl;
    }
    else
        cout << "No se ha encontrado el nodo 5" << endl << endl;
    cout << endl;
    cout << endl;
    cout << "Eliminando un nodo con dos hijos (20) " << endl;
    cout << endl;
    if(a.buscar(20)){
        if (a.borrar()){   
            cout << "Nodo 20 borrado exitosamente" <<endl;
		    a.recorridoInOrden(e);
        }
        else
            cout << "No se ha podido borrar el nodo 20" << endl << endl;
    }
    else
        cout << "No se ha encontrado el nodo 20" << endl << endl;
    cout << endl;
    cout << endl;
    cout << "Eliminando un nodo con dos hijos (60) " << endl;
    cout << endl;
    if(a.buscar(60)){
        if(a.borrar()){   
            cout << "Nodo 60 borrado exitosamente" << endl;
		    a.recorridoInOrden(e);
        }
        else
            cout << "No se ha podido borrar el nodo 60" << endl << endl;
    }
    else
        cout << "No se ha encontrado el nodo 60" << endl << endl;
    
            
    cout << endl;
    cout << endl;
    cout << endl <<"\tBORRANDO ARBOL COMPLETO CON LA FUNCION borrarArbol()" << endl << endl;
    cout << endl;
    cout << endl;
    a.borrarArbol();
    cout << endl;

    mostrarArbol(a);
    return 0;
}