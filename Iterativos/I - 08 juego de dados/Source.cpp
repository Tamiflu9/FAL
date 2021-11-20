// Tamara Huertas Smolis 
// A37

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

/*
coste: la funcion resolver es igual al maximo entre los coste de sus dos bulces. 
El primero tiene coste O(n), done n es el numero de elementos del vector de entrada
El segundo tiene coste O(maxValores), donde maxValores es el numero maximo que se puede conseguir con las tiradas.
O(max (n, maxValores))
*/

// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {
	std::vector<int> repes(maximoValores+1);
	std::vector<int> aux;
	int maxVeces = 0;

	for (int i = 0; i < v.size(); i++) {
		repes[v[i]]++;
		if (repes[v[i]] > maxVeces) {
			maxVeces = repes[v[i]];
		}
	}

	for (int i = repes.size()-1; i > 0; i--) {
		if (repes[i] == maxVeces) {
			aux.push_back(i);
		}
	}

	return aux;
}

// Entrada y salida de datos
bool resuelveCaso() {

	int numTiradas, valorMax;
	std::cin >> numTiradas >> valorMax;
	
	if (numTiradas == -1) return false;  // Entrada con centinela
	
	std::vector<int> v(numTiradas);
	
	for (int& i : v) std::cin >> i;
	// LLamada a la funcion resolver para calcular los valores que 
	// aparecen más veces
	
	std::vector<int> res = resolver(v,valorMax);	

	// Escribir los valores del vector que ha calculado resolver
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << ' ';
	}
	std::cout << "\n";

	return true;
}

int main() {

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

