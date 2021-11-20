// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>


int no_ffinal(int n, int k) {

	if (n <= 9) {
		if (n == k) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (n % 10 == k){
			return no_ffinal(n / 10, k) + 1;
		}
		else {
			return no_ffinal(n / 10, k);
		}
	}
}

int ffinal(int n, int k, int s) {

	if (n <= 9) {
		if (n % 10 == k) {
			return 1 + s;
		}
		else {
			return s;
		}
	}
	else {
		if (n % 10 == k) {
			return ffinal(n / 10, k, 1 + s);
		}
		else {
			return ffinal(n / 10, k, s);
		}	
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int n, k; 
	std::cin >> n >> k;

	std::cout << no_ffinal(n, k) << ' ' << ffinal(n, k, 0) << '\n';

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