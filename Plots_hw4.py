import numpy as np
import matplotlib.pylab as plt
import math


datosODE1=np.genfromtxt("datos1.dat",delimiter=",")

datosODE2=np.genfromtxt("datos2.dat",delimiter=",")

posx=datosODE1[:,0]
posy=datosODE1[:,1]
t1=datosODE1[:,2]
vel1=datosODE1[:,3]

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig(posxtiempo.pdf")

t2=datosODE2[:,0]
p1x=datosODE2[:,1]
p1y=datosODE2[:,2]
v1=datosODE2[:,3]
p2x=datosODE2[:,4]
p2y=datosODE2[:,5]
v2=datosODE2[:,6]
p3x=datosODE2[:,7]
p3y=datosODE2[:,8]
v3=datosODE2[:,9]
p4x=datosODE2[:,10]
p4ydatosODE2[:,11]
v4=datosODE2[:,12]
p5x=datosODE2[:,13]
p5y=datosODE2[:,14]
v5=datosODE2[:,15]
p6x=datosODE2[:,16]
p6y=datosODE2[:,17]
v6=datosODE2[:,18]
p7x=datosODE2[:,19]
p7y=datosODE2[:,20]
v7=datosODE2[:,21]

plt.figure()
plt.plot(p1x,p1y,label="10")
plt.plot(p2x,p2y,label="20")
plt.plot(p3x,p3y,label="30")
plt.plot(p4x,p4y,label="40")
plt.plot(p5x,p5y,label="50")
plt.plot(p6x,p6y,label="60")
plt.plot(p7x,p7y,label="70")
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("posxtiempo2.pdf")



datosPDE1=np.genfromtxt("datos3.dat",delimiter=",")
#caso 1
plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c1g1inial.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c1g2inter.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c1g3inter.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c1g4equi.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c1g5prom.pdf")


#caso 2
plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c2g1inial.pdf")


plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c2g2inte.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c3g3inter.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c2g4equi.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
#plt.savefig("c2g5prom.pdf")

#caso 3

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
plt.savefig("c3g1inial.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
plt.savefig("c3g2inter.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
plt.savefig("c3g3inter.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
plt.savefig("c3g4equi.pdf")

plt.figure()
plt.plot()
plt.title('')
plt.xlabel()
plt.ylabel()
plt.legend(loc="best")
plt.savefig("c3g5prom.pdf")
