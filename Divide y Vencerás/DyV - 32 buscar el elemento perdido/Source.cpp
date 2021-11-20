// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
 *	 T(n) =	C				n = 0, n = 1
 *	 T(n) =	T(n/2) + C		n > 1
 *
 *   Coste: O(log n) siendo n el numero de elementos
 */

int resolver(std::vector<int> const& a, std::vector<int> const& b, int ini, int fin) {

	if (ini == fin) {

		return a[ini];
	}
	if (ini + 1 == fin) {

		if (a[ini] == b[ini]) {
			return a[fin];
		}
		else {
			return a[ini];
		}
	}
	else {

		int m = (ini + fin) / 2;
		
		if (a[m] != b[m]) {
			return resolver(a, b, ini, m);
		}
		else {
			return resolver(a, b, m, fin);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	int n, e;
	std::cin >> n;

	std::vector<int> a, b;

	for (int i = 0; i < n; i++) {
		std::cin >> e;
		a.push_back(e);
	}

	for (int i = 0; i < n - 1; i++) {
		std::cin >> e;
		b.push_back(e);
	}

	std::cout << resolver(a, b, 0, n-1) << '\n';

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