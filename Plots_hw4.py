import numpy as np
import matplotlib.pylab as plt
import math


datosODE1=np.genfromtxt("datos1.dat",delimiter=",")

datosODE2=np.genfromtxt("datos2.dat",delimiter=",")

pos1=datosODE1[:,0]
vel1=datosODE1[:,1]
t1=datosODE1[:,2]

t2=datosODE2[:,0]
p1=datosODE2[:,1]
v1=datosODE2[:,2]
p2=datosODE2[:,3]
v2=datosODE2[:,4]
p3=datosODE2[:,5]
v3=datosODE2[:,6]
p4=datosODE2[:,7]
v4=datosODE2[:,8]
p5=datosODE2[:,9]
v5=datosODE2[:,10]
p6=datosODE2[:,11]
v6=datosODE2[:,12]
p7=datosODE2[:,13]
v7=datosODE2[:,14]



datosPDE1=np.genfromtxt("datos3.dat",delimiter=",")
