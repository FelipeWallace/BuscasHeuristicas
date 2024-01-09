#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <map>

using namespace std;

bool busca(list<string> lista, string item){
  list<string> aux = lista;
  while(!aux.empty()){
    if(item == aux.front()){
      return true;
    }
    else 
      aux.pop_front();
  }
  return false;
}

int main() {

  struct vizinhos{
    string cidade;
    int dist;
  };

  string inicio, fim;
  map<string, int> distBucharest;
  map<string, list<vizinhos>> mapa;
  list<string> percorridos;
  vizinhos aux;

  inicio = "Oradea";
  fim = "Bucharest";

  // mapa que associa cada cidade a uma lista de cidades vizinhas
  // Arad
  aux.cidade = "Zerind";
  aux.dist = 75;
  mapa["Arad"].push_back(aux);

  aux.cidade = "Sibiu";
  aux.dist = 140;
  mapa["Arad"].push_back(aux);

  aux.cidade = "Timisoara";
  aux.dist = 118;
  mapa["Arad"].push_back(aux);

  // Zerind
  aux.cidade = "Arad";
  aux.dist = 75;
  mapa["Zerind"].push_back(aux);

  aux.cidade = "Oradea";
  aux.dist = 71;
  mapa["Zerind"].push_back(aux);

  // Oradea
  aux.cidade = "Zerind";
  aux.dist = 71;
  mapa["Oradea"].push_back(aux);

  aux.cidade = "Sibiu";
  aux.dist = 151;
  mapa["Oradea"].push_back(aux);

  // Sibiu
  aux.cidade = "Arad";
  aux.dist = 140;
  mapa["Sibiu"].push_back(aux);

  aux.cidade = "Oradea";
  aux.dist = 151;
  mapa["Sibiu"].push_back(aux);

  aux.cidade = "Fagaras";
  aux.dist = 99;
  mapa["Sibiu"].push_back(aux);

  aux.cidade = "Rimnicu";
  aux.dist = 80;
  mapa["Sibiu"].push_back(aux);

  // Timisoara
  aux.cidade = "Arad";
  aux.dist = 118;
  mapa["Timisoara"].push_back(aux);

  aux.cidade = "Lugoj";
  aux.dist = 111;
  mapa["Timisoara"].push_back(aux);

  // Lugoj
  aux.cidade = "Timisoara";
  aux.dist = 111;
  mapa["Lugoj"].push_back(aux);

  aux.cidade = "Mehadia";
  aux.dist = 70;
  mapa["Lugoj"].push_back(aux);

  // Mehadia
  aux.cidade = "Lugoj";
  aux.dist = 70;
  mapa["Mehadia"].push_back(aux);

  aux.cidade = "Drobeta";
  aux.dist = 75;
  mapa["Mehadia"].push_back(aux);

  // Drobeta
  aux.cidade = "Mehadia";
  aux.dist = 75;
  mapa["Drobeta"].push_back(aux);

  aux.cidade = "Craiova";
  aux.dist = 120;
  mapa["Drobeta"].push_back(aux);

  // Craiova
  aux.cidade = "Drobeta";
  aux.dist = 120;
  mapa["Craiova"].push_back(aux);

  aux.cidade = "Rimnicu";
  aux.dist = 146;
  mapa["Craiova"].push_back(aux);

  aux.cidade = "Pitesti";
  aux.dist = 138;
  mapa["Craiova"].push_back(aux);

  // Rimnicu
  aux.cidade = "Sibiu";
  aux.dist = 140;
  mapa["Rimnicu"].push_back(aux);

  aux.cidade = "Craiova";
  aux.dist = 146;
  mapa["Rimnicu"].push_back(aux);

  aux.cidade = "Pitesti";
  aux.dist = 97;
  mapa["Rimnicu"].push_back(aux);

  // Fagaras
  aux.cidade = "Sibiu";
  aux.dist = 99;
  mapa["Fagaras"].push_back(aux);

  aux.cidade = "Bucharest";
  aux.dist = 211;
  mapa["Fagaras"].push_back(aux);

  // Pitesti
  aux.cidade = "Bucharest";
  aux.dist = 101;
  mapa["Pitesti"].push_back(aux);

  aux.cidade = "Rimnicu";
  aux.dist = 97;
  mapa["Pitesti"].push_back(aux);

  aux.cidade = "Craiova";
  aux.dist = 138;
  mapa["Pitesti"].push_back(aux);

  // Bucharest
  aux.cidade = "Fagaras";
  aux.dist = 211;
  mapa["Bucharest"].push_back(aux);

  aux.cidade = "Pitesti";
  aux.dist = 101;
  mapa["Bucharest"].push_back(aux);

  aux.cidade = "Giurgiu";
  aux.dist = 90;
  mapa["Bucharest"].push_back(aux);

  aux.cidade = "Urziceni";
  aux.dist = 85;
  mapa["Bucharest"].push_back(aux);

  // Girgiu
  aux.cidade = "Bucharest";
  aux.dist = 90;
  mapa["Giurgiu"].push_back(aux);

  // Urziceni
  aux.cidade = "Bucharest";
  aux.dist = 85;
  mapa["Urziceni"].push_back(aux);

  aux.cidade = "Vaslui";
  aux.dist = 142;
  mapa["Urziceni"].push_back(aux);

  aux.cidade = "Hirsova";
  aux.dist = 98;
  mapa["Urziceni"].push_back(aux);

  // Hirsova
  aux.cidade = "Urziceni";
  aux.dist = 98;
  mapa["Hirsova"].push_back(aux);

  aux.cidade = "Eforie";
  aux.dist = 86;
  mapa["Hirsova"].push_back(aux);

  // Eforie
  aux.cidade = "Hirsova";
  aux.dist = 86;
  mapa["Eforie"].push_back(aux);

  // Vaslui
  aux.cidade = "Iasi";
  aux.dist = 92;
  mapa["Vaslui"].push_back(aux);

  aux.cidade = "Urziceni";
  aux.dist = 142;
  mapa["Vaslui"].push_back(aux);

  // Iasi
  aux.cidade = "Vaslui";
  aux.dist = 92;
  mapa["Iasi"].push_back(aux);

  // Neamt
  aux.cidade = "Iasi";
  aux.dist = 87;
  mapa["Neamt"].push_back(aux);

  // mapa que associa a distância de cada cidade até Bucharest 
  distBucharest["Arad"] = 366;
  distBucharest["Bucharest"] = 0;
  distBucharest["Craiova"] = 160 ;
  distBucharest["Drobeta"] = 242;
  distBucharest["Eforie"] = 161;
  distBucharest["Fagaras"] = 176;
  distBucharest["Giurgiu"] = 77;
  distBucharest["Hirsova"] = 151;
  distBucharest["Iasi"] = 226;
  distBucharest["Lugoj"] = 244;
  distBucharest["Mehadia"] = 241;
  distBucharest["Neamt"] = 234;
  distBucharest["Oradea"] = 380;
  distBucharest["Pitesti"] = 100;
  distBucharest["Rimnicu"] = 193;
  distBucharest["Sibiu"] = 253;
  distBucharest["Timisoara"] = 329;
  distBucharest["Urziceni"] = 80;
  distBucharest["Vaslui"] = 199;
  distBucharest["Zerind"] = 373;

  string percorrido;
  int distTotal = 0, dist = 0;
  percorridos.push_back(inicio);
  
  while(inicio != fim){
  
    int menorDistBucharest = INT_MAX;
    int distancia = 0;
    int tam = mapa[inicio].size();
    
    percorrido = mapa[inicio].front().cidade;
    dist = mapa[inicio].front().dist;
    
    for(int i = 0; (i < tam) && !(mapa[inicio].empty()); i++) {
      
      distancia = (distBucharest[mapa[inicio].front().cidade] + mapa[inicio].front().dist);

      if((distancia < menorDistBucharest) && !(busca(percorridos, mapa[inicio].front().cidade))){
        menorDistBucharest = distancia;
        percorrido = mapa[inicio].front().cidade;
        dist = mapa[inicio].front().dist;
      }
      mapa[inicio].pop_front();
    }
    percorridos.push_back(percorrido);
    inicio = percorrido;
    distTotal += dist; 
  }
  
  // impressão dos resultados
  cout <<"Percurso: ";
  while(!percorridos.empty()){
    if(percorridos.size() == 1){
      cout << percorridos.front() << endl;
      percorridos.pop_front();
    }
    else{
      cout << percorridos.front() << " -> ";
      percorridos.pop_front();
    }
  }
  cout << "Distâcia: " << distTotal << " milhas" << endl;
  
  return 0;
}
