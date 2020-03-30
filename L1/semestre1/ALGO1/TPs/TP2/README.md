# TP2 Quiz

Aujourd’hui, nous allons créer un quiz. Il s’agît d’un type de questionnaire fréquemment trouvé dans les
magazines et sur internet qui testent notre connaissance sur un sujet particulier : une série télé, un personage, une
équipe sportive, etc.

### Exercice 1

Créer un quiz. Voici la liste de fonctionnalités que le programme doit contenir obligatoirement :

1. Créer son propre quiz avec un minimum de cinq questions. Il faut au moins une question de chaque type :
    — numérique (ex. : Combien de planètes y a-t-il dans le système solaire ?)
    — textuelle (ex. : Quel est le deuxième prénom du Capitaine Kirk ?)
    — sélection (ex. : Quel est la réponse correcte? A, B, C.. .)
2. Si l’utilisateur doit entrer des réponses non-numériques, vous devez couvrir les différentes possibilités. Par
    exemple, si la réponse est “a”, donc “A” est-il accepté aussi?
3. Informer l’utilisateur si elle ou il a répondu correctement. Imprimer un message en fonction de sa réponse.
4. À la fin du programme, afficher le nombre et le pourcentage des réponses correctes. Calculer le pourcentage
    en utilisant une formule. Éviter de juste additionner 20% à chaque réponse correcte. Avec une formule, si
    plus tard vous décidez d’ajouter une question, vous pouvez le faire avec un seul et facile changement dans
    le programme.
5. À la fin du programme, féliciter l’utilisateur s’il a répondu correctement à plus de la moitié des questions.
    Afficher également le niveau de connaissance de l’utilisateur. Par exemple :
    — si le score est inférieur à 25% afficher«faible connaissance».
    — si le score est situé entre 25% et 50% afficher«quelques connaissances».
    — si le score est situé entre 50% et 75% afficher«connaisseur».
    — si le score est supérieur à 75% afficher«bonne connaissance».
    — si le score est égal à 100% afficher«maître».

```
En plus :
— Utilisez des commentaires dans votre programme.
— Suivez les recommandations données en cours pour les noms de variables.
— Séparez les groupes d’instructions avec une ligne blanche. Par exemple, insérez une ligne blanche entre le
code de chaque question du quiz.
— Parfois, c’est une bonne idée re-utiliser des variables. Par exemple, au lieu de créer une variable différente
pour sauvegarder la réponse à chaque question, vous pouvez utiliser la même variable.
— Utilisez des noms des variables descriptifs. En effet,«x»n’est pas un bon nom de variable, car très peu
descriptif. Utilisez quelque chose commenumero_correct, par exemple.
```
```
Quelques pistes pour réaliser votre quiz :
— Pour pouvoir afficher le nombre de réponses correctes à la fin du programme, créez une variable qui servira
à sauvegarder cette valeur. Initialisez-la à zéro au début du programme. À chaque réponse correcte donnée
par l’utilisateur, ajoutez 1 à cette variable.
— Pour afficher une ligne blanche entre deux questions, vous pouvez utiliser l’instructionprintsans argu-
ment :
print()
— Souvenez-vous qu’il est possible d’imprimer plusieurs items par ligne avec une instruction comme :
print(’La réponse correcte est : ’, reponse)
```

   Exemple d'exécution:

```
Quiz : Le système solaire.

Combien des planètes y a-t-il dans le système solaire? 8
Correct!

Quelle est la planète la plus massive? jupiter
Correct!

Lequel de ces objets célestes est une comète?
A. Pluton
B. Chariklo
C. Halley
D. Titania
? c
Correct!

Lequel de ces objets célestes est le plus éloigné du soleil?
A. Mercure
B. Neptune
C. Cérès
D. Terre
? b
Correct!

Où se trouve le volcan le plus massif du système solaire? mars
Correct!

Félicitations! Vous avez répondu correctement à 5 questions.
Votre score est de 100.0 %.
Vous êtes un maître en matière de système solaire.
```

### Exercice 2(bonus)

Améliorer le quiz de l’exercice précédent en lui ajoutant quelques questions. Ensuite, mo-
difier le programme de manière à ce que les questions posées soient choisies aléatoirement.
Pour réaliser ce programme, vous avez besoin d’utiliser la bibliothèquerandomet la fonctionrandint. Vous
pouvez demander plus des renseignements à votre enseignant.

### Exercice 3(bonus)
Créer un jeu de “Deviner le Nombre”. Dans ce jeu, l’ordinateur choisit aléatoirement
un nombre entre 1 et 20. Ensuite, l’ordinateur demande à l’utilisateur de deviner le nombre. L’utilisateur a cinq
essayes pour le deviner, mais à chaque erreur, l’ordinateur lui dit si l’essai était supérieur ou inférieur au nombre
choisi. Si l’utilisateur devine le nombre avant le cinquième essai, il gagne le jeu.
Exemple d’exécution :

```
Bonjour!
Je viens de choisir un nombre entre 1 et 20. Devinez-le!

Essai 1 : 10
Non. J’ai choisi un nombre plus petit.

Essai 2 : 5
Non. J’ai choisi un nombre plus petit.

Essai 3 : 3
Félicitations! Vous avez deviné le nombre en 3 essais.
```


