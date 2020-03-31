#!/bin/bash
test "$#" -ne 1 && echo "Merci de mettre un argument " && exit 1 

oldIFS=$IFS
IFS=""

exo1_2()
{
  if ! [ -e "$1" ]
  then
    return 1
  fi
  cd `dirname $1`
  echo "`pwd`/`basename $1`"
  IFS=$oldIFS
}

exo1_2 $@
