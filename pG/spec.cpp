#include <tcframe/spec.hpp>
// #include <vector>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
    long long n, m;
    void InputFormat()
    {
        LINE(n, m);
    }

    // void OutputFormat()
    // {
    //     LINES(ans);
    // }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(64000);
    }

    /*void Constraints() {
        CONS(1 <= N && N <= 50);
    }*/
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:


    void TestCases(){
        for(int i=0;i<100;i++){
            int k = rnd.nextInt(0, 5);
            CASE(n = (long long)pow(3, k), m = rnd.nextInt(0, (long long)pow(9, k) - (long long)pow(8, k)));
        }
    }
    
   
};
