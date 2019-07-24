// #include <string.h>

char highestOccurringChar(char input[]) {
  int freq_array[256] = {0};
    for(int i = 0; i < strlen(input); i++){  //fill array
        int index = (int) input[i];
        freq_array[index]++;
    }
    
    int max_index = 0;
    for(int i = 97; i < 123; i++){
        if(freq_array[i] > freq_array[max_index]){
            max_index = i;        
        }else if(freq_array[i] == freq_array[max_index]){
            if(i < max_index){
                max_index = i;
            }
        }
    }
    
    return (char) max_index;   
}