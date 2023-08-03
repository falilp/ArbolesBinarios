#include "abin.hpp"
#include <iostream>

#pragma region Ejercicio1
/*Dado un arbol binario de un tipo generico T , calcular el numero de nodos que siendo hermanos entre si tienen la misma raiz y sus subarboles son reflejados.
Reflejados es que tenga la misma estructura de ramificacion.*/

template <typename T>
bool Reflejados(const Abin<T>& A,const typename Abin<T>::nodo nodo1,const typename Abin<T>::nodo nodo2){
    if(A.arbolVacio()){
        return false;
    }else if(((A.NODO_NULO != nodo1) && (A.NODO_NULO != nodo2)) || ((A.NODO_NULO == nodo1) && (A.NODO_NULO == nodo2))){
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
/*Contar el numero de nodos de un arbol binario que tenga el doble de nietos de de bisnietos*/
#pragma endregion

#pragma region Ejercicio3
/*Contar el numero de nodos de un arbol binario que tenga el doble de nietos de de bisnietos*/
#pragma endregion

#pragma region Ejercicio4
/*Saber si un Abin es un ABB*/
#pragma endregion