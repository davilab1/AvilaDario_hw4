

Resultados_hw4.pdf:Plots_hww4.py ode.out pde.out Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
	xdg-open Resultados_hw4.pdf

posxtiempo.pdf posxtiempo2.pdf c1g1inial.pdf c1g2inter.pdf c1g3inter.pdf c1g4equi.pdf c1g5prom.pdf  c2g1inial.pdf c2g2inter.pdf c2g3inter.pdf c2g4equi.pdf c2g5prom.pdf c3g1inial.pdf c3g2inter.pdf c3g3inter.pdf c3g4equi.pdf c3g5prom.pdf:Plots_hww4.py datos1.dat datos2.dat datos3.dat
	python3 Plots_hww4.py

datos1.dat: ode.out
	./ode.out > datos1.dat

datos2.dat: ode.out
	./ode.out > datos2.dat

ode.out: ODE.cpp
	g++ ODE.cpp

datos3.dat: pde.out
	./pde.out > datos3.dat

pde.out: PDE.cpp
	g++ PDE.cpp
