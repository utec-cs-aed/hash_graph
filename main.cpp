#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <cmath>
#include "graph.h"

using namespace std;

Graph<int, float> testOperation(Graph<int, float> *grafito){
	auto start = std::chrono::steady_clock::now();	
	Graph<int, float> result = grafito->execKruskal();
	auto end = std::chrono::steady_clock::now();
	//show the elapsed time
    cout << "Elapsed time in microseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
    return result;
}

int main()
{
	//Grafo estructurado con lista de adyacencias
	ListGraph<int, float> grafitoAdy;
	//Grafo estructurado con hash de adyacencias
	HashGraph<int, float> grafitoHash;

	int N,init,end;
	float peso;

	for (int i = 2; i <= 7; ++i)
	{
		N = pow(10, i);

		//1-insertar vertices
		for (int j = 0; j < N; ++i)
		{
			grafitoAdy.insertVertex(j);
			grafitoHash.insertVertex(j);
		}

		//2-insertar aristas en ambos grafos
		for (int j = 0; j < N; ++i)
		{
			init = generarInt(0, N-1);//genera numero aleatorio
			end = generarInt(0, N-1, init);//genera numero aleatorio diferente de init
			peso = generarFloat(1, 100);//generar numero decimal aleatorio
			grafitoAdy.createEdge(init, end, peso);
			grafitoHash.createEdge(init, end, peso);
		}
		ASSERT(grafitoAdy.density() == grafitoHash.density(), "Los grafos no son iguales");

		//3- ejecutar una operacion y capturar los tiempos	
		Graph<int, float> result1 = testOperation(&grafitoAdy);
		Graph<int, float> result2 = testOperation(&grafitoHash);
		ASSERT(comparar_grafos(&result1, &result2) == true, "El resultado no es igual");

		//4- limpiar grafo
		grafitoAdy.clear();
		grafitoHash.clear(); 
	}
}
