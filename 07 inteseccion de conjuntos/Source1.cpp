// TAMARA HUERTAS SMOLIS	
// A37

/*
En la funcion resuelveCaso vamos a tener 2 bucles de coste lineal respecto al numero de elementos que leemos (que van a ser
el numero de elementos de cada vector) y las operaciones de dentro de casa bucle tienen coste constante.
Después vamos a ordenar nuestros dos vectores aplicando la funcion 'sort' a ambos. Esto tiene coste nlog(n) siendo n el numero 
de elementos de cada vector. Por lo que la funcion resuelveCaso tiene coste: O(n log n)

Una vez tenemos los vectores ordenados ya podemos empezar a resolver el problema. La idea es recorrer los dos vectores a la vez
teniendo dos indices, uno para cada vector. Iremos almacenando en un vector nuevo solo los elementos que esten en ambos vectores, 
si en los elementos actuales que estamos analizando de cada vector hay uno que sea menor que el otro avanzaremos el indice de dicho
vector. El coste de esta funcion es lineal respecto al numero de elementos del vector de menor longitud ya que saldremos del bucle
cuando uno de los dos vectores llegue a su fin y no analizeremos los datos del otro vector ya que eso significa que no estan en el 
vector que ya ha llegado a su fin. Po tanto tiene coste: O(n)

Precondicion: {  0 <= a1.size() < 10^9 && 0 <= a2.size() < 10^9 }

Invariante: { paraTodo i,j: 0 <= i < a1.size() , 0 <= j < a2.size() : Existe k: 0 <= k <= i,j : v[k]: a1[i] = a2[j] }

Postcondicion: { paraTodo k: Exixte i,j:  k: 0 <= k <= i,j : v[k]:  a1[i] = a2[j] }

*/

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>


std::vector<int> resolver(std::vector<int> const& a1, std::vector<int> const& a2) {
	int i = 0, j = 0;
	std::vector<int> res;

	while (i < a1.size() && j < a2.size()) {
		if (a1[i] < a2[j]) {
			i++;
		}
		else if (a2[j] < a1[i]) {
			j++;
		}
		else if (a1[i] == a2[j]) {
			res.push_back(a1[i]); // O(1)
			i++; j++;
		}
	}
	return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	int elem;
	std::vector<int> a1,a2;
	std::cin >> elem;
	// leemos primer vector
	while (elem != 0) {
		a1.push_back(elem);
		std::cin >> elem;
	}
	std::cin >> elem;
	// leemos segundo vector
	while (elem != 0) {
		a2.push_back(elem);
		std::cin >> elem;
	}
	// ordenamos los elementos de los dos vectores
	std::sort(a1.begin(),a1.end()); // O(N log N)
	std::sort(a2.begin(), a2.end()); // O(N log N)

	std::vector<int> sol = resolver(a1,a2);
	
	for (int i = 0; i < sol.size(); i++) {
		std::cout << sol[i] << ' ';
	}

	std::cout << "\n";
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