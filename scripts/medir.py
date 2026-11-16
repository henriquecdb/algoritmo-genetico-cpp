from pathlib import Path
import subprocess, csv, json, statistics, datetime, hashlib, os
root=Path(__file__).resolve().parents[1]
os.chdir(root)
d=root/'dados'; d.mkdir(exist_ok=True)
def run(args, **kw):
    return subprocess.run(args, check=True, **kw)
env={}
for name,cmd in [('cpu',['lscpu']),('memoria',['free','-b']),('sistema',['uname','-a']),('distribuicao',['cat','/etc/os-release']),('compilador',['g++','--version']),('time',['/usr/bin/time','--version'])]:
    env[name]=subprocess.check_output(cmd,text=True)
env['inicio']=datetime.datetime.now().astimezone().isoformat()
env['flags']='-O2 -g -std=c++14; gprof: acrescenta -pg'
env['sha256']={p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in (root/'codigo').glob('*')}
run(['g++','-O2','-g','-std=c++14','codigo/main.cpp','codigo/genetico.cpp','-o','sequencial'])
run(['g++','-O2','-g','-pg','-std=c++14','codigo/main.cpp','codigo/genetico.cpp','-o','instrumentado'])
rows=[]
for caso,entrada in [('nenhuma','n\nn\n'),('gluten','s\nn\n'),('lactose','n\ns\n'),('ambas','s\ns\n')]:
    (d/f'entrada_{caso}.txt').write_text(entrada)
    run(['./sequencial'],input=entrada,text=True,stdout=subprocess.DEVNULL)
    for i in range(1,11):
        stamp=datetime.datetime.now().astimezone().isoformat()
        with (d/f'saida_{caso}_{i:02}.txt').open('w') as out:
            run(['/usr/bin/time','-f','%e,%U,%S,%M,%F,%R,%c,%w','-o',str(d/f'time_{caso}_{i:02}.txt'),'./sequencial'],input=entrada,text=True,stdout=out)
        vals=(d/f'time_{caso}_{i:02}.txt').read_text().strip().split(',')
        rows.append([caso,i,stamp]+vals)
        print(caso,i,vals[0],flush=True)
with (d/'tempos.csv').open('w',newline='') as f:
    w=csv.writer(f); w.writerow(['cenario','repeticao','inicio','real_s','usuario_s','sistema_s','rss_kib','major_faults','minor_faults','trocas_involuntarias','trocas_voluntarias']); w.writerows(rows)
stats={}
for caso in ['nenhuma','gluten','lactose','ambas']:
    v=[float(r[3]) for r in rows if r[0]==caso]; q=statistics.quantiles(v,n=4,method='inclusive')
    stats[caso]=dict(minimo=min(v),q1=q[0],mediana=statistics.median(v),media=statistics.mean(v),q3=q[2],maximo=max(v),desvio_amostral=statistics.stdev(v))
(d/'estatisticas.json').write_text(json.dumps(stats,indent=2))
for i in range(1,6):
    with (d/f'saida_gprof_{i}.txt').open('w') as out:
        run(['./instrumentado'],input='n\nn\n',text=True,stdout=out)
    Path('gmon.out').rename(d/f'gmon_{i}.out')
    with (d/f'gprof_{i}.txt').open('w') as out:
        run(['gprof','-b','./instrumentado',str(d/f'gmon_{i}.out')],stdout=out)
with (d/'gprof_agregado.txt').open('w') as out:
    run(['gprof','-b','./instrumentado']+[str(d/f'gmon_{i}.out') for i in range(1,6)],stdout=out)
env['fim']=datetime.datetime.now().astimezone().isoformat()
(d/'ambiente.json').write_text(json.dumps(env,indent=2,ensure_ascii=False))
