#!/bin/bash

ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`); ./push_swap $ARG | tee >(wc -l) | ./checker $ARG
