// Tamara Huertas Smolis 
// A37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado
/*
Idea: Vamos a tener una variable 'sumaTotal' donde almacenamos la suma de todos los elementos del vector, una variable 'min' 
      donde almacenamos el minimo elemento del vector y una variable 'n' que cuenta el numero de veces que aparece el minimo.
	  Después de calcular la suma total, el minimo y las veces que aparece este, a la suma total le restamos el minimo tantas 
	  veces como aparece en el vector.

Coste: lineal respecto al numero de elementos del vector.
*/

// Coste del algoritmo utilizado

struct sol {
	int suma;
	int num;
};

// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
sol resolver(std::vector<int> const&v) {
	int sumaTotal = v[0], n = 1, min = v[0];

	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == min) {
			n++;
		}
		else if (v[i] < min){
			n = 1;
			min = v[i];
		}
		sumaTotal += v[i];
	}

	sumaTotal = sumaTotal - (min * n);
	n = v.size() - n;

	return { sumaTotal, n };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// Lectura de los datos
	int numElem;
	std::cin >> numElem;
	std::vector<int> v(numElem);
	for (int& i : v) std::cin >> i;
	// LLamar a la función resolver
	sol s = resolver(v);
	// Escribir los resultados
	std::cout << s.suma << ' ' << s.num << '\n';
}

int main() {
	// Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("03sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
