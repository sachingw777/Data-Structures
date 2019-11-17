#include <unordered_map>
void PairSum(int *input, int n) {	 
	unordered_map<int,int> m;
	//fill map
    for(int i = 0; i < n; i++){
        m[input[i]]++;
    }

    //traverse for key & -key. 
    //Can be improved. try in one pass.
    for(int i = 0; i < n; i++){
    	int key = input[i];
    	if(m[key] != 0 && m[-key] != 0){
    		int times = m[key] * m[-key];

    		while(times != 0){
    			cout << min(key, (-key)) << " " << max(key, (-key)) << endl;
    			times--;
    		}
    		m[key] = 0;
    		m[-key] = 0;
    	}
    }
}