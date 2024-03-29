﻿// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>

// recursion no final
int normal(int n) {
	
	if (n <= 9) {
		return 9 - n;
	}
	else {
		return normal(n / 10) * 10 + (9 - (n % 10));
	}
}

// recursion final
int inverso(int n, int s) {
	
	if (n <= 9) {
		return s * 10 + (9 - n);
	}
	else {
		return inverso(n / 10, s * 10 + 9 - (n % 10));
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int n; 
	std::cin >> n;

	std::cout << normal(n) << ' ' << inverso(n, 0) << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}