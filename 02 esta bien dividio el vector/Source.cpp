// Tamara Huertas Smoli
// A37

/*
Idea: 
Si el indice p señala a la ultima siempre sera cierto

Si no, dividimos el vector en dos partes:

	-> la primera parte va desde 0 a p
	-> la segunda parte va desde p+1 a v.size()

y nos vamos a quedar con la componente mas grande del primer tramo (max) y con la componenete mas pequeña del segundo (min),
para compararlas y si la componente max es mas pequeña de min se cumple.

Complejidad: En el caso mejor coste constante.
			 En el caso peor coste lineal respecto al numero de elementos del vector.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool div_vector(vector<int> const&v, int p) {

	if (p == v.size()-1) {
		return true;
	}
	else {
		// dejamos inicializados los indices
		int i = 1, max = v[0], min = v[p + 1];

		// tratamos la primera parte del vector
		while (i <= p) {
			if (v[i] > max) {
				max = v[i];
			}
			i++;
		}
		// tratamos la segunda parte del vector
		i = p + 2;

		while (i < v.size()) {
			if (min > v[i]) {
				min = v[i];
			}
			i++;
		}
		// comparamos resultados
		if (min > max) {
			return true;
		}
		else {
			return false;
		}
	}
	
}


void resuelveCaso() {

	int tam, p, num;
	cin >> tam >> p;

	vector<int> v(tam);

	for (int i = 0; i < tam; i++) {
		cin >> num;
		v[i] = num;
	}

	if (div_vector(v, p)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}

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