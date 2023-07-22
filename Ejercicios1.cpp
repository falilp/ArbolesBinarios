#include "abin.hpp"
#include <iostream>

//Ejercicio 1:Implementa un subprograma que calcule el número de nodos de un árbol binario

template <typename T>
int ContarNodos(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == A.NODO_NULO){
        return 0;
    }else{
        return 1 + ContarNodos(A,A.hijoIzqdo(n)) + ContarNodos(A,A.hijoDrcho(n));
    }
}

template <typename T>
int NumeroNodos(const Abin<T>& A){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return 0;
    }else{
        return ContarNodos(A,A.raiz());
    }
}

//Ejercicio 2:Implementa un subprograma que calcule la altura de un árbol binario

template <typename T>
const T Maximo(const T& V1,const T& V2){
    return (V1 > V2 ? a : b); 
}

template <typename T>
int AlturaRecursiva(const Abin<T>& A,const typename Abin<T>::nodo n){
    if(n == A.NODO_NULO){
        return 0;
    }else{
        else 1 + Maximo();
    }
}

template <typename T>
int AlturaArbol(const Abin<T>& A){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return 0;
    }else{
        return AlturaRecursiva(A,A.raiz());
    }
}