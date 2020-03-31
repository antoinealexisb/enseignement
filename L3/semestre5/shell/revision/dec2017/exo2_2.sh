#!/bin/bash
! test -d "$1" && echo "Merci de mettre un chemin de dossier valide" && exit 1
#test est une commade d'après "La programmation "shell"" version 2.1 de frédéric lang page 31
sortie=""
(
#oldIFS=$IFS
#IFS=""
for i in "$1"/*
do
  poubelle=`source exo1_1.sh "$i" "$2"`
  if [ $? -eq 0 ]
  then
    sortie=`echo "$sortie\`basename "$i"\`-->$poubelle"`
    sortie="$sortie
"
  fi
done
#echo "$sortie"
echo "$sortie" |sort -r -n -t '>' -k2
#IFS=$oldIFS
)
