'''
    You can only use the nested class, because there is no nested
    object
'''

class Human:
    def __init__(self):
        self.name = 'Guido'
        self.head = self.Head()

    class Head:
        def talk(self):
            return 'talking...'

if __name__ == '__main__':
    guido = Human()
    print(guido.name)
    print(guido.head.talk())
