#!/bin/sh
j=0
for nb in `ls strat/`
do
  j=`expr $j + 1`
done
return $j
