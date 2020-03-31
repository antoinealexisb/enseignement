#!/bin/bash
test "$#" -ne 1 && echo "Merci de mettre seulement un argument qui est le fichier à desarchiver !" && exit 1

truc="/dev/null"

cat $1 |while read fic
do
  poubelle=`echo "$fic" |grep -E ^#\!.\*#\!$`
  if [ $? -eq 0 ]
  then
    poubelle=`echo "$poubelle" |sed -E "s/#\!//g"`
    mkdir -p `dirname $poubelle`
    echo -n "" > "$poubelle"
    truc="$poubelle"
  else
    echo `echo "$fic" |sed -E "s/##/#/g"` >> "$truc"
  fi
done
