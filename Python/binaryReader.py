class Binario:
    def __init__(self, string, cant01, cant10):
        self.cant01 = cant01
        self.cant02 = cant10
        self.string = string
        self.cifras = len(string)

    def menor(self):
        if self.cant01 < self.cant02:
            return True
        else:
            return False

    def contarValores(self):
        self.cant01 = 0
        self.cant10 = 0
        for i in range(self.cifras - 1):
            if self.string[i:i + 2] == "01":
                self.cant01 += 1
            elif self.string[i:i + 2] == "10":
                self.cant10 += 1
                
def factorial(num):
    if num == 0:
        return 1
    else:
        return num * factorial(num - 1)


def almacenar(string):


def combinaciones(act, uno, cero, cifras):
    if len(act) == cifras:
        almacenar(act)
        return act
    if uno > 0:
        combinaciones(act + '1', uno - 1, cero, cifras)
    if cero > 0:
        combinaciones(act + '0', uno, cero - 1, cifras)

def leerArchivo():
    file = open("arch.txt", 'r')
    binarios = []

    iteraciones = int(file.readline())
    for i in range(iteraciones):
        string = file.readline().strip("\n")
        a, b = file.readline().split(" ")
        if b[-1] == '\n':
            b = int(b[:-1])
            a = int(a)
        else:
            b = int(b)
            a = int(a)
        binarios.append(Binario(string,a, b))
    return binarios



binarios = leerArchivo()
curr = ""
todos = dict

if __name__ == "__main__":
    for i in binarios:
        curr = i
        combinaciones("", 2, 2, curr.cifras)
