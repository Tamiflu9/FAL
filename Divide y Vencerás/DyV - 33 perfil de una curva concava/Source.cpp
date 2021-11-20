// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin) {

	if (ini + 1 == fin) {
		return v[ini];
	}
	else {
		int m = (ini + fin) / 2;

		if (v[m] > v[m - 1]) {
			return resolver(v, ini, m);
		}
		else {
			return resolver(v, m, fin);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, e;
	std::cin >> n;

	if (!std::cin)
		return false;

	std::vector<int> v;

	for (int i = 0; i < n; i++) {
		std::cin >> e;
		v.push_back(e);
	}

	std::cout << resolver(v, 0, n) << '\n';
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}