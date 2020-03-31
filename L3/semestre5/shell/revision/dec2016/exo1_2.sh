#!/bin/sh
test "$#" -gt 3 && echo "Le nombre d'arguments est trop élevé !!!!!!!!!" && exit 1
test "$#" -lt 2 && echo "Pas assez d'arguments !!!!!!!!!" && exit 2

oldIFS=$IFS
IFS=""
if [ "$#" -eq 2 ]
  then
    fichier=""
    until `test -e "$fichier"`
    do
    echo "Merci de mettre le nom du fichier motherfucker !"
    read fichier
    done
    truc1=$1
    truc2=$2
    set -- $1 $2 $fichier
fi

if ! [ -e "$3" ]
  then
    echo "Merci de recommencer avec un nom de fichier valide, sur ceux Au REVOIR" && IFS=$oldIFS && exit 3
fi
IFS=$oldIFS

rien=`echo $1 |grep -E ^\[0-9\]+\$`
if [ $? -ne 0 ]
  then
    echo "Merci de recommencer avec un nombre en premier param." && exit 4
fi
rien=`echo $2 |grep -E ^\[0-9\]+\$`
if [ $? -ne 0 ]
  then
    echo "Merci de recommencer avec un nombre en deuxième param." && exit 5
fi

if [ $1 -gt $2 ]
  then
    echo "Merci de bien vouloir donner des lignes valides avec param1 <= param2, Au revoir alors ;)" && exit 6
fi

nblignes=`wc -l "$3"| cut -d ' ' -f1`

if [ $1 -gt $nblignes ]
  then
  exit 0
fi

i=$1
while test $i -ne `expr $2 + 1`
do
  sed -n "$i"p "$3" #-n Supprimer l'affichage automatique de l'espace de travail. et p imprime la ligne
  i=$(($i + 1))
done

