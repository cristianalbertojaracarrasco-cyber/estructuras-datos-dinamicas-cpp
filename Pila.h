/*
 * ============================================================
 * Archivo   : Pila.h
 * Asignatura: Estructura de Datos Dinámicos - CFT CENCO
 * Docente   : Raúl G. Villegas T.
 * Propósito : Implementación de una PILA (Stack) con punteros.
 *             Política LIFO: el último en entrar es el primero
 *             en salir. Todo ocurre en un solo extremo: la cima.
 * Operaciones: push, pop, estaVacia y mostrar.
 * ============================================================
 */
#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;

// Nodo de la pila: dato + puntero al nodo que está "debajo".
struct NodoPila {
    int dato;
    NodoPila* siguiente;
};

class Pila {
private:
    NodoPila* cima;  // Elemento superior de la pila (nullptr si vacía)

public:
    // Constructor: pila vacía.
    Pila() : cima(nullptr) {}

    // Se bloquea la copia para evitar doble liberación de nodos.
    Pila(const Pila&) = delete;
    Pila& operator=(const Pila&) = delete;

    // Destructor: desapila y libera todos los nodos restantes.
    ~Pila() {
        while (cima != nullptr) {
            NodoPila* temp = cima;
            cima = cima->siguiente;
            delete temp;
        }
    }

    /*
     * push(valor)
     * Crea un nodo nuevo y lo coloca sobre la cima. Costo O(1).
     */
    void push(int valor) {
        NodoPila* nuevo = new NodoPila();
        nuevo->dato = valor;
        nuevo->siguiente = cima;  // El nuevo queda encima del anterior
        cima = nuevo;             // Se actualiza la cima
        cout << "[Pila Push] Agregado a la cima: " << valor << endl;
    }

    /*
     * pop()
     * Retira el elemento de la cima y devuelve su valor. Costo O(1).
     * Si la pila esta vacia informa el error y retorna -1
     * (valor centinela; por eso se recomienda llamar antes a estaVacia()).
     */
    int pop() {
        if (cima == nullptr) {
            cout << "[Pila] Error: la pila esta vacia (subdesbordamiento)" << endl;
            return -1;
        }
        NodoPila* temp = cima;
        int valor = temp->dato;   // Se guarda el dato antes de liberar
        cima = cima->siguiente;   // La cima baja un nivel
        delete temp;              // Se libera el nodo retirado
        return valor;
    }

    // estaVacia(): true si no hay elementos.
    bool estaVacia() const { return cima == nullptr; }

    // mostrar(): imprime desde la cima hacia el fondo.
    void mostrar() const {
        cout << "Estado de Pila (cima -> fondo): ";
        for (NodoPila* p = cima; p != nullptr; p = p->siguiente) cout << p->dato << " ";
        cout << endl;
    }
};

#endif
