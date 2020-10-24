// TAMARA HUERTAS SMOLIS	
// A37

/*
Idea:

Vamos a tener una variable max donde vamos a ir actualizando el valor en cada vuelta del bucle, si el numero actual
es mas gandre que el maximo, significa que todos los valores anteriores son menores que el y por tanto tenemos que guardar
el año correspondiente, si no lo es avanzamos sin hacer nada. Para ir guardando los años, vamos a guardar la posicion en la
que se cuentran los valores mas grandes en un vector nuevo y luego en resuelve caso al recorrer dicho vector vamos a sumar
la fecha de inicio a cada componente del vector y asi calcular el año correspondiente.

coste:

Todas las operaciones que hacemos dentro de todos los bucles tienen coste constante.

La funcion resolver tiene coste linel respecto al numero de elementos del vector de entrada ya que lo vamos a recorrer entero.

La funcion resuelveCaso tiene dos buecles, el primero tiene coste lineal respecto al numero de datos que leemos y
el segundo tiene coste lineal respecto al numero de elemetos que tiene el vector nuevo devuelto por al funcion resolver.

-> Coste final: O(N)

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

vector<int> resolver(vector<int> const& datos) {
	int max = datos[0], i = 1;
	vector<int> res;

	while (i < datos.size()){
		if (datos[i] > max) {
			res.push_back(i);
			max = datos[i];
		}
		i++;
	}

	return res;
}


void resuelveCaso() {

	int ini, fin, elem; cin >> ini >> fin;
	vector<int> datos;

	// coste lineal respecto el numero de datos que leemos
	for (int i = ini; i <= fin; i++) {
		cin >> elem;
		datos.push_back(elem);
	}

	vector<int> sol = resolver(datos);

	// coste lineal respecto el numero de datos del vector
	for (auto i = 0; i < sol.size(); i++) {
		cout << ini+sol[i] << ' ';
	}
	cout << "\n";
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