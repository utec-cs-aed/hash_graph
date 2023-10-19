#include <iostream>

template<typename TV, typename TE>
class Graph<TV, TE>{
	//TODO
};

template<typename TV, typename TE>
class ListGraph: public Graph<TV, TE>{
	//TODO
	//Hash<TV, list<pair<TV, TE>>> graph;
};

template<typename TV, typename TE>
class HashGraph: public Graph<TV, TE>{
	//TODO
	//Hash<TV, Hash<TV, TE>> graph;
};
