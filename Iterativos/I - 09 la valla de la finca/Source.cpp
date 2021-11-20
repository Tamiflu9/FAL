// TAMARA HUERTAS SMOLIS
// A37

# include <iostream>
# include <fstream>
# include <vector>

int resolver(std::vector<int> & v, int p) {
	// Inicializar los valores con el primer intervalo
	//int cont = 0; // Numero de intervalos que tienen el mismo numero de huecos
	int maxHueco = 0; // mayor numero de huecos
	int hueco = 0; // Numero de porciones de valla con huecos
	int sin_h = 0; // numero de porciones de valla sin huecos
	int res = 0;

	for (int i = 0; i < p; ++i) { // primer intervalo
		if (v[i] == 1) ++sin_h;
		else if (v[i] == 0) ++hueco;
	}
	maxHueco = hueco;// inicializamos con los valores del primer intervalo
	// Bucle principal
	for (int j = p; j < v.size(); ++j) { // avanza el intervalo una posicion
	
		// eliminamos la porcion de la izquierda
		if (v[j-p] == 0) {
			--hueco;
		}
		else if(v[j-p] == 1){
			--sin_h;
		}
		// anadimos la porcion de la derecha
		if(v[j] == 0) {
			++hueco;
		}
		else if (v[j] == 1) {
			++sin_h;
		}
		
		// comprobamos la posicion desde donde debe empezar la valla
		if (hueco >= maxHueco) {
			maxHueco = hueco;
			res = j - p + 1;
		}
		
	}
	if (maxHueco == 0) res = -1;
	return res;
}

bool resuelveCaso() {
	int numElem;
	std::cin >> numElem;
	if (numElem == 0) return false;

	int longValla, e;
	std::cin >> longValla;

	std::vector<int> v;

	for (int i = 0; i < numElem; i++) {
		std::cin >> e;
		v.push_back(e);
	}

	int cont = resolver(v,longValla);

	if (cont == -1) {
		std::cout << "No hace falta\n";

	}
	else {
		std::cout << cont << "\n";

	}
	return true;
}


int main() {
	// Para la entrada por fichero .
#ifndef DOMJUDGE
	std::ifstream in("09sample.in");
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