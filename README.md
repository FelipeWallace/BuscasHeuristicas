# Implementação de buscas heurísticas

Este projeto descreve uma implementação de duas buscas heurísticas, incluindo um resumo sobre o problema a ser resolvido, uma breve descrição da Busca Gulosa e A* e quais estruturas de dados foram usadas na implementação.


## Problema

Russell and Norvig [2010] propuseram um problema de otimização de rota que pode ser solucionado utilizando buscas heurísticas. O problema consiste em encontrar a rota mais curta entre duas cidades na Romênia, representadas por um grafo onde cada vértice é uma cidade e cada aresta tem a distância em milhas entre as cidades. Para solucionar o problema, é utilizada uma heurística que estima a distância em linha reta entre a cidade atual e a cidade de destino. Para isso, foram fornecidas informações sobre as distâncias em linha reta entre cada cidade e a cidade de Bucharest. O algoritmo de busca gulosa utiliza apenas a heurística de distância estimada em linha reta, enquanto o algoritmo A* utiliza a heurística de distância estimada em linha reta somada à distância local.

<div align="center">
   <img src="https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/315054d5-8c01-4b4f-9749-e0bbaecb00ed" style="width: 700px;">
</div>

<div align="center">
   <img src="https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/a26f3ace-b316-4df7-9dbc-238ce6e00fb0" style="width: 700px;">
</div>

## Busca Gulosa

Para implementar o algoritmo de busca gulosa, em C++, foram utilizadas duas estruturas de dados: o mapa e a lista. O mapa é uma estrutura que associa um valor a uma chave, enquanto a lista é uma sequência de elementos do mesmo tipo. Para modelar o grafo, criamos uma estrutura chamada "vizinhos", que contém a cidade vizinha e a distância até essa cidade. Em seguida, criamos um mapa que associa cada cidade a uma lista de vizinhos. Por fim, criamos uma lista para armazenar as cidades já percorridas no caminho. Essa lista é necessária para guardar o todo o percurso e será impressa no final da execução do código.

```
  struct vizinhos{
    string cidade;
    int dist;
  };

  string inicio, fim;
  vizinhos aux;
  map<string, int> distBucharest;
  map<string, list<vizinhos>> mapa;
  list<string> percorridos;

  inicio = "Arad";
  fim = "Bucharest";
```

Para implementar o algoritmo de caminho mais curto, foi utilizada a lógica explicada na subseção *Problema*. Esse algoritmo começa pelo vértice de origem e caminha para um dos vértices adjacentes a ele, sempre considerando como refrência a distância da próxima cidade para Bucharest. Em seguida, ele armazena a cidade visitada na lista de "percorridos" e repete o processo até que a cidade de destino seja alcançada. No nosso exemplo, a cidade de origem é "Arad" e a cidade de destino é sempre "Bucharest". O algoritmo começa guardando a distância (aresta) de Arad até a cidade vizinha mais próxima de Bucharest e faz isso com todas até o final da execução, momento onde a distância percorrida pela rota será apresentada para o usuário.

```
string percorrido;
  int distTotal = 0, dist = 0;
  percorridos.push_back(inicio);

  while(inicio != fim){

    int menorDistBucharest = distBucharest[mapa[inicio].front().cidade];
    percorrido = mapa[inicio].front().cidade;
    dist = mapa[inicio].front().dist;
    mapa[inicio].pop_front();
    
    while(!mapa[inicio].empty()){
      if(distBucharest[mapa[inicio].front().cidade] < menorDistBucharest){
        menorDistBucharest = distBucharest[mapa[inicio].front().cidade];
        percorrido = mapa[inicio].front().cidade;
        dist = mapa[inicio].front().dist;
      }
      mapa[inicio].pop_front();
    }
    percorridos.push_back(percorrido);
    inicio = percorrido;
    distTotal += dist; 
  }
```
## Busca A*

A principal mudança do algoritmo A* em relação a busca gulosa é o critério para escolher a próxima cidade (vértice), desta vez além da distância em linha reta para Bucharest, também é considerada a distância local (aresta) entre as cidades, desta forma a próxima cidade a ser visitada é sempre a que tiver a menor distância somada destes dois valores. Este algoritmo é capaz de gerar percursos menores, entretanto alguns cuidados devem ser tomados, por exemplo a possibilidade da melhor escolha ser uma cidade já visitada. Para corrigir isso, foi adicionado ao código uma função de busca que faz uso da lista "percorridos" onde estão listadas todas as cidades já visitadas, caso a busca retorne verdadeiro a cidade em questão será desconsiderada.

```
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
```

```
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
```
## Resultados

Pode-se verificar nos testes realizados que, o algoritmo A* se sobressai em cidades nas quais possuem mais de uma rota possível até *Bucharest*.

<div align="center">
   <img src="https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/8e7ad82b-da57-4536-b66c-ae802d156661" style="width: 700px;">
</div>

Como podemos observar na figura, a melhor rota de *Zerind* até *Bucharest* foi obtida do algoritmo A*, que retornou uma distância de 493 milhas, contra 525 milhas da busca gulosa. A diferença na resposta se dá quando ambos algoritmos "passam" pela cidade de *Sibiu*, pois nessa cidade o algoritmo "guloso" opta por ir para *Fagaras* que está mais próximo de **Bucharest**, porém o trajeto de *Sibiu* até ela é maior, enquanto o algoritmo A* decide ir por *Rimnicu Vilcea*.

Entretanto, em cidades que possuem uma ou duas rotas (na qual há uma distância considerável entre elas) tanto a busca gulosa quanto a A* apresentam o mesmo resultado, como poderemos observar posteriormente na tabela.

<div align="center">
   <img src="https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/ff1d0668-4837-471b-a3b4-e5ca6d336f9a" style="width: 700px;">
</div>

Conforme ilustrado na figura, podemos notar que ambas as buscas resultaram na mesma resposta (615 milhas). Essa situação se repetiu nas cidades *Neamt*, *Iasi*, *Vaslui* e *Hirsova*, pois estas cidades apresentam um único caminho até *Bucharest*.

Com isso, podemos diz quer a busca a-estrela apresenta uma ligeira diferença em comparação com a busca gulosa, como podemos observar na tabela.

| Cidade        | Busca Gulosa| Busca A*| Menor rota possível |
|---------------|-------------|---------|---------------------|
| Neamt         | 406         | 406     | 406                 |
| Timisoara     | 615         | 615     | 536                 |
| Fagaras       | 211         | 211     | 211                 |
| Arad          | 450         | 418     | 418                 |
| Oradea        | 461         | 429     | 429                 |
| Zerind        | 525         | 493     | 493                 |

Porém, nas abordagens utilizadas nem sempre a solução encontrada será a menor possível. Pois quando a cidade inicial é *Timisoara* as respostas das duas buscas não foram a melhor possível. Depois de realizar uma análise nas rotas a partir da cidade citada anteriormente, podemos observar que a rota ótima seria obtida indo para *Arad* ao invés de *Lugoj*, esse caminho teria um custo maior a princípio, entretando este trajeto seria mais curto até chegar a *Bucharest*, pois a distância final seria igual a 536 milhas.
