#include "graph.h"
#include <iostream>

Vertex::Vertex(int n)
{
    id = n;
}

bool Vertex::add_neighbor(Vertex& v, int distance)
{
    // check if the neighbor is already in the list
    for (std::vector<Neighbor>::iterator neighbor_itr = adj_list.begin(); 
        neighbor_itr != adj_list.end(); ++neighbor_itr)
    {
        if(*neighbor_itr == v)
            return false;
    }

    Neighbor *n = new Neighbor( v, distance);
    adj_list.push_back(*n);

    return true;
}

void Vertex::print_neighbors()
{
    std::cout << "\tNeighbors: ";
    for (std::vector<Neighbor>::iterator neighbor_itr = adj_list.begin(); 
        neighbor_itr != adj_list.end(); ++neighbor_itr)
    {
        std::cout << "(" << neighbor_itr->get_id() << "," 
            << neighbor_itr->get_distance() << "), ";
    }
    std::cout << std::endl;
}

Neighbor::Neighbor(Vertex& v, int d)
{
    destination = v.get_id();
    distance = d;
}

Graph::Graph()
{
    n_vertices = 0;
    n_edges = 0;
}

bool Graph::add_vertex(Vertex& v)
{
    //do not allow insertion of repeated Vertices
    for (std::vector<Vertex>::iterator vecItr = vertices_list.begin(); 
        vecItr != vertices_list.end(); ++vecItr)
    {
        if(*vecItr == v)
            return false;
    }

    vertices_list.push_back(v);
    n_vertices++;
    return true;
}


bool Graph::add_edge(Vertex& src, Vertex& dest, int distance)
{
    std::vector<Vertex>::iterator vec_itr;
    
    //find the source Vertex in the list
    for (vec_itr = vertices_list.begin(); 
        vec_itr != vertices_list.end(); ++vec_itr)
    {
        if(*vec_itr == src)
            break;
    }
    
    // found the source Vertex. Now add the the destination
    // to the list of adjacent vertices
   
    if(!(*vec_itr).add_neighbor(dest, distance))
        return false;

    n_edges++;
    return true;
}


void Graph::print_vertices()
{
    for (std::vector<Vertex>::iterator vec_itr = vertices_list.begin(); 
        vec_itr != vertices_list.end(); ++vec_itr)
    {
        std::cout << "Vertex: " << vec_itr->get_id() << std::endl;
        vec_itr->print_neighbors();
    }

}
