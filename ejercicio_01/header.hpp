#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <iostream>
#include <string>
using namespace std;

enum Condimentos { SAL = 1, PIMIENTA, AJO, OREGANO, PEREJIL, ACEITE };

struct FecEla {
    int dd;
    int mm;
    int aa;
};

struct Tiempo {
private:
    int hora;
    int min;
public:
    Tiempo() : hora(0), min(0) {}
    Tiempo(int hh, int mi) : hora(hh), min(mi) {}

    void setHora(int hh) { hora = hh; }
    void setMinutos(int mi) { min = mi; }

    int getHora() { return hora; }
    int getMinutos() { return min; }
};

struct Ingrediente {
private:
    string producto;
    float gramos;
    float precio;
    FecEla fecEla;
public:
    Ingrediente() : gramos(0), precio(0) {}
    Ingrediente(string prod, float gr, float pr, FecEla fec) : producto(prod), gramos(gr), precio(pr), fecEla(fec) {}

    void setProducto(string prod) { producto = prod; }
    void setGramos(float gr) { gramos = gr; }
    void setPrecio(float pr) { precio = pr; }
    void setFecElaboracion(FecEla fec) { fecEla = fec; }

    string getProducto() { return producto; }
    float getGramos() { return gramos; }
    float getPrecio() { return precio; }
    FecEla getFecElaboracion() { return fecEla; }
};

struct Plato {
private:
    string receta;
    Tiempo tiempo;
    Ingrediente ingredientes[4];
    Condimentos condimentos[2];
public:
    Plato() {}
    Plato(string rec, Tiempo ti, Ingrediente ingr[4], Condimentos cond[2]) : receta(rec), tiempo(ti) {
        for (int i = 0; i < 4; ++i) {
            ingredientes[i] = ingr[i];
        }
        condimentos[0] = cond[0];
        condimentos[1] = cond[1];
    }

    void setReceta(string rec) { receta = rec; }
    void setTiempo(Tiempo ti) { tiempo = ti; }
    void setIngredientes(Ingrediente ingr[4]) {
        for (int i = 0; i < 4; ++i) {
            ingredientes[i] = ingr[i];
        }
    }
    void setCondimentos(Condimentos cond[2]) {
        condimentos[0] = cond[0];
        condimentos[1] = cond[1];
    }

    string getReceta() { return receta; }
    Tiempo getTiempo() { return tiempo; }
    Ingrediente* getIngredientes() { return ingredientes; }
    Condimentos* getCondimentos() { return condimentos; }
};

void mostrarIngrediente(const Ingrediente& ing);
void mostrarPlato(const Plato& plato);


#include "funciones.cpp"
#endif
