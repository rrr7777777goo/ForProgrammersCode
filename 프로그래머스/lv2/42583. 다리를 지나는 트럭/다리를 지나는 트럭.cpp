#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Data
{
    int weight, start, end;
    Data(int w, int s, int e) { weight = w; start = s; end = e; }
};

queue<Data> qu;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int sum_weight = 0, sum_truck = 0;
    int startTime = 1, endTime = 1 + bridge_length;
    
    for(int i = 0; i < truck_weights.size(); i++)
    {
        Data d(truck_weights[i], startTime, endTime);
        
        while(sum_truck + 1 > bridge_length || sum_weight + d.weight > weight)
        {
            
            Data x = qu.front(); qu.pop();
            
            --sum_truck; sum_weight -= x.weight;
            
            if(x.end > d.start)
            {
                d.start = x.end; d.end = d.start + bridge_length;
            }
        }

        qu.push(d);
        sum_weight += d.weight; sum_truck += 1;
        startTime = d.start + 1; endTime = startTime + bridge_length;
    }
    
    return endTime-1;
}