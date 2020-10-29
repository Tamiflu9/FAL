// TAMARA HUERTAS SMOLIS
// A37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

int resolver(std::vector<int> const& v) {

	int longMax = 0, longAct = 0, aux = v[0], max = 0;
	for (int i = 0; i < v.size(); i++) {

		if (v[i] == aux) {
			++longAct;

			if (longAct > longMax) {
				longMax = longAct;
				max = v[i];
			}

		}
		else {
			longAct = 1;
			aux = v[i];

		}
	}
	return max;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n; std::cin >> n;

	if (n == -1)
		return false;
	std::vector<int> v;
	int elem;

	for (int i = 0; i < n; i++) {
		std::cin >> elem;
		v.push_back(elem);
	}
	std::sort(v.begin(), v.end());

	std::cout << resolver(v) << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}