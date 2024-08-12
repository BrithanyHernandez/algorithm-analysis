#include <iostream>
#include <fstream>
#include <string>

// Definir la estructura para un producto
struct Producto {
    std::string nombre;
    double precio;
};

// Definir la estructura para un cliente
struct Cliente {
    std::string nombre;
    Producto compras[100];
    int cantidadCompras;
    double totalGastado;

    Cliente() : cantidadCompras(0), totalGastado(0.0) {}
};

// Función para leer datos de un archivo
int leerDatos(const std::string& nombreArchivo, Producto productos[], int maxProductos) {
    std::ifstream archivo(nombreArchivo);
    int contador = 0;

    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return 0;
    }
    
    while (archivo >> productos[contador].nombre >> productos[contador].precio) {
        if (++contador >= maxProductos) {
            break;
        }
    }

    archivo.close();
    return contador;
}

// Función para escribir datos en un archivo
void escribirDatos(const std::string& nombreArchivo, const Producto productos[], int cantidad) {
    std::ofstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }
    
    for (int i = 0; i < cantidad; ++i) {
        archivo << productos[i].nombre << " " << productos[i].precio << std::endl;
    }

    archivo.close();
}

// Implementación de Bubble Sort (ineficiente)
void bubbleSort(Producto productos[], int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - 1 - i; ++j) {
            if (productos[j].precio > productos[j + 1].precio) {
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

// Implementación de QuickSort (eficiente)
void quickSort(Producto productos[], int izquierda, int derecha) {
    int i = izquierda;
    int j = derecha;
    double pivot = productos[(izquierda + derecha) / 2].precio;

    while (i <= j) {
        while (productos[i].precio < pivot) {
            ++i;
        }
        while (productos[j].precio > pivot) {
            --j;
        }
        if (i <= j) {
            Producto temp = productos[i];
            productos[i] = productos[j];
            productos[j] = temp;
            ++i;
            --j;
        }
    }

    if (izquierda < j) {
        quickSort(productos, izquierda, j);
    }
    if (i < derecha) {
        quickSort(productos, i, derecha);
    }
}

// Implementación de Bubble Sort para ordenar clientes por total gastado
void bubbleSortClientes(Cliente clientes[], int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - 1 - i; ++j) {
            if (clientes[j].totalGastado > clientes[j + 1].totalGastado) {
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }
}

// Función para buscar un producto por nombre
bool buscarProducto(const Producto productos[], int cantidad, const std::string& nombre) {
    for (int i = 0; i < cantidad; ++i) {
        if (productos[i].nombre == nombre) {
            return true;
        }
    }
    return false;
}

// Función para agregar un nuevo producto
void agregarProducto(Producto productos[], int& cantidad, const std::string& nombre, double precio) {
    productos[cantidad].nombre = nombre;
    productos[cantidad].precio = precio;
    ++cantidad;
}

// Función para mostrar el menú de productos
void mostrarMenuProductos() {
    std::cout << "1. Mostrar productos" << std::endl;
    std::cout << "2. Buscar producto" << std::endl;
    std::cout << "3. Agregar producto" << std::endl;
    std::cout << "4. Ordenar productos (Bubble Sort)" << std::endl;
    std::cout << "5. Ordenar productos (QuickSort)" << std::endl;
    std::cout << "6. Regresar al menú principal" << std::endl;
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    std::cout << "1. Administrar productos" << std::endl;
    std::cout << "2. Crear cliente" << std::endl;
    std::cout << "3. Agregar producto a cliente" << std::endl;
    std::cout << "4. Mostrar clientes" << std::endl;
    std::cout << "5. Ordenar clientes por total gastado" << std::endl;
    std::cout << "6. Guardar y salir" << std::endl;
}

int main() {
    const int MAX_PRODUCTOS = 100;
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = leerDatos("productos.txt", productos, MAX_PRODUCTOS);

    if (cantidadProductos == 0) {
        std::cerr << "No se leyeron datos del archivo." << std::endl;
        return 1;
    }

    const int MAX_CLIENTES = 100;
    Cliente clientes[MAX_CLIENTES];
    int cantidadClientes = 0;

    int opcionPrincipal;
    do {
        mostrarMenuPrincipal();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionPrincipal;
        std::cin.ignore(); // Limpiar el buffer de entrada

        if (opcionPrincipal == 1) {
            // Administrar productos
            int opcionProductos;
            do {
                mostrarMenuProductos();
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcionProductos;
                std::cin.ignore(); // Limpiar el buffer de entrada

                if (opcionProductos == 1) {
                    // Mostrar productos
                    for (int i = 0; i < cantidadProductos; ++i) {
                        std::cout << productos[i].nombre << " " << productos[i].precio << std::endl;
                    }
                } else if (opcionProductos == 2) {
                    // Buscar producto
                    std::string nombreBuscado;
                    std::cout << "Ingrese el nombre del producto: ";
                    std::getline(std::cin, nombreBuscado);
                    if (buscarProducto(productos, cantidadProductos, nombreBuscado)) {
                        std::cout << "Producto " << nombreBuscado << " encontrado." << std::endl;
                    } else {
                        std::cout << "Producto " << nombreBuscado << " no encontrado." << std::endl;
                    }
                } else if (opcionProductos == 3) {
                    // Agregar producto
                    std::string nombre;
                    double precio;
                    std::cout << "Ingrese el nombre del nuevo producto: ";
                    std::getline(std::cin, nombre);
                    std::cout << "Ingrese el precio del nuevo producto: ";
                    std::cin >> precio;
                    std::cin.ignore(); // Limpiar el buffer de entrada

                    if (buscarProducto(productos, cantidadProductos, nombre)) {
                        std::cout << "El producto ya existe." << std::endl;
                    } else {
                        agregarProducto(productos, cantidadProductos, nombre, precio);
                        std::cout << "Producto agregado exitosamente." << std::endl;
                    }
                } else if (opcionProductos == 4) {
                    // Ordenar productos usando Bubble Sort (ineficiente)
                    bubbleSort(productos, cantidadProductos);
                    std::cout << "Productos ordenados usando Bubble Sort." << std::endl;
                } else if (opcionProductos == 5) {
                    // Ordenar productos usando QuickSort (eficiente)
                    quickSort(productos, 0, cantidadProductos - 1);
                    std::cout << "Productos ordenados usando QuickSort." << std::endl;
                } else if (opcionProductos != 6) {
                    std::cout << "Opción inválida. Intente de nuevo." << std::endl;
                }
            } while (opcionProductos != 6);
        } else if (opcionPrincipal == 2) {
            // Crear cliente
            if (cantidadClientes >= MAX_CLIENTES) {
                std::cout << "No se pueden agregar más clientes." << std::endl;
            } else {
                std::string nombreCliente;
                std::cout << "Ingrese el nombre del cliente: ";
                std::getline(std::cin, nombreCliente);
                clientes[cantidadClientes].nombre = nombreCliente;
                ++cantidadClientes;
                std::cout << "Cliente creado exitosamente." << std::endl;
            }
        } else if (opcionPrincipal == 3) {
            // Agregar producto a cliente
            std::string nombreCliente;
            std::cout << "Ingrese el nombre del cliente: ";
            std::getline(std::cin, nombreCliente);

            int clienteIndex = -1;
            for (int i = 0; i < cantidadClientes; ++i) {
                if (clientes[i].nombre == nombreCliente) {
                    clienteIndex = i;
                    break;
                }
            }

            if (clienteIndex == -1) {
                std::cout << "Cliente no encontrado." << std::endl;
            } else {
                std::string nombreProducto;
                std::cout << "Ingrese el nombre del producto: ";
                std::getline(std::cin, nombreProducto);

                int productoIndex = -1;
                for (int i = 0; i < cantidadProductos; ++i) {
                    if (productos[i].nombre == nombreProducto) {
                        productoIndex = i;
                        break;
                    }
                }

                if (productoIndex == -1) {
                    std::cout << "Producto no encontrado." << std::endl;
                } else {
                    clientes[clienteIndex].compras[clientes[clienteIndex].cantidadCompras] = productos[productoIndex];
                    clientes[clienteIndex].totalGastado += productos[productoIndex].precio;
                    clientes[clienteIndex].cantidadCompras++;
                    std::cout << "Producto agregado al cliente exitosamente." << std::endl;
                }
            }
        } else if (opcionPrincipal == 4) {
            // Mostrar clientes
            for (int i = 0; i < cantidadClientes; ++i) {
                std::cout << "Cliente: " << clientes[i].nombre << ", Total Gastado: " << clientes[i].totalGastado << std::endl;
                for (int j = 0; j < clientes[i].cantidadCompras; ++j) {
                    std::cout << "  " << clientes[i].compras[j].nombre << " " << clientes[i].compras[j].precio << std::endl;
                }
            }
        } else if (opcionPrincipal == 5) {
            // Ordenar clientes por total gastado
            bubbleSortClientes(clientes, cantidadClientes);
            std::cout << "Clientes ordenados por total gastado." << std::endl;
        } else if (opcionPrincipal != 6) {
            std::cout << "Opción inválida. Intente de nuevo." << std::endl;
        }
    } while (opcionPrincipal != 6);

    escribirDatos("productos.txt", productos, cantidadProductos);
    std::cout << "Datos guardados. Saliendo del programa." << std::endl;

    return 0;
}