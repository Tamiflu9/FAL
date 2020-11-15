// TAMARA HUERTAS SMOLIS
// A37


#include <iostream>
#include <iomanip>
#include <fstream>


int sol(long long int numero) {

	if (numero < 10) {
		return 1;
	}
	else {
		return 1 + sol(numero/10);
	}

 }


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int num;
	std::cin >> num;

	if (!std::cin)
		return false;

	std::cout << sol(num) << '\n';


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