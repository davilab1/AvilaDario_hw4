import numpy as np
import matplotlib.pylab as plt
import math


datosODE1=np.genfromtxt("datosODE1.dat",delimiter=",")

#datosODE2=np.genfromtxt("datos2.dat",delimiter=",")

time1=datosODE1[:,0]
posx=datosODE1[:,1]
posy=datosODE1[:,2]
velx=datosODE1[:,3]
vely=datosODE1[:,4]


plt.figure()
plt.plot(posx,posy)
plt.title('')
#plt.xlabel()
#plt.ylabel()
plt.legend(loc="best")
plt.show()
#plt.savefig(posxtiempo.pdf")

t1=datosODE2[:,0]
p1x=datosODE2[:,1]
p1y=datosODE2[:,2]
v1x=datosODE2[:,3]
v1y=datosODE2[:,4]

t2=datosODE2[:,5]
p2x=datosODE2[:,6]
p2y=datosODE2[:,7]
v2x=datosODE2[:,8]
v2y=datosODE2[:,9]

t3=datosODE2[:,10]
p3x=datosODE2[:,11]
p3y=datosODE2[:,12]
v3x=datosODE2[:,13]
v3y=datosODE2[:,14]

t4=datosODE2[:,15]
p4x=datosODE2[:,16]
p4y=ydatosODE2[:,17]
v4x=datosODE2[:,18]
v4y=datosODE2[:,19]

t5=datosODE2[:,20]
p5x=datosODE2[:,21]
p5y=datosODE2[:,22]
v5x=datosODE2[:,23]
v5y=datosODE2[:,24]

t6=datosODE2[:,25]
p6x=datosODE2[:,26]
p6y=datosODE2[:,27]
v6x=datosODE2[:,28]
v6y=datosODE2[:,29]

t7=datosODE2[:,30]
p7x=datosODE2[:,31]
p7y=datosODE2[:,32]
v7x=datosODE2[:,33]
v7y=datosODE2[:,34]

plt.figure()
plt.plot(p1x,p1y,label="10")
plt.plot(p2x,p2y,label="20")
plt.plot(p3x,p3y,label="30")
plt.plot(p4x,p4y,label="40")
plt.plot(p5x,p5y,label="50")
plt.plot(p6x,p6y,label="60")
plt.plot(p7x,p7y,label="70")
plt.title('Variacion en angulos')
plt.xlabel("$x$")
plt.ylabel("$y$")
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
