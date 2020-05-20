//intercambia juegos entre rondas
void swapRounds(vector<vector<int>> & S, int i, int j){
    if(i==j)return;
    vector<int> auxRound=S[i];
    S[i]=S[j];
    S[j]=auxRound;
}

//intercambia juegos entre dos equipos (excepto aquellos en los que esos dos equipos jueguen)
void swapTeams(vector<vector<int>> & S, int i, int j){
    if(i==j)return;
    for(int round=0;round<2*(n-1);round++){
        if(abs(S[round][i])!=j+1 && abs(S[round][j])!=i+1){
            int auxTeam=S[round][i];
            S[round][i]=S[round][j];
            S[round][j]=auxTeam;
        }
    }
    //actualiza rivales
    for(int r=0;r<2*(n-1);r++){
        int rival1=S[r][i];
        int rival2=S[r][j];
        if(rival1>0) S[r][rival1-1]=-(i+1);
        else S[r][-rival1-1]=i+1;
        
        if(rival2>0) S[r][rival2-1]=-(j+1);
        else S[r][-rival2-1]=j+1;
    }
}
