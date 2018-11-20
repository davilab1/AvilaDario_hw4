import numpy as np
import matplotlib.pylab as plt
import math
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D


datosODE1=np.genfromtxt("datosODE1.dat",delimiter=",")

time1=datosODE1[:,0]
posx=datosODE1[:,1]
posy=datosODE1[:,2]
velx=datosODE1[:,3]
vely=datosODE1[:,4]


plt.figure()
plt.plot(posx,posy,label="45")
plt.title('Trayectoria para 45 grados')
plt.xlabel('x')
plt.ylabel('y')
plt.ylim(0,3)
#plt.show())
plt.savefig("posxtiempo.pdf")

datosODE2=np.genfromtxt("datosODE2.dat",delimiter=",")

#t1=datosODE2[:,0]
p1x=datosODE2[1:1800,1]
p1y=datosODE2[1:1800,2]
#v1x=datosODE2[:,3]
#v1y=datosODE2[:,4]

#t2=datosODE2[:,5]
p2x=datosODE2[1801:3600,1]
p2y=datosODE2[1801:3600:,2]
#v2x=datosODE2[:,8]
#v2y=datosODE2[:,9]

#t3=datosODE2[:,10]
p3x=datosODE2[3601:5400,1]
p3y=datosODE2[3601:5400,2]
#v3x=datosODE2[:,13]
#v3y=datosODE2[:,14]

#t4=datosODE2[:,15]
p4x=datosODE2[5401:7200,1]
p4y=datosODE2[5401:7200,2]
#v4x=datosODE2[:,18]
#v4y=datosODE2[:,19]

#t5=datosODE2[:,20]
p5x=datosODE2[7201:9000,1]
p5y=datosODE2[7201:9000,2]
#v5x=datosODE2[:,23]
#v5y=datosODE2[:,24]

#t6=datosODE2[:,25]
p6x=datosODE2[9001:10800,1]
p6y=datosODE2[9001:10800,2]
#v6x=datosODE2[:,28]
#v6y=datosODE2[:,29]

#t7=datosODE2[:,30]
p7x=datosODE2[10801:12600,1]
p7y=datosODE2[10801:12600,2]
#v7x=datosODE2[:,33]
#v7y=datosODE2[:,34]

plt.figure()
plt.plot(abs(p1x),(p1y),label="10")
plt.plot(abs(p2x),(p2y),label="20")
plt.plot(abs(p3x),(p3y),label="30")
plt.plot(abs(p4x),(p4y),label="40")
plt.plot(abs(posx),(posy),label="45")
plt.plot(abs(p5x),(p5y),label="50")
plt.plot(abs(p6x),(p6y),label="60")
plt.plot(abs(p7x),(p7y),label="70")
plt.xlim(0,5)
plt.ylim(0,4)
plt.title('Variacion en angulos')
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.legend(loc="best")
#plt.show()

plt.savefig("posxtiempo2.pdf")



#---------------------------------------------------------------------------#---------------------------------------------------------------------------

#PDE 3D
#Guia para elaboracion de correctas grafics en 3D https://jakevdp.github.io/PythonDataScienceHandbook/04.12-three-dimensional-plotting.html

xP=np.linspace(0,50,50)
yP=np.linspace(0,50,50)
x,y = np.meshgrid(xP,yP, sparse=True)


#caso 1
datosC11=np.genfromtxt("datosPDEC11.dat")
#print(datosC11)
fig=plt.figure()
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC11,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Condiciones iniciales Caso 1")
plt.savefig("c1g1inial.pdf")


fig=plt.figure()
datosC12=np.genfromtxt("datosPDEC12.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,abs(datosC12),antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado Intermedio Caso 1")
plt.savefig("c1g2inter.pdf")


fig=plt.figure()
datosC13=np.genfromtxt("datosPDEC13.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,abs(datosC13),antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado Intermedio 2 Caso 1" )
plt.legend(loc="best")
plt.savefig("c1g3inter.pdf")

fig=plt.figure()
datosC14=np.genfromtxt("datosPDEC14.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,abs(datosC14),antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado final Caso 1 ")

plt.savefig("c1g4equi.pdf")
plt.show()
'''
plt.figure()
datosC15=np.genfromtxt("datosPDEC14.dat")
plt.plot()
plt.title("Temperatura promedio Caso 3")
plt.legend(loc="best")
#plt.savefig("c1g5prom.pdf")'''

#----------------------------------------------------------------------#--------------------------------------------------------------------------------
#caso 2

datosC21=np.genfromtxt("datosPDEC11.dat")
fig=plt.figure()
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC21,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Condiciones iniciales Caso 2")
plt.savefig("c2g1inial.pdf")

datosC22=np.genfromtxt("datosPDEC22.dat")
fig=plt.figure()
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC22,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado Intermedio-Caso 2")
plt.savefig("c2g2inte.pdf")


datosC23=np.genfromtxt("datosPDEC23.dat")
fig=plt.figure()
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC23,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado Intermedio 2- Caso 2")
plt.savefig("c3g3inter.pdf")


datosC24=np.genfromtxt("datosPDEC24.dat")
fig=plt.figure()
ax =fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC24,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Configuracion de Equilibrio Caso 1")

plt.savefig("c2g4equi.pdf")
'''
plt.figure()
datosC25=np.genfromtxt("datosPDEC25.dat")
plt.plot()
ax.set_zlabel('Temperatura')
plt.title("Temperatura promedio Caso 3")
#plt.savefig("c2g5prom.pdf")'''


#------------------------------------------------------------------------------------------------------------------------------------------------------
#caso 3

fig=plt.figure()
datosC31=np.genfromtxt("datosPDEC11.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC31,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Condiciones iniciales Caso 2")
plt.savefig("c3g1inial.pdf")

fig=plt.figure()
datosC32=np.genfromtxt("datosPDEC32.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC32,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado Intermedio Caso 3")
plt.savefig("c3g2inter.pdf")

fig=plt.figure()
datosC33=np.genfromtxt("datosPDEC33.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC33,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Estado Intermedio 2- Caso 3 ")
plt.savefig("c3g3inter.pdf")

fig=plt.figure()
datosC34=np.genfromtxt("datosPDEC34.dat")
ax = fig.gca(projection='3d')
sup=ax.plot_surface(x,y,datosC34,antialiased=True,cmap="inferno")
fig.colorbar(sup, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Configuracion de Equilibrio Caso 3")
plt.savefig("c3g4equi.pdf")

'''
plt.figure()
datosC35=np.genfromtxt("datosPDEC35.dat")
plt.plot()
plt.title("Temperatura promedio Caso 3")'''
#plt.savefig("c3g5prom.pdf")'''
