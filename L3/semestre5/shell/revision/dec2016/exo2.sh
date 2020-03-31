#!/bin/sh
test "$#" -gt 1 && echo "Le nombre d'arguments est trop élevé !!!!!!!!!" && exit 1
test "$#" -eq 0 && echo "Pas assez d'argument !!!!!!!" && exit 2
#1er param c'est une aborescence dont la racine est donnée donc cd / pour ensuite vérifier 
#si le chemin donnée en param existe 
cd /

if ! [ -d "$1" ]
then
  echo "Merci de mettre un paramètre valide (celui-ci doit etre un chemin vers un dossier contenant la racine)" && exit 3
fi
#copy IFS
oldIFS=$IFS
IFS='

'
#find pour trouver les liens symbolique du dossier courant (car sujet ecrit pour l'exemple "
# si la recherche est lancée dans le répertoire /home/..." donc le param1 est juste un dossier
# à analyser )
truc=`find $1 -maxdepth 1 -type l`

#parcours l'ensemble des liens symboliques
for i in $truc
do
  #IFS=$oldIFS
  #chat c'est pour avoir sur quoi pointe le lien symbolique. bon si le nom à un espace c'est chiant mais flemme de refléchir pour resoudre ça.
  chat=`ls -l $i |rev |cut -d ' ' -f 1 |rev`
  #ici regarder si le lien symbolique est dans le chemin de param1 (probleme si lien symbolique
  # est ../../ pour regler ça faire un cd pour etre au niveau $1 et ensuite cd $chat et 
  #verifier avec pwd [j'ai la flemme][bon finalement je l'ai fais])
  truc=`echo "$1" | grep "$chat"`
  #echo "$truc"
  if [ $? -eq 0 ]
  then
    echo "$i provoque un cycle dans l'arborescence."
  fi
  echo "$chat"
  truc=`echo "$chat" |grep "\.\."`
  if [ $? -eq 0 ]
  then
    cd "$1"
    cd "$chat"
    truc=`pwd`
    truc=`echo "$1" | grep "$truc"`
    if [ $? -eq 0 ]
    then
      echo "$i provoque un cycle dans l'arborescence."
    fi
  fi
done

IFS=$oldIFS
