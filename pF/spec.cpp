#include <tcframe/spec.hpp>
// #include <vector>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
    int N;
    string S;
    vector<string> ans;
    void InputFormat()
    {
        LINE(N);
        LINE(S);
    }

    void OutputFormat()
    {
        LINES(ans);
    }

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

    string shu_string = "abcdefghijklmnopqrstuvwxyz";
    string rnd_str(){
        rnd.shuffle(shu_string.begin(), shu_string.end());
        return shu_string.substr(0, N);
    }

    void TestCases(){
        for(int i=0;i<10;i++){
            CASE(N = rnd.nextInt(1, 3), S = rnd_str());
        }
        for(int i=0;i<40;i++){
            CASE(N = rnd.nextInt(1, 6), S = rnd_str());
        }
        for(int i=0;i<50;i++){
            CASE(N = rnd.nextInt(1, 9), S = rnd_str());
        }
    }
    
   
};
