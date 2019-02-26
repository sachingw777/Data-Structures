#include<string.h>
bool isPermutation(char input1[], char input2[]) 
{
	int freq[256] = {0};
	for (int i = 0; input1[i] != '\0' ; i++)
	{
		/* code */
		int index = (int) input1[i];
		freq[index]++;
	}
	for (int i = 0; input2[i] != '\0' ; i++)
	{
		/* code */
		int index = (int) input2[i];
		freq[index]--;
	}

	for (int i = 0; i < 256 ; i++)
	{
		if (freq[i]!=0 )	
		{
			return false;
		}
	}
			/* code */
	return true;

}