#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
g++ -O2 -g -pg -fno-inline -fno-optimize-sibling-calls -std=c++14 codigo/main.cpp codigo/genetico.cpp -o diagnostico
printf 'n\nn\n' | ./diagnostico > dados/saida_diagnostico.txt
mv gmon.out dados/gmon_diagnostico.out
gprof -b diagnostico dados/gmon_diagnostico.out > dados/gprof_diagnostico.txt
g++ -O2 -g -pg -fno-ipa-icf -std=c++14 codigo/main.cpp codigo/genetico.cpp -o instrumentado_sem_icf
for i in 1 2 3 4 5; do
  printf 'n\nn\n' | ./instrumentado_sem_icf > "dados/saida_icf_$i.txt"
  mv gmon.out "dados/gmon_icf_$i.out"
done
gprof -b instrumentado_sem_icf dados/gmon_icf_1.out > dados/gprof_sem_icf.txt
