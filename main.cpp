#include <thread>
#include <iostream>
#include <vector>

void calcFactorial(unsigned long long &val, int end) {
    int start = val;
    for (int i = start+1; i < end; i++) {
	    val = val * i;
    }
}
int main(){
    std::vector<std::thread> threads;
    int n;
    std::cout<<"Enter number to calcFactorial"<<std::endl;
    std::cin>>n;
    unsigned long long a = 1;
    unsigned long long b = n/2;
    unsigned long long c = n/2+n/4;
    threads.push_back(std::thread(calcFactorial, std::ref(a), int(b)));
    threads.push_back(std::thread(calcFactorial, std::ref(b), int(c)));
    threads.push_back(std::thread(calcFactorial, std::ref(c), n));
    
    for(auto& thread : threads){
        thread.join();
    }
    std::cout<<"result: "<<a*b*c*n<<std::endl;
    return 0;
}