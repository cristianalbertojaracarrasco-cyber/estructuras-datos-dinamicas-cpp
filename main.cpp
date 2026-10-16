/*
 * ============================================================
 * Archivo   : main.cpp
 * Asignatura: Estructura de Datos Dinámicos - CFT CENCO
 * Docente   : Raúl G. Villegas T.
 * Propósito : Programa de ejemplos de uso de la biblioteca.
 *             Prueba la Lista Enlazada Simple, la Pila (LIFO)
 *             y la Cola (FIFO) e imprime los resultados.
 * Compilar  : g++ -std=c++11 -Wall main.cpp -o estructuras
 * Ejecutar  : ./estructuras        (en Windows: estructuras.exe)
 * ============================================================
 */
#include <iostream>
#include "ListaEnlazada.h"
#include "Pila.h"
#include "Cola.h"
using namespace std;

int main() {
    cout << "=== PRUEBA DE ESTRUCTURAS DE DATOS DINAMICAS EN C++ ===" << endl;

    // ---------- 1. LISTA ENLAZADA SIMPLE ----------
    cout << "\n--- LISTA ENLAZADA SIMPLE ---" << endl;
    ListaEnlazadaSimple lista;
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.mostrar();                                   // 30 -> 20 -> 10 -> NULL

    cout << "Buscar 20: " << (lista.buscar(20) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 99: " << (lista.buscar(99) ? "Encontrado" : "No encontrado") << endl;

    cout << "Eliminar 20: " << (lista.eliminar(20) ? "Eliminado" : "No existe") << endl;
    lista.mostrar();                                   // 30 -> 10 -> NULL
    cout << "Eliminar 99: " << (lista.eliminar(99) ? "Eliminado" : "No existe") << endl;

    // ---------- 2. PILA (LIFO) ----------
    cout << "\n--- PILA (LIFO) ---" << endl;
    Pila pila;
    pila.push(100);
    pila.push(200);
    pila.mostrar();                                    // 200 100
    cout << "pop(): " << pila.pop() << endl;          // 200 (último en entrar)
    cout << "pop(): " << pila.pop() << endl;          // 100
    cout << "Pila vacia?: " << (pila.estaVacia() ? "Si" : "No") << endl;
    pila.pop();                                        // Caso borde: pila vacía

    // ---------- 3. COLA (FIFO) ----------
    cout << "\n--- COLA (FIFO) ---" << endl;
    Cola cola;
    cola.InsertarQ(500);
    cola.InsertarQ(600);
    cola.mostrar();                                    // 500 600
    cout << "EliminarQ(): " << cola.EliminarQ() << endl; // 500 (primero en llegar)
    cout << "EliminarQ(): " << cola.EliminarQ() << endl; // 600
    cout << "Cola vacia?: " << (cola.estaVacia() ? "Si" : "No") << endl;
    cola.EliminarQ();                                  // Caso borde: cola vacía

    cout << "\n=== PRUEBAS CONCLUIDAS EXITOSAMENTE ===" << endl;
    return 0;  // Al salir, los destructores liberan la memoria restante
}
