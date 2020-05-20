#include<stdlib.h>
#include<ctime>
#include<cmath>
#include<cstddef>
#include<iterator>
#include<algorithm> 
#include<fstream>
#include<chrono>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<fstream>
#include <sstream>
#include"tda.h"
#include"initial.h"
#include"basic.h"
#include"cost.h"
#include"permutations.h"
#include"greedyfix.h"




int ReadNumbers( const string & s, vector<int> & v) {
    istringstream is( s );
    double n;
    while( is >> n ) {
        v.push_back( n );
    }
    return v.size();
}

//fuente: https://www.quora.com/How-do-I-read-a-matrix-from-a-file-in-C++
vector<vector<double>> distanceMatrix(string arch){

    ifstream File; 
    vector<vector<double>> d;

    std::string line;
    vector<int> v;

    File.open(arch);
    if (File.is_open()){
        int i=0;
        getline(File, line);
        n =ReadNumbers(line, v);
        cout << "N:" << n << endl;
        for ( i=1;i<32767;i++){
            if (!getline(File, line)) break;//TODO: OJO CON EL COMPILADOR ACÁ!!!!!!!!!
            ReadNumbers( line, v );
            
        }
        File.close();
    }
    else{
        cout << "file open failed";
    }
    for (int i=0;i<n;i++){
        vector<double> row;
        for (double j=0;j<n;j++){
            row.push_back(v[i*n+j]);
            //cout<<v[i*n+j]<<"\t"
        }
        //cout << endl;
        d.push_back(row);
    }
    return d;
}


int main(int argc ,char* argv[]){
    cout<<argv[1]<<endl;
    string f=string(argv[1]);
    string arch="instancias/"+string(argv[1]);

    D=distanceMatrix(arch);
    double bestDist=INFINITY;
    double worstDist=-1;
    double meanEvaluation=0;
    srand(0);
    int total_success=0;
    int iterations=1000;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<iterations;i++){
        //ojo: al contrario de la representación indicada en el informe, acá las columnas representan a los equipos (la razón tiene que ver con que los movimientos serán más eficientes, considerando que C++ no trabaja con columnas)
        vector<vector<int>> M=DoubleRoundRobin();

        int success=greedyFix(M);
        double d=scheduleDistance(M);
        //cout<<"torneo resultante: "<<endl; printTournament(M);
        //cout<<"distancia total de viajes de torneo: "<<d<<endl; 
        if(success){
            if(d<bestDist)bestDist=d;
            if(d>worstDist)worstDist=d;
            meanEvaluation+=d;
            //cout<<"torneo factible"<<endl;
        }
        //else cout<<"torneo no factible"<<endl;
        
        total_success+=success;

    }
    meanEvaluation/=total_success;
    cout<<"numero total de soluciones factibles: "<<total_success<<endl;
    cout<<"mejor función de evaluación obtenida: "<<bestDist<<endl;
    cout<<"peor función de evaluación obtenida: "<<worstDist<<endl;
    cout<<"promedio de funciones de evaluaciones (factibles) obtenidas: "<<meanEvaluation<<endl;
    //vector<vector<int>> M2=randomSchedule();
    //printMatrix(M1);
    //printMatrix(M2);
    auto stop = chrono::high_resolution_clock::now(); 
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cout<<"tiempo de ejecucion:"<<duration.count()/1000000.0<<" segundos";
    return 0;
}
