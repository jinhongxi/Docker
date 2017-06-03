# 
#  This file is part of the course materials for AMATH483/583 at the University of Washington,
#  Spring 2017
# 
#  Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
#  https://creativecommons.org/licenses/by-nc-sa/4.0/
# 
#  Author: Andrew Lumsdaine
# 

import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

import csv
import sys

names = []

plt.figure(figsize=(9,4))

for name in sys.argv[1:]:

    names.append(name)

    infile = name + '.txt'

    print ('plotting ' + infile)

    with open(infile, 'rb') as csvfile:
        Ns = []
        Flops = []
        
        reader = csv.DictReader(csvfile, delimiter='\t')
    
        for row in reader:
            Ns.append(int(row['N']))
            Flops.append(float(row['Flops'])/1.e9)
        

        plt.semilogx(Ns, Flops)


pp = PdfPages('matplots.pdf');


plt.axis([0, 4096, .01, 15])
plt.legend(names, loc='upper left', fontsize='small')
plt.title('Matrix Matrix Product Performance')
plt.xlabel('Matrix Dimension')
plt.ylabel('GFlops')
plt.xticks([8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096] , [8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096])

pp.savefig()
pp.close();
# plt.show()
