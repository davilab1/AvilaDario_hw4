

Resultados_hw4.pdf:Plots_hww4.py ODE.out PDE.out Resultados_hw4.tex posxtiempo.pdf posxtiempo2.pdf c1g1inial.pdf c1g2inter.pdf c1g3inter.pdf c1g4equi.pdf c1g5prom.pdf  c2g1inial.pdf c2g2inter.pdf c2g3inter.pdf c2g4equi.pdf c2g5prom.pdf c3g1inial.pdf c3g2inter.pdf c3g3inter.pdf c3g4equi.pdf c3g5prom.pdf
	pdflatex Resultados_hw4.tex
	xdg-open Resultados_hw4.pdf

posxtiempo.pdf posxtiempo2.pdf c1g1inial.pdf c1g2inter.pdf c1g3inter.pdf c1g4equi.pdf c1g5prom.pdf  c2g1inial.pdf c2g2inter.pdf c2g3inter.pdf c2g4equi.pdf c2g5prom.pdf c3g1inial.pdf c3g2inter.pdf c3g3inter.pdf c3g4equi.pdf c3g5prom.pdf:Plots_hw4.py datosODE1.dat datosODE2.dat datosPDEC11.dat datosPDEC12.dat datosPDEC13.dat datosPDEC14.dat datosPDEC15.dat datosPDEC21.dat datosPDEC22.dat datosPDEC23.dat datosPDEC24.dat datosPDEC25.dat datosPDEC21.dat datosPDEC31.dat datosPDEC32.dat datosPDEC33.dat datosPDEC34.dat datosPDEC35.dat
	python3 Plots_hw4.py

datosODE1.dat datosODE2.dat: ODE.out
	./ODE.out

ODE.out: ODE.cpp
	g++ -o ODE.out ODE.cpp

datosPDEC11.dat datosPDEC12.dat datosPDEC13.dat datosPDEC14.dat datosPDEC15.dat datosPDEC21.dat datosPDEC22.dat datosPDEC23.dat datosPDEC24.dat datosPDEC25.dat datosPDEC21.dat datosPDEC31.dat datosPDEC32.dat datosPDEC33.dat datosPDEC34.dat datosPDEC35.dat : PDE.out
	./PDE.out

PDE.out: PDE.cpp
	g++  -o PDE.out PDE.cpp
