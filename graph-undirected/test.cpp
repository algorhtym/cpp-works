// Kemal Kilic 300143720
// Yasemin Eroltu 300111834

#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"

using namespace std;

int main () {
    cout << "sdfs11\n";
    Graph a(5);

    cout << "a(1,2):\n";
    cout << a(1,2) << endl;
   
    cout << "after adding edge (1,2): \n" << endl;
    a.add_edge(1,2);
    a.add_edge(3,4);
    a.add_edge(2,4);
    a.add_edge(5,1);
    //cout << a(1,1) << endl;
    cout << "a(1,2):\n";
    cout << a(1,2) << endl;
    //cout << a(1,3) << endl;
    cout << "a(2,1):\n";
    cout << a(2,1) << endl;

    cout << "\ntesting edge_exists:\n";
    bool tst_edge_exists1 = a.edge_exist(1,2);
    bool tst_edge_exists2 = a.edge_exist(2,1);
    if (tst_edge_exists1){
        cout << "a(1,2) exists\n";
    } else {
        cout << "a(1,2) doesn't exist\n";
    }

    if (tst_edge_exists2){
        cout << "a(2,1) exists\n";
    } else {
        cout << "a(2,1) doesn't exist\n";
    }

    cout << endl << endl;
    cout << "testing get_degree(1): " << a.get_degree(1) << endl;
    cout << "testing get_degree(2): " << a.get_degree(2) << endl;
    cout << "testing get_degree(3): " << a.get_degree(3) << endl;
    cout << "testing get_degree(4): " << a.get_degree(4) << endl;
    cout << "testing get_degree(5): " << a.get_degree(5) << endl;

    cout << a << endl;

    cout << endl << endl;
    cout << "testing ++ : \n\n lalaalal\n";

    cout << endl;
    
    a++;
    cout << a;
    // ++a;
    // cout << a;

    cout << "\n\ntesting --: \n";
    //a++;

    a.add_edge(1,6);
    a.add_edge(3,6);
    cout << a << endl;
    a--;
    cout << a;
    // ++a;
    // cout << a;




    cout << endl << endl;
    cout << "Now testing removing:\n";

    a.remove_edge(1,2);
    cout << "a(1,2):\n";
    cout << a(1,2) << endl;
    cout << "a(2,1):\n";
    cout << a(2,1) << endl;
    cout << "a(3,1):\n";
    cout << a(3,1) << endl;
    /*
    int i, j;
	
	int size = 0;
	int capacity = 10;

    vector<DoubleLinkedList*> vertices;

    for (i = 0; i < capacity; i++) {
        cout << "bruh\n";
        DoubleLinkedList* edge = new DoubleLinkedList;
        edge->add_to_back(i+1);
        for (j = 0; j < capacity; j++) {
            edge->add_to_back(0);
            cout << "j" << j << endl;
        }
        cout << "i" << i << endl;
        vertices.push_back(edge);
        cout << "vertices[i][0]:  "<< vertices[i][0] << endl;
        cout << "added vertice: " << i + 1 << endl;
        size++;
    }

    typename vector<DoubleLinkedList*>::iterator it = vertices.begin();
    

	while (it != vertices.end()) {
        cout << (*it)[0][0];
        cout << endl;
        it++;
    }

    */
     
    Graph g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    //g.add_edge(2, 0);
    g.add_edge(3, 4);
    g.add_edge(4, 4);

    cout << g << endl;

    //cout << "DFS: for vertex 2: \n";

   // g.DFS(2);

    //cout << "\n\nDFS: for vertex 2: \n";

    //g.BFS(2);
    

    return 0;
}