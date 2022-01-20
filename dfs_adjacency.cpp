#include <iostream>
#include <vector>

using namespace std;

class graph_adjacency
{
private:
    int num_v;              // number of vertice
    int **matrix;           // incident matrix
    vector<bool>passed;     // to check if a vertex is passed

public:
    graph_adjacency(int);
    ~graph_adjacency();
    void add();             // get input to create the matrix
    void DFS(int start);    // print the vertices in DFS order
    void print();           // print the matrix
};

graph_adjacency::graph_adjacency(int Num_v){
    this->num_v  = Num_v;
    vector<bool> a(num_v,false);
    this->passed = a;

    this->matrix = new int*[num_v];
    for(int i = 0; i < num_v; i++)
    {
        matrix[i] = new int[num_v];
        for(int j = 0; j < num_v; j++){
            matrix[i][j] = 0;
        }
    }
};

graph_adjacency::~graph_adjacency(){
    for(int i = 0; i < this->num_v; i++){
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
};

void graph_adjacency::add(){
    cout <<  "Enter row by row :" << endl ;
    for(int i = 0; i < this->num_v; i++){
        for(int j = 0; j < this->num_v; j++){
            int a;
            cin >> a; this->matrix[i][j] = a;
        }
    }
};

void graph_adjacency::print(){
    cout << "The adjacency matrix :" << endl;
    for(int i = 0; i < this->num_v; i++){
        for(int j = 0; j < this->num_v; j++){
            if(j == 0) cout << this->matrix[i][j] << " ";
            else{
                if(j == this->num_v-1) cout << this->matrix[i][j] << endl;
                else cout << this->matrix[i][j] << " ";
            }
        }
    }
};

void graph_adjacency::DFS(int start){
    cout << "V" << start << " ";
    this->passed[start] = true;

    for(int i = 0; i < this->num_v; i++){
        if(this->matrix[start][i] == 1 && (!this->passed[i])){
            this->DFS(i);
        }
    }
};

int main(){
    int num_vertices;
    
    cout << endl << "Number of vertices :" << endl;
    cin >> num_vertices;
    graph_adjacency a(num_vertices);

    a.add();

    int c;
    cout << endl << "Starting vertex : "<< endl;
    cin >> c;

    cout << endl;
    a.print();
    cout << endl << "The DFS order :" << endl;
    a.DFS(c);
    cout << endl;
}

