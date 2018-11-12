


Resultados_hw4.pdf:Plots_hww4.py ode.out pde.out
	python3 Plots_hww4.py

datos1.dat: ode.out
	./ode.out

datos2.dat: ode.out
	./ode.out

ode.out: ODE.cpp
	g++ ODE.cpp

datos3.dat: pde.out
	./pde.out

pde.out: PDE.cpp
	g++ PDE.cpp
