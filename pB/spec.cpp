#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    vector<int> N;
    vector<int> a, b, c;

    void InputFormat() {
        LINE(T);
        LINES(N) % SIZE(T);
    }

    void OutputFormat() {
        LINES(a, b, c) % SIZE(T);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

   
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "125",
            "1100",
            "134"
        });
        Output({
            "1 1 6",
            "11 0 0",
            "1 2 4"
        });
    }
    
    void gen(){
        for(int i=0;i<T;i++){
            N.push_back(rnd.nextInt(1, 1e9));
        }
    }
    void BeforeTestCase(){
        N.clear();
    }

    void TestCases() {
        for(int i=1;i<=100;i++)
            CASE(T = rnd.nextInt(1, 1e5), gen());
    }
};