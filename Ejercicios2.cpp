#include "abin.hpp"
#include <iostream>

#pragma region Ejercicio1
/*Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación, es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos árboles binarios son similares.*/

template <typename T>
bool RecSimilares(const Abin<T>& A, const Abin<T>& B, const typename Abin<T>::nodo nodoA, const typename Abin<T>::nodo nodoB){
    if(nodoA == A.NODO_NULO() && nodoB == B.NODO_NULO()){
        return true;
    }else if(nodoA != A.NODO_NULO() && nodoB != B.NODO_NULO()){
        return true && RecSimilares(A,B,A.hijoIzqdo(nodoA),B.hijoIzqdo(nodoB)) && RecSimilares(A,B,A.hijoDrcho(nodoA),B.hijoDrcho(nodoB));
    }else{
        return false;
    }
}

template <typename T>
bool ArbolesBinariosSimilares(const Abin<T>& A, const Abin<T>& B){
    if(A.arbolVacio() && B.arbolVacio()){
        return true;
    }else if(!A.arbolVacio() && !B.arbolVacio()){
        return RecSimilares(A,B,A.raiz(),B.raiz());
    }else{
        return false;
    }
}

#pragma endregion

#pragma region Ejercicio2
/*Para un árbol binario B, podemos construir el árbol binario reflejado BR cambiando los subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que devuelva
el arbol binario reflejado de uno dado.*/

template <typename T>
void RecReflejarArbol(const Abin<T>& B, Abin<T>& BR, const typename Abin<T>::nodo nodoB, const typename Abin<T>::nodo nodoBR){
    if(nodoB != B.NODO_NULO){
        BR.insertarHijoDrcho(nodoBR,B.elemento(B.hijoIzqdo(nodoB)));
        BR.insertarHijoIzqdo(nodoBR,B.elemento(B.hijoDrcho(nodoB)));

        RecReflejarArbol(B,BR,B.hijoIzqdo(nodoB),BR.hijoDrcho(nodoBR));
        RecReflejarArbol(B,BR,B.hijoDrcho(nodoB),BR.hijoIzqdo(nodoBR));
    }
}

template <typename T>
Abin<T>& CrearArbolReflejado(const Abin<T>& B){
    Abin<T> BR;

    if(!B.arbolVacio()){
        BR.insertarRaiz(B.elemento(B.raiz()));
        RecReflejarArbol(B,BR,B.raiz(),BR.raiz());
    }

    return BR;
}

#pragma endregion

#pragma region Ejercicio3
/*El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
de los nodos los operadores. 

a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar operadores y operandos.

b) Implementa una función que tome un árbol binario de expresión (aritmética) y devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
árbol representa una expresión correcta. Los operadores binarios posibles en la expresión aritmética serán suma, resta, multiplicación y división.*/

typedef struct elemento{
    double operando;
    char operador;
    elemento(char ope='#', double op=0):operando(op),operador(ope){}
}Elemento;

double ResultadoExpresion(const Abin<Elemento> &abin){
    if(abin.arbolVacio()){
        return 0;
    }else{
        return ExpresionRec(abin,abin.raiz());
    }
}

double ExpresionRec(const Abin<Elemento> &abin,const typename Abin<Elemento>::nodo nodo){
    Elemento elemento = abin.elemento(nodo);
    if(nodo != abin.NODO_NULO){
        switch(elemento.operador){
        case '+':
            return ExpresionRec(abin,abin.hijoIzqdo(nodo)) + ExpresionRec(abin,abin.hijoDrcho(nodo));
            break;
        case '-':
            return ExpresionRec(abin,abin.hijoIzqdo(nodo)) - ExpresionRec(abin,abin.hijoDrcho(nodo));
            break;
        case '*':
            return ExpresionRec(abin,abin.hijoIzqdo(nodo)) * ExpresionRec(abin,abin.hijoDrcho(nodo));
            break;
        case '/':
            return ExpresionRec(abin,abin.hijoIzqdo(nodo)) / ExpresionRec(abin,abin.hijoDrcho(nodo));
            break;
        default:
            std::cout<<"Ha introducido un operador erroneo"<<std::endl;
            break;
        }
    }else{
        return abin.elemento(nodo).operando;
    }
}

#pragma endregion

#pragma region Ejercicio4
/*RENEGADOS:Se dice que un nodo es renegado cuando va encontra de los demás. Dado un Árbol Binario, calcular el número de nodos renegados que hay en dicho árbol.
Nota: considero que renegado es apartir de la raiz y */

template <typename T>
unsigned int RecNodosRenagados(const Abin<T>& A,const typename Abin<T>::nodo nodo){
    if(A.raiz() == ndoo){
        return RecNodosRenagados(A,A.hijoIzqdo(nodo)) + RecNodosRenagados(A,A.hijoDrcho(nodo));
    }else if(nodo != A.NODO_NULO){
        if(A.elemento(nodo) == A.elemento(A.raiz())){
            return 1 + RecNodosRenagados(A,A.hijoIzqdo(nodo)) + RecNodosRenagados(A,A.hijoDrcho(nodo));
        }else{
            return RecNodosRenagados(A,A.hijoIzqdo(nodo)) + RecNodosRenagados(A,A.hijoDrcho(nodo));
        }
    }else{
        return 0;
    }
}

template <typename T>
unsigned int NodosRenegados(const Abin<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return RecNodosRenagados(A,A.raiz())
    }
}

#pragma endregion

#pragma region Ejercicio5
/*Encontrar un nodo en el arbol*/

template <typename T>
typename Abin<T>::nodo RecBuscarNodo(const Abin<T>& A, const typename Abin<T>::nodo nodo, const typename Abin<T>::nodo nodoAux){
    if(A.NODO_NULO != nodoAux){
        if(nodo == nodoAux){
            return nodoAux;
        }else{
            RecBuscarNodo(A,nodo,A.hijoIzqdo(nodoAux));
            RecBuscarNodo(A,nodo,A.hijoDrcho(nodoAux));
        }
    }
}

template <typename T>
typename Abin<T>::nodo EncontrarNodo(const Abin<T>& A, const typename Abin<T>::nodo nodo){
    if(A.arbolVacio() || nodo == A.NODO_NULO){
        return A.NODO_NULO;
    }else{
        return RecBuscarNodo(A,nodo,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio6
/*Contar el numero de nodos de un arbol binario que tenga exactamente 3 nietos*/

#pragma endregion
/*
Code by Falilp
*/