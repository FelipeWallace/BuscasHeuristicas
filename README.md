# Implementação de buscas heurísticas

Este projeto descreve uma implementação de duas buscas heurísticas, incluindo um resumo sobre o problema a ser resolvindo, uma breve descrição da Busca Gulosa e A* e quais estruturas de dados foram usadas na implementação.


## Problema

Russell and Norvig [2010] propuseram um problema de otimização de rota que pode ser solucionado utilizando buscas heurísticas. O problema consiste em encontrar a rota mais curta entre duas cidades na Romênia, representadas por um grafo onde cada vértice é uma cidade e cada aresta tem a distância em milhas entre as cidades. Para solucionar o problema, é utilizada uma heurística que estima a distância em linha reta entre a cidade atual e a cidade de destino. Para isso, foram fornecidas informações sobre as distâncias em linha reta entre cada cidade e a cidade de Bucharest. O algoritmo de busca gulosa utiliza apenas a heurística de distância estimada em linha reta, enquanto o algoritmo A* utiliza a heurística de distância estimada em linha reta somada à distância local.

![Romenia_dist](https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/315054d5-8c01-4b4f-9749-e0bbaecb00ed)
![DistBucharest](https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/a26f3ace-b316-4df7-9dbc-238ce6e00fb0)
<!-- \begin{figure}[H]
\centering
\includegraphics[width=7cm]{Images/Romenia_dist.png}
\caption{\label{fig4}Mapa simplificado de uma reigão da Romênia, com a distância rodoviárias em milhas. Fonte: Russell and Norvig [2010]} 
\end{figure}

\begin{figure}[H]
\centering
\includegraphics[width=7cm]{Images/DistBucharest.png}
\caption{\label{fig5}Lista de cidades com a distância estimada em linha reta até \textit{Bucharest}. Fonte: Russell and Norvig [2010]} 
\end{figure} -->

## Busca Gulosa

Para implementar o algoritmo de busca gulosa, em C++, utilizamos duas estruturas de dados: o mapa\cite{geeksforgeeks} e a lista. O mapa é uma estrutura que associa um valor a uma chave, enquanto a lista é uma sequência de elementos do mesmo tipo. Para modelar o grafo, criamos uma estrutura chamada "vizinhos", que contém a cidade vizinha e a distância até essa cidade. Em seguida, criamos um mapa que associa cada cidade a uma lista de vizinhos. Por fim, criamos uma lista para armazenar as cidades já percorridas no caminho. Essa lista é necessária para guardar o todo o percurso e será impressa no final da execução do código.

<!-- \small\lstinputlisting[language=C++, firstline=9 , lastline=21,  label = Exe01, caption = Estruturas e variáveis.]{Code/Busca_Gulosa.cpp} -->

Para implementar o algoritmo de caminho mais curto, utilizamos o a lógica explicada na subseção \textit{Problema}. Esse algoritmo começa pelo vértice de origem e caminha para um dos vértices adjacentes a ele, sempre considerando como refrência a distância da próxima cidade para Bucharest. Em seguida, ele armazena a cidade visitada na lista de "percorridos" e repete o processo até que a cidade de destino seja alcançada. No nosso exemplo, a cidade de origem é "Arad" e a cidade de destino é sempre "Bucharest". O algoritmo começa guardando a distância (aresta) de Arad até a cidade vizinha mais próxima de Bucharest e faz isso com todas até o final da execução, momento onde a distância percorrida pela rota será apresentada para o usuário.

<!-- \small\lstinputlisting[language=C++, firstline=246 , lastline=268,  label = Exe02, caption = Laço principal da Busca Gulosa., breaklines=true, linewidth=0.45\textwidth]{Code/Busca_Gulosa.cpp} -->

## Busca A*

A principal mudança do algoritmo A* em relação a busca gulosa é o critério para escolher a próxima cidade (vértice), desta vez além da distância em linha reta para Bucharest, também é considerada a distância local (aresta) entre as cidades, desta forma a próxima cidade a ser visitada é sempre a que tiver a menor distância somada destes dois valores. Este algoritmo é capaz de gerar percursos menores, entretanto alguns cuidados devem ser tomados, por exemplo a possibilidade da melhor escolha ser uma cidade já visitada. Para corrigir isso, foi adicionado ao código uma função de busca que faz uso da lista "percorridos" onde estão listadas todas as cidades já visitadas, caso a busca retorne verdadeiro a cidade em questão será desconsiderada.

<!-- \small\lstinputlisting[language=C++, firstline=8 , lastline=18,  label = Exe03, caption = Função de busca na lista de percorridos., breaklines=true, linewidth=0.45\textwidth]{Code/A_estrela.cpp}

\small\lstinputlisting[language=C++, firstline=259 , lastline=286,  label = Exe03, caption = Laço principal da Busca A*., breaklines=true, linewidth=0.45\textwidth]{Code/A_estrela.cpp} -->

## Resultados

Pode-se verificar nos testes realizados que, o algoritmo A* se sobressai em cidades nas quais possuem mais de uma rota possível até \textit{Bucharest}.

![Zerind-Bucharest](https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/8e7ad82b-da57-4536-b66c-ae802d156661)
<!-- \begin{figure}[H]
\centering
\includegraphics[width=7cm]{Images/Zerind-Bucharest.png}
\caption{\label{fig6}Melhores rotas encontradas pelos dois algoritmos de busca a Gulosa (em azul) e A* (em vermelho) de \textit{Zerind} até \textit{Bucharest}. Fonte: Russell and Norvig [2010] \textit{Obs:} As rotas em destaque foram confeccionadas através de um software edição.} 
\end{figure} -->

Como podemos observar na Figura \ref{fig6}, a melhor rota de \textit{Zerind} até \textit{Bucharest} foi obtida do algoritmo A*, que retornou uma distância de $493$ \textit{milhas}, contra $525$ \textit{milhas} da busca gulosa. A diferença na resposta se dá quando ambos algoritmos "passam" pela cidade de \textit{Sibiu}, pois nessa cidade o algoritmo "guloso" opta por ir para \textbf{Fagaras} que está mais perto de \textbf{Bucharest}, porém o trajeto de \textit{Sibiu} até ela é maior, enquanto o algoritmo A* decide ir por \textit{Rimnicu Vilcea}.

Entretanto, em cidades que possuem uma ou duas rotas (na qual há uma distância considerável entre elas) tanto a busca gulosa quanto a A* apresentam o mesmo resultado, como podemos observar na tabela \ref{tab2}.

![Timisoara-Bucharest](https://github.com/FelipeWallace/BuscasHeuristicas/assets/97401368/ff1d0668-4837-471b-a3b4-e5ca6d336f9a)
<!-- \begin{figure}[H]
\centering
\includegraphics[width=7cm]{Images/Timisoara-Bucharest.png}
\caption{\label{fig7}Melhores rotas encontradas pelos dois algoritmos de busca a Gulosa (em azul) e A* (em vermelho) de \textit{Timisoara} até \textit{Bucharest}. Fonte: Russell and Norvig [2010] \textit{Obs:} As rotas em destaque foram confeccionadas através de um software edição.} 
\end{figure} -->

Conforme ilustrado na figura \ref{fig7}, podemos notar que ambas as buscas resultaram na mesma resposta ($615$ \textit{milhas}). Essa situação se repetiu nas cidades \textit{Neamt}, \textit{Iasi}, \textit{Vaslui} e \textit{Hirsova}, pois estas cidades apresentam um único caminho até \textit{Bucharest}.

Com isso, podemos diz quer a busca a-estrela apresenta uma ligeira diferença em comparação com a busca gulosa, como podemos observar na tabela \ref{tab2}.

<!-- \begin{table}[H]
\label{tab:garesults}
\centering
\caption{Distância em milhas obtida da melhor rota de cada busca} \label{tab2} 
\begin{tabular}{@{}lccc@{}}
\toprule
\textbf{Cidade} & \textbf{Busca Gulosa} & \textbf{Busca A*} &\textbf{Menor rota possível} \\ 
\midrule
\textbf{Neamt}       &$406$      &$406$     &$406$\\
\textbf{Timisoara}   &$615$      &$615$     &$536$\\
\textbf{Fagaras}     &$211$      &$211$     &$211$\\
\textbf{Arad}        &$450$      &$418$     &$418$\\
\textbf{Oradea}      &$461$      &$429$     &$429$\\
\textbf{Zerind}      &$525$      &$493$     &$493$\\

\bottomrule
\end{tabular}
\begin{minipage}{\linewidth}
\vspace{5pt}
\end{minipage}
\end{table} -->

Porém, nas abordagens utilizadas nem sempre a solução encontrada será a menor possível. Pois quando a cidade inicial é \textit{Timisoara} as respostas das duas buscas não foram a melhor possível. Depois de realizar uma análise nas rotas a partir da cidade citada anteriormente, podemos observar que a rota ótima seria obtida indo para \textit{Arad} ao invés de \textit{Lugoj}, esse caminho teria um custo maior a princípio, entretando este trajeto seria mais curto até chegar a \textit{Bucharest}, pois a distância final seria igual a $536$ \textit{milhas}.
