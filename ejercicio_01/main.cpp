#include "header.hpp"

int main()
{
  Ingrediente ingredientes[4];

  FecEla fecha1 = {1, 1, 2024};
  ingredientes[0] = Ingrediente("Cebollas", 150, 399.9, fecha1);

  FecEla fecha2 = {2, 1, 2024};
  ingredientes[1] = Ingrediente("Caldos", 38, 150, fecha2);

  FecEla fecha3 = {3, 1, 2024};
  ingredientes[2] = Ingrediente("Morrón", 82, 456, fecha3);

  string producto;
  float gramos;
  float precio;
  FecEla fecha4;

  cout << "Ingrese el nombre del ingrediente 4: ";
  getline(cin, producto);
  cout << "Ingrese los gramos del ingrediente 4: ";
  cin >> gramos;
  cout << "Ingrese el precio del ingrediente 4: ";
  cin >> precio;
  cout << "Ingrese la fecha del ingrediente 4 (dd mm yyyy): ";
  cin >> fecha4.dd >> fecha4.mm >> fecha4.aa;
  cin.ignore();

  ingredientes[3] = Ingrediente(producto, gramos, precio, fecha4);


  Tiempo tiempo(1, 30);
  Condimentos condimentos[2] = {SAL, AJO};
  Plato plato("Receta de ejemplo", tiempo, ingredientes, condimentos);

  mostrarPlato(plato);

  double costoPlato1 = 0.0;
  for (int i = 0; i < 4; ++i)
  {
    costoPlato1 += plato.getIngredientes()[i].getPrecio();
  }
  double costoPlato2 = costoPlato1 * 1.1;

  cout << "Costo del primer platillo: $" << costoPlato1 << endl;
  cout << "Costo del segundo platillo: $" << costoPlato2 << endl;

  cin.get();
  return 0;
}
