#!/bin/bash

#STARTED=$(stat -c '%w' ../libft | cut -c -16)
NBRDONE=$(grep -c "DONE" subject)
DIFF=$(bc <<< "43 - ${NBRDONE}")
PERCENT=$(bc -l <<< "(${NBRDONE} / 43) * 100" | cut -c -5)


function progressbar()
{
    echo -n "Progress|"
    for ((i=0;i<44;i++)) 
    do
      if [ $i -lt $1 ] ; then
        echo -n "█"
      else
        echo -n "-"
      fi
    done
    echo "|$2% Completed"
}

printf "\n"
#echo "Project started : $STARTED"
progressbar "${NBRDONE}" "$PERCENT"
echo "                            ${NBRDONE}/43 Done"
echo "-- ${DIFF} tasks  remaining ! --"
