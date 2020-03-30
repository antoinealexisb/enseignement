# TP5 Le pendu

Aujourd’hui, nous allons programmer le jeu du pendu. Voici un exemple d’exécution du jeu :

```
LE PENDU

   +---+
   |   |
       |
       |
       |
       |
==========

Erreurs :
_ _ _ _ _ _ _ _ _

Entrez une lettre : a

...

   +---+
   |   |
   O   |
  /|\  |
       |
       |
==========

Erreurs :
f e i p

b a r r a c u _ a

Entrez une lettre : d
Vous avez gagne !
Le mot secrait etait : barracuda
>>>
```

Comme auparavant, nous allons décomposer le problème en plusieurs sous-problèmes, où chacun
correspond à une des fonctions suivantes :  
	— choisis_mot: choisi le mot secret.  
	— input_lettre: demande une lettre au joueur.  
	— dessine_ecran: dessine l’écran du jeu.  
	— main: la fonction principale.  
La fonction *dessine_ecran* sera par la suite décomposée en d’autres fonctions.

**N’oubliez pas de documenter et tester vos fonctions !**

## 1 Choisir le mot secret

Écrivez la fonction *choisis_mot* qui reçoit une liste de chaînes de caractères en argument et qui
**retourne** une chaîne aléatoirement choisie dans la liste.  
Exemple de teste :

```
>>> choisis_mot([’alligator’, ’escargot’])
’alligator’
>>> choisis_mot([’alligator’, ’escargot’])
’escargot’
```

## 2 Demander une lettre au joueur

Écrivez la fonction *input_lettre* qui reçoit une chaîne de caractères *lettres_entrees* en argument et qui retourne une lettre (chaîne de caractères). La fonction doit demander à l’utilisateur d’entrer
une lettre. Si l’utilisateur entre plus d’une lettre, elle doit afficher un message d’erreur et redemander. De même, si l’utilisateur entre avec autre chose qu’une lettre, la fonction doit afficher un message d’erreur et redemander. De plus, si l’utilisateur entre avec une lettre déjà présente dans la chaîne
*lettres_entrees*, la fonction doit afficher un message d’erreur et redemander.  
Exemple de teste :

```
>>> input_lettre(’abc’)
Entrez une lettre : dd
Entrez une seule lettre, s’il vous plaît.
Entrez une lettre : a
Vous avez déjà entré cette lettre.
Entrez une lettre : 0
Ceci n’est pas une lettre.
Entrez une lettre : e
’e’
>>>
```

## 3 Dessiner l’écran du jeu

La fonction qui dessine l’écran du jeu est un peu plus compliquée. Nous allons donc la décomposer
en plusieurs fonctions :  
    — dessine_pendu: affiche un dessin du pendu.  
	— affiche_erreurs: affiches les erreurs du joueur.  
	— affiche_correctes: affiche le lettres correctes.
### 3.1 Dessiner le pendu

Écrivez la fonction *dessine_pendu* qui reçoit un entiernen argument et qui n’a pas de valeur de
retour. La fonction doit afficher la *n*-ième figure du pendu.  
La meilleur forme de dessiner le pendu est d’utiliser une liste de dessins. Dans notre cas, nous
pouvons utiliser une liste de chaînes de caractères où chaque élément correspond à un des dessins du
pendu. Par exemple, la liste ci-dessous contient deux figures du pendu :

```
FIGURES_PENDU = ['''
   +---+
   |   |
       |
       |
       |
       |
==========''','''
   +---+
   |   |
   O   |
  /|\  |
  / \  |
       |
==========''']

```
Par exemple, l’instruction *print(FIGURES_PENDU[0])* affichera la première figure du pendu.

### 3.2 Afficher les erreurs

Écrivez la fonction *affiche_erreurs* qui reçoit une chaîne de caractèreserreursen argument et
qui n’a pas de valeur de retour. La fonction doit afficher les éléments de la chaîne comme les erreurs du
joueur.  
Exemple de testes :

```
>>> affiche_erreurs(’abc’)
Erreurs :
a b c
>>> affiche_erreurs(’efgdx’)
Erreurs :
e f g d x
```

### 3.3 Afficher les lettres correctes

Écrivez la fonction *affiche_correctes* qui reçoit deux chaînes de caractères *correctes* et *mot_secret*
et qui affiche les lettres correctes entrées par le joueur.  
Exemples de teste :


```
>>> affiche_correctes(’elc’, ’ecurreil’)
e c _ _ _ e _ l
>>> affiche_correctes(’lia’, ’alligator’)
a l l i _ a _ _ _
```

## 4 La fonction principale

Écrivez la fonction principale du programme (main) qui ne reçoit pas d’arguments et qui n’a pas de
valeur de retour. La fonction doit utiliser les fonctions décrites auparavant pour :  

1. Afficher l’entrée du jeu.
2. Choisir un mot secret.
3. Tant que le nombre max d’erreurs n’est pas atteint et que le joueur n’a pas gagné :
	(a) Dessine le pendu.  
	(b) Affiche les erreurs.  
	(c) Affiche les lettres correctes.  
	(d) Demande au joueur d’entrer une lettre.  
4. Affiche si le joueur a gagné ou pas et affiche le mot secret.

Ajoutez l’appel à la fonction *main* dans votre programme.