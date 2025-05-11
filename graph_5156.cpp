#include <iostream>
using namespace std;

int main(){
	int jumlah_vertex, jumlah_edge, sumber, tujuan, i, j;
	bool nolsemua, ketemu;
	
	cout << "Jumlah vertex: ";
	cin >> jumlah_vertex;
	cout << "Jumlah edge: ";
	cin >> jumlah_edge;
	
	int matrix[jumlah_vertex][jumlah_vertex];
	
	for(int i = 1; i <= jumlah_vertex; i++){
		for(int j = 1; j <= jumlah_vertex; j++){
			matrix[i][j] = 0;
		}	
	}	
	
	for(int i = 1; i <= jumlah_edge; i++){
		cout << "Vertex sumber: ";
		cin >> sumber;
		cout << "Vertex tujuan: ";
		cin >> tujuan;
		matrix[sumber][tujuan] = 1;
		matrix[tujuan][sumber] = 1;
	}
	
	i = 1;
	nolsemua = false;
	while(i <= jumlah_vertex && nolsemua == false){
		j = 1;
		ketemu = false;
		while(j <= jumlah_vertex && ketemu == false){
			if(matrix[i][j] == 1){
				ketemu = true;
			}else{
				j++;
			}
		}
		if (ketemu == false){
			nolsemua = true;
		}else{
			i++;
		}
	}
	
	if(nolsemua == true){
		cout << "Graph tidak terhubung";
	}else{
		cout << "Graph terhubung" << endl;
		
		bool directed = true;
		bool weighted = false;
		
		for(int i = 1; i <= jumlah_vertex; i++){
			for(int j = 1; j <= jumlah_vertex; j++){
				if(matrix[i][j] != matrix[j][i]){
					directed = false;
					break;
				}
			}
		}
		
		if(directed){
			cout << "Jenis Graf: Directed Graph (Digraph)" << endl;
		}else if(weighted){
			cout << "Jenis Graf: Weighted Graph" << endl;
		}else{
			cout << "Jenis Graf: Undirected Graph (Undigraph)" << endl;
		}
	}
	return 0;
}