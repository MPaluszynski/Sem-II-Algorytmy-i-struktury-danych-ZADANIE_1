#include <iostream>
#include <stdio.h>

using namespace std;

int filterResult(int firstResult, int secondResult) {
	return (firstResult > secondResult) ? firstResult : secondResult;
}

int calculateResult(int tabOfWages[], int tabOfWeights[], int n, int c) {
	if (n == 0 || c == 0){
 		return 0;
	} else if (tabOfWeights[(n-1)] > c){
        return calculateResult(tabOfWages, tabOfWeights, n-1, c);
	} else {
	    return filterResult((calculateResult(tabOfWages, tabOfWeights, n-1,c-tabOfWeights[n-1]) + tabOfWages[n-1]), calculateResult(tabOfWages, tabOfWeights, n-1,c));
	}
}


int main()
{
    int numOfCars, numOfItems, maxWeight;
    scanf("%d", &numOfCars);
    for(int a = 0 ; a < numOfCars ; a++) {
        scanf("%d", &numOfItems);
        if (numOfItems == 0) {
			printf("%d\n", 0);
		} else {
            int* tabOfWages = new int[numOfItems];
            int* tabOfWeights = new int[numOfItems];

            for(int b=0 ; b<numOfItems ; b++)
            {
                scanf("%d", &tabOfWages[b]);
            }
            for(int c=0 ; c<numOfItems ; c++)
            {
                scanf("%d", &tabOfWeights[c]);
            }
            scanf("%d", &maxWeight);
            if (maxWeight <= 0) {
				printf("%d\n", 0);
			} else {
			    int counter = 0, dummyInteger = 0, totalWage =0, totalWeight = 0, finalResult;
			    for(int d = 0 ; d<numOfItems ; d++){
                    if(tabOfWeights[d] <= maxWeight && !(tabOfWeights[d]>100 && tabOfWages[d]<5)){
                    counter++;
                    }
                }
                int * newTabOfWages = new int[counter];
                int * newTabOfWeights = new int[counter];

                for(int e = 0 ; e<numOfItems ; e++) {
                    if(tabOfWeights[e] <= maxWeight && !(tabOfWeights[e]>100 && tabOfWages[e]<5)){
                        newTabOfWeights[dummyInteger] = tabOfWeights[e];
                        if(tabOfWeights[e]>100){
                            newTabOfWages[dummyInteger] = tabOfWages[e]-5;
                        } else {
                            newTabOfWages[dummyInteger] = tabOfWages[e];
                        }
                        totalWeight += newTabOfWeights[dummyInteger];
                        totalWage += newTabOfWages[dummyInteger];
                        dummyInteger++;
                    }
                }
                if(totalWeight <= maxWeight && totalWeight != 0 && totalWage>20){
                    finalResult = totalWage;
                    printf("%d\n", (finalResult - 20));
                } else if(totalWeight == 0) {
                    finalResult = totalWage;
                    printf("%d\n", finalResult);
                } else {
                    finalResult = calculateResult(newTabOfWages, newTabOfWeights, counter, maxWeight);
                    if (finalResult > 20) {
                        printf("%d\n", (finalResult - 20));
                    }
                    else {
                        printf("%d\n", 0);
                    }
                }
                delete [] newTabOfWages;
                delete [] newTabOfWeights;
			}
            delete [] tabOfWages;
            delete [] tabOfWeights;
		}
    }
    return 0;
}
