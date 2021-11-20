// TAMARA HUERTAS SMOLIS
//A37


#include <iostream>
#include <iomanip>
#include <fstream>

/*
coste:								
			C1			si n == 0	
	T(n) =  C1			si n == 1		=>	O(n)
			T(n-1)		si n > 1	
	
	En los casos base son operaciones de coste constante ya que son operaciones de retorno
	En el caso recursivo como se llama a la funcion recursiva diminuyendo en una unidad el parametro n 
		y en los demas parametros hacemos operaciones de coste constante, el coste final es del orden de n
		siendo n el valor del numero del que queremos averiguar su sucesión de fibonacci ya que se van a 
		hacer tantas llamadas con valor tenga la n.
*/
long long int resolver(int n, long long int n1, long long int n2) {
	
	if (n == 0) {
		return n2;
	}
	if (n == 1) {
		return n1;
	}
	else {
		return resolver(n - 1, n1 + n2, n1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n; 
	std::cin >> n;

	if (!std::cin)
		return false;

	std::cout << resolver(n, 1, 0) << '\n';


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