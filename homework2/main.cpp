#include <iostream>
#include "graph.h"

int main(int argc, char **argv)
{
    Graph g1;
#if 0
    
    Vertex* v;
    
    for(int i = 0; i < 10; i++)
    {
        v = new Vertex(i);
        if(!g1.add_vertex(*v)) {
            std::cout << "problem inserting Vertex " 
                << v->get_id() << std::endl;
        }
    }
#endif

    Vertex v1(1);
    Vertex v2(2);
    Vertex v3(3);
    Vertex v4(4);
    Vertex v5(5);
    Vertex v6(6);
    
    g1.add_vertex(v1);
    g1.add_vertex(v2);
    g1.add_vertex(v3);
    g1.add_vertex(v4);
    g1.add_vertex(v5);
    g1.add_vertex(v6);
    
    g1.add_edge(v1,v2, 5);
    g1.add_edge(v1,v3, 6);
    g1.add_edge(v1,v4, 8);

    g1.add_edge(v2,v6, 3);
    g1.add_edge(v2,v5, 4);
    
    g1.add_edge(v6,v3, 7);
    
    g1.add_edge(v3,v4, 6);
    
    g1.add_edge(v5,v6, 4);
    g1.add_edge(v5,v4, 2);
    g1.add_edge(v5,v3, 8);
    g1.add_edge(v5,v2, 9);
    g1.add_edge(v5,v1, 1);


    g1.print_vertices();

   
    // try to add a vertex that already exists
    if(!g1.add_vertex(v2)) {
        std::cout << "problem inserting Vertex " 
            << v2.get_id() << std::endl;
    }

    // try to add a vertex that already exists
    if(!g1.add_vertex(v3)) {
        std::cout << "problem inserting Vertex " 
            << v3.get_id() << std::endl;
    }

    return 0;
}
