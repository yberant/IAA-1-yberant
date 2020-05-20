//actualiza la información de la mejor solución, en caso de que la solución "candidata" sea mejor que la mejor actuar
bool updateBest(vector<vector<int>> candidateS,vector<vector<int>> & bestS,int & bestConflicts, double & bestDistance){
    int conflicts=totalConflicts(candidateS);
    double distance=scheduleDistance(candidateS);
    if(conflicts<bestConflicts || (conflicts==bestConflicts && distance<bestDistance)){//si el movimiento actual es mejor, se actualiza el mejor
        bestS=candidateS;
        bestConflicts=conflicts;
        bestDistance=distance;
        return true;
    }
    return false;
}

int greedyFix(vector<vector<int>> & S){
    int bestConflicts;
    double bestDistance;
    vector<vector<int>> bestS=S;
    vector<vector<int>> actualS=S;
    bool newFound;
    
    do{
        newFound=false;
        vector<int> bestConflictedRounds;
        vector<int> bestConflictedTeams;
        //actualiza listas de columnas y filas en conflicto
        noRepeatConflicts(bestS,bestConflictedRounds,bestConflictedTeams);
        atMostConflicts(bestS,bestConflictedRounds,bestConflictedTeams);
        bestConflicts=bestConflictedRounds.size()+bestConflictedTeams.size();
        bestDistance=scheduleDistance(S);

        for(auto r: bestConflictedRounds){//busca cambios desde las rondas en conflictos (swaprounds)
            for(int round=0;round<2*(n-1);round++){
                if(round!=r){
                    vector<vector<int>> candidateS=actualS;
                    swapRounds(candidateS,round,r);
                    bool update=updateBest(candidateS,bestS,bestConflicts,bestDistance);
                    if(update){
                        newFound=true;
                        /*
                        double d=scheduleDistance(candidateS);
                        int c=totalConflicts(candidateS);
                        cout<<"se encontró uno mejor, con "<<c<<" conflictos y una distancia de: "<<d<<endl;
                        cout<<"swaprounds: "<<round<<", "<<r<<endl;*/
                        if(bestConflicts==0) break;
                    } 
                }
            }
            if(bestConflicts==0) break;
        }

        for(auto t: bestConflictedTeams){//busca cambios desde los equipos en conflictos (swaprounds)
            for(int team=0;team<n;team++){
                if(team!=t){
                    vector<vector<int>> candidateS=actualS;
                    swapTeams(candidateS,team,t);
                    bool update=updateBest(candidateS,bestS,bestConflicts,bestDistance);
                    if(update){
                        newFound=true;
                        /*double d=scheduleDistance(candidateS);
                        int c=totalConflicts(candidateS);
                        cout<<"se encontró uno mejor, con "<<c<<" conflictos y una distancia de: "<<d<<endl;
                        cout<<"swapteams: "<<team<<", "<<t<<endl;*/
                        if(bestConflicts==0) break;
                    } 
                }
            }
            if(bestConflicts==0) break;
        }
    
    //cout<<"best conflicts: "<<bestConflicts<<", best distance: "<<bestDistance<<endl;
        actualS=bestS;
        /*if(!newFound){
            cout<<"no se encontraron nuevos movimientos, conlfictos finales: "<<bestConflicts<<endl;
        }*/

    }while(bestConflicts>0 && newFound);

    S=bestS;
    

    if(bestConflicts==0)return 1;
    else return 0;

}