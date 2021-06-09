from Grafo import Grafo
import matplotlib.pyplot as plt
import networkx as nx
import sys

if __name__ == '__main__':

    grafo = Grafo()

    filename = sys.argv[1]

    try:
        with open(filename, 'r') as my_file:
            for linea in my_file:
                linea = linea.split(' ')
                grafo.agregar_nodo(linea)
    except:
        print('archivo no existe')
        sys.exit(0)

    grafo.set_colores()
    grafo.pintar_grafo()
    grafo.print_grafo()


    print('nodos', grafo.get_node_list())
    print('edges', grafo.get_edges_list())

    G = nx.Graph()

    nodelist = grafo.get_node_list()
    edgelist = grafo.get_edges_list()
    labels = grafo.get_labels()
    colores = grafo.get_colores()

    print('colores ', colores)
    print('nodelist', nodelist)

    G.add_nodes_from(nodelist)
    G.add_edges_from(edgelist)

    pos = nx.spring_layout(G)  # positions for all nodes

    # nodos
    nx.draw_networkx_nodes(G, pos, nodelist,
                           node_color=colores,
                           node_size=500,
                           alpha=0.4)
    # aristas
    nx.draw_networkx_edges(G, pos,
                           edgelist,
                           width=4, alpha=0.5, edge_color='r')

    #
    nx.draw_networkx_labels(G, pos, labels, font_size=16)

    plt.axis('off')
    plt.show()
