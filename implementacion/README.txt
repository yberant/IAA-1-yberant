Instrucciones de ejecución:

Existen dos archivos c++, "main.cpp" y "onlyone.cpp": 
-main.cpp: es el archivo que se usó para el experimento del informe, en el que se generan 1000 soluciones/torneos.
-onlyone.cpp: sirve para generar, como indica su nombre, solo un torneo, el cual se imprime en pantalla junto con sus datos.

Comandos de makefile: Desde la carpeta implementaciónIAA-1, ejecutar:
	- make compile: para compilar main.cpp
	- make run f=*nombre de archivo instancia*: para correr main.cpp, tomando como parámetro una instancia. Por ejemplo, "make run f=NL6.txt" corre main.cpp usando la instancia NL6.txt.
	- make all f=*nombre de archivo instancia*: para compilar y correr main.cpp.
	- make onlyOneCompile: para compilar onlyone.cpp.
	- make onlyOneRun f=*nombre de archivo instancia* seed=*numero de semilla*. Por ejemplo, "make onlyOneRun f=NL6.txt seed=10" corre onlyOneRun usando la instancia NL6.txt y una semilla de valor 10.
		

		
Indicaciones:

1. No es necesario especificar el directorio en el nombre de archivo, solo poner "NL4.txt", por ejemplo. Lo importante es que las instancias deben estar en la carpeta "instancias", la cual debe estar en el mismo directorio en que se ejecute el programa.
2. Para cambiar la cantidad de soluciones generadas en main.cpp, hay que cambiar el valor del valor "iterations", en la linea 83 de main.cpp
3. En main.cpp, Para que se imprima en pantalla información relevante en relación a los torneos generados, se pueden "descomentar" los prints que se encuentran en las lineas 91, 92, 97 y 99 de main.cpp (cuidado con el número de soluciones, inicialmente se estarían imprimiendo 1000 torneos. Se puede cambiar este número modificando el valor de iterations(ver indicación 2)).
4. Además de las carpetas, los archivos.h y .cpp también deben estar en el mismo directorio.
