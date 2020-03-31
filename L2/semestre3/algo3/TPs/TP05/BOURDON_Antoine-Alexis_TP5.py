'''
BOURDON Antoine-Alexis L2 2018/2019
TP5 - Listes Chainées
'''

class MaillonRec :

    def __init__(self,val,suiv=None):
        self.__val = val
        self.__suiv = suiv

    def suivant(self):
        return self.__suiv

    def append(self,val):
        '''MaillonRec, Objet -> None
        '''
        if self.__suiv == None :
            self.__suiv = MaillonRec(val)
        else :
            self.__suiv.append(val)

    def __str__(self):
        '''MaillonRec -> str

        >>> m = MaillonRec(1)
        >>> print(m)
        1
        >>> m2 = MaillonRec(2,m)
        >>> print(m2)
        2, 1
        '''
        mess = str(self.__val)
        if self.__suiv != None :
            mess += ", "+self.__suiv.__str__()
        return mess

    def len(self):
        '''MaillonRec -> int
        
        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.len()
        3
        '''
        nb = 1
        if self.__suiv != None :
            nb += self.__suiv.len()
        return nb


    def get(self,ind):
        '''MaillonRec, int -> Objet
        '''
        assert ind < self.len()
        if ind == 0 :
            return self.__val
        else :
            assert self.__suiv is not None
            return self.__suiv.get(ind-1)


    def set(self,ind,val):
        '''MaillonRec, int, Objet -> None
        '''
        if ind == 0 :
            self.__val = val
        else :
            assert self.__suiv is not None
            self.__suiv.set(ind-1,val)

    def delete(self,ind):
        '''MaillonRec, int -> None
        '''
        assert self.__suiv != None
        if ind == 0 :
            self.__suiv = self.__suiv.__suiv
        else :
            self.__suiv.delete(ind-1)

    def insert(self,val,ind):
        '''MaillonRec,Objet,int -> None
        '''
        if ind == 0 :
            m = MaillonRec(val,self.__suiv)
            self.__suiv = m
        else :
            assert self.__suiv != None
            self.__suiv.insert(val, ind - 1)

    def copy(self):
        '''MaillonRec -> MaillonRec
        '''
        nouveau_maillon = MaillonRec(self.__val)
        if self.__suiv != None :
            nouveau_maillon.__suiv = self.__suiv.copy()
        return nouveau_maillon

## fin de la classe MaillonRec


class ListeChaineeRec :

    def __init__(self):
        self.__tete = None

    def est_vide(self) :
        '''ListeChaineeRec -> boolean
        
        >>> l = ListeChaineeRec()
        >>> l.est_vide()
        True
        >>> l.append(1)
        >>> l.est_vide()
        False
        '''
        return self.__tete == None

    def append(self,val):
        '''ListeChaineeRec -> str
        
        >>> l = ListeChaineeRec()
        >>> print(l)
        []
        >>> l.append(1)
        >>> print(l)
        [1]
        >>> l.append(2)
        >>> l.append(3)
        >>> print(l)
        [1, 2, 3]
        >>> l.len()
        3
        '''
        if self.est_vide() :
            self.__tete = MaillonRec(val)
        else :
            self.__tete.append(val)

    def len(self):
        '''ListeChaineeRec -> int
        
        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.len()
        3
        '''
        if self.est_vide():
            return 0
        else :
            return self.__tete.len()

    def __str__(self) :
        '''ListeChaineeRec -> str
        
        >>> l = ListeChaineeRec()
        >>> print(l)
        []
        >>> l.append(1)
        >>> print(l)
        [1]
        >>> l.append(2)
        >>> l.append(3)
        >>> print(l)
        [1, 2, 3]
        >>> l.len()
        3
        '''
        mess = "["
        if not self.est_vide() :
            mess += self.__tete.__str__()
        mess += "]"
        return mess

    def get(self,ind):
        '''ListeChaineeRec, int -> Objet

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.get(0)
        1
        >>> l.append(2)
        >>> l.append(3)
        >>> l.get(1)
        2
        >>> l.get(2)
        3
        '''
        assert not self.est_vide()
        return self.__tete.get(ind)

    def set(self,ind,val):
        '''ListeChaineeRec, int, Objet -> None

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.set(1,12)
        >>> print(l)
        [1, 12, 3]
        '''
        assert not self.est_vide()
        self.__tete.set(ind,val)

    def delete(self,ind):
        '''ListeChaineeRec, int -> None

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.delete(1)
        >>> print(l)
        [1, 3]
        >>> l.delete(0)
        >>> print(l)
        [3]
        '''
        assert not self.est_vide()
        if ind == 0 :
            self.__tete = self.__tete.suivant()
        else :
            self.__tete.delete(ind-1)

    def insert(self,val,ind):
        '''ListeChaineeRec,Objet,int -> None

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> print(l)
        [1, 2, 3]
        >>> l.insert(8,0)
        >>> print(l)
        [8, 1, 2, 3]
        >>> l.insert(12,2)
        >>> print(l)
        [8, 1, 12, 2, 3]
        >>> l.insert(15,4)
        >>> print(l)
        [8, 1, 12, 2, 15, 3]
        '''
        if ind == 0 :
            ## c'est ici qu'on doit insérer
            m = MaillonRec(val,self.__tete)
            self.__tete = m
        else :
            assert self.__tete != None
            self.__tete.insert(val,ind-1)


    def copy(self):
        '''ListeChaineeRec -> ListeChaineeRec
        '''
        nouveau = ListeChaineeRec()
        if self.__tete != None : 
            nouveau.__tete= self.__tete.copy()
        return nouveau


    def repete(self):
        '''Fonction permettant de trouver le premier éléèment qui se répète dans une liste chainée.

        ListeChaineeRec -> Bool.
        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.repete()

        >>> l.append(3)
        >>> l.repete()
        True
	'''
        assert not self.est_vide()
        for i in range(self.len()):
            for j in range(i+1, self.len()):
                if self.get(i) == self.get(j):
                    return True
        return None

    def existe_ite(self, val):
        '''Fonction permettant de tester si une valeur donnée est présente dans une liste chainée.
        ListeChaineeRec, int -> Bool.

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.existe_ite(3)

        >>> l.existe_ite(2)
        True
        '''
        assert not self.est_vide()
        for i in range(self.len()):
            if self.get(i) == val:
                return True
        return None

    def existe_recur(self, val, i=-2):
        '''Fonction permettant de tester si une valeur donnée est présente dans une liste chainée.
        ListeChaineeRec, int, (int) -> Bool.

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.existe_recur(3)

        >>> l.existe_recur(2)
        True
        '''
        assert not self.est_vide()
        if i==-2:
            i=self.len()-1
        if i==-1:
            return None
        if self.get(i) == val:
            return True
        return self.existe_recur(val,i-1)

    def maxi(self):
        '''Fonction permettant de retourner la valeur maximale d'une liste chainée.
        ListeChaineeRec -> int

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.maxi()
        3
        '''
        maxi=0
        for i in range (self.len()):
            if self.get(i) > maxi:
                maxi=self.get(i)
        return maxi

    def maxi_recur(self,max=0,i=0):
        '''Fonction permettant de retourner la valeur maximale d'une liste chainée.
        ListeChaineeRec, (int), (int) -> int

        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.maxi_recur()
        3
        '''
        if self.get(i)>max:
            max=self.get(i)
        if self.len()<=i+1:
            return max
        return self.maxi_recur(max,i+1)

    def mini_liste(self):
        '''Fonction permettant de retourner la liste les maillons de valeur minimale d'une liste chainée.
        ListeChaineeRec -> list(tuple) # (minimum,position dans la chaine)

        >>> l = ListeChaineeRec()
        >>> l.append(2)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(1)
        >>> l.mini_liste()
        [(1,3),(1,5)]
        '''
        mini=self.get(0)
        l_n=[]
        for i in range (self.len()):
            if self.get(i) < mini:
                mini=self.get(i)
        for i in range(self.len()):
            if self.get(i) == mini:
                l_n.append((mini,i))
        return l_n

    
    def kieme(self,k):
        '''Fonction permettant de retrouver la valeur du kieme élèment depuis la fin d'une liste chainée.

        ListeChaineeRec, int -> int(Maillon)
        >>> l = ListeChaineeRec()
        >>> l.append(2)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(1)
	>>> l.kieme(2)
        2
        '''
        for i in range (self.len(),-1,-1):
            if k == 0:
                return self.get(i)
            else:
                k-=1

    def permutation(self):
        '''Fonction permettant de permuter chaque deux maillons qui se suivent

        ListeChaineeRec(modif) -> None
        >>> l = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.append(4)
        >>> l.append(5)
        >>> l.append(6)
        >>> l.append(7)
	>>> print(l)
        [1,2,3,4,5,6,7]
        >>> l.permutation()
        >>> print(l)
        [2,1,4,3,6,5,7]
        '''
        for i in range(0, self.len()-(self.len()%2),2):
            val1=self.get(i)
            val2=self.get(i+1)
            self.set(i,val2)
            self.set(i+1,val1)

    def division(self,m2):
        '''Fonction permettant de diviser une liste chainée en deux listes chainées en attribuant les maillons à tour de rôle.

        ListeChaineeRec(modif),ListeChaineeRec(modif) -> None
        >>> l = ListeChaineeRec()
        >>> m = ListeChaineeRec()
        >>> l.append(1)
        >>> l.append(2)
        >>> l.append(3)
        >>> l.append(4)
        >>> l.append(5)
        >>> l.append(6)
        >>> l.append(7)
	>>> print(l)
        [1,2,3,4,5,6,7]
        >>> print(m)
        []
        >>> l.division(m)
        >>> print(l)
        [1,3,5,7]
        >>> print(m)
        [2,4,6]
        '''
        assert not self.est_vide()
        assert m2.est_vide()
        j=0
        for i in range(0,self.len()-self.len()%2,2):
            self.set(j,self.get(i))
            j+=1
            m2.append(self.get(i+1))
        if self.len()%2==1:
            self.set(j,self.get(self.len()-1))
            j+=1
        for i in range(self.len()-((self.len()//2)+self.len()%2)):
            self.delete(j)


'''
def main():
    l=ListeChaineeRec()
    l.append(12)
    l.append(2)
    l.append(-5)
    l.append(999)
    l.append(0)
    l.maxi()
    l.mini_liste()
    print(l)

'''
