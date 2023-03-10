// Kemal Kilic 300143720
// Yasemin Eroltu 300111834

#include <iostream>
#include "Graph.h"
#include "DoubleLinkedList.h"
#include<list>

using namespace std;


ostream& operator<<(ostream& out , Graph& g) {
    
	typename vector<DoubleLinkedList*>::iterator it = g.vertices.begin();
    int i;
    out << "V = {";
    while(it != g.vertices.end()) {
        if (it != g.vertices.begin()) {
			out << ", ";
		}
        
        out << (*it)[0][0];
        it++;
    }

    out << "}";
    out << endl << "E =" << endl << "{" << endl;

    typename vector<DoubleLinkedList*>::iterator it2 = g.vertices.begin();
    it2 = g.vertices.begin();    

	while (it2 != g.vertices.end()) {
		int v = (*it2)[0][0];
		out << "\t" << v << " => ";
        int tmp = 0;
        for (i = 0; i < g.capacity; i++) {
            if(g.get_degree(v) == 0) {
                out << "None";
                break;
            }

            if (g(v,i+1)) {
                if(tmp != 0) {
                    out << ", ";
                }
                out << i+1;
                tmp++;
            }
            
        }
		out << endl;
		++it2;
	}

	out << "}";

	return out;
}

Graph::Graph() {

	int i, j;
	
	size = 0;
	capacity = DEF_ELEM;
    vertices.reserve(MAX_ELEM);

	//vertices = new DoubleLinkedList<DoubleLinkedList<int>>;
    
    for (i = 0; i < capacity; i++) {
        //cout << "bruh\n";
        DoubleLinkedList* edge = new DoubleLinkedList;
        edge->add_to_back(i+1);
        for (j = 0; j < capacity; j++) {
            edge->add_to_back(0);
            //cout << "j" << j << "\n";
        }
       // cout << "i" << i << "\n";
        vertices.push_back(edge);

        cout << "added vertice: " << i + 1 << endl;
    }
}

Graph::Graph(int s) {

	int i, j;

	size = 0;
	capacity = s;
    vertices.reserve(MAX_ELEM);
	
    for (i = 0; i < capacity; i++) {
        //cout << "bruh\n";
        DoubleLinkedList* edge = new DoubleLinkedList;
        edge->add_to_back(i+1);
        for (j = 0; j < capacity; j++) {
            edge->add_to_back(0);
        }
        //cout << "haha\n";
        vertices.push_back(edge);
        cout << "added vertice: " << i + 1 << endl;
    }
}

Graph::Graph(const Graph& g) {
	//int i;
	
    size = g.size;
    capacity = g.capacity;
    vertices = g.vertices;
}

Graph::~Graph()
{
    typename vector<DoubleLinkedList*>::iterator it = vertices.begin();
    
	while (it != vertices.end()) {
        for (int j = 0; j < size; j++)
		{
			(*it)[0][j] = 0;
		}
        it++;
    }
	
    //vertices->erase(vertices->begin(), vertices->end());
    vertices.clear();
}

bool Graph::add_edge_dir(int src, int dest)
{
	if (src > 0 && src <= capacity && dest > 0 && dest <= capacity)
	{
		//vertices[src][dest] = true;
        typename vector<DoubleLinkedList*>::iterator it = vertices.begin();
        int check = -1;
        //int i = 0;
	    while (it != vertices.end()) {
            //cout << "loop " << i << endl;
            check = (*it)[0][0];
            if (check == src) {
                break;
            }
            //i++;
            it++;
        }
        //cout << endl;
        if (it == vertices.end()) {
            return false;
        }

        (*it)[0][dest] = 1;
        return true;
	}
    else {
        cout << "index out of range!\n";
        return false;
    }
}

void Graph::add_edge(int src, int dest) {
    bool first = false;
    bool second = false;
    first = add_edge_dir(src, dest);
    second = add_edge_dir(dest, src);
    if (!first) {
        cout << "Could not add first!\n";
    } else {
        size++;
    }

    if (!second) {
        cout << "Could not add second!\n";
    } else {
        size++;
    }
}

bool Graph::remove_edge_dir(int src, int dest)
{
	if (src > 0 && src <= capacity && dest > 0 && dest <= capacity)
	{
		//vertices[src][dest] = true;
        typename vector<DoubleLinkedList*>::iterator it = vertices.begin();
        int check = -1;

	    while (it != vertices.end()) {
            check = (*it)[0][0];
            if (check == src) {
                break;
            }
            it++;
        }
        if (it == vertices.end()) {
            return false;
        }

        (*it)[0][dest] = false;
        return true;
	}
    else {
        return false;
    }
}

void Graph::remove_edge(int src, int dest)
{
	
    bool first = false;
    bool second = false;
    first = remove_edge_dir(src, dest);
    second = remove_edge_dir(dest, src);

    if (!first) {
        cout << "Could not remove first!\n";
    } else {
        size--;
    }

    if (!second) {
        cout << "Could not remove second!\n";
    } else {
        size--;
    }

}


bool Graph::edge_exist(int src, int dest)
{
	if (src > 0 && src <= capacity && dest > 0 && dest <= capacity)
	{
		bool isAnEdge = false;
		isAnEdge = (*this)(src,dest);
		return isAnEdge;
	} else {
        return false;
    }
}

int Graph::get_degree(int src) {
    int i, count = 0;
    if (src > 0 && src <= capacity) {
        for(i = 0; i < capacity; i++) {
            if(edge_exist(src, i+1)){
                count++;
            }
        }
        return count;
    } else {
        // cout << "vertex doesn't exist!\n";
        return -1;
    }
}

bool Graph::path_exist(int src, int dest) {
    if (src > 0 && src <= capacity) {

    }
    return true; //temp
}

void Graph::BFS(int src){
    
    vector<bool> visited;
    visited.resize(capacity, false);

    list<int> queue;
    visited[src] = true;
    queue.push_back(src);
    int temp;
    while (!queue.empty()) {
        temp = queue.front();
        cout << temp << " ";
        queue.pop_front();

        for (int i = 1; i <= capacity; i++) {
            if ((*this)(src,i)) {
                if(!visited[i]) {
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
    
    }

}

void Graph::DFS(int src) {
    vector<bool>* visited;
    visited->resize(capacity, true);
    //visited[0][src] = true;
    //cout << src << " ";
    dfs_recur(src, visited);

}

void Graph::dfs_recur(int v, vector<bool> *visited){
    visited[0][v] = true;
    cout << v << " ";
    int i;

    for (i = 1; i <= capacity; i++) {
        if ((*this)(v,i)) {
            if(!visited[0][i]) {
                dfs_recur(i,visited);
            }
        }
    }

}

Graph Graph::operator++ () {

    vector<DoubleLinkedList*> temp;

    temp.reserve(MAX_ELEM);


    int i, check, k, m;
    
    
    typename vector<DoubleLinkedList*>::iterator iter;
    for (iter = vertices.begin(); iter != vertices.end(); iter++) {
        k = (*iter)[0][0];
        DoubleLinkedList* edge = new DoubleLinkedList;
        edge->add_to_back(k);
        for (m = 1; m <= capacity; m++) {
            edge->add_to_back((*this)(k,m));
        }
        edge->add_to_back(0);
        temp.push_back(edge);
        k++;
    }

    capacity++;
    DoubleLinkedList* edge = new DoubleLinkedList;
    edge->add_to_back(capacity);
    for (i = 0; i < capacity; i++) {
        edge->add_to_back(0);
        //cout << "j" << j << "\n";
    }
    // cout << "i" << i << "\n";
    temp.push_back(edge);
    
    vertices.clear();
    vertices = temp;

    return (*this);
}

Graph Graph::operator++ (int) {
    Graph result = *this;
    vector<DoubleLinkedList*> temp;

    temp.reserve(MAX_ELEM);


    int i, check, k, m;
    
    
    typename vector<DoubleLinkedList*>::iterator iter;
    for (iter = vertices.begin(); iter != vertices.end(); iter++) {
        k = (*iter)[0][0];
        DoubleLinkedList* edge = new DoubleLinkedList;
        edge->add_to_back(k);
        for (m = 1; m <= capacity; m++) {
            edge->add_to_back((*this)(k,m));
        }
        edge->add_to_back(0);
        temp.push_back(edge);
        k++;
    }

    capacity++;
    DoubleLinkedList* edge = new DoubleLinkedList;
    edge->add_to_back(capacity);
    for (i = 0; i < capacity; i++) {
        edge->add_to_back(0);
        //cout << "j" << j << "\n";
    }
    // cout << "i" << i << "\n";
    temp.push_back(edge);
    
    vertices.clear();
    vertices = temp;
    
 
    return result;
}

Graph Graph::operator-- () {

    int i, j;
    for (i = 1; i <= capacity; i++) {
        if (edge_exist(capacity,i)) {
            remove_edge(capacity,i);
        }
    }
    if (get_degree(capacity) != 0) {
        cout << "Unsuccessful decrement operation!\n";
    }
    //vertices.pop_back();
    capacity--;

    return (*this);
}

Graph Graph::operator-- (int x) {
    Graph result = *this;

    int i, j;
    for (i = 1; i <= capacity; i++) {
        if (edge_exist(capacity,i)) {
            remove_edge(capacity,i);
        }
    }
    if (get_degree(capacity) != 0) {
        cout << "Unsuccessful decrement operation!\n";
    }
    //vertices.pop_back();
    capacity--;

    return result;
}


int Graph::operator() (int src, int dest) {
    // cout << "Start Indexing\n";
    typename vector<DoubleLinkedList*>::iterator it = vertices.begin();
    int check;

    while (it != vertices.end()) {
        check = (*it)[0][0];
        if (check == src) {
            //cout << (*it)[0] << endl;
            break;
        }
        it++;
    }
    if (it == vertices.end()) {
        cout << "Index not found!\n";
        return -1;
    }
     
    return (*it)[0][dest];
}
