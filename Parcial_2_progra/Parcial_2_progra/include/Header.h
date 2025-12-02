#pragma once

/**
 * @file
 * @brief Inclusión de bibliotecas estándar necesarias para la gestión de productos y operaciones relacionadas.
 */

#include <vector>        ///< @brief Para manejar listas dinámicas de elementos, como colecciones de productos.
#include <string>        ///< @brief Para manipulación de cadenas de texto (nombres, descripciones, etc.).
#include <ctime>         ///< @brief Para trabajar con fechas y tiempos, útil en registros o caducidades.
#include <iostream>      ///< @brief Para entrada/salida estándar (mostrar/solicitar datos por consola).
#include <unordered_map> ///< @brief Para estructuras de mapeo rápido (asociar códigos de productos con sus datos).
#include <fstream>       ///< @brief Para operaciones de lectura y escritura en archivos (guardar o cargar datos de productos).
#include <stdexcept>     ///< @brief Para manejo de excepciones estándar (errores comunes en tiempo de ejecución).
#include <cstdlib>       ///< @brief Para utilidades generales, como la función 'exit()' para terminar el programa.