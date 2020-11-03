
// TAMARA HUERTAS SMOLIS
// A37

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;

// Calcula un vector con los valores acumulados
// Recibe un vector a con los datos de entrada
// Devuelve en un vector diferente v los datos de entrada acumulados
// Postcondicion de la función para todo i: 0 <= i < v.size(): v[i] = Sum k : 0 <= k <= i: a[i]
void resolver(std::vector<int> const& a, std::vector<lli>& v){
	lli acu = 0;
	for (int i = 0; i < a.size(); i++) {
		acu += a[i];
		v.push_back(acu);
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// Lee las dos fechas entre las que tenemos datos
	int a1, a2;
	std::cin >> a1 >> a2;
	if (a1 == 0 && a2 == 0) return false;
	int elem;
	std::vector<int> ini;
	std::vector< lli> acu;

	// Lee el resto de los datos en un vector
	for (int i = 0; i < a2 - a1 + 1; i++) {
		std::cin >> elem;
		ini.push_back(elem);
	}

	resolver(ini, acu);

	// Lectura de las preguntas
	int m; std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int f1, f2;
		std::cin >> f1 >> f2;

		int posF = f2 - a1;
		int restar = f1 - a1 - 1;
		lli res;
		if (restar == -1) {
			res = acu[posF];
		}
		else {
			res = acu[posF] - acu[restar];
		}
		
		std::cout << res << '\n';

	}
	std::cout << "---\n";

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


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}



