#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
// Para numeric_limits

const int MAX_PEDIDOS = 100; // Máxima cantidad de pedidos que se pueden almacenar
const int TAM_PEDIDO = 50;   // Tamaño máximo de un pedido
   char vocal;
void cargarPedido(char pedidos[][TAM_PEDIDO], int &contador);
void procesarPedido(const char* pedido);
int strcasecmp_custom(const char *s1, const char *s2);

int main() {
    char pedidos[MAX_PEDIDOS][TAM_PEDIDO];
    int contador = 0;
    std::cout << "Bienvenidos a la Mejor tienda de comida rapida Ingrese los datos" << std::endl;
    // Cargar algunos pedidos para demostrar el funcionamiento
    cargarPedido(pedidos, contador);
   //cargarPedido(pedidos, contador);
   //cargarPedido(pedidos, contador);

    // Procesar todos los pedidos
    for (int i = 0; i < contador; ++i) {
        std::cout << "\nProcesando pedido: " << pedidos[i] << std::endl;
        procesarPedido(pedidos[i]);
    }

    return 0;
}

void cargarPedido(char pedidos[][TAM_PEDIDO], int &contador) {
    if (contador >= MAX_PEDIDOS) {
        std::cerr << "No se aceptan mas pedidos, Cerramos cocina." << std::endl;
        return;
    }
    std::cout << "Ingrese su hamburgesa Ejemplo: BigCheddar-Coca-Grande : " << std::endl;


    std::cout << "" ;
    std::cin.getline(pedidos[contador], TAM_PEDIDO);

    contador++;

}

void procesarPedido(const char* pedido) {
    char pedidoCopia[TAM_PEDIDO];
    strncpy(pedidoCopia, pedido, TAM_PEDIDO); // Copiamos el pedido para no modificar el original

    // a. Obtener el primer token (hamburguesa)
    char* token = strtok(pedidoCopia, "-");
    if (token == nullptr) {
        std::cerr << "Formato de pedido incorrecto." << std::endl;
        return;
    }
    std::cout << "Hamburguesa: " << token << std::endl;

    // b. Determinar la longitud de la cadena token obtenida
    size_t longitud = strlen(token);
    std::cout << "Longitud de la hamburguesa: " << longitud << std::endl;

    // c. Verificar y anexar "cheddar" si es necesario
    const char* cheddar = "cheddar";
    if (strcasecmp_custom(token, cheddar) == 0) {
        std::cout << "La hamburguesa es 'cheddar'." << std::endl;
    }
    if (strstr(token, cheddar) != nullptr) {
        std::cout << "'cheddar' está contenido en la hamburguesa." << std::endl;
    } else {
        strcat(token, "Cheddar");
        std::cout << "Cadena de hamburguesa modificada: " << token << std::endl;
    }

    // d. Verificar la presencia de una vocal en el token
    //char vocal;
    std::cout << "Ingrese una vocal para verificar en la hamburguesa: ";
    std::cin >> vocal;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada

    if (strchr(token, vocal) !=  NULL) {
        std::cout << "La vocal '" << vocal << "' está presente en la hamburguesa." << std::endl;
    } else {
        std::cout << "La vocal '" << vocal << "' no está presente en la hamburguesa." << std::endl;
    }
}

int strcasecmp_custom(const char *token1, const char *token2) {
    while (*token1 && *token2) {
        if (tolower(*token1) != tolower(*token2)) {
            return tolower(*token1) - tolower(*token2);
        }
        token1++;
        token2++;
    }
    return tolower(*token1) - tolower(*token2);
};
