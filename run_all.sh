#!/bin/bash

source /afs/cern.ch/work/h/hselyuzh/public/peter/set49_local.sh

root -l <<EOF
.L NA49calculator.C++
.x run.C(0)
EOF