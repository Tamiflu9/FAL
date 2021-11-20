// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>


// recursion final
int resolver(int n, int s) {

	if (n < 10) {
		return s * 10 + n;
	}
	else {
		s = s *10 + n % 10;
		return resolver(n/10, s);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n; 
	std::cin >> n;
	
	if (n == 0)
		return false;

	
	std::cout << resolver(n, 0) << '\n';

	// escribir sol

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
