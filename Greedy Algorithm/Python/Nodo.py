class Nodo:

    def __init__(self, label, inicial, final):
        self.color = None
        self.label = label
        self.inicial = inicial
        self.final = final

    def pintar(self, color):
        self.color = color

    def print(self):
        print('color', self.color, 'label', self.label, 'inicial', self.inicial, 'final', self.final )