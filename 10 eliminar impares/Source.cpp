// TAMARA HUERTAS SMOLIS
// A37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Tenemos un entero 'pos' donde vamos a ir guardando la ultima posicion del elemento 'bueno', en este caso la posicion
// donde el valor del vector es par. Recorremos los elementos del vector y vamos mirando componente a componente si
// el valor es par, si es par guardamos ese valor en v[pos], para tener al principio los elementos 'buenos' y despues
// redimensionar el vector al tamaño de las componentes 'buenas'

// Coste lineal en el numero de alumnos matriculados.


// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int> & v) {
	int pos = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			v[pos] = v[i];
			pos++;
		}
	}
	v.resize(pos);
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
	// Leer datos de entrada
	int numElem;
	std::cin >> numElem;

	if (numElem == -1) return false;

	std::vector<int> v(numElem);

	for (int i = 0; i < numElem; ++i) {
		std::cin >> v[i];
	}
	// LLamada a la función resolver
	resolver(v);
	// Escribir el vector resultado
	if (v.size() > 0) std::cout << v[0];
	for (int i = 1; i < v.size(); ++i)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	return true;
}

int main() {
	// Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
