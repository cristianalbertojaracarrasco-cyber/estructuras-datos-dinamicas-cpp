/*
 * ============================================================
 * Archivo   : Cola.h
 * Asignatura: Estructura de Datos Dinámicos - CFT CENCO
 * Docente   : Raúl G. Villegas T.
 * Propósito : Implementación de una COLA (Queue) con punteros.
 *             Política FIFO: el primero en entrar es el primero
 *             en salir. Se inserta por el FINAL y se retira por
 *             el FRENTE.
 * Operaciones: InsertarQ (enqueue), EliminarQ (dequeue),
 *              estaVacia y mostrar.
 * ============================================================
 */
#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;

// Nodo de la cola: dato + puntero al nodo que llegó después.
struct NodoCola {
    int dato;
    NodoCola* siguiente;
};

class Cola {
private:
    NodoCola* frente;  // Primer elemento (el próximo en ser atendido)
    NodoCola* finalQ;  // Último elemento (el que llegó más recientemente)

public:
    // Constructor: cola vacía, ambos punteros en nullptr.
    Cola() : frente(nullptr), finalQ(nullptr) {}

    // Se bloquea la copia para evitar doble liberación de nodos.
    Cola(const Cola&) = delete;
    Cola& operator=(const Cola&) = delete;

    // Destructor: libera todos los nodos desde el frente.
    ~Cola() {
        while (frente != nullptr) {
            NodoCola* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    /*
     * InsertarQ(valor)  -> enqueue
     * Agrega un nodo al FINAL de la cola. Gracias al puntero
     * finalQ la operación es O(1) (no hay que recorrer la cola).
     */
    void InsertarQ(int valor) {
        NodoCola* nuevo = new NodoCola();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;      // Será el último

        if (finalQ == nullptr) {         // Cola vacía: frente y final
            frente = finalQ = nuevo;     // apuntan al mismo nodo
        } else {
            finalQ->siguiente = nuevo;   // Se enlaza tras el último
            finalQ = nuevo;              // y pasa a ser el nuevo final
        }
        cout << "[Cola InsertarQ] Encolado: " << valor << endl;
    }

    /*
     * EliminarQ()  -> dequeue
     * Retira el nodo del FRENTE y devuelve su valor. Costo O(1).
     * Si la cola queda vacía, finalQ también vuelve a nullptr.
     * Si ya estaba vacía informa el error y retorna -1 (centinela).
     */
    int EliminarQ() {
        if (frente == nullptr) {
            cout << "[Cola] Error: la cola esta vacia" << endl;
            return -1;
        }
        NodoCola* temp = frente;
        int valor = temp->dato;
        frente = frente->siguiente;
        if (frente == nullptr) finalQ = nullptr;  // Evita puntero colgante
        delete temp;
        return valor;
    }

    // estaVacia(): true si no hay elementos.
    bool estaVacia() const { return frente == nullptr; }

    // mostrar(): imprime desde el frente hasta el final.
    void mostrar() const {
        cout << "Estado de Cola (frente -> final): ";
        for (NodoCola* p = frente; p != nullptr; p = p->siguiente) cout << p->dato << " ";
        cout << endl;
    }
};

#endif
