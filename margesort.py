class Lista:
    def __init__(self, _pos=[]):
        self.pos = _pos
    

    def length(self):
        return len(self.pos)
    def mostrar(self, _sep=""):
        print(f"{_sep}", end="")
        for item in self.pos:
            print(f"{item}",end=" ")

    def mergesort(self, l=None, r=None):
        if l == None or r == None:
            self.mergesort(0, self.length()-1)
        else:
            if l < r:
    
                m = l+(r-l)//2
        
                self.mergesort(l, m)
                self.mergesort(m+1, r)
                
                self.merge(self.pos, l, m, r)

    @staticmethod
    def merge(arr, l, m, r):
        n1 = m - l + 1
        n2 = r - m
    
        L = [0] * (n1)
        R = [0] * (n2)
    
        for i in range(0, n1):
            L[i] = arr[l + i]
    
        for j in range(0, n2):
            R[j] = arr[m + 1 + j]
    
        i = 0
        j = 0
        k = l
    
        while i < n1 and j < n2:
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        while i < n1:
            arr[k] = L[i]
            i += 1
            k += 1
            
        while j < n2:
            arr[k] = R[j]
            j += 1
            k += 1


lista = Lista([1, 2, 6, 7, 8, 41, 56, 5, 12 , 0])

print("\nLista não ordenada: ")
lista.mostrar()

print("\n\nLista ordenada: ")
lista.mergesort()
lista.mostrar()
