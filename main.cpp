#include <iostream>
using namespace std;
int items[100];
int sum;
int main() {
    int test_case;
	std::cin >> test_case;
	for(int i = 0; i<test_case; i++){
	    sum = 0;
	    int numberOfItems;
	    std::cin >> numberOfItems;
	    std::cout << std::endl;
	    for (int j=0;j<numberOfItems;j++){
	        cin>>items[j];
	        sum+=items[j];
	    }
	    
	    int half = sum/2;
	    int dp[half+1]={0};
	    dp[0]=1;
	    for(int i = 0 ; i<numberOfItems;i++){
	        int item = items[i];
	        for(int j = half; j>=item; j--){
	            if(dp[j-item]==1){
	                dp[j]=1;
	            }
	        }
	    }
	    
	    int bestCount = 0;

	    for(int k=half; k>=0;k--){
	        
	        if(dp[k]==1){
	            bestCount = k;
	            break;
	        }
	    }

	    int ans = sum-(2*bestCount);
	    cout<<ans;
	}

}
