#include "abin.hpp"
#include <iostream>

//Implementa un subprograma que calcule el número de nodos de un árbol binario

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