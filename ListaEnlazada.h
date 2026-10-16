/*
 * ============================================================
 * Archivo   : ListaEnlazada.h
 * Asignatura: Estructura de Datos Dinámicos - CFT CENCO
 * Docente   : Raúl G. Villegas T.
 * Propósito : Implementación de una LISTA ENLAZADA SIMPLE usando
 *             punteros y memoria dinámica (new / delete).
 * Operaciones: insertar, eliminar, buscar y mostrar.
 * ============================================================
 */
#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
using namespace std;

/*
 * Estructura NodoLista
 * Cada nodo guarda un dato entero y un puntero al nodo siguiente.
 * El último nodo de la lista apunta a nullptr (fin de la lista).
 */
struct NodoLista {
    int dato;              // Valor almacenado en el nodo
    NodoLista* siguiente;  // Enlace (puntero) al próximo nodo
};

/*
 * Clase ListaEnlazadaSimple
 * Encapsula el puntero "cabeza", que apunta al primer nodo.
 * Al ser privado, solo los métodos de la clase pueden modificarlo.
 */
class ListaEnlazadaSimple {
private:
    NodoLista* cabeza;  // Primer nodo de la lista (nullptr si está vacía)

public:
    // Constructor: la lista comienza vacía.
    ListaEnlazadaSimple() : cabeza(nullptr) {}

    // Se bloquea la copia para evitar que dos objetos liberen
    // los mismos nodos (doble delete).
    ListaEnlazadaSimple(const ListaEnlazadaSimple&) = delete;
    ListaEnlazadaSimple& operator=(const ListaEnlazadaSimple&) = delete;

    // Destructor: recorre la lista y libera cada nodo con delete,
    // evitando fugas de memoria (memory leaks).
    ~ListaEnlazadaSimple() {
        while (cabeza != nullptr) {
            NodoLista* temp = cabeza;   // Guarda el nodo actual
            cabeza = cabeza->siguiente; // Avanza la cabeza
            delete temp;                // Libera el nodo guardado
        }
    }

    /*
     * insertar(valor)
     * Inserta un nuevo nodo AL INICIO de la lista. Costo O(1).
     */
    void insertar(int valor) {
        NodoLista* nuevo = new NodoLista(); // Reserva memoria dinámica
        nuevo->dato = valor;
        nuevo->siguiente = cabeza;          // El nuevo apunta al antiguo primero
        cabeza = nuevo;                     // El nuevo pasa a ser la cabeza
        cout << "[Lista] Insertado: " << valor << endl;
    }

    /*
     * buscar(valor)
     * Recorre la lista nodo a nodo. Retorna true si encuentra el
     * valor y false en caso contrario. Costo O(n).
     */
    bool buscar(int valor) const {
        NodoLista* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    /*
     * eliminar(valor)
     * Elimina la primera aparición del valor. Reconecta los punteros
     * del nodo anterior con el siguiente y libera el nodo con delete.
     * Retorna true si se eliminó y false si el valor no existía.
     */
    bool eliminar(int valor) {
        if (cabeza == nullptr) return false;          // Lista vacía

        if (cabeza->dato == valor) {                  // Caso 1: es el primero
            NodoLista* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        // Caso 2: se busca el nodo ANTERIOR al que se quiere eliminar
        NodoLista* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {           // Se encontró
            NodoLista* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;      // Puentea el nodo
            delete temp;                              // Libera memoria
            return true;
        }
        return false;                                 // No se encontró
    }

    // mostrar(): imprime la lista completa, desde la cabeza hasta NULL.
    void mostrar() const {
        NodoLista* actual = cabeza;
        cout << "Estado de Lista: ";
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }
};

#endif
