#!/usr/bin/env python3
import pandas as pd
import matplotlib.pyplot as plt

merge_times = pd.read_csv('Merge.txt',header=None)
#merge_times = merge_times[::-1]

insert_times = pd.read_csv('Insert.txt',header=None)
#insert_times = insert_times[::-1]
Sizes = pd.read_csv('Sizes.txt',header=None)
# Crear el gráfic0

plt.plot(Sizes, merge_times, label='Merge Sort')
plt.plot(Sizes ,insert_times, label='Insertion Sort')
plt.xlabel('Tamaño de la lista')
plt.ylabel('Tiempo de ejecución (segundos)')
plt.legend()
plt.show()
