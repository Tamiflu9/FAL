// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>


int no_ffinal(int n) {

	if (n <= 9) {
		return n * 10 + n;
	}
	else {
		return no_ffinal(n / 10) * 100 + n % 10 * 10 + n % 10;
	}
}

int ffinal(int n, int s, int pot) {

	if (n == 0) {
		return s;
	}
	if (n <= 9) {
		return (n * 10 + n)*pot + s;
	}
	else {
		return ffinal(n / 10, (n % 10 * 10 + n % 10)*pot + s, pot * 100);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int n; 
	std::cin >> n;

	std::cout << no_ffinal(n) << ' ' << ffinal(n, 0, 1) << '\n';

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