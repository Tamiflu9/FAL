// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>


// recursion final
long long int resolver(long long int n, long long int s, int pot) {

	if (n < 10) {
		if (n % 2 == 0) {
			return s;
		}
		else {
			return n * pot + s;
		}
	}
	else {
		if (n % 2 == 0) {
			return resolver(n / 10, s, pot);
		}
		else {
			return resolver(n / 10, n % 10 * pot + s, pot * 10);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int n;
	std::cin >> n;

	if (!std::cin)
		return false;

	std::cout << resolver(n, 0, 1) << '\n';


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