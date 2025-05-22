string merge(string S1, string S2) {
    int n1=S1.size();
    int n2=S2.size();
    string result="";
    
    int i = 0, j = 0;
    
    while(i<n1 && j<n2){
        result+=S1[i++];
        result+=S2[j++];
    }
    while (i < n1) {
        result += S1[i++];
    }

    while (j < n2) {
        result += S2[j++];
    }

    return result;
    
}
