#!/bin/bash
NBRDONE=$(grep -c "DONE" subject)
echo "done ${NBRDONE}/43"

DIFF=$(bc <<< "43 - ${NBRDONE}")
echo "still ${DIFF} left to do"

RESULT=$(bc -l <<< "(${NBRDONE} / 43) * 100")
RESULT=$(echo "${RESULT}" | cut -c -5)
echo "${RESULT}% done"
