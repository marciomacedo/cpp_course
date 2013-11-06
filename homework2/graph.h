#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Neighbor;

class Vertex {
    private:
        int id;
        std::vector <Neighbor> adj_list;

    public:
        Vertex(int n);
        bool add_neighbor(Vertex& v, int distance);
        void print_neighbors();

        inline int get_id() 
        {
            return id;
        }

        inline bool operator== (Vertex& v2)
        {
            if(id == v2.id)
                return true;
            return false;
        }
};

class Neighbor {
    private:
        //Vertex& destination; //I had strange template problems when tryed this. Decided to workaround
        int destination;
        unsigned int distance;
    public:
        Neighbor(Vertex& v, int d);

    inline int get_id(){
        return destination;
    }
    
    inline int get_distance(){
        return distance;
    }

    inline bool operator== (Vertex& v2)
        {
            if(destination == v2.get_id())
                return true;
            return false;
        }

};

class Graph {
    private:
        int n_vertices;
        int n_edges;
        std::vector <Vertex> vertices_list;

    public:
        Graph(); // Constructor
        
        bool add_vertex (Vertex& v);
        bool add_edge(Vertex& src, Vertex& dest, int distance);
        void print_vertices();
    /*
        int count_vertices ();
        int count_edges ();
        bool adjacent (Vertex& v1, Vertex& v2);
        vector <Vertex> neighbors(Vertex& v);
        bool add_edge (Vertex& v1, Vertex& v2);
        bool remove_vertex (Vertex &v);
        bool remove_edge (Edge& edge);
   */
};

//inline bool operator== (Vertex& v1, Vertex& v2);

#endif
