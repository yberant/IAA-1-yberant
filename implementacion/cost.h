double distance(int i, int j){//recibe numeros de equipos, no indices (hay que restar)
    /*cout<<"locacion actual:"<<i<<endl;
    cout<<"me muevo a:"<<j<<endl;
    cout<<"recorro una distancia de:"<< D[i-1][j-1]<<endl;*/
    return D[i-1][j-1];
}

double teamScheduleDistance(vector<vector<int>> S, int j){
    double dist=0;
    int actual=j;
    int next=j;
    for(int i=0;i<2*(n-1);i++){
        int t=S[i][j-1];
        //cout<<endl<<"siguiente rival: "<<t<<endl;
        if(t<0){//juego de visita
            next=abs(t);
        }
        else{//juego como local
            next=j;
        }
        dist+=distance(actual,next);
        //cout<<"distancia actual recorrida por el equipo "<<j<<": "<<dist<<endl;
        actual=next;
    }
    next=j;
    dist+=distance(actual,j);
    //cout<<"distancia final recorrida por el equipo "<<j<<": "<<dist<<endl;
    return dist;
}

double scheduleDistance(vector<vector<int>> S){
    double dist=0;
    for(int j=1;j<=n;j++){
        
        dist+=teamScheduleDistance(S,j);
        //cout<<"distancia recorrida por equipos actualmente: "<<dist<<endl;
    }
    return dist;
}





void atMostConflicts(vector<vector<int>> S, vector<int> & conflictedRounds, vector<int> & conlfictedTeams){
    int cost=0;
    
    
    for(int j=0;j<n;j++){
        int consecutive=0;
        int sign;
        if (S[0][j]>0) sign=1;
        else sign=-1;
        int teamconflict=0;
        vector<int> currentRows;//filas en que hay visitas/locales seguidas, en el equipo
        for(int i=0;i<2*(n-1);i++){
            
            if(S[i][j]*sign<0){ 
                if(currentRows.size()>3){
                    addValues(conflictedRounds,currentRows);
                    teamconflict=1;
                }
                resetVector(currentRows);
                sign=-sign;
                
            }
            currentRows.push_back(i);
            //cout<<"S["<<i<<"]["<<j<<"]: "<<S[i][j]<<", c.rows: ";printVector(currentRows);
        }
        if(currentRows.size()>3){
                    addValues(conflictedRounds,currentRows);
                    teamconflict=1;
        }
        if(teamconflict==1) add(conlfictedTeams,j);
    }
    return;
}

void noRepeatConflicts(vector<vector<int>> S, vector<int> & conflictedRounds, vector<int> & conlfictedTeams){
    
    for(int j=0;j<n;j++){
        int actual=0;
        int next=0;
        int teamconflict=0;
        for(int i=0;i<2*(n-1);i++){
            next=S[i][j];
            if(abs(actual)==abs(next)){
                add(conflictedRounds,i);
                add(conflictedRounds,i-1);
                teamconflict=1;
            }
            actual=next;

        }
        if(teamconflict==1) add(conlfictedTeams,j);

    }
    return;
}

int totalConflicts(vector<vector<int>> S){
    vector<int> conflictedTeams;
    vector<int> conflictedRounds;
    noRepeatConflicts(S,conflictedRounds,conflictedTeams);
    atMostConflicts(S,conflictedRounds,conflictedTeams);
    int CT=conflictedTeams.size();
    int CR=conflictedRounds.size();
    return CT+CR;
}