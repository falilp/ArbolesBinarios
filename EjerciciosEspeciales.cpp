#include "abin.hpp"
#include <iostream>

#pragma region Ejercicio1
/*Dado un arbol binario de un tipo generico T , calcular el numero de nodos que siendo hermanos entre si tienen la misma raiz y sus subarboles son reflejados.
Reflejados es que tenga la misma estructura de ramificacion.*/

/*Consideraré que un par de vertices que son hermanos entre si y reflejados cuentan como 1,
tambien podria contemplarse como 2 al ser estos reflejados*/

template <typename T>
bool Reflejados(const Abin<T>& A,const typename Abin<T>::nodo nodo1,const typename Abin<T>::nodo nodo2){
    if(A.NODO_NULO == nodo1 && A.NODO_NULO == nodo2){
        return true;
    }else if(A.NODO_NULO != nodo1 && A.NODO_NULO != nodo2){
        return true && Reflejados(A,A.hijoIzqdo(nodo1),A.hijoIzqdo(nodo2)) && Reflejados(A,A.hijoDrcho(nodo1),A.hijoDrcho(nodo2));
    }else{
        return false;
    }
}

template <typename T>
unsigned int RecHermanosReflejados(const Abin<T>& A,const typename Abin<T>::nodo nodo){
    if(A.NODO_NULO == nodo){
        return 0;
    }else if((A.hijoIzqdo(nodo) != A.NODO_NULO) && (A.hijoDrcho(nodo) != A.NODO_NULO)){
        if(Reflejados(A,A.hijoIzqdo(nodo),A.hijoDrcho(nodo))){
            return 1 + RecHermanosReflejados(A,A.hijoIzqdo(nodo)) + RecHermanosReflejados(A,A.hijoDrcho(nodo));
        }else{
            return RecHermanosReflejados(A,A.hijoIzqdo(nodo)) + RecHermanosReflejados(A,A.hijoDrcho(nodo));
        }
    }else{
        return RecHermanosReflejados(A,A.hijoIzqdo(nodo)) + RecHermanosReflejados(A,A.hijoDrcho(nodo));
    }
}

template <typename T>
unsigned int HermanosReflejados(const Abin<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return RecHermanosReflejados(A,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio2
/*Contar el numero de nodos de un arbol binario que tenga el doble de nietos que de bisnietos*/
//Denominare a nodos de un arbol binario que tenga el doble de nietos de de bisnietos como Nodos Jovenes

template <typename T>
unsigned int Nhijos(const Abin<T>& A,const typename Abin<T>::nodo nodo){
    unsigned int hijos = 0;
    if(nodo != A.NODO_NULO){
        if(A.hijoIzqdo(nodo) != A.NODO_NULO){hijos++;}
        if(A.hijoDrcho(nodo) != A.NODO_NULO){hijos++;}
    }
    return hijos;
}

template <typename T>
unsigned int NumNietos(const Abin<T>& A,const typename Abin<T>::nodo nodo){
    if(nodo == A.NODO_NULO){
        return 0;
    }else{
        return Nhijos(A,A.hijoIzqdo(nodo)) + Nhijos(A,A.hijoDrcho(nodo));
    }
}

template <typename T>
unsigned int NumBisNietos(const Abin<T>& A,const typename Abin<T>::nodo nodo){
    if(nodo == A.NODO_NULO){
        return 0;
    }else{
        return NumNietos(A,A.hijoIzqdo(nodo)) + NumNietos(A,A.hijoDrcho(nodo));
    }
}

template <typename T>
unsigned int RecNodosJovenes(const Abin<T>& A,const typename Abin<T>::nodo nodo){
    if(nodo == A.NODO_NULO){
        return 0;
    }else if(NumBisNietos(A,nodo) == 2*NumNietos(A,nodo)){
        return 1 + RecNodosJovenes(A,A.hijoIzqdo(nodo)) + RecNodosJovenes(A,A.hijoDrcho(nodo));
    }else{
        return RecNodosJovenes(A,A.hijoIzqdo(nodo)) + RecNodosJovenes(A,A.hijoDrcho(nodo));
    }
}

template <typename T>
unsigned int NodosJovenes(const Abin<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return RecNodosJovenes(A,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio3
/*Saber si un Abin es un ABB*/
/*Definición: Un árbol binario de búsqueda (ABB) es un árbol binario con la propiedad de que todos los elementos 
almacenados en el subárbol izquierdo de cualquier nodo x son menores que el elemento almacenado en x ,y todos los 
elementos almacenados en el subárbol derecho de x son mayores que el elemento almacenado en x.*/
#pragma endregion