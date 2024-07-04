#include "header.hpp"

void mostrarIngrediente(Ingrediente &ing)
{
  cout << "Producto: " << ing.getProducto() << ", Gramos: " << ing.getGramos() << ", Precio: $" << ing.getPrecio() << ", Fecha: " << ing.getFecElaboracion().dd << "-" << ing.getFecElaboracion().mm << "-" << ing.getFecElaboracion().aa << endl;
}

void mostrarPlato(Plato &plato)
{
  cout << "Receta: " << plato.getReceta() << ", Tiempo: " << plato.getTiempo().getHora() << ":" << plato.getTiempo().getMinutos() << endl;
  for (int i = 0; i < 4; ++i)
  {
    mostrarIngrediente(plato.getIngredientes()[i]);
  }
  cout << "Condimentos: " << plato.getCondimentos()[0] << ", " << plato.getCondimentos()[1] << endl;
}