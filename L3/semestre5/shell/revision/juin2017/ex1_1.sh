#!/bin/sh

exo1_1()
{
  ! test "$#" -eq 2 && echo "Le nombre de paramètre n'est pas correct !" && exit 1
  ! test `expr "$1" : ".*"` -eq 1 && echo "Paramètre 1 non valide, il faut UN caractère !" && exit 2
rien=`echo $1 |grep -E ^\[^0-9\\]\$` #tout caractère sauf chiffre
#grep -E ^\[a-Z\]\$` seulement de a-Z
  ! test $? -eq 0 && echo "Merci de mettre un caractère et non un chiffre ou autre. !" && exit 2
  ! test -f "$2" && echo "Paramètre 2 non valide, mettez un fichier ! " && exit 3

  cat "$2" |sed "s/$1/$1$1/g"
  return 0
}

exo1_1 $1 $2
