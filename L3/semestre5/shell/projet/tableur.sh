#!/bin/bash
#########################################################
#Script Name : tableur.sh
#Description : réalisation d'un mini tableur.
#Args : ce tableur prend en paramètre une feuille de calculs et devra fournir en retour le tableau complètement renseigné.
#Authors : Bourdon Antoine-Alexis && Devrainne Anthony
#Email : antoine-alexis_bourdon@ens.univ-artois.fr \
#        anthony_devrainne@ens.univ-artois.fr
#########################################################

##NOTE : éviter de mettre comme variable true ;)

 # Fonction qui teste si les cellules données son atteignable ou non.
 # #Args : 
 #  -$1 : ligne1
 #  -$2 : ligne2
 #  -$3 : Col1
 #  -$4 : Col2
 # #Return : 1 erreur, 0 sinon
function passErreur()
{
     # Test pour verifier si les cellules données sont possibles sinon erreurs
     test "$1" -gt "$nbLigne" 2>/dev/null || test "$1" -lt 0 2>/dev/null && exit 1
     test "$2" -gt "$nbLigne" 2>/dev/null || test "$2" -lt 0 2>/dev/null && exit 1
     test "$3" -gt "$nbColonne" 2>/dev/null || test "$1" -lt 0 2>/dev/null && exit 1
     test "$4" -gt "$nbColonne" 2>/dev/null || test "$2" -lt 0 2>/dev/null && exit 1
     exit 0

}

 # Fonction vérifiant si une chaine est un nombre ou non.
 # #Args :
 #   -$1 : chaine à tester
 # #Return : 42 si nombre, sinon 0
# note : =~ effectue une correspondance d'expression régulière de la chaîne située à sa gauche.
function estNombre()
 {
   if [[ "$1" =~ ^-?[0-9]*[.]?[0-9]+$ ]]  
   then
      echo "42"
    elif [[ "$1" =~ ^-?[0-9]*[.]$ ]]
    then
      echo "42"
    else
      echo "0"
    fi
}

# Fonction revoyant le numero de la ligne.
# #Args:
#   -$1 : lxcy(x,y sont des nombres et l,c ligne et colonne)
# #Return:
#   -la valeur de la cellule (ligne)

function lCel()
{
    echo "$1" | cut -dc -f 1 | cut -dl -f 2
}

# Fonction renvoyant le numero de la colonne.
# #Args:
#   -$1 : lxcy(x,y sont des nombres et l,c ligne et colonne)
# #Return:
#   -la valeur de la cellule (colonne)
function cCel(){
    echo "$1" | cut -dc -f 2
}

# Fonction qui analyse la cellule et choisit la fonction adapté pour traiter le cellule.
# #Args :
#   -$1 : Contenu de la cellule (exemple "=/(6/2)")
# #Retun : None ou "ERROR"
function calcul()
{
    nbCarac=${#1}
    (
    variable1=""
    variable2=""
    variable3=""
    operateur=""
    calcule=""
    true=0
    ecrit=0
    car=""
    k=1

    # Recuperons l'operateur Dora !
    operateur=`echo "$1" | cut -d"=" -f2`
    calcule=`echo "$operateur" | cut -d"(" -f1`

    #Si c'est un nb alors afficher le nb.
    if [[ `estNombre "$1"` -eq 42 ]] || [[ -f "$1" ]]
    then
        echo "$1"

    # si c'est un operateur alors on stocke le premier paramètre
    elif test "$calcule" = "+" || test "$calcule" = "-" || test "$calcule" = "*" || test "$calcule" = "/" || test "$calcule" = "^" || test "$calcule" = "somme" || test "$calcule" = "moyenne" || test "$calcule" = "variance" || test "$calcule" = "ecarttype" || test "$calcule" = "mediane" || test "$calcule" = "min" || test "$calcule" = "max" || test "$calcule" = "concat" || test "$calcule" = "display"
    then

    while [[ "$k" -le "$nbCarac" ]]
    do
        car=`echo "$operateur" | cut -c"$k"`
        test "$ecrit" -eq 1 && test "$car" = "," && break
        test "$ecrit" -gt 0 && variable1="$variable1""$car"
        test "$car" = "(" && ecrit=$(($ecrit + 1))
        test "$car" = ")" && ecrit=$(($ecrit - 1))
        k=$(($k + 1))
done


    ecrit=0
    k=1
    while [[ "$nbCarac" -gt "$k" ]]
        do
        car=`echo "$operateur" | cut -c"$nbCarac"`
        test "$ecrit" -eq 1 && test "$car" = "," && break
        test "$ecrit" -gt 0 && variable2="$car""$variable2"
        test "$car" = ")" && ecrit=$(($ecrit + 1))
        test "$car" = "(" && ecrit=$(($ecrit - 1))
        nbCarac=$(($nbCarac - 1))
    done
    "$calcule" "$variable1" "$variable2"

# Si un seul param
elif test "$calcule" = "ln" || test "$calcule" = "e" || test "$calcule" = "sqrt" || test "$calcule" = "length" || test "$calcule" = "size" || test "$calcule" = "lines" || test "$calcule" = "cos" || test "$calcule" = "sin"|| test "$calcule" = "shell"
then

    while [[ "$k" -le "$nbCarac" ]]
    do
        car=`echo "$operateur" | cut -c"$k"`
        test "$ecrit" -eq 1 && test "$car" = ")" && break
        test "$ecrit" -gt 0 && variable1="$variable1""$car"
        test "$car" = "(" && ecrit=$(($ecrit + 1))
        test "$car" = ")" && ecrit=$(($ecrit - 1))
        k=$(($k + 1))
    done
    "$calcule" "$variable1"

#Pour subsitue
elif [[ "$calcule" = "subsitute" ]]
then

    while [[ "$k" -le "$nbCarac" ]]
    do
        car=`echo "$operateur" | cut -c"$k"`
        test "$ecrit" -eq 1 && test "$car" = "," && break
        test "$ecrit" -gt 0 && variable1="$variable1""$car"
        test "$car" = "(" && ecrit=$(($ecrit + 1))
        test "$car" = ")" && ecrit=$(($ecrit - 1))
        k=$(($k + 1))
    done

    ecrit=0
    k=1
    while [[ "$k" -le "$nbCarac" ]]
    do
        car=`echo "$operateur" | cut -c"$k"`
        test "$ecrit" -eq 1 && test "$true" -eq 1 && test "$car" = "," && break
        test "$true" -eq 1 && variable2="$variable2""$car"
        test "$ecrit" -eq 1 && test "$true" -eq 0 && test "$car" = "," && true=1
        test "$car" = "(" && ecrit=$(($ecrit + 1))
        test "$car" = ")" && ecrit=$(($ecrit - 1))
        k=$(($k + 1))
   done

    ecrit=0
    k=1
    while [[ "$nbCarac" -gt "$k" ]]
    do
        car=`echo "$operateur" | cut -c"$nbCarac"`
        test "$ecrit" -eq 1 && test "$car" = "," && break
        test "$ecrit" -gt 0 && variable3="$car""$variable3"
        test "$car" = ")" && ecrit=$(($ecrit + 1))
        test "$car" = "(" && ecrit=$(($ecrit - 1))
        nbCarac=$(($nbCarac - 1))
    done
"$calcule" "$variable1" "$variable2" "$variable3"

#Si c'est un [] pour les cel ;)
elif [[ `echo "$calcule" | cut -c1` = "[" ]] && [[ `expr "$calcule" : ".*\(.\)"` = "]" ]]
then
    calcul `val \`echo "$calcule" | cut -d"[" -f2 | cut -d"]" -f1\``

# Sinon c'est pas bon donc mange ton erreur.
else
echo "ERROR"
fi
)
}

# Fonction renvoyant le contenu de la cellule.
# #Args:
#    -$1 : lxcy(x,y sont des nombres et l,c ligne et colonne)
# #Return : contenu de la cellule ou "ERROR!"

function val()
{
  ( #création d'un sous shell car j'oublie les local.
  resultat=""
  ligne=`lCel "$1"`
  colonne=`cCel "$1"`

  if [[ `estNombre "$ligne"` -ne 42 ]] || [[ `estNombre "$colonne"` -ne 42 ]]
  then
    echo "ERROR !" 
   # echo "Yo les aliens $1 $2 `estNombre $ligne` $ligne `estNombre $colonne` $colonne">>sortie.txt

  #VERIFICATION DEPASSEMENT !!!!!! à faire plz ;)
  elif [[ "$ligne" -gt "$nbLigne" ]] || [[ "$ligne" -lt 1 ]] || [[ "$colonne" -gt "$nbColonne" ]] || [[ "$colonne" -lt 1 ]]
  then
    echo "ERROR !"

  else
#echo "ici debug">&2
      echo `echo "$fichierMere" | cut -d "$sepLigDep" -f "$ligne" | cut -d "$sepColDep" -f "$colonne"`
#echo "22ici debug">&2
  fi
  )
}

 #Fonction revoyant l'addition des deux paramètres.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 #   -$2 : chaine2 representation le nombre2
 # #Return: $1+$2 ou "Erreur"
function +(){
(
  #nb1=`val $1`
  #nb2=`val $2`
  nb1="$1"
  nb2="$2"

  #Si l'un des nbs n'est pas numerique alors on le calcul
  if [[ `estNombre "$1"` -ne 42 ]]
  then
    nb1=`calcul "$1"`
  fi
  if [[ `estNombre "$2"` -ne 42 ]]
  then
    nb2=`calcul "$2"`
  fi

  #Si l'un des deux n'est pas un nb numerique.
  test `estNombre $nb1` = "0" || test `estNombre $nb2` = "0" && echo "ERROR!" && exit 1

  echo "scale=3; $nb1 + $nb2" | bc -l
)
}

 #Fonction revoyant la soustraction des deux paramètres.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 #   -$2 : chaine2 representation le nombre2
 # #Return: $1-$2 ou "Erreur"
function -(){
(
   nb1="$1"
   nb2="$2"

   if [[ `estNombre "$1"` -ne 42 ]]
   then
     nb1=`calcul "$1"`
   fi
   if [[ `estNombre "$2"` -ne 42 ]]
   then
     nb2=`calcul "$2"`
   fi

   test `estNombre $nb1` = "0" || test `estNombre $nb2` = "0" && echo "ERROR!" && exit 1

   echo "scale=3; $nb1 - $nb2" | bc -l
)
 }

 #Fonction revoyant la multiplication des deux paramètres.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 #   -$2 : chaine2 representation le nombre2
 # #Return: $1*$2 ou "Erreur"
function *(){
(
   nb1="$1"
   nb2="$2"

   if [[ `estNombre "$1"` -ne 42 ]]
   then
     nb1=`calcul "$1"`
   fi
   if [[ `estNombre "$2"` -ne 42 ]]
   then
     nb2=`calcul "$2"`
   fi

   test `estNombre $nb1` = "0" || test `estNombre $nb2` = "0" && echo "ERROR!" && exit 1

   echo "scale=3; $nb1 * $nb2" | bc -l
)
 }

 #Fonction revoyant la division des deux paramètres.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 #   -$2 : chaine2 representation le nombre2
 # #Return: $1/$2 ou "Erreur"
function /(){
(
   nb1="$1"
   nb2="$2"

   if [[ `estNombre "$1"` -ne 42 ]]
   then
     nb1=`calcul "$1"`
   fi
   if [[ `estNombre "$2"` -ne 42 ]]
   then
     nb2=`calcul "$2"`
   fi

   # Retourne si erreur si nb2 est un zero
   test "$nb2" -eq 0 && echo "ERROR div by zero impossible" && exit 1

   # Si l'une des valeurs n'est toujours pas un nb alors Error
   test `estNombre $nb1` = "0" || test `estNombre $nb2` = "0" && echo "ERROR!" && exit 1

   echo "scale=3; $nb1 / $nb2" | bc -l
)
}

 # Fonction POWERRR qui mets à la puissance AA , j'adore XD
 # Fonction revoyant la puissance du paramètre1 avec le paramètre2.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 #   -$2 : chaine2 representation le nombre2
 # #Return: $1^$2 ou "Erreur"
function ^(){
(
    nb1="$1"
    nb2="$2"

    if [[ `estNombre "$1"` -ne 42 ]]
    then
      nb1=`calcul "$1"`
    fi
    if [[ `estNombre "$2"` -ne 42 ]]
    then
      nb2=`calcul "$2"`
    fi

     test `estNombre $nb1` = "0"  || test `estNombre $nb2` = "0" && echo "ERROR!" && exit 1

     echo "scale=3; $nb1 ^ $nb2" | bc -l
)
}


 # Fonction revoyant l'exponentiel du paramètre1.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 # #Return: exp($1) ou "Erreur"
function e(){
(
    nb1="$1"

    if [[ `estNombre "$1"` -ne 42 ]]
    then
      nb1=`calcul "$1"`
    fi

    #Verifie si c'est pas un nombre
    test `estNombre "$nb1"` = "0" && echo "ERROR!" && exit 1

    echo "scale=3; e($nb1)" | bc -l
)
}

 # Fonction revoyant la logarithme népérien du paramètre1 avec le paramètre2.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 # #Return: ln($1) ou "Erreur"
function ln(){
(
    nb1="$1"

    if [[ `estNombre "$1"` -ne 42 ]]
    then
      nb1=`calcul "$1"`
    fi

    # Si c'est toujours pas valable
    test `estNombre $nb1` = "0" && echo "CHEH ! ERROR!" && exit 1

    echo "scale=3; l($nb1)" | bc -l
)
}

 # Fonction revoyant la racine carrée du paramètre1.
 # #Args:
 #   -$1 : chaine1 representation le nombre1
 # #Return: sqrt($1) ou "Erreur"
function sqrt(){
(
    nb1="$1"

    if [[ `estNombre "$1"` -ne 42 ]]
    then
      nb1=`calcul "$1"`
    fi

    #Si c'est toujours pas un nb
    test `estNombre "$nb1"` = "0" && echo "ERROR NOT A NUMBER!" && exit 1

    #la ligne à manquer de ne pas être là XD
    echo "scale=3; sqrt($nb1)" | bc -l
)
 }

# Fonction Cosinus
# Retourne le resultat sinon erreur en cas de.
# le param est un nombre en radian ;)
function cos(){
(
    nb1="$1"

    if [[ `estNombre "$1"` -ne 42 ]]
    then
      nb1=`calcul "$1"`
    fi

    #Si c'est toujours pas un nb
    test `estNombre "$nb1"` = "0" && echo "ERROR!" && exit 1

    #la ligne à manquer de ne pas être là XD
    echo "scale=3; c($nb1)" | bc -l
)
 }

# Fonction Sinus
# Retourne le resultat sinon erreur en cas de.
# le param est un nombre en radian comme pour le cosinus ;)
function sin(){
(
    nb1="$1"

    if [[ `estNombre "$1"` -ne 42 ]]
    then
      nb1=`calcul "$1"`
    fi

    #Si c'est toujours pas un nb
    test `estNombre "$nb1"` = "0" && echo "ERROR!" && exit 1

    #la ligne à manquer de ne pas être là XD
    echo "scale=3; s($nb1)" | bc -l
)
 }

 # Fonction revoyant la somme entre le paramètre1 et le paramètre2 (les paramètres sont inclus).
 # #Args:
 #   -$1 : chaine1 representation la cellule 1 pour la somme (lxcy).
 #   -$2 : chaine2 representation la cellule 2 pour la somme (lxcy).
 # #Return: somme entre deux celulles(incluses) ou Error de ligne car on dépasse la feuille de calcul.
function somme(){
(
     rslt=0
     ligne1=`lCel "$1"`
     ligne2=`lCel "$2"`
     Col1=`cCel "$1"`
     Col2=`cCel "$2"`

     ! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Error de ligne" && exit 1

     while [[ "$ligne1" -le "$ligne2" ]]
     do
         if [[ "$ligne1" -eq "$ligne2" ]]
         then
            while [[ "$Col1" -le "$Col2" ]]
            do
                rslt=`+ "$rslt" \`val l"$ligne1"c"$Col1"\``
                Col1=$(($Col1 + 1))
            done
          else
            while [[ "$Col1" -le "$nbColonne" ]]
            do
              rslt=`+ "$rslt" \`val l"$ligne1"c"$Col1"\``
              Col1=$(($Col1 + 1))
             done

        fi
        Col1=1
        ligne1=$(($ligne1 + 1))
    done
    echo "$rslt"
)
 }

 # Fonction qui fait la moyenne des cellules dans l'intervalle donnée grace aux parametres
 # Retourne le resultat si c'est bon sinon Ptit ERROR
 # prend 2 param une cel de debut et une cel de fin
function moyenne(){
(
     rslt=0
     cpt=0
     ligne1=`lCel "$1"`
     ligne2=`lCel "$2"`
     Col1=`cCel "$1"`
     Col2=`cCel "$2"`
     
     ! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Error de ligne" && exit 1

     while [[ "$ligne1" -le "$ligne2" ]]
     do
         if [[ "$ligne1" -eq "$ligne2" ]]
         then
             while [[ "$Col1" -le "$Col2" ]]
             do
                 rslt=`+ "$rslt" \`val l"$ligne1"c"$Col1"\``
                 Col1=$(($Col1 + 1))
                 cpt=$(($cpt + 1))
             done
         else
            while [[ "$Col1" -le "$nbColonne" ]]
            do
                rslt=`+ "$rslt" \`val l"$ligne1"c"$Col1"\``
                Col1=$(($Col1 + 1))
                cpt=$(($cpt + 1))
            done
        fi
        Col1=1
        ligne1=$(($ligne1 + 1))
    done
    echo `/ "$rslt" "$cpt"`
)
}

# Fonction qui calcul la variance des cellules qui sont dans l'intervalles donnée grace aux parametres
# Retourne le resultat si ca va sinon ERROR
# Prend 2 params une cellule debut et une cellule de function
function variance(){
(
    rslt=0
    sous=0
    carre=0
    cpt=0
    ligne1=`lCel "$1"`
    ligne2=`lCel "$2"`
    Col1=`cCel "$1"`
    Col2=`cCel "$2"`

    ! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Error de ligne" && exit 1

    local moyenne=`moyenne "$1" "$2"`

    test `estNombre "$moyenne"` = "0" && echo "ErrOr Cheh" && exit 1

    while [[ "$ligne1" -le "$ligne2" ]]
    do
        if [[ "$ligne1" -eq "$ligne2" ]]
        then
            while [[ "$Col1" -le "$Col2" ]]
            do
                sous=`- \`val l"$ligne1"c"$Col1"\` "$moyenne"`
                carre=`echo "$sous ^ 2" | bc -l`
                rslt=`echo "$rslt + $carre" | bc -l`
                Col1=$(($Col1 + 1))
                cpt=$(($cpt + 1))
            done
        else
            while [[ "$Col1" -le "$nbColonne" ]]
            do
                sous=`- \`val l"$ligne1"c"$Col1"\` "$moyenne"`
                carre=`echo "$sous ^ 2" | bc -l`
                rslt=`echo "$rslt + $carre" | bc -l`
                Col1=$(($Col1 + 1))
                cpt=$(($cpt + 1))
            done
        fi
        Col1=1
        ligne1=$(($ligne1 + 1))
    done
    echo `echo "scale=3; $rslt / $cpt" | bc -l`
)
}

# Fonction qui calcul l'ecart type grace a la variance.
# Retourne le rslt si c'est valide sinon error grace a la variance
# Prend 2 param une cellule de debut et une cellule de fin
function ecarttype()
{
    (
        sqrt "`variance "$1" "$2"`"
    )
}
# Fonction mediane qui calculs la mediane des cel compris en param 1 et 2
# Retourne le rslt si ce sont de bon param sinon ErrOr
# prend 2 param une cel debut et une cel function
function mediane(){
(
#utilisation de tableau
    tab=()
    saveTab=""
    valeur=0
    index=0
    cpt=0
    milieu=0
    SaveIFs="$IFS"
    ligne1=`lCel "$1"`
    ligne2=`lCel "$2"`
    Col1=`cCel "$1"`
    Col2=`cCel "$2"`
    erreur=0

    ! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Error de ligne" && exit 1

    # Récupère dans un tableau les valeurs des cellules dans l'intervalle
	while [[ "$ligne1" -le "$ligne2" ]]
	do
		if [[ "$ligne1" -eq "$ligne2" ]]
		then
			while [[ "$Col1" -le "$Col2" ]]
			do
				valeur=`calcul \`val l"$ligne1"c"$Col1"\``
				test `estNombre "$valeur"` -eq "0" && erreur=1 && break
				tab["$index"]="$valeur"
				Col1=$(($Col1 + 1))
				index=$(($index + 1))
			done
		else
			while [[ "$Col1" -le "$nbColonne" ]]
			do
				valeur=`calcul \`val l"$ligne1"c"$Col1"\``
				test `estNombre "$valeur"` -eq "0" && erreur=1 && break
				tab["$index"]="$valeur"
				Col1=$(($Col1 + 1))
				index=$(($index + 1))
			done
		fi
		Col1=1
		ligne1=$(($ligne1 + 1))
	done
	index=$(($index + 1))

	if [[ "$erreur" -eq 0 ]]
	then
		# On stock le rslt du tableau trie et separer avec ;
		saveTab=$( echo ${tab[*]} | sed -e 's/ /;/g' | sort -n )

		# on efface le tabl prec (on sait jamais s'il est trop grand pour après)
		unset tab

		# on remet les val dans tab
		IFS=";"
		for i in ${saveTab[0]}
		do
			tab[$cpt]="$i"
			cpt=$(($cpt + 1)) #problème avec ceci à revoir /!\ URGENT ...surement probleme de signe; corrigé ;)
		done
                # On remet l'ifs a la normal
		IFS="$saveIFS"

		milieu=`echo "scale=0; $index / 2" | bc -l`
		#on calcule la mediane
		if [[ `echo "$index % 2" | bc` -eq 0 ]]
		then
			echo "scale=3; (${tab[$milieu]} + ${tab[$(($milieu - 1))]}) / 2.0" | bc -l #probleme avec ceci à revoir /!\ URGENT
		else
			echo ${tab[milieu]}
		fi
	else
		echo "Erreur"
	fi
)
}

 # Fonction revoyant le max entre le paramètre1 et le paramètre2 (les paramètres sont inclus).
 # #Args:
 #   -$1 : chaine1 representation la cellule 1 pour la somme (lxcy).
 #   -$2 : chaine2 representation la cellule 2 pour la somme (lxcy).
 # #Return: max entre deux celulles(incluses) ou Error de ligne car on dépasse la feuille de calcul.
function max(){
(
    maximum=0
    ligne1=`lCel "$1"`
    ligne2=`lCel "$2"`
    Col1=`cCel "$1"`
    Col2=`cCel "$2"`
    erreur=0

   ! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Error de ligne" && exit 1

	valeur=`calcul \`val l"$ligne1"c"$Col1"\``
	maximum="$valeur"
	Col1=$(($Col1 + 1))

	# Compare toutes les valeurs et reaffecte si un max est trouvé. comme un tri en gros.
	while [[ "$ligne1" -le "$ligne2" ]]
	do
		if [[ "$ligne1" -eq "$ligne2" ]]
		then
			while [[ "$Col1" -le "$Col2" ]]
			do
				valeur=`calcul \`val l"$ligne1"c"$Col1"\``
				test `estNombre "$valeur"` -eq "0" && erreur=1 && break
				if [[ `echo "$valeur>$maximum" | bc` -eq 1 ]]
				then
					maximum="$valeur"
    				fi
				Col1=$(($Col1 + 1))
			done
		else
			while [[ "$Col1" -le "$nbColonne" ]]
			do
				valeur=`calcul \`val l"$ligne1"c"$Col1"\``
				test `estNombre "$valeur"` -eq "0" && erreur=1 && break
				if [[ `echo "$valeur>$maximum" | bc` -eq 1 ]]
				then
					maximum="$valeur"
				fi
				Col1=$(($Col1 + 1))
			done
	    fi
    		Col1=1
		ligne1=$(($ligne1 + 1))
		test "$erreur" -eq 1 && break
	done
    	if [[ "$erreur" -eq 0 ]]
	then
		echo "$maximum"
	else
		echo "CHERROR"
	fi
)
}

 # Fonction revoyant le min entre le paramètre1 et le paramètre2 (les paramètres sont inclus).
 # #Args:
 #   -$1 : chaine1 representation la cellule 1 pour la somme (lxcy).
 #   -$2 : chaine2 representation la cellule 2 pour la somme (lxcy).
 # #Return: min entre deux celulles(incluses) ou Error de ligne car on dépasse la feuille de calcul.
function min(){
(
    minimum=0
    ligne1=`lCel "$1"`
    ligne2=`lCel "$2"`
    Col1=`cCel "$1"`
    Col2=`cCel "$2"`
    erreur=0

    ! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Error de ligne" && exit 1

	valeur=`val l"$ligne1"c"$Col1"`
	valeur=`calcul "$valeur"`
	minimum="$valeur"
	Col1=$(($Col1 + 1))

	while [[ "$ligne1" -le "$ligne2" ]]
	do
		if [[ "$ligne1" -eq "$ligne2" ]]
		then
			while test "$Col1" -le "$Col2"
			do
				valeur=`calcul \`val l"$ligne1"c"$Col1"\``
				test `estNombre "$valeur"` -eq "0" && erreur=1 && break
				if [[ `echo "$valeur<$minimum" | bc` -eq 1 ]]
				then
					minimum="$valeur"
    				fi
				Col1=$(($Col1 + 1))
			done
		else
			while test "$Col1" -le "$nbColonne"
			do
				valeur=`calcul \`val l"$ligne1"c"$Col1"\``
				test `estNombre "$valeur"` -eq "0" && erreur=1 && break
				if [[ `echo "$valeur<$minimum" | bc` -eq 1 ]]
				then
					minimum="$valeur"
				fi
				Col1=$(($Col1 + 1))
			done
	    fi
    		Col1=1
		ligne1=$(($ligne1 + 1))
		test "$erreur" -eq 1 && break
	done
    	if [[ "$erreur" -eq 0 ]]
	then
		echo "$minimum"
	else
		echo "CHERROR"
	fi
)
}
# Fonction qui concatene les deux paramètres.
# #Args:
#   -$1 : chaine1
#   -$2 : chaine2
# #Return : $chaine1$chaine2
function concat(){
    echo "$1""$2"
}

# Fonction envoyant la longeur de la chaine en paramètre.
# #Args:
#   -$1 : chaine1
# #Return : taille(int)
function length(){
    echo "${#1}"
}

# Fonction qui remplace dans le paramètre $1 , la sous chaine $2 par $3.
# #Args:
#   -$1 : chaine1
#   -$2 : chaine2
#   -$3 : chaine3
# #Return : chaine
function subsitute(){
    echo ${1//$2/$3}
}

# Fonction renvoyant la taille d'un fichier s'il existe.
# #Args:
#   -$1 : chaine1 (nom fichier)
# #Return : taille en octect ou "FUCKERROR"
function size()
{
(
    resultat=""
    if [[ -f "$1" ]]
    then
        resultat=`ls -l "$1" | cut " " -f5`
        echo "$resultat"
    else
        resultat=`calcul "$1"`
        if [[ -f "$resultat" ]]
        then
            resultat=`ls -l "$resultat" | cut -d " " -f5`
            echo "$resultat"
        else
            echo "FUCKERROR"
        fi
    fi
)
}

# Fonction renvoyant le nombre de ligne du fichier s'il existe.
# #Args:
#   -$1 : chaine1 (nom du fichier)
# #Return : nombre de ligne ou "ERRORTATOR"
function lines(){
(
    resultat=""
    if [[ -f "$1" ]]
    then
    resultat=`wc -l "$1" | cut -d " " -f 1`
    echo "$resultat"
    else
        resultat=`calcul "$1"`
        if [[ -f "$resultat" ]]
        then
            resultat=`wc -l "$resultat" | cut -d " " -f 1`
            echo "$resultat"
        else
            echo "ERRORTATOR"
        fi
    fi
)
}

# Fonction qui execute la commande shell à effectuer.
# #Args:
#   -$1 : chaine1 (commande à faire, exemple : "expr 12 + 12")
# #Return : le retour de la commande shell
function shell(){
    echo `eval "$1"`
}

# Fonction qui execute le display en fonction de ce que veux la variable
# sois inverse l'affichage ou non
# prend deux param une cellule debut et une cellule fin
function display(){
    if [[ "$inverse" -eq 0 ]]
    then
    displayNormal "$1" "$2"
    else
    displayPasNormal "$1" "$2"
    fi
}


##fonction qui execute le display
#display(){
#while (test "$1" != "$2")
#do	res=`val $1`
#	res=`calcul $res`
#	echo -n $res;echo -n $sepColSortie
#       suiv=`nextCel $1` #a creer 
#        set $suiv $2
#done
#res=`val $2`
#res=`calcul $res`
#echo $res
#} #changer pour prevoir une version inversé et non inversé et enregistre dans File.

# Fonction qui calcul chaque cellules de la feuille.
# #Return le résultat des calculs dans le fichier de sortie ou dans le terminal. Si une celulle n'est pas valide son contenu sera comme dans le feuille de calcul.
function normalCalcul()
{
(
	resultat=""
	valeurCellule=""
	lig=1
	col=1
	saveIFS="$IFS"
	IFS="$sepLigDep"
	for ligne in $fichierMere
	do
		ligne="$ligne""$sepColDep"
		IFS="$sepColDep"
		for colonne in $ligne
		do
			celluleActuelle="l""$lig""c""$col"
			if [[ "$colonne" = "" ]]
			then
				echo "Erreur : cellule $celluleActuelle vide" >&2
				if [[ "$col" -ne 1 ]]
				then
					resultat="$resultat""$sepColSortie"
				fi
			elif [[ `echo "$colonne" | cut -d "(" -f 1` = "=display" ]]
			then
				calcul "$colonne"
			else
				valeurCellule=`calcul "$colonne"`
				if [[	"$valeurCellule" = "ERROR" ]]
				then
					echo "Erreur : cellule $celluleActuelle incorrecte" >&2
					valeurCellule="$colonne"
				fi

				if [[ "$col" -eq 1 ]]
				then
					resultat="$resultat""$valeurCellule"
				else
					resultat="$resultat""$sepColSortie""$valeurCellule"
				fi
			fi

			col=$(($col + 1))
		done

		if [[ `expr "$col" - 1` -ne "$nbColonne" ]]
		then
			echo "Le nombre de colonnes n'est pas le même sur toutes les lignes"
			exit 1
		fi

		if [[ "$lig" -ne "$nbLigne" ]]
		then
			resultat="$resultat""$sepLigSortie"
		fi

		col=1
		lig=$(($lig + 1))
		IFS="$sepLigDep"
	done
	IFS="$saveIFS"

	if [[ "$Displaytrue" -eq 1 ]]
	then
		resultat="$display"
	fi

	echo "$resultat"
)
}

# Fonction qui calcul chaque cellules de la feuille dans l'ordre inverse.
# #Return le résultat des calculs dans le fichier de sortie ou dans le terminal. Si une celulle n'est pas valide son contenu sera comme dans le feuille de calcul.
function inverse()
{
(
	res=""
	valeurCellule=""
	l=1
	c=1
	saveIFS="$IFS"

	IFS="$sepLigDep"
	for ligne in $fichierMere
	do
		ligne="$ligne""$sepColDep"
		IFS="$sepColDep"
		for colonne in $ligne
		do
			celluleActuelle="l""$l""c""$c"
			if [[ "$colonne" = "" ]]
			then
				echo "Erreur : cellule $celluleActuelle vide" >&2
				if [[ "$c" -ne 1 ]]
				then
					res="$sepColSortie""$res"
				fi
			elif [[ `echo "$colonne" | cut -d "(" -f 1` = "=display" ]]
			then
				calcul "$colonne"
			else
				valeurCellule=`calcul "$colonne"`

				if [[	"$valeurCellule" = "Erreur" ]]
				then
					echo "Erreur : cellule $celluleActuelle" >&2 && valeurCellule="$colonne"
				fi

				if [[ "$c" -eq 1 ]]
				then
					res="$valeurCellule""$res"
				else
					res="$sepColSortie""$valeurCellule""$res"
				fi
			fi

			c=$(($c + 1))
		done

		if [[ `expr "$c" - 1` -ne "$nbColonne" ]]
		then
			echo "Le nombre de colonnes n'est pas le même sur toutes les lignes"
			exit 1
		fi

		if [[ "$l" -ne "$nbLigne" ]]
		then
			res="$sepLigSortie""$res"
		fi

		c=1
                l=$(($l +1))
		IFS="$sepLigDep"
	done
	IFS="$saveIFS"

	if [[ "$isDisplay" -eq 1 ]]
	then
		res="$display"
	fi

	echo "$res"
)
}

# Fonction qui affiche un ensemble de celulle dans un ordre inverse.
# #Args:
#   -$1 : cellule de départ
#   -$2 : cellule d'arriver
function displayPasNormal()
{
(
	ligne1=`lCel "$1"`
	ligne2=`lCel "$2"`
	Colonne1=`cCel "$1"`
	Colonne2=`cCel "$2"`
        resultatCellule=""
	valeurCellule=""

	! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Erreur" && exit 1
	Displaytrue=1

	while [[ "$ligne1" -le "$ligne2" ]]
	do
		if [[ "$ligne1" -eq "$ligne2" ]]
		then
			while [[ "$Colonne1" -le "$Colonne2" ]]
			do
				valeurCellule=`val l"$ligne1"c"$Colonne1"`

				if [[ "$valeurCellule" = "" ]]
				then
					resultatCellule=""
				else
					resultatCellule=`calcul "$valeurCellule"`
					if [[	"$resultatCellule" = "FUCKITERROR" ]]
					then
						resultatCellule="$valeurCellule"
					fi
				fi

				if [[ "$ConformeDisplay" -eq 1 ]]
				then
					display="$resultatCellule""$display"
				else
					display="$sepColSortie""$resultatCellule""$display"
				fi

				Colonne1=$(($Colonne1 + 1))
				ConformeDisplay=$(($ConformeDisplay + 1))
				if [[ `expr $ConformeDisplay - 1` -eq "$nbColonne" ]]
				then
					if [[ $LigueOfLolDisplay -ne "$nbLigne" ]]
					then
						display="$sepLigSortie""$display"
					fi
					ConformeDisplay=1
					LigueOfLolDisplay=$(($LigueOfLolDisplay + 1))
				fi
			done
		else
			while test "$Colonne1" -le "$nbColonne"
			do
				valeurCellule=`val l"$ligne1"c"$Colonne1"`
				if [[ "$valeurCellule" = "" ]]
				then
					"$resultatCellule"=""
				else
					resultatCellule=`calcul "$valeurCellule"`

					if [[	"$resultatCellule" = "Erreur" ]]
					then
						resultatCellule="$valeurCellule"
					fi
				fi
				if [[ "$ConformeDisplay" -eq 1 ]]
				then
					display="$resultatCellule""$display"
				else
					display="$sepColSortie""$resultatCellule""$display"
				fi

				Colonne1=$(($Colonne1 + 1))
				ConformeDisplay=$(($ConformeDisplay + 1))
				if [[ `expr $ConformeDisplay - 1` -eq "$nbColonne" ]]
				then
					if [[ $ConformeDisplay -ne "$nbLigne" ]]
					then
						display="$sepLigSortie""$display"
					fi
					ConformeDisplay=1
					LigueOfLolDisplay=$(($LigueOfLolDisplay + 1))
				fi
			done
		fi

		Colonne1=1
		ligne1=$(($ligne1 + 1))
	done
)
}
# Fonction qui affiche un ensemble de celulle.
# #Args:
#   -$1 : cellule de départ
#   -$2 : cellule d'arriver
function displayNormal()
{
(
	ligne1=`lCel "$1"`
	ligne2=`lCel "$2"`
        Colonne1=`cCel "$1"`
	Colonne2=`cCel "$2"`
	resultatCellule=""
        valeurCellule=""

	# Si les cellules sont trop loin FUCK IT
	! `passErreur "$ligne1" "$ligne2" "$Col1" "$Col2" ` && echo "Erreur" && exit 1

	Displaytrue=1

	while [[ "$ligne1" -le "$ligne2" ]]
	do
		if [[ "$ligne1" -eq "$ligne2" ]]
		then
			while [[ "$Colonne1" -le "$Colonne2" ]]
			do
				valeurCellule=`val l"$ligne1"c"$Colonne1"`
				if [[ "$valeurCellule" = "" ]]
				then
					resultatCellule=""
				else
					resultatCellule=`calcul "$valeurCellule"`
					if [[ "$resultatCellule" = "Erreur" ]]
					then
						resultatCellule="$valeurCellule"
					fi
				fi
				if [[ "$ConformeDisplay" -eq 1 ]]
				then
					display="$display""$resultatCellule"
				else
					display="$display""$sepColSortie""$resultatCellule"
				fi

				Colonne1=$(($Colonne1 + 1))
				ConformeDisplay=$(($ConformeDisplay + 1))
				if [[ `expr $ConformeDisplay - 1` -eq "$nbColonne" ]]
				then
					if [[ "$LigueOfLolDisplay" -ne "$nbLigne" ]]
					then
						display="$display""$sepLigSortie"
					fi
					ConformeDisplay=1
					LigueOfLolDisplay=$(($LigueOfLolDisplay + 1))
				fi
			done
		else
			while [[ "$Colonne1" -le "$nbColonne" ]]
			do
				valeurCellule=`val l"$ligne1"c"$Colonne1"`
				if [[ "$valeurCellule" = "" ]]
				then
					resultatCellule=""
				else
					resultatCellule=`calcul "$valeurCellule"`
					if [[	"$resultatCellule" = "Erreur" ]]
					then
						echo "Erreur : cellule $celluleActuelle" >&2
						resultatCellule="$valeurCellule"
					fi
				fi
				if [[ "$ConformeDisplay" -eq 1 ]]
				then
					display="$display""$resultatCellule"
				else
					display="$display""$sepColSortie""$resultatCellule"
				fi

				Colonne1=$(($Colonne1 + 1))
				ConformeDisplay=$(($ConformeDisplay + 1))
				if [[ `expr $ConformeDisplay - 1` -eq "$nbColonne" ]]
				then
					if [[ "$LigueOfLolDisplay" -ne "$nbLigne" ]]
					then
						display="$display""$sepLigSortie"
					fi
					ConformeDisplay=1
					LigueOfLolDisplay=$(($LigueOfLolDisplay + 1))
				fi
			done
		fi

		Colonne1=1
		ligne1=$(($ligne1 + 1))
	done
)
}


# Fonction qui analyse les options entrées dans le  programme et vérifie les conditions pour afficher les erreurs
# Arguments : $*
function recupParams()
{

	local tmp=""
	local cInDeja=0
	local lInDeja=0
	local cOutDeja=0
	local lOutDeja=0
	local ligInit=""
	local colInit=""
	local ligSortie=""
	local colSortie=""

	while (test $# -gt 0)
	do
		case $1 in
		"-in")
			shift
			test $# -eq 0 && echo "Argument de in manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^-.+$"`
			test "$tmp" != "" && echo "Argument de in manquant.">&2 && exit 1
			test ! -f "$1" && echo "Le fichier de la feuille de calcul n'existe pas.">&2 && exit 1
			fichierMere="$1"
			shift;;
		"-out")
			shift
			test $# -eq 0 && echo "Argument de out manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^-.+$"`
			test "$tmp" != "" && echo "Argument de out manquant.">&2 && exit 1
			test ! -f "$1" && touch "$1" && sortie="$1"
			shift;;
		"-scin")
			shift
			test $# -eq 0 && echo "Argument de scin manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^-.+$"`
			test "$tmp" != "" && echo "Argument de scin manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^[^0-9a-zA-Z^*/+-~]$"`
			test "$tmp" = "" && echo "Erreur : le séparateur de scin ne doit contenir qu'un seul caractère. (Pas une lettre ni un chiffre ni +, -, ^, /, *, et ~">&2 && exit 1
			test "$lInDeja" -eq 1 && test "$ligInit" = "$1" && echo "Le séparateur scin \"$ligInit\" est le même que le séparateur slin.">&2 && exit 1
			cInDeja=1 && colInit="$1"
			shift;;
		"-scout")
			shift
			test $# -eq 0 && echo "Argument de scout manquant.">&2 && exit 1
			local tmp=`echo "$1" | grep -E "^-.+$"`
			test "$tmp" != "" && echo "Argument de scout manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^[^0-9a-zA-Z^*/+-~]$"`
			test "$tmp" = "" && echo "Erreur : le séparateur de slin ne doit contenir qu'un seul caractère. (Pas une lettre ni un chiffre ni +, -, ^, /, *, et ~">&2 && exit 1
			test "$lOutDeja" -eq 1 && test "$ligSortie" = "$1" && echo "Le séparateur scout \"$colSortie\" est le même que le séparateur slout.">&2 && exit 1
			cOutDeja=1 && colSortie="$1"
			shift;;
		"-slout")
			shift
			test $# -eq 0 && echo "Argument de slout manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^-.+$"`
			test "$tmp" != "" && echo "Argument de slout manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^[^0-9a-zA-Z^*/+-~]$"`
			test "$tmp" = "" && echo "Erreur : le séparateur de slin ne doit contenir qu'un seul caractère. (Pas une lettre ni un chiffre ni +, -, ^, /, *, et ~">&2 && exit 1
			test "$cOutDeja" -eq 1 && test "$colSortie" = "$1" && echo "Le séparateur slout \"$colSortie\" est le même que le séparateur scout.">&2 && exit 1
			lOutDeja=1 && ligSortie="$1"
			shift;;
		"-slin")
			shift
			test $# -eq 0 && echo "Argument de slin manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^-.+$"`
			test "$tmp" != "" && echo "Argument de slin manquant.">&2 && exit 1
			local tmp=`echo -n "$1" | grep -E "^[^0-9a-zA-Z^*/+-~]$"`
			test "$tmp" = "" && echo "Erreur : le séparateur de slin ne doit contenir qu'un seul caractère. (Pas une lettre ni un chiffre ni +, -, ^, /, *, et ~">&2 && exit 1
			test "$cInDeja" -eq 1 && test "$colInit" = "$1" && echo "Le séparateur scin \"$colInit\" est le même que le séparateur slin.">&2 && exit 1
			lInDeja=1 && ligInit="$1"
			shift;;
		"-inverse")
			shift
			inverse=1;;
		*)
                        echo "$1 : Paramètre non valide.">&2 && exit 1;;
		esac
	done

	test "$lInDeja" -eq 1 && sepLigDep="$ligInit"
	test "$cInDeja" -eq 1 && sepColDep="$colInit"
	test "$lOutDeja" -eq 1 && sepLigSortie="$ligSortie"
	test "$cOutDeja" -eq 1 && sepColSortie="$colSortie"
	test "$sepColSortie" = "" && sepColSortie="$sepColDep"
	test "$sepLigSortie" = "" && sepLigSortie="$sepLigDep"
	fichierMere=`cat $fichierMere`
	if [[ "$fichierMere" = "" ]]
	then
		echo "Le fichier fichierMere est vide"
		exit 1
	fi
	echo
}

# Fonction pincipal du programme.
# Args : tout ;D
function main()
{
	local saveIFS="$IFS"
	fichierMere="" && sortie=""
	erreurRetour=""
	sepColDep=$'\t' && sepLigDep=$'\n'
	sepColSortie="" && sepLigSortie=""
	nbLigne=0 && nbColonne=0
	LigueOfLolDisplay=1 && ConformeDisplay=1 #ligne et colonne ;)
	inverse=0
	display=""
	Displaytrue=0
	celluleActuelle=""
	local testSep=""


	recupParams $@	

	# Changement du séparateur '\t' en "🄯"(copyleft) pour compter le nombre de lignes et colonnes.
        # utilisation de 🄯 car quasiment non utilisé dans le monde XD bon finalement ça sera ~ (car copyleft c'est sur 2 octect et cut n'en veut pas alors ... ).
	test "$sepColDep" = $'\t' && sepColDep='\t' && fichierMere=`echo -n "$fichierMere" | sed "s/$sepColDep/~/g"` && sepColDep='~'

	IFS="$sepLigDep"
	for ligne in $fichierMere
	do
		nbLigne=$(($nbLigne + 1))
		if [[ "$nbLigne" -eq 1 ]];then
			IFS="$sepColDep"
			ligne="$ligne""$sepColDep"
			for colonne in $ligne
			do
				nbColonne=$(($nbColonne + 1))
			done
			IFS="$sepLigDep"
		fi
	done
	IFS="$saveIFS"

	# Calcul des calculs depend de si option inverse entré ;D
	if [[ "$inverse" -eq 0 ]]
	then
		if [[ "$sortie" = "" ]];then
			normalCalcul
		else
			normalCalcul > $sortie
		fi
	else
		if [[ "$sortie" = "" ]];then
			inverse
		else
			inverse > $sortie
		fi
	fi

	echo ""
	local IFS="$saveIFS" #restaure en local ;)
}


main $@

