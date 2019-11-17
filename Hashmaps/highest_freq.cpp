#include <unordered_map>
int highestFrequency(int *input, int n){	 
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
    	int key = input[i];
    	if(m.count(key)  == 0){
    		m[key] = 1;
    	}else{
    		m[key]++;
    	}
    }

    int maxKey = m[input[0]];
    int value = input[0];
    int i = 0;

    while(i < n){
    	if(maxKey < m[input[i]]){
    		maxKey = m[input[i]];
    		value = input[i];
    	}
    	i++;
    }
    return value;
}