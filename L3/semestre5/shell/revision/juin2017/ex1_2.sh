#!/bin/bash
! test "$#" -gt 1 && echo "Pas assez de paramètres" && exit 1

namefile=$1
echo -n "" > $1
shift

oldIFS=$IFS
IFS='

'
emplacement=`pwd`

archive()
{
while test $# -ne 0
do
  if [ -f "$1" ]
  then
    echo "#!$1#!">>"$namefile"
    exo1_1 \# "$1">>"$namefile"
    elif [ -d "$1" ]
    then
      dirfiles=`find "$1" -maxdepth 1 -type f`
      for i in "$dirfiles"
      do
        archive $i
      done
    else
    echo "$1 n'est pas un fichier valide."
  fi
  shift
done
}

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

archive $@
