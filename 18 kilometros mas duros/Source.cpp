// TAMARA HUERTAS SMOLIS
// A37

/*
Idea:

En el primer bucle se calculan los valores del struct para del primer intervalo.

En el bucle que recorre el resto del vector, iremos comprobaremos para los demas intervalos, quitando el elemento de la
izquierda y añadiendo el elemento de la derecha, y si dicho intervalo tiene mayor desnivel se actualiza el maximo o si se
repite el mayor desnivel actualizamos la posicon del ultimo (posicion donde empieza el ultimo intervalo con ese desnivel).

Coste:

El algoritmo tiene dos bucle. 

El primero se ejecuta tantas veces como el tamaño del intervalo. Las instrucciones del bucle son de coste constante, 
por lo tanto el coste es el numero de vueltas que da el bucle por el coste constante de cada vuelta. 
-> El coste es: O(p), siendo p el tamaño del intervalo.

El segundo bucle recorre todos los elementos del vector desde el final del primer intervalo hasta el final del vector. 
Por lo tanto el numero de vueltas que da es v.size() - p. En cada vuelta se realizan operaciones de coste constante. 
-> El coste es: O(v.size() − p).

*/

#include <iostream>
#include <fstream>
#include <vector>

struct sol {
	int desnivel; // maximo desnivel
	int primer; // posicion donde empieza el primer intervalo
	int ultimo; // posicion donde empieza el ultimo tramo
};

sol resolver(std::vector<int> const& v, int p) {
	sol res;

	int acu = 0; // suma del desnivel
	// inicializamos a cero todo
	res.desnivel = 0;
	res.primer = 0;
	res.ultimo = 0;

	for (int i = 0; i < p; ++i) { // primer intervalo
		acu += v[i];
	}

	res.desnivel = acu;
	// Bucle principal
	for (auto j = p; j < v.size(); ++j) { // avanza el intervalo una posicion

		// quitamos el elemento de la izquierda y añadimos el de la derecha
		acu = acu - v[j - p];
		acu = acu + v[j];
		
		// comprobamos cual el mayor desnivel
		if (acu > res.desnivel) {
			res.desnivel = acu;
			res.primer = j-p+1;
			res.ultimo = res.primer;
		}else if (acu == res.desnivel) {
			res.ultimo = j-p+1;
		}
	}
	
	// si no se ha repetido otra vez el denivel maximo
	if (res.ultimo == 0) {
		res.ultimo = res.primer;
	}

	return res;
}

bool resuelveCaso() {
	int kilometro, tramo;
	std::cin >> kilometro >> tramo;
	if (kilometro == 0 && tramo == 0) return false;

	int e;
	std::vector<int> v;

	for (int i = 0; i < kilometro; i++) {
		std::cin >> e;
		v.push_back(e);
	}

	sol solucion = resolver(v, tramo);

	std::cout << solucion.desnivel << ' ' << solucion.primer << ' ' << solucion.ultimo << "\n";

	return true;
}


int main() {
	// Para la entrada por fichero .
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	// Entrada con centinela
	while (resuelveCaso())
		;
	// Para restablecer entrada .
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
#endif
	return 0;
}