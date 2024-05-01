#!/bin/bash

EXPECTED=2
if [[ $# -lt $EXPECTED ]]; then
    echo "USAGE: Provide number of threads and binary"
    echo "$# Arguments provided, expected $EXPECTED"
    echo ">Aborting<"
    exit 2
fi

export OMP_NUM_THREADS=$1
export OMP_DISPLAY_AFFINITY=true
export OMP_DISPLAY_ENV=true
export OMP_AFFINITY_FORMAT='(%i) %n @ %L -> %A'
export OMP_PLACES=cores,threads
export OMP_PROC_BIND=true

#RUN
${@:2}
