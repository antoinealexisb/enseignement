#importation
from random import *
#note : les fonctions ne sont pas encore dispo.
__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr>'

taux = int(0)
question = int(0)
alea = 0
rep_1= "0"
rep_2= "0"
rep_3= "0"
rep_4= "0"
rep_5= "0"
rep_6= "0"
print('TP2-ALL_EXOS-BOURDON ANTOINE-ALEXIS LMI-2')
choix = input('Choisir l\'exercice :\n1 - Quizz\n2 - Jeu_devine\n')
if choix == '1':
	print("Quiz : Cinéma.\n")#DEBUT AVEC LE 'TITRE'
	alea = randint(1,6)
	while question < 6:
		if alea == 1:
			if rep_1== "0":
				reponse_1 = input("Quel acteur français prononce cette phrase dans le film dans Astérix et Obélix : Mission Cléopâtre « Excusez-moi d’en faire un sac, mais je vais finir dans un crocodile peut-être ! » \n A:Alain Chabat \n B:Gérard Darmon\n C:édouard Baer\n D:Jamel Debbouze\n Votre Réponse: ") #QUESTION 1
				if reponse_1 == "D" or reponse_1 == "d": #REPONSE 
					print("La réponse est correcte\n") #AFFICCHE REPONSE CORRECTE
					taux=taux+1; #AUGMENTATION DU TAUX QUI CORRESPOND AU SCORE
					question = question+1
					rep_1=1
					alea = randint(1,6)
				else:
					print("La réponse est fausse\n") #REPONSE FAUSSE
					question = question+1
					rep_1=1
					alea = randint(1,6)
			else:   
				alea = randint(1,6)
			############## PAREILLE POUR LES QUESTIONS A VENIR
		if alea == 2:
			if rep_2== "0":
				reponse_2 = input("Dans quel film entend-on cette réplique « J’adore l’odeur du napalm au petit matin » ? Votre Réponse: ").lower()
				if reponse_2 == "apocalypse now" :
					print("La réponse est correcte\n")
					question = question+1
					taux=taux+1;
					rep_2=1
					alea = randint(1,6)
				else:
					print("La réponse est fausse\n")
					question = question+1
					rep_2=1
					alea = randint(1,6)
			else:
				alea = randint(1,6)

		if alea == 3:
			if rep_3== "0":    
				reponse_3 = input("Qui joue le rôle de l'épicier un peu benêt dans le film « Le fabuleux Destin d'Amélie Poulain » ?\n A:Jamel Debbouze \n B:Rufus\n C:Ramzy\n D:Patrick Timsit\n Votre Réponse: ")
				if reponse_3 == "A" or reponse_3 == "a":
					print("La réponse est correcte\n")
					question = question+1
					taux=taux+1;
					rep_3=1
					alea = randint(1,6)
				else:
					print("La réponse est fausse\n")
					question = question+1
					rep_3=1
					alea = randint(1,6)
			else:
				alea = randint(1,6)
		
		if alea == 4:
			if rep_4== "0":     
				reponse_4 = input("Quelle actrice interprète le rôle de Leeloo dans « Le 5e élément » ?\n Votre Réponse: ").lower()
				if reponse_4 == "milla jovovitch" or reponse_4 =="jovovitch milla":
					print("La réponse est correcte\n")
					question = question+1
					taux=taux+1;
					rep_4=1
					alea = randint(1,6)
				else:
					print("La réponse est fausse\n")
					question = question+1
					rep_4=1
					alea = randint(1,6)
			else:
				alea = randint(1,6)


		if alea == 5:
			if rep_5== "0":      
				reponse_5 = input("Quel acteur de la Comédie française a réalisé le film « Les garçons et Guillaume, à table ! » ? \n Votre Réponse: ").lower()
				if reponse_5 == "guillaume galienne" or reponse_5=="galienne guillaume":
					print("La réponse est correcte\n")
					question = question+1
					taux=taux+1;
					rep_5=1
					alea = randint(1,6)
				else:
					print("La réponse est fausse\n")
					question = question+1
					rep_5=1
					alea = randint(1,6)
			else:
				alea = randint(1,6)
		if alea == 6:
			if rep_6== "0":      
				reponse_6 = input("Quel acteur joue le rôle du professeur dans « Le Cercle des Poètes disparus » ? \n Votre Réponse: ").lower()
				if reponse_6 == "robin williams" or reponse_6=="williams robin":
					print("La réponse est correcte\n")
					question = question+1
					taux=taux+1;
					rep_6=1
					alea = randint(1,6)
				else:
					print("La réponse est fausse\n")
					question = question+1
					rep_6=1
					alea = randint(1,6)
			else:
				alea = randint(1,6)

    ##################CALCUL DU POURCENTAGE + AFFICHE LE SCORE AVEC UN COMMENTAIRE
	if question == 6:
		taux_pourcent=(taux*100)/6
		print("Votre score : ", taux,"/6","\n Votre pourcentage : ", taux_pourcent,"%")
		if (taux_pourcent > float(0)):
			if (taux_pourcent > float(80)):
				print('maitre')
			elif (taux_pourcent > float(50)):
				if (taux_pourcent == float(75)):
					print("bonne connaissance")
				print('connaisseur')
			elif (taux_pourcent >= int(0)):
				if (taux_pourcent > float(25)):
					print("quelques connaisances")
				if (taux_pourcent<float(25)):
					print(taux_pourcent)
					print("faible connaissance")

##########PROG 2 #######

if choix =='2':

	print('Bonjour ! \nJe viens de choisir un nombre entre 1 et 20. Devinez-le !')
	machine_num=randint(1,20)
	i=1
	while i<=5:
		utilisateur_num=int(input('Essai {0}:'.format(i)))
		if utilisateur_num!=machine_num:
			i=i+1
			if machine_num>utilisateur_num:
				print('Non. J\'ai choisi un nombre plus grand\n')
			if machine_num<utilisateur_num:
				print('Non. J\'ai choisi un nombre plus petit\n')
		if utilisateur_num==machine_num:
			a=i
			i=10000
			print('Felicitations ! Vous avez devine le nombre en ',a,' essaies')

	if i==5:
		print('Pas de chance vous n\'avez pas reussi')
