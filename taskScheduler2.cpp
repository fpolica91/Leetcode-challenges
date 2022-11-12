#include "taskScheduler.hpp"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long taskSchedulerII(vector<int>& tasks, int space) {
     
     if(space == 0)
         return tasks.size();
     if(tasks.size() ==0)
         return 0;

     map<int, long> freq;
     long long days = 0;
    

     for(int i = 0; i < tasks.size(); i++){
         int curr = tasks[i];
         if(freq.find(curr) != freq.end()){
             int diff = days - freq[curr] - 1;
             if(diff < space){
                 days+= (space-diff);
             }
         }
          
          freq[curr] = days++;
        
     
     }
     return days;
 }


void exec(){
    vector<int> arr {1,2,1,2,3,1};
    taskSchedulerII(arr, 3);
}