class ArbreBinaire :
    '''Classe qui permet d'implémenter un arbre biniare.'''
    
    def __init__(self , val, fg=None, fd=None) :
        '''Contructeur de la classe ArbreBiniare, qui permet d'initialiser les attributs de self.
        Arguments :
            self -- ArbreBinaire
            val -- int
            fg -- int
            fd -- int
        Retour :
            ArbreBiniare(modif)'''
        
        self.val = val
        self.fg = fg
        self.fd = fd

    def valeur(self) :
        '''Méthode qui permet de retourner la valeur du noeud courant.
        Arguments :
            self -- ArbreBiniare
        Retour :
            None/int '''
        return self.val
        

    def aFG(self) :
        '''Méthode qui permet de vérifier si le noeud courant possède un fils gauche.
        Arguments :
            self -- ArbreBiniare
        Retour :
            boolean '''
        return self.fg != None
    

    def aFD(self) :
        '''Méthode qui permet de vérifier si le noeud courant possède un fils droit.
        Arguments :
            self -- ArbreBiniare
        Retour :
            boolean '''
        return self.fd != None
    

    def estFeuille(self) :
        '''Méthode qui permet de vérifier si un noeud est une feuille.
        Argument :
            self -- ArbreBiniare
        Retour :
            boolean '''
        return (not self.aFD()) and (not self.aFG())


    def nombre_sommets(self) :
        '''Méthode qui permet de calculer le nombre de sommets de l'arbre biniaire.
        Arguments :
            self -- ArbreBinaire
        Retour :
            int '''
        if (self.val is None) or (self.estFeuille()) :
            return 0
        if self.aFG() :
            return 1 + self.fg.nombre_sommets()
        if self.aFD() :
            return 1 + self.fd.nombre_sommets()


    # DFS
    def DeuxiemePlusGrand (self) :
        '''Méthode qui permet de retourner le deuxième plus grand noeud de l'arbre biniare.
        Arguments :
            self -- ArbreBiniare
        Retour :
            int '''
        
        
        if self.val == None :
            return None
        maxi = self.valeur()
        maxi2 = 0
        if self.aFG():
            if self.fg.valeur() > maxi2 and self.fg.valeur() < maxi :
                maxi2 = self.fg.valeur()
            if self.fg.valeur() > maxi :
                maxi2 = maxi
                maxi = self.fg.valeur()
            self.fg.DeuxiemePlusGrand()
        if self.aFD():
            if self.fd.valeur() > maxi2 and self.fd.valeur() < maxi :
                maxi2 = self.fd.valeur()
            if self.fd.valeur() > maxi :
                maxi2 = maxi
                maxi = self.fd.valeur()
            self.fd.DeuxiemePlusGrand()
        return maxi2

        # BFS
    def DeuxiemePlusGrand_BFS (self) :
        '''Méthode qui permet de retourner le deuxième plus grand noeud de l'arbre biniare.
        Arguments :
            self -- ArbreBiniare
        Retour :
            int '''
        
        
        if self.val == None :
            return None
        maxi = self.valeur()
        maxi2 = 0
        f = File()
        f.ajouter(self)
        while not f.est_vide() :
            sommet = f.enelever()
            if sommet.aFG() :
                if self.fg.valeur() > maxi2 and self.fg.valeur() < maxi :
                    maxi2 = self.fg.valeur()
                if self.fg.valeur() > maxi :
                    maxi2 = maxi
                    maxi = self.fg.valeur()
                f.ajoute(sommet.fg)
            if self.aFD():
                if self.fd.valeur() > maxi2 and self.fd.valeur() < maxi :
                    maxi2 = self.fd.valeur()
                if self.fd.valeur() > maxi :
                    maxi2 = maxi
                    maxi = self.fd.valeur()
                f.ajoute(sommet.fd)
        return maxi2
    
    # DFS

    def unFils(self) :
        '''Méthode qui permet de retourner la liste des noeuds ayant un seul fils.
        Arguments :
            self -- ArbreBinaire
        Retour :
            list(int) '''
        
    
        if self.val == None :
            return None
        fils = []
        if (self.aFG() and not self.aFD()) : 
            fils.append(self.fg)
            self.fg.unFils()
        if (self.aFD() and not self.aFG()) :
            fils.append(self.fd)
            self.fd.unFils()
            
        return fils
    
        # BFS

        
    def unFils_BFS(self) :
        '''Méthode qui permet de retourner la liste des noeuds ayant un seul fils.
        Arguments :
            self -- ArbreBinaire
        Retour :
            list(int) '''

        fils = []
        if self == None:
            return 0
        f = File()
        f.ajoute(self)
        cpt=0
        if (self.aFG() and not self.aFD()) or (self.aFD() and not self.aFG()) :
            fils.append(self)
        while not f.est_vide():
            sommet = f.enlever()
            cpt += 1
            if sommet.aFG():
                if (self.fg.aFD() and not self.fg.aFG()) or (self.fg.aFG() and not self.fg.aFD()) :
                    fils.append(self.fg)
                f.ajoute(sommet.fg)
            if sommet.aFD():
                if (self.fd.aFD() and not self.fd.aFG()) or (self.fd.aFG() and not self.fd.aFD()) :
                    fils.append(self.fd)
                f.ajoute(sommet.fd)
        return fils



    def internes(self) :
        '''Méthode qui permet de retourer la liste des sommets internes (qui ne sont pas feuilles) de l'arbre biniare.
        Arguments :
            self -- ArbreBiniare
        Retour :
            list '''

        if self.val == None :
            return None
        interne = []
        if self.aFG() : 
            interne.append(self)
            self.fg.internes()
        elif self.aFD() :
            interne.append(self)
            self.fd.internes()

        return interne


    def plus_grand_k(self, k) :
        '''Méthode qui permet de retourner la plus grande valeur inférieure à k.
        Arguments :
            self -- ArbreBiniare
            k -- int
        Retour :
            int '''
        if self.val == None :
            return None
        maxi = 0
        if self.aFG():
            if self.fg.valeur() > maxi :
                if self.fg.valeur() <= k :
                    maxi = self.fg.valeur()
                elif self.fg.valeur() < k :
                    self.fg.plus_grand_k(k)
        if self.aFD():
            if self.fd.valeur() > maxi :
                if self.fd.valeur() <= k :
                    maxi = self.fd.valeur()
                elif self.fd.valeur() < k :
                    self.fd.plus_grand_k(k)
        return maxi




    def feuilles_negatives(self) :
        '''Méthode qui permet de retourer la liste des feuilles négatives.
        Arguments :
            self -- ArbreBiniare
        Retour :
            list '''
        feuille_neg = []
        if self.aFG() :
            if self.fg.estFeuille() :
                if self.fg.valeur() < 0 :
                    feuille_neg.append(self.fg)
            else :
                self.fg.feuilles_negatives()
        if self.aFD():
            if self.fd.estFeuille() :
                if self.fd.valeur() < 0 :
                    feuille_neg.append(self.fd)
            else :
                self.fd.feuilles_negatives()
        return feuille_neg


    def toStr_Infixe(self) :
        '''Méthode qui permet d'afficher un arbre binaire dans un ordre infixé.
        Arguments :
            self -- ArbreBinaire
        Retour : / '''

        st = ""
        if self.aFG() :
            st += "("+int(str(self.fg.valeur()))
            self.fg.toStr_Infixe()
        st+= int(str(self.valeur()))
        if self.aFD() :
            st += int(str(self.fd.valeur())) + ")"
            self.fd.toStr_Infixe()
        st += ")"
        return st
        
    def toStr_Postfixe(self) :
        '''Méthode qui permet d'afficher un arbre binaire dans un ordre postfixé.
        Arguments :
            self -- ArbreBinaire
        Retour : / '''
    
        st = ""
        if self.aFG() :
            st += "("+int(str(self.fg.valeur()))
            self.fg.toStr_Infixe()
        if self.aFD() :
            st += int(str(self.fd.valeur()))
            self.fd.toStr_Infixe()
        st += int(str(self.valeur)) + ")"
        return st
            
            
    def toStr_Prefixe(self) :
        '''Méthode qui permet d'afficher un arbre binaire dans un ordre prefixé.
        Arguments :
            self -- ArbreBinaire
        Retour : / '''

        st = ""
        st += "(" + int(str(self.valeur()))
        if self.aFG() :
            self.fg.toStr_Prefixe()
        if self.aFD() :
            self.toStr_Prefixe()
        else :
            st += "()"
        st + ")"
        return st
        

    def sommets_profondeur_k(self,k) :
        '''Méthode qui permet de renvoyer les noeuds situés à une profondeur k.
        Arguments :
            self -- ArbreBinaire
        Retour :
            list '''

        sommets_k = []
        while not self.estFeuille() and k != 1:
            if self.aFG() :
                self.fg.sommets_profondeur_k(k-1)
            if self.aFD():
                self.fd.sommets_profondeur_k(k-1)
    
        if self.aFD() :
                sommets_k.append(self.fd)
        if self.aFG() :
                sommets_k.append(self.fg)
        return sommets_k


    def LesPlusProfonds(self) :
        '''Méthode qui permet de renvoyer la liste des sommets les plus profonds dans arbre binaire.
        Arguments :
            self -- ArbreBinaire
        Retour :
            list '''
        
        profonds = []
        if self.aFG() :
            if self.fg.estFeuille() :
                profonds.append(self)
            else :
                self.fg.LesPlusProfonds()
        elif self.aFD() :
            if self.fd.estFeuille() :
                profonds.append(self)
            else :
                self.fd.LesPlusProfonds()
        return profonds
