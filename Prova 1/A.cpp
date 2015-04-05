#include <iostream>
#include <utility> 
#include <vector>

using namespace std;

int contem(int num, vector<int> aux){
	for(int i = 0; i < aux.size(); i++){
		if(num == aux[i]) return 1;
	}
	return 0;
}

vector <int> difAll(vector <int> aux, vector< pair <string, vector<int> > > cities){
	for(int i = 0; i < cities.size(); i++){
		for(int j = 0; j < cities[i].second.size(); j++){
			if(contem(cities[i].second[j], aux)){
				//aux.erase(aux.begin() + j);
			}
		}
	}
}

vector <int> searchMaps(string city, vector< pair <string, vector<int> > > cities, vector <int> aux){
	int aux2;
	for(int i = 0; i < cities.size(); i++){
		cout << cities[i].first << endl;
		if(cities[i].first == city){
			for(int j = 0; j < cities[i].second.size(); j++){
				if(!contem(cities[i].second[j], aux)){
					aux.push_back(cities[i].second[j]);
				}
			}
			aux2 = i;
		}
	}
	return aux;
}

int main(){
	string cityA, cityE;
	int num, aux2;

	vector< pair <string, vector<int> > > cities;
	pair <string, vector<int> > city;
	vector <int> aux;

	while(1){
		cin >> cityA;
		if(cityA != "ELIMINA"){
			cin >> num;
			while(num){
				cin >> aux2;
				aux.push_back(aux2);
				num--;
			}
			city = make_pair(cityA, aux);
			cities.push_back(city);
			aux.clear();	
		}else{
			while(cin >> cityE){
				aux = searchMaps(cityE, cities, aux); //Adiciona os mapas a aux e elimina a cidade do vetor 
				/*for(int i = 0; i < cities.size(); i++){
					if(cities[i].first == cityE){
						cities.erase(cities.begin() + i);
						break;
					}
				}*/
				aux = difAll(aux, cities); //subtração de conjunto entre aux e os mapas não excluidos do vetor
			}
			if(!aux.empty()){
				for(int i = 0; i < aux.size(); i++){
					cout << aux[i] << " ";
				}
			}else cout << "NENHUM";
		}
	}
}