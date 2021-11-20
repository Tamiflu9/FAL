// TAMARA HUERTAS SMOLIS
//A37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*
 *	 T(n) =	C				n = 1
 *	 T(n) =	T(n/2) + C		n > 1
 *
 *   Coste: O(log n) siendo n el numero de elementos
 */

int resolver(std::vector<int> const& v, int k, int ini, int fin) {

	if (ini + 1 == fin) {
		
		if (k + ini == v[ini]) {
			return v[ini];
		}
		else {
			return -1;
		}
	}
	else {

		int m = (ini + fin) / 2;

		if (k + m < v[m]) {
			return resolver(v, k, ini, m);
		}
		else {
			return resolver(v, k, m, fin);
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, k, e;
	std::cin >> n >> k;
	std::vector<int> v;

	for (int i = 0; i < n; i++) {
		std::cin >> e;
		v.push_back(e);
	}

	int sol = resolver(v, k, 0, n);

	if (sol == -1) {
		std::cout << "NO" << '\n';
	}
	else {
		std::cout << sol << '\n';
	}
	
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