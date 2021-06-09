from Nodo import Nodo

colores = ['rojo', 'azul', 'verde', 'amarillo', 'café', 'negro', 'blanco', 'lila', 'amarillo', 'violeta', 'vino', 'gris','amarillo patito','rojo sangre','azul marino','verde pasto']

class Grafo:

    def __init__(self):
        self.vertices = 0
        self.nodos = {}
        self.colores = []

    def agregar_nodo(self, linea):
        label = linea[0]
        inicial = int(linea[1])
        final = int(linea[2])
        nodo = Nodo(label, inicial, final)

        adyacentes = self.get_adyacentes(nodo)

        for adyacente in adyacentes:
            self.nodos[adyacente].append(nodo)

        if not self.nodos.get(nodo, False):
            self.nodos[nodo] = []

        self.nodos[nodo] = list(set(self.nodos[nodo] + adyacentes))
        self.colores.append(len(self.colores))

    def set_colores(self):
        self.colores = colores[:len(self.nodos)]
        print(self.colores)

    def get_adyacentes(self, nuevo_nodo):
        adyacentes = []

        for nodo in self.nodos:
            if nodo.inicial < nuevo_nodo.inicial < nodo.final \
               or nodo.inicial < nuevo_nodo.inicial < nodo.final \
               or nuevo_nodo.inicial < nodo.inicial < nuevo_nodo.final \
               or nuevo_nodo.inicial < nodo.final < nuevo_nodo.final:
                adyacentes.append(nodo)

        return adyacentes

    def puedo_pintar_color(self, nodo, color):
        for adyacente in self.nodos.get(nodo):
            if adyacente.color == color:
                return False
        return True

    def get_color_nodo(self, nodo):
        for color in self.colores:
            if self.puedo_pintar_color(nodo, color):
                return color

    def pintar_grafo(self):
        for nodo in self.nodos:
            nodo.color = self.get_color_nodo(nodo)

    """
    Todo esto es para graficar usando networkx 
    """

    def get_node_list(self):
        return [x.label for x in self.nodos]

    def get_edges_list(self):
        adyacent_list = []
        for nodo in self.nodos:
            for adyacente in self.nodos.get(nodo):
                adyacent_list.append((nodo.label, adyacente.label))

        return adyacent_list

    def get_labels(self):
        return {nodo.label: nodo.label for nodo in self.nodos}


    def get_colores(self):
        colores_aux = []
        colores_dict = {}
        i = 1
        for nodo in self.nodos:
            if not colores_dict.get(nodo.color):
                colores_dict[nodo.color] = i
                i = i + 1
            colores_aux.append(colores_dict[nodo.color])

        return colores_aux

    def print_grafo(self):
        for nodo in self.nodos:
            print((nodo.label, nodo.color), '->', [x.label for x in self.nodos[nodo]])
