#!/bin/bash
test "$#" -ne 1 && echo "Merci de mettre un seul paramètre" && exit 1
! test -d "$1" && echo "le paramètre 1 doit être un dossier" && exit 1

oldIFS=$IFS
IFS=""

chemabsolu=`source exo1_2.sh $1`
find "$1" -maxdepth 1 -type l |while read fic
do
  chemSy=`source exo1_1.sh $fic`
  if [ $? -eq 0 ]
  then
    truc=`source exo1_3.sh $chemSy $chemabsolu`
    test "$?" -eq 0 && echo "$fic est un cycle."
  fi
done
IFS=$oldIFS
exit 0
