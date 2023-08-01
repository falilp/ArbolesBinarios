#include "abin.hpp"
#include <iostream>

#pragma region Ejercicio1 
//Ejercicio 1:Implementa un subprograma que calcule el número de nodos de un árbol binario

template <typename T>
unsigned int ContarNodos(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == A.NODO_NULO){
        return 0;
    }else{
        return 1 + ContarNodos(A,A.hijoIzqdo(n)) + ContarNodos(A,A.hijoDrcho(n));
    }
}

template <typename T>
unsigned int NumeroNodos(const Abin<T>& A){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return 0;
    }else{
        return ContarNodos(A,A.raiz());
    }
}
#pragma endregion

#pragma region Ejercicio2
//Ejercicio 2:Implementa un subprograma que calcule la altura de un árbol binario

template <typename T>
const T Maximo(const T& V1,const T& V2){
    return (V1 > V2 ? a : b); 
}

template <typename T>
unsigned int AlturaRecursiva(const Abin<T>& A,const typename Abin<T>::nodo n){
    if(n == A.NODO_NULO){
        return 0;
    }else{
        else 1 + Maximo(AlturaRecursiva(A,A.hijoIzqdo(n)),AlturaRecursiva(A,A.hijoDrcho(n)));
    }
}

template <typename T>
unsigned int AlturaArbol(const Abin<T>& A){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return 0;
    }else{
        return AlturaRecursiva(A,A.raiz())-1;
    }
}
#pragma endregion

#pragma region Ejercicio3
//Ejercicio 3:Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine la profundidad de este nodo en dicho árbol.

template <typename T>
unsigned int ProfundidadNodo(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return 0;
    }else if(A.padre(n) == A.NODO_NULO){
        return 0;
    }else{
        return 1 + ProfundidadNodo(A,A.padre(n));
    }
}
#pragma endregion

#pragma region Ejercicio4
//Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario, definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
//define como la diferencia entre las alturas de los subárboles del mismo

template <typename T>
unsigned int CalcularDesequilibrio(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == A.NODO_NULO){
        return 0;
    }else{
        return abs(AlturaRecursiva(A,A.hijoIzqdo(n))-AlturaRecursiva(A,A.hijoDrcho(n)));
    }
}

template <typename T>
unsigned int DesequilibrioAbin(const Abin<T>& A){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return 0;
    }else{
        return CalcularDesequilibrio(A,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio5
//Implementa un subprograma que determine si un árbol binario es o no pseudocompleto. En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
//del mismo cada uno de los nodos tiene dos hijos o ninguno.

template<typename T>
bool PseudocompletoRecursivo(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == A.NODO_NULO){
        return true;
    }else{
        if(AlturaRecursiva(A,n)-1 == ProfundidadNodo(A,n)){ //El penultimo nivel coincide con la altura - 1 del arbol = la profundidad del nodo
            if(((A.hijoIzqdo(n) != A.NODO_NULO) && (A.hijoDrcho(n) != A.NODO_NULO)) || 
                ((A.hijoIzqdo(n) == A.NODO_NULO) && (A.hijoDrcho(n) == A.NODO_NULO))){
                return true;
            }else{
                return false;
            }
        }else{
            return PseudocompletoRecursivo(A,A.hijoIzqdo(n)) && PseudocompletoRecursivo(A,A.hijoDrcho(n));
        }
    }
}

template<typename T>
bool PseudocompletoAbin(const Abin<T>& A){
    if(A.arbolVacio() || (A.raiz() == A.NODO_NULO)){
        return false;
    }else{
        return PseudocompletoRecursivo(A,A.raiz());
    }
}

#pragma endregion
/*
Code by Falilp
*/